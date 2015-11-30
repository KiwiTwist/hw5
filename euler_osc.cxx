#include <iostream> 
#include <cstdlib>
#include <cmath>

using namespace std;


int main() {
	double y_f[2];
	double y_b[2];
	double y_a;

	y_f[0] = 1.0;
	y_f[1] = 0.0;
	y_b[0] = 1.0;
	y_b[1] = 0.0;
	y_a = 1.0;

	double dt = M_PI/100.0;
	cout << 0*dt << "\t" << y_f[0] << "\t" << y_b[0] << "\t" << y_a << endl;


	for(double i = dt; i <= 20*M_PI; i += dt) {
		// forward euler
		double temp1 = y_f[0];
		y_f[0] = y_f[0] + dt*y_f[1];
		y_f[1] = y_f[1] - dt*temp1;

		// backward euler
		y_b[0] = (y_b[0] + dt*y_b[1])/(1 + dt*dt);
		y_b[1] = y_b[1] - dt*y_b[0];

		// analytic solution
		y_a = cos(i);		


		cout << i << "\t" << y_f[0] << "\t" << y_b[0] << "\t" << y_a << endl;
	}


	return 0;
}
