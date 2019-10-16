#include <iostream>

using namespace std;

int main(){
    int N,tab;
    cin>>N>>tab;
    int i=N;
    while(i--){
        int M;
        cin>>M;
        tab-=M;
        if(tab<0){
            cout<<N-i-1<<endl;
            return 0;
        }
    }
    cout<<N<<endl;
    return 0;
}
