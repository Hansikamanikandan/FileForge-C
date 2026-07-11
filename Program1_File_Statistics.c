#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;
    int characters = 0, lines = 0;

    fp = fopen("input.txt", "r");

    if(fp == NULL)
    {
        printf("Unable to open file.");
        return 1;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        characters++;

        if(ch == '\n')
            lines++;
    }

    fclose(fp);

    printf("Number of Characters : %d\n", characters);
    printf("Number of Lines : %d\n", lines + 1);

    return 0;
}
