
json_t * jsonp_stringn_nocheck_own(char *value,size_t len)

{
  json_t *pjVar1;
  size_t len_local;
  char *value_local;
  
  pjVar1 = string_create(value,len,1);
  return pjVar1;
}

