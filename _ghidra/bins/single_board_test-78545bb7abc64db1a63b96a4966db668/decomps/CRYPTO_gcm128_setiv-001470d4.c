
void CRYPTO_gcm128_setiv(uint *param_1,uint *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x5b] = 0;
  param_1[0x5a] = 0;
  if (param_3 == 0xc) {
    uVar8 = param_2[1];
    iVar4 = 2;
    uVar3 = param_2[2];
    *param_1 = *param_2;
    param_1[1] = uVar8;
    param_1[2] = uVar3;
    *(undefined1 *)(param_1 + 3) = 0;
    *(undefined1 *)((int)param_1 + 0xd) = 0;
    *(undefined1 *)((int)param_1 + 0xe) = 0;
    *(undefined1 *)((int)param_1 + 0xf) = 1;
    goto LAB_00147388;
  }
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  puVar6 = param_1 + 0x10;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  puVar7 = param_1 + 0x18;
  uVar8 = param_3;
  if (0xf < param_3) {
    puVar5 = param_2 + 4;
    do {
      uVar8 = uVar8 - 0x10;
      *(byte *)(param_1 + 0x10) = (byte)param_1[0x10] ^ (byte)puVar5[-4];
      *(byte *)((int)param_1 + 0x41) =
           *(byte *)((int)puVar5 + -0xf) ^ *(byte *)((int)param_1 + 0x41);
      *(byte *)((int)param_1 + 0x42) =
           *(byte *)((int)param_1 + 0x42) ^ *(byte *)((int)puVar5 + -0xe);
      *(byte *)((int)param_1 + 0x43) =
           *(byte *)((int)param_1 + 0x43) ^ *(byte *)((int)puVar5 + -0xd);
      *(byte *)(param_1 + 0x11) = (byte)param_1[0x11] ^ (byte)puVar5[-3];
      *(byte *)((int)param_1 + 0x45) =
           *(byte *)((int)puVar5 + -0xb) ^ *(byte *)((int)param_1 + 0x45);
      *(byte *)((int)param_1 + 0x46) = *(byte *)((int)param_1 + 0x46) ^ *(byte *)((int)puVar5 + -10)
      ;
      *(byte *)((int)param_1 + 0x47) = *(byte *)((int)param_1 + 0x47) ^ *(byte *)((int)puVar5 + -9);
      *(byte *)(param_1 + 0x12) = (byte)param_1[0x12] ^ (byte)puVar5[-2];
      *(byte *)((int)param_1 + 0x49) = *(byte *)((int)puVar5 + -7) ^ *(byte *)((int)param_1 + 0x49);
      *(byte *)((int)param_1 + 0x4a) = *(byte *)((int)param_1 + 0x4a) ^ *(byte *)((int)puVar5 + -6);
      *(byte *)((int)param_1 + 0x4b) = *(byte *)((int)puVar5 + -5) ^ *(byte *)((int)param_1 + 0x4b);
      *(byte *)(param_1 + 0x13) = (byte)param_1[0x13] ^ (byte)puVar5[-1];
      *(byte *)((int)param_1 + 0x4d) = *(byte *)((int)param_1 + 0x4d) ^ *(byte *)((int)puVar5 + -3);
      *(byte *)((int)param_1 + 0x4e) = *(byte *)((int)puVar5 + -2) ^ *(byte *)((int)param_1 + 0x4e);
      *(byte *)((int)param_1 + 0x4f) = *(byte *)((int)param_1 + 0x4f) ^ *(byte *)((int)puVar5 + -1);
      gcm_gmult_4bit(puVar6,puVar7);
      puVar5 = puVar5 + 4;
    } while (0xf < uVar8);
    uVar8 = param_3 & 0xf;
    param_2 = (uint *)((int)param_2 + (param_3 - 0x10 & 0xfffffff0) + 0x10);
  }
  if (uVar8 != 0) {
    bVar10 = param_2 <= param_1 + 0x11;
    bVar9 = param_1 + 0x11 == param_2;
    if (bVar10 && !bVar9) {
      bVar10 = puVar6 <= param_2 + 1;
      bVar9 = param_2 + 1 == puVar6;
    }
    if (((uint)param_2 & 3) != 0 || (uVar8 < 6 || bVar10 && !bVar9)) {
      *(byte *)(param_1 + 0x10) = (byte)*param_2 ^ (byte)param_1[0x10];
      if ((((((uVar8 != 1) &&
             (*(byte *)((int)param_1 + 0x41) =
                   *(byte *)((int)param_1 + 0x41) ^ *(byte *)((int)param_2 + 1), uVar8 != 2)) &&
            (*(byte *)((int)param_1 + 0x42) =
                  *(byte *)((int)param_1 + 0x42) ^ *(byte *)((int)param_2 + 2), uVar8 != 3)) &&
           (((*(byte *)((int)param_1 + 0x43) =
                   *(byte *)((int)param_1 + 0x43) ^ *(byte *)((int)param_2 + 3), uVar8 != 4 &&
             (*(byte *)(param_1 + 0x11) = (byte)param_1[0x11] ^ (byte)param_2[1], 5 < uVar8)) &&
            ((*(byte *)((int)param_1 + 0x45) =
                   *(byte *)((int)param_1 + 0x45) ^ *(byte *)((int)param_2 + 5), 6 < uVar8 &&
             ((*(byte *)((int)param_1 + 0x46) =
                    *(byte *)((int)param_2 + 6) ^ *(byte *)((int)param_1 + 0x46), uVar8 != 7 &&
              (*(byte *)((int)param_1 + 0x47) =
                    *(byte *)((int)param_2 + 7) ^ *(byte *)((int)param_1 + 0x47), uVar8 != 8))))))))
          && (*(byte *)(param_1 + 0x12) = (byte)param_2[2] ^ (byte)param_1[0x12], uVar8 != 9)) &&
         ((((*(byte *)((int)param_1 + 0x49) =
                  *(byte *)((int)param_2 + 9) ^ *(byte *)((int)param_1 + 0x49), uVar8 != 10 &&
            (*(byte *)((int)param_1 + 0x4a) =
                  *(byte *)((int)param_2 + 10) ^ *(byte *)((int)param_1 + 0x4a), uVar8 != 0xb)) &&
           (*(byte *)((int)param_1 + 0x4b) =
                 *(byte *)((int)param_2 + 0xb) ^ *(byte *)((int)param_1 + 0x4b), uVar8 != 0xc)) &&
          (*(byte *)(param_1 + 0x13) = (byte)param_2[3] ^ (byte)param_1[0x13], uVar8 != 0xd)))) {
        bVar1 = *(byte *)((int)param_1 + 0x4d);
        bVar2 = *(byte *)((int)param_2 + 0xd) ^ bVar1;
        if (uVar8 == 0xf) {
          bVar1 = *(byte *)((int)param_1 + 0x4e);
        }
        *(byte *)((int)param_1 + 0x4d) = bVar2;
        if (uVar8 == 0xf) {
          *(byte *)((int)param_1 + 0x4e) = *(byte *)((int)param_2 + 0xe) ^ bVar1;
        }
      }
    }
    else {
      iVar4 = (uVar8 - 4 >> 2) + 1;
      uVar3 = iVar4 * 4;
      if (uVar8 - 1 < 3) {
        uVar3 = 0;
      }
      else {
        param_1[0x10] = param_1[0x10] ^ *param_2;
        if (((iVar4 != 1) && (param_1[0x11] = param_2[1] ^ param_1[0x11], iVar4 != 2)) &&
           (param_1[0x12] = param_2[2] ^ param_1[0x12], iVar4 != 3)) {
          param_1[0x13] = param_2[3] ^ param_1[0x13];
        }
        if (uVar8 == uVar3) goto LAB_00147310;
      }
      *(byte *)((int)param_1 + uVar3 + 0x40) =
           *(byte *)((int)param_1 + uVar3 + 0x40) ^ *(byte *)((int)param_2 + uVar3);
      if (uVar3 + 1 < uVar8) {
        *(byte *)((int)param_1 + uVar3 + 0x41) =
             *(byte *)((int)param_1 + uVar3 + 0x41) ^ *(byte *)((int)param_2 + uVar3 + 1);
        if (uVar3 + 2 < uVar8) {
          *(byte *)((int)param_1 + uVar3 + 0x42) =
               *(byte *)((int)param_1 + uVar3 + 0x42) ^ *(byte *)((int)param_2 + uVar3 + 2);
        }
      }
    }
LAB_00147310:
    gcm_gmult_4bit(puVar6,puVar7);
  }
  iVar4 = param_3 << 3;
  *(byte *)((int)param_1 + 0x4b) = *(byte *)((int)param_1 + 0x4b) ^ (byte)(param_3 >> 0x1d);
  *(byte *)((int)param_1 + 0x4e) = *(byte *)((int)param_1 + 0x4e) ^ (byte)((uint)iVar4 >> 8);
  *(byte *)((int)param_1 + 0x4f) = (byte)iVar4 ^ *(byte *)((int)param_1 + 0x4f);
  *(byte *)(param_1 + 0x13) = (byte)param_1[0x13] ^ (byte)((uint)iVar4 >> 0x18);
  *(byte *)((int)param_1 + 0x4d) = *(byte *)((int)param_1 + 0x4d) ^ (byte)((uint)iVar4 >> 0x10);
  gcm_gmult_4bit(puVar6,puVar7);
  uVar8 = param_1[0x13];
  iVar4 = (uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 | uVar8 >> 0x18
          ) + 1;
  *param_1 = param_1[0x10];
  param_1[1] = param_1[0x11];
  param_1[2] = param_1[0x12];
  param_1[3] = param_1[0x13];
LAB_00147388:
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  (*(code *)param_1[0x5c])(param_1,param_1 + 8,param_1[0x5d]);
  *(char *)((int)param_1 + 0xf) = (char)iVar4;
  *(char *)(param_1 + 3) = (char)((uint)iVar4 >> 0x18);
  *(char *)((int)param_1 + 0xd) = (char)((uint)iVar4 >> 0x10);
  *(char *)((int)param_1 + 0xe) = (char)((uint)iVar4 >> 8);
  return;
}

