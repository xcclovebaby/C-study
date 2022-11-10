#include <stdio.h>

/** ==========================
 * 学习目录：
 * 1.打开文件和关闭文件
 * 2.读写文件(文件复制)
 * ==========================*/

/** 1.打开文件和关闭文件 */
/* FILE结构体在头文件stdio中被定义
 * FILE *fopen(const char *path, const char *mode);
 * 第一个参数为相对路径或绝对路径
 * 第二个参数是文件打开的方式：
 * 1.r/rb：只读，文件不存在则报错
 * 2.r+/rb+：读写，文件不存在则报错
 * 3.w/wb：只写，文件不存在创建，存在则清空
 * 4.w+/wb+：读写，文件不存在创建，存在则清空
 * 5.a/ab：只写，文件不存在创建，存在则末尾追加内容
 * 6.a+/ab+：读写，文件不存在创建，存在则末尾追加内容
 *
 * 返回值：成功则返回文件类型FILE指针
 * 失败则返回NULL
 *
 * int fclose(FILE *fp);
 * 成功关闭返回0
 * 关闭失败返回非0
 * 关闭后不能对文件指针进行读写操作
 */
int test1() {
    FILE *fp = fopen("C:/Users/Administrator/Desktop/1.txt", "r");
    if(fp == NULL) return -1;
    int status = fclose(fp);
    printf("close status=%d \n", status);
}

/** 2.读写文件(文件复制) */
/* size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream); 读文件
 * 从stream所指向的文件中读取数据，一共size字节，共nmemb块，存放在ptr指向的内存中
 * 返回读到的实际块数
 *
 * size_t fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream); 写文件
 * 将ptr指向的内存中的数据向stream所指向的文件中写入，一块是size字节，共nmemb块
 * 返回实际写入的块数
 */
void test2() {
    FILE *fp = fopen("C:/Users/Administrator/Desktop/1.txt", "r");
    if(fp == NULL) return;

    int num, len;

    char buf[128] = "";

    FILE *wfp = fopen("C:/Users/Administrator/Desktop/2.txt", "w");

    //判断是否读到文件最后
    while(!feof(fp)) {
        num = fread(buf, 1, 1024, fp);

        printf("buf = %s \n", buf);
        printf("num = %d \n", num);

        if(feof(fp)) {
            break;
        }

        len = fwrite(buf, 1, num, wfp);

        if(len != num) {
            printf("请检查磁盘是否已满");
            goto END;
            return;
        }
    }

    len = fwrite(buf, 1, num, wfp);
    if(len != num) {
        printf("请检查磁盘是否已满");
        goto END;
        return;
    }

    END:
    if(fp != NULL) fclose(fp);
    if(wfp != NULL) fclose(wfp);
}


int main()
{
//    test1();
    test2();
    return 0;
}
