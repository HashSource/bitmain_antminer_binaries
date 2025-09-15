
int json_string_setn(json_t *json,char *value,size_t len)

{
  int iVar1;
  size_t len_local;
  char *value_local;
  json_t *json_local;
  
  if ((value == (char *)0x0) || (iVar1 = utf8_check_string(value,len), iVar1 == 0)) {
    iVar1 = -1;
  }
  else {
    iVar1 = json_string_setn_nocheck(json,value,len);
  }
  return iVar1;
}

