#pragma once

#include <string>
#include <iostream>
#include "stringconverter.h"

/*
 * recursive backtracking algorithm
 * shamelessly borrowed from the ruby at
 * http://weblog.jamisbuck.org/2010/12/27/maze-generation-recursive-backtracking
 */
class MazeGenerator
{
private:
	enum class DIR
	{
//JAVA TO C++ CONVERTER TODO TASK: Enum values must be single integer values in C++:
		N(1, 0, -1), S(2, 0, 1), E(4, 1, 0), W(8, -1, 0);
//JAVA TO C++ CONVERTER TODO TASK: Enums cannot contain fields in C++:
//		private final int bit;
//JAVA TO C++ CONVERTER TODO TASK: Enums cannot contain fields in C++:
//		private final int dx;
//JAVA TO C++ CONVERTER TODO TASK: Enums cannot contain fields in C++:
//		private final int dy;
//JAVA TO C++ CONVERTER TODO TASK: Enums cannot contain fields in C++:
//		private DIR opposite;

		// use the static initializer to resolve forward references
//JAVA TO C++ CONVERTER TODO TASK: Static constructors are not available in native C++:
//JAVA TO C++ CONVERTER TODO TASK: Enums cannot contain methods in C++:
//		static MazeGenerator()
//		{
//			N.opposite = S;
//			S.opposite = N;
//			E.opposite = W;
//			W.opposite = E;
//		}

//JAVA TO C++ CONVERTER TODO TASK: Enums cannot contain methods in C++:
//		private DIR(int bit, int dx, int dy)
//		{
//			this.bit = bit;
//			this.dx = dx;
//			this.dy = dy;
//		}
	};

private:
	const int x;
	const int y;
//JAVA TO C++ CONVERTER WARNING: Since the array size is not known in this declaration, Java to C++ Converter has converted this array to a pointer.  You will need to call 'delete[]' where appropriate:
//ORIGINAL LINE: private final int[][] maze;
	const int **maze;
public:
	static int k = 0;
//JAVA TO C++ CONVERTER NOTE: The following call to the 'RectangularArrays' helper class reproduces the rectangular array initialization that is automatic in Java:
//ORIGINAL LINE: public MazeGenerator(int x, int y)
	MazeGenerator(int x, int y);

	virtual void display();

private:
	void generateMaze(int cx, int cy);

	static bool between(int v, int upper);

	static void main(std::wstring args[]);
//	 public static void main(String[] args) {
//	        for(int i = 1; i < args.length; i++) {
//	            System.out.println(args[i]);
//	        }
//	    }
};
//odd generate 1-> path,even generate 0-> encapsulation
