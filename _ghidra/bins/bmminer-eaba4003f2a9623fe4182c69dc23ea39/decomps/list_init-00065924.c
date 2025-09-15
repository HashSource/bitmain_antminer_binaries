
void list_init(list_t *list)

{
  list_t *list_local;
  
  list->next = list;
  list->prev = list;
  return;
}

