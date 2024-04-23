/*
** EPITECH PROJECT, 2024
** src/rand/rand
** File description:
** randomness
*/

static unsigned int lvi_seed_access(unsigned int seed, char mode)
{
    static unsigned int lvi_seed = 0;

    if (mode)
        lvi_seed = seed;
    return lvi_seed;
}

int lv_rand(void)
{
    unsigned int seed = lvi_seed_access(0, 0);

    seed = ((seed * 1103515245U) + 12345U) & 0x7fffffff;
    seed >>= 1;
    lvi_seed_access(seed, 1);
    return seed;
}

void lv_srand(unsigned int seed)
{
    static int seed_s = 0;

    seed_s = seed;
    lvi_seed_access(seed, 1);
}
