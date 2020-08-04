/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-03 16:51:18
 * @LastEditTime: 2020-08-03 17:29:36
 * @FilePath: \gtk\layout_hbox\hbox.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */

#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    //创建窗口
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    //设置标题
    gtk_window_set_title(GTK_WINDOW(window), "cpucode layout");

    //设置窗口边框的宽度
    gtk_container_set_border_width(GTK_CONTAINER(window), 15);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /*
     * 创建横向盒状容器
     * GtkWidget *gtk_vbox_new(gboolean homogeneous, gint spacing);
     * homogeneous：容器内控件是否均衡排放(TRUE or FALSE)
     * spacing: 控件之间的间隔
     */
    GtkWidget *hbox = gkt_hbox_new(TRUE, 10);

    //把横向容器放到窗口
    gtk_container_add(GTK_CONTAINER(window), hbox);
    //button1
    GtkWidget *button = gtk_button_new_with_label("button1");
    // 按钮添加到布局容器里
    gtk_container_add(GTK_CONTAINER(hbox), button);

    // button2
	button = gtk_button_new_with_label("button2");
    // 按钮添加到布局容器里
	gtk_container_add(GTK_CONTAINER(hbox), button);

    // button3
	button = gtk_button_new_with_label("button3");
    gtk_container_add(GTK_CONTAINER(hbox), button); 	// 按钮添加到布局容器里

    gtk_widget_show_all(window);	// 显示窗口控件

    gtk_main(); 	// 主事件循环

	return 0; 
}
