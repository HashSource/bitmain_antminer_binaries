
/* WARNING: Unknown calling convention */

void * json_object_iter_at(json_t *json,char *key)

{
  void *pvVar1;
  
  if ((json != (json_t *)0x0 && key != (char *)0x0) && (json->type == JSON_OBJECT)) {
    pvVar1 = hashtable_iter_at((hashtable_t *)(json + 1),key);
    return pvVar1;
  }
  return (void *)0x0;
}

