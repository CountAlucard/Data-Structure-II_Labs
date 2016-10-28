#include <stdio.h>
#include <stdlib.h>

//En esta tarea tuve que convertir el resultado de las operaciones a un char array ya que me daba problemas el fwrite a la hora de escribir en el archivo
//El resultado es un long para poder escribir valores mas grandes (tanto positivos como negativos) en el archivo

int x, y;
long result;
int option;
char s[32];
FILE *fp;
char *fname = "file.hex";

void menu();
void addition();
void subtraction();
void multiplication();
int loadFile(char fname[]);

int main()
{
    menu();
    return 0;
}

void menu()
{
    if(loadFile(fname))
    {
      printf("\nSelect the mathematical operation you want to use: \n");
      printf("1. Addition\n");
      printf("2. Subtraction\n");
      printf("3. Multiplication\n");
      scanf("%d", &option);

      switch(option)
      {
          case 1:
                  addition();
                  break;
          case 2:
                  subtraction();
                  break;
          case 3:
                  multiplication();
                  break;
      }
    }
}

void addition()
{
    printf("\nYou have selected addition.\n");
    result = x+y;
    sprintf(s,"%ld", result);
    fseek(fp, 0, SEEK_END);
    fwrite(s, sizeof(long), 1, fp);
    fclose(fp);
    printf("%d\n", x+y);
}

void subtraction()
{
    printf("\nYou have selected subtraction.\n");
    result = x-y;
    sprintf(s,"%ld", result);
    fseek(fp, 0, SEEK_END);
    fwrite(s, sizeof(long), 1, fp);
    fclose(fp);
    printf("%d\n", x-y);
}

void multiplication()
{
    printf("\nYou have selected multiplication.\n");
    result = x*y;
    sprintf(s,"%ld", result);
    fseek(fp, 0, SEEK_END);
    fwrite(s, sizeof(long), 1, fp);
    fclose(fp);
    printf("%d\n", x*y);
}

int loadFile(char fname[])
{
    fp = fopen(fname, "r+");
    if(fp == NULL)
    {
        printf("\nFailed to open %s. Please try a different file.\n", fname);
        return 0;
    }
    printf("\nFile opened successfully\n");
    fscanf(fp, "%d", &x);
    fscanf(fp, "%d", &y);
    return 1;
}
