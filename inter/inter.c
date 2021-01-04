/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@42lyon.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 22:51:59 by gbaud             #+#    #+#             */
/*   Updated: 2021/01/03 23:26:32 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int array[256];
	int i;

	i = -1;
	while (++i < 256)
		array[i] = 0;
	if (argc == 3)
	{
		i = -1;
		while (argv[2][++i])
			if (!array[(int)argv[2][i]])
				array[(int)argv[2][i]] = 1;
		i = -1;
		while (argv[1][++i])
			if (array[(int)argv[1][i]]--)
				write(1, &argv[1][i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
