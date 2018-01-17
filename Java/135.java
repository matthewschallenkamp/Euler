import java.util.Scanner;
import java.math.BigInteger;



public class Main {

    public static long s(long n)
    {
        return n * n;
    }

    public static void main(String[] args) {
        byte[] cts;

        cts = new byte[1000000];

        long top = 1;
        long sub = 0;

        for (; top <= 10000000; top++) {
            System.out.println(top);
            for (sub = top / 4 + 1; top - sub > 0; sub++) {
                long val = (4 * sub - top) * top;

                if (val >= 1000000) {
                    break;
                }
                cts[(int)val]++;
            }
        }
        long tot = 0;
        for (int i = 0; i < 1000000; i++) {
            if(cts[i] == 10) {
                tot++;
                System.out.println(i);
            }
        }
        System.out.println(tot);

    }
}
