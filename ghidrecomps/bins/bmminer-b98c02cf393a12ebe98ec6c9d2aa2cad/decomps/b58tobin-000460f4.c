
void b58tobin(undefined *param_1,byte *param_2)

{
  longlong lVar1;
  size_t sVar2;
  byte *pbVar3;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint local_34;
  uint local_30;
  uint local_2c [5];
  byte *pbVar4;
  
  uVar8 = 0;
  local_30 = 0;
  local_34 = 0;
  local_2c[0] = 0;
  local_2c[1] = 0;
  local_2c[2] = 0;
  local_2c[3] = 0;
  local_2c[4] = 0;
  sVar2 = strlen((char *)param_2);
  uVar6 = uVar8;
  if (0 < (int)sVar2) {
    pbVar4 = param_2;
    do {
      pbVar3 = pbVar4 + 1;
      puVar5 = local_2c + 4;
      uVar6 = *(uint *)(b58tobin_tbl + (uint)*pbVar4 * 4);
      while( true ) {
        lVar1 = (ulonglong)uVar8 * 0x3a + (ulonglong)uVar6;
        uVar6 = (uint)((ulonglong)lVar1 >> 0x20) & 0x3f;
        *puVar5 = (uint)lVar1;
        if (&local_34 == puVar5) break;
        puVar5 = puVar5 + -1;
        uVar8 = *puVar5;
      }
      pbVar4 = pbVar3;
      uVar8 = local_2c[4];
    } while (param_2 + sVar2 != pbVar3);
    uVar8 = local_34 & 0xff;
    uVar6 = local_30 << 0x18 | (local_30 >> 8 & 0xff) << 0x10 | (local_30 >> 0x10 & 0xff) << 8 |
            local_30 >> 0x18;
  }
  puVar5 = &local_30;
  *param_1 = (char)uVar8;
  puVar7 = (uint *)(param_1 + 1);
  while( true ) {
    *puVar7 = uVar6;
    if (puVar7 + 1 == (uint *)(param_1 + 0x19)) break;
    puVar5 = puVar5 + 1;
    uVar6 = *puVar5;
    uVar6 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
            uVar6 >> 0x18;
    puVar7 = puVar7 + 1;
  }
  return;
}

