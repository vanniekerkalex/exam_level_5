/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:07:07 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/26 21:33:08 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "check_mate.h"

int check_pawn(t_map *map)
{
	int y = map->y;
	int x = map->x;

	if (y + 1 < map->size - 1 && x - 1 >= 0)
		if (map->map[y + 1][x - 1] == 'P')
			return (1);
	if (y + 1 < map->size - 1 && x + 1 < map->size - 1)
		if (map->map[y + 1][x + 1] == 'P')
			return (1);
	return (0);
}

int check_rook(t_map *map)
{
	int i;
	i = 0;

	//while (i < map->size - 1)
	while (map->map[map->y][i])
	{
		if (map->map[map->y][i] == 'B' || map->map[map->y][i] == 'P')
			return (0);
		if (map->map[map->y][i] == 'R' || map->map[map->y][i++] == 'Q')
			return (1);
	}
	i = 0;
	while (i < map->size - 1)
	{
		if (map->map[i][map->x] == 'B' || map->map[i][map->x] == 'P')
			return (0);
		if (map->map[i][map->x] == 'R' || map->map[i++][map->x] == 'Q')
			return (1);
	}
	return(0);
}

int check_bishop(t_map *map)
{
	int i;
	int j;
	j = map->x;
	i = map->y;
	//while (i < map->size - 1 && j < map->size - 1)

	while (map->map[i] && map->map[i][j])
	{
		if (map->map[i][j] == 'R' || map->map[i][j] == 'P')
			return (0);
		if (map->map[i][j] == 'B' || map->map[i++][j++] == 'Q')
			return (1);
	}
	j = map->x;
	i = map->y;
	while (i < map->size - 1 && j >= 0)
	{
		if (map->map[i][j] == 'R' || map->map[i][j] == 'P')
			return (0);
		if (map->map[i][j] == 'B' || map->map[i++][j--] == 'Q')
			return (1);
	}
	j = map->x;
	i = map->y;
	while (j < map->size - 1 && i >= 0)
	{
		if (map->map[i][j] == 'R' || map->map[i][j] == 'P')
			return (0);
		if (map->map[i][j] == 'B' || map->map[i--][j++] == 'Q')
			return (1);
	}
	j = map->x;
	i = map->y;
	while (j >= 0 && i >= 0)
	{
		if (map->map[i][j] == 'R' || map->map[i][j] == 'P')
			return (0);
		if (map->map[i][j] == 'B' || map->map[i--][j--] == 'Q')
			return (1);
	}
	return(0);
}

void fill_map(t_map *map, char **argv)
{
	int i;
	int j;
	int size = map->size;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			map->map[i][j] = argv[i + 1][j];
			if (map->map[i][j] == 'K')
			{
				map->y = i;
				map->x = j;
			}
			j++;
		}
		map->map[i][j] = '\0';
		i++;
	}
	map->map[i] = NULL;
}

int main (int argc, char **argv)
{
	t_map *map;
	int i;

	map = (t_map *)malloc(sizeof(t_map));
	map->map = NULL;
	map->x = 0;
	map->y = 0;
	map->size = argc;

	i = 0;
	if (argc >= 2)
	{
		map->map = (char **)malloc(sizeof(char *) * (argc));
		while (i < argc)
			map->map[i++] = (char *)malloc(sizeof(char) * (argc));
		fill_map(map, argv);
		if (check_pawn(map) || check_rook(map) || check_bishop(map))
			write(1,"Success\n",8);
		else
			write(1, "Fail\n", 5);
	}
	else
		write(1, "\n", 1);
	return (0);
}
