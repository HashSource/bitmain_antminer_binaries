
undefined4 camellia_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2,undefined4 param_3,int param_4)

{
  CAMELLIA_KEY *key;
  int iVar1;
  EVP_CIPHER *cipher;
  ulong uVar2;
  uint uVar3;
  code *pcVar4;
  bool bVar5;
  
  key = (CAMELLIA_KEY *)EVP_CIPHER_CTX_get_cipher_data();
  iVar1 = EVP_CIPHER_CTX_key_length(param_1);
  iVar1 = Camellia_set_key(param_2,iVar1 << 3,key);
  if (iVar1 < 0) {
    ERR_put_error(6,0x9f,0x9d,"crypto/evp/e_camellia.c",0xdd);
    return 0;
  }
  cipher = EVP_CIPHER_CTX_cipher(param_1);
  uVar2 = EVP_CIPHER_flags(cipher);
  uVar3 = uVar2 & 0xf0007;
  bVar5 = uVar3 - 1 == 1;
  if (uVar3 - 1 < 2) {
    bVar5 = param_4 == 0;
  }
  if (!bVar5) {
    pcVar4 = (code *)0x0;
    key[1].u.rd_key[0] = 0x18abe5;
    if (uVar3 == 2) {
      pcVar4 = (code *)0x18ab6d;
    }
    key[1].u.rd_key[1] = (uint)pcVar4;
    return 1;
  }
  key[1].u.rd_key[0] = 0x18abf1;
  if (uVar3 == 2) {
    pcVar4 = (code *)0x18ab6d;
  }
  else {
    pcVar4 = (code *)0x0;
  }
  key[1].u.rd_key[1] = (uint)pcVar4;
  return 1;
}

