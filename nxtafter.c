/* nxtafter.c - Tinker with the nextafter() function...
*
* Compile using:
*   $ gcc nxtafter.c -lm -o nxtafter
*
* Based on info found here:
*   https://c-for-dummies.com/blog/?p=3695#more-3695
*/

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <fenv.h>

#define NDIG "50" // number of digits to display



int nxtaftr(double x)
{
    printf("The nextafter %e is:\n",x);
    printf("  Down = %."NDIG"lf\n",nextafter(x,x-1.0));
    printf("         or %e\n",nextafter(x,x-1.0));
    printf("  Up   = %."NDIG"lf\n",nextafter(x,x+1.0));
    printf("         or %e\n",nextafter(x,x+1.0));
    return(0);
}



int main()
{
    double f;

    printf("This program demonstrates the nextafter() function in C...\n\n");
    
    printf("Size of double is %zu bytes.\n\n", sizeof(f));
  
    f = -100.0;
    nxtaftr(f);

    printf("\n");

    f = 0.0;
    nxtaftr(f);

    printf("\n");

    f = 100.0;
    nxtaftr(f);

    return(0);
}
