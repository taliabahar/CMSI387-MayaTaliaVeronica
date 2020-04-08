#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

// run using ./a.out < /etc/passwd
int main()
{
  pid_t returnedValue = fork();
  if (returnedValue < 0)
  {
    perror("error forking");
    return -1;
  }
  else if (returnedValue == 0)
  {
    execlp("tr", "tr", "a-z", "A-Z", NULL);
    return -1;
  }
  else
  {
    if (waitpid(returnedValue, 0, 0) < 0)
    {
      perror("error waiting for child");
      return -1;
    };
  }
}
