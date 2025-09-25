
undefined4 final_alpn(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0 && *(int *)(param_1 + 0x1c) == 0) {
    if (*(int *)(*(int *)(param_1 + 0x474) + 0x1e4) != 0) {
      *(undefined4 *)(param_1 + 0x5b0) = 0;
    }
  }
  else if (((*(int *)(param_1 + 0x1c) != 0) &&
           (-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c)) &&
          (iVar2 = **(int **)(param_1 + 4), iVar2 != 0x10000 && 0x303 < iVar2)) {
    uVar1 = tls_handle_alpn();
    return uVar1;
  }
  return 1;
}

