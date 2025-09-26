
int rinf_cb(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 1) {
    return 1;
  }
  iVar2 = *param_2;
  iVar1 = OPENSSL_sk_new_null();
  *(int *)(iVar2 + 0x18) = iVar1;
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

