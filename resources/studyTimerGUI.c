#include "studyTimerGUI.h"

#define display_height 100
#define display_width 200

// Define timer values with global access:
TimerVals values;
values.hours = 0;
values.min = 0;
values.sec = 0;

void GTKwindowInit(int argc, char* argv[])
{

	// Create the window:
		gtk_init(&argc, &argv);
		GtkWidget *window;// Display window

		GtkWidget *label_hour;  // Labels that will display the time values:
		GtkWidget *label_minute;
		GtkWidget *label_second;

    GtkWidget *label_title;

		GtkWidget *button_start;  // Buttons for controlling values:
		GtkWidget *button_stop;
		GtkWidget *button_clear;

		GtkWidget *button_hour_add;
		GtkWidget *button_hour_sub;

		GtkWidget *button_min_add;
		GtkWidget *button_min_sub;

		GtkWidget *button_sec_add;
		GtkWidget *button_sec_sub;

    GtkWidget *hours_box;  // Boxes for controlling layout:
    GtkWidget *min_box;
    GtkWidget *sec_box;

    GtkWidget *timer_box;

    GtkWidget *controls_box;

    GtkWidget *display_box;

    // Create the Window:
		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Define all Buttons:
		button_start = gtk_button_new_with_label("Start");
		button_stop = gtk_button_new_with_label("Stop");
		button_clear = gtk_button_new_with_label("Clear");

		button_hour_add = gtk_button_new_with_label("+");
		button_hour_sub = gtk_button_new_with_label("-");

		button_min_add = gtk_button_new_with_label("+");
		button_min_sub = gtk_button_new_with_label("-");

  	button_sec_add = gtk_button_new_with_label("+");
		button_sec_sub = gtk_button_new_with_label("-");

    // Define all Label:
    label_hour = gtk_label_new("0");
    label_minute = gtk_label_new("0");
    label_second = gtk_label_new("0");
    label_title = gtk_label_new("Count down clock.");

    // Define all Boxes:
    hours_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 3);
		min_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 3);
    sec_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 3);

		timer_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3);
		controls_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 3);
		display_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 3);

		// Creating the layout:
		gtk_box_pack_start(GTK_BOX(hours_box), GTK_WIDGET(button_hour_add), 1, 1, 0);
		gtk_box_pack_start(GTK_BOX(hours_box), GTK_WIDGET(label_hour), 1, 1, 0);
		gtk_box_pack_start(GTK_BOX(hours_box), GTK_WIDGET(button_hour_sub), 1, 1, 0);

		gtk_box_pack_start(GTK_BOX(min_box), GTK_WIDGET(button_min_add), 1, 1, 0);
		gtk_box_pack_start(GTK_BOX(min_box), GTK_WIDGET(label_minute), 1, 1, 0);
		gtk_box_pack_start(GTK_BOX(min_box), GTK_WIDGET(button_min_sub), 1, 1, 0);

		gtk_box_pack_start(GTK_BOX(sec_box), GTK_WIDGET(button_sec_add), 1, 1, 0);
		gtk_box_pack_start(GTK_BOX(sec_box), GTK_WIDGET(label_second), 1, 1, 0);
		gtk_box_pack_start(GTK_BOX(sec_box), GTK_WIDGET(button_sec_sub), 1, 1, 0);

		gtk_box_pack_start(GTK_BOX(timer_box), GTK_WIDGET(hours_box), 1, 1, 0);
		gtk_box_pack_start(GTK_BOX(timer_box), GTK_WIDGET(min_box), 1, 1, 0);
		gtk_box_pack_start(GTK_BOX(timer_box), GTK_WIDGET(sec_box), 1, 1, 0);

		gtk_box_pack_start(GTK_BOX(controls_box), GTK_WIDGET(button_start), 1, 1, 0);
		gtk_box_pack_start(GTK_BOX(controls_box), GTK_WIDGET(button_stop), 1, 1, 0);
		gtk_box_pack_start(GTK_BOX(controls_box), GTK_WIDGET(button_clear), 1, 1, 0);

		gtk_box_pack_start(GTK_BOX(display_box), GTK_WIDGET(label_title), 1, 1, 0);
		gtk_box_pack_start(GTK_BOX(display_box), GTK_WIDGET(timer_box), 1, 1, 0);
		gtk_box_pack_start(GTK_BOX(display_box), GTK_WIDGET(controls_box), 1, 1, 0);

		gtk_container_add(GTK_CONTAINER(window), display_box);

		// Connecting functions to widgets:

	g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	//g_signal_connect(button, "pressed", G_CALLBACK(update_button), NULL);

	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
  gtk_window_set_default_size(GTK_WINDOW(window), display_width , display_height);
	gtk_window_set_title(GTK_WINDOW(window),"Study Timer");

	g_signal_connect(button_hour_add, "pressed", G_CALLBACK(hourADD), NULL);
	g_signal_connect(button_hour_sub, "pressed", G_CALLBACK(hourSUB), NULL);

	g_signal_connect(button_min_add, "pressed", G_CALLBACK(minADD), NULL);
	g_signal_connect(button_min_sub, "pressed", G_CALLBACK(minSUBADD), NULL);

	g_signal_connect(button_sec_add, "pressed", G_CALLBACK(secADD), NULL);
	g_signal_connect(button_sec_sub, "pressed", G_CALLBACK(secSUB), NULL);

	g_signal_connect(button_start, "pressed", G_CALLBACK(TimerStart), NULL);
	g_signal_connect(button_stop, "pressed", G_CALLBACK(TimerStop), NULL);
	g_signal_connect(button_clear, "pressed", G_CALLBACK(TimerClear), NULL);

	gtk_widget_show_all(window);

	gtk_main();


}

void hourADD()
{
	if (values.hours < 60)
	{
		values.hours += 1;
		GTKupdateTimerVals();
	}

}

void hourSUB()
{
	if (values.hours > 0)
	{
		values.hours -= 1;
		GTKupdateTimerVals();
	}
}

void minADD()
{
	if (values.min < 60)
	{
		values.min += 1;
		GTKupdateTimerVals();
	}
}

void minSUB()
{
	if (values.min > 0)
	{
		values.min -= 1;
		GTKupdateTimerVals();
	}
}

void secADD()
{
	if (values.sec < 60)
	{
		values.sec += 1;
		GTKupdateTimerVals();
	}
}

void secSUB()
{
	if (values.sec > 0)
	{
		values.sec += 1;
		GTKupdateTimerVals();
	}
}

void TimerStart()
{
	// Start time checker thread and lock buttons:
}
void TimerStop()
{
	// kill time checker thread and unlock buttons:
}
void TimerClear()
{
	values.hours = 0;
	values.min = 0;
	values.sec = 0;
	GTKupdateTimerVals();
}


void GTKupdateTimerVals()
{
	// Update the time values. along with anything else that needs to be updated.
	
}
