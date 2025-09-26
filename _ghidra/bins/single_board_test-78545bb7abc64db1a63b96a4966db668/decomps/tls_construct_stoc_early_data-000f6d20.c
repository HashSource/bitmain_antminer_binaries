
undefined4 tls_construct_stoc_early_data(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  if (param_3 == 0x2000) {
    if (*(int *)(param_1 + 0xf50) != 0) {
      iVar1 = WPACKET_put_bytes__(param_2,param_2,0x2a,0,2);
      if (iVar1 != 0) {
        uVar3 = WPACKET_start_sub_packet_len__(param_2,2);
        if ((((int)uVar3 != 0) &&
            (iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar3 >> 0x20),
                                         *(undefined4 *)(param_1 + 0xf50),0,4), iVar1 != 0)) &&
           (iVar1 = WPACKET_close(param_2), iVar1 != 0)) {
          return 1;
        }
      }
      uVar2 = 0x797;
      goto LAB_000f6d66;
    }
  }
  else if (*(int *)(param_1 + 0x5ac) == 2) {
    iVar1 = WPACKET_put_bytes__(param_2,param_2,0x2a,0,2);
    if (((iVar1 != 0) && (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 != 0)) &&
       (iVar1 = WPACKET_close(param_2), iVar1 != 0)) {
      return 1;
    }
    uVar2 = 0x7a5;
LAB_000f6d66:
    ossl_statem_fatal(param_1,0x50,0x213,0x44,"ssl/statem/extensions_srvr.c",uVar2);
    return 0;
  }
  return 2;
}

