#include <stdio.h>

int main(void)
{
  char *menuOptions[50] = {"Display Items", "Add Items", "Remove Item"};

  for (int i = 0; i < 3; i++)
  {
    printf("[%d]: %s\n", i, menuOptions[i]);
  }
}