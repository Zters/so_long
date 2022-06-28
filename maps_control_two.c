/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_control_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyanar <tyanar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:28:23 by saksoy            #+#    #+#             */
/*   Updated: 2022/06/28 16:46:06 by tyanar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minlbx.h"

void	endln_control(char line) // mapta bos sataır var mı diye konrol ediyor 
{
	if (line == '\n')
	{
		write(1, "Empty Line In Map", 18);
		exit(1);
	}
}

void	coin_control(t_win *pnc) // oyunda kac tane toplanabilir coin var diye bakıyor 0 olursa acmıyor 
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (pnc->map->mappin[++i])
	{
		while (pnc->map->mappin[i][++j])
		{
			if (pnc->map->mappin[i][j] == 'C')
				pnc->map->coin_cnt = pnc->map->coin_cnt + 1;
		}
		j = 0;
	}
	if (pnc->map->coin_cnt <= 0)
	{
		write(1, "Not Found Coin in Map", 22);
		close_frame(pnc);
	}
}

void	file_control(char *path) // acmayı istedigğim dosya gercketen var mı diye bakıyoruz  
{
	int	fd;

	fd = open(path, O_RDWR);
	if (fd <= 0)
	{
		write(1, "Wrong File Path", 16);
		close(fd);
		exit(1);
	}
	close(fd);
}

void	char_control(t_win *pnc) //istemediğimiz bir sey var mı diye kontrol ediyor 
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (pnc->map->mappin[++i])
	{
		while (pnc->map->mappin[i][++j])
		{
			if (pnc->map->mappin[i][j] != '0'
				&& pnc->map->mappin[i][j] != '1'
				&& pnc->map->mappin[i][j] != 'P'
				&& pnc->map->mappin[i][j] != 'C'
				&& pnc->map->mappin[i][j] != 'E')
			{
				write(1, "Undefined Char", 15);
				close_frame(pnc);
			}
		}
		j = 0;
	}
}
