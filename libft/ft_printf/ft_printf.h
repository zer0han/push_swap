/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdalal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:48:48 by rdalal            #+#    #+#             */
/*   Updated: 2024/07/01 14:46:04 by rdalal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);

int		ft_printf(const char *str, ...);

int		ft_print_str(char *str);

int		ft_print_int(int n);

int		ft_print_unsigned(unsigned int n);

int		ft_print_ptr(unsigned long ptr);

int		ft_print_hexa(unsigned int nbr, int uppercase);

void	ft_putchar_fd(char c, int fd);

#endif
