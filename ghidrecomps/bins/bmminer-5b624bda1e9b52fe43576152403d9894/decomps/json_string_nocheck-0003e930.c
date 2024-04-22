
/* WARNING: Unknown calling convention */

json_t * json_string_nocheck(char *value)

{
  json_t *pjVar1;
  json_string_t *string;
  char *pcVar2;
  json_t *local_14 [2];
  
  if ((value != (char *)0x0) && (pjVar1 = (json_t *)jsonp_malloc(0xc), pjVar1 != (json_t *)0x0)) {
    pjVar1->type = JSON_STRING;
    pjVar1->refcount = 1;
    local_14[0] = pjVar1;
    pcVar2 = jsonp_strdup(value);
    pjVar1[1].type = (json_type)pcVar2;
    if (local_14[0][1].type != JSON_OBJECT) {
      return local_14[0];
    }
    _jsonp_free(local_14);
    return (json_t *)0x0;
  }
  return (json_t *)0x0;
}

