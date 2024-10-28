#pragma GCC optimize("O3", "unroll-loops")
#include<bits/stdc++.h>

#define optimize() ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

int dp[200][200][200];
int dfs(int sx,int sy,int tx,int ty,int mask,int n,int warm[][5])
{
    if(dp[sx][sy][mask]!=-1)
    {
        // // cout << "Hello" << endl;
        // cout << sx << " " << sy << " " << dp[sx][sy][mask] << endl;
        return dp[sx][sy][mask];
    }
    int curr_dist=abs(tx-sx)+abs(ty-sy);
    for(int i=0;i<n;i++)
    {
        if(!(mask & (1<< i)))
        {
            mask =(mask | (1<<i));
            curr_dist=min(curr_dist,abs(warm[i][0]-sx)+abs(warm[i][1]-sy)+warm[i][4]+dfs(warm[i][2],warm[i][3],tx,ty,mask,n,warm));
            curr_dist=min(curr_dist,abs(warm[i][2]-sx)+abs(warm[i][3]-sy)+warm[i][4]+dfs(warm[i][0],warm[i][1],tx,ty,mask,n,warm));
            mask =(mask ^ (1<<i));
        }
    }
    return dp[sx][sy][mask]=curr_dist;
}
void solve()
{
    int n;
    cin >> n;
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    int warm[n][5];
    for(int i=0;i<n;i++)
    {
        cin >> warm[i][0] >> warm[i][1] >> warm[i][2] >> warm[i][3] >> warm[i][4];
    }
    memset(dp,-1,sizeof(dp));
    cout << dfs(sx,sy,tx,ty,0,n,warm) << endl;
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
