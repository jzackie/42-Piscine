/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masalon <masalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:26:10 by masalon           #+#    #+#             */
/*   Updated: 2025/07/05 05:02:51 by masalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign;
	int	number;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	number = 0;
	while (*str >= 48 && *str <= 57)
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * sign);
}
