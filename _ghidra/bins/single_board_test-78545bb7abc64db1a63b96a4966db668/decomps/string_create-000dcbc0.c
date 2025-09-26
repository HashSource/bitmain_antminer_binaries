
/* WARNING: Unknown calling convention */

json_t * string_create(char *value,size_t len,int own)

{
  json_t *pjVar1;
  
  if ((value != (char *)0x0) &&
     ((own != 0 || (value = jsonp_strndup(value,len), value != (char *)0x0)))) {
    pjVar1 = (json_t *)jsonp_malloc(0x10);
    if (pjVar1 != (json_t *)0x0) {
      pjVar1[1].type = (json_type)value;
      pjVar1[1].refcount = len;
      pjVar1->type = JSON_STRING;
      pjVar1->refcount = 1;
      return pjVar1;
    }
    jsonp_free(value);
    return (json_t *)0x0;
  }
  return (json_t *)0x0;
}

