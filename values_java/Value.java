package values;

import java.lang.Math;

public class Value{

  Genesis gen = new Genesis();

  public byte[] value;
  public boolean sign;

  public Value(){
    value = new byte[1];
    value[0] = (byte)0x00;
    sign = true;
  }

  public Value(int len, byte[] val){
    value = new byte[len];
    value = subArray(val,0,len);
    sign = true;
  }

  public Value(int len, byte[] val, boolean sign){
    value = new byte[len];
    value = subArray(val,0,len);
    this.sign = sign;
  }

  public int len(){
    return value.length;
  }

  public Value plus(Value val){

    byte[] aVal = value;
    byte[] bVal = val.value;

    boolean s = sign;
    int len = 0;
    int blen = 0;

    if(sign != val.sign){
      return minus(new Value(val.len(),bVal,!val.sign));
    }

    if(len() > val.len()){
      len = len();
      blen = val.len();
    }else{
      len = val.len();
      blen = len();
      aVal = val.value;
      bVal = value;
    }

    byte[] temp = new byte[len+1];

    int r = 0;
    int o = 0;
    int b = 0;
    int a = 0;
    int t = 0;

    for(int i=0;i<len;i++){

      if(i>=blen){
        b = 0;
      } else {
        b = (int)(bVal[i]&0xff);
       }

       a = (int)(aVal[i]&0xff);

      r = a+b+o;

      o = (r>>8)&0b1;

      temp[i] = (byte)r;
      t=i;
    }

    if(o>0){
      temp[t+1] = (byte)o;
      return new Value(len+1,temp,s);
    } else {
      return new Value(len,temp,s);
    }
  }

  public Value minus(Value val){

    byte[] aVal = value;
    byte[] bVal = val.value;

    boolean s = sign;
    int len = 0;
    int blen = 0;

    if(sign != val.sign){
      return plus(new Value(val.len(),bVal,!val.sign));
    }

    if(this.isGreater(val)){
      len = len();
      blen = val.len();
    }else{
      len = val.len();
      blen = len();
      aVal = val.value;
      bVal = value;
      s = !s;
    }

    byte[] rVal = new byte[len];

    int r = 0;
    int o = 0;
    int b = 0;
    int a = 0;
    int l = 0;

    for(int i=0;i<len;i++){

      if(i>=blen){
        b = 0;
      } else {
       b = (int)(bVal[i]&0xff);
      }

      a = (int)(aVal[i]&0xff);

     r = a+o-b;

    if(r<0){o=-1;r=r+256;} else {o=0;}

     rVal[i] = (byte)(r&0xFF);
     if(rVal[i]==0){
       l++;
     }else{
       l=0;
     }

    }

    return new Value(len-l,rVal,s);
  }


  public Value times(Value val){

    byte[] zero = {(byte)0x00};

    Value result = new Value(1,zero,sign);
    Value one = gen.one();
    boolean s = true;

    if(val.sign^sign){s=false;}

    if(!val.sign){
      val = new Value(val.len(),val.value,!val.sign);
    }

    while(!val.isZero()){
      System.out.println(val.hex());
      result = result.plus(this);
      val = val.minus(one);
    }

    result.sign = s;

    return result;
  }

  public Value div(Value val){

    Value remainder = new Value(len(),value,sign);
    Value result = new Value();
    Value one = gen.one();
    boolean s = true;

    if(sign!=val.sign){
      val = new Value(val.len(),val.value,!val.sign);
      s = false;
    }

    if(val.isZero()){
      return remainder;
    }

    while(remainder.isGreater(val)||remainder.minus(val).isZero()){
      remainder = remainder.minus(val);
      result = result.plus(one);
    }

    result.sign = s;

    return result;
  }

  public Value pow(Value val){

    Value result = new Value(len(),value,sign);
    Value one = gen.one();

    if(!val.sign){
      val = new Value(val.len(),val.value,!val.sign);
      val = val.minus(one);
      return this.div(this.pow(val));
    }

    if(val.isZero()){
      result = new Value();
    } else {
      val = val.minus(one);
    }

    while(!val.isZero()){
      result = result.times(this);
      val = val.minus(one);
    }

    return result;
  }

  public Value log(Value val){

    Value leftOver = new Value(len(),value,sign);
    Value result = new Value();
    Value one = gen.one();


    while(leftOver.isGreater(val)||leftOver.minus(val).isZero()){
      leftOver = leftOver.div(val);
      result = result.plus(one);
    }

    return result;

  }

  public Value mod(Value val){

    Value remainder = new Value(len(),value,sign);

    while(remainder.isGreater(val)||remainder.minus(val).isZero()){
      remainder=remainder.minus(val);
    }

    return remainder;
  }

  public Value invMod(Value val){
    return new Value();
  }

  public boolean isZero(){
    for(int b=0;b<len();b++){
      if(value[b]!=0){return false;}
    }
    return true;
  }

  public boolean isGreater(Value val){

    byte[] aVal = value;
    byte[] bVal = val.value;

    int len = 0;
    boolean res = true;

    if(len() == val.len()){
      len = len();
    }else{
      return len() > val.len();
    }

    for(int i=len-1;i>=0;i--){
      for(int t=7;t>=0;t--){
        boolean a = ((aVal[i]>>t)&1) == 1;
        boolean b = ((bVal[i]>>t)&1) == 1;

        if(a && !b){return true;}

        if(b && !a){return false;}

      }
    }

    System.out.println("I am trash, " + hex() +" : "+ val.hex());
    return false;

  }

  private int bitLen(){
    int l = 0;
    for(int i=7;i>=0;i--){
      boolean a = ((value[len()-1]>>i)&1) == 1;
      if(a){
        l = i;
        break;
      }
    }
    return (len()-1)*8 + l + 1;
  }

  public String hex() {
      char[] HEX_ARRAY = "0123456789ABCDEF".toCharArray();
      char[] hexChars = new char[len() * 2];

      for (int j = 0; j < len(); j++) {
          int v = value[len()-1-j] & 0xFF;
          hexChars[j * 2] = HEX_ARRAY[v >>> 4];
          hexChars[j * 2 + 1] = HEX_ARRAY[v & 0x0F];
      }

      String hex = new String(hexChars);

      if(!sign){
        return "-"+hex;
      }
      return hex;
  }

  public String decimal(){

    Value temp = this;
    Value len = gen.fromLong((len()*8));
    Value two = gen.fromLong(2);
    Value ten = gen.fromLong(10);

    int powersOfTen = 0;//two.pow(len).log(ten).toInt();
    char[] string = new char[powersOfTen+1];

    for(int i=powersOfTen;i>=0;i--){

      Value degree = gen.fromLong(i);
      Value div = temp.div(ten.pow(degree));

      if(!div.isZero()){
        temp = temp.minus(div.times(ten.pow(degree)));
        //string[powersOfTen-i] = (char)(div.toInt()+48);
      }

    }

    return new String(string);
  }

  private byte[] subArray(byte[] array,int s, int e){

    byte[] subArray = new byte[e-s];

    int t=0;
    for(int i=s;i<e;i++){
      subArray[t] = array[i];
      t++;
    }

    return subArray;
  }

}
