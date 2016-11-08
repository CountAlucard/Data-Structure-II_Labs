#include "Persona.h"

//Fixed Size
int FSdata_w(char *data, struct Persona_FS *pfs, int r_index, int r_size);
int FSdata_r(char *data, struct Persona_FS *pfs, int r_index, int r_size);

//Lenght Indicators
int LIdata_w(char *data, struct Persona *p, int r_index, int pos);
int LIdata_r(char *data, struct Persona *p, int r_index, int pos);

//Delimiter Char
int DCdata_w(char *data, struct Persona *p, int r_index);
int DCdata_r(char *data, struct Persona *p);

//Fixed Size
int FSdata_w(char *data, struct Persona_FS *pfs, int r_index, int r_size)
{
  char *rs_data = (char*)malloc(r_size);
  int curr_pos = 0;
  memcpy(&(rs_data[curr_pos]), pfs->name, 20);
  curr_pos += 20;
  memcpy((&rs_data[curr_pos]), pfs->l_name, 20);
  curr_pos += 20;
  memcpy(&(rs_data[curr_pos]), &(pfs->age), 4);
  curr_pos += 20;

  int data_pos = r_index * r_size;
  memcpy(&(data[data_pos]), rs_data, r_size);
  free(rs_data);

  return 1;
}

int FSdata_r(char *data, struct Persona_FS *pfs, int r_index, int r_size)
{
  int data_pos = r_index * r_size;
  char *r_data = &(data[data_pos]);

  int r_pos = 0;
  memcpy(pfs->name, &(r_data[data_pos]),20);
  r_pos += 20;
  memcpy(pfs->l_name, &(r_data[data_pos]), 20);
  r_pos += 20;
  memcpy(&(pfs->age), &(r_data[data_pos]), 4);
  r_pos += 4;

  return 1;
}

//Length Indicators
int LIdata_w(char *data, struct Persona *p, int r_index, int pos)
{
  return 1;
}

int LIdata_r(char *data, struct Persona *p, int r_index, int pos)
{
  return 1;
}

//Delimiter Char
int DCdata_w(char *data, struct Persona *p, int r_index)
{
  int n_size = strlen(p->name)+1;
  int ln_size = strlen(p->l_name)+1;
  int a_size =  nDigits(p->age)+1;
  const char *delim = ";";
  int registerSize = n_size + ln_size + a_size + 2;
  char *r_data = malloc(registerSize);

  int curr_pos = 0;
  memcpy(&(r_data[curr_pos]), p->name, n_size);
  curr_pos += n_size;
  memcpy(&(r_data[curr_pos]), delim, 1);
  curr_pos += 1;

  memcpy(&(r_data[curr_pos]), p->l_name, ln_size);
  curr_pos += ln_size;
  memcpy(&(r_data[curr_pos]), delim, 1);
  curr_pos += 1;

  memcpy(&(r_data[curr_pos]), &(p->age), a_size);
  curr_pos += a_size;

  int data_pos = r_index * registerSize;
  memcpy(&(data[data_pos]), r_data, registerSize);
  free(r_data);

}

int DCdata_r(char *data, struct Persona *p)
{
  
}
