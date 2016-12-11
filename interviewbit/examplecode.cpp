#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    map<int,int> count;
    while(cin>>x){
        count[x]++;
        if(count[x] > 18){
            cout<<x<<" "<<count[x]<<"\n";
        }
    }
}