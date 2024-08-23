int max(int *tab, unsigned int len)
{
    if (len == 0)
    {
        return 0;
    }

    int max = tab[0];
    for (int i = 1; i < len; i++)
    {
        if (max < tab[i])
        {
            max = tab[i];
        }
    }
    return max;
}
