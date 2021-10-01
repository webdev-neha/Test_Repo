#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string s;
		cin>>n>>s;
		int c=0,maxi=INT_MIN;
		for(int i=1;i<n;i++)
		{
			c=1;
			for(int j=i;j<n;j++)
			{
				if(s[j]==s[j-1])
				{
					break;
				}
				c++;
			}
			maxi=max(c,maxi);
		}
		cout<<maxi<<endl;
	}
	return 0;
}
