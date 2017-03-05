// This header file will define all functions relating to designing and updating the GUI inter face.
#include <gtk/gtk.h>
#include <string.h>

typedef struct
{
	unsigned short int hour;
	unsigned short int min;
	unsigned short int sec;
} TimerVals;

void GTKwindowInit();
void GTKupdateTimerVals();

void hourADD();
void hourSUB();
void minADD();
void minSUB();
void secADD();
void secSUB();

void TimerStart();
void TimerStop();
void TimerClear();
