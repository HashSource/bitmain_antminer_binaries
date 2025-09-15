
json_t * json_string_nocheck(char *value)

{
  size_t len;
  json_t *pjVar1;
  char *value_local;
  
  if (value == (char *)0x0) {
    pjVar1 = (json_t *)0x0;
  }
  else {
    len = strlen(value);
    pjVar1 = string_create(value,len,0);
  }
  return pjVar1;
}

