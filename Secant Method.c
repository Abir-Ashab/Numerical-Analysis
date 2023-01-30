#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 200
#define F(x)  ( (x)*(x)*(x) + 4*(x)*(x) - 10)

int main () {
  int i;
  double x1 = 1.5, x2 = 2, x3, tol = 1.0e-5, c;
  double fx1, fx2, fx3;

  for (i=1; i< MAXN; i++) {
    fx1 = F(x1);   fx2 = F(x2);
    x3 = x2 - fx2*(x2 - x1)/(fx2 - fx1);
    fx3 = F(x3);
    if (fabs(fx3) <= tol ) {
      printf("Root = %lf, Itr = %d\n", x3,i );
      return 1;
    }
    x1 = x2; x2 = x3;
  }
  printf("Itr Overflow ...\n");
  return 0;
}
