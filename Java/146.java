import java.util.Scanner;
import java.math.BigInteger;



public class Main {

    public static void main(String[] args) {

        System.out.println("start");
        long ct = 0;
        long sum = 0;
        for (long i = 10; i < 150000000; i = i + 10) {
            if ((((i * i) + 2) % 3) != 0)
                continue;
            if (((i * i + 4) % 7) != 0 && ((i * i + 5) % 7) != 0)
                continue;
            if ((i * i) % 13 == 0)
                continue;

            if(BigInteger.valueOf((i * i) + 1).isProbablePrime(3) &&
                BigInteger.valueOf(((i * i) + 3)).isProbablePrime(3) &&
                BigInteger.valueOf(((i * i) + 7)).isProbablePrime(3) &&
                BigInteger.valueOf(((i * i) + 9)).isProbablePrime(3) &&
                BigInteger.valueOf(((i * i) + 13)).isProbablePrime(3) &&
                BigInteger.valueOf(((i * i) + 27)).isProbablePrime(3) &&
                !BigInteger.valueOf(((i * i) + 19)).isProbablePrime(3) &&
                !BigInteger.valueOf(((i * i) + 21)).isProbablePrime(3)) {
                System.out.println(i);
                sum += i;
                ct++;
            }
        }
        System.out.println("end");

        System.out.println(ct);
        System.out.println(sum);

    }
}
