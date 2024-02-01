#include <bits/types/struct_iovec.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <PID> <TARGET_ADDRESS>\n", argv[0]);
    exit(1);
  }

  // Setup local memory to be injected into the remote
  char *x = "aaaa";
  struct iovec local[1];
  local[0].iov_base = x;
  local[0].iov_len = 4;

  // Define remote target
  struct iovec remote[1];
  remote[0].iov_base = (void *)strtol(argv[2], NULL, 16);
  remote[0].iov_len = 4;

  // Write into remote process memory
  int pid = atoi(argv[1]);
  int ret = process_vm_writev(pid, local, 1, remote, 1, 0);
  if (ret == -1) {
    perror("write");
    exit(1);
  }
  return 0;
}
