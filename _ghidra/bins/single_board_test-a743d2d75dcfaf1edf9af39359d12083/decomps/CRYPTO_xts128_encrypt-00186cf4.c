
undefined4
CRYPTO_xts128_encrypt
          (undefined4 *param_1,uint *param_2,uint *param_3,uint *param_4,uint param_5,int param_6)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint *puVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  uint local_68;
  uint uStack_64;
  uint local_5c;
  uint *local_4c;
  uint local_48;
  uint uStack_44;
  uint local_40;
  uint local_3c;
  uint local_38 [5];
  
  if (param_5 < 0x10) {
    return 0xffffffff;
  }
  local_48 = *param_2;
  local_40 = param_2[2];
  uStack_44 = param_2[1];
  local_3c = param_2[3];
  (*(code *)param_1[3])(&local_48,&local_48,param_1[1]);
  if (((param_6 != 0) || ((param_5 & 0xf) == 0)) ||
     (param_5 = param_5 - 0x10, local_4c = param_4, 0xf < param_5)) {
    puVar5 = param_3 + 4;
    puVar9 = param_4 + 4;
    do {
      local_4c = puVar9;
      param_3 = puVar5;
      HintPreloadData(param_3 + 8);
      local_38[1] = param_3[-3] ^ uStack_44;
      local_38[0] = param_3[-4] ^ local_48;
      local_38[3] = param_3[-1] ^ local_3c;
      local_38[2] = param_3[-2] ^ local_40;
      (*(code *)param_1[2])(local_38,local_38,*param_1);
      local_38[0] = local_48 ^ local_38[0];
      local_38[1] = uStack_44 ^ local_38[1];
      local_38[2] = local_38[2] ^ local_40;
      local_38[3] = local_38[3] ^ local_3c;
      param_5 = param_5 - 0x10;
      local_4c[-4] = local_38[0];
      local_4c[-3] = local_38[1];
      local_4c[-2] = local_38[2];
      local_4c[-1] = local_38[3];
      if (param_5 == 0) {
        return 0;
      }
      uVar3 = uStack_44 * 2 + (uint)CARRY4(local_48,local_48);
      uVar2 = (int)local_3c >> 0x1f;
      local_3c = local_3c * 2 + (uint)CARRY4(local_40,local_40);
      local_40 = local_40 * 2 | uStack_44 >> 0x1f;
      local_48 = local_48 * 2 ^ uVar2 & 0x87;
      puVar5 = param_3 + 4;
      puVar9 = local_4c + 4;
      uStack_44 = uVar3;
    } while (0xf < param_5);
    if (param_6 != 0) {
      puVar5 = param_3 + 1;
      puVar9 = local_4c + 1;
      bVar12 = local_4c <= puVar5;
      bVar11 = puVar5 == local_4c;
      if (bVar12 && !bVar11) {
        bVar12 = param_3 <= puVar9;
        bVar11 = puVar9 == param_3;
      }
      uVar10 = param_5 >> 2;
      uVar2 = uVar10 * 4;
      if (uVar10 == 0 ||
          ((((uint)local_4c | (uint)param_3) & 3) != 0 ||
          ((param_5 < 4 || (bVar12 && !bVar11 || local_38 < puVar5 && param_3 < local_38 + 1)) ||
          local_38 < puVar9 && local_4c < local_38 + 1))) {
        uVar2 = 0;
      }
      else {
        uVar4 = 0;
        iVar6 = 0;
        do {
          uVar8 = *(undefined4 *)((int)param_3 + iVar6);
          uVar4 = uVar4 + 1;
          *(undefined4 *)((int)local_4c + iVar6) = *(undefined4 *)((int)local_38 + iVar6);
          *(undefined4 *)((int)local_38 + iVar6) = uVar8;
          iVar6 = iVar6 + 4;
        } while (uVar4 < uVar10);
        if (uVar2 - param_5 == 0) goto LAB_001870fa;
      }
      do {
        uVar1 = *(undefined1 *)((int)param_3 + uVar2);
        *(undefined1 *)((int)local_4c + uVar2) = *(undefined1 *)((int)local_38 + uVar2);
        *(undefined1 *)((int)local_38 + uVar2) = uVar1;
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_5);
LAB_001870fa:
      local_38[0] = local_48 ^ local_38[0];
      local_38[1] = uVar3 ^ local_38[1];
      local_38[3] = local_38[3] ^ local_3c;
      local_38[2] = local_38[2] ^ local_40;
      (*(code *)param_1[2])(local_38,local_38,*param_1);
      local_4c[-4] = local_38[0] ^ local_48;
      local_4c[-3] = local_38[1] ^ uStack_44;
      local_4c[-2] = local_38[2] ^ local_40;
      local_4c[-1] = local_38[3] ^ local_3c;
      return 0;
    }
  }
  uStack_64 = local_3c * 2 + (uint)CARRY4(local_40,local_40);
  uVar3 = uStack_44 * 2 + (uint)CARRY4(local_48,local_48);
  local_5c = 0;
  uVar2 = local_48 * 2 ^ (int)local_3c >> 0x1f & 0x87U;
  local_38[0] = *param_3 ^ uVar2;
  local_38[1] = param_3[1] ^ uVar3;
  local_68 = local_40 * 2 | uStack_44 >> 0x1f;
  local_38[2] = param_3[2] ^ local_68;
  local_38[3] = param_3[3] ^ uStack_64;
  (*(code *)param_1[2])(local_38,local_38,*param_1);
  local_38[0] = uVar2 ^ local_38[0];
  local_38[1] = uVar3 ^ local_38[1];
  local_68 = local_68 ^ local_38[2];
  uStack_64 = uStack_64 ^ local_38[3];
  local_38[2] = local_68;
  local_38[3] = uStack_64;
  if (param_5 == 0) goto LAB_00186fce;
  puVar7 = param_3 + 4;
  puVar5 = local_38 + 1;
  puVar9 = local_4c + 4;
  uVar3 = param_5 >> 2;
  if (uVar3 == 0 ||
      ((((uint)puVar7 | (uint)puVar9) & 3) != 0 ||
      ((param_5 < 4 ||
       (puVar9 < param_3 + 5 && puVar7 < local_4c + 5 || local_38 < param_3 + 5 && puVar7 < puVar5))
      || local_38 < local_4c + 5 && puVar9 < puVar5))) {
LAB_00186fac:
    do {
      uVar1 = *(undefined1 *)((int)param_3 + local_5c + 0x10);
      *(undefined1 *)((int)local_4c + local_5c + 0x10) = *(undefined1 *)((int)local_38 + local_5c);
      *(undefined1 *)((int)local_38 + local_5c) = uVar1;
      local_5c = local_5c + 1;
    } while (local_5c < param_5);
  }
  else {
    puVar9 = param_3 + 3;
    puVar7 = local_4c + 3;
    uVar2 = 0;
    do {
      uVar2 = uVar2 + 1;
      puVar9 = puVar9 + 1;
      uVar10 = *puVar9;
      puVar7 = puVar7 + 1;
      *puVar7 = puVar5[-1];
      puVar5[-1] = uVar10;
      puVar5 = puVar5 + 1;
    } while (uVar2 < uVar3);
    local_5c = uVar3 * 4;
    if (uVar3 * 4 != param_5) goto LAB_00186fac;
  }
  local_68 = local_38[2];
  uStack_64 = local_38[3];
LAB_00186fce:
  local_38[1] = local_38[1] ^ uStack_44;
  local_38[0] = local_38[0] ^ local_48;
  local_38[2] = local_68 ^ local_40;
  local_38[3] = uStack_64 ^ local_3c;
  (*(code *)param_1[2])(local_38,local_38,*param_1);
  *local_4c = local_48 ^ local_38[0];
  local_4c[1] = uStack_44 ^ local_38[1];
  local_4c[2] = local_38[2] ^ local_40;
  local_4c[3] = local_38[3] ^ local_3c;
  return 0;
}

