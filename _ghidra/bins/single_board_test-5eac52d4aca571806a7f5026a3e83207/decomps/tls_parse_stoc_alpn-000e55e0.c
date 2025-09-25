
undefined4 tls_parse_stoc_alpn(int param_1,int *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  iVar9 = *(int *)(param_1 + 0x7c);
  if (*(int *)(iVar9 + 0x350) == 0) {
    ossl_statem_fatal(param_1,0x6e,0x243,0x6e,"ssl/statem/extensions_clnt.c",0x665);
    return 0;
  }
  uVar3 = param_2[1];
  if (1 < uVar3) {
    puVar6 = (undefined1 *)*param_2;
    iVar7 = uVar3 - 2;
    uVar2 = *puVar6;
    uVar1 = puVar6[1];
    param_2[1] = iVar7;
    *param_2 = (int)(puVar6 + 2);
    uVar8 = (uint)CONCAT11(uVar2,uVar1) - iVar7;
    if (uVar8 != 0) {
      uVar8 = 1;
    }
    if (iVar7 == 0) {
      uVar8 = uVar8 | 1;
    }
    if (uVar8 == 0) {
      uVar8 = (uint)(byte)puVar6[2];
      param_2[1] = uVar3 - 3;
      *param_2 = (int)(puVar6 + 3);
      if (uVar8 == uVar3 - 3) {
        CRYPTO_free(*(void **)(iVar9 + 0x340));
        iVar7 = *(int *)(param_1 + 0x7c);
        pvVar4 = CRYPTO_malloc(uVar8,"ssl/statem/extensions_clnt.c",0x676);
        iVar9 = *(int *)(param_1 + 0x7c);
        *(void **)(iVar7 + 0x340) = pvVar4;
        pvVar4 = *(void **)(iVar9 + 0x340);
        if (pvVar4 == (void *)0x0) {
          *(undefined4 *)(iVar9 + 0x344) = 0;
          ossl_statem_fatal(param_1,0x50,0x243,0x44,"ssl/statem/extensions_clnt.c",0x67a);
          return 0;
        }
        if (uVar8 <= (uint)param_2[1]) {
          memcpy(pvVar4,(void *)*param_2,uVar8);
          iVar9 = *(int *)(param_1 + 0x474);
          iVar7 = *(int *)(param_1 + 0x7c);
          pvVar4 = *(void **)(iVar9 + 0x1e4);
          *param_2 = *param_2 + uVar8;
          param_2[1] = param_2[1] - uVar8;
          *(uint *)(iVar7 + 0x344) = uVar8;
          if (pvVar4 == (void *)0x0) {
            *(undefined4 *)(param_1 + 0x5b0) = 0;
            if (*(int *)(param_1 + 0x8c) == 0) {
              uVar5 = CRYPTO_memdup(*(undefined4 *)(iVar7 + 0x340),uVar8,
                                    "ssl/statem/extensions_clnt.c",0x696);
              iVar7 = *(int *)(param_1 + 0x474);
              *(undefined4 *)(iVar9 + 0x1e4) = uVar5;
              if (*(int *)(iVar7 + 0x1e4) != 0) {
                *(undefined4 *)(iVar7 + 0x1e8) = *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x344);
                return 1;
              }
              *(undefined4 *)(iVar7 + 0x1e8) = 0;
              ossl_statem_fatal(param_1,0x50,0x243,0x44,"ssl/statem/extensions_clnt.c",0x69a);
              return 0;
            }
          }
          else {
            if ((*(size_t *)(iVar9 + 0x1e8) == uVar8) &&
               (iVar9 = memcmp(pvVar4,*(void **)(iVar7 + 0x340),*(size_t *)(iVar9 + 0x1e8)),
               iVar9 == 0)) {
              iVar9 = *(int *)(param_1 + 0x8c);
            }
            else {
              iVar9 = *(int *)(param_1 + 0x8c);
              *(undefined4 *)(param_1 + 0x5b0) = 0;
            }
            if (iVar9 == 0) {
              ossl_statem_fatal(param_1,0x50,0x243,0x44,"ssl/statem/extensions_clnt.c",0x692);
              return 0;
            }
          }
          return 1;
        }
        ossl_statem_fatal(param_1,0x32,0x243,0x6e,"ssl/statem/extensions_clnt.c",0x67f);
        return 0;
      }
    }
  }
  ossl_statem_fatal(param_1,0x32,0x243,0x6e,"ssl/statem/extensions_clnt.c",0x672);
  return 0;
}

