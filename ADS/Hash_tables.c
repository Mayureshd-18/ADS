#include<stdio.h>
#define size 10
int arr[size];

void initialize()
{
    int i;
    for(i = 0; i < size; i++)
        arr[i] = 0;
}

void insert(int value)
{
    int key = value % size;

    if(arr[key] == 0)
    {
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value,key);
    }
    else
    {
        while(arr[key]!=0){
            key+=1;
        }
        arr[key]= value;
    }
}
void delete(int value)
{
    int key = value % size;
    if(arr[key] == value)
        arr[key] = 0;
    else
        printf("%d not present in the hash table\n",value);
}
void search(int value)
{
    int key = value % size;
    if(arr[key] == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
}
void print()
{
    int i;
    for(i = 0; i < size; i++)
        printf("list[%d] = %d\n",i,arr[i]);
}

int main()
{
    int choice, key, data, n;
    int c = 0;
    initialize();


    do
    {
        printf("1.Insert item in the Hash Table"
               "\n2.Remove item from the Hash Table"
               "\n3.Display Hash Table\n");

        scanf("%d", &choice);
        switch (choice)
        {
            case 1:

                printf("Enter the data:\t");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:

                printf("Enter the data to delete-:");
                scanf("%d", &key);
                delete(key);
                break;
            case 3:
                print();
                break;
            default:
                printf("Invalid Input\n");
        }
        printf("\n(press 1 to continue): ");
        scanf("%d", &c);

    } while (c == 1);
}