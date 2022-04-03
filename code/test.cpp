#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        sort(buildings.begin(), buildings.end(), [](vector<int> build1, vector<int> build2){
         return(build1.front() <= build2.front());
    });
        return buildings;
    }
};

int minCheckDuration(vector<int>& goods) {
        // write code here
        int len = goods.size();
        if(len == 0){
            return 0;
        }
        else if(len == 1){
            return goods[0];
        }
        vector<int> dp(len, 0);
        dp[0] = goods[0];
        dp[1] = min(goods[0], goods[1]);
        for(int i = 2; i < len; ++i){
            dp[i] = goods[i] + min(dp[i - 2], dp[i - 1]);
            // cout << i << ":" << dp[i] << endl;
        }
        return min(dp[len - 1], dp[len - 2]);
    }

int main(){
    vector<int> goods;
    goods = {2,100,2,3,3,90,3,2,80,2};
    int ans = minCheckDuration(goods);
    cout << ans <<endl;
}