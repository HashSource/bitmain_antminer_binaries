
void power_off_all_chain(void)

{
  int local_c;
  
  for (local_c = 0; local_c < total_exist_chain_num; local_c = local_c + 1) {
    disable_pic_dac(*(uint *)(exist_chain + local_c * 4) & 0xff);
  }
  return;
}

