
void __list_add(list_head *new,list_head *prev,list_head *next)

{
  list_head *next_local;
  list_head *prev_local;
  list_head *new_local;
  
  next->prev = new;
  new->next = next;
  new->prev = prev;
  prev->next = new;
  return;
}

