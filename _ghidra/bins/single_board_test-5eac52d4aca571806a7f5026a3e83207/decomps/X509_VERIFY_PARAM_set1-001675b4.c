
int X509_VERIFY_PARAM_set1(X509_VERIFY_PARAM *to,X509_VERIFY_PARAM *from)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = to->inh_flags;
  to->inh_flags = uVar2 | 1;
  iVar1 = X509_VERIFY_PARAM_inherit(to,from);
  to->inh_flags = uVar2;
  return iVar1;
}

