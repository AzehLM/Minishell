/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_copy_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:20:47 by lbuisson          #+#    #+#             */
/*   Updated: 2025/03/26 12:48:00 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

static char	*dup_dquotes(char *content)
{
	char	*content_dquotes;
	size_t	i;
	size_t	j;
	bool	equal;

	equal = false;
	content_dquotes = ft_calloc((ft_strlen(content) + 3), sizeof(char));
	if (content_dquotes == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (content[i])
	{
		content_dquotes[j] = content[i];
		if (content[i] == '=' && equal == false)
		{
			content_dquotes[++j] = '\"';
			equal = true;
		}
		j++;
		i++;
	}
	if (equal == true)
		content_dquotes[j] = '\"';
	return (content_dquotes);
}

static t_list	*copy_dquotes(t_list **new_list)
{
	t_list	*temp;
	char	*content_dquotes;

	temp = *new_list;
	content_dquotes = NULL;
	while (temp)
	{
		content_dquotes = dup_dquotes(temp->content);
		if (content_dquotes == NULL)
		{
			free_list(*new_list);
			return (NULL);
		}
		free(temp->content);
		temp->content = content_dquotes;
		temp = temp->next;
	}
	return (*new_list);
}

t_list	*copy_env(t_list *env)
{
	t_list	*new_list;
	t_list	*temp;

	new_list = NULL;
	temp = env;
	while (temp)
	{
		if (add_node(&new_list, temp->content) == NULL)
		{
			free_list(new_list);
			return (NULL);
		}
		temp = temp->next;
	}
	if (copy_dquotes(&new_list) == NULL)
		return (NULL);
	return (new_list);
}
