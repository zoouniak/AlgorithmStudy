package BOJ;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class BOJ18352 {
    //그래프 각 도시들에 이어진 간선을 저장하자
    static ArrayList<Node>[] city;
    static int[] d;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        city = new ArrayList[n+1];
        for(int i=1;i<n+1;i++){
            city[i]= new ArrayList<>();
        }
        d=new int[n+1];
        Arrays.fill(d,987654321);
        int m = Integer.parseInt(s[1]);
        int k = Integer.parseInt(s[2]);
        int x = Integer.parseInt(s[3]);
        for(int i=0;i<m;i++){
            String[] input = br.readLine().split(" ");
            city[Integer.parseInt(input[0])].add(new Node(Integer.parseInt(input[1]),1));
        }
        dijkstra(x);
        int result=0;
        for(int i=1;i<n+1;i++) {
            if(d[i]==k){
                bw.write(i+"\n");
                result++;
            }
            System.out.println(d[i]);
        }
        System.out.println("==" );
        if(result==0) System.out.println(-1);
        else bw.flush();
    }

    private static void dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(start,0));
        d[start]=0;
        while (!pq.isEmpty()){
            Node node = pq.poll();
            int now = node.to;
            int cost = node.cost;
            if(d[now]<cost)continue;
            for(int i=0;i<city[now].size();i++){//얘를 거쳐가는 경우의 수를 모두보자
                int newCost = d[now]+city[now].get(i).cost;
                if(newCost<d[city[now].get(i).to]){//거쳐가는 경우가 더 짧은 경로일경우
                    d[city[now].get(i).to]=newCost;
                    pq.offer(new Node(city[now].get(i).to,newCost));
                }
            }
        }
    }

    public static class Node implements Comparable<Node> {
        int to;
        int cost;

        public Node(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
        @Override
        public int compareTo(Node o) {
            return this.cost-o.cost;
        }
    }
}
