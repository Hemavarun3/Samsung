#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v={{-1,0},{1,0},{0,-1},{0,1}};
int bfs(vector<vector<int>> &mat,int start_x,int start_y)
{
    int n=mat.size(),m=mat[0].size();
    vector<vector<int>> visi(n,vector<int> (m,0));
    queue<pair<int,int>> qe;
    qe.push({start_x,start_y});
    visi[start_x][start_y]=1;
    int level=0;
    while(!qe.empty())
    {
        int size=qe.size();
        while(size--)
        {
            auto [p,q]=qe.front();
            qe.pop();
            for(auto it:v)
            {
                int i=p+it.first;
                int j=q+it.second;
                if(i<n && i>=0 && j<m && j>=0 && !visi[i][j] && mat[i][j])
                {
                    visi[i][j]=1;
                    qe.push({i,j});
                }
            }
        }
        level++;
    }
    return level;
}
void solve()
{
    int m,n;
    cin >> m >> n;
    vector<vector<int>> mat(n,vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mat[i][j];
        }
    }
    int start_x,start_y;
    cin >> start_x >> start_y;
    cout << bfs(mat,start_y-1,start_x-1) << endl;
}
int32_t main()
{
    int d=1;
    cin >> d;
    while(d--)
    {
        solve();
    }
    return 0;
}
