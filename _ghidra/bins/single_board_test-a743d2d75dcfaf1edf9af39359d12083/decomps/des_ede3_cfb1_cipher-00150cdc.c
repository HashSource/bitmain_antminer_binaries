
undefined4 des_ede3_cfb1_cipher(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  DES_key_schedule *ks1;
  DES_key_schedule *pDVar4;
  bool bVar5;
  uchar local_38 [8];
  byte local_30 [12];
  
  if (param_4 != 0) {
    uVar2 = 0;
    do {
      uVar3 = uVar2 >> 3;
      ks1 = *(DES_key_schedule **)(param_1 + 0x60);
      bVar5 = ((int)(uint)*(byte *)(param_3 + uVar3) >> (~uVar2 & 7) & 1U) == 0;
      pDVar4 = ks1 + 2;
      if (bVar5) {
        pDVar4 = (DES_key_schedule *)0x0;
      }
      local_38[0] = (uchar)pDVar4;
      if (!bVar5) {
        local_38[0] = 0x80;
      }
      DES_ede3_cfb_encrypt
                (local_38,local_30,1,1,ks1,ks1 + 1,ks1 + 2,(DES_cblock *)(param_1 + 0x20),
                 *(int *)(param_1 + 8));
      uVar1 = uVar2 & 7;
      uVar2 = uVar2 + 1;
      *(byte *)(param_2 + uVar3) =
           *(byte *)(param_2 + uVar3) & ~(byte)(0x80 >> uVar1) |
           (byte)((int)(local_30[0] & 0xffffff80) >> uVar1);
    } while (uVar2 != param_4);
  }
  return 1;
}

