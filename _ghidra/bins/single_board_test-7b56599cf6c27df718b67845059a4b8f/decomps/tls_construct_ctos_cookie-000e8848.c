
undefined4 tls_construct_ctos_cookie(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x5b8) == 0) {
    return 2;
  }
  iVar1 = WPACKET_put_bytes__(param_2,param_2,0x2c,0,2);
  if ((((iVar1 == 0) || (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 == 0)) ||
      (iVar1 = WPACKET_sub_memcpy__
                         (param_2,*(undefined4 *)(param_1 + 0x5b4),*(undefined4 *)(param_1 + 0x5b8),
                          2), iVar1 == 0)) || (iVar1 = WPACKET_close(param_2), iVar1 == 0)) {
    uVar2 = 0;
    ossl_statem_fatal(param_1,0x50,0x217,0x44,"ssl/statem/extensions_clnt.c",0x2de);
  }
  else {
    uVar2 = 1;
  }
  CRYPTO_free(*(void **)(param_1 + 0x5b4));
  *(undefined4 *)(param_1 + 0x5b4) = 0;
  *(undefined4 *)(param_1 + 0x5b8) = 0;
  return uVar2;
}

