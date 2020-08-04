/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-03 20:46:55
 * @LastEditTime: 2020-08-04 08:06:30
 * @FilePath: \gtk\table_box\table.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */
#include <gtk/gtk.h>	// 头文件

// button 1, button 2处理函数
void callback(GtkButton *button, gpointer data)
{
	g_print("%s is clicked!\n", (gchar *)data);
}

// close button处理函数
void close_window(GtkWidget *widget, GdkEvent *event, gpointer data)
{
	gtk_main_quit();
}

int main(int argc, char *argv[]) 
{
    gtk_init(&argc, &argv); 	// 初始化
    // 创建窗口
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // 设置标题 
    gtk_window_set_title(GTK_WINDOW(window), "table");

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    // 设置窗口边框的宽度
    gtk_container_set_border_width(GTK_CONTAINER(window), 15);

    /*
	 * 创建表格布局容器
	 * GtkWidget * gtk_table_new(guint rows, guint columns, gboolean homogeneous);
	 * rows:         行数
	 * coumns:       列数
	 * homogeneous： 容器内控件是否均衡排放(TRUE or FALSE)
	 */
    GtkWidget *table = gtk_table_new(2, 2, TRUE);
    gtk_container_add(GTK_CONTAINER(window), table); // 容器加入窗口

    // button 1
	GtkWidget *button = gtk_button_new_with_label("buttton 1");
    g_signal_connect(button, "pressed", G_CALLBACK(callback), "button 1");
	gtk_table_attach_defaults(GTK_TABLE(table), button, 0, 1, 0, 1);// 把按钮加入布局

    // button 2
	button = gtk_button_new_with_label("button 2");
    g_signal_connect(button, "pressed", G_CALLBACK(callback), "button 2");
    gtk_table_attach_defaults(GTK_TABLE(table), button, 1, 2, 0, 1);

    // close button
	button = gtk_button_new_with_label("close");
    g_signal_connect(button, "pressed", G_CALLBACK(close_window), NULL);
	gtk_table_attach_defaults(GTK_TABLE(table), button, 0, 2, 1, 2);

    gtk_widget_show_all(window);	// 显示窗口控件

    gtk_main(); 	// 主事件循环

    return 0;
}