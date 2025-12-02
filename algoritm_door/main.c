#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>



#define abs_(x) ((x)>0?(x):-(x))

// Parameters struct
typedef struct{
    double maxSpeed;
    double k;
    double end_point;
    double y1;
    double y2;
} Parameters;

// Door struct
typedef struct Door {
    bool isOpening;
    bool isClosing;
    bool state;
    bool intPhotocellTriggered;
    volatile bool microSwitch1;
    volatile bool microSwitch2;
    int integral_door;
    double integral_history[20];
    int integral_history_index;
    double mande_integral;
    double rafte_integral;
    Parameters p;
} Door;

Door door1, door2;




double sigmoid(double z){
	 return 1 / (1 + exp(-z));
}
   
double g(double x,Parameters *p){
	 return p->y1 + (p->maxSpeed - p->y1) * sigmoid(p->k * x) + (p->y2 - p->maxSpeed) * sigmoid(p->k * (x - p->end_point));
}
   
double compute_y1(double g_start, const Parameters* p) {
    
    return 2.0 * g_start - p->maxSpeed 
           - 2.0 * (p->y2 - p->maxSpeed) 
           + 2.0 * (p->y2 - p->maxSpeed) * sigmoid(p->k * p->end_point);
}
// 1 < K 
double integral_g(double x, const Parameters* p) {
	if(p->k == 0){
		return ((p->y2 + p->y1) / 2) * x;	
	}
    return  ((p->maxSpeed - p->y1) / p->k) * log(1 + exp( p->k * x))
    		- ((p->maxSpeed - p->y1) / p->k) * log(1 + exp(p->k * (x - p->end_point)))
    		+ ((p->y2 - p->y1) / p->k) * log(1+ exp(p->k * (x - p->end_point)))
    		+ p->y1 * x
			- 1.11797932348;
}

double integral_g_endpoint(const Parameters* p) {
	if(p->k == 0){
		return ((p->y2 + p->y1) / 2) * p->end_point;	
	}
	
    return  ((p->maxSpeed - p->y1) / p->k) * log(1 + exp( p->k * p->end_point))
    		- ((p->maxSpeed - p->y1) / p->k) * log(2)
    		+ ((p->y2 - p->y1) / p->k) * log(2)
    		+ p->y1 * p->end_point
			- 1.11797932348;
}
// K < R
double trapezoidalIntegral(double a, double b, int n, Parameters *p){


    double h = (b - a) / n;   
    double sum = 0.0;
	int i;
   
    for(i = 1; i < n; ++i){
        sum += g(a + i * h, p);
    }

   
    double result = (g(a, p) + g(b, p)) / 2.0 + sum;

    return result * h;  
}
double simpsonIntegral(double a, double b, int n, Parameters *p) {
   
    if (n % 2 == 1) {
        n++;  
    }
    
    double h = (b - a) / n;
    double sum = g(a, p) + g(b, p);  
    int i;
    for(i = 1; i < n; i++) {
        double x = a + i * h;
        if(i % 2 == 1) {
            sum += 4 * g(x, p);    
        } else {
            sum += 2 * g(x, p);   
        }
    }
    
    return (h / 3.0) * sum;
}

void find_end_point(Parameters*p,double target){ 
	const double TOLERANCE = 0.0001;   
    const int MAX_ITER = 50;
    double avg_speed = p->maxSpeed * 0.68; 
    double estimated_time = target / avg_speed;
    
    p->end_point = estimated_time * 0.9;
    if (p->end_point < 0.4) p->end_point = 0.4;
    if (p->end_point > 100.0) p->end_point = 100.0;
    
    int iter;
    for(iter=0; iter<MAX_ITER; ++iter){ 
    	double current_distance = integral_g_endpoint(p);
        double error = target - current_distance;
        if (fabs(error) < TOLERANCE) break;
        
		double h = 0.0002;
        double saved = p->end_point;
        p->end_point += h;
        double dist_plus = integral_g_endpoint(p);
        double derivative = (dist_plus - current_distance) / h;
        p->end_point = saved;
        
       	double step = error / derivative;
        
 
        double max_step = 0.18 * fabs(p->end_point ? p->end_point : 1.0);
        if (fabs(step) > max_step)
            step = (step > 0) ? max_step : -max_step;
        
        p->end_point += step;
        
      
        if (p->end_point < 0.4) p->end_point = 0.4;
        if (p->end_point > 100.0) p->end_point = 100.0;
	} 
}

Parameters p = {7.2,1,5.4,-2.8,1.6};

int main(){
	double  i=-10;
    printf("Door Test Start\n");
	for( i=4; i <= 4 ;i=i+1){
		p.end_point = 70.000001;
    	find_end_point(&p,i);
		printf("integral : (%f) p.end_point : %f integral_g = %f \n\n",  i,p.end_point,integral_g_endpoint(&p));
	
   
}
    return 0;
}

