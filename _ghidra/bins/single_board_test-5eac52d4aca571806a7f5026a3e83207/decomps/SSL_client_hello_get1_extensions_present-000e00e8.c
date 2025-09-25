
undefined4 SSL_client_hello_get1_extensions_present(int param_1,undefined4 *param_2,uint *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  void *ptr;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  iVar4 = *(int *)(param_1 + 0x5c8);
  if (iVar4 == 0) {
    return 0;
  }
  if (param_3 == (uint *)0x0 || param_2 == (undefined4 *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar6 = 0;
    if (*(int *)(iVar4 + 0x264) != 0) {
      iVar5 = *(int *)(iVar4 + 0x268);
      iVar4 = iVar5 + *(int *)(iVar4 + 0x264) * 0x18;
      do {
        piVar1 = (int *)(iVar5 + 8);
        iVar5 = iVar5 + 0x18;
        if (*piVar1 != 0) {
          uVar6 = uVar6 + 1;
        }
      } while (iVar4 != iVar5);
      if (uVar6 != 0) {
        ptr = CRYPTO_malloc(uVar6 << 2,"ssl/ssl_lib.c",0x1451);
        if (ptr == (void *)0x0) {
          ERR_put_error(0x14,0x273,0x41,"ssl/ssl_lib.c",0x1453);
          return 0;
        }
        iVar4 = *(int *)(param_1 + 0x5c8);
        uVar7 = *(uint *)(iVar4 + 0x264);
        if (uVar7 != 0) {
          iVar5 = *(int *)(iVar4 + 0x268);
          uVar3 = 0;
          do {
            uVar3 = uVar3 + 1;
            if (*(int *)(iVar5 + 8) != 0) {
              if (uVar6 <= *(uint *)(iVar5 + 0x14)) {
                CRYPTO_free(ptr);
                return 0;
              }
              *(undefined4 *)((int)ptr + *(uint *)(iVar5 + 0x14) * 4) =
                   *(undefined4 *)(iVar5 + 0x10);
              uVar7 = *(uint *)(iVar4 + 0x264);
            }
            iVar5 = iVar5 + 0x18;
          } while (uVar3 < uVar7);
        }
        *param_2 = ptr;
        *param_3 = uVar6;
        return 1;
      }
    }
    uVar2 = 1;
    *param_2 = 0;
    *param_3 = 0;
  }
  return uVar2;
}

