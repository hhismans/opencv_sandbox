#include <sstream>
#include <string>
#include <iostream>

using namespace std;

enum EFace
{
	UP,
	BACK,
	LEFT,
	FRONT,
	RIGHT,
	DOWN
};

char convert_char(char inst, EFace face)
{
	if (inst == 'U' || inst == 'D')
		return inst;
	else if (inst == 'F')
	{
		if (face == FRONT) return 'F';
		else if (face == BACK) return 'B';
		else if (face == LEFT) return 'L';
		else if (face == RIGHT) return 'R';
	}
	else if (inst == 'R')
	{
		if (face == FRONT) return 'R';
		else if (face == BACK) return 'L';
		else if (face == LEFT) return 'F';
		else if (face == RIGHT) return 'R';
	}
	else if (inst == 'B')
	{
		if (face == FRONT) return 'B';
		else if (face == BACK) return 'F';
		else if (face == LEFT) return 'R';
		else if (face == RIGHT) return 'L';
	}
	else if (inst == 'L')
	{
		if (face == FRONT) return 'L';
		else if (face == BACK) return 'R';
		else if (face == LEFT) return 'B';
		else if (face == RIGHT) return 'F';
	}
	cerr << "error in convertchar" << endl;
	return -1;
}

std::string convert_instructions(std::string str, EFace face)
{
	string ret = "";
	for (int i = 0; i < str.size(); i++)
	{
		ret += convert_char(str[i], face);
		if (i < str.size() - 1 && (str[i + 1] == '\'' || str[i + 1] ==  '2'))
		{
			ret += str[i + 1];
			i++;
		}
	}
	return ret;
}

int main (int argc, char **argv )
{

	string inst = "UDFBLRU2L2R2B2F2F'D'B'F'L'";
	cout << inst << endl;
	cout << "FRONT\t" << convert_instructions(inst, FRONT) << endl;
	cout << "BACK\t" << convert_instructions(inst, BACK) << endl;
	cout << "LEFT\t" << convert_instructions(inst, LEFT) << endl;
	cout << "RIGHT\t" << convert_instructions(inst, RIGHT) << endl;
}
