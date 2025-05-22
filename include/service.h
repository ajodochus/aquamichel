#ifndef SERVICE_H
#define SERVICE_H
extern int service_timer_10s_current;
void timer_10s_start();
void timer_10s_loop();
extern int service_timer_1s_current;
void timer_1s_start();
void timer_1s_loop();
void service_loop();

#endif