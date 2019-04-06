#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define max(a, b) ((a < b) ? b : a)


void shiftTheTable2(int* shiftTable2,char *toSearch,int toSearchLen);
int suffixLength(char *word, int wordlen, int pos);
int prefix(char *word, int wordlen, int pos);
int boyerMoore(char * wholeThing, char* toSearch);
void shiftTheTable(char *toSearch,int shiftTable[52]);

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

int boyerMoore(char * wholeThing, char* toSearch)
{
  int shiftTable[52];
  int *shiftTable2=malloc(sizeof(int)*strlen(toSearch));
  shiftTheTable(toSearch,shiftTable);
  shiftTheTable2(shiftTable2,toSearch,strlen(toSearch));
  int shifts=0,charsCompared=0;
  int i=strlen(toSearch)-1;
  while(i<strlen(wholeThing))
  {
    int j=strlen(toSearch)-1;
    while(j>=0 && (wholeThing[i]==toSearch[j]))
    {
      --i;
      --j;
      charsCompared++;
    }
    if(j<0)
    {
      printf("Number of shifts: %d\n",shifts);
      return i+1;
    }
    charsCompared++;

    i+=max(shiftTable[i],shiftTable2[j]);

  }
  return -1;
}

int prefix(char *word, int wordlen, int pos)
{
    int i;
    int suffixLen=wordlen-pos;

    for (i=0; i < suffixLen; i++)
    {
        if (word[i] != word[pos+i])
        {
            return 0;
        }
    }
    return 1;
}

int suffixLength(char *word, int wordlen, int pos)
{
    int i;
    for (i = 0; (word[pos-i] == word[wordlen-1-i]) && (i < pos); i++);
    return i;
}

void shiftTheTable2(int *shiftTable2,char *toSearch,int toSearchLen)
{
  int lastIndex=1;
  for(int i=toSearchLen-1;i>-1;i--)
  {
    if(prefix(toSearch,toSearchLen,i+1))
    {
      lastIndex=i+1;
    }
    shiftTable2[i]=toSearchLen-1-i+lastIndex;
  }

  for(int i=0;i<toSearchLen-1;i++)
  {
    int len=suffixLength(toSearch,toSearchLen,i);
    if(toSearch[i-len]!=toSearch[toSearchLen-1-len])
    {
      shiftTable2[toSearchLen-1-len]=toSearchLen-1-i+len;
    }
  }

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
  int hi=boyerMoore(wholeThing,toSearch);
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



  return 0;
}
