/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:23:06 by steh              #+#    #+#             */
/*   Updated: 2022/07/18 18:23:25 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
 
int main()
{
	char str[100];
	int i, j;

	printf("\n Please Enter any String :  ");
	gets(str);

	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			for (j = i; j < strlen(str); j++)
			{
				str[j] = str[j + 1];
			}

			i--;
		}
	}

	printf("\n The Final String after Removing All Quotes = %s ", str);

	return 0;
}