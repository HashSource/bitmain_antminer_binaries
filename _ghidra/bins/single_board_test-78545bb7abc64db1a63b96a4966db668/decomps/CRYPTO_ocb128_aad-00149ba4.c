
undefined4 CRYPTO_ocb128_aad(undefined4 *param_1,void *param_2,uint param_3)

{
  uint *puVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  uint local_58;
  uint uStack_54;
  void *local_4c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  uVar3 = param_1[0x12];
  uVar7 = uVar3 + (param_3 >> 4);
  uVar10 = param_1[0x13] + (uint)CARRY4(uVar3,param_3 >> 4);
  local_58 = uVar3 + 1;
  uStack_54 = param_1[0x13] + (uint)(0xfffffffe < uVar3);
  bVar14 = uStack_54 <= uVar10;
  if (uVar10 == uStack_54) {
    bVar14 = local_58 <= uVar7;
  }
  local_4c = param_2;
  if (bVar14) {
    pvVar2 = (void *)((int)param_2 + 0x10);
    do {
      local_4c = pvVar2;
      if ((local_58 & 1) == 0) {
        iVar8 = 0;
        uVar3 = local_58;
        uVar4 = uStack_54;
        do {
          uVar5 = uVar4 & 1;
          uVar4 = uVar4 >> 1;
          uVar6 = uVar3 >> 1;
          uVar3 = (uint)(uVar5 != 0) << 0x1f | uVar6;
          iVar8 = iVar8 + 1;
        } while ((uVar6 & 1) == 0);
      }
      else {
        iVar8 = 0;
      }
      puVar1 = (uint *)ocb_lookup_l(param_1,iVar8);
      if (puVar1 == (uint *)0x0) {
        return 0;
      }
      uVar3 = *puVar1;
      uVar5 = puVar1[1];
      uVar9 = param_1[0x16];
      uVar11 = param_1[0x17];
      bVar14 = 0xfffffffe < local_58;
      local_58 = local_58 + 1;
      HintPreloadData((int)local_4c + 0x20);
      uStack_54 = uStack_54 + bVar14;
      uVar12 = param_1[0x18];
      uVar13 = param_1[0x19];
      param_1[0x16] = uVar9 ^ uVar3;
      param_1[0x17] = uVar11 ^ uVar5;
      uVar4 = puVar1[2];
      uVar6 = puVar1[3];
      param_1[0x18] = uVar12 ^ uVar4;
      param_1[0x19] = uVar13 ^ uVar6;
      local_38 = uVar9 ^ uVar3 ^ *(uint *)((int)local_4c + -0x10);
      local_34 = uVar11 ^ uVar5 ^ *(uint *)((int)local_4c + -0xc);
      local_30 = *(uint *)((int)local_4c + -8) ^ uVar12 ^ uVar4;
      local_2c = *(uint *)((int)local_4c + -4) ^ uVar13 ^ uVar6;
      (*(code *)*param_1)(&local_38,&local_38,param_1[2]);
      param_1[0x1a] = param_1[0x1a] ^ local_38;
      param_1[0x1b] = param_1[0x1b] ^ local_34;
      param_1[0x1c] = param_1[0x1c] ^ local_30;
      param_1[0x1d] = param_1[0x1d] ^ local_2c;
      bVar14 = uStack_54 <= uVar10;
      if (uVar10 == uStack_54) {
        bVar14 = local_58 <= uVar7;
      }
      pvVar2 = (void *)((int)local_4c + 0x10);
    } while (bVar14);
  }
  param_3 = param_3 & 0xf;
  if (param_3 != 0) {
    uVar3 = param_1[0x16];
    uVar5 = param_1[0x17];
    uVar9 = param_1[8];
    uVar12 = param_1[9];
    local_34 = 0;
    uVar11 = param_1[0x18];
    uVar13 = param_1[0x19];
    param_1[0x16] = uVar3 ^ uVar9;
    param_1[0x17] = uVar5 ^ uVar12;
    uVar4 = param_1[10];
    uVar6 = param_1[0xb];
    local_38 = 0;
    local_30 = 0;
    param_1[0x18] = uVar11 ^ uVar4;
    param_1[0x19] = uVar13 ^ uVar6;
    local_2c = 0;
    pvVar2 = memcpy(&local_38,local_4c,param_3);
    *(undefined1 *)((int)&local_38 + param_3) = 0x80;
    local_38 = uVar3 ^ uVar9 ^ local_38;
    local_34 = uVar5 ^ uVar12 ^ local_34;
    local_30 = uVar11 ^ uVar4 ^ local_30;
    local_2c = uVar13 ^ uVar6 ^ local_2c;
    (*(code *)*param_1)(pvVar2,pvVar2,param_1[2]);
    param_1[0x1a] = param_1[0x1a] ^ local_38;
    param_1[0x1b] = param_1[0x1b] ^ local_34;
    param_1[0x1c] = param_1[0x1c] ^ local_30;
    param_1[0x1d] = param_1[0x1d] ^ local_2c;
  }
  param_1[0x12] = uVar7;
  param_1[0x13] = uVar10;
  return 1;
}

