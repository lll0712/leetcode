package countSubarrays;

import java.util.HashMap;
import java.util.Map;

public class Solution {
    public static int countSubArrays(int[] nums, int k){
        int kIndex=0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i]==k){
                kIndex=i;
                break;
            }
        }
        int ans=0;
        Map<Integer,Integer> count= new HashMap<>();
        count.put(0,1);
        int sum=0;

        for (int i = 0; i < nums.length; i++) {
            sum+=sign(nums[i]-k);
            if (i<kIndex){
                count.put(sum,count.getOrDefault(sum,0)+1);
            }else {
                int m=count.getOrDefault(sum,0);
                int n=count.getOrDefault(sum-1,0);
                ans+=m+n;
            }
        }

        return ans;

    }
    public static int sign(int n){
        if(n==0)
            return 0;
        return (n>0)?1:-1;
    }

    public static void main(String[] args) {
        int[] nums=new int[]{3,2,1,4,5};
        System.out.println(countSubArrays(nums,4));
    }
}
