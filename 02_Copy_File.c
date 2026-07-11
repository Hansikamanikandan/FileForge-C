#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *source, *destination;
    char ch;

    source = fopen("source.txt", "r");

    if(source == NULL)
    {
        printf("Unable to open source file.");
        return 1;
    }

    destination = fopen("destination.txt", "w");

    while((ch = fgetc(source)) != EOF)
    {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);

    printf("File copied successfully.");

    return 0;
}
