
void CRYPTO_gcm128_setiv(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  undefined4 uVar11;
  byte bVar12;
  undefined4 uVar13;
  byte bVar14;
  undefined4 *puVar15;
  uint uVar16;
  uint uVar17;
  byte bVar18;
  byte bVar19;
  byte bVar20;
  byte bVar21;
  byte bVar22;
  byte bVar23;
  undefined4 *local_38;
  uint local_34;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x5b] = 0;
  param_1[0x5a] = 0;
  if (param_3 == 0xc) {
    uVar11 = param_2[1];
    iVar10 = 2;
    uVar13 = param_2[2];
    *param_1 = *param_2;
    param_1[1] = uVar11;
    param_1[2] = uVar13;
    *(undefined *)((int)param_1 + 0xf) = 1;
    goto LAB_000ebb76;
  }
  if (param_3 < 0x10) {
    local_34 = param_3;
    if (param_3 != 0) goto LAB_000ebaa4;
  }
  else {
    bVar14 = 0;
    bVar9 = 0;
    bVar20 = 0;
    bVar8 = 0;
    bVar19 = 0;
    bVar7 = 0;
    bVar18 = 0;
    bVar6 = 0;
    bVar22 = 0;
    bVar5 = 0;
    bVar23 = 0;
    bVar4 = 0;
    bVar21 = 0;
    bVar3 = 0;
    bVar12 = 0;
    bVar2 = 0;
    puVar15 = param_2;
    uVar17 = param_3;
    while( true ) {
      uVar17 = uVar17 - 0x10;
      *(byte *)param_1 = bVar12 ^ *(byte *)puVar15;
      *(byte *)((int)param_1 + 1) = bVar21 ^ *(byte *)((int)puVar15 + 1);
      *(byte *)((int)param_1 + 2) = bVar23 ^ *(byte *)((int)puVar15 + 2);
      *(byte *)((int)param_1 + 3) = bVar22 ^ *(byte *)((int)puVar15 + 3);
      *(byte *)(param_1 + 1) = bVar18 ^ *(byte *)(puVar15 + 1);
      *(byte *)((int)param_1 + 5) = bVar19 ^ *(byte *)((int)puVar15 + 5);
      *(byte *)((int)param_1 + 6) = *(byte *)((int)puVar15 + 6) ^ bVar2;
      *(byte *)((int)param_1 + 7) = bVar20 ^ *(byte *)((int)puVar15 + 7);
      *(byte *)(param_1 + 2) = *(byte *)(puVar15 + 2) ^ bVar3;
      *(byte *)((int)param_1 + 9) = *(byte *)((int)puVar15 + 9) ^ bVar4;
      *(byte *)((int)param_1 + 10) = *(byte *)((int)puVar15 + 10) ^ bVar5;
      *(byte *)((int)param_1 + 0xb) = *(byte *)((int)puVar15 + 0xb) ^ bVar6;
      *(byte *)(param_1 + 3) = *(byte *)(puVar15 + 3) ^ bVar7;
      *(byte *)((int)param_1 + 0xd) = *(byte *)((int)puVar15 + 0xd) ^ bVar8;
      *(byte *)((int)param_1 + 0xe) = *(byte *)((int)puVar15 + 0xe) ^ bVar9;
      pbVar1 = (byte *)((int)puVar15 + 0xf);
      puVar15 = puVar15 + 4;
      *(byte *)((int)param_1 + 0xf) = bVar14 ^ *pbVar1;
      gcm_gmult_4bit(param_1,param_1 + 0x18);
      if (uVar17 < 0x10) break;
      bVar2 = *(byte *)((int)param_1 + 6);
      bVar3 = *(byte *)(param_1 + 2);
      bVar12 = *(byte *)param_1;
      bVar4 = *(byte *)((int)param_1 + 9);
      bVar5 = *(byte *)((int)param_1 + 10);
      bVar6 = *(byte *)((int)param_1 + 0xb);
      bVar7 = *(byte *)(param_1 + 3);
      bVar8 = *(byte *)((int)param_1 + 0xd);
      bVar21 = *(byte *)((int)param_1 + 1);
      bVar23 = *(byte *)((int)param_1 + 2);
      bVar22 = *(byte *)((int)param_1 + 3);
      bVar18 = *(byte *)(param_1 + 1);
      bVar19 = *(byte *)((int)param_1 + 5);
      bVar20 = *(byte *)((int)param_1 + 7);
      bVar14 = *(byte *)((int)param_1 + 0xf);
      bVar9 = *(byte *)((int)param_1 + 0xe);
    }
    local_34 = param_3 & 0xf;
    param_2 = (undefined4 *)((int)param_2 + (param_3 - 0x10 & 0xfffffff0) + 0x10);
    if (local_34 != 0) {
LAB_000ebaa4:
      local_38 = param_1 + 0x18;
      uVar17 = local_34 & 0xfffffffc;
      if (local_34 >> 2 == 0 ||
          (local_34 < 4 ||
          (((uint)param_2 & 3) != 0 || param_2 < param_1 + 1 && param_1 < param_2 + 1))) {
        uVar17 = 0;
LAB_000ebb00:
        do {
          *(byte *)((int)param_1 + uVar17) =
               *(byte *)((int)param_1 + uVar17) ^ *(byte *)((int)param_2 + uVar17);
          uVar17 = uVar17 + 1;
        } while (uVar17 < local_34);
      }
      else {
        iVar10 = 0;
        uVar16 = 0;
        do {
          uVar16 = uVar16 + 1;
          *(uint *)((int)param_1 + iVar10) =
               *(uint *)((int)param_2 + iVar10) ^ *(uint *)((int)param_1 + iVar10);
          iVar10 = iVar10 + 4;
        } while (uVar16 < local_34 >> 2);
        if (local_34 != uVar17) goto LAB_000ebb00;
      }
      gcm_gmult_4bit(param_1,local_38);
    }
  }
  local_38 = param_1 + 0x18;
  iVar10 = param_3 << 3;
  *(byte *)(param_1 + 3) = (byte)((uint)iVar10 >> 0x18) ^ *(byte *)(param_1 + 3);
  *(byte *)((int)param_1 + 0xd) = (byte)((uint)iVar10 >> 0x10) ^ *(byte *)((int)param_1 + 0xd);
  *(byte *)((int)param_1 + 0xb) = (byte)(param_3 >> 0x1d) ^ *(byte *)((int)param_1 + 0xb);
  *(byte *)((int)param_1 + 0xf) = (byte)iVar10 ^ *(byte *)((int)param_1 + 0xf);
  *(byte *)((int)param_1 + 0xe) = *(byte *)((int)param_1 + 0xe) ^ (byte)((uint)iVar10 >> 8);
  gcm_gmult_4bit(param_1,local_38);
  iVar10 = ((uint)*(byte *)((int)param_1 + 0xf) |
            (uint)*(byte *)((int)param_1 + 0xd) << 0x10 | (uint)*(byte *)(param_1 + 3) << 0x18 |
           (uint)*(byte *)((int)param_1 + 0xe) << 8) + 1;
LAB_000ebb76:
  (*(code *)param_1[0x5c])(param_1,param_1 + 8,param_1[0x5d]);
  *(char *)((int)param_1 + 0xf) = (char)iVar10;
  *(char *)(param_1 + 3) = (char)((uint)iVar10 >> 0x18);
  *(char *)((int)param_1 + 0xd) = (char)((uint)iVar10 >> 0x10);
  *(char *)((int)param_1 + 0xe) = (char)((uint)iVar10 >> 8);
  return;
}

