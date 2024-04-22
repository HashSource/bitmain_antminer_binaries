
int json_string_setn_nocheck(json_t *json,char *value,size_t len)

{
  char *pcVar1;
  int iVar2;
  size_t len_local;
  char *value_local;
  json_t *json_local;
  json_string_t *string;
  char *dup;
  
  if (((json == (json_t *)0x0) || (json->type != JSON_STRING)) || (value == (char *)0x0)) {
    iVar2 = -1;
  }
  else {
    pcVar1 = jsonp_strndup(value,len);
    if (pcVar1 == (char *)0x0) {
      iVar2 = -1;
    }
    else {
      jsonp_free((void *)json[1].type);
      json[1].type = (json_type)pcVar1;
      json[1].refcount = len;
      iVar2 = 0;
    }
  }
  return iVar2;
}

