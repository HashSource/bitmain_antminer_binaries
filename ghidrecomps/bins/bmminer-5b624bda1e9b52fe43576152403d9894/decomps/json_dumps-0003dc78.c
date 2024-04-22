
/* WARNING: Unknown calling convention */

char * json_dumps(json_t *json,size_t flags)

{
  int iVar1;
  char *pcVar2;
  char *result;
  strbuffer_t strbuff;
  
  iVar1 = strbuffer_init(&strbuff);
  if ((iVar1 == 0) && (iVar1 = json_dump_callback(json,DAT_0003dcb0,&strbuff,flags), iVar1 == 0)) {
    if ((int)(flags << 0x13) < 0) {
      pcVar2 = jsonp_eolstrsteal(&strbuff);
    }
    else {
      pcVar2 = jsonp_strsteal(&strbuff);
    }
  }
  else {
    pcVar2 = (char *)0x0;
  }
  return pcVar2;
}

