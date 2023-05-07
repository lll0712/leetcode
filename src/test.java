public class test {
    public static void main(String[] args) {
        int [][] roads=new int[][]{{0,1},{0,3},{1,2},{1,3}};
        int n=4;
        boolean[][] connect = new boolean[n][n];
        int[] degree = new int[n];
        for (int[] v : roads) {
            connect[v[0]][v[1]] = true;
            connect[v[1]][v[0]] = true;
            degree[v[0]]++;
            degree[v[1]]++;
            System.out.println(v[0] + " " + v[1]);

        }

    }
}
