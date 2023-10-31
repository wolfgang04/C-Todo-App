#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// linked list for the todo items
typedef struct item
{
  char *desc;
  struct item *next;
} item;

// prototypes
item *addItem(item *prev, int *itemCount);
void printItems(item *currItem);
int sizeOfArray(char *arr[]);
void removeItem(item *head, int *itemCount);

int main(void)
{
  // declare all variables
  char *menuOptions[50] = {"Display Items", "Add Items", "Remove Item", NULL};
  int sizeOfOpt = sizeOfArray(menuOptions); // sets the size of the options array
  item *head = NULL, *prev = NULL;
  int userChoice;
  int *itemCountPtr;
  void *ptr;

  // declares itemCountPtr for removing of items;
  itemCountPtr = (int *)malloc(sizeof(int));
  if (itemCountPtr == NULL)
  {
    printf("Allocation failed!\n");
    return 1;
  }
  *itemCountPtr = 0;

  // prints the menu
  do
  {
    for (int i = 0; i < sizeOfOpt; i++)
    {
      printf("[%d]: %s", i + 1, menuOptions[i]);

      if (i < sizeOfOpt - 1)
      {
        printf("\n");
      }
    }

    printf("\nSelect Option: ");
    scanf("%d", &userChoice);

    switch (userChoice)
    {
    case 1:
      printItems(head);

      break;
    case 2:
      head = addItem(prev, itemCountPtr);
      prev = head;

      break;
    case 3:
      removeItem(head, itemCountPtr);

      break;
    default:
      printf("Invalid choice!\n");

      break;
    }

  } while (userChoice != 0);
}

void removeItem(item *head, int *itemCount)
{
  item *current = head;
  item *previous = NULL;
  int choice, curr = 0;

  do
  {
    printf("Which item do you wish to remove? ");
    scanf("%d", &choice);

    if (choice > *itemCount)
    {
      printf("Item removal failed! Choice doesn't exist in list\n");
    }
  } while (choice > *itemCount && choice < 0);

  while (current != NULL)
  {
    curr += 1;
    if (curr == choice)
    {
      if (previous != NULL)
      {
        previous->next = current->next;
      }
      else
      {
        head = current->next;
      }

      free(current);
      return;
    }

    previous = current;
    current = current->next;
  }
}

void printItems(item *currItem)
{
  item *ptr = currItem;

  for (int i = 1; ptr != NULL; i++)
  {
    printf("[%d] %s\n", i, ptr->desc);
    ptr = ptr->next;
  }

  printf("\n");
}

item *addItem(item *prev, int *itemCount)
{
  char *todoEntry = (char *)malloc(101 * sizeof(char));
  item *todoItem = (item *)malloc(sizeof(item));
  if (todoItem == NULL)
  {
    printf("Allocation failed!\n");
    return NULL;
  } // handle allocation failure

  printf("\nWhat would you like to do? ");
  scanf(" %100[^\n]", todoEntry);

  // todoItem->desc = todoEntry;
  todoItem->desc = (char *)malloc(strlen(todoEntry) + 1);
  if (todoItem->desc == NULL)
  {
    printf("Item description allocation failed!\n");
    return NULL;
  }
  strcpy(todoItem->desc, todoEntry);

  if (prev == NULL)
  {
    todoItem->next = NULL;
  }
  else
  {
    todoItem->next = prev;
  }

  *itemCount += 1;
  printf("Item added!\n");

  free(todoEntry);
  return todoItem;
}

int sizeOfArray(char *arr[])
{
  int size = 0;
  while (arr[size] != NULL)
  {
    size++;
  }

  return size;
}