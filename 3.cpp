#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>
using namespace std;
struct student{
    private:
        string ID;
        
    public:
        string name;
        map<string,double> clsscore;
        void init(string s,string n){
            name=n;
            ID=s;
        }
        student(const student &t){name = t.name;ID = t.ID;clsscore=t.clsscore;}
        student(){}
        void addscore(string t,double k){
            clsscore[t]=k;
        }
        double calavr(){
            double sum=0;
            int cnt=0;
            for(map<string,double>::iterator p=clsscore.begin();p!=clsscore.end();p++){
                sum+=p->second;
                cnt++;
            }
            double avr;
            avr=sum/cnt;
//             cout<<'@'<<avr<<endl;
            return avr;
        }


};
struct course{
    private:
        string nom;//name
        int number;//student number
        double sum;//sum score
    public:
        // course(string n,double v):nom(n),
        void init(string s){
            sum=0.0;
            nom=s;
            number=0;
        };
        void insscore(double c){
            number++;
            sum+=c;
        };
        double calavr(){
            return sum/number;
        };
};
map<string,student> idtostu;
map<string,course> nametocour;
string& trim(string &s) 
{
    if (s.empty()) 
    {
        return s;
    }
 
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
};


double string2num(const string& str)
{
    istringstream iss(str);
    double num;
    iss >> num;
    return num;    
};
int main(){
    string line;
    while (getline(cin, line)) {
        if ( line.size() <1 ) continue;
        istringstream f(line);
        vector<string> a;
        string w;
        while (getline(f, w, ',') ) {
            trim(w);
            a.push_back(w);
        }
        int judge=a.size();
        if(judge==2){
            // cout<<"hello"<<endl;
             student tempstu;
             tempstu.init(a[0],a[1]);
            //  cout<<"here"<<tempstu.name<<endl;
             idtostu[a[0]].name=tempstu.name;
        }else if(judge==3){
            double temp=string2num(a[2]);
            if(nametocour.count(a[1])==0){
                course tempc=nametocour[a[1]];
                tempc.init(a[1]);
            }
            idtostu[a[0]].addscore(a[1],temp);
            nametocour[a[1]].insscore(temp);
        }
        // cout<<'1'<<endl;
    }
    cout<<"student id, name,";
    for (map<string, course>::iterator p = nametocour.begin(); p!= nametocour.end(); p++ ) {
        cout << ' '<< p->first<<',';
    }
    cout<<' '<<"average"<<endl;
    // cout<<idtostu["3180111430"].name<<endl;
    for (map<string, student>::iterator p = idtostu.begin(); p!= idtostu.end(); p++ ) {
        cout << p->first << ','<<' '<<p->second.name;
        for (map<string, course>::iterator q = nametocour.begin(); q!= nametocour.end(); q++ ) {
            cout <<','<<' ';
            if(p->second.clsscore.count(q->first)){
                cout<<p->second.clsscore[q->first];
            }
        }
        cout<<','<<' '<<fixed<<setprecision(1)<<p->second.calavr()<<endl;
    }
    cout<<", ";
    double avrsum;
    int avrcnt=0;
    for (map<string, course>::iterator p = nametocour.begin(); p!= nametocour.end(); p++ ) {
        cout <<','<<' '<<fixed<<setprecision(1)<<p->second.calavr();
        avrsum+=p->second.calavr();
        avrcnt++;
    }
    double avravr=0;
    avravr=avrsum/avrcnt;
    cout<<','<<' '<<fixed<<setprecision(1)<<avravr;
    




}