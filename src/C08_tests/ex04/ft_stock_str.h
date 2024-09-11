#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

// Definition of the structure t_stock_str
typedef struct s_stock_str
{
    int size;    // Length of the string
    char *str;   // Original string
    char *copy;  // Copy of the string
} t_stock_str;

#endif
