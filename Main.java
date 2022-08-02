import values.*;

public class Main {

    public static void main(String[] args) {

        // byte[] key = {
        //   (byte)0x00, //1
        //   (byte)0x01, //2
        //   (byte)0x02, //3
        //   (byte)0x03, //4
        //   (byte)0x04, //5
        //   (byte)0x05, //6
        //   (byte)0x06, //7
        //   (byte)0x07, //8
        //   (byte)0x08, //9
        //   (byte)0x09, //10
        //   (byte)0x0a, //11
        //   (byte)0x0b, //12
        //   (byte)0x0c, //13
        //   (byte)0x0d, //14
        //   (byte)0x0e, //15
        //   (byte)0x0f //16
        // };
        //
        // byte[] open = {
        //   (byte)0x00, //1
        //   (byte)0x11, //2
        //   (byte)0x22, //3
        //   (byte)0x33, //4
        //   (byte)0x44, //5
        //   (byte)0x55, //6
        //   (byte)0x66, //7
        //   (byte)0x77, //8
        //   (byte)0x88, //9
        //   (byte)0x99, //10
        //   (byte)0xaa, //11
        //   (byte)0xbb, //12
        //   (byte)0xcc, //13
        //   (byte)0xdd, //14
        //   (byte)0xee, //15
        //   (byte)0xff //16
        // };


       Genesis gen = new Genesis();

       Value _256 = gen.fromLong(256);
       System.out.println(_256.hex());

       System.out.println();

       Value _32 = gen.fromLong(32);
       System.out.println(_32.hex());

       System.out.println();

       Value _224 = _256.minus(_32);
       System.out.println(_224.hex());

       System.out.println();

       Value _480 = _224.plus(_256);
       System.out.println(_480.hex());

       System.out.println();

       Value _2 = gen.fromLong(2);
       Value log = _256.log(_2);
       System.out.println("log: " + log.hex());

       Value pow = _2.pow(_2);
       System.out.println("pow: " + pow.hex());

       System.out.println(_256.decimal());

    }

}
