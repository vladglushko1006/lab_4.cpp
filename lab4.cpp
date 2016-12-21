#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

const char EXIT = 6;
const double pi = 3.1415926536;
const double p = 1.6075;

class VolumetricFigures
{
	
protected:

	double S, V;

public:

	void input()
	{
		cout << "      " << " <<<<< Enter parameters of figure >>>>> " << "\n";
	}
	void output()
	{
		cout << "      " << " <<<<< Inference square and volume of figure >>>>> " << "\n";
		cout << "Square of figure\n S= " << S << "\n";
		cout << "Volume of figure\n V= " << V << "\n";
	}
};


class Cone : public VolumetricFigures
{

private:
	
	double r, h, l;

public:

	void input ()
	{
		VolumetricFigures :: input ();
		cout << "   " << " <<<<< Cone >>>>> " <<"\n";
		cout << "Enter semidiameter of cone:\n r=";
		cin >> r;
		cout << "Enter height of cone:\n h=";
		cin >> h;
	}

	void calculate ()
	{
		l = sqrt(pow(r,2)+pow(h,2));
		S = pi * r * (r + l);
		V = (1.0/3) * pi * r * r * h;
	}
	
	void output ()
	{
		VolumetricFigures :: output ();
	}
};


class Parallelepiped : public VolumetricFigures
{

private:
	
	double x, y, z, sin_x_y, sin_y_z, sin_z_x, sin_z_x_y;

public:

	void input ()
	{
		VolumetricFigures :: input ();
		cout << "   " << " <<<<< Parallelepiped >>>>> " <<"\n";
		cout << "Enter length of parallelepiped:\n x=";
		cin >> x;
		cout << "Enter depth of parallelepiped:\n y=";
		cin >> y;
		cout << "Enter height of parallelepiped:\n z=";
		cin >> z;
		
		sin_x_y = 2;
	 	while (sin_x_y > 1 || sin_x_y < -1)
	 	{
	 		cout << "Enter sinus of corner between x and y (bigger than -1 and less than 1):\n sin_x_y =";
	 		cin >> sin_x_y;
	 	}
	 	
	 	sin_y_z = 2;
	 	while (sin_y_z > 1 || sin_y_z < -1)
	 	{
			cout << "Enter sinus of corner between y and z:\n sin_y_z =";
			cin >> sin_y_z;
		}
		
		sin_z_x = 2;
	 	while (sin_z_x > 1 || sin_z_x < -1)
	 	{
		cout << "Enter sinus of corner between z and x:\n sin_z_x =";
		cin >> sin_z_x;
		}
		
		sin_z_x_y = 2;
	 	while (sin_z_x_y > 1 || sin_z_x_y < -1)
	 	{
		cout << "Enter sinus of corner between z and plane(x,y):\n sin_z_x_y =";
		cin >> sin_z_x_y;
		}
	}

	void calculate ()
	{
		S = 2 * (x * y * sin_x_y + y * z * sin_y_z + z * x * sin_z_x);
		V = x * y * z * sin_x_y * sin_z_x_y;
	}

	void output ()
	{
		VolumetricFigures :: output ();
	}
};


class Cube : public VolumetricFigures
{

private:
	
	double x;

public:

	void input ()
	{
		VolumetricFigures :: input ();
		cout << "   " << " <<<<< Cube >>>>> " <<"\n";
		cout << "Enter edge of cube:\n x=";
		cin >> x;
	}

	void calculate ()
	{
		S = 6 * x * x;
		V = x * x * x;
	}

	void output ()
	{
		VolumetricFigures :: output ();
	}
};


class Sphere : public VolumetricFigures
{

private:
	
	double r;

public:

	void input ()
	{
		VolumetricFigures :: input ();
		cout << "   " << " <<<<< Sphere >>>>> " <<"\n";
		cout << "Enter semidiameter of sphere:\n r=";
		cin >> r;
	}

	void calculate ()
	{
		S = 4 * pi * r * r;
		V = (4.0/3) * pi * r * r *r;
	}

	void output ()
	{
		VolumetricFigures :: output ();
	}
};


class Ellipsoid : public VolumetricFigures
{

private:

	double a, b, c;

public:

	void input ()
	{
		VolumetricFigures :: input ();
		cout << "   " << " <<<<< Ellipsoid >>>>> " <<"\n";
		cout << "Enter first semiaxis of ellipsoid:\n a=";
		cin >> a;
		cout << "Enter second semiaxis of ellipsoid:\n b=";
		cin >> b;
		cout << "Enter third semiaxis of ellipsoid:\n c=";
		cin >> c;
	}

	void calculate ()
	{
		S = 4 * pi * (pow(pow(a,p) * pow(b,p) + pow(a,p) * pow(c,p) + pow(b,p) * pow(c,p) / 3,(1.0 / p)));
		V = 4 * pi * a * b * c;
	}

	void output ()
	{
		VolumetricFigures :: output ();
	}
};



int main()
{
	int count;

	enter_figure: cout << "Choose figure:\n 1 - Cone;\n 2 - Parallelepiped;\n 3 - Cube;\n 4 - Ellipsoid;\n 5 - Sphere:\n ";
	cin >> count;

	switch (count) 
	{
		case 1: 
		{
		Cone k;
			k.input();
			k.calculate();
			k.output();
		break;
		}

		case 2:
		{
		Parallelepiped p;
			p.input();
			p.calculate();
			p.output();
		break;
		}

		case 3:
		{
		Cube c;
			c.input();
			c.calculate();
			c.output();
		break;
		}

		case 4:
		{
		Ellipsoid e;
			e.input();
			e.calculate();
			e.output();
		break;
		}

		case 5:
		{
			Sphere s;
			s.input();
			s.calculate();
			s.output();
			break;
		}

		default: 
			cout << "Wrong enter" << endl;
			goto enter_figure;
		}

	system("pause");
	return 0;
}
