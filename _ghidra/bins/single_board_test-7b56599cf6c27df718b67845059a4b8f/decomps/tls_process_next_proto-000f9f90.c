
undefined4 tls_process_next_proto(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  
  if (param_2[1] != 0) {
    uVar1 = param_2[1] - 1;
    pbVar4 = (byte *)*param_2 + 1;
    uVar3 = (uint)*(byte *)*param_2;
    if (uVar3 <= uVar1) {
      iVar2 = uVar1 - uVar3;
      *param_2 = pbVar4 + uVar3;
      param_2[1] = iVar2;
      if (iVar2 != 0) {
        uVar1 = (uint)pbVar4[uVar3];
        if (uVar1 <= iVar2 - 1U) {
          iVar2 = (iVar2 - 1U) - uVar1;
          *param_2 = pbVar4 + uVar3 + uVar1 + 1;
          param_2[1] = iVar2;
          if (iVar2 == 0) {
            CRYPTO_free(*(void **)(param_1 + 0x59c));
            *(undefined4 *)(param_1 + 0x59c) = 0;
            if (uVar3 != 0) {
              iVar2 = CRYPTO_memdup(pbVar4,uVar3,"ssl/statem/../packet_local.h",0x1ce);
              *(int *)(param_1 + 0x59c) = iVar2;
              if (iVar2 == 0) {
                *(undefined4 *)(param_1 + 0x5a0) = 0;
                ossl_statem_fatal(param_1,0x50,0x17f,0x44,"ssl/statem/statem_srvr.c",0x109d);
                return 0;
              }
            }
            *(uint *)(param_1 + 0x5a0) = uVar3;
            return 3;
          }
        }
      }
    }
  }
  ossl_statem_fatal(param_1,0x32,0x17f,0x9f,"ssl/statem/statem_srvr.c",0x1096);
  return 0;
}

