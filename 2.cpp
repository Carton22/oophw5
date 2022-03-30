#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int max=0;
    string a;
    map<string,int> mymap;
    while(getline(cin,a)){
        int loc=a.find("\"");
        if(loc>=0){
            a=a.substr(loc,a.length());
            loc=a.find("/");
            a=a.substr(loc+1,a.length());
            loc=a.find(" ");
            a=a.substr(0,loc);
            loc=a.find('?');
            if(loc!=-1){
                a=a.substr(0,loc);
            }
            if(mymap.count(a))
            mymap[a]++;
            else
            mymap[a]=1;
        }else{
            continue;
        }
    }
    std::map<string,int>::iterator mapiter;
    for(auto mapiter=mymap.begin();mapiter!=mymap.end();++mapiter){
        if(mapiter->second>max){
            max=mapiter->second;
        }
    }
    vector<string> web;
    for(auto mapiter=mymap.begin();mapiter!=mymap.end();++mapiter){
        if(mapiter->second==max){
            web.push_back(mapiter->first);
        }
    }
    sort(web.begin(),web.end());
    for(auto i:web){
        cout<<max<<":/"<<i<<endl;
    }
    return 0;
    
    
}