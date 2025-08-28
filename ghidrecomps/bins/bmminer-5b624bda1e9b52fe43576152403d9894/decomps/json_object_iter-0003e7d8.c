
/* WARNING: Unknown calling convention */

void * json_object_iter(json_t *json)

{
  void *pvVar1;
  
  if ((json != (json_t *)0x0) && (json->type == JSON_OBJECT)) {
    pvVar1 = hashtable_iter((hashtable_t *)(json + 1));
    return pvVar1;
  }
  return (void *)0x0;
}

