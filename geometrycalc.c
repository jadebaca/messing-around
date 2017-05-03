/**
 *@file geometrycalc.c
 *@brief This program caculates geometric data.
 *@author Jade Baca
 *@date February 2017
 *@bug No known bugs
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double area_rectangle(int rect_height, int rect_width);
double perimeter_rectangle(int rect_height, int rect_width);
double diagonal_rectangle(int rect_height, int rect_width);
double area_circle(double circle_radius);
double circumference(double circle_radius);
double area_triangle(double tri_base, double tri_height);
double hypotenuse(double tri_base, double tri_height);
double perimeter_triangle(double tri_base, double tri_height);
double exterior_angle(int poly_numberside);
double suminterior_angle(int poly_numberside);
double interior_angle(int poly_numberside);
double area_regular_polygon(int poly_numberside, double poly_lengthside);

int main() {
        int rect_height = 0;
        int rect_width = 0;
        double tri_height = 0;
        double tri_base = 0;
        double circle_radius = 0;
        int poly_numberside = 0;
        double poly_lengthside = 0;
        char buf[1024];

        char y, z, f, d, j;


        printf("Welcome to the geometry calculator!TM \n");
        printf("What shape are we calculating today? \n");
        printf("[A] Rectangle \n[B] Circle \n[C] Triangle \n[D] Regular Polygon \n");

        y = getchar();
        getchar(); //2nd is used for the newline character

        switch (y) {
                  case 'a':
                  case 'A':

                          printf("What would you like me to calculate? \n" );
                          printf("[A] Area \n[B] Perimeter \n" );

                          f = getchar();
                          getchar();

                          switch (f) {
                                  case 'A':
                                  case 'a':
                                          printf("Alrighty! Enter the height of the rectangle as a whole number: \n" );
                                          fgets(buf, 1024, stdin);
                                          rect_height = atoi(buf);
                                          if (rect_height < 1) {
                                                  printf("Error: value must be a postive number\n");
                                                  break; //error check for positive value, exits program
                                          }
                                          printf("Enter the width of the rectangle as a whole number: \n" );
                                          fgets(buf, 1024, stdin);
                                          rect_width = atoi(buf);
                                          if (rect_width < 1) {
                                                  printf("Error: value must be a postive number\n");
                                                  break;
                                          }
                                          printf("The area of a rectangle with a height of %d and a width of %d is %f. Nice.\n", rect_height, rect_width, area_rectangle(rect_height, rect_width) );

                                          break;
                                  case 'B':
                                  case 'b':
                                          printf("Enter the height of the rectangle as a whole number: \n" );
                                          fgets(buf, 1024, stdin);
                                          rect_height = atoi(buf);
                                          if (rect_height < 1) {
                                                  printf("Error: value must be a postive number\n");
                                                  break;
                                          }
                                          printf("Enter the width of the rectangle as a whole number: \n" );
                                          fgets(buf, 1024, stdin);
                                          rect_width = atoi(buf);
                                          if (rect_width < 1) {
                                                  printf("Error: value must be a postive number\n");
                                                  break;
                                          }
                                          printf("The perimeter of a rectangle with a height of %d and a width of %d is %f. Cool!\n", rect_height, rect_width, perimeter_rectangle(rect_height, rect_width) );

                                          break;
                                  default:
                                         printf("Invalid Response.\n");
                                  }


                                  break;

                  case 'B':
                  case 'b':
                            printf("Calculations for circle:\n" );
                            printf("[A] Radius\n[B] Circumference\n" );

                            z = getchar();
                            getchar();

                            switch (z) {
                                    case 'a':
                                    case 'A':
                                            printf("Okay! Enter the radius of a circle as a float number: \n");
                                            fgets(buf, 1024, stdin);
                                            circle_radius = atof(buf);
                                            if (circle_radius < 1) {
                                                    printf("Error: value must be a postive number\n");
                                                    break;
                                            }
                                            printf("The area of a circle with a radius of %lf is %lf. What a card! \n", circle_radius, area_circle(circle_radius));

                                            break;
                                    case 'b':
                                    case 'B':
                                            printf("I guess we can...Enter the radius of a circle as a float number: \n");
                                            fgets(buf, 1024, stdin);
                                            circle_radius = atof(buf);
                                            if (circle_radius < 1) {
                                                    printf("Error: value must be a postive number\n");
                                                    break;
                                            }
                                            printf("The circumference of a circle with a radius of %lf is %lf. That was rough. \n", circle_radius, circumference(circle_radius) );

                                            break;
                                    default:
                                            printf("Invalid response\n");
                                    }
                                    break;
                  case 'C':
                  case 'c':
                            printf("Okay let's do a triangle. What would you like to calculate?\n");
                            printf("[A] Area\n[B] Perimeter\n");

                            d = getchar();
                            getchar();

                            switch (d) {
                                    case 'A':
                                    case 'a':
                                            printf("Enter the height of a right triangle as a float number: \n");
                                            fgets(buf, 1024, stdin);
                                            tri_height = atof(buf);
                                            if (tri_height < 1) {
                                                    printf("Error: value must be a postive number\n");
                                                    break;
                                            }
                                            printf("Enter the base of a right triangle as a float number: \n");
                                            fgets(buf, 1024, stdin);
                                            tri_base = atof(buf);
                                            if (tri_base < 1) {
                                                    printf("Error: value must be a postive number\n");
                                                    break;
                                            }
                                            printf("The area of a right triangle with a height of %lf and a base of %lf is %lf. Neato! \n", tri_height, tri_base, area_triangle(tri_height, tri_base) );

                                            break;

                                    case 'B':
                                    case 'b':
                                            printf("Cool. Enter the height of a right triangle as a float number: \n");
                                            fgets(buf, 1024, stdin);
                                            tri_height = atof(buf);
                                            if (tri_height < 1) {
                                                    printf("Error: value must be a postive number\n");
                                                    break;
                                            }
                                            printf("Enter the base of a right triangle as a float number: \n");
                                            fgets(buf, 1024, stdin);
                                            tri_base = atof(buf);;
                                            if (tri_base < 1) {
                                                    printf("Error: value must be a postive number\n");
                                                    break;
                                            }
                                            printf("The perimeter of a right triangle with a height of %lf and a base of %lf is %lf. Done deal.\n", tri_height, tri_base, perimeter_triangle(tri_height, tri_base) );

                                            break;
                                    default:
                                            printf("Oh no, you were supposed to put in A or B. Now you gotta start all over. Bye!\n");
                            }
                            break;

                  case 'D':
                  case 'd':
                            printf("Which calculation would you like?\n");
                            printf(" [A] Exterior Angle Degree\n [B] Interior Angle Degree\n [C] Sum of Interior Angles\n [D] Area\n");

                            j = getchar();
                            getchar();

                            switch (j) {
                                    case 'A':
                                    case 'a':
                                            printf("Enter the number of sides of a regular polygon as a whole number: \n" );
                                            fgets(buf, 1024, stdin);
                                            poly_numberside = atoi(buf);
                                            if (poly_numberside < 1) {
                                                    printf("Error: value must be a postive number\n");
                                                    break;
                                            }
                                            printf("Enter the length of the side of a regular polygon as a float number: \n" );
                                            fgets(buf, 1024, stdin);
                                            poly_lengthside = atof(buf);
                                            if (poly_lengthside < 1) {
                                                    printf("Error: value must be a postive number\n");
                                                    break;
                                            }
                                            printf("The exterior angle of a regular polygon with %d sides is %lf \n", poly_numberside, exterior_angle(poly_numberside));

                                            break;

                                    case 'B':
                                    case 'b':
                                            printf("Enter the number of sides of a regular polygon as a whole number: \n" );
                                            fgets(buf, 1024, stdin);
                                            poly_numberside = atoi(buf);;
                                            if (poly_numberside < 1) {
                                                    printf("Error: value must be a postive number\n");
                                                    break;
                                            }
                                            printf("Enter the length of the side of a regular polygon as a float number: \n" );
                                            fgets(buf, 1024, stdin);
                                            poly_lengthside = atof(buf);
                                            if (poly_lengthside < 1) {
                                                    printf("Error: value must be a postive number\n");
                                                    break;
                                            }
                                            printf("The interior angle of a regular polygon with %d sides is %lfn degrees \n", poly_numberside, interior_angle(poly_numberside) );

                                            break;

                                    case 'C':
                                    case 'c':
                                            printf("Enter the number of sides of a regular polygon as a whole number: \n" );
                                            fgets(buf, 1024, stdin);
                                            poly_numberside = atoi(buf);
                                            if (poly_numberside < 1) {
                                                    printf("Error: value must be a postive number\n");
                                                    break;
                                            }
                                            printf("Enter the length of the side of a regular polygon as a float number: \n" );
                                            fgets(buf, 1024, stdin);
                                            poly_lengthside = atof(buf);;
                                            if (poly_lengthside < 1) {
                                                    printf("Error: value must be a postive number\n");
                                                    break;
                                            }
                                            printf("The interior angle of a regular polygon with %d sides sums to %lf degrees \n", poly_numberside, suminterior_angle(poly_numberside));

                                            break;

                                    case 'D':
                                    case 'd':
                                            printf("Enter the number of sides of a regular polygon as a whole number: \n" );
                                            fgets(buf, 1024, stdin);
                                            poly_numberside = atoi(buf);
                                            if (poly_numberside < 1) {
                                                    printf("Error: value must be a postive number\n");
                                                    break;
                                            }
                                            printf("Enter the length of the side of a regular polygon as a float number: \n" );
                                            fgets(buf, 1024, stdin);
                                            poly_lengthside = atof(buf);
                                            if (poly_lengthside < 1) {
                                                    printf("Error: value must be a postive number\n");
                                                    break;
                                            }

                                            printf("The area of a regular polygon with sides, each %lf long, is %lf \n", poly_lengthside, area_regular_polygon(poly_numberside, poly_lengthside) );

                                            break;

                                    default:
                                            printf("Invalid response.\n");
                                  }

                            break;
                  default:
                            printf("%c is not a valid shape. Bye!\n", y);

                          }

              return(0);
}

/**
* calculates area of rectangle
* @param rect_height rectangle height
* @param rect_width rectangle width
* @return multiplying rect_height by rect_height
*/double area_rectangle(int rect_height, int rect_width)
{
        return(rect_height * rect_width);
}

/**
* calculates perimeter of rectangle
* @param rect_height rectangle height
* @param rect_width rectangle width
* @return sum of rect_height and rect_width twice
*/
double perimeter_rectangle(int rect_height, int rect_width)
{
        return(rect_height + rect_height + rect_width + rect_width);
}

/**
* calculates diagonal of rectangle
* @param rect_height rectangle height
* @param rect_width rectangle width
* @return pythagorean theorem with rect_height and rect_width
*/
double diagonal_rectangle(int rect_height, int rect_width)
{
        return(sqrt(pow(rect_height, 2)) + pow(rect_width, 2));
}

/**
* calculates area of a circle
* @param circle_radius radius of a circle
* @return formula for area of a circle using circle_radius
*/
double area_circle(double circle_radius)
{
        return(M_PI * pow(circle_radius, 2) );
}

/**
* calculates circumference of a circle
* @param circle_radius radius of a circle
* @return formula for circumference of a circle using circle_radius
*/
double circumference( double circle_radius)
{
        return( 2 * M_PI * circle_radius);
}

/**
* calculates area of a triangle
* @param tri_base base of a triangle
* @param tri_height height of a triangle
* @return formula for area of a triangle
*/
double area_triangle(double tri_base, double tri_height)
{
        return(0.5 * tri_base * tri_height);
}

/**
* calculates hypotenuse of a triangle
* @param tri_base base of a triangle
* @param tri_height height of a triangle
* @return formula for hypotenuse of a triangle
*/
double hypotenuse(double tri_base, double tri_height)
{
        return(pow(tri_base, 2) + pow(tri_height, 2));
}

/**
* calculates perimeter of a triangle
* @param tri_base base of a triangle
* @param tri_height height of a triangle
* @return formula for perimeter of a triangle
*/
double perimeter_triangle(double tri_base, double tri_height)
{
        return(hypotenuse(tri_base, tri_height) + tri_base + tri_height);
}

/**
* calculates exterior angle degree of a regular polygon
* @param poly_numberside number of sides of a regular polygon
* @return formula for exterior angle degree of a regular polygon
*/
double exterior_angle(int poly_numberside)
{
        return(360/ poly_numberside);
}

/**
* calculates the sum of interior angles of a regular polygon
* @param poly_numberside number of sides of a regular polygon
* @return formula for the sum of interior angles of a regular polygon
*/
double suminterior_angle(int poly_numberside)
{
        return(poly_numberside - 2);
}

/**
* calculates the interior angle degree of a regular polygon
* @param poly_numberside number of sides of a regular polygon
* @return formula for the interior angle degree of a regular polygon
*/
double interior_angle(int poly_numberside)
{
        return(180 * (poly_numberside - 2/ poly_numberside));
}

/**
* calculates the area of a regular polygon
* @param poly_numberside number of sides of a regular polygon
* @param poly_lengthside lengh of a side of a regular polygon
* @return formula for the area of a regular polygon
*/
double area_regular_polygon(int poly_numberside, double poly_lengthside)
{
        return(pow(poly_lengthside, 2) * poly_numberside / 4 * tan(M_PI / poly_numberside));
}
