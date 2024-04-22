
json_t * json_pack_ex(json_error_t *error,size_t flags,char *fmt,...)

{
  json_t *pjVar1;
  undefined4 in_r3;
  size_t flags_local;
  json_error_t *error_local;
  va_list ap;
  json_t *value;
  char *fmt_local;
  undefined4 uStack_4;
  
  uStack_4 = in_r3;
  pjVar1 = json_vpack_ex(error,flags,fmt,(va_list)&uStack_4);
  return pjVar1;
}

