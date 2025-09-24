
void CRYPTO_ctr128_encrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,char *param_5,
               uint *param_6,uint *param_7,code *param_8)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint *puVar5;
  uint uVar6;
  byte *pbVar7;
  uint *puVar8;
  byte *pbVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  uVar10 = *param_7;
  puVar5 = param_1;
  puVar8 = param_2;
  if (uVar10 != 0 && param_3 != 0) {
    do {
      pbVar7 = (byte *)((int)param_6 + uVar10);
      uVar6 = uVar10 + 1 & 0xf;
      param_1 = (uint *)((int)puVar5 + 1);
      if (uVar6 != 0) {
        uVar6 = 1;
      }
      param_3 = param_3 - 1;
      uVar6 = uVar6 & 1;
      if (param_3 == 0) {
        uVar6 = 0;
      }
      uVar10 = uVar10 + 1 & 0xf;
      param_2 = (uint *)((int)puVar8 + 1);
      *(byte *)puVar8 = (byte)*puVar5 ^ *pbVar7;
      puVar5 = param_1;
      puVar8 = param_2;
    } while (uVar6 != 0);
  }
  if ((((uint)param_2 | (uint)param_1 | (uint)param_6) & 3) == 0) {
    uVar6 = param_3;
    puVar5 = param_1;
    puVar8 = param_2;
    if (0xf < param_3) {
      do {
        uVar6 = uVar6 - 0x10;
        (*param_8)(param_5,param_6,param_4);
        bVar1 = param_5[0xf];
        param_5[0xf] = (char)(bVar1 + 1);
        uVar10 = (uint)(byte)param_5[0xe] + (bVar1 + 1 >> 8);
        uVar12 = (uint)(byte)param_5[0xd] + (uVar10 >> 8);
        param_5[0xe] = (char)uVar10;
        uVar10 = (uint)(byte)param_5[0xc] + (uVar12 >> 8);
        param_5[0xd] = (char)uVar12;
        uVar12 = (uint)(byte)param_5[0xb] + (uVar10 >> 8);
        param_5[0xc] = (char)uVar10;
        uVar10 = (uint)(byte)param_5[10] + (uVar12 >> 8);
        param_5[0xb] = (char)uVar12;
        uVar12 = (uint)(byte)param_5[9] + (uVar10 >> 8);
        param_5[10] = (char)uVar10;
        uVar13 = (uint)(byte)param_5[8] + (uVar12 >> 8);
        param_5[9] = (char)uVar12;
        uVar10 = (uint)(byte)param_5[7] + (uVar13 >> 8);
        param_5[8] = (char)uVar13;
        uVar12 = (uint)(byte)param_5[6] + (uVar10 >> 8);
        param_5[7] = (char)uVar10;
        uVar10 = (uint)(byte)param_5[5] + (uVar12 >> 8);
        param_5[6] = (char)uVar12;
        uVar12 = (uint)(byte)param_5[4] + (uVar10 >> 8);
        param_5[5] = (char)uVar10;
        uVar13 = (uint)(byte)param_5[3] + (uVar12 >> 8);
        param_5[4] = (char)uVar12;
        uVar10 = (uint)(byte)param_5[2] + (uVar13 >> 8);
        param_5[3] = (char)uVar13;
        iVar2 = (uint)(byte)param_5[1] + (uVar10 >> 8);
        param_5[2] = (char)uVar10;
        param_5[1] = (char)iVar2;
        *param_5 = *param_5 + (char)((uint)iVar2 >> 8);
        *puVar8 = *param_6 ^ *puVar5;
        puVar8[1] = param_6[1] ^ puVar5[1];
        puVar8[2] = param_6[2] ^ puVar5[2];
        puVar8[3] = param_6[3] ^ puVar5[3];
        puVar5 = puVar5 + 4;
        puVar8 = puVar8 + 4;
      } while (0xf < uVar6);
      uVar10 = 0;
      uVar6 = param_3 - 0x10;
      param_3 = param_3 & 0xf;
      iVar2 = (uVar6 & 0xfffffff0) + 0x10;
      param_2 = (uint *)((int)param_2 + iVar2);
      param_1 = (uint *)((int)param_1 + iVar2);
    }
    if (param_3 != 0) {
      (*param_8)(param_5,param_6,param_4);
      bVar1 = param_5[0xf];
      iVar3 = uVar10 + 4;
      param_5[0xf] = (char)(bVar1 + 1);
      uVar6 = (uint)(byte)param_5[0xe] + (bVar1 + 1 >> 8);
      uVar12 = (uint)(byte)param_5[0xd] + (uVar6 >> 8);
      param_5[0xe] = (char)uVar6;
      uVar6 = (uint)(byte)param_5[0xc] + (uVar12 >> 8);
      param_5[0xd] = (char)uVar12;
      uVar12 = (uint)(byte)param_5[0xb] + (uVar6 >> 8);
      param_5[0xc] = (char)uVar6;
      uVar6 = (uint)(byte)param_5[10] + (uVar12 >> 8);
      param_5[0xb] = (char)uVar12;
      uVar12 = (uint)(byte)param_5[9] + (uVar6 >> 8);
      param_5[10] = (char)uVar6;
      uVar6 = (uint)(byte)param_5[8] + (uVar12 >> 8);
      param_5[9] = (char)uVar12;
      uVar12 = (uint)(byte)param_5[7] + (uVar6 >> 8);
      param_5[8] = (char)uVar6;
      uVar6 = (uint)(byte)param_5[6] + (uVar12 >> 8);
      param_5[7] = (char)uVar12;
      uVar12 = (uint)(byte)param_5[5] + (uVar6 >> 8);
      pbVar4 = (byte *)((int)param_6 + uVar10);
      param_5[6] = (char)uVar6;
      uVar14 = (uint)(byte)param_5[4] + (uVar12 >> 8);
      uVar6 = (uint)(byte)param_5[3] + (uVar14 >> 8);
      uVar13 = (uint)(byte)param_5[2] + (uVar6 >> 8);
      param_5[5] = (char)uVar12;
      pbVar7 = (byte *)((int)param_1 + uVar10);
      param_5[4] = (char)uVar14;
      param_5[3] = (char)uVar6;
      iVar2 = (uint)(byte)param_5[1] + (uVar13 >> 8);
      param_5[2] = (char)uVar13;
      puVar5 = (uint *)((int)param_2 + uVar10);
      param_5[1] = (char)iVar2;
      *param_5 = *param_5 + (char)((uint)iVar2 >> 8);
      uVar6 = param_3 - 1;
      if ((((uint)puVar5 | (uint)pbVar4 | (uint)pbVar7) & 3) == 0 &&
          (6 < param_3 &&
          (((uint *)((int)param_6 + iVar3) <= puVar5 || (byte *)((int)param_2 + iVar3) <= pbVar4) &&
          ((uint *)(iVar3 + (int)param_1) <= puVar5 || (byte *)((int)param_2 + iVar3) <= pbVar7))))
      {
        uVar13 = (param_3 - 4 >> 2) + 1;
        uVar12 = uVar10;
        if (2 < uVar6) {
          puVar8 = (uint *)(pbVar7 + -4);
          puVar11 = (uint *)(pbVar4 + -4);
          uVar12 = 0;
          do {
            puVar8 = puVar8 + 1;
            uVar12 = uVar12 + 1;
            puVar11 = puVar11 + 1;
            *puVar5 = *puVar8 ^ *puVar11;
            puVar5 = puVar5 + 1;
          } while (uVar12 < uVar13);
          uVar12 = uVar13 * 4 + uVar10;
          uVar6 = uVar6 + uVar13 * -4;
          if (uVar13 * 4 == param_3) goto LAB_0013c7ee;
        }
        iVar2 = uVar12 + 1;
        *(byte *)((int)param_2 + uVar12) =
             *(byte *)((int)param_1 + uVar12) ^ *(byte *)((int)param_6 + uVar12);
        if (uVar6 != 0) {
          iVar3 = uVar12 + 2;
          *(byte *)((int)param_2 + iVar2) =
               *(byte *)((int)param_6 + iVar2) ^ *(byte *)((int)param_1 + iVar2);
          if (uVar6 != 1) {
            uVar12 = param_3 + uVar10;
            *(byte *)((int)param_2 + iVar3) =
                 *(byte *)((int)param_1 + iVar3) ^ *(byte *)((int)param_6 + iVar3);
            goto LAB_0013c7ee;
          }
        }
        uVar12 = param_3 + uVar10;
      }
      else {
        uVar12 = param_3 + uVar10;
        do {
          pbVar9 = pbVar7 + 1;
          *(byte *)puVar5 = *pbVar7 ^ *pbVar4;
          puVar5 = (uint *)((int)puVar5 + 1);
          pbVar7 = pbVar9;
          pbVar4 = pbVar4 + 1;
        } while (pbVar9 != (byte *)((int)param_1 + uVar12));
      }
LAB_0013c7ee:
      *param_7 = uVar12;
      return;
    }
  }
  else if (param_3 != 0) {
    pbVar7 = (byte *)((int)param_2 + -1);
    puVar5 = param_1;
    do {
      if (uVar10 == 0) {
        (*param_8)(param_5,param_6,param_4);
        bVar1 = param_5[0xf];
        param_5[0xf] = (char)(bVar1 + 1);
        uVar12 = (uint)(byte)param_5[0xe] + (bVar1 + 1 >> 8);
        uVar6 = (uint)(byte)param_5[0xd] + (uVar12 >> 8);
        param_5[0xe] = (char)uVar12;
        uVar12 = (uint)(byte)param_5[0xc] + (uVar6 >> 8);
        param_5[0xd] = (char)uVar6;
        uVar13 = (uint)(byte)param_5[0xb] + (uVar12 >> 8);
        param_5[0xc] = (char)uVar12;
        uVar6 = (uint)(byte)param_5[10] + (uVar13 >> 8);
        param_5[0xb] = (char)uVar13;
        uVar12 = (uint)(byte)param_5[9] + (uVar6 >> 8);
        param_5[10] = (char)uVar6;
        uVar6 = (uint)(byte)param_5[8] + (uVar12 >> 8);
        param_5[9] = (char)uVar12;
        uVar12 = (uint)(byte)param_5[7] + (uVar6 >> 8);
        param_5[8] = (char)uVar6;
        uVar13 = (uint)(byte)param_5[6] + (uVar12 >> 8);
        param_5[7] = (char)uVar12;
        uVar6 = (uint)(byte)param_5[5] + (uVar13 >> 8);
        param_5[6] = (char)uVar13;
        uVar12 = (uint)(byte)param_5[4] + (uVar6 >> 8);
        param_5[5] = (char)uVar6;
        uVar6 = (uint)(byte)param_5[3] + (uVar12 >> 8);
        param_5[4] = (char)uVar12;
        uVar12 = (uint)(byte)param_5[2] + (uVar6 >> 8);
        param_5[3] = (char)uVar6;
        iVar2 = (uint)(byte)param_5[1] + (uVar12 >> 8);
        param_5[2] = (char)uVar12;
        param_5[1] = (char)iVar2;
        *param_5 = *param_5 + (char)((uint)iVar2 >> 8);
      }
      puVar8 = (uint *)((int)puVar5 + 1);
      pbVar4 = (byte *)((int)param_6 + uVar10);
      uVar10 = uVar10 + 1 & 0xf;
      pbVar7 = pbVar7 + 1;
      *pbVar7 = *pbVar4 ^ (byte)*puVar5;
      puVar5 = puVar8;
    } while ((uint *)(param_3 + (int)param_1) != puVar8);
    *param_7 = uVar10;
    return;
  }
  *param_7 = uVar10;
  return;
}

