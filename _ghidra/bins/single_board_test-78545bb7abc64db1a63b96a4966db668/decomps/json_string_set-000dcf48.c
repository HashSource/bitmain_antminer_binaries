
/* WARNING: Unknown calling convention */

int json_string_set(json_t *json,char *value)

{
  size_t len;
  int iVar1;
  
  if (value != (char *)0x0) {
    len = strlen(value);
    iVar1 = json_string_setn(json,value,len);
    return iVar1;
  }
  return -1;
}

