#include <stdio.h>
#include <unistd.h>

int main() {
  int x = 10;
  int process_pid = getpid();
  while (1) {
    printf("[%d]: %p -> %d\n", process_pid, &x, x);
    sleep(1);
  }
}
