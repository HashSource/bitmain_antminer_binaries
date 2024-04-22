
char * json_dumps(json_t *json,size_t flags)

{
  int iVar1;
  char *str;
  size_t flags_local;
  json_t *json_local;
  strbuffer_t strbuff;
  char *result;
  
  iVar1 = strbuffer_init(&strbuff);
  if (iVar1 == 0) {
    iVar1 = json_dump_callback(json,dump_to_strbuffer,&strbuff,flags);
    if (iVar1 == 0) {
      str = strbuffer_value(&strbuff);
      result = jsonp_strdup(str);
    }
    else {
      result = (char *)0x0;
    }
    strbuffer_close(&strbuff);
  }
  else {
    result = (char *)0x0;
  }
  return result;
}

