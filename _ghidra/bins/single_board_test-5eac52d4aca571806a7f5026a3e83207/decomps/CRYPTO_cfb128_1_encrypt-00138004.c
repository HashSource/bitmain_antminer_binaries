
void CRYPTO_cfb128_1_encrypt
               (int param_1,int param_2,uint param_3,undefined4 param_4,byte *param_5,
               undefined4 param_6,int param_7,code *param_8)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  char local_4c;
  byte bStack_4b;
  byte bStack_4a;
  byte bStack_49;
  char local_48;
  byte local_47;
  byte local_46;
  byte local_45;
  char local_44;
  byte local_43;
  byte local_42;
  byte local_41;
  char local_40;
  byte local_3f;
  byte local_3e;
  byte local_3d;
  
  if (param_3 != 0) {
    uVar9 = 0;
    do {
      uVar10 = uVar9 >> 3;
      uVar6 = ~uVar9;
      uVar1 = *(undefined4 *)param_5;
      uVar2 = *(uint *)(param_5 + 4);
      uVar4 = *(uint *)(param_5 + 8);
      bVar11 = ((int)(uint)*(byte *)(param_1 + uVar10) >> (uVar6 & 7) & 1U) == 0;
      bVar8 = !bVar11;
      uVar5 = *(uint *)(param_5 + 0xc);
      uVar7 = 0x80;
      if (bVar11) {
        uVar7 = 0;
      }
      bStack_49 = (byte)((uint)uVar1 >> 0x18);
      bStack_4a = (byte)((uint)uVar1 >> 0x10);
      bStack_4b = (byte)((uint)uVar1 >> 8);
      local_4c = (char)uVar1;
      local_45 = (byte)(uVar2 >> 0x18);
      local_46 = (byte)(uVar2 >> 0x10);
      local_47 = (byte)(uVar2 >> 8);
      local_48 = (char)uVar2;
      local_41 = (byte)(uVar4 >> 0x18);
      local_42 = (byte)(uVar4 >> 0x10);
      local_43 = (byte)(uVar4 >> 8);
      local_44 = (char)uVar4;
      local_3d = (byte)(uVar5 >> 0x18);
      local_3e = (byte)(uVar5 >> 0x10);
      local_3f = (byte)(uVar5 >> 8);
      local_40 = (char)uVar5;
      (*param_8)(param_5,param_5,param_4);
      if (param_7 == 0) {
        uVar7 = uVar7 ^ *param_5;
      }
      else {
        uVar7 = uVar7 ^ *param_5;
        bVar8 = SUB41(uVar7 >> 7,0);
      }
      uVar3 = uVar9 & 7;
      uVar9 = uVar9 + 1;
      *param_5 = (byte)((int)(uint)bStack_4b >> 7) | local_4c << 1;
      param_5[1] = (byte)((int)(uint)bStack_4a >> 7) | bStack_4b << 1;
      param_5[2] = (byte)((int)(uint)bStack_49 >> 7) | bStack_4a << 1;
      param_5[3] = (byte)((int)(uVar2 & 0xff) >> 7) | bStack_49 << 1;
      param_5[4] = (byte)((int)(uint)local_47 >> 7) | local_48 << 1;
      param_5[5] = (byte)((int)(uint)local_46 >> 7) | local_47 << 1;
      param_5[0xe] = (byte)((int)(uint)local_3d >> 7) | local_3e << 1;
      param_5[0xc] = (byte)((int)(uint)local_3f >> 7) | local_40 << 1;
      param_5[6] = (byte)((int)(uint)local_45 >> 7) | local_46 << 1;
      param_5[0xb] = (byte)((int)(uVar5 & 0xff) >> 7) | local_41 << 1;
      param_5[7] = (byte)((int)(uVar4 & 0xff) >> 7) | local_45 << 1;
      param_5[0xd] = (byte)((int)(uint)local_3e >> 7) | local_3f << 1;
      param_5[10] = (byte)((int)(uint)local_41 >> 7) | local_42 << 1;
      param_5[0xf] = bVar8 | local_3d << 1;
      param_5[9] = (byte)((int)(uint)local_42 >> 7) | local_43 << 1;
      param_5[8] = (byte)((int)(uint)local_43 >> 7) | local_44 << 1;
      *(byte *)(param_2 + uVar10) =
           *(byte *)(param_2 + uVar10) & ~(byte)(1 << (uVar6 & 7)) |
           (byte)((int)(uVar7 & 0x80) >> uVar3);
    } while (param_3 != uVar9);
  }
  return;
}

