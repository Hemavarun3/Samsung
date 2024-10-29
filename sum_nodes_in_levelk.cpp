#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int v[10]={0},i=1;
int conve(string &s)
{
    int ind=0,sum=0;
    for(int j=s.length()-1;j>=0;j--)
    {
        sum+=(pow(10,ind)*(s[j]-48));
        ind++;
    }
    return sum;
}
int main() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int level=-1;
    for(int i=0;i<(int)s.length();i++)
    {
        if(s[i]=='(')
        {
            level++;
        }
        else if(s[i]==')')
        {
            level--;
        }
        else
        {
            string g="";
            while(i<(int)s.length() && s[i]!='(' && s[i]!=')')
            {
                g+=s[i];
                i++;
            }
            i--;
            v[level]+=conve(g);
        }
    }
    cout << v[k] << endl;
    return 0;
}
