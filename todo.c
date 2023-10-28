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
item *addItem(item *prev);
void printItems(item *currItem);
int sizeOfArray(char *arr[]);

int main(void)
{
  // declare all variables
  char *menuOptions[50] = {"Display Items", "Add Items", "Remove Item", NULL};
  int sizeOfOpt = sizeOfArray(menuOptions); // sets the size of the options array
  int userChoice;
  item *newItem = NULL, *prev = NULL, *ptr;

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
      printItems(newItem);

      break;
    case 2:
      newItem = addItem(prev);
      prev = newItem;

      break;
    default:
      printf("Invalid choice!\n");

      break;
    }

  } while (userChoice != 0);
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

item *addItem(item *prev)
{
  char *todoEntry = (char *)malloc(101 * sizeof(char));
  item *todoItem = (item *)malloc(sizeof(item));
  if (todoItem == NULL)
  {
    printf("Allocation failed!\n");
    return NULL;
  } // handle allocation failure

  printf("\nWhat would you like to do? ");
  scanf("%s", todoEntry);

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