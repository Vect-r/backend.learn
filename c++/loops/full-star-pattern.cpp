#include <iostream>
using namespace std;

int main(){
    int start=1,end=10;
    for(int row=start;row<=end;row++){
        for(int col=start;col<=end-row;col++){
            cout<<"  ";
        }
        for(int col=start;col<=row;col++){
            cout<<"* ";
        }
        for(int col=start;col<=row-1;col++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int row=end-1;row>=start;row--){
        for(int col=start;col<=end-row;col++){
            cout<<"  ";
        }
        for(int col=start;col<=row;col++){
            cout<<"* ";
        }
        for(int col=start;col<=row-1;col++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
