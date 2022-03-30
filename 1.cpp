// learn string.compare string.strtok()
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string res;
int convert(string x){
    int tempcnt=0;
    for(int i=0;i<=x.length();i++){
        if(x[i]>='0'&&x[i]<='9')
        tempcnt=tempcnt*16+x[i]-'0';
        else if(x[i]>='A'&&x[i]<='F')
        tempcnt=tempcnt*16+x[i]-'A'+10;
    }
    return tempcnt;
}
int check(string c){
    vector<string> tempstore;
    const char b=',';
    string s;
    string tempori=c;
    int loc=0;
    while(1){
        loc=tempori.find(b);
        if(tempori.find(b)==string::npos){
            tempstore.push_back(tempori);
            break;
        }else{
            tempstore.push_back(tempori.substr(0,loc));
            tempori=tempori.substr(loc+1,tempori.length());
        }
    } 
    if(tempstore[0]=="$GPRMC"){
        if(tempstore[2]==string(1,'A')){
            int checktarget=0;
            loc=c.find("*");
            tempori=c.substr(loc+1,c.length());
            checktarget=convert(tempori);
            string cal;
            int sum=0;
            int calnum=0;
            for(int i=c.find('$')+1;i<(int)c.find('*');i++){
                cal=c[i];
                calnum=(int)c[i];
                sum^=calnum;
            }

            sum=sum%65536;
            if(sum==checktarget){
                tempori=tempstore[1];
                string chour=tempori.substr(0,2);
                int ihour=(atoi(chour.c_str())+8)%24;
                chour=to_string(ihour);
                if (chour.length()==1){
                    chour='0'+chour;
                }
                res=chour+':'+tempori.substr(2,2)+':'+tempori.substr(4,2);
                return 1;
            }else{
                tempstore.clear();
                return 0;
            }
        }else{
            tempstore.clear();
            return 0;
        }
    }else{
        tempstore.clear();
        return 0;
    }
}
int main(){
    string a;
    int num=0;
    while(1){
        getline(cin,a);
        if(a=="END"){
            break;
        }else{
           num=check(a); 
        }
    }
    cout<<res<<endl;
    return 0;
}
