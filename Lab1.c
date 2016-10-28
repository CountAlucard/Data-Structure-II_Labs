#include <stdio.h>
#include <stdlib.h>

//Al agregar un elemento al arreglo se agregan empezando del indice 1 ya que tuve problemas cuando empezaba del indice 0; Por eso el arreglo es [11]

int boxes[11];
int red[11];
int blue[11];
int empty = 0, rempty = 0, bempty =0, rsum = 0, bsum = 0;

void add(char color, int amount);
int findEmpty(int array[]);
void removeV(int index);
void addAll();
void print();

void add(char color, int amount)
{
  empty = findEmpty(boxes);
  boxes[empty] = amount;
  if(color == 'r'){
    rempty = findEmpty(red);
    red[rempty] = empty;
    rempty+=1;
  }
  else if(color == 'b'){
    bempty = findEmpty(blue);
    blue[bempty] = empty;
    bempty+=1;
  }
}


int findEmpty(int array[])
{
  int pos = 1;
  while(pos < 11)
  {
    if(array[pos] == 0)
    {
      return pos;
    }
    pos++;
  }
}

void removeV(int index)
{
  index += 1;
  int i;
  if(index < 11)
  {
    boxes[index] = 0;
    for(i = 1; i < 11; i++)
    {
      if(red[i] = index){
        red[i] = 0;
        break;
      }
      else if(blue[i] = index){
        blue[i] = 0;
        break;
      }
    }
  }
}

void addAll()
{
  int i = 1;
  while(i < 11)
  {
    if(red[i] !=  0) rsum += boxes[red[i]];
    if(blue[i] != 0) bsum += boxes[blue[i]];
    i++;
  }

}

void print()
{
  int i;
  printf("Values stored in box array: ");
  for(i = 1; i < 11; i++)
  {
    printf("%d - ", boxes[i]);
  }

  printf("\nRed balls are stored in indexes: ");
  for(i = 1; i < 11; i++)
  {
    if(red[i] != 0) printf("%d - ", red[i]);
  }

  printf("\nBlue balls are stored in indexes: ");
  for(i = 1; i < 11; i++)
  {
    if(red[i] != 0) printf("%d - ", blue[i]);
  }

  printf("\nRed balls: %d\n", rsum);
  printf("Blue balls: %d\n", bsum);
  printf("Total balls: %d\n", rsum+bsum);
}

int main(int argc, char const *argv[]) {
  printf("%d",sizeof(int*));
  return 0;
}
