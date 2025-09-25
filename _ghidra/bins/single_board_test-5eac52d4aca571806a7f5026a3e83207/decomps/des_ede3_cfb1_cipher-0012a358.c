
undefined4 des_ede3_cfb1_cipher(EVP_CIPHER_CTX *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  DES_key_schedule *ks1;
  int iVar2;
  DES_cblock *ivec;
  int enc;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_40;
  uchar local_30 [4];
  byte local_2c [8];
  
  iVar1 = EVP_CIPHER_CTX_test_flags(param_1,0x2000);
  local_40 = param_4;
  if (iVar1 == 0) {
    local_40 = param_4 << 3;
  }
  if (local_40 != 0) {
    uVar4 = 0;
    do {
      uVar5 = uVar4 >> 3;
      if (((int)(uint)*(byte *)(param_3 + uVar5) >> (~uVar4 & 7) & 1U) == 0) {
        local_30[0] = '\0';
      }
      else {
        local_30[0] = 0x80;
      }
      ks1 = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data(param_1);
      iVar1 = EVP_CIPHER_CTX_get_cipher_data(param_1);
      iVar2 = EVP_CIPHER_CTX_get_cipher_data(param_1);
      ivec = (DES_cblock *)EVP_CIPHER_CTX_iv_noconst(param_1);
      enc = EVP_CIPHER_CTX_encrypting(param_1);
      DES_ede3_cfb_encrypt
                (local_30,local_2c,1,1,ks1,(DES_key_schedule *)(iVar1 + 0x80),
                 (DES_key_schedule *)(iVar2 + 0x100),ivec,enc);
      uVar3 = uVar4 & 7;
      uVar4 = uVar4 + 1;
      *(byte *)(param_2 + uVar5) =
           (byte)((int)(local_2c[0] & 0x80) >> uVar3) |
           *(byte *)(param_2 + uVar5) & ~(byte)(0x80 >> uVar3);
    } while (local_40 != uVar4);
  }
  return 1;
}

