
/* WARNING: Unknown calling convention */

void * json_object_iter_next(json_t *json,void *iter)

{
  void *pvVar1;
  
  if (((json != (json_t *)0x0) && (json->type == JSON_OBJECT)) && (iter != (void *)0x0)) {
    pvVar1 = hashtable_iter_next((hashtable_t *)(json + 1),iter);
    return pvVar1;
  }
  return (void *)0x0;
}

