#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int n, int w, int v[], int wt[]) {
    int k[n+1][w+1];
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= w; j++) {
            if(i == 0 || j == 0)
                k[i][j] = 0;
            else if(wt[i-1] <= j)
                k[i][j] = max(v[i-1] + k[i-1][j - wt[i-1]], k[i-1][j]);
            else
                k[i][j] = k[i-1][j];
        }
    }

    /* Uncomment the following code to print the knapsack as well */
    // int res = k[n][w];
    // int W = w;
    
    // for(int i = n; i > 0 && res > 0; i--) {
    //     if(res == k[i-1][W])
    //         continue;
    //     else {
    //         cout << v[i-1] << " ";
    //         res -= v[i-1];
    //         W -= wt[i-1];
    //     }
    // }
    // cout << endl;
    return k[n][w];
}

int main()
 {
	//code
	int t, n, w, wt[1000], v[1000];
	cin >> t;
	while(t--) {
	    cin >> n >> w;
	    for(int i = 0; i < n; i++)
	        cin >> v[i];
	        
        for(int i = 0; i < n; i++)
	        cin >> wt[i];
	        
	    cout << knapsack(n, w, v, wt) << endl;
	}
	return 0;
}