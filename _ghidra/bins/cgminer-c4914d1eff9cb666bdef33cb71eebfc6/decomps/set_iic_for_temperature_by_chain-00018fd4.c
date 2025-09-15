
void set_iic_for_temperature_by_chain(int chain)

{
  int chain_local;
  int j;
  
  for (j = 0; j < dev->chain_asic_temp_num[chain]; j = j + 1) {
    set_misc_control((uchar)chain,'\0',dev->TempChipAddr[chain][j],1);
  }
  return;
}

