
void list_del(list_head *entry)

{
  list_head *entry_local;
  
  __list_del(entry->prev,entry->next);
  entry->next = (list_head *)0x0;
  entry->prev = (list_head *)0x0;
  return;
}

