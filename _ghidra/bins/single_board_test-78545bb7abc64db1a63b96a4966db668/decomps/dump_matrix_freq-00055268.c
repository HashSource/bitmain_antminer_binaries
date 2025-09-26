
void dump_matrix_freq(float *matrix,int row,int cloumn)

{
  int cloumn_local;
  int row_local;
  float *matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  int j;
  int i;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : ============matrix freq==============\n\n","dump_matrix_freq");
  builtin_strncpy(tmp1,"============matrix freq=============",0x24);
  tmp1[0x24] = '=';
  tmp1[0x25] = '\n';
  tmp1[0x26] = '\0';
  log_to_file(tmp1,time_stamp);
  for (i = 0; i < row; i = i + 1) {
    for (j = 0; j < cloumn; j = j + 1) {
      printf("%4.2f ");
      snprintf(dump_matrix_freq::lexical_block_5::lexical_block_5_1::lexical_block_5_1_1::tmp1_1,
               0x100,"%4.2f ",matrix + j + cloumn * i,(double)matrix[j + cloumn * i]);
      log_to_filex(dump_matrix_freq::lexical_block_5::lexical_block_5_1::lexical_block_5_1_1::tmp1_1
                   ,tmp1);
      if (cloumn + -1 == j) {
        putchar(10);
        dump_matrix_freq::lexical_block_5::lexical_block_5_1::lexical_block_5_1_2::tmp1_2[0] = '\n';
        dump_matrix_freq::lexical_block_5::lexical_block_5_1::lexical_block_5_1_2::tmp1_2[1] = '\0';
        log_to_filex(dump_matrix_freq::lexical_block_5::lexical_block_5_1::lexical_block_5_1_2::
                     tmp1_2,tmp1);
      }
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : ============matrix freq==============\n\n","dump_matrix_freq");
  builtin_strncpy(tmp1,"============matrix freq=============",0x24);
  tmp1[0x24] = '=';
  tmp1[0x25] = '\n';
  tmp1[0x26] = '\0';
  log_to_file(tmp1,time_stamp);
  return;
}

