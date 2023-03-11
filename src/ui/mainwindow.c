#include <gtk/gtk.h>
#include "mainwindow.h"

GtkBuilder *builder;
GtkWidget *window;

void createmainwindow(){
    builder = gtk_builder_new_from_file("ui/mainwindow.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_builder_connect_signals(builder, NULL);

    gtk_widget_show_all(window);
}