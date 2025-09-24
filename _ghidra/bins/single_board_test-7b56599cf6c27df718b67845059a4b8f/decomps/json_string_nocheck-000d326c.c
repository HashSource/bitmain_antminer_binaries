
/* WARNING: Unknown calling convention */

json_t * json_string_nocheck(char *value)

{
  size_t len;
  json_t *pjVar1;
  
  if (value != (char *)0x0) {
    len = strlen(value);
    pjVar1 = string_create(value,len,0);
    return pjVar1;
  }
  return (json_t *)0x0;
}

