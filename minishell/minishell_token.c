/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/04 22:43:28 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *new_token(char *cmd, t_type type)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->value = ft_strdup(cmd);
	token->type = type;
	token->next = NULL;
	return (token);
}

void add_token(t_token **head, char *value, t_type type)
{
    t_token *new;
	t_token *temp;

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

t_token	*make_token(char *str)
{
	int		i;
	char	**data;
	t_token	*token;

	i = 0;
	data = minishell_split(str);
	while (data[i])
	{
		if (ft_strncmp(data[i], "|") == 0)
			add_token(&token, data[i], PIPE);
		else if (ft_strncmp(data[i], ">", 2) == 0 || ft_strncmp(data[i], "<", 2) == 0)
			add_token(&token, data[i], REDIRECTION);
		else if (ft_strncmp(data[i], ">>", 3) == 0 || ft_strncmp(data[i], "<<", 3) == 0)
			add_token(&token, data[i], HERE_DOC);
		else if (ft_strncmp(data[i], "$", 2) == 0)
			add_token(&token, data[i], PIPE);
	}
	split_free(data);
}
