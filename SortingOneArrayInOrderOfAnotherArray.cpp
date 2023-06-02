/* 
Problem link: https://codeforces.com/contest/1833/problem/B
*/

/* Tutorial:
1833B - Restore the Weather
Let's solve the problem using a greedy algorithm.

Based on the array 𝑎
, form an array of pairs {temperature, day number} and sort it in ascending order of temperature. Also sort the array 𝑏
 in ascending order. Now, the values 𝑎[𝑖].𝑓𝑖𝑟𝑠𝑡
 and 𝑏[𝑖]
 are the predicted and real temperature on day 𝑎[𝑖].𝑠𝑒𝑐𝑜𝑛𝑑
.

Indeed, consider the minimum temperatures 𝑏[1]
 and 𝑎[1].𝑓𝑖𝑟𝑠𝑡
. The difference between them is 𝑡=|𝑏[1]−𝑎[1].𝑓𝑖𝑟𝑠𝑡|
. If we consider the value |𝑏[𝑖]−𝑎[1].𝑓𝑖𝑟𝑠𝑡|
 or |𝑏[1]−𝑎[𝑖].𝑓𝑖𝑟𝑠𝑡|
 at 𝑖>1
, there will be at least 𝑡
 since 𝑎[1]≤𝑎[𝑖]
 and 𝑏[1]≤𝑏[𝑖]
.

Since it is guaranteed that it is possible to rearrange the elements in the array 𝑏
, and the elements 𝑏[1]
 and 𝑎[1].𝑓𝑖𝑟𝑠𝑡
 have the smallest difference, it is definitely not greater than 𝑘
. 
*/

// solution:
#include<bits/stdc++.h>
using namespace std;
void  solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>>a(n);
    vector<int>b(n), ans(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    for(auto &i : b) cin >> i;
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        ans[a[i].second] = b[i];
    }
    for(auto &i : ans) cout << i << ' ';
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}
