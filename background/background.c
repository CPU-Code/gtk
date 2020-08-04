/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-04 20:07:11
 * @LastEditTime: 2020-08-04 21:44:01
 * @FilePath: \gtk\background\background.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */
#include <gtk/gtk.h>

/**
 * @function: 设置控件字体大小
 * @parameter: 
 *      widget:    需要改变字体的控件
 *      size:      字体大小
 *      is_button: TRUE代表控件为按钮，FALSE为其它控件
 * @return {type} 
 *     success: 
 *     error: 
 * @note: 
 */
static void set_widget_font_size(GtkWidget *widget, int size, gboolean is_button)
{
    GtkWidget *labelChild;  
	PangoFontDescription *font;  
	gint fontSize = size;

    //"Sans"字体名
    font = pango_font_description_from_string("Sans");
    //设置字体大小
    pango_font_description_set_size(font, fontSize * PANGO_SCALE);

    if(is_button)
    {
        //取出GtkButton里的label
        labelChild = gtk_bin_get_child(GTK_BIN(widget));
    }
    else
    {
        labelChild = widget;
    }
    
    //设置label的字体，这样这个GtkButton上面显示的字体就变了
	gtk_widget_modify_font(GTK_WIDGET(labelChild), font);

    pango_font_description_free(font);
}

/**
 * @function: 设置背景图
 * @parameter: 
 *      widget: 主窗口
 *      w, h:   图片的大小
 *      path：  图片路径
 * @return {type} 
 *     success: 
 *     error: 
 * @note: 
 */
static void chang_background(GtkWidget *widget, int w, int h, const gchar *path)
{
    gtk_widget_set_app_paintable(widget, TRUE);		//允许窗口可以绘图
    gtk_widget_realize(widget);

    /* 更改背景图时，图片会重叠
	 * 这时要手动调用下面的函数，让窗口绘图区域失效，产生窗口重绘制事件（即 expose 事件）。
	 */
	gtk_widget_queue_draw(widget);

    GdkPixbuf *src_pixbuf = gdk_pixbuf_new_from_file(path, NULL);	// 创建图片资源对象

    // w, h是指定图片的宽度和高度
    GdkPixbuf *dst_pixbuf = gdk_pixbuf_scale_simple(src_pixbuf, w, h, GDK_INTERP_BILINEAR);

    GdkPixmap *pixmap = NULL;

    /* 
     * 创建pixmap图像; 
	 * NULL：不需要蒙版; 
	 * 123： 0~255，透明到不透明
	 */
    gdk_pixbuf_render_pixmap_and_mask(dst_pixbuf, &pixmap, NULL, 128);

    // 通过pixmap给widget设置一张背景图，最后一个参数必须为: FASLE
	gdk_window_set_back_pixmap(widget->window, pixmap, FALSE);

    // 释放资源
	g_object_unref(src_pixbuf);
    g_object_unref(dst_pixbuf);
    g_object_unref(pixmap);
}

int main( int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    //主窗口操作
	GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "cpucode 改变Label字体大小以及窗口背景图");
	gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    gtk_widget_set_size_request(window, 500, 450);
	gtk_window_set_resizable(GTK_WINDOW(window), FALSE); 		// 固定窗口大小
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    g_signal_connect( window, "destroy", G_CALLBACK(gtk_main_quit), NULL );
    
    GtkWidget *label = gtk_label_new("Test Font");	// 标签
	set_widget_font_size(label, 50, FALSE);			// 设置字体大小

    gtk_container_add(GTK_CONTAINER(window), label);		// 把盒子放在窗口里
	
	chang_background(window, 500, 400, "bg.png");	// 设置窗口背景图

    gtk_widget_show_all(window); // 显示所有部件
	
	gtk_main();
	
	return 0;
}