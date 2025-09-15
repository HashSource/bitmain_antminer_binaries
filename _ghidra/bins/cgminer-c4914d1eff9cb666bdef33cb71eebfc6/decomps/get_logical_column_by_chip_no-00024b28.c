
int get_logical_column_by_chip_no(int chip)

{
  int iVar1;
  int chip_local;
  int logical_row;
  
  iVar1 = chip / 10;
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      chip = 0x13 - chip;
    }
    else if (iVar1 == 2) {
      chip = chip + -0x14;
    }
    else if (iVar1 == 3) {
      chip = 0x27 - chip;
    }
    else if (iVar1 == 4) {
      chip = chip + -0x28;
    }
    else if (iVar1 == 5) {
      chip = 0x3b - chip;
    }
    else {
      chip = 0;
    }
  }
  return chip;
}

