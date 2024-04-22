
/* WARNING: Unknown calling convention */

void BM1397_enable_core_clock(uchar which_chain,uchar which_asic,uint core_id,uchar mode)

{
  if (mode != '\0') {
    mode = true;
  }
  BM1397_set_config(which_chain,which_asic,'<',core_id << 0x10 | 0x84aa,(_Bool)mode);
  (*(code *)PTR_usleep_00030148)(5000);
  return;
}

