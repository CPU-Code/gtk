/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-05 11:20:39
 * @LastEditTime: 2020-08-05 11:35:04
 * @FilePath: \gtk\button_image\button_image.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */

//头文件
#include <gtk/gtk.h>

// 回调函数
void callback(GtkButton *button, gpointer data)
{
    //获得按钮的文本内容
    const char *str = gtk_button_get_label(button);

    printf("str = %s\n", str);
    // 图像控件
    GtkWidget *image = gtk_image_new_from_file("1.png");
    gtk_button_set_image(GTK_BUTTON(button), image);
}

int main(int argc, char *argv[])
{
    // 初始化
    gtk_init(&argc, &argv);
    // 创建窗口
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);    
    // 设置标题
    gtk_window_set_title(GTK_WINDOW(window), "cpucode button");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    // 设置窗口边框的宽度
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);       

    // 窗口居中
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER); 

    GtkWidget *hbox = gtk_hbox_new(TRUE, 10); 		// 水平布局容器
	gtk_container_add(GTK_CONTAINER(window), hbox); // 把横向盒状容器放入窗口

    // 普通按钮
	GtkWidget *normal_button = gtk_button_new_with_label("normal button");
    
    gtk_button_set_label(GTK_BUTTON(normal_button), "change");	// 设置按钮的文本内容
	g_signal_connect(normal_button, "pressed", G_CALLBACK(callback), NULL);
	gtk_container_add(GTK_CONTAINER(hbox), normal_button);     // 把按钮放入横向容器里

    // 带图标按钮
	GtkWidget *button = gtk_button_new(); // 先创建空按钮
	GtkWidget *image = gtk_image_new_from_file("1.png"); // 图像控件

    gtk_button_set_image(GTK_BUTTON(button), image);
	gtk_container_add(GTK_CONTAINER(hbox), button);     // 把按钮放入横向容器里
	gtk_button_set_relief(GTK_BUTTON(button), GTK_RELIEF_NONE);	// 按钮背景色透明


	// 按钮使能设置，默认为使能TRUE，非使能FALSE
	//gtk_widget_set_sensitive(button, FALSE);

	gtk_widget_show_all(window);	// 显示窗口控件

	gtk_main(); 	// 主事件循环

    return 0; 
}