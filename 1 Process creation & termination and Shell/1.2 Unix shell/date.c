#define _GNU_SOURCE /* for tm_gmtoff and tm_zone */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void date_u() {
  time_t t = time(NULL);
  struct tm tm = *gmtime(&t);

  char* date = asctime(&tm);
  int yearIndex = -1;
  int index = 0;
  while (date[index] != '\0') {
      if (date[index] == ' ') yearIndex = index;
      index++;
  }
  
  int len = strlen(date) - yearIndex - 1;
  char year[len + 1];
  
  char date_1[yearIndex+1];
  index = 0;
  while (index < len) {
      year[index] = date[yearIndex+index+1];
      index++;
  }
  year[index] = '\0';

  index = 0;
  while (index < yearIndex) {
      date_1[index] = date[index];
      index++;
  }
  date_1[index] = '\0';
  printf("%s UTC %s\n", date_1, year);
  
  exit(0);
}

void date_r(char* file) {
  struct stat sb;
  int check = stat(file, &sb);
  if (check == -1) {
    printf("Error");
    return;
  }

  // printf("%s", ctime(&sb.st_mtime));

  char* date = ctime(&sb.st_mtime);
  int yearIndex = -1;
  int index = 0;
  while (date[index] != '\0') {
      if (date[index] == ' ') yearIndex = index;
      index++;
  }
  
  int len = strlen(date) - yearIndex - 1;
  char year[len + 1];
  
  char date_1[yearIndex+1];
  index = 0;
  while (index < len) {
      year[index] = date[yearIndex+index+1];
      index++;
  }
  year[index] = '\0';

  index = 0;
  while (index < yearIndex) {
      date_1[index] = date[index];
      index++;
  }
  date_1[index] = '\0';

  time_t t = time(NULL);
  struct tm lt = {0};

  localtime_r(&t, &lt);
  printf("%s %s %s", date_1, lt.tm_zone, year);
  exit(0);

}

int main(int argc, char *argv[])
{
  if (strcmp(argv[0], "-u\n") == 0) {
      date_u();
  }
  
  else if (strcmp(argv[0], "-r") == 0) {
      date_r(argv[1]);
  }
  else {
      printf("date: bad option %s", argv[0]);
  }
  exit(0);
  return 0;
}
