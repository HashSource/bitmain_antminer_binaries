
bool cmd_VerifyCAFile(int param_1,char *param_2)

{
  X509_STORE *ctx;
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    if (*(int *)(param_1 + 0x10) == 0) {
      return true;
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x404);
    ctx = *(X509_STORE **)(iVar1 + 0xec);
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0xc0);
    ctx = *(X509_STORE **)(iVar1 + 0xec);
  }
  if (ctx == (X509_STORE *)0x0) {
    ctx = X509_STORE_new();
    *(X509_STORE **)(iVar1 + 0xec) = ctx;
    if (ctx == (X509_STORE *)0x0) {
      return false;
    }
  }
  iVar1 = X509_STORE_load_locations(ctx,param_2,(char *)0x0);
  return 0 < iVar1;
}

