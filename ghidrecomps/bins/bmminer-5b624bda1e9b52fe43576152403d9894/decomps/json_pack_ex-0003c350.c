
/* Local variable value:json_t *[r0:4] conflicts with parameter, skipped. */

json_t * json_pack_ex(json_error_t *error,size_t flags,char *fmt,...)

{
  json_t *pjVar1;
  undefined4 in_r3;
  va_list ap;
  char *fmt_local;
  undefined4 uStack_4;
  
  uStack_4 = in_r3;
  pjVar1 = json_vpack_ex(error,flags,fmt,(va_list)&uStack_4);
  return pjVar1;
}

