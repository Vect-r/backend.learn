#include <iostream>
using namespace std;

int main(){
    int start=5,end=1;
    for(int row=start;row>=end;row--){
        for(int col=end;col<=start-row;col++){
            cout<<"  ";
        }
        for(int col=end;col<=row;col++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
