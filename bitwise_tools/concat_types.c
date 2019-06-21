/*
** EPITECH PROJECT, 2019
** bitwise tools
** File description:
** Contains functions used to concat types
*/

#include <unistd.h>

unsigned long uint_to_ulong(unsigned int left, unsigned int right, int muted)
{
    unsigned long i = 0x0000000000000000;

    if (sizeof(int) != 4 && muted != 1) {
        write(STDERR_FILENO, "Error: this function can only be used"
            " on 32-bit or 64-bit architecture.\n", 72);
        return (84);
    }
    i |= (unsigned long)right;
    i |= (unsigned long)left << 4 * 8;
    return (i);
}
