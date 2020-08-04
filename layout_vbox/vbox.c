/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-03 17:31:41
 * @LastEditTime: 2020-08-03 18:34:37
 * @FilePath: \gtk\layout_vbox\vbox.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */
#include <gtk/gtk.h>	// 头文件

/*
 * 设置label字体的大小
 * label: 需要操作的label
 * size:  字体的大小
 */
void set_label_font_size(GtkWidget *label, int size)
{
    // 字体指针
    PangoFontDescription *font;

    //参数为字体名字
    font = pango_font_description_from_string("cpucode");

	// #define PANGO_SCALE 1024
	// 设置字体大小   
    pango_font_description_set_size(font, size * PANGO_SCALE);
    // 改变label的字体大小
    gtk_widget_modify_font(label, font);
    // 释放字体指针分配的空间
    pango_font_description_free(font);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);   // 初始化

    // 创建窗口
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // 设置标题 
    gtk_window_set_title(GTK_WINDOW(window), "vertical layout");

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
     // 设置窗口边框的宽度
    gtk_container_set_border_width(GTK_CONTAINER(window), 15);
    // 创建纵向盒状容器
    GtkWidget *vbox = gtk_vbox_new(TRUE, 15);
    // 把纵向盒状容器放入窗口
    gtk_container_add(GTK_CONTAINER(window), vbox);

    //label one
    // 创建标签
    GtkWidget *label = gtk_label_new("label one");
    // 设置label字体大小，这个为自定义的函数
    set_label_font_size(label, 30);
    // 将按钮放在布局容器里
    gtk_container_add(GTK_CONTAINER(vbox), label);

    // label two
	label = gtk_label_new("text");

    gtk_label_set_text(GTK_LABEL(label), "label two");   	   // 设置label的内容
    const char *str = gtk_label_get_label( GTK_LABEL(label) ); // 获得标签的内容
    g_print("str = %s\n", str);
    
	// 设置label字体大小，这个为自定义的函数
    set_label_font_size(label, 30);
    gtk_container_add(GTK_CONTAINER(vbox), label); 		// 将按钮放在布局容器里

    // label three
	label = gtk_label_new("label three");
	set_label_font_size(label, 30);	// 设置label字体大小，这个为自定义的函数
	gtk_container_add(GTK_CONTAINER(vbox), label); 		// 将按钮放在布局容器里
	
	gtk_widget_show_all(window);	// 显示窗口控件

    // 主事件循环
    gtk_main();

    return 0;
}