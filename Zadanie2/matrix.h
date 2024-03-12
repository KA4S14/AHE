#pragma once
#ifndef _MATRIX_H_
#define _MATRIX_H_


#include <iostream>
/// <summary>
/// Class representation of matrix
/// </summary>
class matrix
{
private:
	/// <summary>
    /// Number of elements in matrix.
    /// </summary>
	const int matrixSize = 4;
	/// <summary>
	/// Number of rows in the matrix.
	/// </summary>
	static constexpr int MATRIX_ROWS = 2;

	/// <summary>
    /// Number of columns in the matrix.
    /// </summary>
	static constexpr int MATRIX_COLS = 2;
	
	/// <summary>
    /// Representation of the matrix.
    /// </summary>
	double matrixArray [MATRIX_ROWS][MATRIX_COLS];
public:
	
	/// <summary>
	/// default constructor
	/// </summary>
	matrix();
	/// <summary>
	/// copy constructor
	/// </summary>
	/// <param name="rhs"> matrix object to be copied </param>
	matrix(const matrix &rhs);
	/// <summary>
	/// empty destructor
	/// </summary>
	~matrix();



	//getters
	
	/// <summary>
	/// getter method to retrive number of elements in matrix
	/// </summary>
	/// <returns>number of elements in matrix</returns>
	int getSIZE() const;

	/// <summary>
	/// getter method to retrive ij-element
	/// </summary>
	/// <param name="i">number of row</param>
	/// <param name="j">number of column</param>
	/// <returns>ij-element</returns>
	double get(int i, int j) const;

	//setters

	/// <summary>
	/// setter method to set ij-element on x-value
	/// </summary>
	/// <param name="i">number of row</param>
	/// <param name="j">number of column</param>
	/// <param name="x">value to set ij-element </param>
	void set(int i, int j, double x);

	/// <summary>
	/// method to transpose the matrix
	/// </summary>
	void transpose();

	//operators

	/// <summary>
	/// overloaded op * to perform matrix multiplication
	/// </summary>
	/// <param name="rhs">matrix to be multiplied with</param>
	/// <returns>result of multiplication</returns>
	matrix operator * (const matrix &rhs) const;


	

	/// <summary>
	/// overloaded compund op *= to perform matrix multiplication
	/// </summary>
	/// <param name="rhs">matrix to be multiplied</param>
	/// <returns>reference to modified matrix after multiplication</returns>
	matrix& operator *= (const matrix &rhs);


	/// <summary>
	/// overloaded op + to perform addition
	/// </summary>
	/// <param name="rhs">matrix to be added</param>
	/// <returns>result of matrix addition</returns>
	matrix operator + (const matrix& rhs) const;
	
	/// <summary>
	/// overloaded compound op += to perform matrix addition
	/// </summary>
	/// <param name="rhs">matrix to be added</param>
	/// <returns>reference to modified matrix after addition </returns>
	matrix& operator += (const matrix &rhs);

	// something special


	/// <summary>
	/// overloaded op - to perform matrix substraction
	/// </summary>
	/// <param name="rhs"> matrix to be substract</param>
	/// <returns>matrix after substraction</returns>
	matrix operator - (const matrix& rhs) const;

	/// <summary>
	/// overloaded compound op -= to perform matrix substraction
	/// </summary>
	/// <param name="rhs">matrix to be substract</param>
	/// <returns>reference to modified matrix after substraction </returns>
	matrix& operator -= (const matrix& rhs);



	/// <summary>
	/// overloaded op * to perform scalar multiplication
	/// </summary>
	/// <param name="x">scalar value</param>
	/// <returns>result of scalar multiplication</returns>
	matrix operator *(const double x) const;
	
	/// <summary>
	/// overloaded compound op *to perform scalar multiplication
	/// </summary>
	/// <param name="x">scalar value</param>
	/// <returns>refernce of modified matrix after scalar multiplication </returns>
	matrix& operator *= (const double x);

	/// <summary>
	/// overloaded op = to perform matrix assignment
	/// </summary>
	/// <param name="rhs"> matrix to be assigned</param>
	/// <returns>reference to modified matrix after assignment</returns>
	matrix& operator = (const matrix& rhs);


	/// <summary>
	/// overloaded op == to compare two matrices for equality
	/// </summary>
	/// <param name="rhs">matrix to compare with</param>
	/// <returns>True if matrices are equal, false otherwise</returns>
	bool operator == (const matrix &rhs) const;

	
	/// <summary>
	/// overloaded op << to display matrix content
	/// </summary>
	/// <param name="outs">output stream to which matrix content will be written</param>
	/// <param name="mx">matrix to be displayed</param>
	/// <returns>reference to output stream</returns>
	friend std::ostream& operator << (std::ostream& outs, const matrix& mx);

	

};


#endif // !_MATRIX_H_