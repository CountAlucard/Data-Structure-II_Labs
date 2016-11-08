#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Persona{
  char *name;
  char *l_name;
  int age;
  struct Persona *next;
};

int reg = 0;
struct Persona *head = NULL;
struct Persona *current = NULL;

void new_persona(char *n, char*ln, int a);
void print_persona(struct Persona *p);
int attribute_sz(char *ptr);
int rsize();

struct Persona_FS
{
  char name[20];
  char l_name[20];
  int age;
  struct Persona_FS *next_fs;
};

int fs_reg = 0;
struct Persona_FS *head_fs = NULL;
struct Persona_FS *current_fs = NULL;

void new_fspersona(char *n, char*ln, int a);
void print_persona_fs(struct Persona_FS *p_fs);
void init_fspersona(struct Persona_FS *pfs);
int fs_rsize();

int nDigits(int i);

void init_persona(struct Persona *p)
{
  int i;
  for(i = 0; i < 20; i++)
  {
    (*p).name[i] = 0;
    (*p).l_name[i] = 0;
  }
}

void init_fspersona(struct Persona_FS *pfs)
{
  int i;
  for(i = 0; i < 20; i++)
  {
    (*pfs).name[i] = 0;
    (*pfs).l_name[i] = 0;
  }
}

void new_persona(char *n, char*ln, int a)
{
  struct Persona *npersona = (struct Persona*)malloc(sizeof(struct Persona));
  npersona->name = n;
  npersona->l_name = ln;
  npersona->age = a;

  npersona->next = head;
  head = npersona;
  reg += 1;

  return;
}

void new_fspersona(char *n, char*ln, int a)
{
  struct Persona_FS *npersona_fs = (struct Persona_FS*)malloc(sizeof(struct Persona_FS));
  strcpy(npersona_fs->name,n);
  strcpy(npersona_fs->l_name,ln);
  npersona_fs->age = a;

  npersona_fs->next_fs = head_fs;
  head_fs = npersona_fs;
  fs_reg += 1;

  return;
}

int rsize() { return reg; }
int fs_rsize() { return fs_reg; }

int attribute_sz(char *ptr)
{
  int offset = 0;
  int count = 0;
  while(*(ptr + offset) != '\0')
  {
    ++count;
    ++offset;
  }
  return count;
}

void print_persona(struct Persona *p)
{
  struct Persona *ptr = head;
  int i = 1;

  while(ptr != NULL)
  {
    printf("\nData from element %d in the Persona list:\n", i);
    printf("\t%s\n", ptr->name);
    printf("\t%s\n", ptr->l_name);
    printf("\t%d\n", ptr->age);
    ptr = ptr->next;
    i++;
  }
  return;
}

void print_persona_fs(struct Persona_FS *p_fs)
{
  struct Persona_FS *ptr_fs = head_fs;
  int i = 1;

  while(ptr_fs != NULL)
  {
    printf("Data from element %d in the Persona list:\n", i);
    printf("\t%s\n", ptr_fs->name);
    printf("\t%s\n", ptr_fs->l_name);
    printf("\t%d\n", ptr_fs->age);
    ptr_fs = ptr_fs->next_fs;
    i++;
  }
  return;
}

int nDigits(int i)
{
  if (i < 0) i = -i;
  if (i <         10) return 1;
  if (i <        100) return 2;
  if (i <       1000) return 3;
  if (i <      10000) return 4;
  if (i <     100000) return 5;
  if (i <    1000000) return 6;
  if (i <   10000000) return 7;
  if (i <  100000000) return 8;
  if (i < 1000000000) return 9;
  return 10;
}
