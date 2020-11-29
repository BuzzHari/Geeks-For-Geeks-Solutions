#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>

using namespace std;

int checkPalindrome(string& str, int left, int right) {
    
    for (int i = left, j = right; i<=j; ++i, --j) {
        if (str[i] != str[j])
            return 0;
    }
    
    return 1;
}

int main()
 {
	//code
    int t;
    cin >> t;
    string str;
    while(t--) {
        str = "";
    	cin >> str;
    	int max_left = 0, max_right = 0;
    	for (int i = str.size()-1; i > 0; --i) {
    	    for (int j = 0; j+i < str.size(); ++j) {
    	        if (checkPalindrome(str, j, j+i)) {
    	                max_left = j;
    	                max_right = j+i;
    	                break;
    	        }
    	    }
    	    if (max_right)
    	        break;
    	}
    	
    	for (int i = max_left; i <= max_right; ++i)
    	    cout << str[i];
    	cout << "\n";
    	
    }
	return 0;
}
