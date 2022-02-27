#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

#define CPYCT 250000


int main(){
    FILE* incp = fopen("master.txt", "rb");
    FILE* outcp[CPYCT];
    //FILE** outcp = malloc(sizeof(FILE*) * 1019);
    for(int i=0;i<CPYCT;i++){
        char outname[100];
        sprintf(outname, "Output-%d.txt", i);
        outcp[i] = fopen(outname, "wb");
        char ch;
        while(fread(&ch, sizeof(char), 1, incp)) fwrite(&ch, sizeof(char), 1, outcp[i]);
        if(i>=1019) fclose(outcp[i-1019]);
        fseek(incp, 0, SEEK_SET);
    }
    //free(outcp);
    fclose(incp);
}
