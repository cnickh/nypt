#include "Page.h"

int pages=-1;
page *book=NULL;

uint get_space(){
  return book[pages]->space;
}

uint get_line_count(){
  if(pages == -1){printf("ERROR NO PAGE\n");return 0;}
  page p = book[pages];
  uint count=0;
  line cur = p->head;
  while(cur->next!=NULL){
    //if(cur->used==Y){
      count++;
    //}
    cur = cur->next;
  }
  return count;
}

void new_page(){
  if(book == NULL){book = malloc(BOOK_SIZE*sizeof(void*));}

  page start = malloc(PAGE_SIZE);
  start->space = sizeof(struct page_t);
  start->head = (line)(start+1);
  start->head->this = (word)(start->head+1);
  start->head->next = NULL;

  pages++;
  book[pages] = start;
}

void close(){
  for (uint i=0;i<pages;i++){
    free(book[i]);
  }
  pages=-1;
}

void *draw(uint len){
  if(pages == -1){printf("DERROR NO PAGE\n");return NULL;}
  page p = book[pages];
  //printf("LINE_SIZE: %d  LEN: %d  PAGE_SIZE: %d\n",LINE_SIZE, len, PAGE_SIZE);

  line cur = p->head;
  while(cur->next!=NULL){

    if((cur->used==N)&&(len<=cur->len)){
      cur->used=Y;
      // printf("RECYCLING LEN: %d -> HOLE: %d\n",len,cur->len);
      return cur->this;
    }

    cur = cur->next;
  }

  //printf("CREATING NEW LINE SIZE: %d\n",len);
  uint new_mem = LINE_SIZE+len+p->space;
  if(new_mem > PAGE_SIZE){printf("[%d]PAGE FULL :(\n",pages);print_page();return NULL;}
  p->space = new_mem;

  line next;
  next = (line)(cur->this+len);
  next->this = (word)(next+1);
  next->next = NULL;
  cur->next = next;
  cur->used = Y;
  cur->len = len;

  return cur->this;
}

void erase(void *drawing){
  // printf("Erasing (%d)\n",drawing);
  if(pages == -1){printf("EERROR NO PAGE\n");return;}
  page p = book[pages];

  // printf("ERASE\n");
  // print_page();

  line cur = p->head;
  line breakLine = NULL;
  while(cur->this!=drawing){

    if(cur->used == Y){
      breakLine = NULL;
    }else{
      if(breakLine == NULL){breakLine = cur;}
    }

    if(cur->next==NULL){printf("EERROR: LINE NOT FOUND\n");return;}
    cur = cur->next;
  }

  if(cur->used==N){printf("EERROR: LINE ALREADY ERASED\n");return;}
  cur->used = N;

  if(cur->next->next==NULL){
    if(breakLine!=NULL){
      cur = breakLine;
      while(cur->next!=NULL)
      {p->space-=(cur->len+LINE_SIZE);cur=cur->next;}
      breakLine->next = NULL;
    }else{
      p->space-=(cur->len+LINE_SIZE);
      cur->next=NULL;
    }
  }

  // printf("DONE\n");
  // print_page();
  // printf("\n");

}

// void heal(){
//   if(pages == -1){printf("EERROR NO PAGE\n");return;}
//   page p = book[pages];
//
//   line cur = p->head;
//   line breakLine = cur;
//
//   while(cur->next->next!=NULL){
//
//     if(cur->used == Y){
//       breakLine == NULL;
//     }else{
//       if(breakLine != NULL){breakLine = cur;}
//     }
//
//     cur = cur->next;
//   }
//
//   breakLine->next = NULL;
//
// }

void print_page(){
  if(pages == -1){printf("DERROR NO PAGE\n");return;}
  page p = book[pages];

  uint i = 0;
  line cur = p->head;
  while(cur->next!=NULL){

    printf("<%c>[%d]->%s (%d)(%d)\n",cur->used,i,_hex(cur->this,cur->len),cur->len,cur->this);
    i++;

    cur = cur->next;
  }

}
