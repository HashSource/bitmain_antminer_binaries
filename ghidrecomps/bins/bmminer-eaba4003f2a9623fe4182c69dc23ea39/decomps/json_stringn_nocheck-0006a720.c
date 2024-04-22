
json_t * json_stringn_nocheck(char *value,size_t len)

{
  json_t *pjVar1;
  size_t len_local;
  char *value_local;
  
  pjVar1 = string_create(value,len,0);
  return pjVar1;
}

