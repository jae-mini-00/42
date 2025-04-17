/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_token_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/17 21:10:16 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_pharsing.h"

static t_token	*new_token(char *cmd, t_type type)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->value = ft_strdup(cmd);
	token->type = type;
	token->fd = -1;
	token->next = NULL;
	return (token);
}

static void	add_token(t_token **head, char *value, t_type type)
{
	t_token	*new;
	t_token	*temp;

	new = new_token(value, type);
	if (*head == NULL)
		*head = new;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

int	type_init2(char **str, t_data *minishell)
{
	int		i;
	char	*temp;

	i = 0;
	if (access(str[0], X_OK) == 0)
		return (2);
	else if (str[0][0] == '.' || str[0][0] == '/' || str[0][0] == '~')
		return (2);
	while (minishell->path[i])
	{
		temp = ft_strjoin(minishell->path[i], str[0]);
		if (access(temp, X_OK) == 0)
		{
			free(str[0]);
			str[0] = ft_strdup(temp);
			free(temp);
			return (2);
		}
		free(temp);
		i++;
	}
	return (0);
}

int	type_init(char **str, t_data *minishell)
{
	if (!ft_strncmp(str[0], "env", 4))
		return (1);
	else if (!ft_strncmp(str[0], "echo", 5))
		return (1);
	else if (!ft_strncmp(str[0], "pwd", 4))
		return (1);
	else if (!ft_strncmp(str[0], "exit", 5))
		return (1);
	else if (!ft_strncmp(str[0], "cd", 3))
		return (1);
	else if (!ft_strncmp(str[0], "export", 7))
		return (1);
	else if (!ft_strncmp(str[0], "unset", 6))
		return (1);
	else
		return (type_init2(str, minishell));
}

t_token	*token_init(char *str)
{
	int		i;
	char	**data;
	t_token	*token;

	i = -1;
	token = NULL;
	data = minishell_token_data(str);
	while (data[++i])
	{
		if (ft_strncmp(data[i], "|", 2) == 0)
			add_token(&token, data[i], PIPE);
		else if (ft_strncmp(data[i], ">", 2) == 0 || \
				ft_strncmp(data[i], ">>", 3) == 0 || \
				ft_strncmp(data[i], "<", 2) == 0)
			add_token(&token, data[i], REDIRECTION);
		else if (ft_strncmp(data[i], "<<", 3) == 0)
			add_token(&token, data[i], HERE_DOC);
		else if (ft_strncmp(data[i], "$", 1) == 0)
			add_token(&token, data[i], ENV);
		else
			add_token(&token, data[i], ARG);
	}
	return (split_free(data), token);
}
