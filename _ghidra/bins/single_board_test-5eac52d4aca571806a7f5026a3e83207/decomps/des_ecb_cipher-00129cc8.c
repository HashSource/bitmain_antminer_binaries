
/* WARNING: Type propagation algorithm not settling */

undefined4
des_ecb_cipher(EVP_CIPHER_CTX *param_1,DES_cblock *param_2,const_DES_cblock *param_3,uint param_4)

{
  EVP_CIPHER *pEVar1;
  DES_key_schedule *ks;
  int enc;
  const_DES_cblock *input;
  const_DES_cblock *pauVar2;
  uint uVar3;
  
  pEVar1 = EVP_CIPHER_CTX_cipher(param_1);
  uVar3 = pEVar1->block_size;
  if (uVar3 <= param_4) {
    input = param_3;
    do {
      ks = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data(param_1);
      enc = EVP_CIPHER_CTX_encrypting(param_1);
      pauVar2 = (const_DES_cblock *)((int)*input + uVar3);
      DES_ecb_encrypt(input,param_2,ks,enc);
      input = pauVar2;
      param_2 = (DES_cblock *)((int)*param_2 + uVar3);
    } while ((uint)((int)pauVar2 - (int)param_3) <= param_4 - uVar3);
  }
  return 1;
}

