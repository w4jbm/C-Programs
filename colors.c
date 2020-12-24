/* Test and Demo of the use of ANSI codes to change
   the color and other attributes of characters printed
   to the terminal.
*/

#include <stdio.h>

/* Define the various ANSI Color Codes */
#define RED "\033[31m"
#define GRN "\033[32m"
#define YEL "\033[33m"
#define BLU "\033[34m"
#define MAG "\033[35m"
#define CYN "\033[36m"
#define WHT "\033[37m"

/* Define ANSI effects */
#define BLD "\033[1m"
#define RVS "\033[7m"

/* Define ANSU clear screen */
#define CLS "\033[H\033[J"  // Clear Screen and Home Cursor
#define CLN "\033[K"   // Clear to End of Line

/* This string resets things back to normal */
#define RST "\033[0m"

int main() {
    printf(CLS);
    
    printf(RED "Red\n"     RST);
    printf(GRN "Green\n"   RST);
    printf(YEL "Yellow\n"  RST);
    printf(BLU "Blue\n"    RST);
    printf(MAG "Magenta\n" RST);
    printf(CYN "Cyan\n"    RST);
    printf(WHT "White\n"   RST);

    printf("\n");

    printf(GRN BLD "Bold Green\n" RST);
    printf(GRN RVS "Reverse Green\n" RST);

    return 0;
}
