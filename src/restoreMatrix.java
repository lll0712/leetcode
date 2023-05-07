/**
 * 给你两个非负整数数组rowSum 和colSum，其中rowSum[i]是二维矩阵中第 i行元素的和， colSum[j]是第 j列元素的和。
 * 换言之你不知道矩阵里的每个元素，但是你知道每一行和每一列的和。 请找到大小为rowSum.length x colSum.length的任意
 * 非负整数矩阵，且该矩阵满足rowSum 和colSum的要求。 请你返回任意一个满足题目要求的二维矩阵，题目保证存在 至少一个可行矩阵。
 */
public class restoreMatrix {
    public static int[][] restore(int[] rowSum, int[] colSum) {
        int n = rowSum.length, m = colSum.length;
        int[][] matrix = new int[n][m];
        int i = 0, j = 0;
        while (i < n && j < m) {
            int v = Math.min(rowSum[i], colSum[j]);
            matrix[i][j] = v;
            rowSum[i] -= v;
            colSum[j] -= v;
            if (rowSum[i] == 0)
                ++i;
            if (colSum[j] == 0)
                ++j;
        }
        return matrix;
    }

    public static void main(String[] args) {
        int[] rowSum = new int[]{5, 7, 10};
        int[] colSum = new int[]{8, 6, 8};
        int[][] matrix = restore(rowSum, colSum);
        for (int i = 0; i < rowSum.length; i++) {
            for (int j = 0; j < colSum.length; j++)
                System.out.print(matrix[i][j]);
            System.out.println();
        }
    }
}
