#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int mat[15][15],n,m,ans=0;
void see(int k)
{
    if(k==0)
    {
        int curr_ans=0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<m;j++)
            {
                count+=mat[i][j];
            }
            curr_ans+=(count==m);
        }
        ans=max(ans,curr_ans);
        return;
    }
    vector<int> pre(n);
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            pre[i]=mat[i][j];
            mat[i][j]=1-mat[i][j];
        }
        see(k-1);
        for(int i=0;i<n;i++)
        {
            mat[i][j]=pre[i];
        }
    }
}
int main() 
{   
    int k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mat[i][j];
        }
    }
    see(k);
    cout << ans << endl;
    return 0;
}




#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() 
{   
    int mat[15][15],n,m,k,ans=0;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            int curr_count=0;
            for(int k=0;k<m;k++)
            {
                if(mat[i][k]==mat[j][k])
                {
                    curr_count++;
                }
            }
            count+=(curr_count==m);
        }
        int zero=0;
        for(int j=0;j<m;j++)
        {
            zero+=(1-mat[i][j]);
        }
        if(zero<=k)
        {
            if(zero==k)
            {
                ans=max(ans,count);
            }
            else
            {
                zero=k-zero;
                if(!zero%2)
                {
                    ans=max(ans,count);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}


