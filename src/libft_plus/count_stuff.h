/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_stuff.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrabbe <lkrabbe@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:14:51 by lkrabbe           #+#    #+#             */
/*   Updated: 2022/10/04 11:03:12 by lkrabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_STUFF_H
# define COUNT_STUFF_H

/*----------------------------------------------------------------------------*\
|																			   |
|	Function that count stuff												   |
|																			   |
\*----------------------------------------------------------------------------*/

#include	"../../include/fdf.h"

//counts the how many times charackter chr apears in a str and returns the value as a int
//returns 0 if str == null and 1 if chr is '\0'
int	count_chr_from_str(const char *str, const char chr);

// counts the amount of lines of a file and returns the amount as a int
// could be easily transform to count for any chareckters not just '\n'
int	counts_lines_from_file(char *file);

//coutns the amount of words the amount of 'words' in a string split whitespace {space newline and tab}
// returns the amount as int 
// returns 0 if split is '\0'
int	count_words_in_str(char *str);


int	is_white_space(int a);

int	ft_abs(int num);

#endif
