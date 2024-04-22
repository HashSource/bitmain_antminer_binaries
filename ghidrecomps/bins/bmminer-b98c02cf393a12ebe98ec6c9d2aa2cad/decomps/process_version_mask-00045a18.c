
void process_version_mask(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_2 == (char *)0x0) {
    *(undefined *)(param_1 + 0x284) = 0;
    *(undefined4 *)(param_1 + 0x288) = 1;
    return;
  }
  uVar2 = strtol(param_2,(char **)0x0,0x10);
  bVar1 = false;
  uVar6 = 0;
  uVar5 = 0;
  do {
    uVar4 = ((uVar2 >> 0x10 & 0xc0) << 8) >> (uVar5 & 0xff);
    uVar3 = 1 << (uVar5 & 0xff);
    uVar5 = uVar5 + 1;
    if ((uVar4 & 1) != 0) {
      uVar6 = uVar6 | uVar3;
      if (bVar1) break;
      bVar1 = true;
    }
  } while (uVar5 != 0x20);
  *(uint *)(param_1 + 0x28c) = uVar6;
  if ((uVar6 & 0xc000) == 0) {
    process_version_mask_part_6(param_1,uVar3,uVar4,param_4);
    return;
  }
  *(undefined *)(param_1 + 0x284) = 1;
  *(undefined4 *)(param_1 + 0x288) = 4;
  return;
}

