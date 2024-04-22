
/* WARNING: Unknown calling convention */

void check_chain(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int i;
  int iVar7;
  bool bVar8;
  
  piVar1 = DAT_0002ea7c;
  *(undefined *)(*DAT_0002ea7c + 0x2fbc) = 0;
  iVar2 = get_hash_on_plug();
  if (iVar2 < 0) {
    if ((*DAT_0002ea80 != '\0') &&
       (((*DAT_0002ea84 != '\0' || (*DAT_0002ea88 != '\0')) || (6 < *DAT_0002ea8c)))) {
      check_chain();
      return;
    }
  }
  else {
    iVar3 = *piVar1;
    uVar6 = 0;
    iVar4 = iVar3;
    iVar7 = iVar3;
    do {
      uVar5 = uVar6 & 0xff;
      uVar6 = uVar6 + 1;
      uVar5 = iVar2 >> uVar5 & 1;
      bVar8 = uVar5 == 0;
      if (!bVar8) {
        *(undefined4 *)(iVar4 + 8) = 1;
      }
      iVar4 = iVar4 + 4;
      if (!bVar8) {
        uVar5 = (uint)*(byte *)(iVar3 + 0x2fbc);
      }
      if (bVar8) {
        *(uint *)(iVar7 + 8) = uVar5;
      }
      iVar7 = iVar7 + 4;
      if (!bVar8) {
        *(char *)(iVar3 + 0x2fbc) = (char)uVar5 + '\x01';
      }
    } while (uVar6 != 0x10);
  }
  return;
}

