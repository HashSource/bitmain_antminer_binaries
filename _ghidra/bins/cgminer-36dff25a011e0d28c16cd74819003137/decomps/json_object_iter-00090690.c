
void * json_object_iter(json_t *json)

{
  void *pvVar1;
  json_t *json_local;
  json_object_t *object;
  
  if ((json == (json_t *)0x0) || (json->type != JSON_OBJECT)) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = hashtable_iter((hashtable_t *)(json + 1));
  }
  return pvVar1;
}

