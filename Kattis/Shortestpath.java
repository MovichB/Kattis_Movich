import java.awt.Point;
import java.io.*;
import java.util.*;
class noeud implements Comparable<noeud>{
    public int id;
    public Map<Integer, Set<Point>> chemins;
    public Integer dst = Integer.MAX_VALUE;
    public noeud prec;
    public int compareTo(noeud n){
        return dst-n.dst;       
    }
    public noeud(int id){
        this.id = id;
    }
}
class arete {
    public noeud destination;
    public int poids;
    public arete(noeud destination, int poids) {
        this.destination = destination;
        this.poids = poids;
    }
}
 class Graph {
     public  Map<Integer, Set<Point>> noeuds;
     public int n;
        public Graph(int n){
            noeuds = new HashMap<>();
             for (int i = 0; i < (this.n = n); i++) {
                 noeuds.put(i, new HashSet<>());
            }
        }
        public void _arete(int u, int v, int p){
            noeuds.get(u).add(new Point(v, p));
        }
    }
public class Shortestpath { 
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));

        public static void shortestpath() throws NumberFormatException, IOException{
            String l;
            while (!(l=sc.readLine()).equals("0 0 0 0")) {
                String[] ligne  = l.split(" ");
                int n = Integer.parseInt(ligne[0]);
                int m = Integer.parseInt(ligne[1]);
                int q = Integer.parseInt(ligne[2]);
                int s = Integer.parseInt(ligne[3]);
               Graph g = new Graph(n);
                for (int i = 0; i < m; i++) {
                    ligne = sc.readLine().split(" ");
                    int  u = Integer.parseInt(ligne[0]);
                    int  v = Integer.parseInt(ligne[1]);
                    int  w = Integer.parseInt(ligne[2]);
                    g._arete(u,v,w);
                    }
                dijkstra(g,s,q);
            }
     }
     public static void dijkstra(Graph g, int s, int q) throws NumberFormatException, IOException {
            int[] dis = new int[g.n];
            boolean[] visited = new boolean[g.n];
            for (int i = 0; i < dis.length; i++) {
                dis[i] = Integer.MAX_VALUE;
            }
            dis[s] = 0;
            for(int i=0; i<g.n; i++) {
                int min = Integer.MAX_VALUE;
                int I = -1;
                for(int i1=0;i1<dis.length;i1++)
                      if(!visited[i1] && dis[i1] < min) {
                          min = dis[I = i1];
                      }
                if(I == -1) continue;
                visited[I] = true;

                for (Point p : g.noeuds.get(I))
                    if(!visited[p.x] && dis[I]+p.y<dis[p.x])
                        dis[p.x] = dis[I]+p.y;
            }
            
            for (int i = 0; i < q; i++) {
                int dst = dis[Integer.parseInt(sc.readLine())];
                if (dst == Integer.MAX_VALUE) {
                    System.out.println("Impossible");
                } else {
                    System.out.println(dst);
                }
            }
        }

        public static void main(String[] args) throws IOException{
            shortestpath();
        }
}