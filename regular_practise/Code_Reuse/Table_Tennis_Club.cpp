#include <iostream>
#include <string>

using namespace std;

class TableTennisPlayer
{
private:
    /* data */
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string&fn="none",const string&ln="none",bool ht=false);
    TableTennisPlayer(const TableTennisPlayer&);
    void Name()const;
    bool HasTable()const{return hasTable;}
    void ResetTable(bool v){hasTable=v;}
};

class RatedPlayer:public TableTennisPlayer
{
    private:
    int score;
    public:
    RatedPlayer(int,const TableTennisPlayer&);
    RatedPlayer(int s=0,const string&fn="none",const string&ln="none",bool ht=false);

    void setsocore(int s){score=s;}
    void info()const;
};

TableTennisPlayer::TableTennisPlayer(const string&fn,const string&ln,bool ht):firstname(fn),lastname(ln),hasTable(ht)
{
}

TableTennisPlayer::TableTennisPlayer(const TableTennisPlayer& copy_ttp)
{
    firstname=copy_ttp.firstname;
    lastname=copy_ttp.lastname;
    hasTable=copy_ttp.hasTable;
}

void TableTennisPlayer::Name()const
{
    cout<<lastname<<" "<<firstname<<endl;
}

RatedPlayer::RatedPlayer(int s,const string&fn,const string&ln,bool ht):TableTennisPlayer(fn,ln,ht)
{
    score=s;
}

RatedPlayer::RatedPlayer(int s,const TableTennisPlayer& temp):score(s),TableTennisPlayer(temp)
{
}

void RatedPlayer::info()const
{
    TableTennisPlayer::Name();
    cout<<"The score is "<<score<<endl;
}

int main()
{
    TableTennisPlayer sxz("xingzhi","shi",false);
    sxz.Name();

    RatedPlayer rated_sxz(10,sxz);
    rated_sxz.info();
}