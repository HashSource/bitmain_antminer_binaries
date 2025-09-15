
int json_unpack(json_t *root,char *fmt,...)

{
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  json_t *root_local;
  va_list ap;
  int ret;
  char *fmt_local;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = in_r2;
  uStack_4 = in_r3;
  iVar1 = json_vunpack_ex(root,(json_error_t *)0x0,0,fmt,(va_list)&uStack_8);
  return iVar1;
}

