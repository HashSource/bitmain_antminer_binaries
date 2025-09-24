
void add_bad_asic_ids(int id)

{
  int id_local;
  char time_stamp [48];
  char tmp1 [256];
  int i;
  
  i = 0;
  while( true ) {
    if (g_sweep_bad_asics.bad_asic_num <= i) {
      if (g_sweep_bad_asics.bad_asic_num < 0xc) {
        g_sweep_bad_asics.bad_asic_ids[g_sweep_bad_asics.bad_asic_num] = id;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : bad asic list[%d]:%d\n","add_bad_asic_ids",g_sweep_bad_asics.bad_asic_num,
               g_sweep_bad_asics.bad_asic_ids[g_sweep_bad_asics.bad_asic_num]);
        snprintf(tmp1,0x100,"bad asic list[%d]:%d",g_sweep_bad_asics.bad_asic_num,
                 g_sweep_bad_asics.bad_asic_ids[g_sweep_bad_asics.bad_asic_num]);
        log_to_file(tmp1,time_stamp);
        g_sweep_bad_asics.bad_asic_num = g_sweep_bad_asics.bad_asic_num + 1;
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : bad asic list size:%d\n","add_bad_asic_ids",g_sweep_bad_asics.bad_asic_num);
      snprintf(tmp1,0x100,"bad asic list size:%d",g_sweep_bad_asics.bad_asic_num);
      log_to_file(tmp1,time_stamp);
      return;
    }
    if (g_sweep_bad_asics.bad_asic_ids[i] == id) break;
    i = i + 1;
  }
  return;
}

