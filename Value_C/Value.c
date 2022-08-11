#include "Value.h"

Value add(Value a, Value b, bool inplace){

  // if(a.sign!=b.sign){
  //   Value nb = makeValue(b.value,b.len,flip(b.sign));
  //   Value res = sub(a,nb);
  //   destroy(nb);
  //   return res;
  // }

  Value carry, res, next_carry;

  if(inplace == Y){
    carry = op(a,b,AND,N);
    res = op(a,b,XOR,Y);
  } else {
    carry = op(a,b,AND,N);
    res = op(a,b,XOR,N);
  }

  while(isZero(carry)!=Y){

    carry = shift(carry, 1, R, Y);

    next_carry = op(carry, res, AND, N);
    res = op(res, carry, XOR, Y);

    destroy(carry);
    carry = next_carry;

  }
  destroy(carry);

  res.sign = a.sign;
  return res;
}

Value sub(Value a, Value b, bool inplace){

  // if(a.sign!=b.sign){
  //   Value nb = makeValue(b.value,b.len,flip(b.sign));
  //   Value res = add(a,nb);
  //   destroy(nb);
  //   return res;
  // }

  Value rnot,borrow,res,next_borrow;
  bool sign;

  if(max_cmp(a,b)==B){
    sign = flip(b.sign);

    rnot = neg(b,N);
    borrow = op(rnot,a,AND,N);

    if(inplace == Y){
      res = op(a,b,XOR,Y);
    }else{
      res = op(a,b,XOR,N);
    }

  } else {
    sign = a.sign;

    res = op(a,b,XOR,N);

    if(inplace == Y){
      rnot = neg(a,Y);
    }else{
      rnot = neg(a,N);
    }

    borrow = op(rnot,b,AND,N);
  }

  while(isZero(borrow)!=Y){
    destroy(rnot);
    rnot = neg(res,N);

    borrow = shift(borrow, 1, R, Y);
    res = op(res, borrow, XOR, Y);

    next_borrow = op(borrow, rnot, AND, N);

    destroy(borrow);
    borrow = next_borrow;
  }
  destroy(rnot);
  destroy(borrow);

  res.sign = sign;
  return cleanZeros(res);
}

bool max_cmp(Value a, Value b){

  if(a.len>b.len){
    return A;
  } else if(b.len>a.len){
    return B;
  }

  uint aord, bord;

  for(int i=a.len-1;i>=0;i--){

    for(int t=7;t>=0;t--){
      aord = ((a.value[i]>>t)&1) == 1;
      bord = ((b.value[i]>>t)&1) == 1;

      if(aord && !bord){return A;}

      if(bord && !aord){return B;}

    }

  }

  return E;
}


Value mlt(Value a, Value b, bool inplace){

  // if(a.sign!=b.sign){
  //   a = makeValue(a.value,a.len,N);
  // } else {
  //   a = makeValue(a.value,a.len,P);
  // }

  Value res = emptyValue(a.len+b.len);
  Value fac0 = emptyValue(a.len+b.len);
  Value fac1 = emptyValue(a.len+b.len);

  byte sig = b.value[0]&1;
  if(sig == 1){res = add(res,a,Y);}

  destroy(fac0);
  fac0 = shift(b,1,L,N);
  destroy(fac1);
  if(inplace == Y){
    fac1 = shift(a,1,R,Y);
  }else{
    fac1 = shift(a,1,R,N);
  }

  while(isZero(fac0)!=Y){

    sig = fac0.value[0]&1;
    if(sig == 1){res = add(res,fac1,Y);}

    fac0 = shift(fac0,1,L,Y);
    fac1 = shift(fac1,1,R,Y);

  }
  destroy(fac0);
  destroy(fac1);

  return cleanZeros(res);
}

Value dv(Value a, Value b){

  Value sOne, temp;
  Value res = emptyValue(1);
  Value one = fromUlong(1);
  Value div = cpy(b);
  Value remainder = cpy(a);

  uint len = wordOrder(a.len,a.value)-1;

  for(int i=len;i>=0;i--){

    temp = shift(div,i,R,N);

    bool c = max_cmp(temp,remainder);

    if(c==B||c==E){

      remainder = sub(remainder,temp,Y);

      sOne = shift(one,i,R,N);
      res = add(res,sOne,Y);

      destroy(sOne);
    }

    destroy(temp);
  }

  destroy(div);
  destroy(remainder);
  destroy(one);

  return res;
}

Value pwr(Value a, Value b){

  Value res = fromUlong(1);

  Value pow = cpy(b);
  Value dest = cpy(a);

  while(isZero(pow)!=Y){

    byte sig = pow.value[0]&1;
    if(sig==1){
      res = mlt(res,dest,Y);
    }

    dest = mlt(dest,dest,Y);

    pow = shift(pow, 1, L, Y);

  }
  destroy(pow);
  destroy(dest);

  return res;
}

Value lg(Value a, Value b){
  Value res = emptyValue(1);


  return res;
}
