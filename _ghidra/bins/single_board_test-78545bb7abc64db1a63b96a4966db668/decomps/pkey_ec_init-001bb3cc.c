
bool pkey_ec_init(int param_1)

{
  int iVar1;
  
  iVar1 = CRYPTO_zalloc(0x20,"crypto/ec/ec_pmeth.c",0x2d);
  if (iVar1 == 0) {
    ERR_put_error(0x10,0x11a,0x41,"crypto/ec/ec_pmeth.c",0x2e);
  }
  else {
    *(undefined1 *)(iVar1 + 0xd) = 1;
    *(undefined1 *)(iVar1 + 0xc) = 0xff;
    *(int *)(param_1 + 0x14) = iVar1;
  }
  return iVar1 != 0;
}

