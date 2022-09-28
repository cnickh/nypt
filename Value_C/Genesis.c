#include "Value.h"

Value emptyValue(uint len){

  Value val;

  val.value = draw(len);
  for(int i=0;i<len;i++){val.value[i]=0;}
  val.len = len;
  val.sign = P;

  return val;
}

Value makeValue(word value, uint len, bool sign){


  Value val;

  val.value = shrink(len,value);
  val.sign = sign;
  val.len = len;


  return val;
}

void destroy(Value val){
  erase(val.value);
}


Value fromUlong(long long num){

  if(num==0){return emptyValue(1);}

  word value = draw(8);

  int t = 0;

  bool sign = (num>>63)&0b1;


  for(int i=0;i<8;i++){
    if(i==7){
      value[i] = (byte)((num>>(8*i))&0x7F);
    }else{
      value[i] = (byte)((num>>(8*i))&0xFF);
    }

    if(value[i]==0){t++;}
    else{t=0;}
  }

  if(sign==1){

    word comp = draw(8);
    for(int i=0;i<7;i++){comp[i]=0;}
    comp[7] = 128;

    Value max = makeValue(comp,8,P);
    Value pos = makeValue(value,8-t,P);

    Value res = sub(max,pos,Y);

    destroy(pos);

    res.sign = N;
    return res;

  } else {
    return makeValue(value,8-t,P);
  }

}

Value cpy(Value a){
  Value c;
  c.len = a.len;
  c.sign = a.sign;
  c.value = draw(a.len);

  for(int i=0;i<a.len;i++){
    c.value[i] = a.value[i];
  }

  return c;
}
