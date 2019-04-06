#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int checkAnagram(char a[], char b[]);

int checkAnagram(char a[], char b[])
{
  int first[10] = {0}, second[10] = {0}, c=0; //arrays for each number

  while (a[c] != '\0')
  {
    first[a[c]-'0']++; //counts how many of each number
    c++;
  }

  c = 0;

  while (b[c] != '\0')
  {
    second[b[c]-'0']++;
    c++;
  }

  for (c = 0; c < 10; c++)
  {
    if (first[c] != second[c])
      return 0;
  }

  return 1;
}


int main()
{
  FILE *fp=fopen("data_4.txt","r");
  char *values [60000];
  char buffer[100];
  char *hold=malloc(200);
  int count=0;
  clock_t start, end;

  for(int i=0;i<60000;i++)
  {
    values[i]=malloc(25);
  }

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
  }

  printf("Enter a string: ");
  scanf("%s",hold);

  start = clock();
  int total=0;
  for(int i=0;i<30000;i++)
  {
    total+=checkAnagram(hold,values[i]);
  }

  end = clock();
  double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Brute Force: %d \n%lf seconds\n",total,cpu_time_used);

  return 0;
}
