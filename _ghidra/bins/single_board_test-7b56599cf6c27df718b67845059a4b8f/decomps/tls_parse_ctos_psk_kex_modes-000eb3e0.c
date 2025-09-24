
undefined4 tls_parse_ctos_psk_kex_modes(int param_1,undefined4 *param_2)

{
  int iVar1;
  byte *pbVar2;
  uint uVar4;
  byte *pbVar5;
  bool bVar6;
  byte *pbVar3;
  
  iVar1 = param_2[1];
  if (iVar1 != 0) {
    pbVar5 = (byte *)*param_2;
    uVar4 = (uint)*pbVar5;
    if (uVar4 <= iVar1 - 1U) {
      if (uVar4 == iVar1 - 1U) {
        *param_2 = pbVar5 + 1 + uVar4;
        param_2[1] = 0;
        pbVar3 = pbVar5 + 1;
        if (uVar4 != 0) {
          do {
            pbVar2 = pbVar3 + 1;
            if (*pbVar3 == 1) {
              *(uint *)(param_1 + 0x5a4) = *(uint *)(param_1 + 0x5a4) | 2;
            }
            else if (*pbVar3 == 0) {
              uVar4 = *(int *)(param_1 + 0x4ec) << 0x15;
              bVar6 = (int)uVar4 < 0;
              if (bVar6) {
                uVar4 = *(uint *)(param_1 + 0x5a4) | 1;
              }
              if (bVar6) {
                *(uint *)(param_1 + 0x5a4) = uVar4;
              }
            }
            pbVar3 = pbVar2;
          } while (pbVar5 + iVar1 != pbVar2);
          return 1;
        }
      }
    }
  }
  ossl_statem_fatal(param_1,0x32,0x23c,0x6e,"ssl/statem/extensions_srvr.c",0x253);
  return 0;
}

