
#include <gtk/gtk.h>
// This code test a Parameter Widget for CPIM program


// Lets make  a window creation function to modularize code
static void
CreateNotebookWindow (GtkWidget *window)
{
  /* declare some needed widgets*/
  GtkWidget *label, *frame, *notebook, *box, *scale;

 /* --- Create the notebook --- */
  notebook = gtk_notebook_new ();


  // CP BOX
  // to control the parameter of the contact process
  //GtkWidget *mortality_scale, *mortality_label;
  // SCALE SLIDE BAR to set and LABEL display  mortality
  scale = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL,0,1,0.01);
  label = gtk_label_new ("P = (death/colonization) * dt");
  box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER (box), scale);
  gtk_container_add (GTK_CONTAINER (box), label);


  // CP page
  /* make a CP Parameter  label and a frame to put on a page in the Notebook*/
  label = gtk_label_new ("Contact Process");
  frame =  gtk_frame_new ("Demographics");
  // Add CP BOX to the frame to be put of the first page
  gtk_container_add (GTK_CONTAINER (frame), box);
  /* --- Add a page with the frame and label --- */
  gtk_notebook_append_page (GTK_NOTEBOOK (notebook), frame, label);


  // IM BOX
  // to control the parameter of the contact process
  //GtkWidget *mortality_scale, *mortality_label;
  // SCALE SLIDE BAR to set and LABEL display  mortality
  scale = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL,0,1,0.01);
  label = gtk_label_new ("P = (spin flip rate) * dt");
  box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER (box), scale);
  gtk_container_add (GTK_CONTAINER (box), label);


  // IM page
  /* make a IM Parameter label and a frame to put on the new page*/
  label = gtk_label_new ("Ising Model");
  frame =  gtk_frame_new ("Temperature");
  // Add IM BOX to frame to be put on the  second page
  gtk_container_add (GTK_CONTAINER (frame), box);
  /* --- Add a page with the frame and label --- */
  gtk_notebook_append_page (GTK_NOTEBOOK (notebook), frame, label);



  // Parameters
  /*Lets make a frame for the whole notebook---waroom niet? */
  frame =  gtk_frame_new (" Parameters   ");
  /*  add the notebook to the recently made frame*/
  gtk_container_add (GTK_CONTAINER (frame), notebook);
  /*  add the frame to the Application window*/
  gtk_container_add (GTK_CONTAINER (window), frame);
};





static void
activate (GtkApplication* app,
          gpointer        user_data)
{

  GtkWidget *window;
  /* get the window from the GtkApp */
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "CPIM NoteBook");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  /* make a notebook with pages and place it in the window */
  CreateNotebookWindow(window);
  /* show the window*/
  gtk_widget_show_all (window);
}



int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
