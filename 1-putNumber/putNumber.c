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
/*   putNumber.c                                                                            */
/*                                                                                          */
/*   By: Nepcen <yusufabacik@gmail.com>                      Created: 01/01/2023 20:11:03   */
/*                                                                                          */
/* **************************************************************************************** */

#include <unistd.h>

void putChar(char c) {
    write(1, &c, 1);
}

void putNumbers(int nb) {
    if (nb == -2147483648)
        write(1, "-2147483648", 11);
    else if (nb < 0) {
        putChar('-');
        nb = -nb;
        putNumbers(nb);
    } else if (nb > 9) {
        putNumbers(nb / 10);
        putNumbers(nb % 10);
    } else
        putChar(nb + 48);
}

int main(void) {
    putNumbers(42);
    return (0);
}
