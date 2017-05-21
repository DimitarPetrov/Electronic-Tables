#include <iostream>
#include <fstream>
#include <cstring>
#include "FileCommand.h"
using namespace std;

void FileCommands(){
    bool ready = false;
    FileCommand a;
    char CurrentPath[256];
    while(!ready){
        cin>>a;
        if(a == FileCommand("exit")){
            cout<<"Exiting program..."<<endl;
            break;
        }
        if(a == FileCommand("open")){
            ifstream inf(a.getPath());
            if(!(inf.is_open())){
                ofstream tmp(a.getPath());
                tmp.close();
                ifstream inf(a.getPath());
                if(!inf.is_open()){
                    cerr<<"Can't open file for reading..."<<endl;
                    continue;
                }
                else{
                    cout << "File successfully opened." << endl;
                }
            }
            else{
                cout << "File successfully opened." << endl;
            }
            //Прехвърлям данните от файла в паметта
            inf.close();
            //използваме флаг за да обозначим, че сме успели да прехвърлим данните от файла в паметта и можем да използваме
            //последващите команди.
            ready = true;
            strcpy(CurrentPath,a.getPath());
            while(ready){
                cin>>a;
                if(a == FileCommand("close")){
                    ready = false;
                    cout<<"File successfully closed."<<endl;
                    //Изтриваме  данните от паметта
                    break;
                }
                if(a == FileCommand("save")){
                    ofstream of(CurrentPath);
                    //записваме данните обратно в същия файл.
                    of.close();
                    cout<<"File successfully saved."<<endl;
                }
                if(a == FileCommand("saveas")){
                    ofstream of(a.getPath());
                    //записваме данните в нов .txt файл.
                    of.close();
                    cout<<"File successfully saved as "<<a.getPath()<<endl;
                }
                if(a == FileCommand("exit")){
                    cout<<"Exiting program..."<<endl;
                    break;
                }

            }
        }
    }
}

int main() {

    return 0;
}