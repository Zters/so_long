/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyanar <tyanar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:18:49 by saksoy            #+#    #+#             */
/*   Updated: 2022/06/28 16:47:30 by tyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minlbx.h"

int	str_len(char *str) 
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	player_control(t_win *pnc)// oyunda bir tane mi karakter var diye kontrol ediyor karakter kontrolü
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pnc->map->mappin[i])
	{
		while (pnc->map->mappin[i][j])
		{
			if (pnc->map->mappin[i][j] == 'P')
			{
				pnc->map->p_cnt += 1;
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (pnc->map->p_cnt != 1)
	{
		write(1, "Player Count Error", 19);
		close_frame(pnc);
	}
}

void	wall_control(t_win *pnc)// mapin duvarlarla kaplı olup olmadıgını kontrol ediyor 
{
	int	i;
	int	last;

	i = -1;
	while (pnc->map->mappin[0][++i])
	{
		if (pnc->map->mappin[0][i] != '1' ||
			pnc->map->mappin[pnc->map->h - 1][i] != '1')
		{
			write(1, "Wall Error", 11);
			close_frame(pnc);
		}
	}
	i = -1;
	last = pnc->map->w - 1;
	while (pnc->map->mappin[++i])
	{
		if (pnc->map->mappin[i][0] != '1' || pnc->map->mappin[i][last] != '1')
		{
			write(1, "Wall Error", 11);
			close_frame(pnc);
		}
	}
}

void	map_size_control(t_win *pnc)// mapin her satırı aynı uzunlukta mı diye kontrol ediyor 
{
	int	i;
	int	len;

	i = 0;
	len = pnc->map->w;
	while (pnc->map->mappin[i])
	{
		if (str_len(pnc->map->mappin[i]) != len)
		{
			write(1, "Line Size Error", 16);
			close_frame(pnc);
		}
		i++;
	}
}

void	end_control(t_win *pnc)// en az bir tane cıkıs kapısı olması gerektigini kontrol ediyor 
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (pnc->map->mappin[++i])
	{
		while (pnc->map->mappin[i][++j])
		{
			if (pnc->map->mappin[i][j] == 'E')
			{
				pnc->map->end_cnt = pnc->map->end_cnt + 1;
			}
		}
		j = 0;
	}
	if (pnc->map->end_cnt < 1)
	{
		write (1, "End Door Count Error", 21);
		close_frame(pnc);
	}
}
