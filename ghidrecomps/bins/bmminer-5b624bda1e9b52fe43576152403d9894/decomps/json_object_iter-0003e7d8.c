
/* WARNING: Unknown calling convention */

void * json_object_iter(json_t *json)

{
  json_object_t *object;
  void *pvVar1;
  
  if ((json != (json_t *)0x0) && (json->type == JSON_OBJECT)) {
    object = (json_object_t *)(json + 1);
    pvVar1 = hashtable_iter((hashtable_t *)object);
    return pvVar1;
  }
  return (void *)0x0;
}

