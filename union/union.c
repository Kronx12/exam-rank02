/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@42lyon.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:17:44 by gbaud             #+#    #+#             */
/*   Updated: 2021/01/03 23:31:41 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	array[256];

	i = -1;
	while (++i < 256)
		array[i] = 1;
	if (argc == 3 && !(j = 0))
		while (++j < 3 && (i = -1))
			while (argv[j][++i])
				if (array[(int)argv[j][i]]-- == 1)
					write(1, &argv[j][i], 1);
	write(1, "\n", 1);
	return (0);
}
