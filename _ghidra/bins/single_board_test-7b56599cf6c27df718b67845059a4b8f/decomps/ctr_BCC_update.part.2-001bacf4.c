
undefined4 ctr_BCC_update_part_2(uint param_1,uint *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  int local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  iVar1 = *(int *)(param_1 + 0x58);
  if ((iVar1 != 0) && (uVar7 = 0x10 - iVar1, uVar7 <= param_3)) {
    memcpy((void *)(iVar1 + param_1 + 0x48),param_2,uVar7);
    local_50 = *(uint *)(param_1 + 0x50);
    local_4c = *(uint *)(param_1 + 0x54);
    local_58 = *(uint *)(param_1 + 0x48);
    bVar9 = *(int *)(param_1 + 0x14) != 0x10;
    local_54 = *(uint *)(param_1 + 0x4c);
    if (bVar9) {
      iVar1 = 0x30;
    }
    else {
      iVar1 = 0x20;
    }
    local_48 = local_58;
    local_44 = local_54;
    local_40 = local_50;
    local_3c = local_4c;
    if (bVar9) {
      local_38 = local_58;
      local_34 = local_54;
      local_30 = local_50;
      local_2c = local_4c;
    }
    pbVar6 = (byte *)(param_1 + 0x5c);
    local_5c = 0x10;
    if ((param_1 & 3) == 0) {
      uVar8 = iVar1 - 4U >> 2;
      *(uint *)(param_1 + 0x5c) = local_58 ^ *(uint *)(param_1 + 0x5c);
      *(uint *)(param_1 + 0x60) = local_54 ^ *(uint *)(param_1 + 0x60);
      *(uint *)(param_1 + 100) = local_50 ^ *(uint *)(param_1 + 100);
      *(uint *)(param_1 + 0x68) = local_4c ^ *(uint *)(param_1 + 0x68);
      *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) ^ local_58;
      *(uint *)(param_1 + 0x70) = local_54 ^ *(uint *)(param_1 + 0x70);
      *(uint *)(param_1 + 0x74) = local_50 ^ *(uint *)(param_1 + 0x74);
      *(uint *)(param_1 + 0x78) = local_4c ^ *(uint *)(param_1 + 0x78);
      if ((((uVar8 != 7) &&
           (*(uint *)(param_1 + 0x7c) = local_38 ^ *(uint *)(param_1 + 0x7c), uVar8 != 8)) &&
          (*(uint *)(param_1 + 0x80) = local_34 ^ *(uint *)(param_1 + 0x80), uVar8 != 9)) &&
         (*(uint *)(param_1 + 0x84) = local_30 ^ *(uint *)(param_1 + 0x84), uVar8 == 0xb)) {
        *(uint *)(param_1 + 0x88) = local_2c ^ *(uint *)(param_1 + 0x88);
      }
    }
    else {
      pbVar4 = pbVar6;
      puVar3 = &local_58;
      do {
        pbVar5 = pbVar4 + 1;
        *pbVar4 = *pbVar4 ^ (byte)*puVar3;
        pbVar4 = pbVar5;
        puVar3 = (uint *)((int)puVar3 + 1);
      } while (pbVar5 != pbVar6 + iVar1);
    }
    iVar2 = EVP_CipherUpdate(*(EVP_CIPHER_CTX **)(param_1 + 8),pbVar6,&local_5c,pbVar6,iVar1);
    if ((iVar2 == 0) || (local_5c != iVar1)) {
      return 0;
    }
    param_3 = param_3 - uVar7;
    param_2 = (uint *)((int)param_2 + uVar7);
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  if (0xf < param_3) {
    pbVar6 = (byte *)(param_1 + 0x5c);
    do {
      local_4c = param_2[3];
      local_58 = *param_2;
      local_54 = param_2[1];
      bVar9 = *(int *)(param_1 + 0x14) != 0x10;
      local_50 = param_2[2];
      if (bVar9) {
        iVar1 = 0x30;
      }
      else {
        iVar1 = 0x20;
      }
      local_48 = local_58;
      local_44 = local_54;
      local_40 = local_50;
      local_3c = local_4c;
      if (bVar9) {
        local_38 = local_58;
        local_34 = local_54;
        local_30 = local_50;
        local_2c = local_4c;
      }
      local_5c = 0x10;
      if ((param_1 & 3) == 0) {
        uVar7 = iVar1 - 4U >> 2;
        *(uint *)(param_1 + 0x5c) = local_58 ^ *(uint *)(param_1 + 0x5c);
        *(uint *)(param_1 + 0x60) = local_54 ^ *(uint *)(param_1 + 0x60);
        *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) ^ local_50;
        *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) ^ local_4c;
        *(uint *)(param_1 + 0x70) = local_54 ^ *(uint *)(param_1 + 0x70);
        *(uint *)(param_1 + 0x6c) = local_58 ^ *(uint *)(param_1 + 0x6c);
        *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) ^ local_50;
        *(uint *)(param_1 + 0x78) = local_4c ^ *(uint *)(param_1 + 0x78);
        if (((uVar7 != 7) &&
            (*(uint *)(param_1 + 0x7c) = local_38 ^ *(uint *)(param_1 + 0x7c), uVar7 != 8)) &&
           ((*(uint *)(param_1 + 0x80) = local_34 ^ *(uint *)(param_1 + 0x80), uVar7 != 9 &&
            (*(uint *)(param_1 + 0x84) = local_30 ^ *(uint *)(param_1 + 0x84), uVar7 == 0xb)))) {
          *(uint *)(param_1 + 0x88) = local_2c ^ *(uint *)(param_1 + 0x88);
        }
      }
      else {
        puVar3 = &local_58;
        pbVar4 = pbVar6;
        do {
          pbVar5 = pbVar4 + 1;
          *pbVar4 = *pbVar4 ^ (byte)*puVar3;
          puVar3 = (uint *)((int)puVar3 + 1);
          pbVar4 = pbVar5;
        } while (pbVar5 != pbVar6 + iVar1);
      }
      iVar2 = EVP_CipherUpdate(*(EVP_CIPHER_CTX **)(param_1 + 8),pbVar6,&local_5c,pbVar6,iVar1);
      if (iVar2 == 0) {
        return 0;
      }
      if (local_5c != iVar1) {
        return 0;
      }
      param_3 = param_3 - 0x10;
      param_2 = param_2 + 4;
    } while (0xf < param_3);
  }
  if (param_3 != 0) {
    memcpy((void *)(param_1 + 0x48 + *(int *)(param_1 + 0x58)),param_2,param_3);
    *(uint *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + param_3;
    return 1;
  }
  return 1;
}

