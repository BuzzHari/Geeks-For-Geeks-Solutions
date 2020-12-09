// { Driver Code Starts
// driver code

#include<bits/stdc++.h>
using namespace std;

string LongestPalindromeSubString(string text);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<< LongestPalindromeSubString(s) << endl;
    }
    return 1;
}
// } Driver Code Ends


// return the longest palindrome substring

string LongestPalindromeSubString(string text)
{
    // code here
    int n = 2*text.size()+1;
    int lps[n];
    memset(lps, 0, n*sizeof(int));
    
    /*
        0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
        | a | b | a | b | a |  b  |  a  |
    */
    
    
    // Initializing the first empty char and the first char
    // of string
    lps[0] = 0;
    lps[1] = 1;
    
    
    // Center of the the main palindrome.
    int center = 1;
    // Right end of the main plaindrome.
    int right = 2;
    int maxLen = lps[1];
    int mid = 1;
    int mirror;
  //  cout << lps[0] << " " << lps[1] << " ";

    for (int i = 2; i < n; ++i) {
        mirror = 2*center-i;
        
        // If the current center is part of the main palindrome.
        // Then update lps[i] with it's mirror or right-i (expanding towards left case).
        if (i < right)
            lps[i] = min(lps[mirror], right-i);
        
        // expand
        while( ((i-lps[i]) > 0 && (i+lps[i] < n))  && 
                (((i+lps[i]+1)%2 == 0) || (text[(i+lps[i]+1)/2] == text[(i-lps[i]-1)/2])))
                ++lps[i];
        
        if (lps[i] > maxLen) {
            maxLen = lps[i];
            mid = i;
        }
        
        // Update the new center when subplaindrom extends
        // more than the main palindrome. 
        if (i+lps[i] > right) {
            center = i;
            right = i+lps[i];
        }
        
       // cout << lps[i] << " ";
    }
    
   // cout << endl;
   // cout << mid << " " << maxLen << "\n";
  
    int start = (mid - maxLen)/2;
    int end = start + maxLen  - 1;
    string ans(text, start, end-start+1);
    
    return ans;
}

