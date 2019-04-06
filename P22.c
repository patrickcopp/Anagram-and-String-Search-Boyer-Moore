#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void shiftTheTable(char *toSearch,int shiftTable[52]);
int horspools(char * wholeThing, char* toSearch);

void shiftTheTable(char *toSearch,int shiftTable[52])
{
  for(int i=0;i<52;i++)
  {
    shiftTable[i]=strlen(toSearch);
  }

  for(int i=0;i<strlen(toSearch)-1;i++)
  {
    if(toSearch[i]>90)
    {
      shiftTable[toSearch[i]-71]=strlen(toSearch)-1-i;
    }
    else
    {
      shiftTable[toSearch[i]-65]=strlen(toSearch)-1-i;
    }
  }

}

int horspools(char * wholeThing, char* toSearch)
{
  int shiftTable[52];
  shiftTheTable(toSearch,shiftTable);
  int i=strlen(toSearch)-1;

  while(i<=strlen(wholeThing)-1)
  {
    int k=0;
    while(k<=strlen(toSearch)-1 && toSearch[strlen(toSearch)-1-k]==wholeThing[i-k])
    {
      k=k+1;
    }
    if(k==strlen(toSearch))
    {
      return i-strlen(toSearch)+1;
    }
    else
    {
      if(wholeThing[i]<65 || wholeThing[i]>122 || (wholeThing[i]<97 && wholeThing[i]>90))
      {
        i+=strlen(toSearch);
      }
      else if(wholeThing[i]>90)
      {
        i=i+shiftTable[wholeThing[i]-71];
      }
      else
      {
        i=i+shiftTable[wholeThing[i]-65];
      }
    }
  }

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
  int hi=horspools(wholeThing,toSearch);
  end=clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  if(hi!=-1)
  {
    printf("String found at %d. %lf seconds\n",hi,cpu_time_used);
  }
  else
  {
    printf("String not found. %lf seconds\n",cpu_time_used);
  }



  printf("Horspools: %d\n",hi);

  return 0;
}
