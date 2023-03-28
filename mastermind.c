#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int main(){

    // initialize variables that we need
    char colors[5] = {'R', 'B', 'Y', 'O', 'G'};
    char secretCode[4] = {'R', 'B', 'Y', 'O'};
    char playerInput[4];
    int colorRightPlace = 0, colorWrongPlace = 0, maxTry = 3, try = 0;

    for (int try = 1; try <= maxTry; try++) {

        if (try <= maxTry) {
            // take player input and add it to playerInput
            printf("\n\nYou have %d try left." , (maxTry+1) - try);
            printf("\nPlease enter your secret code (4 colors) between R, B, Y, O and G :");
            fflush(stdin);
            scanf("%c%c%c%c", playerInput, (playerInput + 1), (playerInput + 2), (playerInput + 3));
            
            // comparing playerInput placement and secretCode placement
            for (int i = 0; i < 4; i++) {
                if (secretCode[i] == playerInput[i]) {
                    colorRightPlace++;
                    colorWrongPlace--;
                }
                // check if color wrong place
                for (int j = 0 ; j < 4; j++) {
                    if (secretCode[j] == playerInput[i]) {
                        colorWrongPlace++;
                    }
                }
            }

            if (colorRightPlace == 4) {
                printf("\nYou won! GG!\n\n");
                break;
            }

        }

        printf("\nResult :\nColor at right place: %d\nColor at wrong place: %d", colorRightPlace, colorWrongPlace);
        
        if (try == maxTry) {
            printf("\nYou don't have any try left !\n");
        }
    }
    
    return 0;
}