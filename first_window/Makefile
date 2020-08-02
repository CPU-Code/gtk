 #
 # @由于个人水平有限, 难免有些错误, 还请指点:  
 # @Author: cpu_code
 # @Date: 2020-08-01 15:05:13
 # @LastEditTime: 2020-08-01 15:05:16
 # @FilePath: \gtk\first_window\Makefile
 # @Gitee: [https://gitee.com/cpu_code](https://gitee.com/cpu_code)
 # @Github: [https://github.com/CPU-Code](https://github.com/CPU-Code)
 # @CSDN: [https://blog.csdn.net/qq_44226094](https://blog.csdn.net/qq_44226094)
 # @Gitbook: [https://923992029.gitbook.io/cpucode/](https://923992029.gitbook.io/cpucode/)
 #
CC = gcc
MAINC = first_window.c
EXEC = first_window

CFLAGS = `pkg-config --cflags --libs gtk+-2.0`

main:
	$(CC) $(MAINC) -o $(EXEC) $(CFLAGS)

clean:
	rm $(EXEC) -rf