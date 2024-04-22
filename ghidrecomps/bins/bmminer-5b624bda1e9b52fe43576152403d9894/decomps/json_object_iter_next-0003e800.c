
/* WARNING: Unknown calling convention */

void * json_object_iter_next(json_t *json,void *iter)

{
  json_object_t *object;
  void *pvVar1;
  
  if (((json != (json_t *)0x0) && (json->type == JSON_OBJECT)) && (iter != (void *)0x0)) {
    object = (json_object_t *)(json + 1);
    pvVar1 = hashtable_iter_next((hashtable_t *)object,iter);
    return pvVar1;
  }
  return (void *)0x0;
}

