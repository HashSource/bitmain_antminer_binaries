
void set_matrix_state(uint8_t **state,float *last_matrix,float **matrix)

{
  float fVar1;
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
    if (g_rt.asic_stats.bad_asic_list[i] != false) {
      if ((*state)[i] == '\0') {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : bad asic idx %d,last[%4.2f]\n\n","set_matrix_state",i,*matrix + i,
               (double)(*matrix)[i]);
        snprintf(tmp1,0x100,"bad asic idx %d,last[%4.2f]\n",i,(double)(*matrix)[i]);
        log_to_file(tmp1,time_stamp);
      }
      else {
        (*state)[i] = '\0';
        fVar1 = (*matrix)[i];
        if ((i + 2) % 9 < 4) {
          if (((i + 2) / 7) % 9 != 1) goto LAB_0005d132;
          (*matrix)[i] = last_matrix[i] - 6.25;
        }
        else {
LAB_0005d132:
          (*matrix)[i] = last_matrix[i];
        }
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : bad asic idx %d, reset[%4.2f] to last[%4.2f]\n\n","set_matrix_state",i,
               *matrix + i,(double)fVar1,(double)(*matrix)[i]);
        snprintf(tmp1,0x100,"bad asic idx %d, reset[%4.2f] to last[%4.2f]\n",i,(double)fVar1,
                 (double)(*matrix)[i]);
        log_to_file(tmp1,time_stamp);
      }
    }
    i = i + 1;
  } while( true );
}

