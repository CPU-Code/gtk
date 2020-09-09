/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-09-09 12:15:24
 * @LastEditTime: 2020-09-09 17:33:54
 * @FilePath: \gtk\gtk_thread\gtk_thread.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */
#include <gtk/gtk.h>

void deal_thread(gpointer data);

int main(int argc, char *argv[])
{
    if(FALSE == g_thread_supported())
    {
        // 如果线程没有初始化
        
        // 初始化线程，g_thread_init()必须放在gdk_threads_init()前面
        g_thread_init(NULL);
    }

    gdk_threads_init();      //  gdk_threads_init()必须放在if大括号的外面
    gtk_init(&argc, &argv);

    //创建新窗口
    GtkWidget * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "cpucode thread number");
    gtk_widget_set_size_request(window, 300, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //标签
    GtkWidget *label = gtk_label_new("0");
    gtk_container_add(GTK_CONTAINER(window), label);

    gtk_widget_show_all(window);

    /**
     * @function: 创建线程
     * @parameter: 
     *      deal_thread：开辟新线程的回调函数
	 *      label：      传给deal_thread()的参数
     * @return {type} 
     *     success: 
     *     error: 
     * @note: 
     */
    g_thread_create((GThreadFunc)deal_thread, label, FALSE, NULL);

    // 进入多线程互斥区域
    gdk_threads_enter();
    gtk_main();
    // 退出多线程互斥区域
    gdk_threads_leave();

    return 0;
}

// 线程处理函数
void deal_thread(gpointer data)
{
    static int i = 0;

    while(1)
    {
        char buf[6];
        sprintf(buf, "%d", i);
        sleep(1);

        i++;
        //使用gdk_thread_*()将要刷新的界面

        // 进入多线程互斥区域
        gdk_threads_enter();
        
        gtk_label_set_text(GTK_LABEL(data), buf);
        // 退出多线程互斥区域
        gdk_threads_leave();

        if(11 == i)
        {
            i = 0;
        }
    }
}