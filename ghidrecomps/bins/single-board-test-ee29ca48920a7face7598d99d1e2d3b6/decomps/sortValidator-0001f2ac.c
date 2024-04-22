
undefined4 sortValidator(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int extraout_r1;
  int extraout_r1_00;
  int iVar3;
  int iVar4;
  undefined auStack_1694 [52];
  undefined4 local_1660;
  undefined auStack_165c [32];
  byte abStack_163c [32];
  undefined auStack_161c [1344];
  undefined4 auStack_10dc [512];
  byte abStack_8dc [32];
  undefined4 local_8bc;
  undefined4 uStack_8b8;
  undefined4 uStack_8b4;
  undefined4 uStack_8b0;
  undefined4 local_8ac;
  undefined4 uStack_8a8;
  undefined4 uStack_8a4;
  undefined2 local_8a0;
  int aiStack_89c [512];
  undefined4 *local_9c;
  undefined4 *local_98;
  undefined4 local_94;
  void *local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  size_t local_7c;
  int local_78;
  int local_74;
  int local_70;
  uint local_6c;
  int local_68;
  int *local_64;
  uint local_60;
  uint local_5c;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  size_t local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 local_1c;
  size_t local_18;
  size_t local_14;
  
  local_68 = *param_1;
  local_6c = param_1[1];
  local_70 = param_1[2];
  local_64 = param_1;
  local_74 = __aeabi_idiv(local_68,local_6c + 1);
  local_78 = local_74 + 0xe;
  if (-1 < local_74 + 7) {
    local_78 = local_74 + 7;
  }
  local_78 = local_78 >> 3;
  local_7c = local_78 * (local_6c + 1);
  local_80 = __aeabi_idiv(0x200,local_68);
  iVar3 = local_68 * local_80;
  local_84 = iVar3 + 7;
  if (-1 < iVar3) {
    local_84 = iVar3;
  }
  local_84 = local_84 >> 3;
  iVar3 = __aeabi_idiv(local_68,local_6c + 1);
  iVar3 = iVar3 + 1 << (local_6c & 0xff);
  local_88 = iVar3 + 7;
  if (-1 < iVar3) {
    local_88 = iVar3;
  }
  local_88 = local_88 >> 3;
  local_8c = 0x200;
  local_14 = 4;
  local_18 = 0x200;
  local_1c = 0;
  compare_size = 3;
  expandArray(param_2,local_88,aiStack_89c,0x800,local_74 + 1,1);
  memset(&local_8bc,0,0x1e);
  local_20 = (undefined4 *)malloc(0x4400);
  local_24 = (undefined4 *)malloc(0x4400);
  local_90 = (void *)0x0;
  local_28 = 0;
  memset(abStack_8dc,0,0x1e);
  local_2c = 0;
  do {
    if (local_8c <= local_2c) {
      for (local_34 = 0; local_34 < local_8c; local_34 = local_34 + 1) {
        local_94 = __bswap_32(aiStack_89c[local_34]);
        uVar2 = __aeabi_idiv(local_94,local_80);
        generateHash(local_70,uVar2,auStack_1694,local_84);
        __aeabi_idivmod(local_94,local_80);
        iVar4 = local_68 * extraout_r1;
        iVar3 = iVar4 + 7;
        if (-1 < iVar4) {
          iVar3 = iVar4;
        }
        iVar4 = local_68 + 7;
        if (-1 < local_68) {
          iVar4 = local_68;
        }
        expandArray(auStack_1694 + (iVar3 >> 3),iVar4 >> 3,abStack_163c,local_7c,local_74,0);
        for (local_38 = 0; local_38 < local_7c; local_38 = local_38 + 1) {
          *(byte *)((int)&local_8bc + local_38) =
               abStack_163c[local_38] ^ *(byte *)((int)&local_8bc + local_38);
        }
        memcpy((undefined4 *)((int)local_20 + local_34 * (local_14 + local_7c)),abStack_163c,
               local_7c);
        memcpy((void *)((int)local_20 + local_7c + local_34 * (local_14 + local_7c)),
               aiStack_89c + local_34,local_14);
      }
      iVar3 = isZero(&local_8bc,0x1e);
      if (iVar3 == 0) {
        local_1c = 2;
      }
      else {
        memset(&local_8bc,0,0x1e);
        for (local_3c = 0; local_3c < 9; local_3c = local_3c + 1) {
          qsort(local_20,local_18,local_7c + local_14,compareSR + 1);
          local_28 = 0;
          for (local_40 = 0; puVar1 = local_20, local_40 < local_18; local_40 = local_40 + 2) {
            for (local_44 = 0; local_44 < local_7c; local_44 = local_44 + 1) {
              abStack_8dc[local_44] =
                   *(byte *)(local_44 + (local_40 + 1) * (local_14 + local_7c) + (int)local_20) ^
                   *(byte *)(local_44 + local_40 * (local_14 + local_7c) + (int)local_20);
            }
            memcpy((undefined4 *)((local_40 >> 1) * (local_7c + local_14 * 2) + (int)local_24),
                   abStack_8dc,local_7c);
            memcpy((void *)((int)local_24 + local_7c + (local_40 >> 1) * (local_7c + local_14 * 2)),
                   (void *)(local_7c + local_40 * (local_14 + local_7c) + (int)local_20),local_14);
            memcpy((void *)((int)local_24 +
                           local_14 + (local_40 >> 1) * (local_7c + local_14 * 2) + local_7c),
                   (void *)(local_7c + (local_40 + 1) * (local_14 + local_7c) + (int)local_20),
                   local_14);
            local_28 = local_28 + 1;
          }
          local_14 = local_14 << 1;
          local_98 = local_20;
          local_20 = local_24;
          local_24 = puVar1;
          local_18 = local_28;
          compare_size = compare_size + 3;
        }
        for (local_48 = 0; local_48 < 0x200; local_48 = local_48 + 1) {
          uVar2 = __bswap_32(*(undefined4 *)(local_7c + local_48 * 4 + (int)local_20));
          auStack_10dc[local_48] = uVar2;
        }
        for (local_4c = 0; local_4c < 9; local_4c = local_4c + 1) {
          for (local_50 = 0; local_50 < 0x200; local_50 = (2 << (local_4c & 0xff)) + local_50) {
            sort_pair(auStack_10dc + local_50,1 << (local_4c & 0xff));
          }
        }
        local_14 = 4;
        local_18 = 0x200;
        for (local_54 = 0; local_54 < local_8c; local_54 = local_54 + 1) {
          local_1660 = auStack_10dc[local_54];
          uVar2 = __aeabi_idiv(local_1660,local_80);
          generateHash(local_70,uVar2,auStack_1694,local_84);
          __aeabi_idivmod(local_1660,local_80);
          iVar4 = local_68 * extraout_r1_00;
          iVar3 = iVar4 + 7;
          if (-1 < iVar4) {
            iVar3 = iVar4;
          }
          iVar4 = local_68 + 7;
          if (-1 < local_68) {
            iVar4 = local_68;
          }
          expandArray(auStack_1694 + (iVar3 >> 3),iVar4 >> 3,auStack_165c,local_7c,local_74,0);
          local_1660 = __bswap_32(auStack_10dc[local_54]);
          memcpy((undefined4 *)((int)local_20 + local_54 * (local_14 + local_7c)),auStack_165c,
                 local_7c);
          memcpy((void *)((int)local_20 + local_7c + local_54 * (local_14 + local_7c)),&local_1660,
                 local_14);
          local_90 = (void *)bin2hex((undefined4 *)
                                     (local_54 * (local_14 + local_7c) + (int)local_20),0x22);
          free(local_90);
        }
        for (local_58 = 0; local_58 < 9; local_58 = local_58 + 1) {
          local_28 = 0;
          for (local_5c = 0; puVar1 = local_20, local_5c < local_18; local_5c = local_5c + 2) {
            for (local_60 = 0; local_60 < local_7c; local_60 = local_60 + 1) {
              abStack_8dc[local_60] =
                   *(byte *)(local_60 + (local_5c + 1) * (local_14 + local_7c) + (int)local_20) ^
                   *(byte *)(local_60 + local_5c * (local_14 + local_7c) + (int)local_20);
            }
            memcpy((undefined4 *)((local_5c >> 1) * (local_7c + local_14 * 2) + (int)local_24),
                   abStack_8dc,local_7c);
            memcpy((void *)((int)local_24 + local_7c + (local_5c >> 1) * (local_7c + local_14 * 2)),
                   (void *)(local_7c + local_5c * (local_14 + local_7c) + (int)local_20),local_14);
            memcpy((void *)((int)local_24 +
                           local_14 + (local_5c >> 1) * (local_7c + local_14 * 2) + local_7c),
                   (void *)(local_7c + (local_5c + 1) * (local_14 + local_7c) + (int)local_20),
                   local_14);
            local_28 = local_28 + 1;
          }
          local_14 = local_14 << 1;
          local_9c = local_20;
          local_20 = local_24;
          local_24 = puVar1;
          local_18 = local_28;
          compare_size = compare_size + 3;
        }
        getIndices(local_20,local_7c,0x800,0x14,auStack_161c,0x540);
        local_90 = (void *)bin2hex(auStack_161c,0x540);
        free(local_90);
        local_90 = (void *)bin2hex(local_20,local_14 + local_7c);
        free(local_90);
        local_8bc = *local_20;
        uStack_8b8 = local_20[1];
        uStack_8b4 = local_20[2];
        uStack_8b0 = local_20[3];
        local_8ac = local_20[4];
        uStack_8a8 = local_20[5];
        uStack_8a4 = local_20[6];
        local_8a0 = *(undefined2 *)(local_20 + 7);
        iVar3 = isZero(&local_8bc,0x1e);
        if (iVar3 == 0) {
          local_1c = 3;
        }
      }
LAB_00020252:
      free(local_20);
      free(local_24);
      return local_1c;
    }
    for (local_30 = local_2c + 1; local_30 < local_8c; local_30 = local_30 + 1) {
      if (aiStack_89c[local_2c] == aiStack_89c[local_30]) {
        local_1c = 1;
        goto LAB_00020252;
      }
    }
    local_2c = local_2c + 1;
  } while( true );
}

