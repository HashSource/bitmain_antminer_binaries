
void OPENSSL_sk_pop_free(int *param_1,code *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    return;
  }
  iVar1 = *param_1;
  if (0 < iVar1) {
    iVar3 = 0;
    do {
      iVar2 = *(int *)(param_1[1] + iVar3 * 4);
      iVar3 = iVar3 + 1;
      if (iVar2 != 0) {
        (*param_2)(iVar2);
        iVar1 = *param_1;
      }
    } while (iVar3 < iVar1);
  }
  OPENSSL_sk_free(param_1);
  return;
}

