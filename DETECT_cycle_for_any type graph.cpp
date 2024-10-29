#include<bits/stdc++.h>
using namespace std;



int visit[12]={false},pathVisit[12]={-1},adj[12][12]={0},ans=INT_MAX;
vector<int> ans_vec;
map<vector<int>,int> mp;
void dfs(int node,int n,int parent)
{
    visit[node]=1;
    pathVisit[node]=parent;
    for(int i=1;i<=n;i++)
    {
        if(adj[node][i])
        {
            if(!visit[i])
            {
                dfs(i,n,node);
            }
            else if(pathVisit[i]!=-1)
            {
                int sum=0;
                vector<int> curr;
                curr.push_back(i);
                sum+=i;
                int c_node=node;
                while(c_node!=i)
                {
                    curr.push_back(c_node);
                    sum+=c_node;
                    c_node=pathVisit[c_node];
                }
                reverse(curr.begin(),curr.end());
                sort(curr.begin(),curr.end());
                if(curr.size()>2)
                {
                   mp[(curr)]++;
                }
                if(ans>sum)
                {
                    ans_vec=curr;
                    ans=sum;
                }
            }
        }
    }
    pathVisit[node]=-1;
    visit[node]=0;
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x][y]=1;
    }
    int visit[n]={false};
    for(int i=1;i<=n;i++)
    {
        if(!visit[i])
        {
            dfs(i,n,0);
        }
    }
    // sort(ans_vec.begin(),ans_vec.end());
    // for(int i=0;i<(int)(ans_vec.size());i++)
    // {
    //     cout << ans_vec[i] << " ";
    // }
    for(auto it:mp)
    {
        for(int i=0;i<(it.first).size();i++)
        {
            cout << (it.first)[i] << " ";
        }
        cout << "\n";
    }
}
