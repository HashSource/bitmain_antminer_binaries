
/* WARNING: Variable defined which should be unmapped: ap */
/* Local variable ret:int[r0:4] conflicts with parameter, skipped. */

int json_unpack_ex(json_t *root,json_error_t *error,size_t flags,char *fmt,...)

{
  int iVar1;
  va_list in_stack_00000050;
  va_list ap;
  char *fmt_local;
  
  iVar1 = json_vunpack_ex(root,error,flags,fmt,in_stack_00000050);
  return iVar1;
}

