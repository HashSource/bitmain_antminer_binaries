
/* WARNING: Variable defined which should be unmapped: ap */

int json_unpack_ex(json_t *root,json_error_t *error,size_t flags,char *fmt,...)

{
  int iVar1;
  size_t flags_local;
  json_error_t *error_local;
  json_t *root_local;
  va_list ap;
  int ret;
  char *fmt_local;
  
  iVar1 = json_vunpack_ex(root,error,flags,fmt,(va_list)&stack0x00000000);
  return iVar1;
}

