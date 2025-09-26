
void add_bad_asic_ids(int id)

{
  int id_local;
  
  if (g_sweep_bad_asics.bad_asic_num < 0xc) {
    g_sweep_bad_asics.bad_asic_ids[g_sweep_bad_asics.bad_asic_num] = id;
    g_sweep_bad_asics.bad_asic_num = g_sweep_bad_asics.bad_asic_num + 1;
  }
  return;
}

