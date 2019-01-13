import java.io.*;
import java.util.*;
@SuppressWarnings("unchecked")
public class disrupt
{
   static long time = System.currentTimeMillis();
   static LCANode[] nodes;
   static ArrayList<Integer>[] conn;
   static int[] best;
   static int infix = 0;
   static HashMap<Integer, HashMap<Integer, Integer>> map = new HashMap<Integer, HashMap<Integer, Integer>>();
   public static void main(String[] args) throws Exception 
   {
      FastReader infile = new FastReader("disrupt.in");
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("disrupt.out")));
      int N = infile.nextInt();
      int M = infile.nextInt();
      int[][] path = new int[N-1][2];
      best = new int[N];
      nodes = new LCANode[N+1];
      conn = new ArrayList[N+1];
      for(int x = 1; x <= N; x++)
         conn[x] = new ArrayList<Integer>();
      for(int x = 0; x < N-1; x++)
      {
         for(int y = 0; y < 2; y++)
            path[x][y] = infile.nextInt();
         conn[path[x][0]].add(path[x][1]);
         conn[path[x][1]].add(path[x][0]);
         int min = Math.min(path[x][0], path[x][1]);
         int max = Math.max(path[x][0], path[x][1]);
         if(map.get(min)==null)
            map.put(min, new HashMap<Integer, Integer>());
         map.get(min).put(max, x);
      }
      dfs(1, -1);
      Arrays.fill(best, Integer.MAX_VALUE);
      Triple[] triple = new Triple[M];
      for(int x = 0; x < M; x++)
      {
         int a = infile.nextInt();
         int b = infile.nextInt();
         int dist = infile.nextInt();
         triple[x] = new Triple(a, b, dist);
      }
      Arrays.sort(triple);
      HashSet<Integer> set = new HashSet<Integer>();
      for(int x = 0; x < N; x++)
         set.add(x);
      for(int x = 0; x < M; x++)
      {
         int a = triple[x].x;
         int b = triple[x].y;
         int dist = triple[x].dist;
         LCANode n1 = nodes[a];
         LCANode n2 = nodes[b];
         LCANode anc = LCANode.findLCA(n1, n2);
         while(!n1.equals(anc))
         {
            int min = Math.min(n1.id, n1.parent.id);
            int max = Math.max(n1.id, n1.parent.id);
            int index = map.get(min).get(max); 
            if(set.contains(index))
            {
               best[index] = dist;
               set.remove(index);
            }
            n1 = n1.parent;
         }
         while(!n2.equals(anc))
         {
            int min = Math.min(n2.id, n2.parent.id);
            int max = Math.max(n2.id, n2.parent.id);
            int index = map.get(min).get(max);  
            if(set.contains(index))
            {
               best[index] = dist;
               set.remove(index);
            }
            n2 = n2.parent;
         }
         if(set.isEmpty())
            break;
      }
      //Arrays.sort(repl);
      StringBuilder sb = new StringBuilder();
      for(int x = 0; x < N-1; x++)
      {
         if(best[x]==Integer.MAX_VALUE)
            best[x] = -1;
         sb.append(best[x]).append("\n");
      }
      out.print(sb);
      out.close();
      System.out.println(System.currentTimeMillis()-time);
   }
   public static void dfs(int id, int prev)
   {
      LCANode par;
      if(prev==-1)
         par = null;
      else
         par = nodes[prev];
      nodes[id] = new LCANode(id, 0, par);
      nodes[id].createAncestors();
      for(int i: conn[id])
         if(i!=prev)
         {
            dfs(i, id);
         }
   }
} 
class Triple implements Comparable<Triple>
{
   int x, y, dist;
   public Triple(int a, int b, int d)
   {
      x = a;
      y = b;
      dist = d;
   }
   public int compareTo(Triple t)
   {
      return dist-t.dist;
   }
}
class LCANode
{
   final static int MAXANCESTORS = 20;
   int id;
   int depth;
   int val;
   LCANode parent = null;
   LCANode[] ancestors = null;
   public LCANode(int i, int v, LCANode p)
   {
      id = i;
      val = v;
      parent = p;
   }
   public void createAncestors()
   {
      ancestors = new LCANode[MAXANCESTORS];
      ancestors[0] = parent;
      if(ancestors[0]==null)
      {
         depth = 0;
         return;
      }
      depth = ancestors[0].depth+1;
      for(int x = 1; x < ancestors.length; x++)
         if(ancestors[x-1]!=null)
            ancestors[x] = ancestors[x-1].ancestors[x-1];
   }
   public static LCANode findLCA(LCANode n1, LCANode n2)
   {
      if(n1.depth!=n2.depth)       
      {
         if(n1.depth<n2.depth)
         {
            LCANode temp = n1;
            n1 = n2;
            n2 = temp;
         }
         int k = n1.depth-n2.depth;
         for(int x = n1.ancestors.length-1; x >= 0; x--)
            if(n1.ancestors[x]!=null)
               if(Math.pow(2, x)<=k)
               {
                  k-=(int)Math.pow(2, x);
                  n1 = n1.ancestors[x];
               }
      }
      if(n1.equals(n2))
         return n1;
      for(int x = n1.ancestors.length-1; x >= 0; x--)
         if(n1.ancestors[x]!=null)
            if(!n1.ancestors[x].equals(n2.ancestors[x]))
            {
               n1 = n1.ancestors[x];
               n2 = n2.ancestors[x];
            }
      return n1.ancestors[0];
   }
   public boolean equals(Object o)
   {
      LCANode node = (LCANode) o;
      return id==node.id;
   }
   public String toString()
   {
      return id+"";
   }
}
class FastReader
{
   BufferedReader br;
   StringTokenizer st;

   public FastReader(String file) throws FileNotFoundException
   {
      br = new BufferedReader(new FileReader(file));
   }
 
   String next()
   {
      while (st == null || !st.hasMoreElements())
      {
         try
         {
            st = new StringTokenizer(br.readLine());
         }
         catch (IOException  e)
         {
            e.printStackTrace();
         }
      }
      return st.nextToken();
   }
 
   int nextInt()
   {
      return Integer.parseInt(next());
   }
 
   long nextLong()
   {
      return Long.parseLong(next());
   }
 
   double nextDouble()
   {
      return Double.parseDouble(next());
   }
 
   String nextLine()
   {
      String str = "";
      try
      {
         str = br.readLine();
      }
      catch (IOException e)
      {
         e.printStackTrace();
      }
      return str;
   }
}