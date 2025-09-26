
/* WARNING: Type propagation algorithm not settling */

undefined4
des_ede_ecb_cipher(EVP_CIPHER_CTX *param_1,DES_cblock *param_2,const_DES_cblock *param_3,
                  uint param_4)

{
  EVP_CIPHER *pEVar1;
  DES_key_schedule *ks1;
  int iVar2;
  int iVar3;
  int enc;
  const_DES_cblock *input;
  uint uVar4;
  
  pEVar1 = EVP_CIPHER_CTX_cipher(param_1);
  uVar4 = pEVar1->block_size;
  if (uVar4 <= param_4) {
    input = param_3;
    do {
      ks1 = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data(param_1);
      iVar2 = EVP_CIPHER_CTX_get_cipher_data(param_1);
      iVar3 = EVP_CIPHER_CTX_get_cipher_data(param_1);
      enc = EVP_CIPHER_CTX_encrypting(param_1);
      DES_ecb3_encrypt(input,param_2,ks1,(DES_key_schedule *)(iVar2 + 0x80),
                       (DES_key_schedule *)(iVar3 + 0x100),enc);
      input = (const_DES_cblock *)((int)*input + uVar4);
      param_2 = (DES_cblock *)((int)*param_2 + uVar4);
    } while ((uint)((int)input - (int)param_3) <= param_4 - uVar4);
  }
  return 1;
}

