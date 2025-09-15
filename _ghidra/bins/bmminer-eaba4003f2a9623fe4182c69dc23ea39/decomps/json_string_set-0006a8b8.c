
int json_string_set(json_t *json,char *value)

{
  size_t len;
  int iVar1;
  char *value_local;
  json_t *json_local;
  
  if (value == (char *)0x0) {
    iVar1 = -1;
  }
  else {
    len = strlen(value);
    iVar1 = json_string_setn(json,value,len);
  }
  return iVar1;
}

