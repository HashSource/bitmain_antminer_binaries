
undefined4 tls_construct_stoc_ec_pt_formats(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210);
  if (((*(int *)(iVar2 + 0x10) << 0x1d < 0) || (*(int *)(iVar2 + 0x14) << 0x1c < 0)) &&
     (*(int *)(param_1 + 0x56c) != 0)) {
    tls1_get_formatlist(param_1,&local_18,&local_14);
    iVar2 = WPACKET_put_bytes__(param_2,extraout_r1,0xb,0,2);
    if (((iVar2 == 0) || (iVar2 = WPACKET_start_sub_packet_len__(param_2,2), iVar2 == 0)) ||
       ((iVar2 = WPACKET_sub_memcpy__(param_2,local_18,local_14,1), iVar2 == 0 ||
        (iVar2 = WPACKET_close(param_2), iVar2 == 0)))) {
      ossl_statem_fatal(param_1,0x50,0x1c5,0x44,"ssl/statem/extensions_srvr.c",0x57a);
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    return uVar1;
  }
  return 2;
}

