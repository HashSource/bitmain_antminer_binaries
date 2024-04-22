
uint SSL_get_sigalgs(int param_1,int param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined *param_6,undefined *param_7)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x98);
  iVar2 = *(int *)(iVar1 + 0x124);
  if (iVar2 == 0) {
    return 0;
  }
  if (-1 < param_2) {
    if (*(int *)(iVar1 + 0x128) <= param_2 * 2) {
      return 0;
    }
    iVar1 = iVar2 + param_2 * 2;
    if (param_7 != (undefined *)0x0) {
      *param_7 = *(undefined *)(iVar2 + param_2 * 2);
    }
    if (param_6 != (undefined *)0x0) {
      *param_6 = *(undefined *)(iVar1 + 1);
    }
    tls1_lookup_sigalg(param_4,param_3,param_5,iVar1);
    iVar1 = *(int *)(param_1 + 0x98);
  }
  return *(uint *)(iVar1 + 0x128) >> 1;
}

