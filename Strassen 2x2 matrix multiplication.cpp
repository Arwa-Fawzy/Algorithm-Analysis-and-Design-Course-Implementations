#include<bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define foi(n) for (int i=0; i<n; ++i)
#define foj(y) for (int j=0; j<y; ++j)
 
void solve(){
    ll a[2][2]={{1,3}, {7,5}};
    ll b[2][2]={{6,8}, {4,2}};
    ll c[2][2], p,q,r,s,t,u,v;
    
    p=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
    q=(a[1][0]+a[1][1])*b[0][0];
    r=a[0][0]*(b[0][1]-b[1][1]);
    s=a[1][1]*(b[1][0]-b[0][0]);
    t=(a[0][0]+a[0][1])*b[1][1];
    u=(a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
    v=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
    
    c[0][0]=p+s-t+v;
    c[0][1]=r+t;
    c[1][0]=q+s;
    c[1][1]=p+r-q+u;
    
    foi(2){
        cout<<endl;
        foj(2){
            cout<<c[i][j]<<" ";
        }
    }
}
    
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    solve();
 
}