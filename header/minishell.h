/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:33:07 by avaldin           #+#    #+#             */
/*   Updated: 2024/03/27 12:04:15 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <signal.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>


typedef struct s_redirection
{
	char					*file;
	int 					direction;
	struct s_redirection	*next;
}							t_red;

typedef struct s_section
{
	char 				**cmd;
	t_red 				*first_red;
	struct s_section	*next;
}						t_section;

typedef struct s_data
{
	struct s_section	*first;
}						t_data;


t_section	*parsing(char *line);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s);
t_section	*ft_sectadd_back(t_section *lst, t_section *new);
t_red		*ft_redadd_back(t_red *lst, t_red *new);
int			skip_quote(char *line);
char 		*str_cut(char *line, int start, int end);
int 		write_quote(char *line, char *dest);
char		*pars_red(char *line, t_section *sect);
void		ft_sectclear(t_section *lst);
void		ft_redclear(t_red *lst);
void		cleaning_cmd(t_section *sect, char *line);
char		*envvar_pars(char *line, char **env);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);











#endif
