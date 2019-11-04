#include<bits/stdc++.h>
using namespace std;

int coin(int n, int m, vector<int> v) {
    int coinVal[n+1][m];
    
    int w, wo;
    
    for(int i = 0; i < m; i++)
        coinVal[0][i] = 1;
        
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            w = (i - v[j]) >= 0 ? coinVal[i - v[j]][j] : 0;
            wo = (j >= 1) ? coinVal[i][j - 1] : 0;
            
            coinVal[i][j] = w + wo;
        }
    }
    
    return coinVal[n][m-1];
}

int main()
 {
	//code
	int t, m, n, in;
	cin >> t;
	while(t--) {
	    cin >> m;
	    vector<int> v;
	    for(int i = 0; i < m; i++) {
	        cin >> in;
	        v.push_back(in);
	    }
	    cin >> n;
	    cout << coin(n, m, v) << endl;
	}
	return 0;
}