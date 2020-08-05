/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-08-05 17:17:10
 * @LastEditTime: 2020-08-05 17:30:55
 * @FilePath: \gtk\line_edit\line_edit.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

void deal_entry(GtkEntry *entry, gpointer  user_data)
{
    char *myPasswd="123456";
    const gchar * text = gtk_entry_get_text(GTK_ENTRY(entry));
    
    if(strcmp(myPasswd, text) == 0)
    {
        printf("登录成功\n");
    }
    else
    {
        printf("登录失败\n");
    }
    return;
}

void login_fun(GtkButton *button, gpointer   user_data)
{
    //user_data == 行编辑
    GtkWidget *entry = GTK_WIDGET(user_data);
    char *myPasswd="123456";
    const gchar * text = gtk_entry_get_text(GTK_ENTRY(entry));

    printf("---------------------text=%s\n", text);
    if(strcmp(myPasswd, text) == 0)
    {
        printf("登录成功\n");
    }
    else
    {
        printf("登录失败\n");
    }
    
}

int main(int argc, char  *argv[])
{
    gtk_init(&argc,&argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "signal");
    gtk_widget_set_size_request(window, 300, 150);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(window,"destroy", G_CALLBACK(gtk_main_quit),NULL);

    //创建一个行编辑控件
    GtkWidget *entry = gtk_entry_new();

    //设置显示模式
    gtk_entry_set_visibility(GTK_ENTRY(entry), FALSE);
    g_signal_connect(entry, "activate", G_CALLBACK(deal_entry), NULL);

    GtkWidget *login = gtk_button_new_with_label("登陆");
    g_signal_connect(login,"clicked", G_CALLBACK(login_fun), entry);

    GtkWidget *quit = gtk_button_new_with_label("退出");
    g_signal_connect(quit, "clicked", G_CALLBACK(gtk_main_quit), NULL);

    //表格容器
    GtkWidget *table = gtk_table_new(2, 2, TRUE);
    gtk_container_add(GTK_CONTAINER(window), table);

    gtk_table_attach_defaults(GTK_TABLE(table), entry, 0, 2, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(table), login, 0, 1, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(table), quit, 1, 2, 1, 2);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}