
#include<iostream>
using namespace std;

std::string HC = "_";
char VC = '|';
int z = 6;
int a = 2;

void FH(){
    string s = " ";
    int i = a*z;
    while(i--){
        s = s+HC;
    }
    s=s+" ";
    cout<<s<<endl;

}

void V12( int l, int m, int r){

    int i = z;
    int j;
    while(i--){
        j = a*z;
        if(l)cout<<VC;
        if(l==0)cout<<" ";

        if(i==0 && m){
            while(j--)cout<<HC;
        }
        else if(r){
            while(j--)cout<<" ";
        }
        if(r)cout<<VC;
        cout<<endl;
    }
}
void zero(){
    FH();
    V12(1,0,1);
    V12(1,1,1);
}
void one(){
    V12(1,0,0);
    V12(1,0,0);

}

void two(){
    FH();
    V12(0,1,1);
    V12(1,1,0);

}

void three(){
    FH();
    V12(0,1,1);
    V12(0,1,1);
}

void four(){
    V12(1,1,0);
    V12(0,0,1);
}

void five(){
    FH();
    V12(1,1,0);
    V12(0,1,1);

}
void six(){
    FH();
    V12(1,1,0);
    V12(1,1,1);
}
void seven(){
    FH();
    V12(0,0,1);
    V12(0,0,1);
}
void eight(){
    FH();
    V12(1,1,1);
    V12(1,1,1);
}
void nine(){
    FH();
    V12(1,1,1);
    V12(0,0,1);
}

int main(){
    zero();
    one();
    two();
    three();
    four();
    five();
    six();
    seven();
    eight();
    nine();
    



}