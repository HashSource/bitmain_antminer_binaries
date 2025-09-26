
int SSL_client_hello_get0_ext(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x5c8);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x264) != 0) {
      puVar2 = *(undefined4 **)(iVar1 + 0x268);
      iVar3 = 0;
      do {
        iVar3 = iVar3 + 1;
        if ((puVar2[2] != 0) && (puVar2[4] == param_2)) {
          if (param_3 != (undefined4 *)0x0) {
            *param_3 = *puVar2;
          }
          if (param_4 == (undefined4 *)0x0) {
            return 1;
          }
          *param_4 = puVar2[1];
          return 1;
        }
        puVar2 = puVar2 + 6;
      } while (iVar3 != *(int *)(iVar1 + 0x264));
    }
    iVar1 = 0;
  }
  return iVar1;
}

