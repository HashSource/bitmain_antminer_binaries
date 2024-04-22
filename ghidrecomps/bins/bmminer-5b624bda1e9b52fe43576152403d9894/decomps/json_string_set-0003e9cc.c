
/* WARNING: Unknown calling convention */

int json_string_set(json_t *json,char *value)

{
  int iVar1;
  
  if ((value != (char *)0x0) && (iVar1 = utf8_check_string(value,-1), iVar1 != 0)) {
    iVar1 = json_string_set_nocheck(json,value);
    return iVar1;
  }
  return -1;
}

