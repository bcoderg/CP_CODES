#include <bits/stdc++.h>
using namespace std;

class Sudoku_Check
{
public:
    bool check(vector<vector<char>> &v , char num ,int r ,int c)
    {
        for(int i=0;i<9;i++)
        {
            if(v[i][c]==num)return false;
            
            if(v[r][i]==num)return false;
            
            if(v[3*(r/3) + i/3][3*(c/3) + c%3]==num)return false;
        }
        return true;
    }
    bool valid(vector<vector<char>> &a)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(a[i][j]!='.')
                {
                    char num=a[i][j];
                    
                    a[i][j]='.';
                    
                    bool f=check(a,num,i,j);
                    
                    if(!f)return false;
                    
                    a[i][j]=num;
                }
            }
        }
        return true;
    }
    
    bool validSudoku(vector<vector<char>> &a)
    {
        // complete the function
        
        return valid(a);
    }
};