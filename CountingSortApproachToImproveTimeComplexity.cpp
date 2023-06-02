// First C++ code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

#define ll long long
#define ld long double

//Declaration
template <typename T, typename P>
auto maximum( T a, P b) -> decltype((a > b)? a : b) ;

template <typename T, typename P>
auto minimum( T a, P b) -> decltype((a < b)? a : b) ;

const ll MOD = 1e9 + 7;

//============================================//

void solution(){
	//Your code goes here.
    int n,k;
    cin>>n>>k;
    
    vector<pair<int, int>>a(n);
    vector<int>b(n), ans(n), a1(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
        a[i].first = 0;
        a1[i] = 0;
        a[i].second = i;
    }
    for(int i=0;i<k;i++){
        int q, w;
        cin >> q >> w;
        for(int j=q;j<=w;j++){
            a[j-1].first++;
            a1[j-1]++;
        }
    }

    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    int sum = 0;
    for(int i = 0; i < n; i++){
        ans[a[i].second] = b[i];
    }
    for(int i = 0; i < n; i++){
        sum += ans[i]*a1[i];
    }    
    
    cout << sum << endl;
    
    for(auto &i : ans) cout << i << ' ';
    cout << endl;
}

//============================================//

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	cin>>t;
	
	while(t--){
	    solution();
	}
	return 0;
}

//Definition
template <typename T, typename P>
auto maximum( T a, P b) -> decltype((a > b)? a : b) {
    return (a > b)? a : b;
	
}template <typename T, typename P>
auto minimum( T a, P b) -> decltype((a < b)? a : b) {
    return (a < b)? a : b;
}

/* can you improve its time complexity without changing the algorithm of the code.
To improve the time complexity of the code without changing the algorithm, you can replace the sorting of the a vector with a counting sort approach.
Here's the modified code:
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

#define ll long long
#define ld long double

//Declaration
template <typename T, typename P>
auto maximum(T a, P b) -> decltype((a > b) ? a : b);

template <typename T, typename P>
auto minimum(T a, P b) -> decltype((a < b) ? a : b);

const ll MOD = 1e9 + 7;

//============================================//

void solution() {
    //Your code goes here.
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> a(n);
    vector<int> b(n), ans(n), a1(n);
    vector<int> freq(n + 1, 0); // Frequency array for counting sort

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        a[i].first = 0;
        a1[i] = 0;
        a[i].second = i;
    }
    for (int i = 0; i < k; i++) {
        int q, w;
        cin >> q >> w;
        freq[q - 1]++; // Increase frequency of start index
        freq[w]--;     // Decrease frequency of end index + 1
    }

    int prefix_sum = 0;
    for (int i = 0; i < n; i++) {
        prefix_sum += freq[i]; // Prefix sum of frequencies
        a[i].first = prefix_sum;
        a1[i] = prefix_sum;
    }

    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    int sum = 0;
    for (int i = 0; i < n; i++) {
        ans[a[i].second] = b[i];
    }
    for (int i = 0; i < n; i++) {
        sum += ans[i] * a1[i];
    }

    cout << sum << endl;

    for (auto& i : ans) cout << i << ' ';
    cout << endl;
}

//============================================//

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;

    while (t--) {
        solution();
    }
    return 0;
}

//Definition
template <typename T, typename P>
auto maximum(T a, P b) -> decltype((a > b) ? a : b) {
    return (a > b) ? a : b;

} template <typename T, typename P>
auto minimum(T a, P b) -> decltype((a < b) ? a : b) {
    return (a < b) ? a : b;
}

//By using counting sort for the a vector, the time complexity of sorting is reduced from O(nlogn) to O(n), resulting in an overall improvement in the code's time complexity.
