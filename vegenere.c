#
# cs50/pset2/vegenere.c
#

#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, string argv[]) {

    string k;
    if (argc != 2) {
        printf("Usage: vigenere token\n");
        return 1;
    } else {
        k = argv[1];
        //printf ("Token: %c\n", k[0]);
        printf("plaintext: ");
    }

    int i, n;
    n = strlen(k);
    int token[100];

    for (i=0;i<n;i++) {
        if (k[i] > 64 && k[i] < 91) {
            token[i]=k[i]-65;
            //printf("Token1: %d\n", token[i]);
        } else if (k[i] > 96 && k[i] < 123) {
            token[i]=k[i]-97;
            //printf("Token2: %d\n", token[i]);
        } else {
            //token[i] = token[i-1];
            printf("Invalid code: \n");
            return 1;
        }
    }

    char ch;
    int input_string[200], output_string[200];

        i = 0;
        int new_i = 0;
        int token_i = 0;

        while ((ch = getchar()) != '\n' && ch != EOF) {

            input_string[i] = ch;

                //printf("Num1: %d\n", (ch+token[i%n]) );
                if (ch > 64 && ch < 91) {
                    output_string[i] = ((ch+token[new_i%n]-65)%26) + 65;
                    //printf("Char: %c, Num2: %d\n", output_string[i], ((ch+token[new_i%n]-65)%26) + 65 );
                    new_i++;
                    i++;
                } else if (ch > 96 && ch < 123) {
                    output_string[i] = ((ch+token[new_i%n]-97)%26) + 97;
                    //printf(" %d %d Key: %d, Char: %c, Num2: %d\n", new_i, new_i%n, token[new_i%n], output_string[i], ((ch+token[i%n]-97)%26) + 97 );
                    new_i++;
                    i++;
                } else {
                    output_string[i] = ch;
                    i++;
                }

            //putchar('\n');
            //printf("Char: %c, Num2: %d\n", output_string[i], ((ch+token[i%n]-97)%26) + 97 );
            //i++;

        } //while

    printf("ciphertext: ");

    int j = 0;
    for (j = 0; j < i; j++) {
        putchar(output_string[j]);
    }

putchar('\n');


}
