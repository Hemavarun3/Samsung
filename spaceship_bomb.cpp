#include<bits/stdc++.h>
using namespace std;



int mat[10][5];
vector<pair<int,int>> v={{-1,0},{-1,-1},{-1,1}};
int dp[20][5][2][11];
int see(int i,int j,int flag,int limit)
{
    
    if(i<0 || j<0 || j>4)
    {
        return 0;
    }
    else if(dp[i][j][flag][limit]!=-1)
    {
        return dp[i][j][flag][limit];
    }
    else
    {
        
        int ans=0;
        for(auto it:v)
        {
            if(mat[i][j]<=1)
            {
                ans=max(ans,mat[i][j]+see(i+it.first,j+it.second,flag,limit));
            }
            else
            {
                if(flag)
                {
                    if(i>=limit)
                    {
                        ans=max(ans,see(i+it.first,j+it.second,flag,limit));
                    }
                }
                else
                {
                    ans=max(ans,see(i+it.first,j+it.second,1,i-4));
                }
            }
        }
        return dp[i][j][flag][limit]=ans;
    }
}
void solve(int l)
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin >> mat[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << "#" << l << " " << max({see(n-1,2,0,0),see(n-1,1,0,0),see(n-1,3,0,0)}) << endl;
}
int main()
{
    int t,l=1;
    cin >> t;
    while(l<=t)
    {
        solve(l);
        l++;
    }
}
