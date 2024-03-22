/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:33:07 by avaldin           #+#    #+#             */
/*   Updated: 2024/03/22 16:42:51 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_redirection
{
	char					*file;
	int 					direction;
	struct s_redirection	*next;
}							t_red;

typedef struct s_section
{
	char 				**cmd;
	t_red 				**first_red;
	struct s_section	*next;
}						t_section;

enum special_c {NONE, QUOTE, DOUBLE_QUOTE, LEFT_BRACKET, RIGHT_BRACKET, PIPE, DOUBLE_PIPE, DOUBLE_RIGHT_BRACKET, DOUBLE_LEFT_BRACKET};

t_section	*parsing(char *line);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s);
void		ft_sectadd_back(t_section **lst, t_section *new);
void		ft_redadd_back(t_red **lst, t_red *new);
int			skip_quote(char *line);
char 		*str_cut(char *line, int start, int end);
int 		write_quote(char *line, char *dest);
t_red		**pars_red(char *line, t_red **first_red);








#endif
