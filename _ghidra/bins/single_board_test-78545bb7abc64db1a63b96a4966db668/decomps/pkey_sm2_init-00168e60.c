
bool pkey_sm2_init(int param_1)

{
  int iVar1;
  
  iVar1 = CRYPTO_zalloc(0x14,"crypto/sm2/sm2_pmeth.c",0x24);
  if (iVar1 == 0) {
    ERR_put_error(0x35,0x6f,0x41,"crypto/sm2/sm2_pmeth.c",0x25);
  }
  else {
    *(int *)(param_1 + 0x14) = iVar1;
  }
  return iVar1 != 0;
}

