
void mdc2_body(int param_1,uint *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  DES_key_schedule DStack_a8;
  
  if (param_3 != 0) {
    bVar2 = *(byte *)(param_1 + 0x14);
    bVar1 = *(byte *)(param_1 + 0xc);
    puVar5 = param_2;
    do {
      uVar4 = *puVar5;
      uVar3 = puVar5[1];
      *(byte *)(param_1 + 0xc) = bVar1 & 0x9f | 0x40;
      *(byte *)(param_1 + 0x14) = bVar2 & 0x9f | 0x20;
      puVar5 = puVar5 + 2;
      local_b8 = uVar4;
      local_b4 = uVar3;
      local_b0 = uVar4;
      local_ac = uVar3;
      DES_set_odd_parity((DES_cblock *)(param_1 + 0xc));
      DES_set_key_unchecked((DES_cblock *)(param_1 + 0xc),&DStack_a8);
      DES_encrypt1(&local_b8,&DStack_a8,1);
      DES_set_odd_parity((DES_cblock *)(param_1 + 0x14));
      DES_set_key_unchecked((DES_cblock *)(param_1 + 0x14),&DStack_a8);
      DES_encrypt1(&local_b0,&DStack_a8,1);
      local_b0 = local_b0 ^ uVar4;
      uVar4 = uVar4 ^ local_b8;
      bVar1 = (byte)uVar4;
      local_ac = local_ac ^ uVar3;
      uVar3 = uVar3 ^ local_b4;
      *(char *)(param_1 + 0x10) = (char)local_ac;
      *(char *)(param_1 + 0xe) = (char)(uVar4 >> 0x10);
      *(char *)(param_1 + 0xf) = (char)(uVar4 >> 0x18);
      *(char *)(param_1 + 0x16) = (char)(local_b0 >> 0x10);
      *(char *)(param_1 + 0x15) = (char)(local_b0 >> 8);
      *(char *)(param_1 + 0xd) = (char)(uVar4 >> 8);
      bVar2 = (byte)local_b0;
      *(char *)(param_1 + 0x13) = (char)(local_ac >> 0x18);
      *(char *)(param_1 + 0x17) = (char)(local_b0 >> 0x18);
      *(char *)(param_1 + 0x18) = (char)uVar3;
      *(char *)(param_1 + 0x11) = (char)(local_ac >> 8);
      *(byte *)(param_1 + 0xc) = bVar1;
      *(byte *)(param_1 + 0x14) = bVar2;
      *(char *)(param_1 + 0x12) = (char)(local_ac >> 0x10);
      *(char *)(param_1 + 0x19) = (char)(uVar3 >> 8);
      *(char *)(param_1 + 0x1a) = (char)(uVar3 >> 0x10);
      *(char *)(param_1 + 0x1b) = (char)(uVar3 >> 0x18);
    } while ((uint)((int)puVar5 - (int)param_2) < param_3);
    return;
  }
  return;
}

