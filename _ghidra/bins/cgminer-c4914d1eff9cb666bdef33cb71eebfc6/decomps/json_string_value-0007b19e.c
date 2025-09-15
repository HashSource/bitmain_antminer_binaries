
char * json_string_value(json_t *json)

{
  char *pcVar1;
  json_t *json_local;
  
  if ((json == (json_t *)0x0) || (json->type != JSON_STRING)) {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = (char *)json[1].type;
  }
  return pcVar1;
}

