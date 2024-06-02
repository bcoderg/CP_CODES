//question link:https://www.hackerrank.com/contests/cmrk-module2-week6-binarytrees/challenges/binary-trees-vertical-order-traversal/problem

#include <bits/stdc++.h>

using namespace std;

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int node_data) {
        data = node_data;
        left = right = NULL;
    }
};

/*
 * For your reference:
 *
 * BinaryTreeNode {
 *      data;
 *     BinaryTreeNode* left;
 *     BinaryTreeNode* right;
 * };
 *
 */
void fun(BinaryTreeNode* root , int row , int col , map < int , vector< pair<int , BinaryTreeNode*> >>&mp)
{
    mp[row].push_back({col, root});
    if (root->left != NULL)
    {
        fun(root->left, row - 1, col - 1, mp);
    }
    if (root->right != NULL)
    {
        fun(root->right, row + 1, col - 1, mp);
    }
    return;
}
vector<vector<int>> verticalTraversal(BinaryTreeNode* root) {
    //write your code here
    map < int , vector<pair<int , BinaryTreeNode*> >>mp;

    fun(root, 0, 0, mp);

    vector<vector<int>>ans;

    for (auto x : mp)
    {
        vector<int>v;
        //cout<<x.first<<" --> \n";
        int prev_col;
        vector<int>temp;
        int sz = x.second.size();
        for (int i = 0; i < sz; i++)
        {
            int cur_col = x.second[i].first;

            if (i == 0)
            {
                prev_col = x.second[i].first;
                temp.push_back(x.second[i].second->data);
            }
            else
            {
                if (cur_col == prev_col)
                {
                    temp.push_back(x.second[i].second->data);
                }
                else
                {
                    prev_col = cur_col;
                    sort(temp.begin(), temp.end());

                    for (auto d : temp)
                    {
                        //cout<<d<<" ";
                        v.push_back(d);
                    }

                    temp.clear();
                    temp.push_back(x.second[i].second->data);
                }
            }
        }
        sort(temp.begin(), temp.end());
        for (auto d : temp)
        {
            //cout<<d<<" ";
            v.push_back(d);
        }
        //cout<<"\n";
        temp.clear();

        //cout<<"next level\n";
        ans.push_back(v);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int curr = 0;
    BinaryTreeNode* root = new BinaryTreeNode(v[0]);
    deque<BinaryTreeNode*> dq;
    dq.push_back(root);
    while (!dq.empty()) {
        BinaryTreeNode* fr = dq.front();
        dq.pop_front();
        if (curr + 1 < n) {
            curr++;
            BinaryTreeNode* ln = new BinaryTreeNode(v[curr]);
            fr->left = ln;
            dq.push_back(fr->left);
        }
        if (curr + 1 < n) {
            curr++;
            BinaryTreeNode* rn = new BinaryTreeNode(v[curr]);
            fr->right = rn;
            dq.push_back(fr->right);
        }
    }

    vector<vector<int>> ans = verticalTraversal(root);
    cout << "[";
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < (int)ans[i].size(); j++) {
            cout << ans[i][j];
            if (j != (int)ans[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i != (int)ans.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";
    return 0;
}
