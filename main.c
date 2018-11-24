#include <stdio.h>
#include <stdlib.h>

int last_id = 0;
int last_scores = 0;

// 学生信息
struct student
{
    int id;
    char name[20];
    // 课程分数使用整型
    int c_lang_scores;
    int math_scores;
    int english_scores;
    int total_scores;
    int avg_scores;
    int ranking_scores;
    //char sex[10];
    //int age;
    struct student *next;
};

struct student_scores
{
    float c_lang_scores;
    float math_scores;
    float english_scores;
    float total_scores;
    float avg_scores;
    float ranking_scores;
};

struct ranking_scores
{
    int id;
    int ranking;
};

typedef struct student STU;

STU *head = NULL;

int get_menu_choice()
{
    int selection = 0;
    do
    {
        printf("1 - Add a record");
        printf("\n2 - Change a record");
        printf("\n3 - Delete a record");
        printf("\n4 - Quit");
        printf("\nEnter a selection: ");

        /* scanf("%d", &selection ); */

        //scanf_s("%d", &selection, 1);
        scanf("%d", &selection);
    } while ((selection < 1) || (selection > 4));

    return selection;
}

void add()
{
    ++last_id;
    int ch;

    STU *temp;
    temp = (STU *)malloc(sizeof(STU));
    if (!temp)
    {
        return;
    }

    printf("****************************************************\n");
    printf("1.姓名(必填)\n");
    // printf("2.性别(必填)\n");
    // printf("3.年龄(必填)\n");
    printf("****************************************************\n");

    printf("Enter 姓名: ");
    scanf("%s", temp->name);
    printf("Enter C语言成绩: ");
    scanf("%d", &(temp->c_lang_scores));
    printf("Enter 数学成绩: ");
    scanf("%d", &(temp->math_scores));
    printf("Enter 英语成绩: ");
    scanf("%d", &(temp->english_scores));

    temp->id = last_id;
    temp->total_scores = temp->c_lang_scores + temp->math_scores + temp->english_scores;
    temp->avg_scores = (temp->c_lang_scores + temp->math_scores + temp->english_scores) / 3;
    temp->ranking_scores = 0;

    temp->next = head;

    head = temp;

    /* Flushes input buffer from the newline from scanf() */
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    };

    printf("\n\n 继续...");
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    };

    return;
}

// 显示学生信息
void display()
{
    system("clear");

    if (head == NULL)
    {
        printf("无数据 \n");

        return;
    }

    STU *ptr = head;
    while (ptr != NULL)
    {
        printf("学生id: %d \t 姓名: %s \t C语言成绩: %d \t 数学成绩: %d \t 英语成绩: %d \t 总成绩: %d \t 平均分:%d \t 排名:%d \t \n", (ptr->id), (ptr->name), (ptr->c_lang_scores), (ptr->math_scores), (ptr->english_scores), (ptr->total_scores), (ptr->avg_scores), (ptr->ranking_scores));

        ptr = ptr->next;
    }
    printf("\n");
}

void rest(void)
{
    int ch;
    printf("Sleepy sleepy... zZZzZzZz\n");
    printf("You now feel awake again!\n");

    /* Flushes input buffer */
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    };

    printf("\n\nPress ENTER to continue.");
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    };

    return;
}

void load_menu()
{
    system("clear");

    int choice = 0;
    do
    {
        printf("\n");
        printf("****************************************************\n");
        printf("                       主菜单                        \n");
        printf("1. 添加学生 \n");
        printf("2. 显示学生列表 \n");
        printf("3. 更新成绩排行榜 \n");
        printf("4. 重置 \n");
        printf("100. 退出 \n");
        printf("****************************************************\n");
        printf("\n");

        printf("请输入序号: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            display();
            break;
        case 100:
            printf("退出程序 \n");
            exit(0);
            break;
        default:
            printf("无效参数! \n");
            break;
        }

    } while (choice != 3);
}

int main()
{
    // STU s1;
    // s1.id = 1;

    // int choice;

    // Call get_menu_choice() function

    // choice = get_menu_choice();

    load_menu();

    //printf("You have chosen Menu #%d\n", choice);

    //  printf("\n");

    return 0;
}
