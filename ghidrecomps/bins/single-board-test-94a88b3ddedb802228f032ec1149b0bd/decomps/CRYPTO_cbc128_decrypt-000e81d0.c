
void CRYPTO_cbc128_decrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,uint *param_5,
               code *param_6)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  uint *puVar12;
  uint *puVar13;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  if (param_1 == param_2) {
    puVar7 = param_2;
    if ((((uint)param_5 | (uint)param_2) & 3) == 0) {
      if (0xf < param_3) {
        puVar10 = param_1;
        uVar9 = param_3;
        puVar7 = param_1;
        do {
          uVar9 = uVar9 - 0x10;
          (*param_6)(puVar10,&local_38,param_4);
          uVar5 = *puVar7;
          *puVar7 = *param_5 ^ local_38;
          *param_5 = uVar5;
          uVar5 = puVar10[1];
          puVar10[1] = param_5[1] ^ local_34;
          param_5[1] = uVar5;
          uVar5 = puVar10[2];
          puVar10[2] = param_5[2] ^ local_30;
          param_5[2] = uVar5;
          uVar5 = puVar10[3];
          puVar10[3] = param_5[3] ^ local_2c;
          puVar10 = puVar10 + 4;
          param_5[3] = uVar5;
          puVar7 = puVar7 + 4;
        } while (0xf < uVar9);
        uVar9 = param_3 - 0x10;
        param_3 = param_3 & 0xf;
        param_2 = (uint *)((uVar9 & 0xfffffff0) + 0x10 + (int)param_1);
        puVar7 = param_2;
      }
    }
    else if (0xf < param_3) {
      puVar10 = param_1;
      uVar9 = param_3;
      puVar7 = param_1;
      do {
        uVar9 = uVar9 - 0x10;
        (*param_6)(puVar10,&local_38,param_4);
        bVar1 = *(byte *)puVar7;
        *(byte *)puVar7 = *(byte *)param_5 ^ (byte)local_38;
        *(byte *)param_5 = bVar1;
        bVar1 = *(byte *)((int)puVar10 + 1);
        *(byte *)((int)puVar10 + 1) = *(byte *)((int)param_5 + 1) ^ local_38._1_1_;
        *(byte *)((int)param_5 + 1) = bVar1;
        bVar1 = *(byte *)((int)puVar10 + 2);
        *(byte *)((int)puVar10 + 2) = *(byte *)((int)param_5 + 2) ^ local_38._2_1_;
        *(byte *)((int)param_5 + 2) = bVar1;
        bVar1 = *(byte *)((int)puVar10 + 3);
        *(byte *)((int)puVar10 + 3) = *(byte *)((int)param_5 + 3) ^ local_38._3_1_;
        *(byte *)((int)param_5 + 3) = bVar1;
        bVar1 = *(byte *)(puVar10 + 1);
        *(byte *)(puVar10 + 1) = *(byte *)(param_5 + 1) ^ (byte)local_34;
        *(byte *)(param_5 + 1) = bVar1;
        bVar1 = *(byte *)((int)puVar10 + 5);
        *(byte *)((int)puVar10 + 5) = *(byte *)((int)param_5 + 5) ^ local_34._1_1_;
        *(byte *)((int)param_5 + 5) = bVar1;
        bVar1 = *(byte *)((int)puVar10 + 6);
        *(byte *)((int)puVar10 + 6) = *(byte *)((int)param_5 + 6) ^ local_34._2_1_;
        *(byte *)((int)param_5 + 6) = bVar1;
        bVar1 = *(byte *)((int)puVar10 + 7);
        *(byte *)((int)puVar10 + 7) = *(byte *)((int)param_5 + 7) ^ local_34._3_1_;
        *(byte *)((int)param_5 + 7) = bVar1;
        bVar1 = *(byte *)(puVar10 + 2);
        *(byte *)(puVar10 + 2) = *(byte *)(param_5 + 2) ^ (byte)local_30;
        *(byte *)(param_5 + 2) = bVar1;
        bVar1 = *(byte *)((int)puVar10 + 9);
        *(byte *)((int)puVar10 + 9) = *(byte *)((int)param_5 + 9) ^ local_30._1_1_;
        *(byte *)((int)param_5 + 9) = bVar1;
        bVar1 = *(byte *)((int)puVar10 + 10);
        *(byte *)((int)puVar10 + 10) = *(byte *)((int)param_5 + 10) ^ local_30._2_1_;
        *(byte *)((int)param_5 + 10) = bVar1;
        bVar1 = *(byte *)((int)puVar10 + 0xb);
        *(byte *)((int)puVar10 + 0xb) = *(byte *)((int)param_5 + 0xb) ^ local_30._3_1_;
        *(byte *)((int)param_5 + 0xb) = bVar1;
        bVar1 = *(byte *)(puVar10 + 3);
        *(byte *)(puVar10 + 3) = *(byte *)(param_5 + 3) ^ (byte)local_2c;
        *(byte *)(param_5 + 3) = bVar1;
        bVar1 = *(byte *)((int)puVar10 + 0xd);
        *(byte *)((int)puVar10 + 0xd) = *(byte *)((int)param_5 + 0xd) ^ local_2c._1_1_;
        *(byte *)((int)param_5 + 0xd) = bVar1;
        bVar1 = *(byte *)((int)puVar10 + 0xe);
        *(byte *)((int)puVar10 + 0xe) = *(byte *)((int)param_5 + 0xe) ^ local_2c._2_1_;
        *(byte *)((int)param_5 + 0xe) = bVar1;
        bVar1 = *(byte *)((int)puVar10 + 0xf);
        *(byte *)((int)puVar10 + 0xf) = *(byte *)((int)param_5 + 0xf) ^ local_2c._3_1_;
        puVar10 = puVar10 + 4;
        *(byte *)((int)param_5 + 0xf) = bVar1;
        puVar7 = puVar7 + 4;
      } while (0xf < uVar9);
      uVar9 = param_3 - 0x10;
      param_3 = param_3 & 0xf;
      param_2 = (uint *)((uVar9 & 0xfffffff0) + 0x10 + (int)param_1);
      puVar7 = param_2;
    }
    goto LAB_000e8312;
  }
  puVar7 = param_5;
  if ((((uint)param_2 | (uint)param_1 | (uint)param_5) & 3) == 0) {
    if (0xf < param_3) {
      puVar13 = param_2 + 4;
      uVar9 = param_3;
      puVar7 = param_2;
      puVar10 = param_5;
      puVar12 = param_1;
      do {
        uVar9 = uVar9 - 0x10;
        (*param_6)(puVar12,puVar7,param_4);
        puVar13[-4] = puVar13[-4] ^ *puVar10;
        puVar13 = puVar13 + 4;
        puVar7[1] = puVar7[1] ^ puVar10[1];
        puVar7[2] = puVar7[2] ^ puVar10[2];
        puVar7[3] = puVar7[3] ^ puVar10[3];
        puVar7 = puVar7 + 4;
        puVar10 = puVar12;
        puVar12 = puVar12 + 4;
      } while (0xf < uVar9);
      goto LAB_000e82e4;
    }
  }
  else if (0xf < param_3) {
    puVar13 = param_2 + 4;
    uVar9 = param_3;
    puVar7 = param_2;
    puVar10 = param_5;
    puVar12 = param_1;
    do {
      uVar9 = uVar9 - 0x10;
      (*param_6)(puVar12,puVar7,param_4);
      *(byte *)(puVar13 + -4) = *(byte *)(puVar13 + -4) ^ *(byte *)puVar10;
      puVar13 = puVar13 + 4;
      *(byte *)((int)puVar7 + 1) = *(byte *)((int)puVar10 + 1) ^ *(byte *)((int)puVar7 + 1);
      *(byte *)((int)puVar7 + 2) = *(byte *)((int)puVar10 + 2) ^ *(byte *)((int)puVar7 + 2);
      *(byte *)((int)puVar7 + 3) = *(byte *)((int)puVar10 + 3) ^ *(byte *)((int)puVar7 + 3);
      *(byte *)(puVar7 + 1) = *(byte *)(puVar10 + 1) ^ *(byte *)(puVar7 + 1);
      *(byte *)((int)puVar7 + 5) = *(byte *)((int)puVar10 + 5) ^ *(byte *)((int)puVar7 + 5);
      *(byte *)((int)puVar7 + 6) = *(byte *)((int)puVar10 + 6) ^ *(byte *)((int)puVar7 + 6);
      *(byte *)((int)puVar7 + 7) = *(byte *)((int)puVar10 + 7) ^ *(byte *)((int)puVar7 + 7);
      *(byte *)(puVar7 + 2) = *(byte *)(puVar10 + 2) ^ *(byte *)(puVar7 + 2);
      *(byte *)((int)puVar7 + 9) = *(byte *)((int)puVar10 + 9) ^ *(byte *)((int)puVar7 + 9);
      *(byte *)((int)puVar7 + 10) = *(byte *)((int)puVar10 + 10) ^ *(byte *)((int)puVar7 + 10);
      *(byte *)((int)puVar7 + 0xb) = *(byte *)((int)puVar10 + 0xb) ^ *(byte *)((int)puVar7 + 0xb);
      *(byte *)(puVar7 + 3) = *(byte *)(puVar10 + 3) ^ *(byte *)(puVar7 + 3);
      *(byte *)((int)puVar7 + 0xd) = *(byte *)((int)puVar10 + 0xd) ^ *(byte *)((int)puVar7 + 0xd);
      *(byte *)((int)puVar7 + 0xe) = *(byte *)((int)puVar10 + 0xe) ^ *(byte *)((int)puVar7 + 0xe);
      *(byte *)((int)puVar7 + 0xf) = *(byte *)((int)puVar10 + 0xf) ^ *(byte *)((int)puVar7 + 0xf);
      puVar7 = puVar7 + 4;
      puVar10 = puVar12;
      puVar12 = puVar12 + 4;
    } while (0xf < uVar9);
LAB_000e82e4:
    uVar9 = param_3 - 0x10;
    param_3 = param_3 & 0xf;
    iVar11 = (uVar9 >> 4) + 1;
    puVar7 = (uint *)((int)param_1 + (uVar9 & 0xfffffff0));
    param_2 = param_2 + iVar11 * 4;
    param_1 = param_1 + iVar11 * 4;
  }
  uVar9 = puVar7[1];
  uVar5 = puVar7[2];
  uVar8 = puVar7[3];
  *param_5 = *puVar7;
  param_5[1] = uVar9;
  param_5[2] = uVar5;
  param_5[3] = uVar8;
  puVar7 = param_1;
LAB_000e8312:
  if (param_3 != 0) {
    (*param_6)(puVar7,&local_38,param_4);
    uVar9 = 0;
    do {
      bVar1 = *(byte *)((int)puVar7 + uVar9);
      *(byte *)((int)param_2 + uVar9) =
           *(byte *)((int)&local_38 + uVar9) ^ *(byte *)((int)param_5 + uVar9);
      *(byte *)((int)param_5 + uVar9) = bVar1;
      uVar9 = uVar9 + 1;
    } while (uVar9 < 0x10 && uVar9 < param_3);
    if (uVar9 < 0x10) {
      puVar4 = (undefined4 *)((int)puVar7 + uVar9);
      puVar6 = (undefined4 *)((int)param_5 + uVar9);
      uVar5 = ~uVar9 + 0x11;
      if (uVar5 >> 2 != 0 &&
          ((((uint)puVar4 | (uint)puVar6) & 3) == 0 &&
          (3 < uVar5 && (puVar6 + 1 <= puVar4 || puVar4 + 1 <= puVar6)))) {
        puVar4 = puVar4 + -1;
        uVar8 = 0;
        puVar2 = puVar6 + 1;
        do {
          puVar3 = puVar2;
          puVar4 = puVar4 + 1;
          uVar8 = uVar8 + 1;
          *puVar6 = *puVar4;
          puVar2 = puVar3 + 1;
          puVar6 = puVar3;
        } while (uVar8 < uVar5 >> 2);
        uVar9 = (uVar5 & 0xfffffffc) + uVar9;
        if (uVar5 == (uVar5 & 0xfffffffc)) {
          return;
        }
      }
      do {
        *(byte *)((int)param_5 + uVar9) = *(byte *)((int)puVar7 + uVar9);
        uVar9 = uVar9 + 1;
      } while (uVar9 < 0x10);
    }
  }
  return;
}

