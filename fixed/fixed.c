/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-04 08:14:19
 * @LastEditTime: 2020-08-04 08:22:09
 * @FilePath: \gtk\fixed\fixed.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */
#include <gtk/gtk.h> 

int main( int argc, char *argv[]) 
{
    gtk_init(&argc, &argv); 	// 初始化

    GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL); 	 // 创建窗口 
    gtk_window_set_title(GTK_WINDOW(window), "cpucode"); // 设置标题

    // 为窗口的 "destroy" 事件设置一个信号处理函数  
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    GtkWidget *fixed = gtk_fixed_new(); 	//创建一个固定容器
    gtk_container_add(GTK_CONTAINER (window), fixed); // 固定放进窗口

    GtkWidget *button; 
	int i; 

    for(i = 1 ; i <= 3 ; i++)
    {
        button = gtk_button_new_with_label ("Press me");  // 创建按钮
        // 将按钮组装到一个固定容器的窗口中
		gtk_fixed_put(GTK_FIXED(fixed), button, i * 50, i * 50); 
    }

    gtk_widget_show_all(window);  // 显示所有控件
    
    gtk_main();  //进入事件循环 
	 
	return 0; 
}