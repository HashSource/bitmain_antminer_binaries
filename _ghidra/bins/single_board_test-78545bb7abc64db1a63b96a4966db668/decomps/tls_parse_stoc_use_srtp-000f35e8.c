
undefined4 tls_parse_stoc_use_srtp(SSL *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  stack_st_SRTP_PROTECTION_PROFILE *psVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  int iVar10;
  
  uVar7 = param_2[1];
  if (1 < uVar7) {
    puVar9 = (undefined1 *)*param_2;
    uVar1 = *puVar9;
    uVar2 = puVar9[1];
    *param_2 = puVar9 + 2;
    param_2[1] = uVar7 - 2;
    if ((CONCAT11(uVar1,uVar2) == 2) && (1 < uVar7 - 2)) {
      uVar2 = puVar9[2];
      uVar1 = puVar9[3];
      param_2[1] = uVar7 - 4;
      *param_2 = puVar9 + 4;
      if (uVar7 - 4 != 0) {
        cVar3 = puVar9[4];
        *param_2 = puVar9 + 5;
        param_2[1] = uVar7 - 5;
        if (uVar7 - 5 == 0) {
          if (cVar3 != '\0') {
            ossl_statem_fatal(param_1,0x2f,0x1be,0x160,"ssl/statem/extensions_clnt.c",0x6b8);
            return 0;
          }
          psVar4 = SSL_get_srtp_profiles(param_1);
          if (psVar4 == (stack_st_SRTP_PROTECTION_PROFILE *)0x0) {
            ossl_statem_fatal(param_1,0x32,0x1be,0x167,"ssl/statem/extensions_clnt.c",0x6c0);
            return 0;
          }
          iVar10 = 0;
          while( true ) {
            iVar6 = OPENSSL_sk_num(psVar4);
            if (iVar6 <= iVar10) break;
            pvVar5 = (void *)OPENSSL_sk_value(psVar4,iVar10);
            iVar10 = iVar10 + 1;
            if (*(uint *)((int)pvVar5 + 4) == (uint)CONCAT11(uVar2,uVar1)) {
              param_1[3].tlsext_debug_arg = pvVar5;
              return 1;
            }
          }
          uVar8 = 0x6d2;
          goto LAB_000f3618;
        }
      }
    }
  }
  uVar8 = 0x6b1;
LAB_000f3618:
  ossl_statem_fatal(param_1,0x32,0x1be,0x161,"ssl/statem/extensions_clnt.c",uVar8);
  return 0;
}

