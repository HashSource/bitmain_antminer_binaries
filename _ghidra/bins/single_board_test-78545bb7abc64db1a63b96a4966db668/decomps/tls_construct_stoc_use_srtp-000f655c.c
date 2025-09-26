
undefined4 tls_construct_stoc_use_srtp(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x5e8) == 0) {
    return 2;
  }
  iVar1 = WPACKET_put_bytes__(param_2,param_2,0xe,0,2);
  if (iVar1 != 0) {
    uVar2 = WPACKET_start_sub_packet_len__(param_2,2);
    if ((int)uVar2 != 0) {
      uVar2 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar2 >> 0x20),2,0,2);
      if ((int)uVar2 != 0) {
        uVar2 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar2 >> 0x20),
                                    *(undefined4 *)(*(int *)(param_1 + 0x5e8) + 4),0,2);
        if ((((int)uVar2 != 0) &&
            (iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar2 >> 0x20),0,0,1), iVar1 != 0)
            ) && (iVar1 = WPACKET_close(param_2), iVar1 != 0)) {
          return 1;
        }
      }
    }
  }
  ossl_statem_fatal(param_1,0x50,0x1ce,0x44,"ssl/statem/extensions_srvr.c",0x644);
  return 0;
}

