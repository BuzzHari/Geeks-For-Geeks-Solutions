#include <iostream>

using namespace std;
int main() {

    int t;
    cin >> t;
    int n, m;
    string str1, str2; 
    while(t--) {
        cin >> n >> m;
        
        cin >> str1 >> str2; 
        
        // lcs[i][j] = length of the longest common subsequence in str1(0...i-1) and str2(0..j-1).
        int lcs[str1.size()+1][str2.size()+1];
        for (int i = 0; i <= str1.size(); ++i) {
            for (int j = 0; j <= str2.size(); ++j) {

                if (i == 0 || j == 0)
                    lcs[i][j] = 0;
                
                // If matching characters at the same position, then increment the length. 
                else if (str1[i-1] ==  str2[j-1]) {
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                }
                else 
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);

            }
        }
        cout << lcs[str1.size()][str2.size()]<< "\n"; 
    }

}
