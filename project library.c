#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#define MAX_STUDENT_NAME 50
#define MAX_STUDENT_LASTNAME 50
#define MAX_USER_NAME 50
#define MAX_BOOK_NAME   50
#define MAX_AUTHOR_NAME 50
#define MAX_BORROWED 10
struct BOOKSINFOS {
	int bookscode;
	int numbers;
	char bookName[MAX_BOOK_NAME];
	char author[MAX_AUTHOR_NAME];
}BookInfo[100];
struct DATES {
	int day;
	int month;
	int year;
};
struct BORROWING {
	int p;
	struct BOOKSINFOS borrowedbook;
	struct DATES borrowedday;
	struct DATES returningday;

};
struct MEMBERS
{
	int ID;
	struct DATES birthday;
	char username[MAX_USER_NAME];
	char studentname[MAX_STUDENT_NAME];
	char studentlastname[MAX_STUDENT_LASTNAME];
	struct BORROWING borrowed[MAX_BORROWED];

}p[100];
int y;
int n;
int code;
void functions(void)
{
	for (int i = 0; i < 100; i++)
	{
		if (p[i].studentname[0] == '0')
		{
			n = i;
			break;
		}
	}
}
void function(void)
{
	for (int j = 0; j < 100; j++)
	{
		if (BookInfo[j].bookName[0] == '0')
		{
			n = j;
			break;
		}
	}
}
void SearchBook(void)
{
	y = 0;
	for (int i = 0; i < 100; i++)
	{
		if (code == BookInfo[i].bookscode)
		{
			y = 1;
			n = i;
		}
	}
}
void AddMembers(FILE* fp)
{
	functions();
	printf("\n\t\t*******************************************************************************");
	printf("\n\t\t****************************ADD NEW MEMBERS************************************");
	printf("\n\t\t*******************************************************************************\n");
	printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
	printf("\n\t\t\t---------------------------------------------------------------------------\n");
	printf("Enter your firstname:\n");
	scanf("%s", p[n].studentname);
	fprintf(fp, "%6s", p[n].studentname);
	printf("Enter your lastname:\n");
	scanf("%s", p[n].studentlastname);
	fprintf(fp, "%6s", p[n].studentlastname);
	printf("Enter your username:\n");
	scanf("%s", p[n].username);
	fprintf(fp, "%6s", p[n].username);
	printf("Enter the day of your birthday:\n");
	scanf("%d", &p[n].birthday.day);
	fprintf(fp, "%6d", p[n].birthday.day);
	printf("Enter the month of your birthday:\n");
	scanf("%d", &p[n].birthday.month);
	fprintf(fp, "%6d", p[n].birthday.month);
	printf("Enter the year of your birthday:\n");
	scanf("%d", &p[n].birthday.year);
	fprintf(fp, "%6d", p[n].birthday.year);
	p[n].ID = n;
	printf("Your id is: %4d", p[n].ID);
	fprintf(fp, "%4d", p[n].ID);
	printf("\n");
	fprintf(fp, "\n");
}
void AddBooks(FILE* fb)
{

	function();
	printf("\n\t\t*******************************************************************************");
	printf("\n\t\t****************************ADD NEW BOOKS**************************************");
	printf("\n\t\t*******************************************************************************\n");
	printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
	printf("\n\t\t\t---------------------------------------------------------------------------\n");
	printf("Enter the books codes:\n");
	scanf("%d", &code);
	fprintf(fb, "%4d", code);
	SearchBook();
	if (y == 1)
	{
		BookInfo[n].numbers++;
	}
	else
	{
		function();
		BookInfo[n].bookscode = code;
		printf("Enter the books names:\n");
		scanf("%s", BookInfo[n].bookName);
		fprintf(fb, "%6s", BookInfo[n].bookName);
		printf("Enter the books author:\n");
		scanf("%s", BookInfo[n].author);
		fprintf(fb, "%6s", BookInfo[n].author);
		fprintf(fb, "\n");
		BookInfo[n].numbers++;
	}
}
void BorrowedBooks(void)
{

	int m;
	int z = 5;
	printf("\n\t\t*******************************************************************************");
	printf("\n\t\t*********************************BORROWING BOOKS*******************************");
	printf("\n\t\t*******************************************************************************\n");
	printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
	printf("\n\t\t\t---------------------------------------------------------------------------\n");
	printf("Enter your ID NO:\n");
	scanf("%d", &n);
	printf("Books list:\n");
	for (int i = 0; i < 100; i++)
	{
		if (BookInfo[i].numbers >> 0)
		{
			printf("%s   %d", BookInfo[i].bookName, i);
			printf("\n");
		}
	}
	printf("Enter the books code:\n");
	scanf("%d", &m);
	for (int j = 0; j < 5; j++)
	{
		if (p[n].borrowed[j].p == 0)
		{
			z = j;
			break;
		}
	}
	if (z == 5)
	{
		printf("You can't borrow more books for now!\n");
		return 0;
	}
	else
	{
		p[n].borrowed[z].p++;
		BookInfo[m].numbers--;
		strcpy(p[n].borrowed[z].borrowedbook.bookName, BookInfo[m].bookName);
		strcpy(p[n].borrowed[z].borrowedbook.author, BookInfo[m].author);
		p[n].borrowed[z].borrowedbook.bookscode = BookInfo[m].bookscode;
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		p[n].borrowed[z].borrowedday.day = tm.tm_mday;
		p[n].borrowed[z].borrowedday.month = tm.tm_mon + 1;
		p[n].borrowed[z].borrowedday.year = tm.tm_year + 1900;
		p[n].borrowed[z].returningday.day = tm.tm_mday + 7;
		p[n].borrowed[z].returningday.month = tm.tm_mon + 1;
		p[n].borrowed[z].returningday.year = tm.tm_year + 1900;
	}
}
void ShowBooks(void)
{
	printf("\n\t\t*******************************************************************************");
	printf("\n\t\t**************************SHOW THE BORROWED BOOKS******************************");
	printf("\n\t\t*******************************************************************************\n");
	printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
	printf("\n\t\t\t---------------------------------------------------------------------------\n");
	printf("Enter your ID NO:\n");
	scanf("%d", &n);
	printf("The books you have borrowed:\n");
	for (int i = 0; i < 5; i++)
	{
		if (p[n].borrowed[i].p != 0)
		{
			printf("%s", p[n].borrowed[i].borrowedbook.bookName);
			printf("\n");
		}
	}
}
void ReturningBooks(void)
{
	int m, b;
	printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
	printf("\n\t\t\t---------------------------------------------------------------------------\n");
	printf("Enter your ID NO:\n");
	scanf("%d", &n);
	printf("Enter the books code:\n");
	scanf("%d", &b);
	for (int i = 0; i < 100; i++)
	{
		if (BookInfo[i].bookscode == b)
		{
			m = i;
			break;
		}
	}
	for (int j = 0; j < 5; j++)
	{
		if (p[n].borrowed[j].borrowedbook.bookscode == b)
		{
			time_t t = time(NULL);
			struct tm tm = *localtime(&t);
			if (p[n].borrowed[j].returningday.day >> tm.tm_mday)
			{
				printf("You've been late!\n");
			}
			p[n].borrowed[j].p = 0;
			BookInfo[m].numbers++;
			break;
		}
	}
}
void ShowAllTheMembers(void)
{
	for (int i = 0; i < 100; i++)
	{
		if (p[i].studentname[0] != '0')
		{
			printf("Fullname: %s %s", p[i].studentname, p[i].studentlastname);
			printf("\n");
			printf("Username: %s", p[i].username);
			printf("\n");
			printf("ID: %d", i);
			printf("\n");
			printf("\n");

		}
	}
}
void ShowAllBooks(void)
{
	for (int i = 0; i < 100; i++)
	{
		if (BookInfo[i].bookName[0] != '0')
		{
			printf("%s ", BookInfo[i].bookName);
			printf("%s\n", BookInfo[i].author);
			printf("Holding: %d", BookInfo[i].numbers);
			printf("\n");
			printf("\n");
		}
	}
}
int main()
{
	FILE* fp;
	fp = fopen("libraryproj.txt", "a");
	FILE* fb;
	fb = fopen("libraryproj.txt", "a");
	for (int i = 0; i < 100; i++)
	{
		p[i].studentname[0] = '0';
		BookInfo[i].bookName[0] = '0';
		BookInfo[i].numbers = 0;
		for (int j = 0; j < 5; j++)
		{
			p[i].borrowed[j].p = 0;
		}
	}
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	printf("Date and Time: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	int choice = 1;
	printf("\n\n");
	printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
	printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n\t\t\t        =                 WELCOME                   =");
	printf("\n\t\t\t        =                   TO                      =");
	printf("\n\t\t\t        =                   THE                     =");
	printf("\n\t\t\t        =                 LIBRARY                   =");
	printf("\n\t\t\t        =                 SYSTEM                    =");
	printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
	printf("\n\n\n\n\n");
	printf("\nChoose One Of The Following Options:");
	printf("\n1.Add Members");
	printf("\n2.Add Books");
	printf("\n3.Borrow Books");
	printf("\n4.Show The Books That've Been Borrowed");
	printf("\n5.Returning Books");
	printf("\n6.Show All The Members");
	printf("\n7.Show All The Books"); 
	printf("\n0.Exit\n");
	scanf("%d", &choice);
	while (choice!= 8)
	{
		switch (choice) {

		case 1:
			AddMembers(fp);
			break;
		case 2:
			AddBooks(fb);
			break;
		case 3:
			BorrowedBooks();
			break;
		case 4:
			ShowBooks();
			break;
		case 5:
			ReturningBooks();
			break;
		case 6:
			ShowAllTheMembers();
			break;
		case 7:
			ShowAllBooks();
			break;
		case 0:
			printf("\n\n\n\t\t\t\t\t\tThank you!!!\n\n\n\n\n");
			exit(1);
			break;
		default:
			printf("INVALID INPUT!!! Try again...\n");
		}
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		printf("Date and Time: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
		printf("\nChoose One Of The Following Options:");
		printf("\n1.Add Members");
		printf("\n2.Add Books");
		printf("\n3.Borrow Books");
		printf("\n4.Show The Books That've Been Borrowed");
		printf("\n5.Returning Books");
		printf("\n6.Show All The Members");
		printf("\n7.Show All The Books");
		printf("\n0.Exit\n");
		scanf("%d", &choice);
	}fclose(fp);
	fclose(fb);
	return 0;
}