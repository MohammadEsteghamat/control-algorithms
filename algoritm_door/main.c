#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>



#define abs_(x) ((x)>0?(x):-(x))
// 1 < K
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

//void find_end_point(Parameters*p,double target_value){ 
//    target_value-=500; 
//    if(target_value<500)target_value=600;
//    double tolerance=0.1;
//    p->end_point=1; 
//    for(int i=0;i<1000;i++){ 
//    	double integral_now=definite_integral_g(p);
//        double error=target_value-integral_now;
//        double dI_db=integral_now/p->end_point;
//        if(abs_(error)<tolerance)return; 
//        p->end_point+=error/dI_db;
//        p->end_time=T_B_RATIO*p->end_point;
//	} 
//}
//
//void set_end_point(Door*door){ 
//    double sum=0;
//    for(int i=0;i<20;i++)
//    	sum+=door->integral_history[i];
//    double mean_sum=sum/20; 
//    find_end_point(&door->p,mean_sum);
//    door->integral_door=mean_sum; 
//}
//
//int OperateDoor(Door*door,volatile uint32_t*pwm_door,double*dI,bool first){
//     return 0; 
//}
//
//void door_init(void){ 
//    door1.p.maxSpeed=999;
//    door1.p.k=2.5; 
//    door1.p.end_point=1.4; 
//    door1.p.y1=-225;
//    door1.p.y2=300; 
//    door1.p.end_time=16; 
//}

// --- END merged content ---
Parameters p = {7.2,1,5.4,-2.8,1.6};

int main(){
	double  i=-10;
    printf("Door Test Start\n");
	for( i=0; i < 100 ;i=i+10){
		p.end_point = i;
		printf("integral(%2.2f) : %3.11f\n",  i,integral_g_endpoint(&p) );
	}
   

    return 0;
}

