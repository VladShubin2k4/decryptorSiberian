#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
using namespace std;

void DeleteExtraSPACE(string& str){
    for(short i=4; i<str.length();){
        if(str[i]==' '){
            str.erase(i,1);
            i+=4;
        }
    }
}

void BuildDoll(char (&table)[32][32], short& len){
    short cnt=0,i=0,j=0;
    table[i][j]='1';
    while(++cnt<=len){
        if(i==0) table[i][++j]='1';
        while(j>0 && ++cnt<=len) table[++i][--j]='1';
        if(j==0 && ++cnt<=len) table[++i][j]='1';
        while(i>0 && ++cnt<=len)  table[--i][++j]='1';
    }
}

void FillDoll(char (&table)[32][32], short& len, string& str){
    short cnt=0;
    while(cnt<=len){
        for(short i=0; cnt<=len; ++i){
            for(short j=0; table[i][j]!='\0'; ++j) table[i][j]=str[cnt++];
        }
    }
}

void Decrypt(char (&table)[32][32],short& len){
    short cnt=0,i=0,j=0;
    cout<<table[i][j];
    while(++cnt<=len){
        if(i==0) cout<<table[i][++j];
        while(j>0 && ++cnt<=len) cout<<table[++i][--j];
        if(j==0 && ++cnt<=len) cout<<table[++i][j];
        while(i>0 && ++cnt<=len)  cout<<table[--i][++j];
    }
}

int main(){
    ios::sync_with_stdio(false);
    SetConsoleCP(1251);SetConsoleOutputCP(1251);
    const short R=32,C=32;
    char table[R][C]={};

    string str; getline(cin,str);
    DeleteExtraSPACE(str);

    short len=str.length();
    BuildDoll(table,len);
    FillDoll(table,len,str);

    cout<<"Where to output result: file or console\n";
    char out; cin>>out;
    if(out=='f') freopen("res.txt","w",stdout);

    Decrypt(table,len);
    return 0;
}
