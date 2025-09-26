
void OPENSSL_sk_set_cmp_func(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  *(int *)(param_1 + 0x10) = param_2;
  bVar2 = iVar1 != param_2;
  if (bVar2) {
    param_3 = 0;
  }
  if (bVar2) {
    *(undefined4 *)(param_1 + 8) = param_3;
  }
  return;
}

