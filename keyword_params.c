#include <stdio.h>

#define myfn(...)                                                              \
  _myfn((myfn_args){__VA_ARGS__}) // works by casting the args to a struct!

typedef struct myfn_args {
  int arg1;
  char *arg2;
} myfn_args;

void _myfn(myfn_args args) {
  printf("arg1: %d\n", args.arg1);
  printf("arg2: %s\n", args.arg2);
}

int main() {
  myfn(.arg1 = 1, .arg2 = "hello");

  return 0;
}