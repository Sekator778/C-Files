#include "ft_list.h"
#include <stdio.h>

int	ft_list_size(t_list *begin_list)
{
    int size = 0;
    t_list *current = begin_list;

    while (current)
    {
        size++;
        current = current->next;
    }
    return size;
}

int main(void)
{
    t_list node3 = {NULL, "data3"};
    t_list node2 = {&node3, "data2"};
    t_list node1 = {&node2, "data1"};

    int size = ft_list_size(&node1);
    printf("List size: %d\n", size);

    return 0;
}
