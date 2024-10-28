#pragma GCC optimize("O3", "unroll-loops")
#include<bits/stdc++.h>

#define optimize() ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;


int val,n;
int dp[10][10000];
int dist[100][100]; 
int dfs(int node,int mask)
{
    if(mask==val)
    {
        return dist[node][0]!=INT_MAX ? dist[node][0] : INT_MAX;
    }
    else if(dp[node][mask]!=-1)
    {
        return dp[node][mask];
    }
    else
    {
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(!(mask & (1<<i)) && dist[node][i]!=INT_MAX)
            {
                mask=(mask | (1<<i));
                int curr=dfs(i,mask);
                if(curr!=INT_MAX)
                {
                    ans=min(ans,dist[node][i]+curr);
                }
                
                mask=(mask ^ (1<<i));
            }
        }
        return dp[node][mask]=ans;
    }
}
void solve()
{
    cin >> n;
    val=pow(2,n)-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> dist[i][j];
            if(dist[i][j]==0)
            {
                dist[i][j]=INT_MAX;
            }
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << dfs(0,1) << endl;
}
int32_t main()
{
    optimize();
    int d=1;
    cin >> d;
    while(d--)
    {
        solve();
    }
    return 0;
}
