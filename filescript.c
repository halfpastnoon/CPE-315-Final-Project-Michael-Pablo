#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

#define CPYCT 250000
#define FSZ 4097


int main(){
    FILE* incp = fopen("master.txt", "rb");
    struct stat buf;
    stat("master.txt", &buf);
    int fsz = buf.st_size;
    //FILE* outcp[CPYCT];
    FILE* outcp;
    char* data[CPYCT];
    for(int i=0;i<CPYCT;i++){
        char outname[100];
        sprintf(outname, "Output-%d.txt", i);
        outcp = fopen(outname, "wb");
        data[i] = malloc(sizeof(char)*fsz);
        fread(&data[i], sizeof(char), fsz, incp);
        fwrite(&data[i], sizeof(char), fsz, outcp);
        //char ch;
        //while(fread(&ch, sizeof(char), 1, incp)) fwrite(&ch, sizeof(char), 1, outcp[i]);
        //if(i>=1019) fclose(outcp[i-1019]);
        fclose(outcp);
        fseek(incp, 0, SEEK_SET);
    }
    fclose(incp);
}
