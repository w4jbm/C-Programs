#include <stdio.h>

/*
dump.c - print hex dump of a file

By Jim McClanahan W4JBM (Dec 2020), based on various
bits and pieces found around the web.
*/   

int main(int argc, char *argv[])
{
    FILE *fp;
    unsigned char buffer[16];
    int offset,r,x;

    /* Check for command line arguments and print help
       message if none are present */
    if( argc!=2 )
    {
        puts("Print hex dump (with ASCII) of a file");
        puts("Usage: dump filename");
        return(1);
    }

    /* Try to open the specified file, print error message
       if something goes wrong */
    fp = fopen(argv[1],"r");
    if( fp==NULL )
    {
        fprintf(stderr,"Unable to open file %s\n",argv[1]);
        return(1);
    }

    printf("______   0  1  2  3  4  5  6  7");
    printf("   8  9  A  B  C  D  E  F\n");
    /* Start marching through the fine and dumping in lines
       of 16 bytes until we reach the end of file */
    offset = 0;
    while( !feof(fp) )
    {
        r = fread(buffer,sizeof(unsigned char),16,fp);
        /* Break if we've hit the EOF */
        if( r==0 )
            break;
        /* Print where we are in the dump */
        printf("%06X ",offset);
        /* Print each byte in hex */
        for( x=0; x<r; x++ )
        {
            printf(" %02X",buffer[x]);
            if( x==7 )
                printf(" "); // Extra space after 8th byte
        }
        /* If we have less than 16 bytes to print on this
           row, fill in the blank spots with spaces */
        if( r<16 )
        {
            for( x=r; x<16; x++ )
            {
                printf("   ");
                if( x==7 )
                    printf(" "); // Extra space after 8th byte
            }
        }

        /* Print the ASCII codes for the dumped bytes */
        printf("  ");
        for( x=0; x<r; x++)
        {
            if( buffer[x]<32 || buffer[x]>126 )
                putchar('.');
            else
                putchar(buffer[x]);
        }
        putchar('\n');
        offset += r;
    }
    
/* If you want to print the number of bytes dumped, uncomment
   the following
   
    printf("Bytes Dumped: %d\n",offset);
*/

    /* close the file */
    fclose(fp);

    return(0);
}

