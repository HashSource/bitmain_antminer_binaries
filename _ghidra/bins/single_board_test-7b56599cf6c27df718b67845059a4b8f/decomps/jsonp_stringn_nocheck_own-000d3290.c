
/* WARNING: Unknown calling convention */

json_t * jsonp_stringn_nocheck_own(char *value,size_t len)

{
  json_t *pjVar1;
  
  pjVar1 = string_create(value,len,1);
  return pjVar1;
}

