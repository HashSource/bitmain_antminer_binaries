
undefined4 cast5_ecb_cipher(EVP_CIPHER_CTX *param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  EVP_CIPHER *pEVar1;
  CAST_KEY *key;
  int enc;
  uchar *in;
  uchar *puVar2;
  uint uVar3;
  
  pEVar1 = EVP_CIPHER_CTX_cipher(param_1);
  uVar3 = pEVar1->block_size;
  if (uVar3 <= param_4) {
    in = param_3;
    do {
      key = (CAST_KEY *)EVP_CIPHER_CTX_get_cipher_data(param_1);
      enc = EVP_CIPHER_CTX_encrypting(param_1);
      puVar2 = in + uVar3;
      CAST_ecb_encrypt(in,param_2,key,enc);
      in = puVar2;
      param_2 = param_2 + uVar3;
    } while ((uint)((int)puVar2 - (int)param_3) <= param_4 - uVar3);
  }
  return 1;
}

