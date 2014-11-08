#include "MazeGenerator.h"

//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularArrays' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: public MazeGenerator(int x, int y)
MazeGenerator::MazeGenerator(int x, int y) : x(x), y(y), maze(RectangularArrays::ReturnRectangularIntArray(this->x, this->y))
{
	generateMaze(0, 0);
}

void MazeGenerator::display()
{
	for (int i = 0; i < y; i++)
	{
		// draw the north edge
		for (int j = 0; j < x; j++)
		{
			std::cout << (maze[j][i] &1) == 0 ? L"+---" : L"+   ";
		}
		std::cout << std::wstring(L"+") << std::endl;
		// draw the west edge
		for (int j = 0; j < x; j++)
		{
			std::cout << (maze[j][i] & 8) == 0 ? L"|   " : L"    "; //khac nhau thi bang 0;
		}
		std::cout << std::wstring(L"|") << std::endl;
	}
	// draw the bottom line
	for (int j = 0; j < x; j++)
	{
		std::cout << std::wstring(L"+---");
	}
	std::cout << std::wstring(L"+") << std::endl;
	for (int i = 0; i < y; i++)
	{
		// draw the north edge
		for (int j = 0; j < x; j++)
		{
			std::cout << maze[j][i] << std::wstring(L"   ");
		}
		std::cout << std::wstring(L"") << std::endl;
	}
}

void MazeGenerator::generateMaze(int cx, int cy)
{
//JAVA TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, Java to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
//ORIGINAL LINE: DIR[] dirs = DIR.values();
	DIR *dirs = DIR::values();
	Collections::shuffle(Arrays::asList(dirs));
	for (auto dir : dirs)
	{
		int nx = cx + dir->dx;
		int ny = cy + dir->dy;
		//System.out.println("maze[nx][ny]"+maze[cx][cy]);
		//System.out.println("dx"+dir.dx+" "+dir.dy);
		if (between(nx, x) && between(ny, y) && (maze[nx][ny] == 0))
		{
			//System.out.println(maze[nx][ny]);
			maze[cx][cy] |= dir->bit;
			maze[nx][ny] |= dir->opposite.bit;
			generateMaze(nx, ny);
			k++;
		}

	}
	/*for(int t=1;t<x;t++) {
		for(int u=1;u<y;u++) {
			System.out.print(maze[t][u]+" ");
		}
		System.out.println("");
	}*/
}

bool MazeGenerator::between(int v, int upper)
{
	return (v >= 0) && (v < upper);
}

void MazeGenerator::main(std::wstring args[])
{
	int x = sizeof(args) / sizeof(args[0]) >= 1 ? (StringConverterHelper::fromString<int>(args[0])) : 8;
	int y = sizeof(args) / sizeof(args[0]) == 2 ? (StringConverterHelper::fromString<int>(args[1])) : 8;
	MazeGenerator *maze = new MazeGenerator(x, y);
	maze->display();
}
