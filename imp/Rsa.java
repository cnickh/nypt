package imp;

import java.util.Random;
import java.lang.Math;

public class Rsa implements Asymmetric {

  //max 8 bytes
  public byte[][] createKeyPair(){

    byte[][] kPair = new byte[2][];

    long p = randomPrime();
    long q = randomPrime();

    while(p!=q){
      System.out.println("Here");
      p = randomPrime();
      q = randomPrime();
    }

    long toe = (p-1)*(q-1);
    long n = p*q;

    long e = randomPrime();
    long d = invMod(e,toe);

    while((gcd(e,toe)!=1)||(e>toe)||(d==-1)){
      System.out.println("Here0");
      e = randomPrime();
      d = invMod(e,toe);
    }

    //while()

    return kPair;
  }

  public byte[] encrypt(byte[] pKey, byte[] open){return new byte[0];}

  public byte[] decrypt(byte[] sKey, byte[] close){return new byte[0];}-

  private long gcd(long a, long b){

    long t = 0;

    while(b!=0){
      t = b;
      b = a%b;
      a = t;
    }

    return a;
  }

  private long invMod(long a, long m){

    long q = 0; long temp = 0;
    long t = 0; long nextt = 1;
    long r = m; long nextr = a;

    while(nextr != 0){

      q = r/nextr;

      temp = nextr;
      nextr = r-(q*nextr);
      r = temp;

      temp = nextt;
      nextt = t-(q*nextt);
      t = temp;
    }

    if(r > 1){
      return -1;
    }
    if(t<0){
      t = t + m;
    }

    return t;

  }

}
