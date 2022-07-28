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
        cout << a[i] << " ";
    }
    cout << endl;
}
void printYN(int ans) {
    if (ans) cout << "Yes"  << endl;
    else cout <<  "No" << endl;
}




void test_case() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    sort(s.begin(), s.end());
    int same = 1;
    for (int i = 0; i < k; ++i) {
        if (s[i] != s[0]) same = 0;
    }
    if (!same) {
        cout << s[k - 1] << endl;
    }
    else {
        for (int i = k; i < n; ++i) {
            if (s[i] != s[k]) same = 0;
        }
        string ans;
        ans += s[0];
        if (!same) {

            for (int j = k; j < n; ++j) {
                ans += s[j];
            }
        }
        else {
            for (int j = k; j < n; j += k) {
                ans += s[j];
            }
        }
        cout << ans << endl;
    }
}

bool comp(pair<int, int> a, pair<int, int> b){
    if (a.first != b.first) return a.first < b.first;
    else return a.second >= b.second;
}
class DSU {
    int* parent;
    int* rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }
    // union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph {
    vector<vector<int> > edgelist;
    int V;

public:
    Graph(int V) { this->V = V; }

    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({ w, x, y });
    }

    int kruskals_mst()
    {
        // 1. Sort all edges
        sort(edgelist.begin(), edgelist.end());

        // Initialize the DSU
        DSU s(V);
        int ans = 0;
        for (auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};
signed main()
{

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> v(n), e(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i] >> e[i];
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        Graph g(v[i]);
        for (int j = 0; j < e[i]; ++j) {
            int a, b, l; cin >> a >> b >> l;
            a--; b--;
            g.addEdge(a, b, l);
        }
        ans.push_back({g.kruskals_mst(), i + 1});
    }
    sort(ans.rbegin(), ans.rend());
    cout << ans[k -1 ].second << " " << ans[k - 1].first << endl;
}






