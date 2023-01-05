#include "Page.h"

#define this(cur) ((word)(cur+1))
#define next(cur) ((line)(this(cur) + cur->len))
#define size(cur) (cur->len + LINE_SIZE)

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
  while(cur->used!=E){
    count++;
    cur = next(cur);
  }
  return count;
}

int new_page(){
  if(book == NULL){book = malloc(BOOK_SIZE*sizeof(void*));}

  page start = malloc(PAGE_SIZE);
  start->space = sizeof(struct page_t);
  start->head = (line)(start+1);
  start->head->used = E;

  pages++;
  book[pages] = start;
  return pages;
}

void close(){
  for (uint i=0;i<pages;i++){
    free(book[i]);
  }
  free(book);
  pages=-1;
}

void *draw(uint len){
  if(pages == -1){printf("DERROR NO PAGE\n");return NULL;}
  page p = book[pages];

  line cur = p->head;

  while(check(cur,len)==N){
    if(cur->used == E){break;}
    cur = next(cur);
  }

  if(cur->used != E){
    cur->used = Y;
    return this(cur);
  }

  uint new_mem = LINE_SIZE+len+p->space;
  if(new_mem > PAGE_SIZE){printf("[%d]PAGE FULL :( %d\n",pages,get_space());print_page();close();return NULL;}
  p->space = new_mem;

  cur->used = Y;
  cur->len = len;

  next(cur)->used = E;

  return this(cur);
}

bool check(line cur, uint len){
  if(
    (cur->used==N) && (len <= cur->len)
  ){
    return Y;
  }else{
    return N;
  }
}

void erase(void *drawing){

  if(pages == -1){printf("EERROR NO PAGE\n");return;}
  page p = book[pages];
  line breakLine = NULL;
  line cur = p->head;
  uint freed = 0;

  while(this(cur)!=drawing){
    if(cur->used == E){printf("EERROR: LINE NOT FOUND\n");return;}

    if(cur->used == N && breakLine == NULL){breakLine = cur;freed+=size(cur);}
    else if(cur->used == Y){breakLine = NULL;freed=0;}
    else{freed+=size(cur);}

    cur = next(cur);
  }

  if(cur->used==N){printf("EERROR: LINE ALREADY ERASED\n");return;}

  if(breakLine != NULL){

    if(next(cur)->used == E){
      breakLine->used = E;
      p->space-=(freed+size(cur));
    }else{
      cur->used = N;
    }

  }else{

    if(next(cur)->used == E){
      cur->used = E;
      p->space-=size(cur);
    }else{
      cur->used = N;
    }

  }

}

void seek_page(int page){
  pages=page;
}

/*Shift memory to retake unused space*/
void heal(){
  if(pages == -1){printf("EERROR NO PAGE\n");return;}
  page p = book[pages];

  line cur = p->head;

}

void print_page(){
  if(pages == -1){printf("DERROR NO PAGE\n");return;}
  page p = book[pages];

  uint i = 0;
  line cur = p->head;
  char *h;

  while(cur->used!=E){
    h = _hex(this(cur),cur->len);

    printf("<%c>[%d]->%s (%d)(%d)\n",cur->used,i,h,cur->len,this(cur));
    i++;

    free(h);
    cur = next(cur);
  }

}
