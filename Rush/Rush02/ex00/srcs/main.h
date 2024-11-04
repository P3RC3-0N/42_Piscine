/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vluo <vluo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:31:01 by vluo              #+#    #+#             */
/*   Updated: 2024/07/14 18:27:56 by vluo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_dict	t_s_dict;
struct s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
};

struct s_str
{
	char			*str;
	struct s_str	*next;
};

struct s_dict	*create_empty_dict(void);
void			add_key(struct s_dict *dict, char *key, char *value);
int				max_dict(struct s_dict *dict);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
void			putstr(char *str);
void			pr_dict(struct s_dict *dict);
void			*free_dict(struct s_dict *dict);
char			*get_value(struct s_dict *dict, char *key);
char			*ft_dup(char *str, int start, int end);
char			*ft_d(char *str);
char			*get_value_from_input(char *str);
char			*get_key_from_input(char *str);
struct s_dict	*create_dict(const char *file);
void			print_error(char *value, struct	s_dict *dict, int error);
char			**fill_tab_str(char **tab_str, char *value, int size);
int				add_str(char *str, struct	s_dict *dict,
					struct	s_str *string);
struct s_str	*create_empty_str(void);
char			*good_value(char *value);
void			ft_putstr(char *str);
void			ft_putchar(char c);
char			*init_tab_string(int size);
void			*free_tab(char **tab_str);
void			*free_str(struct	s_str *string);
int				print_block(char *value, struct	s_dict *dict,
					struct	s_str *string, int size);

#endif
