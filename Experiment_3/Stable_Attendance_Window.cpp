#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    int count = 0;
    int len=0;
    for(int i = 0; i < n; i++) {
        char ch;
        cin>>ch;
        if(ch=='P')
            count+=1;
        else
            count-=1;
        if(count==0) {
            len=i+1;
        }
        if(mp.find(count)!=mp.end()){
            len=max(len,i-mp[count]);
        }else{
            mp[count]=i;
        }
    }
    cout<<len;
    return 0;
}