
undefined4 ssl_cache_cipherlist(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  int extraout_r1;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  
  if (param_3 == 0) {
    uVar6 = 2;
  }
  else {
    uVar6 = 3;
  }
  if (param_2[1] == 0) {
    ossl_statem_fatal(param_1,0x2f,0x208,0xb7,"ssl/ssl_lib.c",0x14f7);
    return 0;
  }
  __aeabi_uidivmod(param_2[1],uVar6);
  if (extraout_r1 != 0) {
    ossl_statem_fatal(param_1,0x32,0x208,0x97,"ssl/ssl_lib.c",0x14fd);
    return 0;
  }
  CRYPTO_free(*(void **)(*(int *)(param_1 + 0x7c) + 0x248));
  iVar7 = *(int *)(param_1 + 0x7c);
  *(undefined4 *)(iVar7 + 0x248) = 0;
  *(undefined4 *)(iVar7 + 0x24c) = 0;
  if (param_3 == 0) {
    CRYPTO_free((void *)0x0);
    *(undefined4 *)(iVar7 + 0x24c) = 0;
    iVar1 = param_2[1];
    *(undefined4 *)(iVar7 + 0x248) = 0;
    if (iVar1 != 0) {
      iVar3 = CRYPTO_memdup(*param_2,iVar1,"ssl/packet_local.h",0x1ce);
      *(int *)(iVar7 + 0x248) = iVar3;
      if (iVar3 == 0) {
        ossl_statem_fatal(param_1,0x50,0x208,0x44,"ssl/ssl_lib.c",0x152f);
        return 0;
      }
      *(int *)(iVar7 + 0x24c) = iVar1;
    }
  }
  else {
    iVar7 = param_2[1];
    pcVar5 = (char *)*param_2;
    iVar1 = __aeabi_uidiv(iVar7,uVar6);
    puVar2 = (undefined2 *)CRYPTO_malloc(iVar1 << 1,"ssl/ssl_lib.c",0x1512);
    iVar1 = *(int *)(param_1 + 0x7c);
    *(undefined2 **)(iVar1 + 0x248) = puVar2;
    if (puVar2 == (undefined2 *)0x0) {
      ossl_statem_fatal(param_1,0x50,0x208,0x41,"ssl/ssl_lib.c",0x1516);
      return 0;
    }
    *(undefined4 *)(iVar1 + 0x24c) = 0;
    if (iVar7 != 0) {
      uVar4 = iVar7 - 1;
      do {
        iVar7 = iVar7 + -3;
        if (*pcVar5 == '\0') {
          if (uVar4 < 2) {
LAB_000e4756:
            ossl_statem_fatal(param_1,0x32,0x208,0xf0,"ssl/ssl_lib.c",0x1523);
            CRYPTO_free(*(void **)(*(int *)(param_1 + 0x7c) + 0x248));
            iVar7 = *(int *)(param_1 + 0x7c);
            *(undefined4 *)(iVar7 + 0x248) = 0;
            *(undefined4 *)(iVar7 + 0x24c) = 0;
            return 0;
          }
          *puVar2 = *(undefined2 *)(pcVar5 + 1);
          *(int *)(*(int *)(param_1 + 0x7c) + 0x24c) =
               *(int *)(*(int *)(param_1 + 0x7c) + 0x24c) + 2;
        }
        else if (uVar4 < 2) goto LAB_000e4756;
        puVar2 = puVar2 + 1;
        uVar4 = uVar4 - 3;
        pcVar5 = pcVar5 + 3;
      } while (iVar7 != 0);
    }
  }
  return 1;
}

