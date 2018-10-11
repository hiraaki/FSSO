#include <iostream>
#include <cstring>
#include <SAD16.h>
#include <stdio.h>
//#include <sys/vfs.h>

using namespace std;


int main() {
    string path = "/dev/sdb1"; // para a gabriela no linux, amém
    //string path = "/dev/sdb1"; //linux
    //string path = "\\\\.\\D:"; //windows
    FILE *disk;
    disk=fopen(path.c_str(), "rb+");

    BootSAD piranha;


    if(!disk){
        cout<<path<<"could not be opened!";
    } else{


        int n=0;

//        while(n!=5){
            cout<< "O que deseja fazer?" << endl
            << "1) Formatar" << endl
            << "2) Copiar arquivo do computador para pendrive" << endl
            << "3) Copiar arquivo do pendrive para o computador" <<  endl
            << "4) Listar arquivos" << endl
            << "5) Sair" << endl;
            cin >> n;

            switch (n){
                case 1:
                    unsigned int sectors;
                    cout<<"Numero de Setores a Serem Alocados: ";
                    cin>>sectors;
                    SAD16 fs;
                    fs.setDevice(disk);
                    fs.formatDevice(sectors);


                    break;
                case 2:


                    break;
                case 4:

                    break;
            }
        }
        fclose(disk);



//    }

    return 0;
}