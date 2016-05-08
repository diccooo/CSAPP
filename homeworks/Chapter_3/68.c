#include <stdio.h>
#define BufferSize 50

void good_echo()
{
  char s[BufferSize];
  int i;
  while(fgets(s, BufferSize, stdin)){
    for(i = 0; s[i]; i++){
      putchar(s[i]);
    }
    if(i < BufferSize - 1){
      break;
    }
  }
}

int main()
{
  good_echo();
}
