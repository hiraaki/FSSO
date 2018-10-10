#include <iostream>
#include <cstring>
using namespace std;
int main() {
//    string path = "/dev/sdb1"; //linux
    string path = "\\\\.\\E:"; //windows
    FILE *disk;
    disk=fopen(path.c_str(), "ab+");
    if(!disk){
        cout<<path<<"could not be opened!";
    } else{
        cout<<"------------------------------------------------------"<<endl;
        char buffer[512];
        fseek(disk, 0, SEEK_SET);
        fread(buffer, sizeof(char), sizeof(buffer),disk);
        for(int i=0;i<512;i++){
            printf("%x ", buffer[i]);
        }
        cout<<"------------------------------------------------------"<<endl;
        fseek(disk, 0, SEEK_SET);
        unsigned int dumb=10;
        for (int i = 0; i < 512;i++) {
            fwrite(&dumb, sizeof(int),1,disk);
        }
        fseek(disk, 0, SEEK_SET);
        fread(buffer, sizeof(char), sizeof(buffer),disk);
        for(int i=0;i<512;i++){
            printf("%x ", buffer[i]);
        }
        fclose(disk);
    }

    return 0;
}