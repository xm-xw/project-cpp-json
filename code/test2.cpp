#include<bits/stdc++.h>
using namespace std;

typedef struct Tree{
    int val;
    tree *left;
    tree *right;
}tree;

int main(){
    vector<vector<int>> sum(3, vector<int> (2));

    return 0;
}



vector<int> max_sum_tree(tree *head){
    if(!head){
        return vector<int> {0, 0};
    }
    if(!head->left && !head->right){
        vector<int> res = {head->val, 0};
        return res;
    }
    vector<int> l = max_sum_tree(head->left);
    vector<int> r = max_sum_tree(head->right);
    vector<int> res(2);
    res[0] = head->val + l[1] + r[1];
    res[1] = max(l[0], l[1]) + max(r[0], r[1]);
    return res;

}