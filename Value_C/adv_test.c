#include "Value.h"
#include "Page.h"

//for testing comparisons
#include <math.h>

int main(){

  long long TEST_NUM[8] =
  {5,12,20,3,
  22,44,9,56};



  new_page();
  uint r=0;
  for(int t=0;t<8;t+=1){
    for(int v=0;v<8;v+=1){
      long long i = TEST_NUM[t];
      long long q = TEST_NUM[v];

      printf("Round: %d\n",r++);
      printf("Space: %d\n",get_space());
      printf("Lines: %d\n",get_line_count());

      Value val0 = fromUlong(i);
      Value val1 = fromUlong(q);
      char *v0 = hex(val0);
      char *v1 = hex(val1);
      printf("val0: %s\n",v0);
      printf("val1: %s\n",v1);
      printf("========================\n");

      Value _pow = pwr(val0,val1);
      Value res = fromUlong(pow(i,q));
      char *p = hex(_pow);
      char *ph = hex(res);
      printf("POW: %s == %s\n",p,ph);
      erase(p);erase(ph);
      destroy(_pow);destroy(res);

      //printf("Space Final: %d\n",get_space());
      //printf("erase v0\n");
      erase(v0);
      //printf("erase v1\n");
      erase(v1);
      //printf("destroy val0\n");
      destroy(val0);
      //printf("destroy val1\n");
      destroy(val1);

      printf("Cleared\n");
      // print_page();

      printf("\n");
    }
  }

  close();

}
