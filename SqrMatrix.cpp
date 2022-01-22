#include <iostream>
#include <locale>
#include <math.h>

using namespace std;
#include "SqrMatrix.h"

	SqrMatrix::SqrMatrix(int sizeofmymatrix)
	{
		size = sizeofmymatrix;
		matrix = new double* [size];
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new double[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	SqrMatrix::SqrMatrix()
	{
		size = 2;
		matrix = new double* [size];
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new double[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	SqrMatrix::SqrMatrix(SqrMatrix& M)
	{
		size = M.size;
		matrix = new double* [size];
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new double[size];
		}
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = M.matrix[i][j];
	}
	
	void SqrMatrix::FillMatrix()
	{
		cout << "enter the elements of matrix: " << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << "[" << i << "][" << j << "]:";
				cin >> matrix[i][j];
			}
		}
	}

	void SqrMatrix::OutputMatrix()
	{
		cout << "Matrix: " << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << matrix[i][j] << "  ";
			}
			cout << endl;
		}
	}
	 int SqrMatrix::Set(double x,int i, int j)
	{
		 if (i < size && j < size)
		 {
			 matrix[i][j] = x;
			 return 0;
		 }
		 else return 1;
	}
	
	double SqrMatrix::Get(int i, int j, int &error)
	{
		if (i < size && j < size)
		{
			error = 0;
			return matrix[i][j];
		}
		
		error = 1;
		return 0;
	}

	SqrMatrix& SqrMatrix::operator= (const SqrMatrix& M)
	{
		for (int i = 0; i < size; i++)
			delete[] matrix[i];
		delete[] matrix;
		size = M.size;
		matrix = new double*[size];
		for (int i = 0; i < size; i++)
		{
			matrix[i] = new double[size];
		}
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = M.matrix[i][j];
		return *this;
	}

	SqrMatrix SqrMatrix::operator+ (const SqrMatrix& M) const
	{
		if (size != M.size)
		{
			cout << "Addition of matrix is imposible";
			exit(1);
		}
		SqrMatrix A(size);
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				A.matrix[i][j] = matrix[i][j] + M.matrix[i][j];
		return A;
	}

	SqrMatrix SqrMatrix::operator- (const SqrMatrix& M) const
	{
		if (size != M.size)
		{
			cout << "Subtraction of matrix is imposible";
			exit(1);
		}
		SqrMatrix A(size);
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				A.matrix[i][j] = matrix[i][j] - M.matrix[i][j];
		return A;
	}

	SqrMatrix SqrMatrix::operator* (const SqrMatrix& M) const
	{
		if (size != M.size)
		{
			cout << "Multiplication of matrix is imposible";
			exit(1);
		}
		SqrMatrix A(size);
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				A.matrix[i][j] = matrix[i][j] * M.matrix[j][i];
		return A;
	}

	SqrMatrix SqrMatrix::operator/ (const SqrMatrix& M) const
	{
		if (size != M.size)
		{
			cout << "Dividing of matrix is imposible";
			exit(1);
		}
		double temp;

		double** E = new double* [size];

		for (int i = 0; i < size; i++)
			E[i] = new double[size];

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				E[i][j] = 0.0;

				if (i == j)
					E[i][j] = 1.0;
			}

		for (int k = 0; k < size; k++)
		{
			temp = M.matrix[k][k];

			for (int j = 0; j < size; j++)
			{
				M.matrix[k][j] /= temp;
				E[k][j] /= temp;
			}
			for (int i = k + 1; i < size; i++)
			{
				temp = M.matrix[i][k];

				for (int j = 0; j < size; j++)
				{
					M.matrix[i][j] -= M.matrix[k][j] * temp;
					E[i][j] -= E[k][j] * temp;
				}
			}
		}

		for (int k = size - 1; k > 0; k--)
		{
			for (int i = k - 1; i >= 0; i--)
			{
				temp = M.matrix[i][k];

				for (int j = 0; j < size; j++)
				{
					M.matrix[i][j] -= M.matrix[k][j] * temp;
					E[i][j] -= E[k][j] * temp;
				}
			}
		}
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				M.matrix[i][j] = E[i][j];
		for (int i = 0; i < size; i++)
			delete[] E[i];
		delete[] E;
		SqrMatrix A(size);
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				A.matrix[i][j] = matrix[i][j] * M.matrix[j][i];
		return A;
	}

	void SqrMatrix::operator*= (double x)
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] *= x;
	}

	SqrMatrix::~SqrMatrix() {
		if (size > 0)
		{
			for (int i = 0; i < size; i++)
				delete[] matrix[i];
			delete[] matrix;
		}
	}



