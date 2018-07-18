/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 20:19:00 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/18 20:33:33 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	cycle_detector(const t_list *list)
{
	t_list *l1 = (t_list *)list;
	t_list *l2 = (t_list *)list;

	while (l1 && l2 && l2->next)
	{
		l1 = l1->next;
		l2 = l2->next->next;
		if (l1 == l2)
			return (1);
	}
	return (0);
}
