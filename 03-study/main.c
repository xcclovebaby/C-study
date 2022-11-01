#include <stdio.h>

/** ==========================
 * 学习目录：
 * 1.if
 * 2.switch
 * 3.for
 * 4.while
 * 5.goto
 =============================*/

/** ================= if ==================== */
/* if语句：
 * 1.一般的if结构：
 *  if(1 < 2){
 *      xxxxx
 *  }else {
 *      xxxx
 *  }
 *
 * 2.if后面只有一行代码可以省略{}
 * if(a < b) a = b;
 */
void testIf1() {
    int a,b,max;
    printf("\n input two numbers: \n");

    //scanf()函数为获取键盘输入的字符
    scanf("%d%d", &a,&b);

    max = a;
    if(max < b) max = b;
    printf("max = %d \n", max);
}

/*前两种形式的if语句一般用于两个分支的情况. 当有多个分支选择时, 可采用if-else-if语句:
 * if(表达式) …;
 * eles if(表达式)
 * else …;
 */
void testIf2() {
    char c;
    printf("input a character: ");
    c = getchar();
    if(c < 32){
        printf("This is a control character \n");
    }else if(c >= '0' && c <= '9'){
        printf("This is a digit \n");
    }else if(c >= 'A' && c <= 'Z'){
        printf("This is a capital letter \n");
    }else if(c >= 'a' && c <= 'z'){
        printf("This is a small letter \n");
    }else {
        printf("This is an other character \n");
    }
}

/** ================= switch ==================== */
/* switch(表达式) 表达式只能是字符型和整型(short int long)
 * {
 *  case 表达式1：
 *      语句;
 *      break;
 *
 *  default:
 *      break;
 * }
 *
 * 运行顺序：将表达式的值和switch中表达式的值对比，
 * 如果相同,则执行该case中的语句,
 * 如果都不是,则执行default中的语句.
 * 注意break的使用,如果没有break则会一直往下执行！
 */
void testSwitch() {
    int a;
    printf("\n input one numbers: \n");
    scanf("%d", &a);
    switch(a) {
    case 5:
        printf("case 5: a = %d", a);
        break;
    case 6:
        printf("case 6: a = %d", a);
        break;
    case 10:
        printf("case 10: a = %d", a);
        break;
    default:
        printf("default: a = %d", a);
    }
}
/** ================= for ==================== */
/* for循环 for(表达式1; 表达式2; 表达式3) { 循环体 }
 * 执行顺序：
 * 1.第一次进入循环时，执行表达式1，但表达式1只执行一次
 * 2.表达式2是循环的条件，只有表达式2为真(true)的时候才去执行循环体，
 *   也就是说每次循环时都要去判断表达式2是否为真
 * 3.每次执行完循环体后，去执行表达式3
 *
 * 循环求0-100的和
 */
void testFor() {
    int a = 0;
    for(int i = 1; i <= 100; i++) {
        a += i;
    }
    printf("a = %d", a);
}

/** ================= while ==================== */
/* while循环 while(条件表达式) { 循环体 }
 * 进入while循环和每一次循环时会先判断条件表达式是否为真，为真进入循环，不为真退出循环
 *
 * 循环求0-100的和
 */
void testWhile() {
    int a = 0, b = 1;
    while (b <= 100) {
        a += b;
        b++;
    }
    printf("a = %d", a);
}

/** ================= do while ==================== */
/* do while循环 do { 循环体 } while(条件表达式);
 * do while和while不同的是do while首先执行循环体，
 * 再判断条件表达式是否为真
 * 所以do while始终都会先执行一次
 */
void testDoWhile() {
    int a = 1;
    do {
        printf("a = %d \n", a);
        a += 1;
    } while(a == 1);
    printf("a = %d \n", a);
}

/** ================= goto ==================== */
/* goto循环 主要用于在一个函数里面实现代码跳转
 * goto 跳转标识符;
 * ... ...
 * 跳转标识符:
 * ... ...
 * 代码执行时，到了goto这里会略过下面的代码，
 * 一直跳转到 跳转标识符后面得代码
 */
void testGoTo() {
    printf("1111111111111");
    goto next;
    printf("2222222222222");
    printf("3333333333333");
    next:
    printf("4444444444444");


    //使用goto实现1到100的累加和
    int i = 1, sum = 0;
    JOOP:
        sum += i;
        i++;
    if(i <= 100) {
        goto JOOP;
    }
    printf("\n testGoTo: sum = %d \n", sum);
}

int main()
{
    //testIf1();
    //testIf2();
//    testSwitch();
//    testFor();
//    testWhile();
//    testDoWhile();
    testGoTo();
    return 0;
}
