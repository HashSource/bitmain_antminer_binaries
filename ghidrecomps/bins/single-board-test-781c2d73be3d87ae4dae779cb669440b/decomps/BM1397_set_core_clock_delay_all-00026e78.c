
/* WARNING: Unknown calling convention */

void BM1397_set_core_clock_delay_all(uchar which_chain,uchar which_asic,uchar reg_data,uchar mode)

{
  if (mode != '\0') {
    mode = true;
  }
  BM1397_set_config(which_chain,which_asic,'\0',reg_data | 0x80008000,(_Bool)mode);
  (*(code *)PTR_usleep_00030148)(5000);
  return;
}

