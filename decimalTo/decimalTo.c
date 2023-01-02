#include <unistd.h>

int strLen(char * str) {
    int a;

    a = 0;
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
            write(1, & base[l_nbr], 1);
    }
}

int main(void) {
    decimalTo(1903, "0123456789ABCDEF");
    return (0);
}