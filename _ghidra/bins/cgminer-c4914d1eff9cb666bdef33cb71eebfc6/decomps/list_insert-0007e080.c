
void list_insert(list_t *list,list_t *node)

{
  list_t *node_local;
  list_t *list_local;
  
  node->next = list;
  node->prev = list->prev;
  list->prev->next = node;
  list->prev = node;
  return;
}

