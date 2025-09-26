
undefined4 tls_construct_ctos_ec_pt_formats(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r1;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = use_ecc();
  if (iVar1 == 0) {
    uVar2 = 2;
  }
  else {
    tls1_get_formatlist(param_1,&local_18,&local_14);
    iVar1 = WPACKET_put_bytes__(param_2,extraout_r1,0xb,0,2);
    if ((((iVar1 == 0) || (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 == 0)) ||
        (iVar1 = WPACKET_sub_memcpy__(param_2,local_18,local_14,1), iVar1 == 0)) ||
       (iVar1 = WPACKET_close(param_2), iVar1 == 0)) {
      ossl_statem_fatal(param_1,0x50,0x1d3,0x44,"ssl/statem/extensions_clnt.c",0xb2);
      return 0;
    }
    uVar2 = 1;
  }
  return uVar2;
}

