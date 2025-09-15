
void update_middle_offset(int chain,int temp_id)

{
  int temp_id_local;
  int chain_local;
  
  check_reg_temp('\x11','\x01','\x01',dev->TempChipAddr[chain][temp_id],chain);
  return;
}

