#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;

class library
{
    string accession_number;
    string author;
    string title;
    string year_publication;
    int cost;
    public:
    library()
    {
        cout<<"enter accession number : ";
        getline(cin>>ws,accession_number);
        cout<<"enter author name : ";
        getline(cin>>ws,author);
        cout<<"enter title : ";
        getline(cin>>ws,title);
        cout<<"enter year of publication : ";
        getline(cin>>ws,year_publication);
        cout<<"enter cost : ";
        cin>>cost;
    }
    void print()
    {
        cout<<setw(22)<<right<<"accession number :  "<<accession_number<<endl;
        cout<<setw(22)<<right<<"name of author : "<<author<<endl;
        cout<<setw(22)<<right<<"title of the book : "<<title<<endl;
        cout<<setw(22)<<right<<"year of publication : "<<year_publication<<endl;
        cout<<setw(22)<<right<<"cost of the book : "<<cost<<endl<<endl;
    }
    string gettitle()
    {
        return title;
    }
    friend char prober_accession(library,int);
    friend char prober_author(library,int);
    friend char prober_title(library,int);
    friend char prober_year(library,int);
};
char prober_accession(library v,int i)
{
    return v.accession_number[i];
}
char prober_author(library v,int i)
{
    return v.author[i];
}
char prober_title(library v,int i)
{
    return v.title[i];
}
char prober_year(library v,int i)
{
    return v.year_publication[i];
}

int main()
{
    int c{};
    vector<library> v;
    vector<library>::iterator it;
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
                cout<<"book "<<i<<endl;
                cout<<"---------"<<endl;
                it->print();
            }
            break;
        }
        case 2:
        {
            cout<<endl;
            library v1;
            v.push_back(v1);
            cout<<endl;
            break;
        }
        case 3:
        {
            cout<<endl<<"enter the entry which you want to edit(note:the first entry starts from one) : ";
            int edit_num{};
            cin>>edit_num;
            v[edit_num-1]=library();
            break;
        }
        case 4:
        {
            // int cases{};
            // cout<<"select one of the options : "<<endl;
            // cout<<"search by name:1 ,search by DOB:2, search by address:3 ";
            string search;
            cout<<endl<<"this program searches the given keyword in title,author,accession number,year of publication"<<endl;
            cout<<"even if one entry has multiple occurance of the keyword in title,author etc, it is printed only once"<<endl;
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
                    if(search[j]!=prober_accession(*it,j)) break;
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
                    if(search[j]!=prober_author(*it,j)) break;
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
                    if(search[j]!=prober_title(*it,j)) break;
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
                    if(search[j]!=prober_year(*it,j)) break;
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
                    if (v[i].gettitle()>v[i+1].gettitle())
                    {
                        library temp=v[i];
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
