class Solution {
    public boolean isPalindrome(String s) {
        
        s=s.toLowerCase();
        s=s.trim();
        s=s.replaceAll("\\s","");
        s=s.replaceAll("[^a-zA-Z0-9]", "");
        
        Stack<Character> st=new Stack<>();
        
        if(s.length()%2==0)
        {
            for(int i=0;i<s.length()/2;i++)
            {
                st.push(s.charAt(i));
            }
        
            for(int i=s.length()/2;i<s.length();i++)
            {
                if(st.pop()!=s.charAt(i))
                {
                    return false;
                }
            }
        }
        else{
            for(int i=0;i<s.length()/2;i++)
            {
                st.push(s.charAt(i));
            }
        
            for(int i=s.length()/2+1;i<s.length();i++)
            {
                if(st.pop()!=s.charAt(i))
                {
                    return false;
                }
            }
        }
        return true;
    }
}
