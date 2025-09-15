
int json_object_set_new(json_t *json,char *key,json_t *value)

{
  size_t length;
  int iVar1;
  json_t *value_local;
  char *key_local;
  json_t *json_local;
  
  if (key != (char *)0x0) {
    length = strlen(key);
    iVar1 = utf8_check_string(key,length);
    if (iVar1 != 0) {
      iVar1 = json_object_set_new_nocheck(json,key,value);
      return iVar1;
    }
  }
  json_decref(value);
  return -1;
}

