
void get_sweep_bad_asics(sweep_bad_asic_info_t *bad_asics)

{
  sweep_bad_asic_info_t *bad_asics_local;
  
  if (bad_asics != (sweep_bad_asic_info_t *)0x0) {
    memcpy(bad_asics,&g_sweep_bad_asics,0x34);
  }
  return;
}

