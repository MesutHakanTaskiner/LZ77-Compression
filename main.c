#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define length 10000

struct word
{
    char word_array;
};


int main()
{
    struct word prime_array[length];

    FILE *file;
    file = fopen("Hakan.txt", "r+");

    char oneword[length], *memory[length], *ch[length], *ch2[length], *ch3[length], *ch4[length];
    char space = ' ', comma = ',', dot = '.';

    int i = 0, j, count = 0, count2 = 0, count3 = 0, count4 = 0;
    int line_Number[length];

    while(!feof(file))
    {
        fscanf(file, "%c", &oneword[i]);
        i++;
    }

    for(i = 0; i < strlen(oneword); i++)
    {
        for (j = 0; j < strlen(oneword); j++)
        {
            if(oneword[i] == oneword[j] && oneword[i + 1] == oneword[j + 1] && oneword[i + 2] == oneword[j + 2])
                count3++;

            if(oneword[i] == oneword[j] && oneword[i + 1] == oneword[j + 1] && oneword[i + 2] == oneword[j + 2] && oneword[i + 3] == oneword[j + 3])
                count4++;
        }

        if(oneword[i] != space && oneword[i] != comma && oneword[i] != dot && count4 > count3 || count4 == count3)
        {
            printf("%d %d %d %d       %c%c%c%c %d tane var. ", i, (i + 1), (i + 2), (i + 3), oneword[i], oneword[i + 1], oneword[i + 2], oneword[i + 3], count4);

            *ch = oneword[i];
            *ch2 = oneword[i + 1];
            *ch3 = oneword[i + 2];
            *ch4 = oneword[i + 3];

            strcat(ch, ch2);
            strcat(ch, ch3);
            strcat(ch, ch4);
            strcat(memory, ch);
            printf("   %s", memory);
            //strcpy(prime_array[i].word_array, memory);
            //printf("\n%s\n", prime_array[0].word_array);
            i += 3;
        }

        if(oneword[i] != space && oneword[i] != comma && oneword[i] != dot && count3 > count4)
        {
            printf("%d %d %d           %c%c%c %d tane var. ", i, (i + 1), (i + 2), oneword[i], oneword[i + 1], oneword[i + 2], count3);

            *ch = oneword[i];
            *ch2 = oneword[i + 1];
            *ch3 = oneword[i + 2];

            strcat(memory, ch);
            strcat(memory, ch2);
            strcat(memory, ch3);
            printf("   %s", memory);
            //strcpy(prime_array[0].word_array, memory);
            //printf("\n%s\n", prime_array[0].word_array);
            i += 2;
        }

        *ch = NULL;
        *ch2 = NULL;
        *ch3 = NULL;
        *ch4 = NULL;
        *memory = NULL;

        count2 = 0;
        count3 = 0;
        count4 = 0;
        printf("\n");
    }
}
