import java.util.*;
public class Solution{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int max = 0,count = 0;
        int l = s.length();

        for(int i=0;i<l-1;++i)
        {
            if(s.charAt(i)!=s.charAt(i+1))
            count++;
            else
            count = 0;


            if(count>max)
            max = count;
        }

        System.out.println(max);
    }
}