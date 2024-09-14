#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(Value) ({ \
    int temp = (Value); \
    if (temp < 0) \
        temp = -temp; \
    temp; \
})

#endif
