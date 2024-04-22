
int long_i2c(uint *param_1,undefined *param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined uVar4;
  undefined *puVar5;
  int iVar6;
  ulong uVar7;
  uint uVar8;
  undefined *puVar9;
  byte *pbVar10;
  
  uVar1 = *param_1;
  if (*(uint *)(param_4 + 0x14) == uVar1) {
    iVar3 = -1;
  }
  else {
    uVar8 = ~uVar1;
    if ((int)~uVar1 <= (int)uVar1) {
      uVar8 = uVar1;
    }
    uVar2 = BN_num_bits_word(uVar8);
    iVar3 = (int)(uVar2 + 7) >> 3;
    uVar2 = (uint)((uVar2 & 7) == 0);
    if (param_2 != (undefined *)0x0) {
      puVar9 = param_2;
      if (uVar2 != 0) {
        if ((int)uVar1 < 0) {
          uVar4 = 0xff;
        }
        else {
          uVar4 = 0;
        }
        puVar9 = param_2 + 1;
        *param_2 = uVar4;
      }
      iVar6 = iVar3 + -1;
      if (-1 < iVar6) {
        if ((int)uVar1 < 0) {
          pbVar10 = puVar9 + iVar3;
          do {
            iVar6 = iVar6 + -1;
            pbVar10 = pbVar10 + -1;
            *pbVar10 = ~(byte)uVar8;
            uVar8 = uVar8 >> 8;
          } while (iVar6 != -1);
        }
        else {
          if (0x20 < iVar3) {
            puVar5 = puVar9 + iVar3;
            uVar7 = uVar8;
            do {
              HintPreloadData(puVar9 + iVar6 + -0x22);
              iVar6 = iVar6 + -0x20;
              puVar5[-1] = (char)uVar7;
              puVar5[-5] = 0;
              puVar5[-6] = 0;
              uVar8 = 0;
              puVar5[-7] = 0;
              puVar5[-8] = 0;
              puVar5[-9] = 0;
              puVar5[-10] = 0;
              puVar5[-0xb] = 0;
              puVar5[-0xc] = 0;
              puVar5[-0xd] = 0;
              puVar5[-0xe] = 0;
              puVar5[-0xf] = 0;
              puVar5[-0x10] = 0;
              puVar5[-0x11] = 0;
              puVar5[-0x12] = 0;
              puVar5[-0x13] = 0;
              puVar5[-0x14] = 0;
              puVar5[-0x15] = 0;
              puVar5[-0x16] = 0;
              puVar5[-0x17] = 0;
              puVar5[-0x18] = 0;
              puVar5[-0x19] = 0;
              puVar5[-0x1a] = 0;
              puVar5[-0x1b] = 0;
              puVar5[-0x1c] = 0;
              puVar5[-0x1d] = 0;
              puVar5[-0x1e] = 0;
              puVar5[-0x1f] = 0;
              puVar5[-2] = (char)(uVar7 >> 8);
              puVar5[-3] = (char)(uVar7 >> 0x10);
              puVar5[-4] = (char)(uVar7 >> 0x18);
              puVar5 = puVar5 + -0x20;
              *puVar5 = 0;
              uVar7 = 0;
            } while (iVar6 != (iVar3 - (iVar3 - 0x21U & 0xffffffe0)) + -0x21);
          }
          do {
            puVar9[iVar6] = (char)uVar8;
            iVar6 = iVar6 + -1;
            uVar8 = uVar8 >> 8;
          } while (-1 < iVar6);
        }
      }
    }
    iVar3 = iVar3 + uVar2;
  }
  return iVar3;
}

