/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:56:56 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/24 17:16:48 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	validate_char(t_game *g, char c, t_counts *counters, t_pos pos)
{
	if (!ft_strchr(VALID_CHARS, c))
	{
		counters->players = -1;
		return ;
	}
	if (c == 'P')
	{
		counters->players++;
		g->player_x = pos.x;
		g->player_y = pos.y;
	}
	else if (c == 'E')
		counters->exits++;
	else if (c == 'C')
		g->collectibles++;
}
