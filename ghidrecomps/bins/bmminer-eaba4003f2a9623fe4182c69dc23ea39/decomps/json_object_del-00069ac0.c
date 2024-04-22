
int json_object_del(json_t *json,char *key)

{
  int iVar1;
  char *key_local;
  json_t *json_local;
  json_object_t *object;
  
  if (((key == (char *)0x0) || (json == (json_t *)0x0)) || (json->type != JSON_OBJECT)) {
    iVar1 = -1;
  }
  else {
    iVar1 = hashtable_del((hashtable_t *)(json + 1),key);
  }
  return iVar1;
}

