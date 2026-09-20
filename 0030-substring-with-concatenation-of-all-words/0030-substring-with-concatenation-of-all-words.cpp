#include <bits/stdc++.h>

using std::vector;
using std::string;
using i64 = long long;
class Solution {
public:
    static const i64 mod = 1e9 + 7;
    static const i64 base = 13331;
    static const int N = 1e4 + 5;
    static const int M = 35;
    i64 basepow[M];
    i64 hs[N], f[N];
    void init(int n){
        basepow[0] = 1;
        for(int i = 1; i <= n; i++){
            basepow[i] = basepow[i - 1] * base % mod;
        }
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        // hash goes up-bottom
        int n = s.size();
        int m = words.size();
        int k = words[0].size();
        auto rng = [](){
            static std::mt19937 rng(clock());
            return rng() % (mod - 1) + 1;
        };
        i64 target = 0;
        init(k);
        std::unordered_map<i64, i64> mp;
        for(int i = 0; i < m; i++){
            auto& word = words[i];
            i64 h = 0;
            for(int i = 0; i < word.size(); i++){
                h = h * base % mod + word[i];
                h %= mod;
            }
            h = mp[h] ? mp[h] : mp[h] = rng();
            target += h;
        }
        s = ' ' + s;
        for(int i = 1; i <= n; i++){
            hs[i] = hs[i - 1] * base % mod + s[i];
            hs[i] %= mod;
        }
        vector<int> ans;
        f[0] = 1;
        for(int i = 1; i + k - 1 <= n; i++){
            i64 h = (hs[i + k - 1] - hs[i - 1] * basepow[k] % mod + mod) % mod;
            h = mp[h] ? mp[h] : mp[h] = rng();
            f[i + k - 1] = h;
            f[i + k - 1] += f[i - 1];
        }
        for(int i = 1; i + m * k - 1 <= n; i++){
            i64 h = f[i + m * k - 1] - f[i - 1];
            if(h == target){
                ans.emplace_back(i - 1);
            }
        }
        return ans;
    }
};