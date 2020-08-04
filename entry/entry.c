/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-04 13:42:54
 * @LastEditTime: 2020-08-04 18:51:55
 * @FilePath: \gtk\entry\entry.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */
#include <gtk/gtk.h> 

// 按Enter，获取行编辑的内容
void enter_callback( GtkWidget *widget, gpointer entry ) 
{ 
	const gchar *entry_text; 

	// 获得文本内容
	entry_text = gtk_entry_get_text(GTK_ENTRY(entry)); 
	printf("Entry contents: %s\n", entry_text); 
}

int main( int argc, char *argv[] )
{
    gtk_init (&argc, &argv); 	// 初始化

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 	// 创建窗口
    gtk_window_set_title(GTK_WINDOW(window), "cpucode Entry"); 		// 设置标题
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *vbox = gtk_vbox_new(TRUE, 5); 	// 垂直布局，控件均衡摆放，控件间距为0
    gtk_container_add(GTK_CONTAINER(window), vbox); 	// 容器放入窗口

    GtkWidget *entry = gtk_entry_new();  // 创建行编辑 	
	gtk_container_add(GTK_CONTAINER(vbox), entry); 	// 加入垂直布局里
    gtk_entry_set_max_length(GTK_ENTRY(entry), 100);     // 设置行编辑显示最大字符的长度
	gtk_entry_set_text(GTK_ENTRY(entry), "hello word");  // 设置内容
	gtk_entry_set_visibility(GTK_ENTRY(entry), FALSE); 	 // 密码模式

    /* 如果我们想在用户输入文本时进行响应，可以为 activate 设置回调函数。
	 * 当用户在文本输入构件内部按回车键时引发Activate信号；
	 */
    g_signal_connect(entry, "activate", G_CALLBACK(enter_callback), entry);

    GtkWidget *hbox = gtk_hbox_new(TRUE, 0); 	  // 水平布局容器
    gtk_container_add(GTK_CONTAINER(vbox), hbox); // 水平布局容器加入垂直布局容器里

    // "button 1"
    GtkWidget *button1 = gtk_button_new_with_label("button 1");
    gtk_container_add(GTK_CONTAINER(hbox), button1); // 按钮1添加到水平布局容器里

    // "button 2"
    GtkWidget *button2 = gtk_button_new_with_label("button 2"); 
    gtk_container_add(GTK_CONTAINER(hbox), button2); // 按钮2添加到水平布局容器里

    // close button
    GtkWidget *button_close = gtk_button_new_with_label("close"); 
    g_signal_connect(button_close, "clicked", G_CALLBACK (gtk_main_quit), NULL); 
    gtk_container_add(GTK_CONTAINER(vbox), button_close); // 关闭按钮添加到垂直布局容器里

    gtk_widget_show_all(window); // 显示窗口所有控件
 
    gtk_main(); 		// 主事件循环
 
    return 0;
}