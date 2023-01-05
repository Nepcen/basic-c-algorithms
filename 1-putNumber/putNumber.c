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
