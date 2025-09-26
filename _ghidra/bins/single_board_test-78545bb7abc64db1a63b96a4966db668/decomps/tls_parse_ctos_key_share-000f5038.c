
undefined4 tls_parse_ctos_key_share(int param_1,undefined4 *param_2)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined1 *puVar9;
  int iVar10;
  uint uVar11;
  undefined4 local_30;
  undefined4 local_2c [2];
  
  if ((*(int *)(param_1 + 0x8c) != 0) && (-1 < *(int *)(param_1 + 0x5a4) << 0x1e)) {
    return 1;
  }
  if (*(int *)(*(int *)(param_1 + 0x7c) + 0x358) != 0) {
    ossl_statem_fatal(param_1,0x50,0x1cf,0x44,"ssl/statem/extensions_srvr.c",0x277);
    return 0;
  }
  if (1 < (uint)param_2[1]) {
    puVar7 = (undefined1 *)*param_2;
    uVar5 = param_2[1] - 2;
    uVar11 = (uint)CONCAT11(*puVar7,puVar7[1]);
    if (uVar11 <= uVar5) {
      if (uVar11 == uVar5) {
        *param_2 = puVar7 + 2 + uVar11;
        param_2[1] = 0;
        tls1_get_supported_groups(param_1,&local_30,local_2c);
        iVar8 = *(int *)(param_1 + 0x578);
        if (iVar8 == 0) {
          ossl_statem_fatal(param_1,0x6d,0x1cf,0xd1,"ssl/statem/extensions_srvr.c",0x28c);
          return 0;
        }
        uVar6 = *(undefined4 *)(param_1 + 0x57c);
        if ((*(short *)(*(int *)(param_1 + 0x7c) + 0x356) != 0) && (uVar11 == 0)) {
          ossl_statem_fatal(param_1,0x2f,0x1cf,0x6c,"ssl/statem/extensions_srvr.c",0x297);
          return 0;
        }
        bVar3 = false;
        puVar7 = puVar7 + 2;
        while( true ) {
          puVar9 = puVar7;
          if (uVar11 == 0) {
            return 1;
          }
          if (uVar11 < 4) break;
          uVar5 = (uint)CONCAT11(puVar9[2],puVar9[3]);
          if (uVar11 - 4 < uVar5) break;
          uVar11 = (uVar11 - 4) - uVar5;
          puVar7 = puVar9 + 4 + uVar5;
          if (uVar5 == 0) break;
          if (!bVar3) {
            sVar1 = *(short *)(*(int *)(param_1 + 0x7c) + 0x356);
            sVar2 = CONCAT11(*puVar9,puVar9[1]);
            if ((sVar1 != 0) && ((sVar1 != sVar2 || (uVar11 != 0)))) {
              ossl_statem_fatal(param_1,0x2f,0x1cf,0x6c,"ssl/statem/extensions_srvr.c",0x2b3);
              return 0;
            }
            iVar4 = check_in_list(param_1,sVar2,uVar6,iVar8,0);
            if (iVar4 == 0) {
              ossl_statem_fatal(param_1,0x2f,0x1cf,0x6c,"ssl/statem/extensions_srvr.c",0x2ba);
              return 0;
            }
            iVar4 = check_in_list(param_1,sVar2,local_30,local_2c[0],1);
            if (iVar4 != 0) {
              iVar10 = *(int *)(param_1 + 0x7c);
              iVar4 = ssl_generate_param_group(sVar2);
              *(int *)(iVar10 + 0x358) = iVar4;
              if (iVar4 == 0) {
                ossl_statem_fatal(param_1,0x50,0x1cf,0x13a,"ssl/statem/extensions_srvr.c",0x2c6);
                return 0;
              }
              iVar4 = *(int *)(param_1 + 0x7c);
              *(short *)(iVar4 + 0x356) = sVar2;
              iVar4 = EVP_PKEY_set1_tls_encodedpoint
                                (*(undefined4 *)(iVar4 + 0x358),puVar9 + 4,uVar5);
              if (iVar4 == 0) {
                ossl_statem_fatal(param_1,0x2f,0x1cf,0x132,"ssl/statem/extensions_srvr.c",0x2d0);
                return 0;
              }
              bVar3 = true;
            }
          }
        }
        ossl_statem_fatal(param_1,0x32,0x1cf,0x9f,"ssl/statem/extensions_srvr.c",0x2a0);
        return 0;
      }
    }
  }
  ossl_statem_fatal(param_1,0x32,0x1cf,0x9f,"ssl/statem/extensions_srvr.c",0x27d);
  return 0;
}

