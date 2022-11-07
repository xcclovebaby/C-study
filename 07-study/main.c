#include <stdio.h>
#include <string.h>

/** ==========================
 * 字符串相关函数在头文件:#include <string.h>中
 *
 * 学习目录：
 * 1.strlen:获取字符串长度函数
 * 2.strcpy:字符串拷贝函数
 * 3.strcat:字符串追加函数
 * 4.strcmp:字符串比较函数
 * 5.strchr:字符查找函数
 * 6.strstr:字符串匹配函数
 * 7.atoi/atol/atof:字符串转数值
 * 8.strtok:字符串切割函数
 * 9.格式化字符串操作函数
 * 10.const关键字
 * ==========================*/

/** 1.strlen:获取字符串长度函数 */
/* size_t strlen(const char *s);
 * 返回字符指针s指向的字符串长度
 */
void test1() {
    //动态申请100字节的内存
    char *str = (char *)malloc(100);
    printf("str = %p \n", str);
    //给str赋值
    str = strcpy(str, "hello world");
    printf("str = %p \n", str);

    //获取字符指针指向的字符串长度
    int length = strlen(str);
    printf("length = %d \n", length);

    //使用完后释放
    free(str);
}

/** 2.strcpy:字符串拷贝函数 */
/* char *strcpy(char *dest, const char *src);
 * 拷贝str指向的字符串到dest指针指向的空间中，'\0'也会被拷贝
 * 返回值目的内存的地址
 *
 * 注意：使用此函数的时候，必须保证dest内存空间足够大，否则会出现内存污染
 */
void test2() {
    char s1[32] = "hello world";
    char s2[32] = "abcdefg";
    printf("s1 = %s \n", s1);
    strcpy(s1, s2);
    printf("s1 = %s \n", s1);
}

/** 3.strcat:字符串追加函数 */
/* char *strcat(char *dest, const char *src);
 * 追加src到dest字符串的后面，追加的时候会追加'\0'
 * 注意：要保证dest的空间足够大
 */
void test3() {
    char s1[32] = "hello ";
    char s2[32] = "world";
    strcat(s1, s2);
    printf("s1 = %s \n", s1);
}

/** 4.strcmp:字符串比较函数 */
/* int strcmp(const char *s1, const char *s2);
 * 比较两个字符串的大小
 * 比较方法是逐个字符比较ASCII码
 * 如果s1大于s2返回1
 * 如果s1小于s2返回-1
 * 如果s1等于s2返回0
 */
void test4() {
    char s1[32] = "hello";
    char s2[32] = "hella";
    printf("strcmp(s1,s2) = %d \n", strcmp(s1, s2));
}

/** 5.strchr:字符查找函数 */
/* char *strchr(const char *s, int c);
 * 该函数为首次匹配
 * 在字符指针s指向的字符串中，找到ASCII码为c的字符
 * 只会返回首次匹配到第一次出现的位置的地址
 * 找不到会返回NULL
 *
 * char *strrchr(const char *s, int c);
 * 该函数是末次匹配
 * 返回末次匹配的地址值
 */
void test5() {
    char s1[32] = "hello";
    char *p;
    p = strchr(s1,'l');//首次匹配
    printf("p = %p \n", p);

    p = strrchr(s1,'l');//末次匹配
    printf("p = %p \n", p);
}

/** 6.strstr:字符串匹配函数 */
/* char *strstr(const char *haystack, const char *needle);
 * 在haystack指向的字符串中查找needle指向的字符串，首次匹配
 * 找到返回字符串的首地址
 * 没找到返回NULL
 */
void test6() {
    char haystack[32] = "hello world";
    char needle[32] = "hello";
    char *p;
    p = strstr(haystack, needle);
    if(p != NULL) {
        printf("needle in haystacl");
    }else {
        printf("needle not in haystacl");
    }
}

/** 7.atoi/atol/atof:字符串转数值 */
/* int atoi(const char *nptr);
 * long atol(const char *nptr);
 * double atof(const char *nptr);
 * 将nptr指向的字符串转换为数值类型返回
 */
void test7() {
    char nptr[32] = "123";
    int i;
    i = atoi(nptr);
    printf("i = %d \n", i);
}

/** 8.strtok:字符串切割函数 */
/* char *strtok(char *str, const char *delim);
 * 字符串切割，按照delim指向字符串中的字符，切割str指向的字符
 * 在字符串str中寻找delim字符串，出现后就将其变为'\0'
 * 调用一次只切割一次，如果想再次切割则str要传NULL，意思是接着上次切割的位置继续切割
 */
void test8() {
    char str[100] = "111:222:333:444:5555";
    char *p = strtok(str, ":");
    printf("first p = %s \n", p);

    //后面将所有：都切割
    while((p = strtok(NULL, ":")) != NULL) {
        printf("p = %s \n", p);
    }
}

/** 9.格式化字符串操作函数 */
/* int sprintf(char *buf, const char *format, ...);
 * 输出到buf指定的内存区域
 *
 * int sscanf(const char *buf, const char *format, ...);
 * 从buf指定的内存区域中读取信息
 */
void test9() {
    char buf[20];
    sprintf(buf, "%d:%d:%d", 2020,11,7);
    printf("buf = %s \n", buf);

    int a, b, c;
    sscanf("2013:10:1", "%d:%d:%d", &a, &b, &c);
    printf("%d %d %d \n", a, b, c);
}
//sscanf高级用法
void testSscanf() {
    //1.跳过数据：%*s或%*d
    char buf1[20];
    sscanf("1234 5678", "%*s %s", buf1);
    printf("buf1=%s\n", buf1); //buf1=5678

    //2.读指定宽度的数据:%[width]s
    char buf2[20];
    sscanf("12345678", "%4s", buf2);
    printf("buf2=%s\n", buf2); //buf2=1234

    //3.支持正则表达式
    /* %[a-z] 匹配到a到z中任意字符
     * %[aBc] 匹配a、B、c中一员，贪婪性
     * %[^aFc] 匹配非a、F、c的任意字符，贪婪性
     * %[^a-z] 匹配非a-z以外的任意字符
     */
    char buf3[20];
    sscanf("agcd32DajfDdFF", "%[a-z]", buf3);
    printf("buf3=%s\n", buf3); //buf3=agcd
}

/** 10.const关键字 */
/* 修饰普通变量代表只读的意思
 * const int a = 100; 定义了一个只读变量a 值为100
 *
 * const修饰指针
 * const char *str 意思是str指向的内存不能通过str来修改
 * 用来保护str指向的内容
 * 但str的指向可以改变
 */

int main()
{
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6();
//    test7();
//    test8();
//    test9();
//    testSscanf();
    return 0;
}
