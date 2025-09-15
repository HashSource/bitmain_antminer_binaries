
void * json_object_iter_next(json_t *json,void *iter)

{
  void *pvVar1;
  void *iter_local;
  json_t *json_local;
  json_object_t *object;
  
  if (((json == (json_t *)0x0) || (json->type != JSON_OBJECT)) || (iter == (void *)0x0)) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = hashtable_iter_next((hashtable_t *)(json + 1),iter);
  }
  return pvVar1;
}

