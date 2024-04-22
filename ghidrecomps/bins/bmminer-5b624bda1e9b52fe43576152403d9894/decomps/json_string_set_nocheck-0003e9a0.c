
/* WARNING: Unknown calling convention */

int json_string_set_nocheck(json_t *json,char *value)

{
  char *pcVar1;
  char *dup;
  json_string_t *string;
  
  if ((((json != (json_t *)0x0) && (json->type == JSON_STRING)) && (value != (char *)0x0)) &&
     (pcVar1 = jsonp_strdup(value), pcVar1 != (char *)0x0)) {
    _jsonp_free((void **)(json + 1));
    json[1].type = (json_type)pcVar1;
    return 0;
  }
  return -1;
}

