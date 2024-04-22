
/* WARNING: Unknown calling convention */

int get_pre_header_hash(uint *buf)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  char tmp42 [2048];
  
  iVar5 = *(int *)(DAT_0002e330 + 0x8d4);
  cVar1 = *DAT_0002e334;
  uVar10 = *(uint *)(iVar5 + 0x140);
  *buf = uVar10;
  uVar2 = *(uint *)(iVar5 + 0x144);
  buf[1] = uVar2;
  uVar3 = *(uint *)(iVar5 + 0x148);
  buf[2] = uVar3;
  uVar9 = *(uint *)(iVar5 + 0x14c);
  buf[3] = uVar9;
  uVar8 = *(uint *)(iVar5 + 0x150);
  buf[4] = uVar8;
  uVar7 = *(uint *)(iVar5 + 0x154);
  buf[5] = uVar7;
  uVar4 = *(uint *)(iVar5 + 0x158);
  buf[6] = uVar4;
  uVar6 = *(uint *)(iVar5 + 0x15c);
  buf[7] = uVar6;
  if ((cVar1 != '\0') &&
     (((*DAT_0002e340 != '\0' || (*DAT_0002e344 != '\0')) || (6 < *DAT_0002e348)))) {
    snprintf(tmp42,0x800,DAT_0002e338,DAT_0002e33c,uVar10,uVar2,uVar3,uVar9,uVar8,uVar7,uVar4,uVar6)
    ;
    _applog(7,tmp42,false);
    uVar6 = buf[7];
  }
  return uVar6;
}

