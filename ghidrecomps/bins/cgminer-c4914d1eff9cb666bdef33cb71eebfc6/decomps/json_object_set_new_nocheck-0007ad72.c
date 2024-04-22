
int json_object_set_new_nocheck(json_t *json,char *key,json_t *value)

{
  int iVar1;
  json_t *value_local;
  char *key_local;
  json_t *json_local;
  json_object_t *object;
  
  if (value == (json_t *)0x0) {
    iVar1 = -1;
  }
  else if ((((key == (char *)0x0) || (json == (json_t *)0x0)) || (json->type != JSON_OBJECT)) ||
          (json == value)) {
    json_decref(value);
    iVar1 = -1;
  }
  else {
    iVar1 = hashtable_set((hashtable_t *)(json + 1),key,value);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      json_decref(value);
      iVar1 = -1;
    }
  }
  return iVar1;
}

