#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int bruteForce(char * wholeThing, char* toSearch);


int bruteForce(char * wholeThing, char* toSearch)
{
  int i2;
  int counterReach=strlen(toSearch);
  int i=0;
  for(i=0;i<(strlen(wholeThing)-counterReach);i++)
  {
    i2=0;
    for(int j=0;j<counterReach;j++)
    {
      if(toSearch[j]!=wholeThing[i+i2])
      {
        break;
      }
      i2++;

      if(i2==counterReach)
      {
        printf("Number of shifts: %d\n",i);
        return i;
      }
    }

  }
  printf("Number of shifts: %d\n",i);
  return -1;
}


int main(void)
{
  FILE *fp=fopen("data_5.txt","r");
  char * wholeThing=malloc(1);
  char * toSearch=malloc(200);
  int count=0,hold=0;
  clock_t start, end;
  double cpu_time_used;

  while((hold=fgetc(fp))!=EOF)
  {
    wholeThing=realloc(wholeThing,count+2);
    wholeThing[count]=hold;
    count++;
  }

  printf("Enter string to search for: ");
  scanf("%s",toSearch);
  start = clock();
  int hold2=bruteForce(wholeThing,toSearch);
  end=clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  if(hold2!=-1)
  {
    printf("String found at %d. %lf seconds\n",hold2,cpu_time_used);
  }
  else
  {
    printf("String not found. %lf seconds\n",cpu_time_used);
  }


  return 0;
}
