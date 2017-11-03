/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:41:33 by hhismans          #+#    #+#             */
/*   Updated: 2017/11/03 08:50:51 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/OpenCvHandler.class.hpp"
#include "../includes/enum.hpp"

int main(int argc, char **argv)
{
	//OpenCvHandler ocHandler;
	Cube cube;

	cube.init();

	cube.move(IUP);
	cube.move(IDOWN);
	cube.move(ILEFT);
	cube.move(IRIGHT);
	cube.move(IBACK);
	cube.move(IFRONT);
	cout << cube << endl;

	
//	ocHandler.run();
	return (0);
}
