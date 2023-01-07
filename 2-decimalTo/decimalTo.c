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
/*   decimalTo.c                                                                            */
/*                                                                                          */
/*   By: Nepcen <yusufabacik@gmail.com>                      Created: 02/01/2023 15:48:29   */
/*                                                                                          */
/* **************************************************************************************** */

#include <unistd.h>

int strLen(char * str) {
    int a = 0;

    while (str[a] != '\0')
        a++;

    return (a);
}

int checkBase(char * str) {
    int i;
    int j;

    if (! * str || strLen(str) == 1)
        return (0);

    i = 0;
    while (str[i] != '\0') {
        j = i + 1;
        while (str[j] != '\0') {
            if (str[i] == str[j] || str[i] == '+' || str[i] == '-' || str[i] <= 32 || str[i] == 127)
                return (0);
            j++;
        }
        i++;
    }
    
    return (1);
}

void decimalTo(int nbr, char * base) {
    int base_len;
    long l_nbr;

    l_nbr = nbr;
    if (checkBase(base)) {
        base_len = strlen(base);
        if (l_nbr < 0) {
            write(1, "-", 1);
            l_nbr = -l_nbr;
        }
        if (l_nbr > base_len - 1) {
            decimalTo(l_nbr / base_len, base);
            decimalTo(l_nbr % base_len, base);
        } else
            write(1, &base[l_nbr], 1);
    }
}

int main(void) {
    decimalTo(1903, "0123456789ABCDEF");
    return (0);
}
