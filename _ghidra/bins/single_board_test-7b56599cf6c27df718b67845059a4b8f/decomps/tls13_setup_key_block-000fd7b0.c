
undefined4 tls13_setup_key_block(int param_1)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c [2];
  
  iVar1 = *(int *)(param_1 + 0x474);
  *(undefined4 *)(iVar1 + 0x1b8) = *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x210);
  iVar1 = ssl_cipher_get_evp(iVar1,&local_20,local_1c,0,0,0,0);
  if (iVar1 != 0) {
    iVar1 = *(int *)(param_1 + 0x7c);
    *(undefined4 *)(iVar1 + 0x230) = local_20;
    *(undefined4 *)(iVar1 + 0x234) = local_1c[0];
    return 1;
  }
  ossl_statem_fatal(param_1,0x50,0x1b9,0x8a,"ssl/tls13_enc.c",0x15f);
  return 0;
}

