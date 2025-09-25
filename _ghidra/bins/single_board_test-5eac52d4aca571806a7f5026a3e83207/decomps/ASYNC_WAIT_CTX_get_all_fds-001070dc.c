
undefined4 ASYNC_WAIT_CTX_get_all_fds(int *param_1,undefined4 *param_2,int *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *param_1;
  *param_3 = 0;
  do {
    if (iVar2 == 0) {
      return 1;
    }
    while (*(int *)(iVar2 + 0x14) != 0) {
      iVar2 = *(int *)(iVar2 + 0x18);
      if (iVar2 == 0) {
        return 1;
      }
    }
    puVar1 = param_2;
    if (param_2 != (undefined4 *)0x0) {
      puVar1 = param_2 + 1;
      *param_2 = *(undefined4 *)(iVar2 + 4);
    }
    iVar2 = *(int *)(iVar2 + 0x18);
    *param_3 = *param_3 + 1;
    param_2 = puVar1;
  } while( true );
}

