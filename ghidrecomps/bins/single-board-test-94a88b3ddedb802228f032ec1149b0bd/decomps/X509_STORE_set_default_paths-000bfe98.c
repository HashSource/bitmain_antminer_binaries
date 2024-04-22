
int X509_STORE_set_default_paths(X509_STORE *ctx)

{
  X509_LOOKUP_METHOD *pXVar1;
  X509_LOOKUP *pXVar2;
  
  pXVar1 = X509_LOOKUP_file();
  pXVar2 = X509_STORE_add_lookup(ctx,pXVar1);
  if (pXVar2 != (X509_LOOKUP *)0x0) {
    X509_LOOKUP_ctrl(pXVar2,1,(char *)0x0,3,(char **)0x0);
    pXVar1 = X509_LOOKUP_hash_dir();
    pXVar2 = X509_STORE_add_lookup(ctx,pXVar1);
    if (pXVar2 != (X509_LOOKUP *)0x0) {
      X509_LOOKUP_ctrl(pXVar2,2,(char *)0x0,3,(char **)0x0);
      ERR_clear_error();
      return 1;
    }
  }
  return 0;
}

