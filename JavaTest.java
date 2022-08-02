import values.*;


public class JavaTest {

   static Value t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,
   t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,
   t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,
   t30,t31,t32,t33,t34,t35;

   public static void setup(){

     Genesis gen = new Genesis();

     //(+) + (+)
     long a = 252334534236l;
     long b = 35345345338l;
     t0 = gen.fromLong(a);
     t1 = gen.fromLong(b);
     t2 = gen.fromLong(a+b);

     //(-) + (+)
     a = -3453535345l;
     b = 56756735355l;
     t3 = gen.fromLong(a);
     t4 = gen.fromLong(b);
     t5 = gen.fromLong(a+b);

     //(+) + (-)
     a = 3463453453353l;
     b = -24234234535423l;
     t6 = gen.fromLong(a);
     t7 = gen.fromLong(b);
     t8 = gen.fromLong(a+b);

     //(-) + (-)
     a = -2342342342l;
     b = -44357345746l;
     t9 = gen.fromLong(a);
     t10 = gen.fromLong(b);
     t11 = gen.fromLong(a+b);

     //(+) - (+)
     a = 789789676l;
     b = 345345345353777l;
     t12 = gen.fromLong(a);
     t13 = gen.fromLong(b);
     t14 = gen.fromLong(a-b);

     //(-) - (+)
     a = -5674564564l;
     b = 47656757526l;
     t15 = gen.fromLong(a);
     t16 = gen.fromLong(b);
     t17 = gen.fromLong(a-b);

     //(+) - (-)
     a = 345789322l;
     b = -4564745858l;
     t18 = gen.fromLong(a);
     t19 = gen.fromLong(b);
     t20 = gen.fromLong(a-b);

     //(-) - (-)
     a = -3467423456324l;
     b = -978597456396l;
     t21 = gen.fromLong(a);
     t22 = gen.fromLong(b);
     t23 = gen.fromLong(a-b);

     //(+) * (+)
     a = 789789676l;
     b = 345345l;
     t24 = gen.fromLong(a);
     t25 = gen.fromLong(b);
     t26 = gen.fromLong(a*b);

     //(-) * (+)
     a = -56745645l;
     b = 476567575l;
     t27 = gen.fromLong(a);
     t28 = gen.fromLong(b);
     t29 = gen.fromLong(a*b);

     //(+) * (-)
     a = 345789322l;
     b = -45647458l;
     t30 = gen.fromLong(a);
     t31 = gen.fromLong(b);
     t32 = gen.fromLong(a*b);

     //(-) * (-)
     a = -34674234l;
     b = -97859745l;
     t33 = gen.fromLong(a);
     t34 = gen.fromLong(b);
     t35 = gen.fromLong(a*b);



   }

   // test method to add two values
   public static void test(){

     System.out.println("t0:");
     System.out.println(t0.plus(t1).hex() + " == " + t2.hex());
     System.out.println();

     System.out.println("t3:");
     System.out.println(t3.plus(t4).hex() + " == " + t5.hex());
     System.out.println();

     System.out.println("t6:");
     System.out.println(t6.plus(t7).hex() + " == " + t8.hex());
     System.out.println();

     System.out.println("t9:");
     System.out.println(t9.plus(t10).hex() + " == " + t11.hex());
     System.out.println();

     System.out.println("t12:");
     System.out.println(t12.minus(t13).hex() + " == " + t14.hex());
     System.out.println();

     System.out.println("t15:");
     System.out.println(t15.minus(t16).hex() + " == " + t17.hex());
     System.out.println();

     System.out.println("t18:");
     System.out.println(t18.minus(t19).hex() + " == " + t20.hex());
     System.out.println();

     System.out.println("t21:");
     System.out.println(t21.minus(t22).hex() + " == " + t23.hex());
     System.out.println();

     System.out.println("t24:");
     System.out.println(t24.times(t25).hex() + " == " + t26.hex());
     System.out.println();

     // System.out.println("t27:");
     // System.out.println(t27.times(t28).hex() + " == " + t29.hex());
     // System.out.println();
     //
     // System.out.println("t30:");
     // System.out.println(t30.times(t31).hex() + " == " + t32.hex());
     // System.out.println();
     //
     // System.out.println("t33:");
     // System.out.println(t33.times(t34).hex() + " == " + t35.hex());
     // System.out.println();

   }

   public static void main(String[] args) {
     setup();
     test();
   }
}
