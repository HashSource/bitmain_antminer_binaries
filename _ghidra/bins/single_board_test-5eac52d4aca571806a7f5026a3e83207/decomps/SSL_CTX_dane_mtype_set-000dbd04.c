
undefined4 SSL_CTX_dane_mtype_set(int param_1,int param_2,uint param_3,undefined1 param_4)

{
  undefined4 uVar1;
  void *pvVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  
  if (param_2 != 0 && param_3 == 0) {
    ERR_put_error(0x14,0x189,0xad,"ssl/ssl_lib.c",0xf4);
    return 0;
  }
  if (*(byte *)(param_1 + 0x208) < param_3) {
    pvVar2 = CRYPTO_realloc(*(void **)(param_1 + 0x200),(param_3 + 1) * 4,"ssl/ssl_lib.c",0xfd);
    iVar5 = 0xff;
    if (pvVar2 != (void *)0x0) {
      *(void **)(param_1 + 0x200) = pvVar2;
      pvVar3 = CRYPTO_realloc(*(void **)(param_1 + 0x204),param_3 + 1,"ssl/ssl_lib.c",0x104);
      if (pvVar3 != (void *)0x0) {
        uVar4 = (uint)*(byte *)(param_1 + 0x208);
        *(void **)(param_1 + 0x204) = pvVar3;
        iVar5 = uVar4 + 1;
        if (iVar5 < (int)param_3) {
          if ((int)(uVar4 + 2) < (int)(param_3 - 7)) {
            pvVar6 = (void *)((int)pvVar2 + (uVar4 + 0x1a) * 4);
            iVar9 = (int)pvVar3 + uVar4;
            do {
              iVar11 = iVar5 + 9;
              HintPreloadData(pvVar6);
              *(undefined4 *)((int)pvVar6 + -100) = 0;
              *(undefined1 *)(iVar9 + 1) = 0;
              iVar5 = iVar5 + 8;
              *(undefined4 *)((int)pvVar6 + -0x60) = 0;
              *(undefined1 *)(iVar9 + 2) = 0;
              *(undefined4 *)((int)pvVar6 + -0x5c) = 0;
              *(undefined1 *)(iVar9 + 3) = 0;
              *(undefined4 *)((int)pvVar6 + -0x58) = 0;
              *(undefined1 *)(iVar9 + 4) = 0;
              *(undefined4 *)((int)pvVar6 + -0x54) = 0;
              *(undefined1 *)(iVar9 + 5) = 0;
              *(undefined4 *)((int)pvVar6 + -0x50) = 0;
              *(undefined1 *)(iVar9 + 6) = 0;
              *(undefined4 *)((int)pvVar6 + -0x4c) = 0;
              *(undefined1 *)(iVar9 + 7) = 0;
              *(undefined4 *)((int)pvVar6 + -0x48) = 0;
              *(undefined1 *)(iVar9 + 8) = 0;
              pvVar6 = (void *)((int)pvVar6 + 0x20);
              iVar9 = iVar9 + 8;
            } while (iVar11 < (int)(param_3 - 7));
          }
          puVar7 = (undefined1 *)((int)pvVar3 + iVar5);
          puVar10 = (undefined4 *)((int)pvVar2 + iVar5 * 4);
          do {
            *puVar10 = 0;
            puVar8 = puVar7 + 1;
            *puVar7 = 0;
            puVar7 = puVar8;
            puVar10 = puVar10 + 1;
          } while ((int)puVar8 - (int)pvVar3 < (int)param_3);
        }
        *(char *)(param_1 + 0x208) = (char)param_3;
        goto LAB_000dbd2a;
      }
      iVar5 = 0x106;
    }
    ERR_put_error(0x14,0x189,0x41,"ssl/ssl_lib.c",iVar5);
    uVar1 = 0xffffffff;
  }
  else {
LAB_000dbd2a:
    uVar1 = 1;
    if (param_2 == 0) {
      param_4 = 0;
    }
    *(int *)(*(int *)(param_1 + 0x200) + param_3 * 4) = param_2;
    *(undefined1 *)(*(int *)(param_1 + 0x204) + param_3) = param_4;
  }
  return uVar1;
}

