/*
** EPITECH PROJECT, 2019
** bitwise tools
** File description:
** Contains functions used to split types
*/

#include <unistd.h>

int split_ulong_to_uint(unsigned long to_split,
    unsigned int *left, unsigned int *right, int muted)
{
    if (sizeof(int) != 4 && muted != 1) {
        write(STDERR_FILENO, "Error: this function can only be used"
            " on 32-bit or 64-bit architecture.\n", 72);
        return (84);
    }
    *left |= (int)(to_split >> 4 * 8);
    *right |= (int)(to_split);
    return (0);
}
