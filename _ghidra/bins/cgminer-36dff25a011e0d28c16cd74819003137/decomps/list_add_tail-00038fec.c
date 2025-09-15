
void list_add_tail(list_head *new,list_head *head)

{
  list_head *head_local;
  list_head *new_local;
  
  __list_add(new,head->prev,head);
  return;
}

