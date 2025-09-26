
undefined4 tls_construct_ctos_post_handshake_auth(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x5f8) == 0) {
    return 2;
  }
  iVar1 = WPACKET_put_bytes__(param_2,param_2,0x31,0,2);
  if (((iVar1 == 0) || (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 == 0)) ||
     (iVar1 = WPACKET_close(param_2), iVar1 == 0)) {
    ossl_statem_fatal(param_1,0x50,0x26b,0x44,"ssl/statem/extensions_clnt.c",0x4c3);
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    *(undefined4 *)(param_1 + 0x5f4) = 1;
  }
  return uVar2;
}

