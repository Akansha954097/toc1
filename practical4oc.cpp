#include <iostream>
using namespace std;

string input;
int pos=0;

void q0();
void qA();
void qB();
void qReject();

void q0(){
    if(pos<input.size()){
        char c=input[pos++];
        if(c=='a') qA();
        else qReject();
    } else qReject();
}

void qA(){
    if(pos<input.size()){
        char c=input[pos++];
        if(c=='a') qA();
        else qB();
    } else cout<<"Rejected\n";
}

void qB(){
    if(pos<input.size()){
        char c=input[pos++];
        if(c=='a') qA();
        else qB();
    } else cout<<"Accepted\n";
}

void qReject(){
    cout<<"Rejected\n";
}

int main(){
    cin>>input;
    q0();
    return 0;
}