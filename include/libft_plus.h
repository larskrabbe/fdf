/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_plus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:14:51 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/11/05 19:06:42 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PLUS_H
# define LIBFT_PLUS_H

# include	"fdf.h"

int	count_chr_from_str(const char *str, const char chr);
int	counts_lines_from_file(char *file);
int	count_words_in_str(char *str);
int	is_white_space(int a);
int	my_abs(int num);
int	my_hextoi(const char *str);
#endif
