/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarroye <alarroye@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:32:26 by alarroye          #+#    #+#             */
/*   Updated: 2024/12/07 13:35:48 by alarroye         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*sr;

	sr = s;
	i = 0;
	while (i < n)
	{
		sr[i] = c;
		i++;
	}
	return (sr);
}
