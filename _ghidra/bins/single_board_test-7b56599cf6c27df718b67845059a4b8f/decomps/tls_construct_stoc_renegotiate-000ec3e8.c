
undefined4 tls_construct_stoc_renegotiate(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(*(int *)(param_1 + 0x7c) + 0x338) == 0) {
    return 2;
  }
  iVar1 = WPACKET_put_bytes__(param_2,param_2,0xff01,0,2);
  if ((((iVar1 == 0) || (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 == 0)) ||
      (iVar1 = WPACKET_start_sub_packet_len__(param_2,1), iVar1 == 0)) ||
     (((iVar1 = WPACKET_memcpy(param_2,*(int *)(param_1 + 0x7c) + 0x2b0,
                               *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x2f0)), iVar1 == 0 ||
       (iVar1 = WPACKET_memcpy(param_2,*(int *)(param_1 + 0x7c) + 0x2f4,
                               *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x334)), iVar1 == 0)) ||
      ((iVar1 = WPACKET_close(param_2), iVar1 == 0 || (iVar1 = WPACKET_close(param_2), iVar1 == 0)))
      ))) {
    ossl_statem_fatal(param_1,0x50,0x1ca,0x44,"ssl/statem/extensions_srvr.c",0x52e);
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

