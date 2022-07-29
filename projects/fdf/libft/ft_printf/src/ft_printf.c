/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:08:42 by gschiavo          #+#    #+#             */
/*   Updated: 2022/07/05 21:06:11 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

int	ft_printf_arg(const char *fmt, int i, va_list ap);

int	ft_handle_void_pointer(void*args);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed;
	int		i;

	i = 0;
	printed = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			printed += ft_printf_arg(format, i, ap);
			i++;
		}
		else
			printed += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (printed);
}

int	ft_printf_arg(const char *fmt, int i, va_list ap)
{
	if (fmt[i + 1] == '%')
		return (ft_putchar(fmt[i + 1]));
	else if (fmt[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (fmt[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (fmt[i + 1] == 'd' || fmt[i + 1] == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (fmt[i + 1] == 'u')
		return (putnbr_unsigned(va_arg(ap, unsigned int)));
	else if (fmt[i + 1] == 'x' || fmt[i + 1] == 'X')
	{
		if (fmt[i + 1] == 'X')
			return (put_hex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
		else
			return (put_hex(va_arg(ap, unsigned int), "0123456789abcdef"));
	}
	else if (fmt[i + 1] == 'p')
		return (ft_handle_void_pointer(va_arg(ap, void *)));
	else
		return (0);
}

int	ft_handle_void_pointer(void*args)
{
	void	*ptr;

	ptr = args;
	if (!ptr)
	{
		ft_putstr("(nil)");
		return (5);
	}
	else
	{
		return (ft_putstr("0x") + put_pointer(ptr, "0123456789abcdef"));
	}
}
