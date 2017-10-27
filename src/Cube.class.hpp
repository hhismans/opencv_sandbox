/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Npuzzle.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 20:38:40 by hhismans          #+#    #+#             */
/*   Updated: 2017/05/08 11:10:38 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_CLASS_HPP
# define NPUZZLE_CLASS_HPP

# include <iostream>
# include <list>
# include <vector>
# include <algorithm> // std::find

# include "Astar.class.hpp"

enum Instruction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	BACK,
	FRONT,
	RUP,
	RDOWN,
	RLEFT,
	RRIGHT,
	RBACK,
	RFRONT
}

enum CornerPosition
{
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEXEN,
	EIGHT
}

enum Rotation
{
	CW, //clockwise
	CCW // countterclockwise
}
enum CornerOrientation
{
	ALPHA,
	BETA,
	GAMMA
}

enum RidgePosition
{
	A_RIDGE,
	B_RIDGE,
	C_RIDGE,
	D_RIDGE,
	E_RIDGE,
	F_RIDGE,
	G_RIDGE,
	I_RIDGE,
	J_RIDGE,
	K_RIDGE,
	L_RIDGE
}

enum RidgeOrientation
{
	TRUE,
	FALSE
}

/*
 * Cube decrit comme 8 coin et 12 arete.
 * Chaque arete 
 * */

class Cube
{
	private :
		Corner _corners[8];
		Ridge  _ridges[12];
	public:
		Npuzzle &	operator=(Npuzzle const & rhs);

		std::vector<int>	data;
		int					size;

		static void			move(Instruction instruction);



		static int			manhattanDistance(const Npuzzle & cur, const Npuzzle & goal);
		static int			misplacedTiles(const Npuzzle & cur, const Npuzzle & goal);
		static int			returnOne(const Npuzzle & cur, const Npuzzle & goal);
		static int			linearConflict(const Npuzzle & cur, const Npuzzle & goal);
		static void			getNeighbours(const Npuzzle & cur, std::list<Node<Npuzzle> > & out);
};

std::ostream &		operator<<(std::ostream & out, const Npuzzle &rhs);

#endif
