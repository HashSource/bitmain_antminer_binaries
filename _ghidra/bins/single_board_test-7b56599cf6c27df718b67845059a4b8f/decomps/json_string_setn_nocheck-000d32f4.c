
/* WARNING: Unknown calling convention */

int json_string_setn_nocheck(json_t *json,char *value,size_t len)

{
  char *pcVar1;
  
  if ((((json != (json_t *)0x0) && (json->type == JSON_STRING)) && (value != (char *)0x0)) &&
     (pcVar1 = jsonp_strndup(value,len), pcVar1 != (char *)0x0)) {
    jsonp_free((void *)json[1].type);
    json[1].type = (json_type)pcVar1;
    json[1].refcount = len;
    return 0;
  }
  return -1;
}

