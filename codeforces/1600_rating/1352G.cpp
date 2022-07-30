//
// Created by Vineet Widhani on 30/07/22.
//
//
// Created by Vineet Widhani on 30/07/22.
//
//
// Created by Vineet Widhani on 29/07/22.
//
//
// Created by Vineet Widhani on 28/07/22.
//
#include <iostream>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <climits>
#include <cstring>
#include <math.h>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <sstream>


using namespace std;
#define endl "\n"
#define int long long


#define mod1 1000000007
#define mod2 998244353
//#define INF 100000000007


//
int add(int a, int b) {
    return (a + b + mod1) % mod1;
}

int mul(int x, int y) {
    return (1LL * x * y) % mod1;
}

int gcd(int a, int b){
    if(b == 0)return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

bool compare(pair<int,int> a, pair<int, int> b){
    return a.second< b.second;
}

//#define mx_val 1e9 + 5
//const int mx = 1e5 + 5;

void printvect(vector<int> &a) {
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] + 1 << " ";
    }
    cout << endl;
}

void readvect(vector<int> &a, int n) {
    for (int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }
}
void printYN(int ans) {
    if (ans) cout << "Ayush"  << endl;
    else cout <<  "Ashish" << endl;
}


bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}


int is_valid(vector<int> &a, int n) {
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1])return 0;
    }
    return 1;
}


void test_case() {
    int n; cin >> n;
    if (n == 2 || n == 3) {
        cout << "-1" << endl;
        return;
    }
    vector<int> ans(n);
    int cur = (n % 2 ? 1 : 2);
    int i = 0;
    while (cur <= n) {
        ans[i] = cur; i++; cur += 2;
    }
    cur -= 3;
    while (cur > 0) {
        ans[i] = cur; i++; cur -= 2;
    }
    int ind = (n % 2 ? n/2 + 1 : n/2);
    swap(ans[ind], ans[ind + 1]);
    for (int j = 0; j < n; ++j) {
        cout << ans[j]<< " ";
    }
    cout << endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
//        cout << "Case #" << i << ": ";
        test_case();
    }
    return 0;
}






