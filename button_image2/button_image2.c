/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-05 17:36:32
 * @LastEditTime: 2020-08-05 17:38:20
 * @FilePath: \gtk\button_image2\button_image2.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */
#include <stdio.h>
#include <gtk/gtk.h>

int main(int argc, char  *argv[])
{
    gtk_init(&argc,&argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "signal");
    gtk_widget_set_size_request(window, 500, 400);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //创建一个水平布局容器
    GtkWidget *hbox = gtk_hbox_new(TRUE, 15);
    gtk_container_add(GTK_CONTAINER(window), hbox);

    //创建两个button放入hbox中
    GtkWidget *button01 = gtk_button_new();
    //设置button 不可用
    gtk_widget_set_sensitive(button01, FALSE);

    GtkWidget *button02 = gtk_button_new();

    //定义一个图片控件(不能设置图片大小)
    GtkWidget *image = gtk_image_new_from_file("play-square.png");
    //给button02设置一张图片
    gtk_button_set_image(GTK_BUTTON(button02), image);
    gtk_button_set_relief(GTK_BUTTON(button02), GTK_RELIEF_NONE);

    gtk_container_add(GTK_CONTAINER(hbox), button01);
    gtk_container_add(GTK_CONTAINER(hbox), button02);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}
