
int get_logical_column_by_chip_no(int chip)

{
  uint uVar1;
  int iVar2;
  int chip_local;
  int logical_row;
  
  iVar2 = chip + 3;
  if (-1 < chip) {
    iVar2 = chip;
  }
  uVar1 = iVar2 >> 2;
  if ((int)uVar1 < 0xc) {
    if ((uVar1 & 1) == 0) {
      iVar2 = chip + uVar1 * -4;
    }
    else {
      iVar2 = ((uVar1 + 1) * 4 + -1) - chip;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}

