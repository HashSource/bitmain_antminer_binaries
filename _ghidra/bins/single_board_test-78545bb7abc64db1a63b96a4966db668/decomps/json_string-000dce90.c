
/* WARNING: Unknown calling convention */

json_t * json_string(char *value)

{
  size_t len;
  json_t *pjVar1;
  
  if (value != (char *)0x0) {
    len = strlen(value);
    pjVar1 = json_stringn(value,len);
    return pjVar1;
  }
  return (json_t *)0x0;
}

