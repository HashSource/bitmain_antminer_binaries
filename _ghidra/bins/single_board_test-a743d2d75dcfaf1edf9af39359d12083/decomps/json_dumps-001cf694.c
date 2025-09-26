
/* WARNING: Unknown calling convention */

char * json_dumps(json_t *json,size_t flags)

{
  int iVar1;
  char *pcVar2;
  strbuffer_t strbuff;
  
  iVar1 = strbuffer_init(&strbuff);
  if (iVar1 == 0) {
    iVar1 = json_dump_callback(json,(json_dump_callback_t)0x1cf0f1,&strbuff,flags);
    pcVar2 = (char *)0x0;
    if (iVar1 == 0) {
      pcVar2 = strbuffer_value(&strbuff);
      pcVar2 = jsonp_strdup(pcVar2);
    }
    strbuffer_close(&strbuff);
  }
  else {
    pcVar2 = (char *)0x0;
  }
  return pcVar2;
}

