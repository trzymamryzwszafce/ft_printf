/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szmadeja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:22:31 by szmadeja          #+#    #+#             */
/*   Updated: 2025/01/08 15:00:24 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_format(char letter, va_list ap)
{
    int i;

    i = 0;
    if (letter == 'c')
        i += ft_char(va_arg(ap, int));
    else if (letter == 's')
        i += ft_str(va_arg(ap, int));
    else if (letter == 'p')
        i += ft_ptr(va_arg(ap, int));
    else if (letter == 'd')
        i += ft_dec(va_arg(ap,int));
    else if (letter == 'i')
        i += ft_int(va_arg(ap, int));
    else if (letter == 'u')
        i += ft_udec(va_arg(ap, int));
    else if (letter == 'x')
        i += ft_lhex(va_arg(ap, int));
    else if (letter == 'X')
        i += ft_uhex(va_arg(ap, int));
    else if (letter == '%')
        i += ft_per(va_arg(ap, int));
    else
        i += write(1, &letter, 1);
    return (i);

}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	i;

	va_start(ap, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
			i += ft_format(*(++format), ap);
		else
			i += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (i);
}
