// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

bool cmp(const val &a, const val &b) {
    return a.first < b.first;
}

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
    // This problem can be solved greedily in nlogn, 
    // but I solved it using DP for practice reasons lol.
    // To solve it greedily, sort it based on the second value, and just greedily pick the
    // pairs.

    // Sort the pairs, as the order doesn't matter here. 
    sort(p, p+n, cmp);
    // maxLen[i] = lenght of max chain formed, which ends at pair 'i'.  
    int maxLen[n];
    maxLen[0] = 1;
    int tmp_max = 1;
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        tmp_max = 1;
        for (int j = 0; j < i; ++j) {
            if (p[j].second < p[i].first)
                tmp_max = max(tmp_max, 1+maxLen[j]);
        }
        maxLen[i] = tmp_max;
        if (maxLen[i] > ans)
            ans = maxLen[i];
    }

    return ans;
    
}
