
undefined4 des_cfb1_cipher(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint local_40;
  uint local_3c;
  uchar local_38 [8];
  byte local_30 [12];
  
  local_40 = param_4;
  if (0x7ffffff < param_4) {
    local_40 = 0x8000000;
  }
  local_3c = param_4;
  while (local_3c != 0 && local_40 <= local_3c) {
    if (local_40 * 8 != 0) {
      uVar2 = 0;
      do {
        uVar3 = uVar2 >> 3;
        if (((int)(uint)*(byte *)(param_3 + uVar3) >> (~uVar2 & 7) & 1U) == 0) {
          local_38[0] = '\0';
        }
        else {
          local_38[0] = 0x80;
        }
        DES_cfb_encrypt(local_38,local_30,1,1,*(DES_key_schedule **)(param_1 + 0x60),
                        (DES_cblock *)(param_1 + 0x20),*(int *)(param_1 + 8));
        uVar1 = uVar2 & 7;
        uVar2 = uVar2 + 1;
        *(byte *)(param_2 + uVar3) =
             *(byte *)(param_2 + uVar3) & ~(byte)(0x80 >> uVar1) |
             (byte)((int)(local_30[0] & 0xffffff80) >> uVar1);
      } while (uVar2 != local_40 * 8);
    }
    param_3 = param_3 + local_40;
    param_2 = param_2 + local_40;
    local_3c = local_3c - local_40;
    if (local_3c <= local_40) {
      local_40 = local_3c;
    }
  }
  return 1;
}

