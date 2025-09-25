
undefined4 sm4_ecb_cipher(EVP_CIPHER_CTX *param_1,int param_2,int param_3,uint param_4)

{
  EVP_CIPHER *pEVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  pEVar1 = EVP_CIPHER_CTX_cipher(param_1);
  uVar5 = pEVar1->block_size;
  if (uVar5 <= param_4) {
    iVar4 = param_3;
    do {
      while( true ) {
        uVar2 = EVP_CIPHER_CTX_get_cipher_data(param_1);
        iVar3 = EVP_CIPHER_CTX_encrypting(param_1);
        if (iVar3 == 0) break;
        iVar3 = iVar4 + uVar5;
        SM4_encrypt(iVar4);
        param_2 = param_2 + uVar5;
        iVar4 = iVar3;
        if (param_4 - uVar5 < (uint)(iVar3 - param_3)) {
          return 1;
        }
      }
      iVar3 = iVar4 + uVar5;
      SM4_decrypt(iVar4,param_2,uVar2);
      param_2 = param_2 + uVar5;
      iVar4 = iVar3;
    } while ((uint)(iVar3 - param_3) <= param_4 - uVar5);
  }
  return 1;
}

