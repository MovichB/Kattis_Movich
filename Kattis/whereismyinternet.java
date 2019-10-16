
package internet;
import java.util.*;

class wheresmyinternet {

    static Map<Integer, Set<Integer>> cnx_m;
    private static Scanner sc;
    static int N,M,a,b,co=0;
    static boolean[] cnx ;

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt(); 

        cnx_m = new HashMap<>();
            for (int i = 0; i < N ; i++) {
                cnx_m.put(i, new HashSet<>());
             }

            for (int i = 0; i < M; i++) {
                a = sc.nextInt();
                b = sc.nextInt();
                cnx_m.get(a).add(b);
                cnx_m.get(b).add(a);
            }

        cnx = new boolean[N];

        p_prof(1);

            for (int i = 0; i < N ; i++) {
                if (cnx[i] = false) {
                    co++;
                break;
                }
            }

        if (co > 0) {
            for (int i = 0; i <= N-1 ; i++) {
                if (cnx[i] = false) {
                    System.out.println(i+ "\n");
                }
            }
        }
         else {
            System.out.println("Connected");
        }
    }

    static void p_prof(int m1) { //m1=maison 1
            int i=0;
            cnx[m1] = true;
            while(cnx_m.get(m1) != null) {
                if (cnx[i] = false) {
                    p_prof(i++);
            }
        }
    }
}

