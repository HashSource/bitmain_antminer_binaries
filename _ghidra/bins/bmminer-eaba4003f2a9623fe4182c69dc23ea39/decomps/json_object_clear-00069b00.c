
int json_object_clear(json_t *json)

{
  int iVar1;
  json_t *json_local;
  json_object_t *object;
  
  if ((json == (json_t *)0x0) || (json->type != JSON_OBJECT)) {
    iVar1 = -1;
  }
  else {
    hashtable_clear((hashtable_t *)(json + 1));
    iVar1 = 0;
  }
  return iVar1;
}

