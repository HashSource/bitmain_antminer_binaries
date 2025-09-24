
undefined4 tls_construct_stoc_supported_versions(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  if (-1 < *(int *)(((int *)param_1[1])[0x19] + 0x30) << 0x1c) {
    iVar2 = *(int *)param_1[1];
    iVar1 = iVar2 + -0x10000;
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    if (iVar2 < 0x304) {
      iVar1 = 0;
    }
    if (iVar1 != 0) {
      iVar1 = WPACKET_put_bytes__(param_2,param_2,0x2b,0,2);
      if (iVar1 != 0) {
        uVar4 = WPACKET_start_sub_packet_len__(param_2,2);
        if ((((int)uVar4 != 0) &&
            (iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar4 >> 0x20),*param_1,
                                         *param_1 >> 0x1f,2), iVar1 != 0)) &&
           (iVar1 = WPACKET_close(param_2), iVar1 != 0)) {
          return 1;
        }
      }
      uVar3 = 0x689;
      goto LAB_000ecb4a;
    }
  }
  uVar3 = 0x67f;
LAB_000ecb4a:
  ossl_statem_fatal(param_1,0x50,0x263,0x44,"ssl/statem/extensions_srvr.c",uVar3);
  return 0;
}

