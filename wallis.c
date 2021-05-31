#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float wallis_pi(int);

int main(void) {
  float pi;
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}

float wallis_pi(int i){
	float pi_by_two =1;
	float pi;
	float form;
	float num;
	float den;
	
	for(int j=1;j<=i;j++){
		num = 4*j*j;
		den = 4*j*j -1;
		form = num/den;
		pi_by_two = pi_by_two * form;
	}
	pi = 2 * pi_by_two;
	return pi;
	
}
