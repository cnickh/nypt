#include "Page.h"

int main(){

  printf("[0]\n");
  new_page();

  printf("[1]\n");
  word mem0 = draw(5);
  word mem1 = draw(5);
  word mem2 = draw(5);
  word mem3 = draw(5);


  printf("[2] Space: %d\n",get_space());
  print_page();

  printf("[3]\n");
  print_page();
  erase(mem0);
  print_page();
  erase(mem1);
  print_page();
  erase(mem2);
  print_page();
  erase(mem3);
  print_page();


  printf("[4]\n");
  print_page();

  close();
}
