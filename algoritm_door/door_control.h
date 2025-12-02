#ifndef DOOR_CONTROL_H
#define DOOR_CONTROL_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    double maxSpeed;
    double k;
    double end_point;
    double y1;
    double y2;
} Parameters;

typedef struct Door {
    bool state;
    int integral_door;
    double integral_history[20];
    int8_t integral_history_index;
    Parameters p;
} Door;


double g(double x, const Parameters *p);
double integral_g(double x, const Parameters *p);
double integral_g_endpoint(const Parameters *p);
double trapezoidalIntegral(double a, double b, int n, Parameters *p);
double simpsonIntegral(double a, double b, int n, Parameters *p);
void find_end_point(Parameters *p, double target_distance_meters);
void auto_calibrate_door(Door *door);
double compute_y1(double g_start, const Parameters* p);

#endif
