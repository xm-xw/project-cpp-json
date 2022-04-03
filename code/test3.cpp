#include <bits/stdc++.h>
using namespace std;

vector<int> Solve(vector<vector<int>> &x){
    int len = x.size();

    //放入一个哈希中
    unordered_map<int, int> umap;
    for(int i = 0; i < len; ++i){
        umap[x[i][0]] = x[i][1];
    }

    // 找出在头部的数
    int head;
    vector<int> all;
    for(int i = 0; i < len; ++i){
        all.push_back(x[i][1]);
    }
    for(int i = 0; i < len; ++i){
        int t = x[i][0];
        bool tag = true;
        for(int j = 0; j < len; ++j){
            if(t == all[j]){
                tag = false;
            }
        }
        if(tag == true){
            head = x[i][0];
            break;
        }
    }

    //
    vector<int> ans;
    ans.push_back(head);
    ans.push_back(umap[head]);
    while(umap.find(ans.back()) != umap.end()){
        ans.push_back(umap[ans.back()]);
    }
    return ans;
}

int main(){
    vector<vector<int>> x = {{1,2},{2,6},{9,5},{6,9}};
    vector<int> res = Solve(x);
    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << endl;
    }
    return 0;
}