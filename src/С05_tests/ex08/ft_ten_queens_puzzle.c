#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_solution(int *board)
{
	int i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(board[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

int	is_safe(int *board, int col, int row)
{
	int i;

	i = 0;
	while (i < col)
	{
		// Check if queens are in the same row or on the same diagonal
		if (board[i] == row || (col - i) == (board[i] - row) || (col - i) == (row - board[i]))
			return (0);
		i++;
	}
	return (1);
}

void	solve(int *board, int col, int *count)
{
	int row;

	if (col == 10)
	{
		print_solution(board);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (is_safe(board, col, row))
		{
			board[col] = row;
			solve(board, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	solve(board, 0, &count);
	return (count);
}

#include <stdio.h>

int ft_ten_queens_puzzle(void);

int main(void)
{
    // Call ft_ten_queens_puzzle to display all solutions and get the total count
    int total_solutions = ft_ten_queens_puzzle();

    // Print the total number of solutions found
    printf("Total solutions found: %d\n", total_solutions);

    // Test cases:
    if (total_solutions == 724)
    {
        printf("Test Passed: The total number of solutions is correct.\n");
    }
    else
    {
        printf("Test Failed: Expected 724 solutions, but found %d.\n", total_solutions);
    }

    return 0;
}
