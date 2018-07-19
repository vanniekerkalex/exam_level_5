/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 20:34:02 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/19 13:17:00 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{
	int i;
	int stack[4096];
	int count;
	int j;
	int error;

	i = 1;
	if (argc >= 2)
	{
		while (i <= argc - 1)
		{
			j = 0;
			count = 0;
			error = 0;
			while (argv[i][j])
			{
				if (argv[i][j] == '(' || argv[i][j] == '[' || argv[i][j] == '{')
					stack[count++] = argv[i][j];
				if (argv[i][j] == ')' && stack[count-- - 1] != '(')
					error = 1;
				if (argv[i][j] == ']' && stack[count-- - 1] != '[')
					error = 1;
				if (argv[i][j] == '}' && stack[count-- - 1] != '{')
					error = 1;
				j++;
			}
			if (error == 0 && count == 0)
				write(1, "OK\n", 3);
			else
				write(1, "Error\n", 6);
			i++;
		}
	}
	else
		write(1,"\n",1);
	return (0);
}
