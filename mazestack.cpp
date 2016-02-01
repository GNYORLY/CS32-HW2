#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Coord
{
public:
	Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
	int r() const { return m_r; }
	int c() const { return m_c; }
private:
	int m_r;
	int m_c;
};


bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
	stack<Coord> coordStack;
	coordStack.push(Coord(sr, sc));
	maze[sr][sc] = '$';
	while (!coordStack.empty())
	{
		Coord c = (coordStack.top());
		cerr << "(" << c.r() << ", " << c.c() << ")" << endl;
		coordStack.pop();
		if (c.r() == er && c.c() == ec)
			return true;
		else
		{
			if ((c.r() - 1) >= 0 && maze[c.r() - 1][c.c()] == '.')
			{
				coordStack.push(Coord(c.r() - 1, c.c()));
				maze[c.r() - 1][c.c()] = '$';
			}
			if ((c.c() + 1) < nCols && maze[c.r()][c.c() + 1] == '.')
			{
				coordStack.push(Coord(c.r(), c.c() + 1));
				maze[c.r()][c.c() + 1] = '$';
			}
			if ((c.r() + 1) < nRows && maze[c.r() + 1][c.c()] == '.')
			{
				coordStack.push(Coord(c.r() + 1, c.c()));
				maze[c.r() + 1][c.c()] = '$';
			}
			if ((c.c() - 1) >= 0 && maze[c.r()][c.c() - 1] == '.')
			{
				coordStack.push(Coord(c.r(), c.c() - 1));
				maze[c.r()][c.c() - 1] = '$';
			}
		}
	}
	return false;
}
          
