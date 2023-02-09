/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:38:45 by steh              #+#    #+#             */
/*   Updated: 2022/07/17 19:06:38 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	*ft_getenv(t_shell *shell, const char *name)
{
	int			i;
	int			j;

	i = 0;
	if (!name || !shell->envp)
		return (NULL);
	while (shell->envp[i])
	{
		j = 0;
		while (shell->envp[i][j] && shell->envp[i][j] == name[j])
			j++;
		if (shell->envp[i][j] == '=' && name[j] == '\0')
			return (&shell->envp[i][j + 1]);
		i++;
	}
	return (NULL);
}

void	ft_setenv(t_shell *shell, const char *key, char *value)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (shell->envp[i])
	{
		j = 0;
		while (shell->envp[i][j] && shell->envp[i][j] == key[j])
			j++;
		if (shell->envp[i][j] == '=')
		{
			j++;
			while (value[k] != '\0')
			{
				shell->envp[i][j] = value[k];
				k++;
				j++;
			}
			shell->envp[i][j] = '\0';
		}
		i++;
	}
}

int	ft_unsetenv(t_shell *shell, const char *name)
{
	int		i;
	size_t	len;

	i = 0;
	if (ft_getenv(shell, name) == NULL)
		return (-1);
	len = ft_strlen(name);
	while (shell->envp[i])
	{
		if (ft_strncmp(name, shell->envp[i], len) == 0
			&& (shell->envp[i][len] == '=' || shell->envp[i][len] == '\0'))
		{
			ft_memmove(&shell->envp[i], &shell->envp[i + 1],
				sizeof(char *) * (shell->env_size - i));
			shell->envp[shell->env_size - 1] = NULL;
			return (0);
		}
		i++;
	}
	return (-1);
}
