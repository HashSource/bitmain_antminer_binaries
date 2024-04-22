
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 sortValidator(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_r1;
  int extraout_r1_00;
  int iVar4;
  uint uVar5;
  undefined4 local_1760;
  undefined4 uStack_175c;
  undefined4 uStack_1758;
  undefined4 uStack_1754;
  undefined2 local_1750;
  uint local_1660;
  undefined auStack_165c [32];
  byte abStack_163c [32];
  undefined auStack_161c [1344];
  uint auStack_10dc [512];
  undefined4 local_8dc;
  undefined4 local_8d8;
  undefined4 local_8d4;
  undefined4 local_8d0;
  undefined4 local_8cc;
  undefined4 local_8c8;
  undefined4 local_8c4;
  undefined2 local_8c0;
  undefined4 local_8bc;
  undefined4 uStack_8b8;
  undefined4 uStack_8b4;
  undefined4 uStack_8b0;
  undefined4 local_8ac;
  undefined4 uStack_8a8;
  undefined4 uStack_8a4;
  undefined2 local_8a0;
  uint auStack_89c [512];
  undefined4 *local_9c;
  undefined4 *local_98;
  uint local_94;
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
  local_78 = local_74 + 7;
  if (local_74 + 7 < 0) {
    local_78 = local_74 + 0xe;
  }
  local_78 = local_78 >> 3;
  local_7c = local_78 * (local_6c + 1);
  local_80 = __aeabi_idiv(0x200,local_68);
  local_84 = local_68 * local_80;
  if (local_84 < 0) {
    local_84 = local_84 + 7;
  }
  local_84 = local_84 >> 3;
  iVar2 = __aeabi_idiv(local_68,local_6c + 1);
  local_88 = iVar2 + 1 << (local_6c & 0xff);
  if (local_88 < 0) {
    local_88 = local_88 + 7;
  }
  local_88 = local_88 >> 3;
  local_8c = 0x200;
  local_14 = 4;
  local_18 = 0x200;
  local_1c = 0;
  compare_size = 3;
  expandArray(param_2,local_88,auStack_89c,0x800,local_74 + 1,1);
  memset(&local_8bc,0,0x1e);
  local_20 = (undefined4 *)malloc(0x4400);
  local_24 = (undefined4 *)malloc(0x4400);
  local_90 = (void *)0x0;
  local_28 = 0;
  local_8dc = 0;
  local_8d8 = 0;
  local_8d4 = 0;
  local_8d0 = 0;
  local_8cc = 0;
  local_8c8 = 0;
  local_8c4 = 0;
  local_8c0 = 0;
  local_2c = 0;
  do {
    if (local_8c <= local_2c) {
      for (local_34 = 0; local_34 < local_8c; local_34 = local_34 + 1) {
        uVar5 = auStack_89c[local_34];
        local_94 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                   uVar5 >> 0x18;
        uVar3 = __aeabi_idiv(local_94,local_80);
        generateHash(local_70,uVar3,&local_1760,local_84);
        __aeabi_idivmod(local_94,local_80);
        iVar2 = local_68 * extraout_r1;
        if (iVar2 < 0) {
          iVar2 = iVar2 + 7;
        }
        iVar4 = local_68;
        if (local_68 < 0) {
          iVar4 = local_68 + 7;
        }
        expandArray((int)&local_1760 + (iVar2 >> 3),iVar4 >> 3,abStack_163c,local_7c,local_74,0);
        for (local_38 = 0; local_38 < local_7c; local_38 = local_38 + 1) {
          *(byte *)((int)&local_8bc + local_38) =
               abStack_163c[local_38] ^ *(byte *)((int)&local_8bc + local_38);
        }
        memcpy((undefined4 *)((int)local_20 + local_34 * (local_7c + local_14)),abStack_163c,
               local_7c);
        memcpy((void *)((int)local_20 + local_34 * (local_7c + local_14) + local_7c),
               auStack_89c + local_34,local_14);
      }
      iVar2 = isZero(&local_8bc,0x1e);
      if (iVar2 == 0) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
          snprintf((char *)&local_1760,0x100,"error: %s xor vHash = 0\n","sortValidator");
          _applog(0,&local_1760,0);
        }
        local_1c = 2;
      }
      else {
        memset(&local_8bc,0,0x1e);
        for (local_3c = 0; local_3c < 9; local_3c = local_3c + 1) {
          qsort(local_20,local_18,local_7c + local_14,compareSR + 1);
          local_28 = 0;
          for (local_40 = 0; puVar1 = local_20, local_40 < local_18; local_40 = local_40 + 2) {
            for (local_44 = 0; local_44 < local_7c; local_44 = local_44 + 1) {
              *(byte *)((int)&local_8dc + local_44) =
                   *(byte *)((int)local_20 + (local_40 + 1) * (local_7c + local_14) + local_44) ^
                   *(byte *)((int)local_20 + local_40 * (local_7c + local_14) + local_44);
            }
            memcpy((undefined4 *)((int)local_24 + (local_40 >> 1) * (local_14 * 2 + local_7c)),
                   &local_8dc,local_7c);
            memcpy((void *)((int)local_24 + (local_40 >> 1) * (local_14 * 2 + local_7c) + local_7c),
                   (void *)((int)local_20 + local_40 * (local_7c + local_14) + local_7c),local_14);
            memcpy((void *)((int)local_24 +
                           (local_40 >> 1) * (local_14 * 2 + local_7c) + local_7c + local_14),
                   (void *)((int)local_20 + (local_40 + 1) * (local_7c + local_14) + local_7c),
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
          uVar5 = *(uint *)((int)local_20 + local_48 * 4 + local_7c);
          auStack_10dc[local_48] =
               uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
               uVar5 >> 0x18;
        }
        for (local_4c = 0; local_4c < 9; local_4c = local_4c + 1) {
          for (local_50 = 0; local_50 < 0x200; local_50 = local_50 + (2 << (local_4c & 0xff))) {
            sort_pair(auStack_10dc + local_50,1 << (local_4c & 0xff));
          }
        }
        local_14 = 4;
        local_18 = 0x200;
        for (local_54 = 0; local_54 < local_8c; local_54 = local_54 + 1) {
          local_1660 = auStack_10dc[local_54];
          uVar3 = __aeabi_idiv(local_1660,local_80);
          generateHash(local_70,uVar3,&local_1760,local_84);
          __aeabi_idivmod(local_1660,local_80);
          iVar2 = local_68 * extraout_r1_00;
          if (iVar2 < 0) {
            iVar2 = iVar2 + 7;
          }
          iVar4 = local_68;
          if (local_68 < 0) {
            iVar4 = local_68 + 7;
          }
          expandArray((int)&local_1760 + (iVar2 >> 3),iVar4 >> 3,auStack_165c,local_7c,local_74,0);
          uVar5 = auStack_10dc[local_54];
          local_1660 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                       uVar5 >> 0x18;
          memcpy((undefined4 *)((int)local_20 + local_54 * (local_7c + local_14)),auStack_165c,
                 local_7c);
          memcpy((void *)((int)local_20 + local_54 * (local_7c + local_14) + local_7c),&local_1660,
                 local_14);
          local_90 = (void *)bin2hex((undefined4 *)
                                     ((int)local_20 + local_54 * (local_7c + local_14)),0x22);
          free(local_90);
        }
        for (local_58 = 0; local_58 < 9; local_58 = local_58 + 1) {
          local_28 = 0;
          for (local_5c = 0; puVar1 = local_20, local_5c < local_18; local_5c = local_5c + 2) {
            for (local_60 = 0; local_60 < local_7c; local_60 = local_60 + 1) {
              *(byte *)((int)&local_8dc + local_60) =
                   *(byte *)((int)local_20 + (local_5c + 1) * (local_7c + local_14) + local_60) ^
                   *(byte *)((int)local_20 + local_5c * (local_7c + local_14) + local_60);
            }
            memcpy((undefined4 *)((int)local_24 + (local_5c >> 1) * (local_14 * 2 + local_7c)),
                   &local_8dc,local_7c);
            memcpy((void *)((int)local_24 + (local_5c >> 1) * (local_14 * 2 + local_7c) + local_7c),
                   (void *)((int)local_20 + local_5c * (local_7c + local_14) + local_7c),local_14);
            memcpy((void *)((int)local_24 +
                           (local_5c >> 1) * (local_14 * 2 + local_7c) + local_7c + local_14),
                   (void *)((int)local_20 + (local_5c + 1) * (local_7c + local_14) + local_7c),
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
        local_90 = (void *)bin2hex(local_20,local_7c + local_14);
        free(local_90);
        local_8bc = *local_20;
        uStack_8b8 = local_20[1];
        uStack_8b4 = local_20[2];
        uStack_8b0 = local_20[3];
        local_8ac = local_20[4];
        uStack_8a8 = local_20[5];
        uStack_8a4 = local_20[6];
        local_8a0 = *(undefined2 *)(local_20 + 7);
        iVar2 = isZero(&local_8bc,0x1e);
        if (iVar2 == 0) {
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
            snprintf((char *)&local_1760,0x100,"error: %s valid falied\n","sortValidator");
            _applog(0,&local_1760,0);
          }
          local_1c = 3;
        }
      }
LAB_0001aabe:
      free(local_20);
      free(local_24);
      return local_1c;
    }
    for (local_30 = local_2c + 1; local_30 < local_8c; local_30 = local_30 + 1) {
      if (auStack_89c[local_2c] == auStack_89c[local_30]) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
          local_1760._0_1_ = s_error__dup_index_0002c8fc[0];
          local_1760._1_1_ = s_error__dup_index_0002c8fc[1];
          local_1760._2_1_ = s_error__dup_index_0002c8fc[2];
          local_1760._3_1_ = s_error__dup_index_0002c8fc[3];
          uStack_175c._0_1_ = s_error__dup_index_0002c8fc[4];
          uStack_175c._1_1_ = s_error__dup_index_0002c8fc[5];
          uStack_175c._2_1_ = s_error__dup_index_0002c8fc[6];
          uStack_175c._3_1_ = s_error__dup_index_0002c8fc[7];
          uStack_1758._0_1_ = s_error__dup_index_0002c8fc[8];
          uStack_1758._1_1_ = s_error__dup_index_0002c8fc[9];
          uStack_1758._2_1_ = s_error__dup_index_0002c8fc[10];
          uStack_1758._3_1_ = s_error__dup_index_0002c8fc[11];
          uStack_1754._0_1_ = s_error__dup_index_0002c8fc[12];
          uStack_1754._1_1_ = s_error__dup_index_0002c8fc[13];
          uStack_1754._2_1_ = s_error__dup_index_0002c8fc[14];
          uStack_1754._3_1_ = s_error__dup_index_0002c8fc[15];
          local_1750 = (undefined2)ram0x0002c90c;
          _applog(0,&local_1760,0);
        }
        local_1c = 1;
        goto LAB_0001aabe;
      }
    }
    local_2c = local_2c + 1;
  } while( true );
}

