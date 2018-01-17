import java.util.Scanner;
import java.math.BigInteger;



public class Main {

    public static long s(long n)
    {
        return n * n;
    }

    public static void main(String[] args) {
        byte[] cts;

        cts = new byte[50000000];

        long top = 1;
        long sub = 0;

        for (; top < 100000000; top++) {
            System.out.println(top);
            //binary search for endpoints, then walk between them
            long low = 1, hi = top / 2;
            //search for the 0 point
            while((hi - low) > 1)
            {
                long mid = (hi + low) / 2;
                if(s(top) - s(top - mid) - s(top - 2 * mid) > 0)
                {
                    //score is too high, need to reduce it by shrinking the progression
                    hi = mid;
                }
                else
                {
                    low = mid;
                }
            }
            long bbound = low;

            low = 1;
            hi = top / 2;
            //search for the 0 point
            while((hi - low) > 1) {
                long mid = (hi + low) / 2;
                if (s(top) - s(top - mid) - s(top - 2 * mid) > 50000000) {
                    hi = mid;
                } else {
                    low = mid;
                }
            }
            long ubound = hi;
            //linear search
            for (sub = bbound; sub < ubound; sub++) {
                if(s(top) - s(top - sub) - s(top - sub - sub) >= 50000000)
                    continue;
                if(s(top) - s(top - sub) - s(top - sub - sub) < 0)
                    continue;
                cts[(int)(s(top) - s(top - sub) - s(top - sub - sub))]++;
            }
        }
        long tot = 0;
        for (byte b: cts) {
            if(b == 1)
                tot++;
        }
        System.out.println(tot);

    }
}
