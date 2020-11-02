// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        // minop[i] = min operations to get the number 'i', using the two given
        // operations.
        int minop[n+1];
        minop[0] = 0;
        for (int i = 1; i <=n; ++i) {
            minop[i] = 1+minop[i-1];
            if (i%2 == 0) 
                minop[i] = min(minop[i], 1+minop[i/2]);
        }
        
        return minop[n];
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}  // } Driver Code Ends
