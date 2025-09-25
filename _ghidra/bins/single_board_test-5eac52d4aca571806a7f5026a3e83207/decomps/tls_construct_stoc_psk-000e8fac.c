
undefined4 tls_construct_stoc_psk(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x8c) == 0) {
    return 2;
  }
  iVar1 = WPACKET_put_bytes__(param_2,param_2,0x29,0,2);
  if (iVar1 != 0) {
    uVar2 = WPACKET_start_sub_packet_len__(param_2,2);
    if ((((int)uVar2 != 0) &&
        (iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar2 >> 0x20),
                                     *(int *)(param_1 + 0x5c4),*(int *)(param_1 + 0x5c4) >> 0x1f,2),
        iVar1 != 0)) && (iVar1 = WPACKET_close(param_2), iVar1 != 0)) {
      return 1;
    }
  }
  ossl_statem_fatal(param_1,0x50,0x1f8,0x44,"ssl/statem/extensions_srvr.c",0x7b7);
  return 0;
}

