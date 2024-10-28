#pragma GCC optimize("O3", "unroll-loops")
#include<bits/stdc++.h>

#define optimize() ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;


struct point{
    int x;
    int y;
};
int val,n;
int sx,sy,tx,ty;
int dp[10][10000];
int dfs(int mask,int node,point cord[])
{
    if(mask==val)
    {
        // cout << mask << endl;
        return (abs(cord[node].x-tx)+abs(cord[node].y-ty));
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
            if(!(mask & (1<<i)))
            {
                mask=(mask | (1<<i));
                ans=min(ans,(abs(cord[node].x-cord[i].x)+abs(cord[node].y-cord[i].y)+dfs(mask,i,cord)));
                mask=(mask ^ (1<<i));
            }
        }
        return dp[node][mask]=ans;
    }
}
void solve()
{
    cin >> n;
    point cord[n];
    val=pow(2,n)-1;
    cin >> sx >> sy >> tx >> ty;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        cord[i].x=a;
        cord[i].y=b;
    }
    int ans=INT_MAX;
    int mask=0;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        if(!(mask & (1<<i)))
        {
            mask=(mask | (1<<i));
            ans=min(ans,abs(sx-cord[i].x)+abs(sy-cord[i].y)+dfs(mask,i,cord));
            mask=(mask ^ (1<<i));
        }
    }
    cout << ans << endl;
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
