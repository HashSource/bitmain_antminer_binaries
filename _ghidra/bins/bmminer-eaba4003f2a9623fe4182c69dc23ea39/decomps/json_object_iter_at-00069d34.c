
void * json_object_iter_at(json_t *json,char *key)

{
  void *pvVar1;
  char *key_local;
  json_t *json_local;
  json_object_t *object;
  
  if (((key == (char *)0x0) || (json == (json_t *)0x0)) || (json->type != JSON_OBJECT)) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = hashtable_iter_at((hashtable_t *)(json + 1),key);
  }
  return pvVar1;
}

