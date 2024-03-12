#include "matrix.h"

matrix::matrix(): matrixArray{{2,1},{3,7}} {}

matrix::matrix(const matrix& rhs)
{
	for (int i = 0; i < MATRIX_ROWS; i++)
	{
		for (int j = 0; j < MATRIX_COLS; j++)
		{
			matrixArray[i][j] = rhs.matrixArray[i][j];
		}
}
}

matrix::~matrix()
{
}

int matrix::getSIZE() const
{
	return matrixSize;
}

double matrix::get(int i, int j) const
{
	return matrixArray[i][j];
}

void matrix::set(int i, int j, double x)
{
	this->matrixArray[i][j] = x;

}

void matrix::transpose()
{
	double tmp[MATRIX_ROWS][MATRIX_COLS];
	for (int row = 0; row < MATRIX_ROWS; row++)
	{
		for (int col = 0; col < MATRIX_COLS; col++)
		{
			tmp[row][col] = matrixArray[row][col];
		}
	}


	for (int row = 0; row < MATRIX_ROWS; row++)
	{
		for (int col = 0; col < MATRIX_COLS; col++)
		{
			matrixArray[row][col]= tmp[col][row] ;
		}
	}
}

matrix matrix::operator*(const matrix &rhs) const
{
	matrix mpr ;
	for (int row = 0; row < MATRIX_ROWS; row++)
	{
		for (int col = 0; col < MATRIX_COLS; col++)
		{
			mpr.matrixArray[row][col] = 0;

			for (int k = 0; k < MATRIX_COLS; ++k) {
				mpr.matrixArray[row][col] += this->matrixArray[row][k] * rhs.matrixArray[k][col];
			}


		}
	}
	


	return mpr;
}

matrix& matrix::operator*=(const matrix &rhs)
{
	matrix mpr;
	for (int row = 0; row < MATRIX_ROWS; row++)
	{
		for (int col = 0; col < MATRIX_COLS; col++)
		{
			mpr.matrixArray[row][col] = 0;

			for (int k = 0; k < MATRIX_COLS; ++k) {
				mpr.matrixArray[row][col] += matrixArray[row][k] * rhs.matrixArray[k][col];
			}


		}
	}
	for (int row = 0; row < MATRIX_ROWS; row++)
	{
		for (int col = 0; col < MATRIX_COLS; col++)
		{
			this->matrixArray[row][col] = mpr.matrixArray[col][row];
		}
	}




	return *this;
}

matrix matrix::operator+(const matrix &rhs) const
{
	matrix sum;
	for (int row = 0; row < MATRIX_ROWS; row++)
	{
		for (int col = 0; col < MATRIX_COLS; col++)
		{
			sum.matrixArray[row][col] = 0;
			sum.matrixArray[row][col] = 
				this->matrixArray[row][col] + rhs.matrixArray[row][col];
		}
	}
	return sum;
}

matrix& matrix::operator+=(const matrix& rhs)
{
	
	for (int row = 0; row < MATRIX_ROWS; row++)
	{
		for (int col = 0; col < MATRIX_COLS; col++)
		{
		
			this->matrixArray[row][col] += rhs.matrixArray[row][col];
		}
	}
	return *this;
}

matrix matrix::operator*(const double x) const
{
	matrix mprs;
	for (int row = 0; row < MATRIX_ROWS; row++)
	{
		for (int col = 0; col < MATRIX_COLS; col++)
		{
			mprs.matrixArray[row][col] = 0;
			mprs.matrixArray[row][col] =
				matrixArray[row][col] * x;
		}
	}
	return mprs;
}

matrix& matrix::operator*=(const double x)
{
	
	for (int row = 0; row < MATRIX_ROWS; row++)
	{
		for (int col = 0; col < MATRIX_COLS; col++)
		{
			
			this->matrixArray[row][col] = matrixArray[row][col] * x;
		}
	}
	return *this;
}

matrix& matrix::operator=(const matrix& rhs)
{
	
	if (this == &rhs)
	{
		return *this;
	}
	for (int i = 0; i < MATRIX_ROWS; ++i) 
	{
		for (int j = 0; j < MATRIX_COLS; ++j) 
		{
			this->matrixArray[i][j] = rhs.matrixArray[i][j];
		}
	}

	return *this;
}

bool matrix::operator==(const matrix& rhs) const
{
	bool eq=false;
	for (int i = 0; i < MATRIX_ROWS; i++)
	{
		for (int j = 0; j < MATRIX_COLS; j++)
		{
			if (matrixArray[i][j] == rhs.matrixArray[i][j])
			{
				eq = true;

			}
			else
			{
				eq = false;
				break;
			}
		}
	}

	return eq;
}

std::ostream& operator<<(std::ostream& outs, const matrix& mx)
{
	
	int size = mx.getSIZE();

	outs << "Matrix 2x2:" << std::endl;
	for (int i = 0; i < size/2; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			outs << " a"<< i + 1<<"," << j + 1<< ":"<< mx.get(i,j) ;
		}
		std::cout << "\n";
	}
	return outs;
}
