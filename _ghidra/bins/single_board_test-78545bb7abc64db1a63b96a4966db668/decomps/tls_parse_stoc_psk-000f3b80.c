
undefined4 tls_parse_stoc_psk(int param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  SSL_SESSION *ses;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  uchar *puVar6;
  uchar *puVar7;
  int iVar8;
  uint uVar9;
  SSL_SESSION *ses_00;
  undefined4 uVar10;
  
  if (1 < (uint)param_2[1]) {
    puVar5 = (undefined1 *)*param_2;
    iVar8 = param_2[1] - 2;
    uVar1 = *puVar5;
    uVar2 = puVar5[1];
    *param_2 = puVar5 + 2;
    param_2[1] = iVar8;
    if (iVar8 == 0) {
      uVar9 = (uint)CONCAT11(uVar1,uVar2);
      if (*(uint *)(param_1 + 0x5c4) <= uVar9) {
        ossl_statem_fatal(param_1,0x2f,0x1f6,0x72,"ssl/statem/extensions_clnt.c",0x7bf);
        return 0;
      }
      ses_00 = *(SSL_SESSION **)(param_1 + 0x478);
      if (uVar9 == 0) {
        if (*(uint *)(param_1 + 0x5c4) == 2 || ses_00 == (SSL_SESSION *)0x0) {
          *(undefined4 *)(param_1 + 0x8c) = 1;
          SSL_SESSION_free(ses_00);
          *(undefined4 *)(param_1 + 0x478) = 0;
          return 1;
        }
      }
      else if (ses_00 == (SSL_SESSION *)0x0) {
        ossl_statem_fatal(param_1,0x50,0x1f6,0x44,"ssl/statem/extensions_clnt.c",0x7d2);
        return 0;
      }
      ses = *(SSL_SESSION **)(param_1 + 0x474);
      if ((((*(uint *)(param_1 + 0x68) & 0xfffffffb) != 3) ||
          (ses->tlsext_ellipticcurvelist_length != 0)) ||
         (ses_00->tlsext_ellipticcurvelist_length == 0)) {
        puVar4 = (undefined4 *)(param_1 + 0xcc);
        puVar6 = ses_00->key_arg;
        do {
          puVar7 = puVar6 + 0x10;
          uVar10 = *(undefined4 *)(puVar6 + 4);
          iVar8 = *(int *)(puVar6 + 8);
          uVar3 = *(undefined4 *)(puVar6 + 0xc);
          *puVar4 = *(undefined4 *)puVar6;
          puVar4[1] = uVar10;
          puVar4[2] = iVar8;
          puVar4[3] = uVar3;
          puVar4 = puVar4 + 4;
          puVar6 = puVar7;
        } while (puVar7 != ses_00->session_id);
      }
      SSL_SESSION_free(ses);
      uVar3 = *(undefined4 *)(param_1 + 0x478);
      *(undefined4 *)(param_1 + 0x478) = 0;
      *(undefined4 *)(param_1 + 0x8c) = 1;
      *(undefined4 *)(param_1 + 0x474) = uVar3;
      if (uVar9 == 0) {
        return 1;
      }
      *(undefined4 *)(param_1 + 0x5b0) = 0;
      return 1;
    }
  }
  ossl_statem_fatal(param_1,0x32,0x1f6,0x9f,"ssl/statem/extensions_clnt.c",0x7b9);
  return 0;
}

