
json_t * json_pack(char *fmt,...)

{
  json_t *pjVar1;
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  va_list ap;
  json_t *value;
  char *fmt_local;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = in_r1;
  uStack_8 = in_r2;
  uStack_4 = in_r3;
  pjVar1 = json_vpack_ex((json_error_t *)0x0,0,fmt,(va_list)&uStack_c);
  return pjVar1;
}

