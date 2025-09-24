
/* WARNING: Unknown calling convention */

json_t * json_stringn_nocheck(char *value,size_t len)

{
  json_t *pjVar1;
  
  pjVar1 = string_create(value,len,0);
  return pjVar1;
}

