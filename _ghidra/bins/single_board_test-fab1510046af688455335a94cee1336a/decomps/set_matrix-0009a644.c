
void set_matrix(float nextfreq,float **matrix,uint8_t **state)

{
  int iVar1;
  uint8_t **state_local;
  float **matrix_local;
  float nextfreq_local;
  char time_stamp [48];
  char tmp42 [256];
  int which_asic;
  int asic_in_domain;
  int which_domain;
  
  snprintf(tmp42,0x100,"set freq[%4.2f] to matrix",tmp42,(double)nextfreq);
  puts(tmp42);
  for (which_domain = 0; which_domain < (g_rt.config)->domains; which_domain = which_domain + 1) {
    for (asic_in_domain = 0; asic_in_domain < (g_rt.config)->asics_in_domain;
        asic_in_domain = asic_in_domain + 1) {
      iVar1 = asic_in_domain + which_domain * (g_rt.config)->asics_in_domain;
      if ((*state)[iVar1] == '\x01') {
        (*matrix)[iVar1] = (*matrix)[iVar1] + g_rt.sweep.step;
      }
      else if ((float)(longlong)((g_rt.config)->tests[(g_rt.config)->test_levels + -1].freq + -10) <
               (*matrix)[iVar1]) {
        (*matrix)[iVar1] = (*matrix)[iVar1] - g_rt.sweep.step;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: bad asic idx %d,set to[%4.2f]\n\n","set_matrix",iVar1,*matrix + iVar1,
               (double)(*matrix)[iVar1]);
        snprintf(tmp42,0x800,"bad asic idx %d,set to[%4.2f]\n",iVar1,(double)(*matrix)[iVar1]);
        log_to_file(tmp42,time_stamp);
      }
    }
  }
  dump_matrix_freq(*matrix,(g_rt.config)->domains,(g_rt.config)->asics_in_domain);
  return;
}

