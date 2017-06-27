#include <iostream>
#include <fstream>
#include <cstring>
#include "FileCommand.h"
#include "BlankCell.h"
#include "IntCell.h"
#include "DoubleCell.h"
#include "StringCell.h"
#include "SRow.h"
#include "Spreadsheet.h"
using namespace std;

//функция реализираща командния лог.
void FileCommands(Spreadsheet& ss) {
    bool ready = false;
    FileCommand a;
    char CurrentPath[256];
    while (!ready) {
        cin >> a;
        if (a == FileCommand("exit")) {
            cout << "Exiting program..." << endl;
            break;
        }
        if (a == FileCommand("open")) {
            ifstream inf(a.getPath());
            if (!(inf.is_open())) {
                ofstream tmp(a.getPath());
                tmp.close();
                ifstream inf(a.getPath());
                if (!inf.is_open()) {
                    cerr << "Can't open file for reading..." << endl;
                    continue;
                } else {
                    cout << "File successfully opened." << endl;
                }
            } else {
                cout << "File successfully opened." << endl;
            }
            try {
                inf >> ss;
                inf.close();
                //използваме флаг за да обозначим, че сме успели да прехвърлим данните от файла в паметта и можем да използваме
                //последващите команди.
                ready = true;
                strcpy(CurrentPath, a.getPath());
                while (ready) {
                    cin >> a;
                    if (a == FileCommand("close")) {
                        ready = false;
                        cout << "File successfully closed." << endl;
                        //Изтриваме  данните от паметта
                        ss.empty();
                        break;
                    }
                    if (a == FileCommand("save")) {
                        ofstream of(CurrentPath);
                        of << ss;
                        //записваме данните обратно в същия файл.
                        of.close();
                        cout << "File successfully saved." << endl;
                    }
                    if (a == FileCommand("saveas")) {
                        ofstream of(a.getPath());
                        //записваме данните в нов .txt файл.
                        of << ss;
                        of.close();
                        cout << "File successfully saved as " << a.getPath() << endl;
                    }
                    if (a == FileCommand("exit")) {
                        cout << "Exiting program..." << endl;
                        break;
                    }
                    if (a == FileCommand("edit")) {
                        int row, col;
                        char buffer[128];
                        cin >> row >> col;
                        cin.getline(buffer, 128);
                        if(ss.Edit(row - 1, col - 1, buffer)){
                            cout << "Cell on row " << row << " and column " << col << " edited successfuly" << endl;
                        }
                        ss.FinalState();

                    }
                    if (a == FileCommand("print")) {
                        ss.Print();
                    }

                }
            } catch (char* ex) {
                cout << "Error " << ex << " is invalid data type" << endl;
            }
        }
    }
}

int main() {
    Spreadsheet ss;
    FileCommands(ss);
    return 0;
}