
void fresh_bad_asic_info(float **matrix,int sweep_count)

{
  int *piVar1;
  int iVar2;
  double dVar3;
  uint uVar4;
  ushort local_15c;
  int sweep_count_local;
  float **matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  uint16_t least_nonce_num;
  uint16_t got_nonce_num;
  int which_asic;
  int index;
  int asic_in_domain;
  int which_domain;
  
  dVar3 = (double)(longlong)((g_rt.config)->patter_num * (g_rt.config)->asic_small_cores) * 0.8;
  uVar4 = (uint)(0.0 < dVar3) * (int)(longlong)dVar3;
  local_15c = (ushort)uVar4;
  memset(&g_asic_bad_lit,0,0x404);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : least_nonce_num = %d, sweep_count = %d\n\n","fresh_bad_asic_info",uVar4 & 0xffff,
         sweep_count);
  snprintf(tmp1,0x100,"least_nonce_num = %d, sweep_count = %d\n",uVar4 & 0xffff,sweep_count);
  log_to_file(tmp1,time_stamp);
  for (which_domain = 0; which_domain < (g_rt.config)->domains; which_domain = which_domain + 1) {
    for (asic_in_domain = 0; asic_in_domain < (g_rt.config)->asics_in_domain;
        asic_in_domain = asic_in_domain + 1) {
      iVar2 = asic_in_domain + which_domain * (g_rt.config)->asics_in_domain;
      if ((g_rt.last_succ_asic_nonce_num[iVar2] < local_15c) && ((*matrix)[iVar2] <= 460.0)) {
        piVar1 = g_asic_bad_lit.bad_asic_list + g_asic_bad_lit.bad_asic_num;
        g_asic_bad_lit.bad_asic_num = g_asic_bad_lit.bad_asic_num + 1;
        *piVar1 = iVar2;
      }
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : bad asic count %d\n\n","fresh_bad_asic_info",g_asic_bad_lit.bad_asic_num);
  snprintf(tmp1,0x100,"bad asic count %d\n",g_asic_bad_lit.bad_asic_num);
  log_to_file(tmp1,time_stamp);
  for (index = 0; index < g_asic_bad_lit.bad_asic_num; index = index + 1) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : [%d]\n\n","fresh_bad_asic_info",g_asic_bad_lit.bad_asic_list[index]);
    snprintf(tmp1,0x100,"[%d]\n",g_asic_bad_lit.bad_asic_list[index]);
    log_to_file(tmp1,time_stamp);
  }
  return;
}

