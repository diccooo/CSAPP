#include "csapp.h"

int main()
{
  int fd;
  fd = Open("hello.txt", O_RDWR, 0);
  char *str;
  str = Mmap(0, 1, PROT_WRITE, MAP_SHARED, fd, 0);
  (*str) = 'J';
  Munmap(str, 1);
  Close(fd);
  return 0;
}
