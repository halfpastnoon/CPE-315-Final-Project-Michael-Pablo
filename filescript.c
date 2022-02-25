#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>


int main(){
    FILE* incp = fopen("master.txt", "rb");
    for(int i=0;i<1000000;i++){
        char outname[100];
        sprintf(outname, "Output-%d.txt", i);
        FILE* outcp = fopen(outname, "wb");
        char ch;
        while(fread(&ch, sizeof(char), 1, incp)){
            fwrite(&ch, sizeof(char), 1, outcp);
        }
    }
}