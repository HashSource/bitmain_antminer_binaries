
undefined4 tls_parse_ctos_ec_pt_formats(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  
  if (param_2[1] != 0) {
    uVar2 = param_2[1] - 1;
    uVar3 = (uint)*(byte *)*param_2;
    if (uVar3 <= uVar2) {
      pbVar4 = (byte *)*param_2 + 1;
      if (uVar3 == uVar2) {
        *param_2 = pbVar4 + uVar3;
        param_2[1] = 0;
        if (uVar3 != 0) {
          if (*(int *)(param_1 + 0x8c) != 0) {
            return 1;
          }
          CRYPTO_free(*(void **)(param_1 + 0x56c));
          *(undefined4 *)(param_1 + 0x56c) = 0;
          *(undefined4 *)(param_1 + 0x568) = 0;
          iVar1 = CRYPTO_memdup(pbVar4,uVar3,"ssl/statem/../packet_local.h",0x1ce);
          *(int *)(param_1 + 0x56c) = iVar1;
          if (iVar1 == 0) {
            ossl_statem_fatal(param_1,0x50,0x239,0x44,"ssl/statem/extensions_srvr.c",0x109);
            return 0;
          }
          *(uint *)(param_1 + 0x568) = uVar3;
          return 1;
        }
      }
    }
  }
  ossl_statem_fatal(param_1,0x32,0x239,0x6e,"ssl/statem/extensions_srvr.c",0x100);
  return 0;
}

