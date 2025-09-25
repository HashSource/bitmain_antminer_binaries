
void dump_matrix_state(uint8_t *state)

{
  uint8_t *state_local;
  char time_stamp [48];
  char tmp1 [256];
  int j;
  int i;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : ============matrix state==============\n\n","dump_matrix_state");
  builtin_strncpy(tmp1,"============matrix state==============\n",0x28);
  log_to_file(tmp1,time_stamp);
  for (i = 0; i < (g_rt.config)->domains; i = i + 1) {
    for (j = 0; j < (g_rt.config)->asics_in_domain; j = j + 1) {
      printf("%4d ",(uint)state[j + i * (g_rt.config)->asics_in_domain]);
      snprintf(dump_matrix_state::lexical_block_3::lexical_block_3_1::lexical_block_3_1_1::tmp1_1,
               0x100,"%4d ",(uint)state[j + i * (g_rt.config)->asics_in_domain]);
      log_to_filex(dump_matrix_state::lexical_block_3::lexical_block_3_1::lexical_block_3_1_1::
                   tmp1_1,tmp1);
      if ((g_rt.config)->asics_in_domain + -1 == j) {
        putchar(10);
        dump_matrix_state::lexical_block_3::lexical_block_3_1::lexical_block_3_1_2::tmp1_2[0] = '\n'
        ;
        dump_matrix_state::lexical_block_3::lexical_block_3_1::lexical_block_3_1_2::tmp1_2[1] = '\0'
        ;
        log_to_filex(dump_matrix_state::lexical_block_3::lexical_block_3_1::lexical_block_3_1_2::
                     tmp1_2,tmp1);
      }
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : ============matrix state==============\n\n","dump_matrix_state");
  builtin_strncpy(tmp1,"============matrix state==============\n",0x28);
  log_to_file(tmp1,time_stamp);
  return;
}

