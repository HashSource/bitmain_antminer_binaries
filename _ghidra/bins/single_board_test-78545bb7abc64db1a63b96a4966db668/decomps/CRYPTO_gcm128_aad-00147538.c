
undefined4 CRYPTO_gcm128_aad(int param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  bool bVar5;
  
  if (*(int *)(param_1 + 0x3c) != 0 || *(int *)(param_1 + 0x38) != 0) {
    return 0xfffffffe;
  }
  iVar2 = *(uint *)(param_1 + 0x30) + param_3;
  uVar3 = *(int *)(param_1 + 0x34) + (uint)CARRY4(*(uint *)(param_1 + 0x30),param_3);
  bVar5 = 0x1fffffff < uVar3;
  if (uVar3 == 0x20000000) {
    bVar5 = iVar2 != 0;
  }
  if (bVar5) {
    return 0xffffffff;
  }
  uVar1 = *(uint *)(param_1 + 0x16c);
  *(int *)(param_1 + 0x30) = iVar2;
  *(uint *)(param_1 + 0x34) = uVar3;
  if (uVar1 != 0) {
    puVar4 = param_2;
    if (param_3 == 0) {
LAB_0014759e:
      *(uint *)(param_1 + 0x16c) = uVar1;
      return 0;
    }
    do {
      iVar2 = param_1 + uVar1;
      uVar3 = uVar1 + 1 & 0xf;
      param_2 = (uint *)((int)puVar4 + 1);
      if (uVar3 != 0) {
        uVar3 = 1;
      }
      param_3 = param_3 - 1;
      uVar3 = uVar3 & 1;
      if (param_3 == 0) {
        uVar3 = 0;
      }
      uVar1 = uVar1 + 1 & 0xf;
      *(byte *)(iVar2 + 0x40) = (byte)*puVar4 ^ *(byte *)(iVar2 + 0x40);
      puVar4 = param_2;
    } while (uVar3 != 0);
    if (uVar1 != 0) goto LAB_0014759e;
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
  }
  uVar3 = param_3 & 0xfffffff0;
  if (uVar3 == 0) {
    if (param_3 != 0) {
LAB_001475e6:
      if (((uint)param_2 & 3) == 0 &&
          (5 < param_3 &&
          ((uint *)(param_1 + 0x44) <= param_2 || param_2 + 1 <= (uint *)(param_1 + 0x40)))) {
        uVar3 = param_3;
        if (param_3 == 0) {
          uVar3 = 1;
        }
        iVar2 = (uVar3 - 4 >> 2) + 1;
        uVar1 = iVar2 * 4;
        if (param_3 < 4) {
          uVar1 = 0;
        }
        else {
          *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) ^ *param_2;
          if (((iVar2 != 1) &&
              (*(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) ^ param_2[1], iVar2 != 2)) &&
             (*(uint *)(param_1 + 0x48) = param_2[2] ^ *(uint *)(param_1 + 0x48), iVar2 != 3)) {
            *(uint *)(param_1 + 0x4c) = param_2[3] ^ *(uint *)(param_1 + 0x4c);
          }
          if (uVar1 == uVar3) goto LAB_001475c2;
        }
        uVar3 = uVar1 + 1;
        *(byte *)(param_1 + uVar1 + 0x40) =
             *(byte *)(param_1 + uVar1 + 0x40) ^ *(byte *)((int)param_2 + uVar1);
        if (uVar3 < param_3) {
          uVar1 = uVar1 + 2;
          *(byte *)(param_1 + uVar3 + 0x40) =
               *(byte *)(param_1 + uVar3 + 0x40) ^ *(byte *)((int)param_2 + uVar3);
          if (uVar1 < param_3) {
            *(byte *)(param_1 + uVar1 + 0x40) =
                 *(byte *)(param_1 + uVar1 + 0x40) ^ *(byte *)((int)param_2 + uVar1);
            *(uint *)(param_1 + 0x16c) = param_3;
            return 0;
          }
        }
      }
      else {
        *(byte *)(param_1 + 0x40) = *(byte *)(param_1 + 0x40) ^ (byte)*param_2;
        if ((((((((param_3 != 1) &&
                 (*(byte *)(param_1 + 0x41) =
                       *(byte *)((int)param_2 + 1) ^ *(byte *)(param_1 + 0x41), param_3 != 2)) &&
                (*(byte *)(param_1 + 0x42) = *(byte *)((int)param_2 + 2) ^ *(byte *)(param_1 + 0x42)
                , param_3 != 3)) &&
               ((*(byte *)(param_1 + 0x43) = *(byte *)((int)param_2 + 3) ^ *(byte *)(param_1 + 0x43)
                , param_3 != 4 &&
                (*(byte *)(param_1 + 0x44) = (byte)param_2[1] ^ *(byte *)(param_1 + 0x44),
                5 < param_3)))) &&
              ((*(byte *)(param_1 + 0x45) = *(byte *)((int)param_2 + 5) ^ *(byte *)(param_1 + 0x45),
               6 < param_3 &&
               ((*(byte *)(param_1 + 0x46) = *(byte *)((int)param_2 + 6) ^ *(byte *)(param_1 + 0x46)
                , param_3 != 7 &&
                (*(byte *)(param_1 + 0x47) = *(byte *)((int)param_2 + 7) ^ *(byte *)(param_1 + 0x47)
                , param_3 != 8)))))) &&
             (*(byte *)(param_1 + 0x48) = (byte)param_2[2] ^ *(byte *)(param_1 + 0x48), param_3 != 9
             )) && (((*(byte *)(param_1 + 0x49) =
                           *(byte *)((int)param_2 + 9) ^ *(byte *)(param_1 + 0x49), param_3 != 10 &&
                     (*(byte *)(param_1 + 0x4a) =
                           *(byte *)((int)param_2 + 10) ^ *(byte *)(param_1 + 0x4a), param_3 != 0xb)
                     ) && (*(byte *)(param_1 + 0x4b) =
                                *(byte *)((int)param_2 + 0xb) ^ *(byte *)(param_1 + 0x4b),
                          param_3 != 0xc)))) &&
           (((*(byte *)(param_1 + 0x4c) = (byte)param_2[3] ^ *(byte *)(param_1 + 0x4c),
             param_3 != 0xd &&
             (*(byte *)(param_1 + 0x4d) = *(byte *)((int)param_2 + 0xd) ^ *(byte *)(param_1 + 0x4d),
             param_3 != 0xe)) &&
            (*(byte *)(param_1 + 0x4e) = *(byte *)((int)param_2 + 0xe) ^ *(byte *)(param_1 + 0x4e),
            param_3 != 0xf)))) {
          *(byte *)(param_1 + 0x4f) = *(byte *)(param_1 + 0x4f) ^ *(byte *)((int)param_2 + 0xf);
        }
      }
      goto LAB_001475c2;
    }
  }
  else {
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_2,uVar3);
    param_3 = param_3 - uVar3;
    if (param_3 != 0) {
      param_2 = (uint *)((int)param_2 + uVar3);
      goto LAB_001475e6;
    }
  }
  param_3 = 0;
LAB_001475c2:
  *(uint *)(param_1 + 0x16c) = param_3;
  return 0;
}

