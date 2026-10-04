#include <iostream>
using namespace std;
int main(){
    //dfa state 0,1,2 
    //string input _ or letter at first and then letter or digit
    int state =0;
    string s;
    cout<<"enter the string";
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(state==0){
            
      if(isalpha(s[i])|| s[i]=='_') state=1;
               else state=2;}//invaild
     else if(state==1){
             if(isalnum(s[i])) state=1;
            else state=2;
               }
        else state=2;       
             }
             if (state == 1)
        cout << "Valid String" << endl;
    else
        cout << "Invalid String" << endl;

    return 0;
}
//test cases
//_valid
//a1valid
//1invalid
//a_invalid