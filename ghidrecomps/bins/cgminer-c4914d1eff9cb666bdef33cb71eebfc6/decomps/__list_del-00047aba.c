
void __list_del(list_head *prev,list_head *next)

{
  list_head *next_local;
  list_head *prev_local;
  
  next->prev = prev;
  prev->next = next;
  return;
}

