
undefined4 aria_192_cbc_cipher(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iStack_34;
  int iStack_30;
  
  uVar5 = param_4;
  iVar4 = param_2;
  iVar6 = param_3;
  iStack_34 = param_2;
  iStack_30 = param_3;
  if (0x3fffffff < param_4) {
    do {
      uVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
      uVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
      iVar3 = EVP_CIPHER_CTX_encrypting(param_1);
      if (iVar3 == 0) {
        CRYPTO_cbc128_decrypt(iVar6,iVar4,0x40000000,uVar1,uVar2,0x185efd);
      }
      else {
        CRYPTO_cbc128_encrypt(iVar6);
      }
      uVar5 = uVar5 + 0xc0000000;
      iVar4 = iVar4 + 0x40000000;
      iVar6 = iVar6 + 0x40000000;
    } while (0x3fffffff < uVar5);
    uVar5 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iStack_34 = (uVar5 & 0xc0000000) + 0x40000000;
    iStack_30 = param_3 + iStack_34;
    iStack_34 = param_2 + iStack_34;
  }
  if (param_4 != 0) {
    uVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
    uVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
    iVar4 = EVP_CIPHER_CTX_encrypting(param_1);
    if (iVar4 != 0) {
      CRYPTO_cbc128_encrypt(iStack_30,iStack_34,param_4,uVar1,uVar2,0x185efd);
      return 1;
    }
    CRYPTO_cbc128_decrypt(iStack_30);
    return 1;
  }
  return 1;
}

