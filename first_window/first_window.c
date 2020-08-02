/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-01 15:05:07
 * @LastEditTime: 2020-08-01 15:59:41
 * @FilePath: \gtk\first_window\first_window.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */ 
// 头文件
#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    // 初始化，必须在控件定义之前使用
    gtk_init();

    /* 创建窗口(参数有两种形式)
	 * GTK_WINDOW_TOPLEVEL：顶层窗口，包含窗口的标题栏和边框，有最大化最小化
	 * GTK_WINDOW_POPUP：弹出窗口, 没有窗口的标题栏和边框，不能改变大小和移动
	 */
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // 显示窗口控件
    gtk_widget_show(window);	

    // 主事件循环，程序也必须要这个	
    gtk_main();

    return 0;
}