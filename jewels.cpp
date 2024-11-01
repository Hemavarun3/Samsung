#include<bits/stdc++.h>
using namespace std;



int n,m,final_c=0;
vector<vector<int>> final_grid;
vector<pair<int,int>> v={{-1,0},{1,0},{0,1},{0,-1}};
void dfs(vector<vector<int>> &adj,vector<vector<int>> &visi,int jewels,int i,int j)
{
    int curr=adj[i][j];
    adj[i][j]=3;
    if((i==(n-1)) && (j==(m-1)))
    {
        if(jewels>final_c)
        {
            final_grid=adj;
            final_c=jewels;
        }
        return;
    }
    visi[i][j]=1;
    adj[i][j]=curr;
    
    if(adj[i][j]==2)
    {
        jewels++;
    }
    if(!(i==(n-1) && j==(m-1)))
    {
        adj[i][j]=3;
    }
    for(auto it:v)
    {
        int x=i+it.first;
        int y=j+it.second;
        if(x<n && x>=0 && y<m && y>=0 && !visi[x][y] && adj[x][y]!=1)
        {
            dfs(adj,visi,jewels,x,y);
        }
    }
    adj[i][j]=curr;
    visi[i][j]=0;
}
void solve()
{
    
    cin >> n;
    m=n;
    vector<vector<int>> adj(n,vector<int> (m)),visi(n,vector<int> (m,0));
    final_c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> adj[i][j];
        }
    }
    dfs(adj,visi,0,0,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << final_grid[i][j] << " ";
        }
        cout << "\n";
    }
    cout << final_c << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
