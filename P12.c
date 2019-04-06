#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int preSort(char a[], char *b[]);
char *sortString(char * toSort);
static int Compare(const void* a, const void* b);


int preSort(char hold[],char *values[])
{
  int count=0;

  for(int i=0;i<30000;i++)
  {
    values[i]=sortString(values[i]);
  }
  hold=sortString(hold);
  qsort(values,30000,sizeof(char*),Compare);

  for(int i2=0;i2<30000;i2++)
  {
    if(strcmp(hold,values[i2])==0)
    {
      count++;
    }
  }

  return count;
}

char *sortString(char * toSort)
{
  int first[10] = {0}, c=0,c2=0;
  while (toSort[c] != '\0')
  {
    first[toSort[c]-'0']++; //counts how many of each number
    c++;
  }


  char *toReturn=malloc(20);
  int count=0;
  for (c = 0; c < 10; c++)
  {
    for (c2 = 0; c2 < first[c]; c2++)
    {
      toReturn[count]=c+48;
      count++;
    }
  }
  toReturn[count]='\0';
  return toReturn;
}

static int Compare(const void* a, const void* b)
{
  return strcmp(*(const char**)a, *(const char**)b);
}

int main()
{
  FILE *fp=fopen("data_4.txt","r");
  char *values [60000];
  char buffer[100];
  char *hold=malloc(200);
  int count=0;
  clock_t start, end;
  double cpu_time_used;
  for(int i=0;i<60000;i++)
  {
    
    values[i]=malloc(25);
  }
  int count2=0;
  while(fgets(buffer,100,fp))
  {
    hold=strtok(buffer," ");
    strcpy(values[count],hold);
    count++;
    hold=strtok(NULL," ");
    strcpy(values[count],hold);
    count++;
    hold=strtok(NULL," ");
    strcpy(values[count],hold);
    count++;
    hold=strtok(NULL," ");
    strcpy(values[count],hold);
    count++;
    hold=strtok(NULL," ");
    strcpy(values[count],hold);
    count++;
    count2++;
  }

  printf("Enter a string: ");
  scanf("%s",hold);

  start = clock();
  int hi=preSort(hold,values);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Presorting: %d\n%lf seconds\n",hi,cpu_time_used);

  return 0;
}
