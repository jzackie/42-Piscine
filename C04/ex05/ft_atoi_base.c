/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masalon <masalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 02:07:58 by masalon           #+#    #+#             */
/*   Updated: 2025/07/05 05:14:16 by masalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_base(char *base)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	while (base[len])
		len++;
	if (len < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if ((base[i] >= 9 && base[i] <= 13)
			|| base[i] == 32 || base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_convert_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*skip_whitespace_and_signs(char *str, int *sign)
{
	*sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign *= -1;
		str++;
	}
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	result;
	int	index;
	int	sign;

	if (!is_valid_base(base))
		return (0);
	str = skip_whitespace_and_signs(str, &sign);
	len = ft_strlen(base);
	index = is_convert_base(*str, base);
	result = 0;
	while (index != -1)
	{
		result = result * len + index;
		str++;
		index = is_convert_base(*str, base);
	}
	return (result * sign);
}
