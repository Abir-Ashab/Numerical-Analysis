#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 200
#define F(x)  ((x)*(x)*(x) + 4*(x)*(x) - 10)
#define f(x)  (3*(x)*(x) + 8*(x))
//   "(3*(x)*(x) + 8*(x))" er jaygay "3*(x)*(x) + 8*(x)" dile wrong ashbe
//    open bracket is must

int main (void) {
  int i = 1;
  double tol = 1.0e-5;
  double x0 = 1.5;
  printf("-  -  -  -  -  -  -  -  -  -  -  - - - - - - \n");
  printf("i     x0         x1         f(x0)       f(x1)\n");
  printf("-  -  -  -  -  -  -  -  -  -  -  - - -  - - -\n");

  while(i < MAXN) {
    printf("%d   %lf   ",i, x0);
    double x1 = x0 - F(x0)/f(x0);
    printf("%lf   %lf     %lf\n", x1, f(x0), F(x1));
    if (fabs(F(x1)) <= tol ) {
      printf("Root = %lf, Itr = %d\n", x1, i);
      return 1;
    }
    x0 = x1;
    i++;
  }
  printf("Itr Overflow ...\n");
  return 0;
}
