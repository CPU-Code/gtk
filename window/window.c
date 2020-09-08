/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-01 16:31:11
 * @LastEditTime: 2020-08-06 12:05:20
 * @FilePath: \gtk\window\window.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */ 
#include <gtk/gtk.h>

int main(int argc, char *argv[])
{
    //初始化
    gtk_init(&argc, &argv);

    //创建顶部窗口
    GtkWidget *Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    //设置窗口标题
    gtk_window_set_title(GTK_WINDOW(Window), "cpucode");

    /*     
    GTK_WIN_POS_NONE： 不固定
    GTK_WIN_POS_CENTER: 居中
    GTK_WIN_POS_MOUSE: 出现在鼠标位置
    GTK_WIN_POS_CENTER_ALWAYS: 窗口总是居中 
    */
    gtk_window_set_position(GTK_WINDOW(Window), GTK_WIN_POS_CENTER);

    //设置窗口大小
    gtk_widget_set_size_request(Window, 400, 300);

    //设置窗口固定
    gtk_window_set_resizable(GTK_WINDOW(Window), FALSE);

    //"destroy" 和 gtk_main_quit 连接
    g_signal_connect(Window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // 显示窗口全部控件
    gtk_widget_show_all(Window);
    //gtk_widget_hide_all(window);	// 隐藏窗口

    //主事件循环
    gtk_main();

    return 0;
}
