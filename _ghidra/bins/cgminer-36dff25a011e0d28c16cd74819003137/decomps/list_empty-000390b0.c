
int list_empty(list_head *head)

{
  list_head *head_local;
  
  return (uint)(head == head->next);
}

