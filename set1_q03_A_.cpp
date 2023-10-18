#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;

class personalInfo
{
    string name;
    string DOB;
    string bloodG;
    int height;
    int weight;
    string address;
    int telephone;
    public:
    personalInfo()
    {
        cout<<"enter name : ";
        getline(cin>>ws,name);
        cout<<"enter DOB : ";
        getline(cin>>ws,DOB);
        cout<<"enter blood group : ";
        getline(cin>>ws,bloodG);
        cout<<"enter height : ";
        cin>>height;
        cout<<"enter weight : ";
        cin>>weight;
        cout<<"enter address : ";
        getline(cin>>ws,address);
        cout<<"enter telephone no. : ";
        cin>>telephone;
    }
    void print()
    {
        cout<<"name : "<<name<<endl;
        cout<<"DOB : "<<DOB<<endl;
        cout<<"blood group : "<<bloodG<<endl;
        cout<<"height : "<<height<<endl;
        cout<<"weight : "<<weight<<endl;
        cout<<"address : "<<address<<endl;
        cout<<"telephone : "<<telephone<<endl<<endl;
    }
    string getname()
    {
        return name;
    }
    friend char prober_name(personalInfo,int);
    friend char prober_DOB(personalInfo,int);
    friend char prober_bloodG(personalInfo,int);
    friend char prober_address(personalInfo,int);
};
char prober_name(personalInfo v,int i)
{
    return v.name[i];
}
char prober_DOB(personalInfo v,int i)
{
    return v.DOB[i];
}
char prober_bloodG(personalInfo v,int i)
{
    return v.bloodG[i];
}
char prober_address(personalInfo v,int i)
{
    return v.address[i];
}

int main()
{
    int c{};
    vector<personalInfo> v;
    vector<personalInfo>::iterator it;
    while(1)
    {    
        cout<<"enter which operation you want to perform "<<endl;
        cout<<"list table - 1 , insert a new entry - 2 , edit entry - 3 "<<endl;
        cout<<"search for a record and print - 4 , sort entries - 5"<<endl<<endl;
        cin>>c;
       // cout<<v.size()<<endl;
        switch (c)
        {
        case 1:
        {   int i{1};
            for(it=v.begin();it!=v.end();it++,i++)
            {
                cout<<"person "<<i<<endl;
                cout<<"---------"<<endl;
                it->print();
            }
            break;
        }
        case 2:
        {
            cout<<endl;
            personalInfo v1;
            v.push_back(v1);
            cout<<endl;
            break;
        }
        case 3:
        {
            cout<<endl<<"enter the entry which you want to edit(note:the first entry starts from one) : ";
            int edit_num{};
            cin>>edit_num;
            v[edit_num-1]=personalInfo();
            break;
        }
        case 4:
        {
            // int cases{};
            // cout<<"select one of the options : "<<endl;
            // cout<<"search by name:1 ,search by DOB:2, search by address:3 ";
            string search;
            cout<<endl<<"this program searches the given keyword in name,DOB,blood group,address"<<endl;
            cout<<"even if one entry has multiple occurance of the keyword in name,address etc, it is printed only once"<<endl;
            cout<<"enter the name to be searched for : ";
            cin>>search;
            for(it=v.begin();it!=v.end();it++)
            {
                bool complete{};
                //searching name
                int j{};
                for(;j<search.length();j++)
                {
                    if(complete)break;
                    if(search[j]!=prober_name(*it,j)) break;
                }
                if(j==search.length())
                {
                    cout<<endl;
                    it->print();
                    complete=1;
                    cout<<endl<<endl;
                }
                //searching DOB
                j=0;
                for(;j<search.length();j++)
                {
                    if(complete)break;
                    if(search[j]!=prober_DOB(*it,j)) break;
                }
                if(j==search.length())
                {
                    cout<<endl;
                    if(complete)break;
                    it->print();
                    cout<<endl<<endl;
                }
                //searching blood group
                j=0;
                for(;j<search.length();j++)
                {
                    if(complete)break;
                    if(search[j]!=prober_bloodG(*it,j)) break;
                }
                if(j==search.length())
                {
                    cout<<endl;
                    it->print();
                    cout<<endl<<endl;
                }
                //searching address
                j=0;
                for(;j<search.length();j++)
                {
                    if(complete)break;
                    if(search[j]!=prober_address(*it,j)) break;
                }
                if(j==search.length())
                {
                    cout<<endl;
                    it->print();
                    cout<<endl<<endl;
                }
            }
            break;            
        }
        case 5:
        {   //insertion sort algorithm is implemented below
            int j=v.size()-1;
            while(j!=0)
            {
                for(int i{};i<j;i++)
                {
                    if (v[i].getname()>v[i+1].getname())
                    {
                        personalInfo temp=v[i];
                        v[i]=v[i+1];
                        v[i+1]=temp;
                    }
                }
                j--;
            }
            break;
        }
        default:
            break;
        }
    }
    //v.pushback(v1);
    return 0;
}
