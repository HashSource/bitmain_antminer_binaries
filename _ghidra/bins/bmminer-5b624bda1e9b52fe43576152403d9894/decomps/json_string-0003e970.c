
/* WARNING: Unknown calling convention */

json_t * json_string(char *value)

{
  int iVar1;
  json_t *pjVar2;
  
  if ((value != (char *)0x0) && (iVar1 = utf8_check_string(value,-1), iVar1 != 0)) {
    pjVar2 = json_string_nocheck(value);
    return pjVar2;
  }
  return (json_t *)0x0;
}

