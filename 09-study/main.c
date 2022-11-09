#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** ==========================
 * 学习目录：
 * 1.链表的创建
 * 2.链表的遍历
 * 3.链表的释放(递归)
 * 4.链表的释放(循环)
 * 5.链表节点的查找
 * 6.链表节点的删除
 * 7.链表节点的插入
 * 8.链表的排序(冒泡排序)
 * ==========================*/

/** 1.链表的创建 */
typedef struct student{
    //数据域
    int num; //编号
    double score; //成绩
    char name[20]; //姓名
    //指针域
    struct student *next; //链表保存后置位内存地址
}STU;

//单向链表尾插法
//这里使用二级指针作为形参是要保存链表头元素的地址值，如果使用一级指针则无法定位到链表头元素
void link_create_head(STU **p_head, STU *p_new) {
    STU *p_mov = *p_head;
    if(*p_head == NULL) { //首次时传入的p_new为链表的第一个元素 并给p_head赋值内存地址
        *p_head = p_new;
        p_new->next = NULL;
    } else {
        while(p_mov->next != NULL) { //有了链表头以后循环遍历链表的最后一位元素，在尾部插入下一元素
            p_mov = p_mov->next;
        }
        p_mov->next = p_new;
        p_new->next = NULL;
    }
}

/** 2.链表的遍历 */
void link_print(STU *head) {
    STU *p_mov = head;
    while(p_mov != NULL) {
        printf("num=%d,score=%2f,name=%s\n", p_mov->num, p_mov->score, p_mov->name);
        p_mov = p_mov->next;
    }
}

/** 3.链表的释放(递归) */
void free_link(STU *head) {
    STU *p_mov = head;
    if(p_mov->next != NULL) {
        free_link(p_mov->next);
    }
    printf("free num=%d\n", p_mov->num);
    free(p_mov);
    p_mov = NULL;
}

/** 4.链表的释放(循环) */
void free_link_2(STU **head){
    STU *pd;
    while(*head != NULL) {
        pd = *head;
        *head = (*head)->next;
        printf("free num=%d\n", pd->num);
        free(pd);
    }
}

/** 5.链表节点的查找 */
STU *linck_search_num(STU *head, int num) {
    STU *p_mov = head;
    while(head != NULL) {
        if(p_mov->num == num) {
            return p_mov;
        }
        p_mov = p_mov->next;
    }
    return NULL;
}

/** 6.链表节点的删除 */
void link_delete_num(STU **p_head, int num) {
    printf("link_delete_num: num=%d\n", num);
    STU *p_mov = *p_head;
    if(p_mov == NULL) return;
    if(num == 0) {
        *p_head = p_mov->next;
        free(p_mov);
        return;
    }else {
        STU *p;
        while (p_mov->next != NULL) {
            if(p_mov->num == num) {
                p->next = p_mov->next;
                free(p_mov);
            }else {
                p = p_mov;
                p_mov = p_mov->next;
            }
        }
    }
}

/** 7.链表节点的插入 */
void link_add(STU **p_head, int num, STU *p_new) {
    STU *p_mov = *p_head;
    if(p_mov == NULL) return;
    if(num == 0) {
        *p_head = p_new;
        (*p_head)->next = p_mov;
        return;
    }else {
        STU *p;
        while (p_mov->next != NULL) {
            if(p_mov->num == num) {
                p_new->next = p_mov;
                p->next = p_new;
                return;
            }else {
                p = p_mov;
                p_mov = p_mov->next;
            }
        }
    }
}

/** 8.链表的排序(冒泡排序) */
void link_sort(STU *p_head) {
    STU *p1 = p_head,*p2, temp;

    while(p1->next != NULL) {
        p2 = p1->next;
        while(p2 != NULL) {
            if(p2->num < p1->num) {
                temp = *p2;
                *p2 = *p1;
                *p1 = temp;

                temp.next = p2->next;
                p2->next = p1->next;
                p1->next = temp.next;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
}

/** 9.双向链表的创建和遍历 */


int main()
{
    STU *head = NULL, *p_new = NULL;
    int num;
    printf("input init number:\n");
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        p_new = (STU *)malloc(sizeof(STU)); //申请内存
        strcpy(p_new->name, "init-name");
        p_new->num = i;
        p_new->score = i * 10.00;
        link_create_head(&head, p_new); //创建链表
    }
    link_print(head); //循环遍历链表
    printf("\n\n");

    STU *p = linck_search_num(head, 2); //根据num在链表内检索
    printf("linck_search_num: num=%d,score=%2f,name=%s\n", p->num, p->score, p->name);
    printf("\n\n");

    link_delete_num(&head, 1);
    link_print(head); //循环遍历链表
    printf("\n\n");

    STU *add = (STU *)malloc(sizeof(STU));
    add->num = 20;
    strcpy(add->name, "ABC");
    add->score = 75.12;
    link_add(&head, 2, add);
    link_print(head); //循环遍历链表
    printf("\n\n");

    link_sort(head);
    link_print(head); //循环遍历链表
    printf("\n\n");

    free_link(head); //释放链表
    return 0;
}
