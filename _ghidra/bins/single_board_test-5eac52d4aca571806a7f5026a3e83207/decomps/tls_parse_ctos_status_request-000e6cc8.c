
byte * tls_parse_ctos_status_request(int param_1,undefined4 *param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  byte *pbVar2;
  X509_EXTENSIONS *pXVar3;
  OCSP_RESPID *a;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  byte *local_2c [2];
  
  if (param_4 != 0 || *(int *)(param_1 + 0x8c) != 0) {
    return (byte *)0x1;
  }
  if (param_2[1] == 0) {
    ossl_statem_fatal(param_1,0x32,0x241,0x6e,"ssl/statem/extensions_srvr.c",0x15b);
    return (byte *)0x0;
  }
  pbVar2 = (byte *)*param_2;
  pbVar5 = pbVar2 + 1;
  bVar1 = *pbVar2;
  *(uint *)(param_1 + 0x53c) = (uint)bVar1;
  bVar11 = bVar1 != 1;
  iVar4 = param_2[1];
  if (bVar11) {
    pbVar2 = (byte *)0x1;
  }
  *param_2 = pbVar5;
  uVar6 = iVar4 - 1;
  param_2[1] = uVar6;
  if (bVar11) {
    uVar6 = 0xffffffff;
  }
  if (bVar11) {
    *(uint *)(param_1 + 0x53c) = uVar6;
    return pbVar2;
  }
  if (1 < uVar6) {
    uVar6 = iVar4 - 3;
    pbVar5 = pbVar2 + 3;
    uVar9 = (uint)CONCAT11(pbVar2[1],pbVar2[2]);
    if (uVar9 <= uVar6) {
      param_2[1] = uVar6 - uVar9;
      *param_2 = pbVar5 + uVar9;
      OPENSSL_sk_pop_free(*(undefined4 *)(param_1 + 0x54c),(undefined *)0x13f3f5);
      if (uVar9 == 0) {
        *(undefined4 *)(param_1 + 0x54c) = 0;
LAB_000e6d6c:
        if (1 < (uint)param_2[1]) {
          puVar7 = (undefined1 *)*param_2;
          uVar6 = param_2[1] - 2;
          uVar9 = (uint)CONCAT11(*puVar7,puVar7[1]);
          if (uVar9 <= uVar6) {
            pbVar2 = puVar7 + 2;
            if (uVar9 == uVar6) {
              *param_2 = pbVar2 + uVar9;
              param_2[1] = 0;
              if (uVar9 != 0) {
                local_2c[0] = pbVar2;
                OPENSSL_sk_pop_free(*(undefined4 *)(param_1 + 0x550),0x1691dd);
                pXVar3 = d2i_X509_EXTENSIONS((X509_EXTENSIONS **)0x0,local_2c,uVar9);
                *(X509_EXTENSIONS **)(param_1 + 0x550) = pXVar3;
                if ((pXVar3 == (X509_EXTENSIONS *)0x0) || (local_2c[0] != pbVar2 + uVar9)) {
                  uVar8 = 0x1b4;
                  goto LAB_000e6dce;
                }
              }
              return (byte *)0x1;
            }
          }
        }
        uVar8 = 0x1a7;
      }
      else {
        iVar4 = OPENSSL_sk_new_null();
        *(int *)(param_1 + 0x54c) = iVar4;
        if (iVar4 == 0) {
          ossl_statem_fatal(param_1,0x50,0x241,0x41,"ssl/statem/extensions_srvr.c",0x176);
          return (byte *)0x0;
        }
        if (uVar9 != 1) {
          do {
            uVar10 = uVar9 - 2;
            pbVar2 = pbVar5 + 2;
            uVar6 = (uint)CONCAT11(*pbVar5,pbVar5[1]);
            uVar9 = uVar10 - uVar6;
            if ((uVar10 < uVar6) || (uVar6 == 0)) break;
            local_2c[0] = pbVar2;
            a = d2i_OCSP_RESPID((OCSP_RESPID **)0x0,local_2c,uVar6);
            pbVar5 = local_2c[0];
            if (a == (OCSP_RESPID *)0x0) {
              uVar8 = 399;
              goto LAB_000e6dce;
            }
            if (local_2c[0] != pbVar2 + uVar6) {
              OCSP_RESPID_free(a);
              uVar8 = 0x196;
              goto LAB_000e6dce;
            }
            iVar4 = OPENSSL_sk_push(*(undefined4 *)(param_1 + 0x54c),a);
            if (iVar4 == 0) {
              OCSP_RESPID_free(a);
              ossl_statem_fatal(param_1,0x50,0x241,0x44,"ssl/statem/extensions_srvr.c",0x19e);
              return (byte *)0x0;
            }
            if (uVar9 == 0) goto LAB_000e6d6c;
          } while (uVar9 != 1);
        }
        uVar8 = 0x185;
      }
      goto LAB_000e6dce;
    }
  }
  uVar8 = 0x169;
LAB_000e6dce:
  ossl_statem_fatal(param_1,0x32,0x241,0x6e,"ssl/statem/extensions_srvr.c",uVar8);
  return (byte *)0x0;
}

