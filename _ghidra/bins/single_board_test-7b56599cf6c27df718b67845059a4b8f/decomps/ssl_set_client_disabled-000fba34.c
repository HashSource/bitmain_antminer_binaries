
undefined4
ssl_set_client_disabled(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x7c);
  *(undefined4 *)(iVar1 + 0x2a4) = 0;
  *(undefined4 *)(iVar1 + 0x2a0) = 0;
  ssl_set_sig_mask(iVar1 + 0x2a4,param_1,0x5000e,iVar1,param_4);
  iVar1 = ssl_get_min_max_version
                    (param_1,*(int *)(param_1 + 0x7c) + 0x2a8,*(int *)(param_1 + 0x7c) + 0x2ac,0);
  if (iVar1 != 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x4c0) == 0) {
    iVar1 = *(int *)(param_1 + 0x7c);
    *(uint *)(iVar1 + 0x2a4) = *(uint *)(iVar1 + 0x2a4) | 0x10;
    *(uint *)(iVar1 + 0x2a0) = *(uint *)(iVar1 + 0x2a0) | 0x1c8;
  }
  if (-1 < *(int *)(param_1 + 0x648) << 0x1a) {
    iVar1 = *(int *)(param_1 + 0x7c);
    *(uint *)(iVar1 + 0x2a4) = *(uint *)(iVar1 + 0x2a4) | 0x40;
    *(uint *)(iVar1 + 0x2a0) = *(uint *)(iVar1 + 0x2a0) | 0x20;
    return 1;
  }
  return 1;
}

