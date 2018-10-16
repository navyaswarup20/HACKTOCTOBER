/*
Question:
Genghis Khan, the founder and the first Great Khan of Mongol Empire is about to conquer Eurasia. His third son, Ögedei Khan divided Eurasia into R regions for strategical purposes. For each region Ri, his army is divided into N different contingents of sizes c0, c1 . . . , cN-1.
The general of each region wants to redistribute the soldiers in such a way that all the contingents for that region have equal number of soldiers, by sending soldiers from larger contingents to smaller ones. In case the number of soldiers is not enough to be divided into equal contingents, he decides to either add more soldiers, or remove some soldiers from the overall army whichever is lesser in number such that now they can be divided in a way where all the contigents have equal number of soldiers. Help Genghis Khan conquer Eurasia!

Input Format
First line of input contains R, number of regions.
Each region Ri is described by two lines. The first line contains N, the number of contigents and the second line contains the array c.

Constraints
1 <= R, N, ci <= 1000

Output Format
For each region print the total number of soldiers redistributed or added or removed as per the given conditions on a new line.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        int r, i, j, k, sum = 0, n;
    cin >> r;
    for(i = 0; i < r; i++){
        cin >> n;
        int c[n];
        sum = 0;
        for(j = 0; j < n; j++){
            cin >> c[j];
            sum += c[j];
        }
        k = sum / n;
        k *= n;
        int tot = 0;

        if(sum == k){
            k = sum / n;
            for(int z = 0; z < n; z++){
                if(c[z] < k)
                    tot += k - c[z];
            }
        }
        else{
            k = sum / n;
            if((n*(k+1) - sum) >= (sum - n*k))
                tot += sum - n*k;
            else if((n*(k+1) - sum) < (sum - n*k))
                tot += n * (k + 1) - sum;
            else
                tot += 0;
        }
        cout << tot <<  endl;
    }
    return 0;
}
