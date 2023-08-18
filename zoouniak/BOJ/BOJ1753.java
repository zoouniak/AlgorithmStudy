package BOJ;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class BOJ1753 {
    static ArrayList<Node>[] graph;
    static int[] d;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String[] s = br.readLine().split(" ");
        int v = Integer.parseInt(s[0]);
        graph = new ArrayList[v + 1];
        d = new int[v + 1];
        Arrays.fill(d, 987654321);
        for (int i = 1; i <= v; i++) {
            graph[i] = new ArrayList();
        }
        int e = Integer.parseInt(s[1]);
        int k = Integer.parseInt(br.readLine());
        for (int i = 0; i < e; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < 3; j++) {
                graph[Integer.parseInt(input[0])].add(new Node(Integer.parseInt(input[1]), Integer.parseInt(input[2])));
            }
        }
        Dijkstra(k);
        for (int i = 1; i < v + 1; i++) {
            if (i == k) {
                sb.append(0).append("\n");
            } else if (d[i] >= 987654321) {
                sb.append("INF").append("\n");
            } else {
                sb.append(d[i]).append("\n");
            }
        }
        System.out.print(sb);

    }

    public static void Dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue();
        pq.add(new Node(start, 0));
        d[start] = 0;
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int now = node.v;
            int weight = node.weight;
            if (d[now] < weight) continue;
            for (int i = 0; i < graph[now].size(); i++) {
                int newWeight = d[now] + graph[now].get(i).weight;
                if (d[graph[now].get(i).v] > newWeight) {
                    d[graph[now].get(i).v] = newWeight;
                    pq.offer(new Node(graph[now].get(i).v, newWeight));
                }
            }
        }

    }

    public static class Node implements Comparable<Node> {
        int v;
        int weight;

        public Node(int v, int weight) {
            this.v = v;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            return this.weight - o.weight;
        }
    }
}
