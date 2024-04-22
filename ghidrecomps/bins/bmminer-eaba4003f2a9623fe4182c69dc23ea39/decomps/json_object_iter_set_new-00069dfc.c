
int json_object_iter_set_new(json_t *json,void *iter,json_t *value)

{
  int iVar1;
  json_t *value_local;
  void *iter_local;
  json_t *json_local;
  
  if ((((json == (json_t *)0x0) || (json->type != JSON_OBJECT)) || (iter == (void *)0x0)) ||
     (value == (json_t *)0x0)) {
    iVar1 = -1;
  }
  else {
    hashtable_iter_set(iter,value);
    iVar1 = 0;
  }
  return iVar1;
}

