#include "Value.h"
#include "Page.h"

int main(){

  long long TEST_NUM[8] =
  {34,567,4567,73100,
  234955,1000000,85010063,696969333};



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
      printf("Line size: %d, bool: %d, uint: %d\n",LINE_SIZE,sizeof(bool),sizeof(uint));
      print_page();

      Value and = op(val0,val1,AND,N);
      char *ah = hex(and);
      printf("AND: %s\n",ah);destroy(and);erase(ah);
      // print_page();

      Value xor = op(val0,val1,XOR,N);
      char *xh = hex(xor);
      printf("XOR: %s\n",xh);destroy(xor);erase(xh);
      // print_page();

      Value or = op(val0,val1,OR,N);
      char *oh = hex(or);
      printf("OR: %s\n",oh);destroy(or);erase(oh);
      // print_page();

      Value negate = neg(val0,N);
      char *nh = hex(negate);
      printf("NEG: %s\n",nh);destroy(negate);erase(nh);
      // print_page();

      Value shiftR = shift(val1, 9, R, N);
      char *rh = hex(shiftR);
      printf("shiftR: %s\n",rh);destroy(shiftR);erase(rh);
      // print_page();

      Value shiftL = shift(val0, 7, L, N);
      char *lh = hex(shiftL);
      printf("shiftL: %s\n",lh);destroy(shiftL);erase(lh);
      // print_page();

      Value _add = add(val0,val1,N);
      Value res0 = fromUlong(i+q);
      char *ad = hex(_add);
      char *adh = hex(res0);
      printf("ADD: %s == %s\n",ad,adh);
      erase(ad);erase(adh);
      destroy(_add);destroy(res0);

      Value _sub = sub(val0,val1,N);
      Value res1 = fromUlong(i-q);
      char *s = hex(_sub);
      char *sh = hex(res1);
      printf("SUB: %s == %s\n",s,sh);
      erase(s);erase(sh);
      destroy(_sub);destroy(res1);

      Value _mlt = mlt(val1,val0,N);
      Value res2 = fromUlong(i*q);
      char *m = hex(_mlt);
      char *mh = hex(res2);
      printf("MLT: %s == %s\n",m,mh);
      erase(m);
      erase(mh);
      destroy(_mlt);
      destroy(res2);


      Value _dv = dv(val0,val1);
      Value res3 = fromUlong(i/q);
      char *d = hex(_dv);
      char *dh = hex(res3);
      printf("DV: %s == %s\n",d,dh);
      erase(d);
      erase(dh);
      destroy(_dv);
      destroy(res3);

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
      print_page();

      printf("\n");
    }
  }

  close();

}
