Given below are the raw materials quantities and their respective selling price(if sold as raw).

D --> No of CPUs
E --> No of memory chips
F --> No of boards
d --> Selling price of CPU
e --> Selling price of Memory chips

We are given N Computer configurations like below : 
Di, Ei, Fi, SPi, which are the CPU, Chips, Boards and one unit selling price for ith computer respectively.
Our task is to maximize the final cost.
Constraints:
1. Can use at Max 3 different Configurations
2. We can use 1 configuration multiple times
3. Remaining Inventories can be sold on its selling price

Input:
T --> Number of test cases.
D E F d e --> Inventories
N --> Total Configuration Count
Di Ei Fi SPi
...
Dn En Fn SPn

1<=T<=10
1<= D, E, F <= 100
1<= d, e <=100000
1<=N<=8





#include<bits/stdc++.h>
using namespace std;


int dp[9][4][101][101][101];
int see(vector<vector<int>> &v,int i,int cnt,int D,int E,int F,int d,int e)
{
    if(i>=v.size() || cnt==3 || D<=0 || E<=0 || F<=0)
    {
        return (D * d + E * e);
    }
    else if(dp[i][cnt][D][E][F]!=-1)
    {
        return dp[i][cnt][D][E][F];
    }
    else
    {
        int ans=see(v,i+1,cnt,D,E,F,d,e);
        for(int k=0;k<100;k++)
        {
            if((k*v[i][0])<=D && (k*v[i][1])<=E && (k*v[i][2])<=F)
            {
                int value = k * v[i][3] + see(v,i+1,cnt+1, D - (k*v[i][0]) ,  E- (k*v[i][1]), F - (k*v[i][2]), d , e); 
                ans=max(ans,value);
            }
            else
            {
                break;
            }
            
        }
        return dp[i][cnt][D][E][F]=ans;
    }
}
void solve()
{
    int D,E,F,d,e;
    cin >> D >> E >> F >> d >> e;
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int> (4));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin >> v[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << see(v,0,0,D,E,F,d,e) << endl;
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
