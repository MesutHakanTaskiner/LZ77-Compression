#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define length 100
#define max_length 100000

int main()
{
    FILE *file;
    file = fopen("Hakan.txt", "r+");

    char array[length], oneword[max_length], memory[length];
    char space = ' ', comma = ',', dot = '.';

    int i = 0, j, count = 0, count2 = 0, count3 = 0, count4 = 0;

    while(!feof(file))
    {
        fscanf(file, "%c", &oneword[i]);
        //printf("%c", oneword[i]);
        i++;
    }

    //printf("\n\n\n");

    for(i = 0; i < strlen(oneword); i++)
    {
        for (j = 0; j < strlen(oneword); j++)
        {
            //if(oneword[i] == oneword[j] && oneword[i + 1] == oneword[j + 1])
             //   count2++;

            if(oneword[i] == oneword[j] && oneword[i + 1] == oneword[j + 1] && oneword[i + 2] == oneword[j + 2])
                count3++;

            if(oneword[i] == oneword[j] && oneword[i + 1] == oneword[j + 1] && oneword[i + 2] == oneword[j + 2] && oneword[i + 3] == oneword[j + 3])
                count4++;
        }

        if(oneword[i] != space && oneword[i] != comma && oneword[i] != dot && count4 > count3 || count4 == count3)
        {
            //printf("%c%c %d tane var. ", oneword[i], oneword[i + 1], count2);
            //printf("%c%c%c %d tane var. ", oneword[i], oneword[i + 1], oneword[i + 2], count3);
            printf("%c%c%c%c %d tane var. ", oneword[i], oneword[i + 1], oneword[i + 2], oneword[i + 3], count4);
        }

        if(oneword[i] != space && oneword[i] != comma && oneword[i] != dot && count4 < count3)
        {
            //printf("%c%c %d tane var. ", oneword[i], oneword[i + 1], count2);
            printf("%c%c%c %d tane var. ", oneword[i], oneword[i + 1], oneword[i + 2], count3);
            //printf("%c%c%c%c %d tane var. ", oneword[i], oneword[i + 1], oneword[i + 2], oneword[i + 3], count4);
        }

        count2 = 0;
        count3 = 0;
        count4 = 0;
        printf("\n");
    }

}
