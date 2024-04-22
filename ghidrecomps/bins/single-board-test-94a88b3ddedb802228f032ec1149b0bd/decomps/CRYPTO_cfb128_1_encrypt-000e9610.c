
void CRYPTO_cfb128_1_encrypt
               (int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined local_38 [8];
  byte local_30 [12];
  
  if (param_3 != 0) {
    uVar2 = 0;
    do {
      uVar3 = uVar2 >> 3;
      uVar4 = ~uVar2;
      if (((int)(uint)*(byte *)(param_1 + uVar3) >> (uVar4 & 7) & 1U) == 0) {
        local_38[0] = 0;
      }
      else {
        local_38[0] = 0x80;
      }
      cfbr_encrypt_block_part_0(local_38,local_30,1,param_4,param_5,param_7,param_8);
      uVar1 = uVar2 & 7;
      uVar2 = uVar2 + 1;
      *(byte *)(param_2 + uVar3) =
           *(byte *)(param_2 + uVar3) & ~(byte)(1 << (uVar4 & 7)) |
           (byte)((int)(local_30[0] & 0xffffff80) >> uVar1);
    } while (uVar2 != param_3);
  }
  return;
}

