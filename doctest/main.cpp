/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:05:14 by steh              #+#    #+#             */
/*   Updated: 2022/09/22 14:53:15 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

int	fact(int n)
{
	return n <= 1 ? n: fact(n - 1) * n;
}

TEST_CASE ("testing factorial")
{
	CHECK(fact(0) == 1);
	CHECK(fact(1) == 1);
}
