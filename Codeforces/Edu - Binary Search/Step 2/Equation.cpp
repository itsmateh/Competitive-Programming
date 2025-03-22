#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define raya cerr << "=================" << endl;
#define forn(i,n) for(int i=0;i<int(n);i++)
#define pb push_back
#define endl "\n";

double c;
bool cumple(double x){
    return (pow(x,2) + sqrt(x) - c) < 1e-6;
}


int main(){
    FIN

    cin>>c;
    double l = 0;
    double r = 2*1e10;
    double ans = 0;
    for(int i=0; i<100; i++){
        double m = l+(r-l)/2;
        if(cumple(m)){l = m;}
        else {r = m;}
    }
    cout<<setprecision(20)<<r<<endl;
    return 0;
}