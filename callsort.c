/* callsort.c - call *nix sort command to sort a file

   by Jim McClanahan W4JBM (Dec 2020)

   Meant to be a simple demo of how to call a Linux command
   from inside a C program.
   
   The output only goes to the console--if you really want
   to do something useful you'd probably have to do some
   tweaking.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc!=2) { // if no filename, print a help message
        puts("Call *nix sort from a C program");
        puts("Usage: sort filename");
        return(1);
    }

    int length=5+strlen(argv[1])+1; // room for "sort " + filename
    char *command=(char *) calloc(length, sizeof(char));
    sprintf(command, "sort %s", argv[1]);

    int ret=system(command);

    return(ret);
}
