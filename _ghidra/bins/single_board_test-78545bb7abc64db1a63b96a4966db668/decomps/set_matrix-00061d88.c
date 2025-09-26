
void set_matrix(float nextfreq,float **matrix,uint8_t **state)

{
  uint8_t **state_local;
  float **matrix_local;
  float nextfreq_local;
  char time_stamp [48];
  char tmp1 [256];
  int i;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : set freq[%4.2f] to matrix\n","set_matrix",SUB84((double)nextfreq,0),
         (int)((ulonglong)(double)nextfreq >> 0x20));
  snprintf(tmp1,0x100,"set freq[%4.2f] to matrix",tmp1,(double)nextfreq);
  log_to_file(tmp1,time_stamp);
  for (i = 0; i < (g_rt.config)->asics; i = i + 1) {
    if ((*state)[i] == '\x01') {
      (*matrix)[i] = (*matrix)[i] + 6.25;
    }
    else if (((*state)[i] == '\0') && (460.0 <= (*matrix)[i])) {
      (*matrix)[i] = (*matrix)[i] - 6.25;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : bad asic idx %d, reset[%4.2f] to last[%4.2f]\n\n","set_matrix",i,*matrix + i,
             (double)(*matrix)[i] + 6.25,(double)(*matrix)[i]);
      snprintf(tmp1,0x100,"bad asic idx %d, reset[%4.2f] to last[%4.2f]\n",i,
               (double)(*matrix)[i] + 6.25,(double)(*matrix)[i]);
      log_to_file(tmp1,time_stamp);
    }
  }
  display_PCBA_result(*matrix,(uint8_t)(g_rt.config)->domains,
                      (uint8_t)(g_rt.config)->asics_in_domain,true);
  return;
}

