#include <iostream>
#include <cstring>
#include <SAD16.h>
//#include <sys/vfs.h>

using namespace std;


int main() {
//    string path = "/dev/sdb"; // para a gabriela no linux, amém
    //string path = "/dev/sdb1"; //linux
    string path = "\\\\.\\E:"; //windows
    FILE *disk;

    disk=fopen(path.c_str(), "ab+");

    if(!disk){
        cout<<path<<"could not be opened!";
    } else{

        int n=0;

        while(n!=5){
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
                    cout<<"------------------------------------------------------"<<endl;
                    char buffer[512];
                    fseek(disk, 0, SEEK_SET);
                    fread(buffer, sizeof(char), sizeof(buffer),disk);
                    for(int i=0;i<512;i++){
                        printf("%x ", buffer[i]);
                    }
                    unsigned int dumb;
                    dumb=10;
                    for (int i = 0; i < 32;i++) {
                        fwrite(&dumb, sizeof(int),1,disk);
                    }
                    fseek(disk, 0, SEEK_SET);
                    fread(buffer, sizeof(char), sizeof(buffer),disk);
                    for(int i=0;i<512;i++){
                        printf("%x ", buffer[i]);
                    }
                    break;

                case 2:


                    break;
            }
        }


//                    struct statfs fsb;
//
//                    if(statfs("/dev/sdb", &fsb) == 0)
//                        printf("device has %ld blocks, each %ld bytes\n", fsb.f_blocks, fsb.f_bsize);
//                        //cout << (fsb.f_blocks*fsb.f_bsize)/(1024*1024*1024) << " gb";
//                        cout << (fsb.f_blocks*fsb.f_bsize)/(1024*1024*1024) << " gb";



//        cout<<"------------------------------------------------------"<<endl;
//        char buffer[512];
//        fseek(disk, 0, SEEK_SET);
//        fread(buffer, sizeof(char), sizeof(buffer),disk);
//        for(int i=0;i<512;i++){
//            printf("%x ", buffer[i]);
//        }
//        cout<<"------------------------------------------------------"<<endl;
//        fseek(disk, 0, SEEK_SET);
//        unsigned int dumb=10;
//        for (int i = 0; i < 512;i++) {
//            fwrite(&dumb, sizeof(int),1,disk);
//        }
//        fseek(disk, 0, SEEK_SET);
//        fread(buffer, sizeof(char), sizeof(buffer),disk);
//        for(int i=0;i<512;i++){
//            printf("%x ", buffer[i]);
//        }

        fclose(disk);
    }

    return 0;
}