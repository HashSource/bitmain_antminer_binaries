
undefined4 tls_parse_ctos_use_srtp(SSL *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  byte bVar2;
  undefined1 uVar3;
  stack_st_SRTP_PROTECTION_PROFILE *psVar4;
  int iVar5;
  void *pvVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined1 *puVar13;
  int unaff_r11;
  
  psVar4 = SSL_get_srtp_profiles(param_1);
  if (psVar4 == (stack_st_SRTP_PROTECTION_PROFILE *)0x0) {
    return 1;
  }
  if (1 < (uint)param_2[1]) {
    puVar7 = (undefined1 *)*param_2;
    uVar9 = param_2[1] - 2;
    uVar1 = *puVar7;
    puVar13 = puVar7 + 2;
    bVar2 = puVar7[1];
    *param_2 = puVar13;
    param_2[1] = uVar9;
    uVar12 = (uint)CONCAT11(uVar1,bVar2);
    if (((bVar2 & 1) == 0) && (uVar12 <= uVar9)) {
      param_2[1] = uVar9 - uVar12;
      *param_2 = puVar13 + uVar12;
      psVar4 = SSL_get_srtp_profiles(param_1);
      param_1[3].tlsext_debug_arg = (void *)(uVar12 & 1);
      iVar5 = OPENSSL_sk_num();
LAB_000e70e2:
      puVar7 = puVar13 + 2;
      if (uVar12 != 0) {
        if (uVar12 == 1) {
          uVar10 = 0x214;
          goto LAB_000e7072;
        }
        uVar1 = *puVar13;
        uVar3 = puVar13[1];
        uVar12 = uVar12 - 2;
        if (0 < iVar5) {
          unaff_r11 = 0;
        }
        puVar13 = puVar7;
        if (0 < iVar5) {
          do {
            pvVar6 = (void *)OPENSSL_sk_value(psVar4,unaff_r11);
            if (*(uint *)((int)pvVar6 + 4) == (uint)CONCAT11(uVar1,uVar3)) {
              param_1[3].tlsext_debug_arg = pvVar6;
              iVar5 = unaff_r11;
              break;
            }
            unaff_r11 = unaff_r11 + 1;
          } while (iVar5 != unaff_r11);
        }
        goto LAB_000e70e2;
      }
      if (param_2[1] == 0) {
        ossl_statem_fatal(param_1,0x32,0x1d1,0x161,"ssl/statem/extensions_srvr.c",0x22d);
        return 0;
      }
      uVar12 = param_2[1] - 1;
      pbVar8 = (byte *)*param_2 + 1;
      uVar9 = (uint)*(byte *)*param_2;
      *param_2 = pbVar8;
      param_2[1] = uVar12;
      if (uVar9 <= uVar12) {
        *param_2 = pbVar8 + uVar9;
        param_2[1] = uVar12 - uVar9;
        if (uVar12 - uVar9 == 0) {
          return 1;
        }
      }
      uVar10 = 0x234;
      uVar11 = 0x160;
      goto LAB_000e707a;
    }
  }
  uVar10 = 0x208;
LAB_000e7072:
  uVar11 = 0x161;
LAB_000e707a:
  ossl_statem_fatal(param_1,0x32,0x1d1,uVar11,"ssl/statem/extensions_srvr.c",uVar10);
  return 0;
}

