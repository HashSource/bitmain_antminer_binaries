
int X509_VERIFY_PARAM_clear_flags(X509_VERIFY_PARAM *param,ulong flags)

{
  param->flags = param->flags & ~flags;
  return 1;
}

