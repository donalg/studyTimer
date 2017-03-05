// This header file will define all functions relating to designing and updating the GUI inter face. 

#include <gtk/gtk.h>
#include <string.h>

typedef struct 
{
	unsigned short int min;
	unsigned short int sec;
	unsigned short int hour;
} TimerVals;

void GTKwindowInit();
void GTKwindowDestroy();
void GTKupdateTimerVals();