
undefined4 tls1_set_server_sigalgs(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x98);
  if (*(void **)(iVar2 + 0x13c) != (void *)0x0) {
    CRYPTO_free(*(void **)(iVar2 + 0x13c));
    iVar2 = *(int *)(param_1 + 0x98);
    *(undefined4 *)(iVar2 + 0x13c) = 0;
    *(undefined4 *)(iVar2 + 0x140) = 0;
  }
  *(undefined4 *)(iVar2 + 0x44) = 0;
  *(undefined4 *)(iVar2 + 0x54) = 0;
  *(undefined4 *)(iVar2 + 0x60) = 0;
  *(undefined4 *)(iVar2 + 0x70) = 0;
  *(undefined4 *)(iVar2 + 0x7c) = 0;
  *(undefined4 *)(iVar2 + 0x8c) = 0;
  *(undefined4 *)(iVar2 + 0x98) = 0;
  *(undefined4 *)(iVar2 + 0xa8) = 0;
  *(undefined4 *)(iVar2 + 0xb4) = 0;
  *(undefined4 *)(iVar2 + 0xc4) = 0;
  *(undefined4 *)(iVar2 + 0xd0) = 0;
  *(undefined4 *)(iVar2 + 0xe0) = 0;
  *(undefined4 *)(iVar2 + 0xec) = 0;
  *(undefined4 *)(iVar2 + 0xfc) = 0;
  *(undefined4 *)(iVar2 + 0x108) = 0;
  *(undefined4 *)(iVar2 + 0x118) = 0;
  if (*(int *)(iVar2 + 0x124) == 0) {
    ssl_cert_set_default_md(iVar2);
    uVar1 = 1;
  }
  else {
    iVar2 = tls1_process_sigalgs(param_1);
    if (iVar2 == 0) {
      ERR_put_error(0x14,0x14f,0x41,DAT_000731d8,0xbbb);
      uVar1 = 0x50;
    }
    else {
      if (*(int *)(*(int *)(param_1 + 0x98) + 0x13c) != 0) {
        return 1;
      }
      ERR_put_error(0x14,0x14f,0x178,DAT_000731d8,0xbc2);
      uVar1 = 0x2f;
    }
    ssl3_send_alert(param_1,2,uVar1);
    uVar1 = 0;
  }
  return uVar1;
}

