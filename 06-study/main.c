#include <stdio.h>

/** ==========================
 * 学习目录：
 * 1.malloc函数
 * 2.free函数
 * 3.calloc函数
 * 4.realloc函数
 * 5.内存泄漏
 * ==========================*/

/** 1.malloc */
/* void *malloc(unsigned int size);
 * 在内存的动态存储区（堆区）分配一个长度为size字节的连续区域
 * 函数原型返回 void*指针，使用时必须做相应的类型转换
 * 一般使用memset初始化
 * 成功返回开辟空间的首地址
 * 失败则返回NULL
 *
 * 注意：
 * 1.在调用malloc之后，一定要判断是否申请成功
 * 2.如果多次调用malloc申请内存，第1次和第2次申请的内存不一定是连续的
 */
char *getStr() {
    //如果使用局部变量，在栈内存中开辟了空间，随着函数的结束，局部变量也被释放
//    char str[100] = "hello";

    //静态区虽然不会随着函数释放空间，如果一个变量不经常使用的话也是浪费内存
//    static char str[100] = "hello";

    //手动申请内存空间，使用完后手动释放，这样比较灵活
    //使用malloc函数需要强制类型转换
    char *str = (char *)malloc(100 * sizeof(char));
    str[0] = 'h';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 'o';
    str[5] = '\0';
    return str;
}

void testMalloc() {
    char *p;
    p = getStr();
    printf("p = %s \n", p);
}

/** 2.free函数 */
/* void free(void *ptr);
 * free函数释放ptr指向的内存
 * 注意：
 * 1.ptr指向的内存必须是malloc、calloc、realloc动态申请的内存
 * 2.free(p)函数释放空间后，因为没有给p赋值，所以p还是指向原来动态申请的内存。但内存已经不能再用了，所以p变成野指针了，一般释放完毕会给p赋值为null
 * 3.一块动态内存只能free一次
 */
void testFree() {
    char *p;
    p = getStr();
    printf("p = %s \n", p);
    //释放内存
    free(p);
    //防止野指针
    p = NULL;
    printf("p = %s \n", p);
}

/** 3.calloc函数 */
/* void *calloc(size_t nmemb, size_t size);
 * size_t实际上是无符号整型，它在头文件中使用typedef定义出来的。
 * calloc函数在内存中，申请nmemb块，每个大小为size字节的区域
 * 成功返回区域首地址
 * 失败返回NULL
 *
 * 注意：
 * malloc和calloc都是用来申请内存的
 * malloc申请的内存，内存中存放的内容是随机的，不确定的
 * calloc申请的内存中内容为0
 */
void testCalloc() {
    //calloc动态申请1块长度为100字节的区域
    char *p = (char *)calloc(1, 100);
    //strcpy(p, "ABC"); //将字符串拷贝到p所指向的内存中
    strcpy(p, "ABC");
    printf("p = %s \n", p);
}

/** 4.realloc函数 */
/* void *realloc(void *s, unsigned int newsize);
 * 在s指向的内存基础上重新申请内存，新的内存大小为newsize字节，
 * 如果原先内存后面有足够大的空间，就追加，如果后面的内存不够用，则realloc函数会在堆找一个newsize字节大小的内存申请，
 * 将原先内存中的内容copy过来，然后释放原先内存，返回一个新的地址
 * 如果newsize比原先内存小，则会释放原先内存后面的存储空间，只留下前面newsize字节
 *
 * 返回值：新申请的内存首地址
 *
 * 调用malloc和calloc函数单次申请的内存是连续的，两次申请的两块内存不一定连续。
 * 有些时候，我先使用malloc或calloc申请了一块内存，我还想在原先内存的基础上挨着申请一块内存，
 * 或者我开始申请了一块内存，后来我想释放后面的一些内存，realloc函数能帮助我们来解决
 */
void testRealloc() {
    //动态申请100个字节的内存
    char *p = (char *)malloc(100 * sizeof(char));
    strcpy(p, "ABC");
    printf("p = %s \n", p);
    //在后面追加50个字节
    p = (char *)realloc(p, 150);//p指向内存的大小为150字节
    printf("p = %s \n", p);
}

/** 5.内存泄漏 */
/* 申请的内存首地址丢了，找不到了，没办法使用也没办法释放，这块内存就被泄漏了。
 */
void test1() {//这个函数被频繁调用而不释放内存，也会造成内存泄漏
    //申请100个字节大小的内存
    char *p = (char *)malloc(100);
    printf("p = %p \n", p);
    //p又指向了字符串常量区的内存地址
    //从此以后再也找不到曾经申请的100个字节的内存了，则内存泄漏
//    p = "hello world";

    //这时候手动释放一下就解决了
    free(p);
    p = "hello world";

    printf("p = %p \n", p);


}

int main()
{
//    testMalloc();
//    testFree();
//    testCalloc();
//    testRealloc();
    test1();
    return 0;
}
