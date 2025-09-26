
int evp_decodeblock_int(int param_1,int param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  uint uVar10;
  
  if (param_1 == 0) {
    puVar9 = data_ascii2bin;
  }
  else if (*(int *)(param_1 + 0x5c) << 0x1e < 0) {
    puVar9 = srpdata_ascii2bin;
  }
  else {
    puVar9 = data_ascii2bin;
  }
  if ((int)param_4 < 1) {
    if ((param_4 & 3) == 0) {
      return 0;
    }
  }
  else {
    if ((-1 < (int)((uint)*param_3 << 0x18)) && (puVar9[*param_3] == -0x20)) {
      pbVar6 = param_3 + 1;
      do {
        param_3 = pbVar6;
        param_4 = param_4 - 1;
        if (param_4 == 0) {
          return 0;
        }
      } while ((-1 < (int)((uint)*param_3 << 0x18)) &&
              (pbVar6 = param_3 + 1, puVar9[*param_3] == -0x20));
    }
    if (3 < (int)param_4) {
      uVar2 = param_4 - 1;
      bVar1 = param_3[uVar2];
      pbVar6 = param_3 + uVar2;
      while ((uVar10 = uVar2, -1 < (int)((uint)bVar1 << 0x18) && ((puVar9[bVar1] | 0x13) == 0xf3)))
      {
        if (uVar10 == 3) {
          return -1;
        }
        pbVar6 = pbVar6 + -1;
        bVar1 = *pbVar6;
        uVar2 = uVar10 - 1;
        param_4 = uVar10;
      }
    }
    if ((param_4 & 3) == 0) {
      iVar8 = param_2 + 3;
      while( true ) {
        if ((int)((uint)*param_3 << 0x18) < 0) {
          uVar2 = 0xff;
        }
        else {
          uVar2 = (uint)(byte)puVar9[*param_3];
        }
        iVar3 = iVar8 - param_2;
        if ((int)((uint)param_3[1] << 0x18) < 0) {
          uVar10 = 0xff;
        }
        else {
          uVar10 = (uint)(byte)puVar9[param_3[1]];
        }
        if ((int)((uint)param_3[2] << 0x18) < 0) break;
        if ((int)((uint)param_3[3] << 0x18) < 0) {
          return -1;
        }
        uVar4 = (uint)(byte)puVar9[param_3[3]] | uVar2 << 0x12 | uVar10 << 0xc;
        uVar5 = uVar4 | (uint)(byte)puVar9[param_3[2]] << 6;
        if ((((uint)(byte)puVar9[param_3[2]] | uVar10 | (byte)puVar9[param_3[3]] | uVar2) & 0x80) !=
            0) {
          return -1;
        }
        *(char *)(iVar8 + -1) = (char)uVar5;
        *(char *)(iVar8 + -3) = (char)(uVar4 >> 0x10);
        iVar7 = iVar8 + 3;
        *(char *)(iVar8 + -2) = (char)(uVar5 >> 8);
        iVar8 = iVar7;
        param_3 = param_3 + 4;
        if ((param_4 - 1 >> 2) * 3 + 6 + param_2 == iVar7) {
          return iVar3;
        }
      }
    }
  }
  return -1;
}

