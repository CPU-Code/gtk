/*
 * @由于个人水平有限, 难免有些错误, 还请指点:  
 * @Author: cpu_code
 * @Date: 2020-09-09 10:06:01
 * @LastEditTime: 2020-09-09 11:21:26
 * @FilePath: \gtk\read_directory\read_directory.c
 * @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 * @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 * @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 * @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 */
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#define IMAGE_WIDTH     400
#define IMAGE_HEIGTH    300
#define IMAGE_DIR       "./image/"

static int gs_index = 0;
static char *gs_bmp_name[50] = {""};        //存放图片目录和文件名地址的指针数组
static int gs_bmp_total = 0;                //图片总数

void get_bmp_name(char *path);
void order_bmp_name(void);
int conver_bmp_name(char *bmp_pathname);
void save_bmp_name(char *path, char *bmp);
void bmp_name_print(void);
void scanner_demo(void);

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    get_bmp_name(IMAGE_DIR);
    order_bmp_name();
    bmp_name_print();

    scanner_demo();
    gtk_main();
    
    return 0;
}

/**
 * @function: 获取并保存图片的名字
 * @parameter: 
 *      图片的路径：path
 * @return {type} 
 *     success: 
 *     error: 
 * @note: 
 */
void get_bmp_name(char *path)
{
    DIR *dir;
    struct dirent *ptr;

    dir = opendir(path);
    while((ptr = readdir(dir)) != NULL)
    {
        //存图片名
        if(strstr(ptr->d_name, ".bmp"))
        {
            printf("ptr->d_name = %s\n", ptr->d_name);

            save_bmp_name(path, ptr->d_name);
        }
    }

    closedir(dir);
}

/**
 * @function: 根据图片的名字排序
 * @parameter: 
 * @return {type} 
 *     success: 
 *     error: 
 * @note: 
 */
void order_bmp_name(void)
{
    char *tmp = NULL;
    int j, k;

    for(j = 0; j < gs_bmp_total -1; j++)
    {
        for(k = j + 1; k < gs_bmp_total; k++)
        {
            if(conver_bmp_name(gs_bmp_name[j]) > conver_bmp_name(gs_bmp_name[k]))
            {
                tmp = gs_bmp_name[k];
                gs_bmp_name[k] = gs_bmp_name[j];
                gs_bmp_name[j] = tmp;
            }
        }
    }
}

/**
 * @function: 转换图片的名字为数字
 * @parameter: 
 *      图片的路径+图片名：bmp_pathname
 * @return {type} 
 *     success: 图片的编号
 *     error: 
 * @note: 
 */
int conver_bmp_name(char *bmp_pathname)
{
    int num = 0;

    sscanf(bmp_pathname, "./image/%d", &num);
    
    //printf("num=%d\n", num);

    return num;
}

/**
 * @function: 保存图片的目录和名字的地址到指针数组里
 * @parameter: 
 *      图片的路径：path
 *      图片的名字：bmp
 * @return {type} 
 *     success: 
 *     error: 
 * @note: 
 */
void save_bmp_name(char *path, char *bmp)
{
    gs_bmp_name[gs_bmp_total] = (char *)malloc(strlen(bmp) + strlen(path));

    bzero(gs_bmp_name[gs_bmp_total], strlen(bmp) + 1);
    strcpy(gs_bmp_name[gs_bmp_total], path);
    strcat(gs_bmp_name[gs_bmp_total], bmp);

    gs_bmp_total++;
}

/**
 * @function: 打印图片的名字
 * @parameter: 
 * @return {type} 
 *     success: 
 *     error: 
 * @note: 
 */
void bmp_name_print(void)
{
    int i;

    for(i = 0; i < gs_bmp_total; i++)
    {
        printf("bmp_name = %s \n", gs_bmp_name[i]);
    }
}

void scanner_demo(void)
{

	//...

}