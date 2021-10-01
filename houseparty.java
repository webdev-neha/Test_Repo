class houseparty{
   static public int[] solve(int[] A) {
        int[] b=new int[A.length];
        int counter=0;
        for(int i=0;i<A.length;i++){
            for(int j=0;j<A.length;j++){
                    if(A[i]%A[j]==0 || A[j]%A[i]==0){
                        counter++;
                    }
            }
            b[i]=counter-1;
        }
        return b;
    }
    public static void main(String[] args) {
        int[] A={2,3,4,5,6};
       int[] z=solve(A);
       for(int i=0;i<z.length;i++){
        System.out.print(z[i]+" ");
        }
    }
}