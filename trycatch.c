#include <setjmp.h>
#include <stdio.h>

#define TRY                                                                    \
  jmp_buf __buf;                                                               \
  int __err = setjmp(__buf);                                                   \
  if (!__err)
#define CATCH else
#define THROW(exception) longjmp(__buf, exception)

typedef enum ExceptionType {
  ExampleException = 1,
  InvalidOperation,
} ExceptionType;

jmp_buf buf;

int main() {
  TRY {
    printf("nice!\n");
    THROW(InvalidOperation);
  }
  CATCH { printf("threw exception: %d\n", __err); }

  printf("we are here!\n");

  return 0;
}