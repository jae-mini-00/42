/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_here_doc_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/30 20:40:49 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

static char	*here_doc_remove_env(char *str, char *start)
{
	char	*temp;
	char	*now_str;
	int		i;

	i = 0;
	now_str = str;
	temp = (char *)malloc(sizeof(char) * \
				(ft_strlen(str) - env_len(&start[1])));
	if (!temp)
		return (NULL);
	while (*now_str)
	{
		if (now_str == start)
			now_str = now_str + env_len(&start[1]) + 1;
		if (*now_str && now_str[0] != 0)
			temp[i++] = *now_str++;
	}
	temp[i] = '\0';
	return (temp);
}

static char	*here_doc_env_init(char *str, char *start, char *env, int j)
{
	char	*temp;
	char	*copy;
	int		i;

	temp = (char *)malloc(sizeof(char) * \
				(ft_strlen(str) + ft_strlen(env) - \
				env_len(start) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	copy = str;
	while (*copy)
	{
		if (copy == start)
		{
			while (env[j])
				temp[i++] = env[j++];
			copy = copy + env_len(start + 1) + 1;
		}
		if (*copy)
			temp[i++] = *copy++;
	}
	temp[i] = '\0';
	free(env);
	return (temp);
}

static char	*here_doc_my_getenv(char *str, char *start, char **env, int i)
{
	char	*temp;
	char	*need_env;
	int		j;

	j = -1;
	need_env = NULL;
	i = env_len(&start[1]);
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	temp[i] = '\0';
	while (++j < i)
		temp[j] = start[1 + j];
	j = -1;
	i = ft_strlen(temp);
	while (env[++j] && i)
		if (ft_strncmp(env[j], temp, ft_strlen(temp)) == 0)
			need_env = ft_strdup(&env[j][i + 1]);
	free(temp);
	if (need_env)
		temp = here_doc_env_init(str, start, need_env, 0);
	else
		temp = here_doc_remove_env(str, start);
	return (temp);
}

static	int	here_doc_write_run(int pipe, char *new_data, t_token *token)
{
	int	len;
	int	o_len;

	o_len = ft_strlen(token->o_value);
	len = ft_strlen(token->value);
	if ((ft_strncmp(new_data, token->value, len) != 0 && !token->quite_flag) \
	|| (token->quite_flag && ft_strncmp(new_data, token->o_value, o_len) != 0))
	{
		write(pipe, new_data, ft_strlen(new_data));
		write(pipe, "\n", 1);
		return (0);
	}
	return (1);
}

int	here_doc_write(char **env, int pipe, char *str, t_token *token)
{
	char	*start;
	char	*temp;
	char	*new_data;
	int		flag;

	temp = NULL;
	new_data = ft_strdup(str);
	while (!token->quite_flag)
	{
		start = here_doc_value_check(new_data, 0);
		if (!start)
			break ;
		temp = new_data;
		if (start && start[1] != '?')
			new_data = here_doc_my_getenv(new_data, start, env, 0);
		else if (start && start[1] == '?')
			new_data = here_doc_exit_code(new_data, start);
		free(temp);
	}
	flag = here_doc_write_run(pipe, new_data, token);
	free(new_data);
	return (flag);
}
