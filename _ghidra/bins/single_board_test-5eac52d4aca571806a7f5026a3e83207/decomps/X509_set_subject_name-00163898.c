
int X509_set_subject_name(X509 *x,X509_NAME *name)

{
  int iVar1;
  
  if (x != (X509 *)0x0) {
    iVar1 = X509_NAME_set((X509_NAME **)&x->ex_flags,name);
    return iVar1;
  }
  return 0;
}

