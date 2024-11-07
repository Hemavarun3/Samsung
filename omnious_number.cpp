#include<bits/stdc++.h>
using namespace std;




int dp[1000][1000][2][2];
int v[10],k;
int see(int *a,int i,string &s,int count,int tight,bool zero)
{
    if(i==s.length())
    {
        return count>=k ? 0 : 1;
    }
    else if(dp[i][count][tight][zero]!=-1)
    {
        return dp[i][count][tight][zero];
    }
    else
    {
        int limit=9;
        if(tight==1)
        {
            limit=s[i]-48;
        }
        int ans=0;
        for(int j=0;j<=limit;j++)
        {
            if(j==0)
            {
                if(zero)
                {
                    ans+=see(a,i+1,s,count,0,zero);
                }
                else
                {
                    ans+=see(a,i+1,s,count+v[j],0,zero);
                }
            }
            else if(j==limit)
            {
                ans+=see(a,i+1,s,count+v[j],tight,0);
            }
            else
            {
                ans+=see(a,i+1,s,count+v[j],0,0);
            }
        }
        return dp[i][count][tight][zero]=ans;
    }
}
void solve()
{
    int l,r;
    cin >> l >> r >> k;
    int n;
    cin >> n;
    int *a=new int[n];
    for(int i=0;i<10;i++)
    {
        v[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        v[x]=1;
    }
    string s_r=to_string(r);
    string s_l=to_string(l-1);
    memset(dp,-1,sizeof(dp));
    int ans_r=see(a,0,s_r,0,1,1);
    // cout << ans_r << endl;
    memset(dp,-1,sizeof(dp));
    int ans_l=see(a,0,s_l,0,1,1);
    cout << ans_r-ans_l << endl;
    
    
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
