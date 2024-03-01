#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>

/// <summary>
/// Represent a point in  terminal with a symbol, coordinates, and color.
/// </summary>
class Point {
private:
    char sign;       ///< character used for representation
    int x;           ///< coordinate  x
    int y;           ///< coordinate y
    int color;       ///< ANSI color code

public:
    /// <summary>
    /// constructs a new Point object
    /// </summary>
    /// <param name="initial_sign"> character used for representation </param>
    /// <param name="initial_x">coordinate  x</param>
    /// <param name="initial_y"> coordinate y </param>
    /// <param name="initial_color">ANSI color code</param>
    Point(char initial_sign, int initial_x, int initial_y, int initial_color) :
        sign(initial_sign), x(initial_x), y(initial_y), color(initial_color) {}




    ///Destructor
   // ~Point() {};

    /// <summary>
    /// display the point on the console
    /// </summary>
    void display() const;

    //Setters


    /// <summary>
    /// Sets the symbol for representation
    /// </summary>
    /// <param name="new_s"> new  symbol</param>
    void setSign(char new_s);

    /// <summary>
    /// Sets x
    /// </summary>
    /// <param name="new_x"> new x value </param>
    void setX(int new_x);

    /// <summary>
    /// Sets y
    /// </summary>
    /// <param name="new_y"> new y value </param>
    void setY(int new_y);

    /// <summary>
    /// Sets the ANSI color code
    /// </summary>
    /// <param name="new_color"> new ANSI color code</param>
    void setColor(int new_color);


    //Getters


    /// <summary>
    /// Gets the symbol used for representation
    /// </summary>
    /// <returns> representation symbol.</returns>
    char getSign() const;

    /// <summary>
    /// Gets x
    /// </summary>
    /// <returns> x value</returns>
    int getX() const;

    /// <summary>
    /// Getsy
    /// </summary>
    /// <returns> y value</returns>
    int getY() const;

    /// <summary>
    /// Gets the ANSI color code
    /// </summary>
    /// <returns>The ANSI color code.</returns>
    int getColor() const;
};

#endif // !_POINT_H_
