#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    SetConsoleCP(1251);SetConsoleOutputCP(1251);

    const short R=32,C=32;
    char table[R][C]={};

    string str; getline(cin,str);
    for(short i=4; i<str.length();){
        if(str[i]==' '){
            str.erase(i,1);
            i+=4;
        }
    }

    short cnt=0,i=0,j=0,len=str.length();
    while(cnt++<=len){
        if(i==0){
            if(cnt==1) table[i][j++]='1';
            else{--cnt; ++j;}
            if(++cnt<=len) table[i][j]='1';
        }
        while(j>0 && ++cnt<=len) table[++i][--j]='1';
        if(j==0 && ++cnt<=len) table[++i][j]='1';
        while(i!=0 && ++cnt<=len)  table[--i][++j]='1';
    }
    cnt=0;
    while(cnt<=len){
        for(short it=0; cnt<=len; ++it){
            for(short jt=0; table[it][jt]!='\0' && cnt<=len; ++jt) table[it][jt]=str[cnt++];
        }
    }

    cout<<"Where to output result: file or console\n";
    char out;
    cin>>out;
    if(out=='f') freopen("res.txt","w",stdout);

    cnt=0;i=0;j=0;
    while(cnt++<=len){
        if(i==0){
            if(cnt==1) cout<<table[i][j++];
            else{--cnt; ++j;}
            if(++cnt<=len) cout<<table[i][j];
        }
        while(j>0 && ++cnt<=len) cout<<table[++i][--j];
        if(j==0 && ++cnt<=len) cout<<table[++i][j];
        while(i!=0 && ++cnt<=len)  cout<<table[--i][++j];
    }
    cout<<"\n";
    return 0;
}
