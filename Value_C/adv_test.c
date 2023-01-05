#include "Value.h"
#include "Page.h"

//for testing comparisons
#include <math.h>

void purple () {
  printf("\033[1;35m");
}

void reset () {
  printf("\033[0m");
}

int main(){

  long long TEST_NUM[8] =
  {5,12,20,3,
  22,44,9,56};

  long long MOD_NUM[8] =
  {9801,8464,8281,7569,
  256,289,400,7056};

  new_page();
  uint r=0;
  for(int t=0;t<8;t+=1){
   for(int v=0;v<8;v+=1){
      long long i = TEST_NUM[t];
      long long q = TEST_NUM[v];
      long long n = MOD_NUM[t];

      printf("Round: %d\n",r++);
      printf("Space: %d\n",get_space());
      printf("Lines: %d\n",get_line_count());

      Value val0 = fromUlong(i);
      Value val1 = fromUlong(q);
      // Value modulos = fromUlong(n);

      char *v0 = hex(val0);
      char *v1 = hex(val1);
      // char *modo = hex(modulos);
      printf("val0: %s\n",v0);
      printf("val1: %s\n",v1);
      // printf("modulos: %s  %d\n",modo,n);
      printf("========================\n");

      erase(v0);
      erase(v1);
      // erase(modo);

      // Value _pow = pwr(val0,val1);
      // Value res = fromUlong(pow(i,q));
      // char *p = hex(_pow);
      // char *ph = hex(res);
      // printf("POW: %s == %s\n",p,ph);
      // erase(p);erase(ph);
      // destroy(_pow);destroy(res);

      Value _mod = mod(val0,val1);
      Value res = fromUlong(i%q);
      char *m = hex(_mod);
      char *mh = hex(res);
      purple();
      printf("MOD: %s == %s\n",m,mh);
      reset();

      erase(m);erase(mh);
      destroy(_mod);destroy(res);

      // Value _mod_pwr = pwr_mod(val0,val1,modulos);
      // long long temp = pow(i,q);
      // res = fromUlong(temp%n);
      // m = hex(_mod_pwr);
      // mh = hex(res);
      // printf("PWR_MOD: %s == %s\n",m,mh);
      // erase(m);erase(mh);
      // destroy(_mod_pwr);destroy(res);


      // Value _sqrt = square(modulos);
      // long long temp = sqrt(n);
      // Value res = fromUlong(temp);
      // char *m = hex(_sqrt);
      // char *mh = hex(res);
      // purple();
      // printf("SQRT: %s == %s\n",m,mh);
      // reset();
      // printf("SQRT-INT: %d\n",square_int(n));
      // erase(m);erase(mh);
      // destroy(_sqrt);destroy(res);

      destroy(val0);
      destroy(val1);
      // destroy(modulos);

      printf("Cleared\n");
      print_page();

      printf("\n");
   }
  }

  close();

}
