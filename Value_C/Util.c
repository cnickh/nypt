#include "Value.h"

char *hex(Value val){

  char HEX_ARRAY[16] =
  {'0','1','2','3',
  '4','5','6','7',
  '8','9','A','B',
  'C','D','E','F'};

  uint len = val.len;
  word value = val.value;
  char *hex;

  if(val.sign==N){

    hex = draw(len*2+2);
    hex[0] = '-';
    for (int j = 0; j < len; j++) {
      byte v = value[len-1-j];
      hex[(j*2) +1] = HEX_ARRAY[v >> 4];
      hex[(j*2) +2] = HEX_ARRAY[v & 0x0F];
    }
    hex[len*2+1] = '\0';

  } else {
    hex = draw(len*2+1);
    for (int j = 0; j < len; j++) {
      byte v = value[len-1-j] & 0xFF;
      hex[j * 2] = HEX_ARRAY[v >> 4];
      hex[j * 2 + 1] = HEX_ARRAY[v & 0x0F];
    }
    hex[len*2] = '\0';
  }

  return hex;
}

char *_hex(word value, uint len){

  char HEX_ARRAY[16] =
  {'0','1','2','3',
  '4','5','6','7',
  '8','9','A','B',
  'C','D','E','F'};

  char *hex;

  hex = malloc(len*2+1);
  for (int j = 0; j < len; j++) {
    byte v = value[len-1-j] & 0xFF;
    hex[j * 2] = HEX_ARRAY[v >> 4];
    hex[j * 2 + 1] = HEX_ARRAY[v & 0x0F];
  }
  hex[len*2] = '\0';

  return hex;
}

word shrink(uint len, word value){

  erase(value);
  word nvalue = draw(len);

  for(int i=0;i<len;i++){
    nvalue[i] = value[i];
  }

  return nvalue;

}

uint byteOrder(byte b){
  int i=BYTE_SIZE-1;
  while((((b>>i)&0b1)!=1)&&(i!=-1)){i--;}
  return (uint)(i+1);
}

uint wordOrder(uint len, word a){
  return BYTE_SIZE*(len-1)+byteOrder(a[len-1]);
}

byte byteMask(uint size){
  byte mask;
  for(uint i=0;i<size;i++){mask = mask | (0b1<<i);}
  return mask;
}

bool flip(bool sign){
  if(sign==P){return N;}else{return P;}
}

uint shift_size(uint len, word a, uint magnitude, bool direction){

  uint size;
  uint order = wordOrder(len,a);

  switch(direction){
    case R:
      size = (order + magnitude)/BYTE_SIZE;
      if(((order + magnitude)%BYTE_SIZE)!=0){size++;}
    break;
    case L:
      if(magnitude >= order){size=1;break;}
      size = (order - magnitude)/BYTE_SIZE;
      if(size == 0){size=1;break;}
      if(((order - magnitude)%BYTE_SIZE)!=0){size++;}
    break;
  }
  return size;
}

Value cleanZeros(Value a){

  if(a.len == 1){
    return a;
  }

  uint z =0;
  for(int i=a.len-1;i>=0;i--){
    if(a.value[i]==0){
      z++;
    }else{
      break;
    }
  }

  if(z == a.len){
    destroy(a);
    return emptyValue(1);
  }

  a.len -= z;
  a.value = shrink(a.len,a.value);

  return a;
}
