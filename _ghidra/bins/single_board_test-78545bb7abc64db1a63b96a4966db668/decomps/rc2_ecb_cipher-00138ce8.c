
undefined4 rc2_ecb_cipher(EVP_CIPHER_CTX *param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  EVP_CIPHER *pEVar1;
  int iVar2;
  int enc;
  uchar *in;
  uchar *puVar3;
  uint uVar4;
  
  pEVar1 = EVP_CIPHER_CTX_cipher(param_1);
  uVar4 = pEVar1->block_size;
  if (uVar4 <= param_4) {
    in = param_3;
    do {
      iVar2 = EVP_CIPHER_CTX_get_cipher_data(param_1);
      enc = EVP_CIPHER_CTX_encrypting(param_1);
      puVar3 = in + uVar4;
      RC2_ecb_encrypt(in,param_2,(RC2_KEY *)(iVar2 + 4),enc);
      in = puVar3;
      param_2 = param_2 + uVar4;
    } while ((uint)((int)puVar3 - (int)param_3) <= param_4 - uVar4);
  }
  return 1;
}

