#include<bits/stdc++.h>
using namespace std;



vector<pair<int,int>> v={{-1,0},{0,1},{0,-1},{1,0}};
void bfs(vector<vector<int>> &grid,int x,int y,vector<vector<int>> &final_grid)
{
    int n=final_grid.size();
    vector<vector<int>> visi(n,vector<int> (n,0)),curr(n,vector<int> (n,INT_MAX));
    queue<pair<int,int>> qe;
    qe.push({x-1,y-1});
    visi[x-1][y-1]=1;
    int level=0;
    while(!qe.empty())
    {
        int size=qe.size();
        while(size--)
        {
            auto [p,q]=qe.front();
            qe.pop();
            curr[p][q]=level;
            for(auto it:v)
            {
                int i=p+it.first;
                int j=q+it.second;
                if(i<n && i>=0 && j<n && j>=0 && !visi[i][j] && grid[i][j])
                {
                    visi[i][j]=1;
                    qe.push({i,j});
                }
            }
        }
        level++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            final_grid[i][j]=max(final_grid[i][j],curr[i][j]);
        }
    }
    return;
}
void see()
{
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> v_e;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        v_e.push_back({x,y});
    }
    vector<vector<int>> grid(n,vector<int> (n)),final_grid(n,vector<int> (n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
        bfs(grid,v_e[i].first,v_e[i].second,final_grid);
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j])
            {
                ans=min(ans,final_grid[i][j]);
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        see();
    }
}
