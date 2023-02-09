#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    void            *content;
	int				num;
    struct s_list    *next;
}            t_list;

// t_list    *ft_lstnew(int    num)
t_list    *ft_lstnew(void *content)
{
    t_list    *new_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->content = content;
    // new_node->num = num;
    new_node->next = NULL;
    return (new_node);
}

int	main(void) 
{
  t_list *head;
  char	*a = "abcdedsfsdfsd";
//   int	b = 123;
  head = ft_lstnew(a);
//   head = ft_lstnew(&b);
  while (head)
  {
    printf("%s", (head->content));
    // printf("%d", *(int *)head->content);
    head = head->next;
  }
  return 0;
}
