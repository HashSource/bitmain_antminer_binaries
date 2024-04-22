
/* Local variable ret:int[r0:4] conflicts with parameter, skipped. */

int json_unpack(json_t *root,char *fmt,...)

{
  int iVar1;
  va_list in_stack_00000048;
  va_list ap;
  char *fmt_local;
  
  iVar1 = json_vunpack_ex(root,(json_error_t *)0x0,0,fmt,in_stack_00000048);
  return iVar1;
}

