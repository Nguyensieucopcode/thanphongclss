#include<bits/stdc++.h>

using namespace std;

#define int long long

bool ss(string s1, string s2)
{
    return s1.size()>s2.size() || (s1.size()==s2.size() && s1>s2);
}

string  plusi(string s1, string s2)
{
    if (ss(s1,s2)) swap(s1,s2);
    int d=s2.size()-s1.size();
    for (int i=1 ;i<=d; i++) s1='0'+s1;
    string tmp="";
    int du=0;
    for(int i=s2.size()-1; i>=0; i--)
    {
        int x=s1[i]-'0'+du,y=s2[i]-'0',t=x+y;
        if (t>9)
        {
            t-=10; du=1;
        }
        else du=0;
        tmp=char(t+'0')+tmp;
    }
    if (du) tmp='1'+tmp;
    return tmp;
}

string minor(string s1,string s2)
{
    int kt=1;
    if (ss(s1,s2)) swap(s1,s2),kt=0;
    int d=s2.size()-s1.size();
    for (int i=1; i<=d; i++) s1='0'+s1;
    string tmp="";
    int du=0;
    for (int i=s2.size()-1; i>=0; i--)
    {
        int x=s2[i]-'0',y=s1[i]-'0'+du;
        if (x<y)
        {
            du=1; x+=10;
        }
        else du=0;
        int t=x-y;
        tmp=char(t+'0')+tmp;
    }
    while (!tmp.empty() && tmp[0]=='0') tmp.erase(0,1);
    if (tmp.empty()) return "0";
    if (kt) tmp='-'+tmp;
    return tmp;
}

string chuyen(int t)
{
    string tmp="";
    while (t!=0)
    {
        tmp = char(t%10+'0') + tmp; t/=10;
    }
    return tmp;
}

string times(string s1, string s2)
{
    string tmp="";
    string k="";
    for (int i=s1.size()-1; i>=0; i--)
    {
        int t=s1[i]-'0'; string rs=""; int du=0;
        for (int j=s2.size()-1; j>=0; j--)
        {
            int t1=t*(s2[j]-'0')+du;
            rs=char(t1%10+'0')+rs; du=t1/10;
        }
        if (du>0) rs=char(du%10+'0')+rs;
        rs=rs+k;
        tmp=plusi(tmp,rs);
        k+='0';
    }
    return tmp;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    #define task "main"
    if (fopen(task".inp","r"))
    {
        (void)!freopen(task".inp","r",stdin);
        (void)!freopen(task".out","w+",stdout);
    }
    string s1,s2;
    cin>>s1>>s2;
    cout<<plusi(s1,s2)<<"\n";
    cout<<minor(s1,s2)<<"\n";
    cout<<times(s1,s2)<<"\n";
}
