
bool pkey_scrypt_init(int param_1)

{
  int iVar1;
  
  iVar1 = CRYPTO_zalloc(0x30,"crypto/kdf/scrypt.c",0x3c);
  if (iVar1 == 0) {
    ERR_put_error(0x34,0x6a,0x41,"crypto/kdf/scrypt.c",0x3e);
  }
  else {
    *(undefined4 *)(iVar1 + 0x18) = 8;
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0x100000;
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x20) = 1;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    *(undefined4 *)(iVar1 + 0x28) = 0x40100000;
    *(undefined4 *)(iVar1 + 0x2c) = 0;
    *(int *)(param_1 + 0x14) = iVar1;
  }
  return iVar1 != 0;
}

