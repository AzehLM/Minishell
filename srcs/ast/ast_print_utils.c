/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gueberso <gueberso@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:20:11 by lbuisson          #+#    #+#             */
/*   Updated: 2025/03/26 12:22:12 by gueberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ast.h"

static void	print_cmd_value(char *cmd)
{
	if (cmd)
		printf("%s +", cmd);
	else
		printf("null +");
}

static void	print_redirect_value(char *symbol, char *cmd)
{
	if (cmd)
		printf("%s:%s ", symbol, cmd);
	else
		printf("%s:null ", symbol);
}

static void	print_single_redirect(char *symbol, char *cmd)
{
	if (cmd)
		printf("%s:%s\n", symbol, cmd);
	else
		printf("%s:null\n", symbol);
}

void	print_cmd_node(t_ast *node, char *prefix)
{
	int	i;

	i = -1;
	printf("%s: ", prefix);
	while (node->cmd->cmds[++i])
		print_cmd_value(node->cmd->cmds[i]);
	printf("\n");
}

void	print_redirect_node(t_ast *node, char *symbol)
{
	int	i;

	if (node->type == NODE_REDIR_OUT)
	{
		i = -1;
		while (node->cmd->cmds[++i])
			print_redirect_value(symbol, node->cmd->cmds[i]);
		printf("\n");
	}
	else
		print_single_redirect(symbol, node->cmd->cmds[0]);
}
