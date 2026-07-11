#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int regno;
    char name[30];
    float mark;
    char grade;
};

int main()
{
    FILE *fp;
    struct Student s;
    int n, i;

    fp = fopen("student.txt", "w");

    if(fp == NULL)
    {
        printf("Unable to open file.");
        return 1;
    }

    printf("Enter Number of Students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Enter Register Number: ");
        scanf("%d", &s.regno);

        printf("Enter Name: ");
        scanf("%s", s.name);

        printf("Enter Mark: ");
        scanf("%f", &s.mark);

        if(s.mark >= 90)
            s.grade = 'A';
        else if(s.mark >= 80)
            s.grade = 'B';
        else if(s.mark >= 70)
            s.grade = 'C';
        else if(s.mark >= 60)
            s.grade = 'D';
        else
            s.grade = 'F';

        fprintf(fp, "%d\t%s\t%.2f\t%c\n", s.regno, s.name, s.mark, s.grade);
    }

    fclose(fp);

    fp = fopen("student.txt", "r");

    printf("\nStudent Details\n");
    printf("\nRegNo\tName\tMark\tGrade\n");

    while(fscanf(fp, "%d%s%f %c", &s.regno, s.name, &s.mark, &s.grade) != EOF)
    {
        printf("%d\t%s\t%.2f\t%c\n", s.regno, s.name, s.mark, s.grade);
    }

    fclose(fp);

    return 0;
}
