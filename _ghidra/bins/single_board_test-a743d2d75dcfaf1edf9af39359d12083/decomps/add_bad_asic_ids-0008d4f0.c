
void add_bad_asic_ids(int id)

{
  int id_local;
  char tmp42 [256];
  int i;
  
  i = 0;
  while( true ) {
    if (g_sweep_bad_asics.bad_asic_num <= i) {
      g_sweep_bad_asics.bad_asic_ids[g_sweep_bad_asics.bad_asic_num] = id;
      snprintf(tmp42,0x100,"bad asic list[%d]:%d",g_sweep_bad_asics.bad_asic_num,
               g_sweep_bad_asics.bad_asic_ids[g_sweep_bad_asics.bad_asic_num]);
      puts(tmp42);
      g_sweep_bad_asics.bad_asic_num = g_sweep_bad_asics.bad_asic_num + 1;
      return;
    }
    if (g_sweep_bad_asics.bad_asic_ids[i] == id) break;
    i = i + 1;
  }
  return;
}

