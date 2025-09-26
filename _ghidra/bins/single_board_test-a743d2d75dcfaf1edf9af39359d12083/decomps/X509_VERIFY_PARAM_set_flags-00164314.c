
int X509_VERIFY_PARAM_set_flags(X509_VERIFY_PARAM *param,ulong flags)

{
  ulong uVar1;
  
  uVar1 = flags | param->flags;
  if ((flags & 0x780) != 0) {
    uVar1 = uVar1 | 0x80;
  }
  param->flags = uVar1;
  return 1;
}

