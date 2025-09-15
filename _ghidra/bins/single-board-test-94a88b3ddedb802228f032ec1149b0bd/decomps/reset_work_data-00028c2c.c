
undefined4 reset_work_data(void)

{
  int iVar1;
  int local_10;
  int local_c;
  
  iVar1 = calculate_asic_number(0x54);
  for (local_c = 0; local_c < iVar1; local_c = local_c + 1) {
    for (local_10 = 0; local_10 < (int)conf._0_4_; local_10 = local_10 + 1) {
      *(undefined4 *)(cgpu + (local_10 + local_c * 5000 + 0x128) * 4) = 0;
    }
    *(undefined4 *)(cgpu + (local_c + 0x9c528) * 4) = 0;
  }
  cgpu._2562212_4_ = 0;
  cgpu._2562216_4_ = 0;
  cgpu._2562220_4_ = 0;
  cgpu._2562224_4_ = 0;
  return 0;
}

