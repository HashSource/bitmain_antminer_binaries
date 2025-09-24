
undefined4 tls_client_key_exchange_post_work(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x7c);
  iVar3 = *(int *)(iVar1 + 0x250);
  uVar2 = *(undefined4 *)(iVar1 + 0x254);
  iVar1 = *(int *)(*(int *)(iVar1 + 0x210) + 0x10);
  if (iVar1 << 0x1a < 0) {
    iVar1 = srp_generate_client_master_secret();
    if (iVar1 != 0) {
      return 1;
    }
  }
  else if ((iVar3 == 0) && (-1 < iVar1 << 0x1c)) {
    ossl_statem_fatal(param_1,0x50,0x162,0x41,"ssl/statem/statem_clnt.c",0xd40);
  }
  else {
    iVar3 = ssl_generate_master_secret(param_1,iVar3,uVar2,1);
    if (iVar3 != 0) {
      return 1;
    }
    uVar2 = 0;
    iVar3 = 0;
  }
  CRYPTO_clear_free(iVar3,uVar2,"ssl/statem/statem_clnt.c",0xd6f);
  iVar3 = *(int *)(param_1 + 0x7c);
  *(undefined4 *)(iVar3 + 0x250) = 0;
  *(undefined4 *)(iVar3 + 0x254) = 0;
  return 0;
}

