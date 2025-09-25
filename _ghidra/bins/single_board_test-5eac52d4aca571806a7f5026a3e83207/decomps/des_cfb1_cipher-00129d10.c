
undefined4 des_cfb1_cipher(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  DES_key_schedule *schedule;
  DES_cblock *ivec;
  int enc;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint local_38;
  uint local_34;
  uchar local_30 [4];
  byte local_2c [8];
  
  local_38 = param_4;
  if (0x7ffffff < param_4) {
    local_38 = 0x8000000;
  }
  if (param_4 != 0) {
    local_34 = param_4;
    do {
      if (local_38 * 8 != 0) {
        uVar2 = 0;
        do {
          uVar3 = uVar2 >> 3;
          if (((int)(uint)*(byte *)(param_3 + uVar3) >> (~uVar2 & 7) & 1U) == 0) {
            local_30[0] = '\0';
          }
          else {
            local_30[0] = 0x80;
          }
          schedule = (DES_key_schedule *)EVP_CIPHER_CTX_get_cipher_data(param_1);
          ivec = (DES_cblock *)EVP_CIPHER_CTX_iv_noconst(param_1);
          enc = EVP_CIPHER_CTX_encrypting(param_1);
          DES_cfb_encrypt(local_30,local_2c,1,1,schedule,ivec,enc);
          uVar1 = uVar2 & 7;
          uVar2 = uVar2 + 1;
          *(byte *)(param_2 + uVar3) =
               (byte)((int)(local_2c[0] & 0x80) >> uVar1) |
               *(byte *)(param_2 + uVar3) & ~(byte)(0x80 >> uVar1);
        } while (uVar2 != local_38 * 8);
      }
      param_3 = param_3 + local_38;
      param_2 = param_2 + local_38;
      local_34 = local_34 - local_38;
      if (local_34 <= local_38) {
        local_38 = local_34;
      }
      uVar2 = local_34;
      if (local_34 != 0) {
        uVar2 = 1;
      }
      if (local_34 < local_38) {
        uVar2 = 0;
      }
    } while (uVar2 != 0);
  }
  return 1;
}

