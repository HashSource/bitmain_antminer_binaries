
undefined4
ASYNC_WAIT_CTX_get_changed_fds
          (int *param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,int *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  
  *param_3 = param_1[1];
  *param_5 = param_1[2];
  if (param_2 == (undefined4 *)0x0 && param_4 == (undefined4 *)0x0) {
    return 1;
  }
  iVar1 = *param_1;
joined_r0x0010711a:
  puVar2 = param_4;
  if (iVar1 == 0) {
    return 1;
  }
  do {
    param_4 = puVar2;
    if (*(int *)(iVar1 + 0x14) == 0) {
      if (*(int *)(iVar1 + 0x10) == 0) break;
    }
    else {
      if ((*(int *)(iVar1 + 0x10) != 0) || (puVar2 == (undefined4 *)0x0)) break;
      param_4 = puVar2 + 1;
      *puVar2 = *(undefined4 *)(iVar1 + 4);
      if ((*(int *)(iVar1 + 0x10) == 0) || (*(int *)(iVar1 + 0x14) != 0)) break;
    }
    if (param_2 == (undefined4 *)0x0) break;
    puVar2 = (undefined4 *)(iVar1 + 4);
    iVar1 = *(int *)(iVar1 + 0x18);
    *param_2 = *puVar2;
    param_2 = param_2 + 1;
    puVar2 = param_4;
    if (iVar1 == 0) {
      return 1;
    }
  } while( true );
  iVar1 = *(int *)(iVar1 + 0x18);
  goto joined_r0x0010711a;
}

