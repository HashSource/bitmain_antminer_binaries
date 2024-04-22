
void list_remove(list_t *list)

{
  list_t *list_local;
  
  list->prev->next = list->next;
  list->next->prev = list->prev;
  return;
}

