#include <iostream>
using namespace std;

int main(){
    int start=1,end=5;
    for(int row=start;row<=end;row++){
        for(int col=start;col<=end-row;col++){
            cout<<"  ";
        }
        for(int col=start;col<=row;col++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
