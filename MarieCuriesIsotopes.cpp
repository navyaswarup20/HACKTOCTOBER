/*
Question:
Marie Curie, the first woman to win Nobel Prize was always fond of radioactivity. One day she was teaching her equally intelligent daughter Irène Joliot-Curie, who also won a Nobel Prize about various isotopes of a radioactive element. Marie decided to name the 26 isotopes with english alphabets 'a', 'b', 'c', . . . , 'z'.
To check Irène's memory, Marie gives her t strings, s0, s1 . . . st-1 consisting of different isotopes and a number k with each string. Help Irène identify if she can get all the 26 isotopes by adding at most k distinct isotopes. She needs to check this for all the strings.

Input Format:
First line contains t, number of strings.
Each of the next ith line contains the string si and the number k with a space in between

Constraints:
1 <= t <= 1000
1 <= |si| <= 100
1 <= k <= 30

Output Format:
For every string si print yes if there exists a solution or else no on the ith line.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, i, j, k;
    cin >> t;
    for(int z = 0; z < t; z++){
        string s;
        cin >> s;
        cin >> k;
        int n = s.length();
            /*int[] count = new int[256];

            for(int x = 0; x < n; x++){
                count[(int)s.charAt(x)]++;
            }

            for(int i = 0; i < n; i++){
                if(count[(int)s.charAt(i)] == 1){
                    if(count[(int)s.charAt(i)] + k >= 26)
                        System.out.println("yes");
                    else
                        System.out.println("no");
                }
            }*/
        int ar[n] = {0};
            //fill(ar, 0);
        int tot = 0;
        for(i = 0; i < n - 1; i++){
            if(ar[i] == 0){
                ar[i] = 1;
                tot += 1;
                for(j = i + 1; j < n; j++){
                    if(s.at(j) == s.at(i))
                        ar[j] = 1;
                }
            }
            else
                continue;
        }

        if(ar[n - 1] == 0)
            tot += 1;

        if(tot + k >= 26)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
