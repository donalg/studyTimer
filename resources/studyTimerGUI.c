#include "studyTimerGUI.h"

#define display_height 400;
#define display_width 500;

void GTKwindowInit()
{
	// Create the window:

	GtkWidget *window;// Display window

	GtkWidget *label_hour;  // Labels that will display the time values: 
	GtkWidget *label_minute; 
	GtkWidget *label_second; 

	GtkWidget *table;	// Table which will define the locations of all widgets

	GtkWidget *button_start;  // Buttons for controlling values:
	GtkWidget *button_stop;
	GtkWidget *button_clear;

	GtkWidget *button_hour_add;
	GtkWidget *button_hour_sub;

	GtkWidget *button_min_add;
	GtkWidget *button_min_sub;

	GtkWidget *button_sec_add;
	GtkWidget *button_sec_sub;


	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	button_start = gtk_button_new();
	button_stop = gtk_button_new();
	button_clear = gtk_button_new();

	button_hour_add = gtk_button_new();
	button_hour_sub = gtk_button_new();

	button_min_add = gtk_button_new();
	button_min_sub = gtk_button_new();

	button_sec_add = gtk_button_new();
	button_sec_sub = gtk_button_new();
	
	gtk_button_set_label(GTK_BUTTON(button_start), "Start");
	gtk_button_set_label(GTK_BUTTON(button_stop), "Stop");
	gtk_button_set_label(GTK_BUTTON(button_clear), "Clear");

	gtk_button_set_label(GTK_BUTTON(button_hour_add), "+");
	gtk_button_set_label(GTK_BUTTON(button_hour_sub), "-");

	gtk_button_set_label(GTK_BUTTON(button_min_add), "+");
	gtk_button_set_label(GTK_BUTTON(button_min_sub), "-");

	gtk_button_set_label(GTK_BUTTON(button_sec_add), "+");
	gtk_button_set_label(GTK_BUTTON(button_sec_sub), "-");

	gtk_container_add(GTK_CONTAINER(window), button);

	g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(button, "pressed", G_CALLBACK(update_button), NULL);

	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window),500,500);
	gtk_window_set_title(GTK_WINDOW(window),"Test Signals with button press : Program");
	gtk_widget_show_all(window);

	gtk_main();


}

void GTKwindowDestroy()
{
	// Destroy the Window

}

void GTKupdate()
{
	// Update the time values. along with anything else that needs to be updated. 

}
