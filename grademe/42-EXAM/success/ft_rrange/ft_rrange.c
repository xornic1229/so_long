/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarci2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:50:54 by jagarci2          #+#    #+#             */
/*   Updated: 2025/03/07 20:51:00 by jagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int s;
	int *arr;

	if (start > end)
		s = start - end + 1;
	else
		s = end - start + 1;
	
	arr = malloc(sizeof(int) * s);
	if (!arr)
        return 0;
	int i = 0;
	
	if (start < end)
	{
		while (end >= start)
		{
			arr[i] = end;
			end--;
			i++;
		}
	}
	else
	{
		while (start >= end)
		{
			arr[i] = start;
			start--;
			i++;
		}
	}
	return arr;
}

/*
int main(int ac, char **av)
{
	if (ac == 3)
	{
		int start = atoi(av[1]);
		int end = atoi(av[2]);		
		int *arr = ft_rrange(start, end);
		int i = 0;
		int size;

		if (start > end)
			size = start - end + 1;
		else
			size = end - start + 1;
		

		while(i < size)
		{
			printf("%d\n", arr[i]);
			i++;;
			
		}
		free(arr);
	}
	else
		return write(1, "\n", 1);

}
*/
