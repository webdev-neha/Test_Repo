//Maximum of Sub array in an given array

#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define t int 
#define in cin
#define ff vector<int>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vp(it,arr)  for(auto it:arr){cout<<it<<;}
#define LOOP(i,a,b) for(int i=a;i<b;i++)
using namespace std;

void print_max_in_all_subarray(int arr[],int k,int n){
   cout<<n<<endl;
      deque<int>arru;
      arru.push_front(0);
      for(int i=1;i<k;i++){
          if(arr[i]>arr[arru.front()]){
              arru.pop_back();
              arru.push_back(i);
          }else{
              arru.push_back(i);
          }
      }
      for(int c=k;c<n;c++){
          cout<<arr[arru.front()]<<" ";
           if(arr[c]>arr[arru.front()]){
              arru.pop_back();
              while(arr[arru.front()]<arr[c]&&arru.empty()==false){
                      arru.pop_back();
              }
              arru.push_back(c);
          }else{
              arru.push_back(c);
          }


          if(arru.front()<=c-k){
              arru.pop_front();
          }

      }

cout<<arr[arru.front()]<<endl;
return;

}



int main(){
int arru[]={1,2,3,1,4,5,2,3,6};
 int n=(sizeof(arru)/sizeof(arru[0]));
print_max_in_all_subarray(arru,3,n);

return 0;
}