
void mdc2_body(int param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  DES_key_schedule DStack_a8;
  
  if (param_3 != 0) {
    bVar3 = *(byte *)(param_1 + 0xc);
    bVar4 = *(byte *)(param_1 + 0x14);
    pbVar7 = param_2;
    do {
      bVar5 = pbVar7[6];
      bVar1 = pbVar7[5];
      bVar6 = pbVar7[4];
      bVar2 = pbVar7[7];
      uVar9 = (uint)pbVar7[2] << 0x10 | (uint)pbVar7[1] << 8 | (uint)*pbVar7 |
              (uint)pbVar7[3] << 0x18;
      *(byte *)(param_1 + 0xc) = bVar3 & 0x9f | 0x40;
      *(byte *)(param_1 + 0x14) = bVar4 & 0x9f | 0x20;
      uVar8 = (uint)bVar5 << 0x10 | (uint)bVar1 << 8 | (uint)bVar6 | (uint)bVar2 << 0x18;
      pbVar7 = pbVar7 + 8;
      local_b8 = uVar9;
      local_b4 = uVar8;
      local_b0 = uVar9;
      local_ac = uVar8;
      DES_set_odd_parity((DES_cblock *)(param_1 + 0xc));
      DES_set_key_unchecked((DES_cblock *)(param_1 + 0xc),&DStack_a8);
      DES_encrypt1(&local_b8,&DStack_a8,1);
      DES_set_odd_parity((DES_cblock *)(param_1 + 0x14));
      DES_set_key_unchecked((DES_cblock *)(param_1 + 0x14),&DStack_a8);
      DES_encrypt1(&local_b0,&DStack_a8,1);
      local_b8 = uVar9 ^ local_b8;
      local_ac = uVar8 ^ local_ac;
      bVar3 = (byte)local_b8;
      uVar8 = uVar8 ^ local_b4;
      uVar9 = uVar9 ^ local_b0;
      *(char *)(param_1 + 0xe) = (char)(local_b8 >> 0x10);
      *(char *)(param_1 + 0x18) = (char)uVar8;
      *(char *)(param_1 + 0xf) = (char)(local_b8 >> 0x18);
      *(char *)(param_1 + 0x15) = (char)(uVar9 >> 8);
      *(char *)(param_1 + 0x16) = (char)(uVar9 >> 0x10);
      *(char *)(param_1 + 0x11) = (char)(local_ac >> 8);
      *(char *)(param_1 + 0xd) = (char)(local_b8 >> 8);
      bVar4 = (byte)uVar9;
      *(char *)(param_1 + 0x1b) = (char)(uVar8 >> 0x18);
      *(char *)(param_1 + 0x17) = (char)(uVar9 >> 0x18);
      *(char *)(param_1 + 0x10) = (char)local_ac;
      *(byte *)(param_1 + 0xc) = bVar3;
      *(byte *)(param_1 + 0x14) = bVar4;
      *(char *)(param_1 + 0x12) = (char)(local_ac >> 0x10);
      *(char *)(param_1 + 0x13) = (char)(local_ac >> 0x18);
      *(char *)(param_1 + 0x19) = (char)(uVar8 >> 8);
      *(char *)(param_1 + 0x1a) = (char)(uVar8 >> 0x10);
    } while ((uint)((int)pbVar7 - (int)param_2) < param_3);
  }
  return;
}

