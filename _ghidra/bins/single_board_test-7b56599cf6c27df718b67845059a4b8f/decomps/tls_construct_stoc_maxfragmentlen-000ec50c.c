
undefined4 tls_construct_stoc_maxfragmentlen(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (3 < *(byte *)(*(int *)(param_1 + 0x474) + 0x1ec) - 1) {
    return 2;
  }
  iVar1 = WPACKET_put_bytes__(param_2,param_2,1,0,2);
  if (iVar1 != 0) {
    uVar2 = WPACKET_start_sub_packet_len__(param_2,2);
    if ((((int)uVar2 != 0) &&
        (iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar2 >> 0x20),
                                     *(undefined1 *)(*(int *)(param_1 + 0x474) + 0x1ec),0,1),
        iVar1 != 0)) && (iVar1 = WPACKET_close(param_2), iVar1 != 0)) {
      return 1;
    }
  }
  ossl_statem_fatal(param_1,0x50,0x224,0x44,"ssl/statem/extensions_srvr.c",0x55e);
  return 0;
}

