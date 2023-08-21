package TCT.java;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class 전보 {
    public static int[] d;
    public static ArrayList<Node>[] city;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        d = new int[n + 1];
        city = new ArrayList[n + 1];
        Arrays.fill(d, 987654321);//최단거리 테이블 초기화
        for (int i = 1; i <= n; i++) city[i] = new ArrayList<>();
        int m = Integer.parseInt(s[1]);
        int c = Integer.parseInt(s[2]);//보내는 도시
        for (int i = 0; i < m; i++) {
            String[] input = br.readLine().split(" ");
            city[Integer.parseInt(input[0])].add(new Node(Integer.parseInt(input[1]), Integer.parseInt(input[2])));
        }
        dijkstra(c);
        int num = 0;
        int time = 0;
        for (int i = 1; i <= n; i++) {
            if (i == c) continue;
            if (d[i] < 987654321) {
                num++;
                time = Math.max(time, d[i]);
            }
        }
        System.out.println(num + " " + time);
    }

    private static void dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(start, 0));
        d[start] = 0;

        while (!pq.isEmpty()) {//우선순위 큐가 빌 때까지
            //가장 비용이 작은 노드에 대한 정보 꺼내기
            Node node = pq.poll();
            int cost = node.getCost();
            int now = node.getIndex();
            if (d[now] < cost) continue;//최단거리보다 더 큰 비용일 경우

            //현재 노드와 인접한 노드들 확인
            for (int i = 0; i < city[now].size(); i++) {//이어진 간선 개수만큼
                int newCost = d[now] + city[now].get(i).getCost();//현재 노드를 거쳐서 가는 비용
                if (newCost < d[city[now].get(i).getIndex()]) {//현재 노드를 거쳐서 이동하는 비용이 더 적은 경우
                    d[city[now].get(i).getIndex()] = newCost;
                    pq.offer(new Node(city[now].get(i).getIndex(), newCost));
                }
            }
        }
    }

    public static class Node implements Comparable<Node> {
        int index;//to
        int cost;//비용

        public Node(int index, int cost) {
            this.index = index;
            this.cost = cost;
        }

        public int getIndex() {
            return index;
        }

        public int getCost() {
            return cost;
        }
        @Override
        public int compareTo(Node o) { //비용이 적은 순으로 정렬되도록
            return o.cost - this.cost;
        }
    }
}
