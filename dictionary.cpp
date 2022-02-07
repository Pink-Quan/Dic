#include <iostream>
#include <string>
#include <vector>
#include<fstream>
using namespace std;

typedef struct dictionary
{
    string eng;
    string viet;
}dictionary;

vector<dictionary> vietEngDic;
void loadData()
{
    fstream data;
    data.open("dataDic.quan",ios_base::in);
    if(data.fail())
    {
        cout<<"Data file not found";
        data.open("dataDic.quan",ios_base::out);
        data<<"Quan La-dev-dep-trai-da-tao-ra-app-tu-dien-nay\n";
        //data.open("dataDic.quan",ios_base::in);
    }
    vietEngDic.clear();
    dictionary*tempdic=new dictionary;
    while (!data.eof())
    {
        data>>tempdic->eng;
        data>>tempdic->viet;
        vietEngDic.push_back(*tempdic);
    }
    data.close();
    delete(tempdic);
}
void addWord()
{
    dictionary*tempDic=new dictionary;
    cout<<endl<<"Word must not have space " "";
    cout<<"\nInput English word: ";
    cin>>tempDic->eng;
    cout<<"Input Vietnamese meaning: ";
    cin>>tempDic->viet;
    vietEngDic.push_back(*tempDic);
    ofstream data;
    data.open("dataDic.quan",ios_base::app|ios_base::out);
    data<<tempDic->eng<<" "<<tempDic->viet<<"\n";
    data.close();
    delete(tempDic);
    system("cls");
    loadData();
}

void searchWord()
{
    cout<<"\n*****Type 0 to go to Menu*****";
    next:
    string find;
    cout<<"\nSearch: ";
    cin>>find;
    if(find=="0")
    {
        system("cls");
        return;
    }
    cin.ignore();
    bool cantfind=true;
    for(int i=0;i<vietEngDic.size();i++)
    {
        if(find==vietEngDic[i].eng)
        {
            cout<<endl<<"\tEng: "<<find<<"\n\tViet: "<<vietEngDic[i].viet<<endl;
            cantfind=false;
            break;
        }
    }
    if(cantfind)
        cout<<endl<<"\tNot found\n";
    goto next;
}

void deleteWord()
{
    string find;
    cout<<"Input English word to delete: ";
    cin>>find;
    cin.ignore();
    for(int i=0;i<vietEngDic.size();i++)
    {
        if(find==vietEngDic[i].eng)
        {
            cout<<"\n\tDelete "<<vietEngDic[i].eng<<" with meaning is "<<vietEngDic[i].viet<<" sucessfully\n";
            vietEngDic.erase(vietEngDic.begin()+i);
            ofstream data;
            data.open("dataDic.quan",ios_base::trunc|ios_base::out);
            for(int i=0;i<vietEngDic.size();i++)
            {
                data<<vietEngDic[i].eng<<" "<<vietEngDic[i].viet<<" ";
            }
            data.close();
            cout<<"\nPress any key to continue\n";
            cin.ignore();
            system("cls");
            return;
        }
    }
    cout<<endl<<"Not found\n";
    cout<<"\tPress any key to continue";
    cin.ignore();
    system("cls");
}

int main()
{
    loadData();
    int in=0;
    next:
    cout<<"\n\t=============================MENU=============================\n\t| 1.Search 2.Add word 3.Delete word 4.App Information 0.Exit |\n\t==============================================================\nInput function: ";
    cin>>in;
    switch (in)
    {
        case 1:
            searchWord();
            break;
        case 2:
            addWord();
            break;
        case 3:
            deleteWord();
            break;
        case 4:
            system("cls");
            cout<<"\n\tEnglish-Vietnamese dictionary using C/C++ ver 1.0 by Tran Hong Quan\n";
            cout<<"\nPress any key to continue";
            cin.ignore();
            cin.ignore();
            system("cls");
            break;
        case 0:
            cout<<"Exit";
            return 0;
        default:
            break;
    }
    goto next;
    return 0;
}