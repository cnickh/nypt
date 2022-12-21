#include "Value.h"


Value op(Value dest, Value src, char operand, bool inplace){
  //printf("op\n");
  word a,b,temp;
  uint len,blen;

  if(src.len > dest.len){
    a = src.value;
    len = src.len;

    b = dest.value;
    blen = dest.len;

    if(inplace==Y){destroy(dest);}
    temp = draw(len);
  }else{
    a = dest.value;
    len = dest.len;

    b = src.value;
    blen = src.len;

    if(inplace==Y)
    {temp = a;}
    else
    {temp = draw(len);}
  }

  int i=0;

  switch(operand){

    case AND:
    for(i;i<blen;i++){
      temp[i]=a[i]&b[i];
    }  for(i;i<len;i++){
        temp[i]=0;
      }
    break;

    case OR:
    for(i;i<blen;i++){
      temp[i]=a[i]|b[i];
    }  for(i;i<len;i++){
        temp[i]=a[i];
      }
    break;

    case XOR:
    for(i;i<blen;i++){
      temp[i]=a[i]^b[i];
    }  for(i;i<len;i++){
        temp[i]=a[i];
      }
    break;

  }

  //printf("op_done\n");
  if(temp == a){
    return cleanZeros(dest);
  } else{
    return makeValue(temp,len,P);
  }

}

Value neg(Value dest, bool inplace){

  word a = dest.value;
  uint len = dest.len;
  word temp;
  if(inplace==Y){
    temp = a;
  }else{
    temp = draw(len);
  }

  for(uint i=0;i<len-1;i++){
    temp[i]=~a[i];
  }

  byte mask = byteMask(byteOrder(a[len-1]));
  temp[len-1] = (~a[len-1])&mask;

  if(inplace == Y){
    return cleanZeros(dest);
  } else {
    return makeValue(temp,len,dest.sign);
  }

}

Value shift(Value dest, uint magnitude, bool direction, bool inplace){

  word a = dest.value;
  uint len = dest.len;

  uint size = shift_size(len,a,magnitude,direction);

  word temp = draw(size);

  uint delta = magnitude/BYTE_SIZE;
  uint sh = magnitude%BYTE_SIZE;
  uint inv = BYTE_SIZE-sh;

  byte mask=byteMask(sh);

  uint o=0;
  uint i=0;


  switch(direction){

    case R:
      mask=mask<<inv;
      for(i;i<len;i++){
        temp[i+delta] = (a[i]<<sh)|(o>>inv);
        o = a[i]&mask;
      }
      if(size>len+delta){temp[size-1] = (o>>inv);}
      for(i=0;i<delta;i++){temp[i] = 0;}
    break;

    case L:
      if(delta >= len){temp[0]=(byte)0;break;}

      for(i=len;i>=delta+1;i--){
        uint k =i-1;
        if((k-delta)<size){
          temp[k-delta] = (a[k]>>sh)|(o<<inv);
        }
        o = a[k]&mask;
      }
    break;

  }


  if(inplace == Y){
    erase(dest.value);
    dest.value = temp;
    dest.len = size;

    return dest;
  } else {
  //  print_page();
  //  printf("Shift done\n");
    return makeValue(temp,size,P);
  }

}

bool isZero(Value a){
  for(uint i=0;i<a.len;i++){
    if(a.value[i]!=0){
      return N;
    }
  }
  return Y;
}
