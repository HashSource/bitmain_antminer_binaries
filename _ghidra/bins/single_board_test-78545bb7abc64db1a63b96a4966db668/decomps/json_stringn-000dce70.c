
/* WARNING: Unknown calling convention */

json_t * json_stringn(char *value,size_t len)

{
  int iVar1;
  json_t *pjVar2;
  
  if ((value != (char *)0x0) && (iVar1 = utf8_check_string(value,len), iVar1 != 0)) {
    pjVar2 = json_stringn_nocheck(value,len);
    return pjVar2;
  }
  return (json_t *)0x0;
}

