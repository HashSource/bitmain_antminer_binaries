
undefined4 tls_parse_ctos_alpn(int param_1,undefined4 *param_2)

{
  byte *pbVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = *(int *)(param_1 + 0x7c);
  if ((*(int *)(iVar10 + 0x180) != 0) && (*(int *)(iVar10 + 0x204) != 0)) {
    return 1;
  }
  if (1 < (uint)param_2[1]) {
    puVar7 = (undefined1 *)*param_2;
    uVar2 = param_2[1] - 2;
    uVar6 = (uint)CONCAT11(*puVar7,puVar7[1]);
    if (uVar6 <= uVar2) {
      pbVar8 = puVar7 + 2;
      if (uVar6 == uVar2) {
        *param_2 = pbVar8 + uVar6;
        param_2[1] = 0;
        pbVar1 = pbVar8;
        uVar2 = uVar6;
        if (1 < uVar6) {
          while( true ) {
            uVar4 = (uint)*pbVar1;
            uVar5 = (uVar2 - 1) - uVar4;
            if ((uVar2 - 1 < uVar4) || (uVar4 == 0)) break;
            pbVar1 = pbVar1 + uVar4 + 1;
            uVar2 = uVar5;
            if (uVar5 == 0) {
              CRYPTO_free(*(void **)(iVar10 + 0x348));
              iVar9 = *(int *)(param_1 + 0x7c);
              *(undefined4 *)(iVar9 + 0x348) = 0;
              *(undefined4 *)(iVar9 + 0x34c) = 0;
              CRYPTO_free((void *)0x0);
              *(undefined4 *)(iVar9 + 0x348) = 0;
              *(undefined4 *)(iVar9 + 0x34c) = 0;
              iVar10 = CRYPTO_memdup(pbVar8,uVar6,"ssl/statem/../packet_local.h",0x1ce);
              *(int *)(iVar9 + 0x348) = iVar10;
              if (iVar10 == 0) {
                ossl_statem_fatal(param_1,0x50,0x237,0x44,"ssl/statem/extensions_srvr.c",0x1f0);
                return 0;
              }
              *(uint *)(iVar9 + 0x34c) = uVar6;
              return 1;
            }
          }
          uVar3 = 0x1e5;
          goto LAB_000eb196;
        }
      }
    }
  }
  uVar3 = 0x1db;
LAB_000eb196:
  ossl_statem_fatal(param_1,0x32,0x237,0x6e,"ssl/statem/extensions_srvr.c",uVar3);
  return 0;
}

