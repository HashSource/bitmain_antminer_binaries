
/* WARNING: Type propagation algorithm not settling */

int X509_cmp_time(ASN1_TIME *s,time_t *t)

{
  byte bVar1;
  uint uVar2;
  ASN1_TIME *pAVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  long offset_sec;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  byte *pbVar11;
  time_t local_64;
  ASN1_TIME local_60;
  uint local_50;
  uint uStack_4c;
  undefined4 local_48;
  byte local_44 [12];
  byte local_38;
  byte local_37;
  
  iVar6 = s->length;
  local_60.type = s->type;
  puVar7 = (uint *)s->data;
  if (local_60.type == 0x17) {
    if (6 < iVar6 - 0xbU) {
      return 0;
    }
    local_50 = *puVar7;
    uStack_4c = puVar7[1];
    puVar10 = (uint *)((int)puVar7 + 10);
    iVar4 = -10;
    pbVar11 = (byte *)((int)&local_48 + 2);
    local_48 = CONCAT22(local_48._2_2_,*(undefined2 *)(puVar7 + 2));
  }
  else {
    if (10 < iVar6 - 0xdU) {
      return 0;
    }
    local_50 = *puVar7;
    iVar4 = -0xc;
    uStack_4c = puVar7[1];
    local_48 = puVar7[2];
    pbVar11 = local_44;
    puVar10 = puVar7 + 3;
  }
  iVar6 = iVar6 + iVar4;
  bVar1 = *(byte *)puVar10;
  if ((bVar1 == 0x5a || bVar1 == 0x2d) || (iVar4 = 0, bVar1 == 0x2b)) {
    *pbVar11 = 0x30;
    pbVar11[1] = 0x30;
    puVar7 = puVar10;
LAB_000c0db4:
    pbVar11[2] = 0x5a;
    pbVar11[3] = 0;
  }
  else {
    if (iVar6 == 1) {
      return 0;
    }
    *pbVar11 = bVar1;
    pbVar11[1] = *(byte *)((int)puVar10 + 1);
    if (iVar6 + -2 == 0) {
      return 0;
    }
    if (*(byte *)((int)puVar10 + 2) != 0x2e) {
      puVar7 = (uint *)((int)puVar10 + 2);
      iVar6 = iVar6 + -2;
      goto LAB_000c0db4;
    }
    iVar6 = iVar6 + -3;
    puVar7 = (uint *)((int)puVar10 + 3);
    if (iVar6 == 0) {
      return 0;
    }
    if (*(byte *)((int)puVar10 + 3) - 0x30 < 10) {
      puVar10 = puVar10 + 1;
      do {
        puVar7 = puVar10;
        iVar6 = iVar6 + -1;
        iVar4 = iVar4 + 1;
        if (2 < iVar4 || iVar6 == 0) break;
        puVar10 = (uint *)((int)puVar7 + 1);
      } while (*(byte *)puVar7 - 0x30 < 10);
      pbVar11[2] = 0x5a;
      pbVar11[3] = 0;
      if (iVar6 == 0) {
        return 0;
      }
    }
    else {
      pbVar11[3] = 0;
      pbVar11[2] = 0x5a;
    }
  }
  bVar1 = *(byte *)puVar7;
  if (bVar1 == 0x5a) {
    if (iVar6 != 1) {
      return 0;
    }
    offset_sec = 0;
  }
  else {
    if (bVar1 != 0x2d && bVar1 != 0x2b) {
      return 0;
    }
    if (iVar6 != 5) {
      return 0;
    }
    if (9 < *(byte *)((int)puVar7 + 1) - 0x30) {
      return 0;
    }
    uVar5 = (uint)*(byte *)((int)puVar7 + 2);
    if (uVar5 < 0x30) {
      return 0;
    }
    if (0x39 < uVar5) {
      return 0;
    }
    uVar2 = (uint)*(byte *)((int)puVar7 + 3);
    if (uVar2 < 0x30) {
      return 0;
    }
    if (0x39 < uVar2) {
      return 0;
    }
    uVar9 = (uint)*(byte *)(puVar7 + 1);
    if (uVar9 < 0x30) {
      return 0;
    }
    if (0x39 < uVar9) {
      return 0;
    }
    if (bVar1 == 0x2d) {
      iVar6 = -0x3c;
    }
    else {
      iVar6 = 0x3c;
    }
    offset_sec = ((uint)*(byte *)((int)puVar7 + 1) * 600 + uVar5 * 0x3c + uVar9 + uVar2 * 10 +
                 -0x7dd0) * iVar6;
  }
  local_60.flags = 0;
  local_60.length = 0x18;
  local_60.data = &local_38;
  if (t == (time_t *)0x0) {
    time(&local_64);
    if ((local_60.flags & 0x40U) == 0) goto LAB_000c0e40;
  }
  else {
    local_64 = *t;
LAB_000c0e40:
    if (local_60.type == 0x17) {
      pAVar3 = ASN1_UTCTIME_adj(&local_60,local_64,0,offset_sec);
      goto LAB_000c0e52;
    }
    if (local_60.type == 0x18) {
      pAVar3 = ASN1_GENERALIZEDTIME_adj(&local_60,local_64,0,offset_sec);
      goto LAB_000c0e52;
    }
  }
  pAVar3 = ASN1_TIME_adj(&local_60,local_64,0,offset_sec);
LAB_000c0e52:
  if (pAVar3 == (ASN1_TIME *)0x0) {
    return 0;
  }
  if (s->type == 0x17) {
    iVar6 = (local_50 >> 8 & 0xff) + (local_50 & 0xff) * 10;
    iVar4 = iVar6 + -0x210;
    if (iVar4 < 0x32) {
      iVar4 = iVar6 + -0x1ac;
    }
    iVar6 = (uint)local_37 + (uint)local_38 * 10;
    iVar8 = iVar6 + -0x210;
    if (iVar8 < 0x32) {
      iVar8 = iVar6 + -0x1ac;
    }
    if (iVar4 < iVar8) {
      return -1;
    }
    if (iVar8 < iVar4) {
      return 1;
    }
  }
  iVar6 = strcmp((char *)&local_50,(char *)&local_38);
  if (iVar6 == 0) {
    return -1;
  }
  return iVar6;
}

