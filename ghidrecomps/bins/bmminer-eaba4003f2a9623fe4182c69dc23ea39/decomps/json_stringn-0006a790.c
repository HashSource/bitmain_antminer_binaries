
json_t * json_stringn(char *value,size_t len)

{
  int iVar1;
  json_t *pjVar2;
  size_t len_local;
  char *value_local;
  
  if ((value == (char *)0x0) || (iVar1 = utf8_check_string(value,len), iVar1 == 0)) {
    pjVar2 = (json_t *)0x0;
  }
  else {
    pjVar2 = json_stringn_nocheck(value,len);
  }
  return pjVar2;
}

