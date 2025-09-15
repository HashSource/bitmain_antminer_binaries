
_Bool sweep_freq_all_chip_failed(int chain,int column)

{
  int iVar1;
  int column_local;
  int chain_local;
  int chip;
  int row;
  
  row = 0;
  while( true ) {
    if (5 < row) {
      return true;
    }
    iVar1 = get_physical_chip_no(row,column);
    if (scanfreq_info.chip_sweep_failed[chain][iVar1] != true) break;
    row = row + 1;
  }
  return false;
}

