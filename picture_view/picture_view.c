/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-05 17:50:11
 * @LastEditTime: 2020-08-05 18:45:36
 * @FilePath: \gtk\picture_view\picture_view.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */
#include <stdio.h>
#include <gtk/gtk.h>

typedef struct
{
    GtkWidget *mainWindow;
    GtkWidget *table;
    GtkWidget *image;
    GtkWidget *back;
    GtkWidget *next;
}MYWINDOW;

MYWINDOW window;

void loadImagePixbuf( GtkWidget *image, char *fileName, int w, int h)
{
    //清掉原始图片控件中的数据
    gtk_image_clear(GTK_IMAGE(image));

    //获取图片资源
    GdkPixbuf *src = gdk_pixbuf_new_from_file(fileName, NULL);
    //修改图片资源
    GdkPixbuf *dst = gdk_pixbuf_scale_simple(src, w, h, GDK_INTERP_BILINEAR);

    //将图片资源设置到图片控件中
    gtk_image_set_from_pixbuf(GTK_IMAGE(image), dst);

    //释放上面的图片资源
    g_object_unref(src);
    g_object_unref(dst);
}

GtkWidget *create_button_from_file(char *fileName, int w, int h)
{
    GtkWidget *button = gtk_button_new();
    
    GtkWidget *image = gtk_image_new_from_pixbuf(NULL);

    loadImagePixbuf(image, fileName, w, h);

    gtk_button_set_image(GTK_BUTTON(button), image);

    return button;
}

//user_data=&window
void deal_button(GtkButton *button, gpointer user_data)
{
    //在指针变量使用中  &p  加一个*   *p 减一个*    所以&与*同时出现可以抵消
    //int arr[5]={1,2,3,4,5};
    //arr == &arr[0] == &*(arr+0) == arr+0==arr
    //需求：定义有一个数组  数组有24个元素 每个元素为char *
    char *arr[] = {"1.bmp", "2.bmp", "3.bmp", "4.bmp", "5.bmp", "6.bmp", "7.bmp"};
    int n = sizeof(arr) / sizeof(arr[0]);
    static int index = 0;

    MYWINDOW *p = (MYWINDOW *)(user_data);
    
    if(button == GTK_BUTTON(p->back))
    {
        index--;

        if(index == -1)
        {
            index = n-1;
        }
        printf("按下了back--%d--\n", index);
    }
    else if(button == GTK_BUTTON(p->next))
    {
        index++;

        if(index == n)
        {
            index = 0;
        }
        printf("按下了next--%d--\n", index);
    }

    //根据文件名 拼凑路径
    char path[64] = "";
    sprintf(path, "./image/%s", arr[index]);

    //根据path给图片空间image重新加载图片资源
    loadImagePixbuf(p->image, path, 600, 270);

    //将image控件添加到table中
    gtk_table_attach_defaults(GTK_TABLE(p->table), p->image, 1, 6, 1, 5);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc,&argv);

    window.mainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window.mainWindow), "cpucode 图片查看器");
    gtk_widget_set_size_request(window.mainWindow, 800, 480);
    gtk_window_set_position(GTK_WINDOW(window.mainWindow), GTK_WIN_POS_CENTER);
    g_signal_connect(window.mainWindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    //定义表格容器
    window.table = gtk_table_new(7, 7, TRUE);
    //将表格容器添加到主窗口中
    gtk_container_add(GTK_CONTAINER(window.mainWindow), window.table);

    //创建一个图片控件
    window.image = gtk_image_new_from_pixbuf(NULL);
    //加载一张图片
    loadImagePixbuf(window.image, "./image/1.bmp", 600, 270);
    //将图片控件放入 table 容器中
    gtk_table_attach_defaults(GTK_TABLE(window.table), window.image, 1, 6, 1, 5);
    
    //创建back按钮
    //window.back = gtk_button_new();
    window.back = create_button_from_file("./image/left-circle.png", 100, 70);
    gtk_table_attach_defaults(GTK_TABLE(window.table), window.back, 1, 2, 5, 6);
    g_signal_connect(window.back, "clicked", G_CALLBACK(deal_button), &window);

    //创建next按钮
    window.next = create_button_from_file("./image/right-circle.png", 100, 70);
    gtk_table_attach_defaults(GTK_TABLE(window.table), window.next, 5, 6, 5, 6);
    g_signal_connect(window.next, "clicked", G_CALLBACK(deal_button), &window);


    gtk_widget_show_all(window.mainWindow);
    gtk_main();
    return 0;
}



