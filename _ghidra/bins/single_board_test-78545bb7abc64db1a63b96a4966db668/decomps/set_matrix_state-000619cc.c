
/* WARNING: Variable defined which should be unmapped: his_asic_nonce_num_local */
/* WARNING: Variable defined which should be unmapped: matrix_local */
/* WARNING: Variable defined which should be unmapped: last_matrix_local */

void set_matrix_state(uint8_t **state,float *last_matrix,float **matrix,uint16_t *his_asic_nonce_num
                     )

{
  double dVar1;
  uint16_t *his_asic_nonce_num_local;
  float **matrix_local;
  float *last_matrix_local;
  uint8_t **state_local;
  char time_stamp [48];
  char tmp1 [256];
  float curr;
  int i;
  
  i = 0;
  do {
    if ((g_rt.config)->asics <= i) {
      dump_matrix_state(*state);
      return;
    }
    if ((g_rt.asic_stats.bad_asic_list[i] == false) || ((*state)[i] != '\x01')) {
      if ((*state)[i] != '\x01') {
        if ((double)(longlong)((g_rt.config)->patter_num * (g_rt.config)->asic_small_cores) *
            ((double)(longlong)((g_rt.config)->standard).asic_nonce_rate / 10000.0 + 0.01) <
            (double)g_rt.asic_stats.every_asic_got_nonce_num[i]) {
          (*state)[i] = '\x01';
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          dVar1 = (double)(longlong)((g_rt.config)->standard).asic_nonce_rate / 10000.0 + 0.01;
          printf("%s : bad asic %d reset to normal, nonce:%d,stand rate:%f\n\n","set_matrix_state",i
                 ,(uint)g_rt.asic_stats.every_asic_got_nonce_num[i],dVar1);
          snprintf(tmp1,0x100,"bad asic %d reset to normal, nonce:%d,stand rate:%f\n",i,
                   (uint)g_rt.asic_stats.every_asic_got_nonce_num[i],(int)((ulonglong)dVar1 >> 0x20)
                   ,(double)(longlong)((g_rt.config)->standard).asic_nonce_rate / 10000.0 + 0.01,
                   his_asic_nonce_num,matrix,last_matrix);
          log_to_file(tmp1,time_stamp);
          goto LAB_00061d36;
        }
      }
      if ((*state)[i] == '\0') {
        (*state)[i] = '\x02';
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : asic %d remain curr freq, nonce:%d\n\n\n","set_matrix_state",i,
               (uint)g_rt.asic_stats.every_asic_got_nonce_num[i]);
        snprintf(tmp1,0x100,"asic %d remain curr freq, nonce:%d\n\n",i,
                 (uint)g_rt.asic_stats.every_asic_got_nonce_num[i]);
        log_to_file(tmp1,time_stamp);
      }
    }
    else {
      (*state)[i] = '\0';
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : new bad asic %d, nonce:%d\n\n\n","set_matrix_state",i,
             (uint)g_rt.asic_stats.every_asic_got_nonce_num[i]);
      snprintf(tmp1,0x100,"new bad asic %d, nonce:%d\n\n",i,
               (uint)g_rt.asic_stats.every_asic_got_nonce_num[i]);
      log_to_file(tmp1,time_stamp);
    }
LAB_00061d36:
    i = i + 1;
  } while( true );
}

