package values;

import java.util.Random;

public class Genesis{

  Random rand = new Random();

  public Value getPrimeValue(int len){
    return new Value();
  }

  public Value getRandomValue(int len){

    byte[] value = new byte[len];

    rand.nextBytes(value);

    return new Value(len,value);
  }

  public Value fromLong(long num){

    byte[] value = new byte[8];

    boolean sign = ((num>>63)&0b1)!=1;

    int t=0;

    for(int i=0;i<8;i++){

      if(i==7){
        value[i] = (byte)((num>>(8*i))&0x7F);
      }else{
        value[i] = (byte)((num>>(8*i))&0xFF);
      }

      if(value[i]==0){
        t++;
      }else{
        t=0;
      }
    }


    if(!sign){

      byte[] _2_64 = {(byte)0x00,(byte)0x00,(byte)0x00,(byte)0x00,
        (byte)0x00,(byte)0x00,(byte)0x00,(byte)0x80};

      Value max = new Value(8,_2_64,false);
      return max.plus(new Value(8-t,value,true));

    } else {
      return new Value(8-t,value,true);
    }
  }

  public Value one(){
    byte[] one = {(byte)0x1};
    return new Value(1,one);
  }


  public String hex(byte[] value) {
      char[] HEX_ARRAY = "0123456789ABCDEF".toCharArray();
      char[] hexChars = new char[value.length * 2];

      for (int j = 0; j < value.length; j++) {
          int v = value[value.length-j-1] & 0xFF;
          hexChars[j * 2] = HEX_ARRAY[v >>> 4];
          hexChars[j * 2 + 1] = HEX_ARRAY[v & 0x0F];
      }

      String hex = new String(hexChars);

      return hex;
  }
}
