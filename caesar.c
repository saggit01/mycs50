#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//#define NULL 0

int main(int argc, string argv[]) {
int ch;
int input_string[150];
int output_string[150];

if (argc != 2) {
   printf ("Args not right..\n");
   return 1;
}

int k = atoi(argv[1]);

if (k < 0) {
   printf("K value less than 0\n");
} else {
   printf("K value: %d\n", k);
}

//printf("ciphertext: ");

int i = 0;
while ((ch = getchar()) != '\n' && ch != EOF) {


    input_string[i] = ch;
    //printf("Num1: %d\n", (ch+k) );
    if (ch > 64 && ch < 91) {
       output_string[i] = ((ch+k-65)%26) + 65;
    } else if (ch > 96 && ch < 123) {
       output_string[i] = ((ch+k-97)%26) + 97;
    } else {
       output_string[i] = ch;
    }
    //putchar('\n');
    //printf("Num2: %d\n", ((ch+k)%(ch+26)) );
    i++;
}

printf("ciphertext: ");

int j = 0;
for (j = 0; j < i; j++) {
   putchar(output_string[j]);
}

putchar('\n');
return 0;
}
