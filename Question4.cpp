#include <iostream>
using namespace std;

bool sloppyshuffles(string A, string B, int n){
    if(A==B){
        return true;
    }

    if(n%2==0){
    string A1,A2,B1,B2;
    A1=A.substr(0,n/2);
    B1=B.substr(0,n/2);
    A2=A.substr(n/2,n/2);
    B2=B.substr(n/2,n/2);
    
    if ((sloppyshuffles(A2, B2, n/2) && sloppyshuffles(A1, B1, n/2))) return true; 

    if ((sloppyshuffles(A1, B2, n/2) && sloppyshuffles(A2, B1, n/2))) return true; 

    else return false;
    }
    else return false;
}
int main() {
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        int n;
        cin>>n;
        string strA;
        string strB;
        cin>>strA;
        cin>>strB;

        if (sloppyshuffles(strA, strB, n)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}
