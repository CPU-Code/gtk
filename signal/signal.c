/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-02 21:58:29
 * @LastEditTime: 2020-08-03 16:37:58
 * @FilePath: \gtk\signal\signal.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */

#include <gtk/gtk.h>	// 头文件

// 按钮按下的处理函数, gpointer 相当于 void *
void deal_pressed(GtkButton *button, gpointer user_data)
{
    // 获得按钮的文本信息
	const gchar *text = gtk_button_get_label( button );

	// g_print() 相当于C语言的 printf(), gchar相当于char
	g_print("button_text = %s; user_data = %s\n", text, (gchar *)user_data);
}

int main( int argc,char *argv[] )
{
    gtk_init(&argc, &argv);		// 初始化

    // 创建顶层窗口
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 

    // 设置窗口边框的宽度(窗口里的控件与窗口边框间隔为15)
    gtk_container_set_border_width(GTK_CONTAINER(window), 15);

    /* 当窗口关闭时，窗口会触发destroy信号，
	 * 自动调用gtk_main_quit()结束程序运行。
	 */
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //创建按钮
    GtkWidget *button = gtk_button_new_with_label("cpucode");

    // 把按钮放入窗口(窗口也是一种容器)
    gtk_container_add(GTK_CONTAINER(window), button);	

    /* 按钮按下(pressed)后会自动调用 deal_pressed()
	 * "is pressed"是传给deal_pressed()的数据
	 */
    g_signal_connect(button, "pressed", G_CALLBACK(deal_pressed), "is pressed");

    gtk_widget_show_all(window);	// 显示窗口全部控件

    gtk_main();		// 主事件循环

    return 0;
}