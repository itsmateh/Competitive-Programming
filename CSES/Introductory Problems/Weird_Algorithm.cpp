#include <iostream>
using namespace std;
 
#define ll long long
 
int main(){
    ll x; 
    cin>>x; 
    cout<<x<<" ";
 
    while(x>1){
        if(x%2 == 0)
            x = x/2;
        else
            x = (x*3)+1; 
        cout<<x<<" ";
    }
}