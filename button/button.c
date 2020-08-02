/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-01 19:43:14
 * @LastEditTime: 2020-08-01 19:51:56
 * @FilePath: \gtk\button\button.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */ 
#include <gtk/gtk.h> // 头文件

int main( int argc,char *argv[] )
{
    gtk_init(&argc, &argv); // 初始化

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // 创建顶层窗口

    // 设置窗口边框的宽度(窗口里的控件与窗口边框间隔为 15)
    gtk_container_set_border_width(GTK_CONTAINER(window), 15);

    // 创建按钮， 文本信息
    GtkWidget *button = gtk_button_new_with_label("cpucode");
     // 获得按钮的内容
    const char *str = gtk_button_get_label( GTK_BUTTON(button) );

    printf("str = %s\n", str);

    // 把按钮放入窗口(窗口也是一种容器)
    gtk_container_add(GTK_CONTAINER(window), button);

    // 显示控件有两种方法： 逐个显示， 全部显示
    // gtk_widget_show(button);
    // gtk_widget_show(window);
    gtk_widget_show_all(window); // 显示窗口全部控件

    // 主事件循环
    gtk_main();

    return 0;
}