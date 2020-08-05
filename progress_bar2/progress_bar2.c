/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-05 18:49:59
 * @LastEditTime: 2020-08-05 18:54:01
 * @FilePath: \gtk\progress_bar2\progress_bar2.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */
#include <stdio.h>
#include <gtk/gtk.h>

void add_button(GtkButton *button,gpointer user_data)//user_data==bar
{
    //获得进度条的进度百分比
    gdouble  lf =  gtk_progress_bar_get_fraction(GTK_PROGRESS_BAR(user_data));
    lf += 0.05;

    if(lf >= 1.0)
    {
         gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(user_data), 0.0);
    }
    else if(lf > 0.95)
    {
       // printf("lf = %lf\n", lf);
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(user_data), 1.0);
    }
    else
    {
       //设置进度条的百分比1.0
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(user_data), lf);
    }

}

void change_button(GtkButton *button,gpointer user_data)//user_data==bar
{
    switch (gtk_progress_bar_get_orientation(GTK_PROGRESS_BAR(user_data)))
    {
        case GTK_PROGRESS_LEFT_TO_RIGHT:
            gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(user_data),\
                                             GTK_PROGRESS_RIGHT_TO_LEFT);
            break;
    
        case GTK_PROGRESS_RIGHT_TO_LEFT:
            gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(user_data),\
                                             GTK_PROGRESS_LEFT_TO_RIGHT);
            break;
    }
}

int main(int argc, char  *argv[])
{
    gtk_init(&argc,&argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "cpucode 进度条");
    gtk_widget_set_size_request(window, 200, 100);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //创建一个table布局容器
    GtkWidget *table = gtk_table_new(2, 2, TRUE);
    gtk_container_add(GTK_CONTAINER(window), table);

    //创建一个进度条
    GtkWidget *bar = gtk_progress_bar_new();
    //将bar放置在table中
    gtk_table_attach_defaults(GTK_TABLE(table), bar, 0, 2, 0, 1);

    //创建button
    GtkWidget *add = gtk_button_new_with_label("add");
    gtk_table_attach_defaults(GTK_TABLE(table), add, 0, 1, 1, 2);
    g_signal_connect(add, "clicked", G_CALLBACK(add_button), bar);

    //创建button
    GtkWidget *change = gtk_button_new_with_label("change");
    gtk_table_attach_defaults(GTK_TABLE(table), change, 1, 2, 1, 2);
    g_signal_connect(change, "clicked", G_CALLBACK(change_button), bar);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}