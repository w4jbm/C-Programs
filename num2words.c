/* num2words.c - Convert number to words...
*
* Tweaked by Jim McClanahan W4JBM (Jan 2021)
*
* Actually more useful than might be obvious... Originally I wrote
* one of these as part of a check printing program running in BASIC
* on an OSI Challenger system back in the 1980s. This one started
* with code found here:
*
* https://c-for-dummies.com/blog/?p=4342
*
* I added handling up to 1,000 (was previously up to 100), taking
* an argument from the command line, and printing a series of 15
* examples starting at a random number when no argument was provided.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFSZ 32 // string buffer size (777 seems to take the most)

/* return string representing integers 0 through 1000 */

char *verbal(int n)
{
    char *ones[10] = { "one", "two", "three", "four",
                       "five", "six", "seven", "eight",
                       "nine", "ten" };
    char *teens[9] = { "eleven", "twelve", "thirteen",
                       "fourteen", "fifteen", "sixteen",
                       "seventeen", "eighteen", "nineteen" };
    char *tens[8] = { "twenty", "thirty", "forty",
                      "fifty", "sixty", "seventy",
                      "eighty", "ninety" };
    char *hundreds[9] = { "one", "two", "three", "four",
                       "five", "six", "seven", "eight",
                       "nine" };
    int hns,dec,tns,uns;
    static char buffer[BUFSZ];

    if( n==0 ) // handle zero as a special case...
        return("zero");
    if( n==1000) // as well as one thousand...
        return("one-thousand");

    if( n<11 ) // for number 1 thru 10...
        return(ones[n-1]);
    if( n<20 ) // and thru 19...
        return(teens[n-11]);

    if( (n % 100) == 0 ) { // if the number ends in '00'...
        snprintf(buffer,BUFSZ,"%s-hundred", hundreds[(n/100) - 1]);
        return(buffer);}

    // handle everything else...
    hns = (n / 100) - 1; //hundreds
    tns = (n % 100) - 10; //teens
    dec = ((n % 100) - 20) / 10; //decades
    uns = (n - 20) % 10 - 1; //unity
//  printf("%d\n",hns); //for troubleshooting if needed...
    if((n<100) && (uns < 0) ) //for multiples of ten...
        return(tens[dec]);
    if( n<100 ) { //for 20 through 99...
        snprintf(buffer,BUFSZ,"%s-%s",tens[dec],ones[uns]);
        return(buffer);}
    if ((n%100) < 10) { // up to 999... (with a zero in the middle)
        snprintf(buffer,BUFSZ,"%s-hundred and %s", hundreds[hns],ones[uns]);
        return(buffer);}
    if ((n%100) == 10) { // up to 999... (with a ten at the end)
        snprintf(buffer,BUFSZ,"%s-hundred and %s", hundreds[hns],ones[9]);
        return(buffer);}
    if ((n % 100) < 20) { // (with teens at the end)
        snprintf(buffer,BUFSZ,"%s-hundred and %s", hundreds[hns],teens[(n % 100)-11]);
        return(buffer);}
    if ((n % 10) == 0) { // (with zero at the end)
        snprintf(buffer,BUFSZ,"%s-hundred and %s", hundreds[hns],tens[dec]);
        return(buffer);}
    // (and finally anything that wasn't a 'special case')
    snprintf(buffer,BUFSZ,"%s-hundred and %s-%s",hundreds[hns],tens[dec],ones[uns]);
    return(buffer);
}


int main(int argc, char *argv[]) {
    
    int x,ranx;
    time_t t;
    
    if(argc<=1) {
        printf("You can enter an integer on the command line.\nOtherwise we will loop through some examples...\n\n");
        // random number in range: num = (rand() % (upper – lower + 1)) + lower
        srand(time(0));
        ranx = rand() % 986;
        for(x=ranx; x<=ranx+14; x++) {
            printf("%d is %s\n",x,verbal(x)); }
        return(0);
     }
     
     x = atoi(argv[1]); //argv[0] is program name and argv[1] is hopefully a number
                        //atoi = ascii to int

     if ((x<0) || (x>1000)) {
     printf("I can only handle numbers between zero and one-thousand...\n");
     return(1);}
     
     printf("%s\n",verbal(x));

     return(0);
}
