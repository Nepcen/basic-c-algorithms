/* **************************************************************************************** */
/*                                                                                          */
/*   JBB5    7BBJ   JBBBBBBBBB   GBBBBBBBP?        JG###B5!     JBBBBBBBBB   JBB5    7BBJ   */
/*   5@@@B!  J@@5   5@@GJJJJJJ   &@@YYYYP@@B     J&@#5JJG@@G    5@@GJJJJJJ   5@@@B!  J@@5   */
/*   5@@&@@J J@@5   5@@5         &@&     #@@!   ?@@B     5##7   5@@5         5@@&@@J J@@5   */
/*   5@@YJ@@5Y@@5   5@@&####&P   &@@####&@&Y    5@@!            5@@&####&P   5@@YJ@@5Y@@5   */
/*   5@@J 7#@@@@5   5@@J         &@&J????!      7@@B     5@@5   5@@J         5@@J 7#@@@@5   */
/*   5@@Y   G@@@5   5@@B55555P   &@&             ?#@&PY5B@@G    5@@B55555P   5@@Y   G@@@5   */
/*   ?GG7    YPG?   ?GPGGGGGGG   PP5               75GBBGY!     ?GPGGGGGGG   ?GG7    YPG?   */
/*                                                                                          */
/*   printCombN.c                                                                           */
/*                                                                                          */
/*   By: Nepcen <yusufabacik@gmail.com>                      Created: 03/01/2023 21:24:00   */
/*                                                                                          */
/* **************************************************************************************** */

#include <unistd.h>

int powerOf10(int i) {
    int result = 1;
    int j = 0;

    while (j < i) {
        result *= 10;
        j++;
    }
    
    return (result);
}
 
void putChar(char c) {
    write(1, &c, 1);
}

void putNumber(int nb) {
    if (nb > 9) {
        putNumber(nb / 10);
        putNumber(nb % 10);
    } else
        putChar(nb + '0');
}

int checkNumber(int nb) {
    char digits[10] = {0};

    while (nb > 0) {
        if (digits[nb % 10] == 1) return (0);
        digits[nb % 10] = 1;
        nb /= 10;
    }
    
    return (1);
}

void printCombN(int n) {
    int x;

    if (n <= 0) return;

    x = 0;
    while (x < powerOf10(n)) {
        if (checkNumber(x)) {
            if (x != 0) write(1, ", ", 2);
            putNumber(x);
        }
        x++;
    }
}

int main(void) {
    printCombN(2);
    return (0);
}