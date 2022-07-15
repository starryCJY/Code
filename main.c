#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
typedef long long LL; 
typedef struct s
{
	char name[20];
	LL num;
	int sex;
	int Chinese,Math,English,Cross_score,Moral,tearcher_score;
	int ranking,end_ranking;
	double ave_score,end_score;
	char address[50];
	char phone_number[20]; 
	struct s *next;
}student;
int class_num;
student *head,stu[1000],stu0;
FILE *pp;
int main()
{
	void print_menu();
	void print_welcome(); 
	void create_class();
	void modify_stu();
	void delete_stu();
	void search_stu();
	void insert_stu();
	void all_stu();
	void conserve();
	void read_data(); 
	student *add_stu();
	void print_bye();
	void bless();
	
	print_welcome();
	read_data();
	int flag=1;
	while(flag)
	{
		print_menu();
		printf("请输入数字指令，请选择：");
		int command;
		scanf("%d",&command);
		switch(command)
		{
			case 1:
			{
				create_class();
				break;
			}
			case 2:
			{
				if(class_num==0)
				{
					printf("还未创建班级，请先创建班级!\n");
					break;
				}
				head=add_stu();
				conserve();
				break;
			}
			case 3:
			{
				modify_stu();
				conserve();
				break;
			}
			case 4:
			{
				insert_stu();
				conserve();
				break;
			}
			case 5:
			{
				if(head==NULL)
				{
					printf("警告，系统中学生数量为0\n");
					break;
				}
				delete_stu();
				conserve();
				break;	
			}
			case 6:
			{
				search_stu();
				break;
			}
			case 7:
			{
				all_stu();
				break;
			}
			case 0:
			{
				flag=0;
				break;
			}
			default :
			{
				printf("指令键入错误，请检查后重试\n"); 
			}
		}
		if(flag)printf("按任意健继续");
    	if(flag)getch();
    	system("cls");
	}
	print_bye();
	bless();
	system("pause"); 
	return 0;
}
void print_welcome()
{
    printf("__/\\\\\\_______________________/\\\\\\___/\\\\\\\\\\\\\\\\\\\\\\\\\\\\____/\\\\\\__________________/\\\\\\\\\\\\\\\\\\_________/\\\\\\\\\\\\\\\\\\\\________/\\\\\\\\____________/\\\\\\\\_____/\\\\\\\\\\\\\\\\\\\\\\\\\\\\_\n");
    printf(" _\\//\\\\\\_____________________/\\\\\\___\\/\\\\\\//////////____\\/\\\\\\_______________/\\\\\\////////_______/\\\\\\/////////\\\\\\_____\\/\\\\\\\\\\\\________/\\\\\\\\\\\\____\\/\\\\\\//////////__\n");
    printf("   _\\//\\\\\\________/\\\\\\_______/\\\\\\____\\/\\\\\\______________\\/\\\\\\_____________/\\\\\\/______________/\\\\\\/________\\///\\\\\\___\\/\\\\\\//\\\\\\____/\\\\\\//\\\\\\____\\/\\\\\\____________\n");
    printf("     _\\//\\\\\\_____/\\\\\\\\\\\\\\____/\\\\\\_____\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\___\\/\\\\\\____________\\/\\\\\\______________\\/\\\\\\___________\\/\\\\\\___\\/\\\\\\\\///\\\\\\/\\\\\\/_\\/\\\\\\____\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\_\n");
    printf("       _\\//\\\\\\___/\\\\\\_//\\\\\\__/\\\\\\______\\/\\\\\\//////////____\\/\\\\\\____________\\/\\\\\\______________\\/\\\\\\___________\\/\\\\\\___\\/\\\\\\__\\///\\\\\\/___\\/\\\\\\____\\/\\\\\\//////////__\n");
    printf("         _\\//\\\\\\_/\\\\\\__\\//\\\\\\/\\\\\\_______\\/\\\\\\______________\\/\\\\\\____________\\///\\\\\\____________\\///\\\\\\________/\\\\\\/____\\/\\\\\\____\\///_____\\/\\\\\\____\\/\\\\\\____________\n");
    printf("           _\\//\\\\\\\\\\/____\\//\\\\\\\\\\________\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\___\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\___\\///\\\\\\\\\\\\\\\\\\\\\\____\\///\\\\\\\\\\\\\\\\\\\\\\/______\\/\\\\\\_____________\\/\\\\\\____\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\_\n");
    printf("             _\\/////_______\\/////_________\\//////////////____\\//////////////______\\///////////_______\\///////////________\\///______________\\///_____\\//////////////__\n"),
    Sleep(4000);
    system("cls");
}
void print_bye()
{
    printf("__/\\\\\\\\\\\\\\\\\\\\\\\\\\________/\\\\\\____________/\\\\\\____/\\\\\\\\\\\\\\\\\\\\\\\\\\\\_\n"),
    printf(" _\\/\\\\\\/////////\\\\\\_____\\///\\\\\\________/\\\\\\/____\\/\\\\\\//////////__\n"),
    printf("  _\\/\\\\\\_______\\/\\\\\\_______\\///\\\\\\____/\\\\\\/______\\/\\\\\\____________\n"),
    printf("   _\\/\\\\\\\\\\\\\\\\\\\\\\\\\\/__________\\///\\\\\\/\\\\\\/________\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\_\n"),
    printf("    _\\/\\\\\\/////////\\\\\\___________\\///\\\\\\/__________\\/\\\\\\//////////__\n"),
    printf("     _\\/\\\\\\_______\\/\\\\\\_____________\\/\\\\\\___________\\/\\\\\\____________\n"),
    printf("      _\\/\\\\\\\\\\\\\\\\\\\\\\\\\\/______________\\/\\\\\\___________\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\_\n"),
    printf("       _\\/////////////________________\\///____________\\//////////////__\n"),
    Sleep(4000);
    system("cls");
}
void read_data()
{
	student *q,*tail; 
	head=q=tail=NULL;
	pp=fopen("student.txt","r");
	class_num--;
	int i=1; 
	while(1)
	{
		q=(student *)malloc(sizeof(student));
		q->next=NULL; 
		fscanf(pp,"%lld%s%d%s%s%d%d%d%d%d%d%lf%lf%d%d",&q->num,q->name,&q->sex,q->address,q->phone_number,&q->Chinese,&q->Math,&q->English,&q->Cross_score,&q->Moral,&q->tearcher_score,&q->ave_score,&q->end_score,&q->ranking,&q->end_ranking);
		strcpy(stu[i].address,q->address);
		strcpy(stu[i].name,q->name);
		strcpy(stu[i].phone_number,q->phone_number);
		stu[i].ave_score=q->ave_score;
		stu[i].Chinese=q->Chinese;
		stu[i].Cross_score=q->Cross_score;
		stu[i].end_ranking=q->end_ranking;
		stu[i].end_score=q->end_score;
		stu[i].English=q->English;
		stu[i].Math=q->Math;
		stu[i].Moral=q->Moral;
		stu[i].num=q->num;
		stu[i].ranking=q->ranking;
		stu[i].sex=q->ranking;
		stu[i].tearcher_score=q->tearcher_score; 
		i++;
		class_num++;
		if(feof(pp))break;
		if(head==NULL)
		{
			head=q;
			tail=q;
		}
		else
		{
			tail->next=q;
			tail=q;
		}
		
	}
	fclose(pp);
} 
void  bless()
{
	printf(
		"┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐\n"
		"│Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│  ┌┐    ┌┐    ┌┐\n"
		"└───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘  └┘    └┘    └┘\n"
		"┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐\n"
		"│~ `│! 1│@ 2│# 3│$ 4│%% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│ │ NL│ / │ * │ - │\n"
		"├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤\n"
		"│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \  │ │Del│End│PDn│ │ 7 │ 8 │ 9 │   │\n"
		"├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┤ + │\n"
		"│ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│  '│ Enter  │               │ 4 │ 5 │ 6 │   │\n"
		"├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐     ├───┼───┼───┼───┤\n"
		"│ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑│     │ 1 │ 2 │ 3 │   │\n"
		"├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤ E││\n"
		"│ Ctrl│    │ Alt│         Space         │ Alt│    │    │Ctrl│ │ ←│ ↓│ →│ │   0   │ . │←─┘ \n"
		"└─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘\n"
		"\n                键盘在手                                              永无BUG\n\n\n"
	 );
}
void print_menu()
{
	printf("--------------------------------                      ---------------------------------------------------\n");
	printf("|        学生综合测评系统      |                      |                     温馨提示                    |\n");
	printf("--------------------------------                      ---------------------------------------------------\n");
	printf("|         1.创建班级           |                      |1.请务必窗口全屏化，以更好的使用本系统           |\n");      
	printf("|         2.添加学员信息       |                      |2.初次使用系统，请先创建班级后再增添学员信息     |\n");
	printf("|         3.修改学员信息       |                      |3.按菜单提示键入数字指令                         |\n"); 
	printf("|         4.插入学员信息       |                      |4.本系统用于管理学生信息，支持增删查改           |\n");
	printf("|         5.删除学员信息       |                      |5.每次增加、修改、删除信息后，系统会自动保存信息 |\n");
	printf("|         6.查询学员信息       |                      |6.感谢您的使用！！！                             |\n");
	printf("|         7.浏览学员信息       |                      |                                                 |\n");
	printf("|         0.退出系统           |                      |                                                 |\n");
	printf("--------------------------------                      |                                                 |\n");
	printf("| 作者：程吉雨 学号：219074275 |                      |                                                 |\n");
	printf("--------------------------------                      |                                                 |\n");
	return ;
}
void insert_stu()
{
	printf("\n请输入需插入学生的学号：");
	scanf("%lld",&stu[class_num+1].num);
	printf("请输入需插入学生的姓名：");
	scanf("%s",stu[class_num+1].name);
	printf("请输入需插入学生的性别(1表示男，0表示女)：");
	scanf("%d",&stu[class_num+1].sex);
	printf("请输入需插入学生的家庭住址：");
	scanf("%s",stu[class_num+1].address);
	printf("请输入需插入学生的联系电话：");
	scanf("%s",stu[class_num+1].phone_number);
	printf("请输入需插入学生的语文成绩：");
	scanf("%d",&stu[class_num+1].Chinese);
	printf("请输入需插入学生的数学成绩：");
	scanf("%d",&stu[class_num+1].Math);
	printf("请输入需插入学生的外语成绩：");
	scanf("%d",&stu[class_num+1].English);
	printf("请输入需插入学生的同学互评分：");
	scanf("%d",&stu[class_num+1].Cross_score);
	printf("请输入需插入学生的品德成绩：");
	scanf("%d",&stu[class_num+1].Moral); 
	printf("请输入需插入学生的任课教师评分：");
	scanf("%d",&stu[class_num+1].tearcher_score);
	stu[class_num+1].ave_score=(stu[class_num+1].Chinese+stu[class_num+1].Math+stu[class_num+1].English)*1.0/3;
	stu[class_num+1].end_score=stu[class_num+1].ave_score*0.6+stu[class_num+1].Cross_score*0.1+stu[class_num+1].Moral*0.1+stu[class_num+1].tearcher_score*0.2;
	class_num++;
	int i,j;
	for(i=1;i<class_num;i++)
	{
		for(j=1;j<class_num+1-i;j++)
		{
			if(stu[j].ave_score<stu[j+1].ave_score)
			{
				student t;
				t=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=t;
			}
		}
	}
	for(i=1;i<=class_num;i++)
	{
		stu[i].ranking=i;
	}
	for(i=1;i<class_num;i++)
	{
		for(j=1;j<class_num+1-i;j++)
		{
			if(stu[j].end_score<stu[j+1].end_score)
			{
				student t;
				t=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=t;
			}
		}
	}
	for(i=1;i<=class_num;i++)
	{
		stu[i].end_ranking=i;
	}
	int t=class_num;
	student *q=head,*p;
	p=(student *)malloc(sizeof(student));
	p->next=NULL;
	p->num=stu[t].num;
	strcpy(p->name,stu[t].name);
	p->sex=stu[t].sex;
	strcpy(p->address,stu[t].address);
	strcpy(p->phone_number,stu[t].phone_number);
	p->Chinese=stu[t].Chinese;
	p->Math=stu[t].Math;
	p->English=stu[t].English;
	p->ave_score=stu[t].ave_score;
	p->ranking=stu[t].ranking;
	p->Cross_score=stu[t].Cross_score;
	p->Moral=stu[t].Moral;
	p->tearcher_score=stu[t].tearcher_score;
	p->end_score=stu[t].end_score;
	p->end_ranking=stu[t].end_ranking;
	if(stu[t].num<head->num)
	{
		p->next=head;
		head=p;
		return ;
	}
	while(q->next!=NULL&&q->next->num<p->num)
	{
		q=q->next;
	}
	if(q->next!=NULL)
	{
		p->next=q->next;
		q->next=p;
	}
	else q->next=p;
	printf("插入成功！\n");
}
void search_stu()
{
	int n,flag6=1;
	printf("\n按何种方式检索：\n"); 
	printf("1.学号\n"); 
	printf("2.姓名\n");
	printf("3.性别\n");
	scanf("%d",&n);
	student *q=head;
	
	switch(n)
	{
		case 1:
		{
			printf("请输入所查询的学号：");
			LL number;
			scanf("%lld",&number);
			printf("\n|学号      |姓名  |性别  |家庭住址    |联系电话      |语文  |数学  |外语  |互评分|品德  |教师评分|考试成绩|综合测评|考试名次|综合测评名次    \n");
			while(q)
			{
				if(q->num==number)
				{
					flag6=0;
					printf("|%-10lld|%-6s|%-6d|%-12s|%-14s|%-6d|%-6d|%-6d|%-6d|%-6d|%-8d|%-8.2lf|%-8.2lf|%-8d|%-12d\n",q->num,q->name,q->sex,q->address,q->phone_number,q->Chinese,q->Math,q->English,q->Cross_score,q->Moral,q->tearcher_score,q->ave_score,q->end_score,q->ranking,q->end_ranking);
				}
				q=q->next;
			}
			break;
		}
		case 2:
		{
			printf("请输入所查询的姓名：");
			char names[50];
			scanf("%s",names);
			printf("\n|学号      |姓名  |性别  |家庭住址    |联系电话      |语文  |数学  |外语  |互评分|品德  |教师评分|考试成绩|综合测评|考试名次|综合测评名次    \n");
			while(q)
			{
				if(strcmp(names,q->name)==0)
				{
					flag6=0;
					printf("|%-10lld|%-6s|%-6d|%-12s|%-14s|%-6d|%-6d|%-6d|%-6d|%-6d|%-8d|%-8.2lf|%-8.2lf|%-8d|%-12d\n",q->num,q->name,q->sex,q->address,q->phone_number,q->Chinese,q->Math,q->English,q->Cross_score,q->Moral,q->tearcher_score,q->ave_score,q->end_score,q->ranking,q->end_ranking);
				}
				q=q->next;
			}
		 	break;
		}
		case 3:
		{
			printf("请输入所查询的性别：");
			int sexs;
			scanf("%d",&sexs);
			printf("\n|学号      |姓名  |性别  |家庭住址    |联系电话      |语文  |数学  |外语  |互评分|品德  |教师评分|考试成绩|综合测评|考试名次|综合测评名次    \n");
			while(q)
			{
				if(q->sex==sexs)
				{
					flag6=0;
					printf("|%-10lld|%-6s|%-6d|%-12s|%-14s|%-6d|%-6d|%-6d|%-6d|%-6d|%-8d|%-8.2lf|%-8.2lf|%-8d|%-12d\n",q->num,q->name,q->sex,q->address,q->phone_number,q->Chinese,q->Math,q->English,q->Cross_score,q->Moral,q->tearcher_score,q->ave_score,q->end_score,q->ranking,q->end_ranking);
				}
				q=q->next;
			} 
			break;
		}
		default :printf("指令键入错误，请检查后重试！\n");
	}
	if(flag6==1)printf("查无此人！\n\n");
	return ;
}
void delete_stu()
{
	int flag4=1;
	printf("请输入需要删除的学员的学号：");
	LL number;
	scanf("%lld",&number);
	student *q=head;
	if(q->num==number)
	{
		head=head->next;
		flag4=0;
		free(q);
		printf("删除成功！\n"); 
		class_num--;
		return ;
	}
	while(q->next!=NULL&&q->next->num!=number)
	{
		q=q->next;
	}
	if(q->next!=NULL&&q->next->num==number)flag4=0;
	if(!flag4)
	{
		class_num--;
		printf("删除成功！\n"); 
	}
	else 
	{
		printf("查无此人!!!\n");
		return ;
	}
	student *q1=q->next;
	q->next=q->next->next;
	free(q1);
	return ; 
}
void modify_stu()
{
	int flag=0;
	LL number;
	printf("请输入需要修改的学员的学号");
	scanf("%lld",&number);
	student *p=head;
	while(p)
	{
		if(number==p->num)
		{
			flag=1;
			break;
		}
		p=p->next;
	}
	if(flag)
	{
		printf("\n|学号      |姓名  |性别  |家庭住址    |联系电话      |语文  |数学  |外语  |互评分|品德  |教师评分    \n");
		printf("|%-10lld|%-6s|%-6d|%-12s|%-14s|%-6d|%-6d|%-6d|%-6d|%-6d|%-6d\n\n",p->num,p->name,p->sex,p->address,p->phone_number,p->Chinese,p->Math,p->English,p->Cross_score,p->Moral,p->tearcher_score);
		int flag2=1;
		while(1&&flag2==1)
		{
			int flag3=1;
			printf("请选择修改项\n");
			printf("1.姓名\n");
			printf("2.性别\n"); 
			printf("3.家庭住址\n");
			printf("4.联系电话\n");
			printf("5.语文成绩\n");
			printf("6.数学成绩\n");
			printf("7.外语成绩\n");
			printf("8.同学互评分\n");
			printf("9.品德成绩\n");
			printf("10.任课教师评分\n");
			printf("0.修改结束\n");
			printf("请选择：");
			int n;
			scanf("%d",&n);
			switch(n)
			{
				case 1:
				{
					printf("请输入新的姓名：");
					scanf("%s",p->name); 
					break;
				}
				case 2:
				{
					if(p->sex=1)p->sex=0;
					else p->sex=1;
					break;
				}
				case 3:
				{
					printf("请输入新的家庭住址：");
					scanf("%s",p->address); 
					break;
				}
				case 4:
				{
					printf("请输入新的联系电话：");
					scanf("%s",p->phone_number);
					break; 
				}
				case 5:
				{
					printf("请输入新的语文成绩：");
					scanf("%s",&p->Chinese);
					break;
				}
				case 6:
				{
					printf("请输入新的数学成绩：");
					scanf("%d",&p->Math);
					break; 
				}
				case 7:
				{
					printf("请输入新的外语成绩：");
					scanf("%d",&p->English); 
					break;
				}
				case 8:
				{
					printf("请输入新的同学互评分：");
					scanf("%d",&p->Cross_score);
					break; 
				}
				case 9:
				{
					printf("请输入新的品德成绩：");
					scanf("%d",&p->Moral);
					break;
				}
				case 10:
				{
					printf("请输入新的任课教师评分：");
					scanf("%d",&p->tearcher_score);
					break;
				}
				case 0:
				{
					flag2=0;
					break;
				}
				default:
				{
					printf("指令错误，请重新输入");
					flag3=0;
					break; 
				}
			}
			if(flag3&&flag2!=0)printf("修改成功！\n"); 
			printf("请按任意键继续\n\n");
			getch();
		} 
		printf("\n修改完成后 该学生信息如下:\n\n");
		printf("\n|学号      |姓名  |性别  |家庭住址    |联系电话      |语文  |数学  |外语  |互评分|品德  |教师评分    \n");
		printf("|%-10lld|%-6s|%-6d|%-12s|%-14s|%-6d|%-6d|%-6d|%-6d|%-6d|%-6d\n\n",p->num,p->name,p->sex,p->address,p->phone_number,p->Chinese,p->Math,p->English,p->Cross_score,p->Moral,p->tearcher_score); 
	}
	else 
	{
		printf("查无此人!\n");
	}
	return ; 
}
void conserve()
{
	pp=fopen("student.txt","w");
	student *q=head;
	while(q)
	{
		fprintf(pp,"%lld %s %d %s %s %d %d %d %d %d %d %lf %lf %d %d\n",q->num,q->name,q->sex,q->address,q->phone_number,q->Chinese,q->Math,q->English,q->Cross_score,q->Moral,q->tearcher_score,q->ave_score,q->end_score,q->ranking,q->end_ranking);
		q=q->next;
	}
	fclose(pp);
} 
void create_class()
{
	if(class_num!=0)
	{
		printf("您已创建过班级,班级中有%d人\n",class_num);
		return ;
	} 
	printf("请输入需要创建的班级的人数：");
	scanf("%d",&class_num);
	if(class_num<=0)
	{
		printf("不合法！，请重新创建班级\n");
	} 
	else printf("已初始化班级人数为%d人\n",class_num);
}
student *add_stu()
{
	int i,j;
	for(i=1;i<=class_num;i++)
	{
		printf("请输入第%d个学生的学号：",i);
		scanf("%lld",&stu[i].num);
		printf("请输入第%d个学生的姓名：",i);
		scanf("%s",stu[i].name);
		stu[i].sex=-1;
		while(stu[i].sex<0||stu[i].sex>1)
		{
			printf("请输入第%d个学生的性别(1表示男，0表示女)：",i);
			scanf("%d",&stu[i].sex);
			if(stu[i].sex<0||stu[i].sex>1)
			{
				printf("不合法，请重新输入！\n");	
			} 
		}
		printf("请输入第%d个学生的家庭住址：",i);
		scanf("%s",stu[i].address);
		printf("请输入第%d个学生的联系电话：",i);
		scanf("%s",stu[i].phone_number);
		stu[i].Chinese=-1;
		while(stu[i].Chinese<0||stu[i].Chinese>100)
		{
			printf("请输入第%d个学生的语文成绩(0~100)：",i);
			scanf("%d",&stu[i].Chinese);
			if(stu[i].Chinese<0||stu[i].Chinese>100)
			{
				printf("不合法，请重新输入！\n");	
			}	
		}
		stu[i].Math=-1;
		while(stu[i].Math<0||stu[i].Math>100)
		{
			printf("请输入第%d个学生的数学成绩(0~100)：",i);
			scanf("%d",&stu[i].Math);
			if(stu[i].Math<0||stu[i].Math>100)
			{
				printf("不合法，请重新输入！\n");	
			}	
		}
		stu[i].English=-1;
		while(stu[i].English<0||stu[i].English>100)
		{
			printf("请输入第%d个学生的外语成绩(0~100)：",i);
			scanf("%d",&stu[i].English);
			if(stu[i].English<0||stu[i].English>100)
			{
				printf("不合法，请重新输入！\n");	
			}	
		} 
		stu[i].Cross_score=-1;
		while(stu[i].Cross_score<0||stu[i].Cross_score>100)
		{
			printf("请输入第%d个学生的同学互评分(0~100)：",i);
			scanf("%d",&stu[i].Cross_score);
			if(stu[i].Cross_score<0||stu[i].Cross_score>100)
			{
				printf("不合法，请重新输入！\n");	
			}	
		} 
		stu[i].Moral=-1;
		while(stu[i].Moral<0||stu[i].Moral>100)
		{
			printf("请输入第%d个学生的品德成绩(0~100)：",i);
			scanf("%d",&stu[i].Moral); 
			if(stu[i].Moral<0||stu[i].Moral>100)
			{
				printf("不合法，请重新输入！\n");	
			}	
		} 
		stu[i].tearcher_score=-1;
		while(stu[i].tearcher_score<0||stu[i].tearcher_score>100)
		{
			printf("请输入第%d个学生的任课教师评分(0~100)：",i);
			scanf("%d",&stu[i].tearcher_score);
			if(stu[i].tearcher_score<0||stu[i].tearcher_score>100)
			{
				printf("不合法，请重新输入！\n");	
			}	
		} 
		stu[i].ave_score=(stu[i].Chinese+stu[i].Math+stu[i].English)*1.0/3;
		stu[i].end_score=stu[i].ave_score*0.6+stu[i].Cross_score*0.1+stu[i].Moral*0.1+stu[i].tearcher_score*0.2;
		printf("\n");
	}
	for(i=1;i<class_num;i++)
	{
		for(j=1;j<class_num+1-i;j++)
		{
			if(stu[j].ave_score<stu[j+1].ave_score)
			{
				student t;
				t=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=t;
			}
		}
	}
	for(i=1;i<=class_num;i++)
	{
		stu[i].ranking=i;
	}
	for(i=1;i<class_num;i++)
	{
		for(j=1;j<class_num+1-i;j++)
		{
			if(stu[j].end_score<stu[j+1].end_score)
			{
				student t;
				t=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=t;
			}
		}
	}
	for(i=1;i<=class_num;i++)
	{
		stu[i].end_ranking=i;
	}
	for(i=1;i<class_num;i++)
	{
		for(j=1;j<class_num+1-i;j++)
		{
			if(stu[j].num>stu[j+1].num)
			{
				student t=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=t;
			}
		}
	}
	
	student *tail,*p;
	head=tail=NULL;
	for(i=1;i<=class_num;i++)
	{
		p=(student *)malloc(sizeof(student));
		p->next=NULL;
		p->num=stu[i].num;
		strcpy(p->name,stu[i].name);
		p->sex=stu[i].sex;
		strcpy(p->address,stu[i].address);
		strcpy(p->phone_number,stu[i].phone_number);
		p->Chinese=stu[i].Chinese;
		p->Math=stu[i].Math;
		p->English=stu[i].English;
		p->ave_score=stu[i].ave_score;
		p->ranking=stu[i].ranking;
		p->Cross_score=stu[i].Cross_score;
		p->Moral=stu[i].Moral;
		p->tearcher_score=stu[i].tearcher_score;
		p->end_score=stu[i].end_score;
		p->end_ranking=stu[i].end_ranking;
		if(head==NULL)
		{
			head=p;
			tail=p;
		}
		else 
		{
			tail->next=p;
			tail=p;
		}
	}
	printf("添加学员信息成功！\n"); 
	return head;
}
void all_stu()
{
	printf("\n查询成功！\n\n");
	student *q=head;
	printf("\n|学号      |姓名  |性别  |家庭住址    |联系电话      |语文  |数学  |外语  |互评分|品德  |教师评分|考试成绩|综合测评|考试名次|综合测评名次    \n");
	while(q)
	{
		printf("|%-10lld|%-6s|%-6d|%-12s|%-14s|%-6d|%-6d|%-6d|%-6d|%-6d|%-8d|%-8.2lf|%-8.2lf|%-8d|%-12d\n\n",q->num,q->name,q->sex,q->address,q->phone_number,q->Chinese,q->Math,q->English,q->Cross_score,q->Moral,q->tearcher_score,q->ave_score,q->end_score,q->ranking,q->end_ranking);
		q=q->next;
	}
	return ;
}

