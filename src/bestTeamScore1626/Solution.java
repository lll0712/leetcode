package bestTeamScore1626;

import java.util.Arrays;

public class Solution {
    public static int bestTeamScore(int[] scores,int[] ages){
        int res=0;
        int n=scores.length;
        int [][] people=new int[n][2];
        for (int i = 0; i < n; i++) {
            people[i][0]=scores[i];
            people[i][1]=ages[i];
        }
        Arrays.sort(people, (a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        int[] dp = new int[n];
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (people[j][1] <= people[i][1]) {
                    dp[i] = Math.max(dp[i], dp[j]);
                }
            }
            dp[i] += people[i][0];
            res = Math.max(res, dp[i]);
        }
        return res;
    }

    public static void main(String[] args) {
        int[] scores =new int[] {4,5,6,5}, ages =new int[] {2,1,2,1};
        System.out.println(bestTeamScore(scores,ages));
        /*int n=scores.length;
        int [][] people=new int[n][2];
        for (int i = 0; i < n; i++) {
            people[i][0]=scores[i];
            people[i][1]=ages[i];
        }
        for (int i = 0; i < n; i++) {
            System.out.println(people[i][0]+"  "+people[i][1]);
        }
        System.out.println("------------------------------");
        Arrays.sort(people, (a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        for (int i = 0; i < n; i++) {
            System.out.println(people[i][0]+"  "+people[i][1]);
        }*/
    }
}
