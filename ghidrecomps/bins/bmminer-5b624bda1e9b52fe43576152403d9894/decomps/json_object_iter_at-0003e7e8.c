
/* WARNING: Unknown calling convention */

void * json_object_iter_at(json_t *json,char *key)

{
  json_object_t *object;
  void *pvVar1;
  
  if ((json != (json_t *)0x0 && key != (char *)0x0) && (json->type == JSON_OBJECT)) {
    object = (json_object_t *)(json + 1);
    pvVar1 = hashtable_iter_at((hashtable_t *)object,key);
    return pvVar1;
  }
  return (void *)0x0;
}

