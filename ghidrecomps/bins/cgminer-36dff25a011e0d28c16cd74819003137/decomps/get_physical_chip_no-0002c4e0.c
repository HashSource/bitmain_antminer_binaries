
int get_physical_chip_no(int logical_row,int logical_col)

{
  int iVar1;
  int logical_col_local;
  int logical_row_local;
  
  if (logical_row < 0xc) {
    if ((logical_row & 1U) == 0) {
      iVar1 = logical_row * 4 + logical_col;
    }
    else {
      iVar1 = ((logical_row + 1) * 4 + -1) - logical_col;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

