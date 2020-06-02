#include "dequeue.h"

void insert_res();
void delete_res();

int main()
{
	int ch;

	printf("\n\n------MENU------\n");
	printf("1. INSERT Restricted\n");
	printf("2. DELETE Restricted\n");
	printf("Enter Choice : ");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		insert_res();
		break;

	case 2:
		delete_res();
		break;

	default:
		printf("\nInvalid option");
		break;
	}

	return 0;
}

void insert_res()
{
	int ch, n, data;
	char c;
	queue Q = {-1, -1};
	do
	{
		printf("\n\n------MENU------\n");
		printf("1. Insert\n");
		printf("2. Delete from FRONT\n");
		printf("3. Delete from REAR\n");
		printf("4. DISPLAY\n");
		printf("Enter Choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\nEnter the element to insert : ");
			scanf("%d", &data);
			insertRear(&Q, data);
			break;

		case 2:
			data = delFront(&Q);
			if (data == -9999)
				break;
			printf("\n%d Deleted.", data);
			break;

		case 3:
			data = delRear(&Q);
			if (data == -9999)
				break;
			printf("\n%d Deleted.", data);
			break;

		case 4:
			display(&Q);
			break;

		default:
			printf("\nInvalid option");
			break;
		}

		printf("\nDo you want to continue? (y/n) : ");
		c = getche();

	} while (c == 'y' || c == 'Y');
}

void delete_res()
{
	int ch, n, data;
	char c;
	queue Q = {-1, -1};
	do
	{
		printf("\n\n------MENU------\n");
		printf("1. Insert from FRONT\n");
		printf("2. Insert from REAR\n");
		printf("3. Delete\n");
		printf("4. DISPLAY\n");
		printf("Enter Choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\nEnter the element to insert : ");
			scanf("%d", &data);
			insertFront(&Q, data);
			break;

		case 2:
			printf("\nEnter the element to insert : ");
			scanf("%d", &data);
			insertRear(&Q, data);
			break;

		case 3:
			data = delFront(&Q);
			if (data == -9999)
				break;
			printf("\n%d Deleted.", data);
			break;

		case 4:
			display(&Q);
			break;

		default:
			printf("\nInvalid option");
			break;
		}

		printf("\nDo you want to continue? (y/n) : ");
		c = getche();

	} while (c == 'y' || c == 'Y');
}

/*
================ OUTPUT ================
================ SET - 1 ===============
------MENU------
1. INSERT Restricted
2. DELETE Restricted
Enter Choice : 1


------MENU------
1. Insert
2. Delete from FRONT
3. Delete from REAR
4. DISPLAY
Enter Choice : 1

Enter the element to insert : 10

Do you want to continue? (y/n) : y

------MENU------
1. Insert
2. Delete from FRONT
3. Delete from REAR
4. DISPLAY
Enter Choice : 1

Enter the element to insert : 20

Do you want to continue? (y/n) : y

------MENU------
1. Insert
2. Delete from FRONT
3. Delete from REAR
4. DISPLAY
Enter Choice : 1

Enter the element to insert : 30

Do you want to continue? (y/n) : y

------MENU------
1. Insert
2. Delete from FRONT
3. Delete from REAR
4. DISPLAY
Enter Choice : 4
(10) -(20) -(30) -
Do you want to continue? (y/n) : y

------MENU------
1. Insert
2. Delete from FRONT
3. Delete from REAR
4. DISPLAY
Enter Choice : 2

10 Deleted.
Do you want to continue? (y/n) : y

------MENU------
1. Insert
2. Delete from FRONT
3. Delete from REAR
4. DISPLAY
Enter Choice : 3

30 Deleted.
Do you want to continue? (y/n) : y

------MENU------
1. Insert
2. Delete from FRONT
3. Delete from REAR
4. DISPLAY
Enter Choice : 4
(20) -
Do you want to continue? (y/n) : n
================ SET - 2 ===============
------MENU------
1. INSERT Restricted
2. DELETE Restricted
Enter Choice : 2


------MENU------
1. Insert from FRONT
2. Insert from REAR
3. Delete
4. DISPLAY
Enter Choice : 1

Enter the element to insert : 10

Do you want to continue? (y/n) : y

------MENU------
1. Insert from FRONT
2. Insert from REAR
3. Delete
4. DISPLAY
Enter Choice : 2

Enter the element to insert : 20

Do you want to continue? (y/n) : y

------MENU------
1. Insert from FRONT
2. Insert from REAR
3. Delete
4. DISPLAY
Enter Choice : 2

Enter the element to insert : 30

Do you want to continue? (y/n) : y

------MENU------
1. Insert from FRONT
2. Insert from REAR
3. Delete
4. DISPLAY
Enter Choice : 4
(10) -(20) -(30) -
Do you want to continue? (y/n) : y

------MENU------
1. Insert from FRONT
2. Insert from REAR
3. Delete
4. DISPLAY
Enter Choice : 1

Enter the element to insert : 5

Do you want to continue? (y/n) : y

------MENU------
1. Insert from FRONT
2. Insert from REAR
3. Delete
4. DISPLAY
Enter Choice : 4
(5) -(10) -(20) -(30) -
Do you want to continue? (y/n) : y

------MENU------
1. Insert from FRONT
2. Insert from REAR
3. Delete
4. DISPLAY
Enter Choice : 3

5 Deleted.
Do you want to continue? (y/n) : y

------MENU------
1. Insert from FRONT
2. Insert from REAR
3. Delete
4. DISPLAY
Enter Choice : 4
(10) -(20) -(30) -
Do you want to continue? (y/n) : n

*/
