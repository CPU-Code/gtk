/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-09-08 20:45:00
 * @LastEditTime: 2020-09-08 23:30:44
 * @FilePath: \gtk\button_switch\button_switch.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */
#include <gtk/gtk.h>

void login_demo(GtkWidget *window);
GtkWidget *create_button_from_file(const char *file_path, const int w, const int h);
void load_image(GtkWidget *image, const char *file_path, const int w, const int h);
void callback(GtkWidget *widget, gpointer data);

int main(int argc, char *argv[])
{
    //初始化
    gtk_init(&argc, &argv);

    GtkWidget *main_window = NULL;

    login_demo(main_window);

    gtk_main();
    return 0;
}

void login_demo(GtkWidget *window)
{
    //主窗口 , 创建顶层窗口
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //标题
    gtk_window_set_title(GTK_WINDOW(window), "cpucode clock");
    //居中
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    //最小大小
    gtk_widget_set_size_request(window, 300, 200);
    // 可伸缩
    gtk_window_set_resizable(GTK_WINDOW(window), TRUE);
    // 窗口边距
    gtk_container_set_border_width(GTK_CONTAINER(window), 5);
    // 确保能关闭窗口
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    // 按钮
    GtkWidget *button = create_button_from_file("./image/play.bmp", 300-20, 200-10);
    gtk_container_add(GTK_CONTAINER(window), button);
    //按钮回调函数
    g_signal_connect(button, "clicked", G_CALLBACK(callback), NULL);

    // 显示窗口全部控件
    gtk_widget_show_all(window);
}

// 根据图片路径创建一个新按钮，同时指定图片大小
GtkWidget *create_button_from_file(const char *file_path, const int w, const int h)
{
    GtkWidget *temp_image = gtk_image_new_from_pixbuf(NULL);
    load_image(temp_image, file_path, w, h);

    // 先创建空按钮
    GtkWidget *button = gtk_button_new();
    // 给按钮设置图标
    gtk_button_set_image(GTK_BUTTON(button), temp_image);
    gtk_button_set_relief(GTK_BUTTON(button), GTK_RELIEF_NONE); // 按钮背景色透明
    
    return button;
}

// 给创建好的image重新设计一张图片
void load_image(GtkWidget *image, const char *file_path, const int w, const int h)
{
    // 清除图像
    gtk_image_clear(GTK_IMAGE(image));

    // 创建图片资源
    GdkPixbuf *src_pixbuf = gdk_pixbuf_new_from_file(file_path, NULL);
    // 指定大小
    GdkPixbuf *dest_pixbuf = gdk_pixbuf_scale_simple(src_pixbuf, w, h, GDK_INTERP_BILINEAR);
    // 图片控件重新设置一张图片(pixbuf)
    gtk_image_set_from_pixbuf(GTK_IMAGE(image), dest_pixbuf);

    // 释放资源
    g_object_unref(src_pixbuf);
    g_object_unref(dest_pixbuf);
}

void callback(GtkWidget *widget, gpointer data)
{
    static gboolean is_press = TRUE;
    GtkWidget *image = gtk_button_get_image(GTK_BUTTON(widget)); // 获得按钮上面的图标

    if(TRUE == is_press)
    {
        // 自动图标换成暂停图标
        load_image(image, "./image/pause.bmp", 300-20, 200-10);

        is_press = FALSE;
    }
    else
    {
        // 暂停图标换成自动图标
        load_image(image, "./image/play.bmp", 300-20, 200-10);

        is_press = TRUE;
    }
}