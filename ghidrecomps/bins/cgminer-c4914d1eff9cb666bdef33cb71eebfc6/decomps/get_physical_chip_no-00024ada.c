
int get_physical_chip_no(int logical_row,int logical_col)

{
  int iVar1;
  int logical_col_local;
  int logical_row_local;
  
  if (logical_row < 6) {
    if ((logical_row & 1U) == 0) {
      iVar1 = logical_col + logical_row * 10;
    }
    else {
      iVar1 = ((logical_row + 1) * 10 + -1) - logical_col;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

