#include <stdio.h>
#include <stdint.h>

char buffer[2];
uint64_t d=0,K=0,s=0;
int main() {
  scanf("%d%d", &d, &K);
  while (scanf("%s", buffer) > 0) {
    scanf("%d", &d);
    K = *buffer=='+' ? K+d : K<d ? s++,K : K-d;
  }
  printf("%I64d %d\n", K, s);
}