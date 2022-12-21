#include "Value.h"
#include "Page.h"

typedef rsa_key_t {

  Value public;
  Value private;
  Value n;

} rsa_key;

rsa_key gen_rsa_keys(uint mag){

  Value p = getPrimeValue(mag);
  Value q = getPrimeValue(mag);

  Value n = mlt(p,q);

  Value phi = mlt(p-1,q-1);

  Value e; //e :: 1 < e < phi & gcd(e,phi) = 1
  Value d; //d :: 1 < d < phi & ed ~ 1 % phi

}

Value rsa_encrypt(Value key, Value open, Value n){
  return pwr_mod(open,key,n);
}

Value rsa_decrypt(Value key, Value closed, Value n){
  return pwr_mod(closed,key,n);
}

Value rsa_sign(Value key, Value data){

}

Value rsa_verify(Value key, Value sig){

}
