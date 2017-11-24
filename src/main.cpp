/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:41:33 by hhismans          #+#    #+#             */
/*   Updated: 2017/11/24 16:45:59 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/OpenCvHandler.class.hpp"
#include "../includes/enum.hpp"

int main(int argc, char **argv)
{
	Cube cube;

	cube.init();

	string inst = "UDLRBFU2D2L2R2F2B2U'B'D'R'L'";//
	cout <<cube<<endl;
	cube.doWhiteCross();
	cout <<cube<<endl;
	//cube.move(IUP);
	//cube.move(IDOWN);
	//cube.move(ILEFT);
	//cube.move(IRIGHT);
	//cube.move(IBACK);
	//cube.move(IFRONT);
	//cout << cube << endl;

	
	if (argc > 1 && argv[1][0] == 'd')
	{
		OpenCvHandler ocHandler;
		ocHandler.run();
	}
	return (0);
}
