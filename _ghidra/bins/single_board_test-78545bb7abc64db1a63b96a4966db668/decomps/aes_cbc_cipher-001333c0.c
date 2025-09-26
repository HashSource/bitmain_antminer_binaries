
undefined4
aes_cbc_cipher(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  pcVar5 = *(code **)(iVar1 + 0xfc);
  if (pcVar5 == (code *)0x0) {
    iVar4 = EVP_CIPHER_CTX_encrypting(param_1);
    if (iVar4 == 0) {
      uVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
      CRYPTO_cbc128_decrypt(param_3,param_2,param_4,iVar1,uVar2,*(undefined4 *)(iVar1 + 0xf8));
      return 1;
    }
    uVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
    CRYPTO_cbc128_encrypt(param_3,param_2,param_4,iVar1,uVar2,*(undefined4 *)(iVar1 + 0xf8));
  }
  else {
    uVar2 = EVP_CIPHER_CTX_iv_noconst();
    uVar3 = EVP_CIPHER_CTX_encrypting(param_1);
    (*pcVar5)(param_3,param_2,param_4,iVar1,uVar2,uVar3);
  }
  return 1;
}

