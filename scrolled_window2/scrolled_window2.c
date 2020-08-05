/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-05 18:55:24
 * @LastEditTime: 2020-08-05 18:57:30
 * @FilePath: \gtk\scrolled_window2\scrolled_window2.c
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
    gtk_window_set_title(GTK_WINDOW(window), "cpucode 滚动窗口");

    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //创建滚动窗口
    GtkWidget *scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window), scroll);

    //创建子控件
    const gchar *msg = "cpucode 1111111111111111111cpucode1111111111111111\n\
    222222222cpucode22222222222222222222222cpucode222222222\n\
    33333333333cpucode33333333333333333333333333333\n\
    444444444444444444cpucode44444444444444444444444";

    GtkWidget *label = gtk_label_new(msg);

    //将label放入滚动窗口中
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(scroll), label);

    //设置滚动窗口的滚动条出项的方式
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}