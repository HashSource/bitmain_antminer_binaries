
undefined4 cast5_cbc_cipher(undefined4 param_1,uchar *param_2,uchar *param_3,uint param_4)

{
  CAST_KEY *pCVar1;
  uchar *iv;
  int iVar2;
  uchar *puVar3;
  uchar *in;
  uint uVar4;
  uchar *local_2c;
  
  puVar3 = param_2;
  in = param_3;
  uVar4 = param_4;
  local_2c = param_3;
  if (0x3fffffff < param_4) {
    do {
      uVar4 = uVar4 + 0xc0000000;
      pCVar1 = (CAST_KEY *)EVP_CIPHER_CTX_get_cipher_data(param_1);
      iv = (uchar *)EVP_CIPHER_CTX_iv_noconst(param_1);
      iVar2 = EVP_CIPHER_CTX_encrypting(param_1);
      CAST_cbc_encrypt(in,puVar3,0x40000000,pCVar1,iv,iVar2);
      puVar3 = puVar3 + 0x40000000;
      in = in + 0x40000000;
    } while (0x3fffffff < uVar4);
    uVar4 = param_4 + 0xc0000000;
    param_4 = param_4 & 0x3fffffff;
    iVar2 = (uVar4 & 0xc0000000) + 0x40000000;
    param_2 = param_2 + iVar2;
    local_2c = param_3 + iVar2;
  }
  if (param_4 != 0) {
    pCVar1 = (CAST_KEY *)EVP_CIPHER_CTX_get_cipher_data(param_1);
    puVar3 = (uchar *)EVP_CIPHER_CTX_iv_noconst(param_1);
    iVar2 = EVP_CIPHER_CTX_encrypting(param_1);
    CAST_cbc_encrypt(local_2c,param_2,param_4,pCVar1,puVar3,iVar2);
  }
  return 1;
}

