/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:53:51 by nvaubien          #+#    #+#             */
/*   Updated: 2023/02/27 12:33:56 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../set_up.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*nptr == 32) || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - 48;
		nptr++;
	}
	return (result * sign);
}

int	intlen(int n)
{
	unsigned int	len;
	long			nbr;

	if (n == 0)
		return (1);
	len = 0;
	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

void	handle_negative(long *nbr, char **result)
{
	if (*nbr < 0)
	{
		*nbr *= -1;
		*result[0] = '-';
	}
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	i;
	unsigned int	len;
	long			nbr;

	i = 0;
	len = intlen(n);
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	nbr = n;
	handle_negative(&nbr, &result);
	if (nbr == 0)
		result[0] = '0';
	while (nbr != 0)
	{
		result[len - i - 1] = (nbr % 10) + '0';
		nbr /= 10;
		i++;
	}
	result[len] = 0;
	return (result);
}
