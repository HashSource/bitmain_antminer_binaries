
void display_PCBA_result(void *value,uint8_t row,uint8_t clomun,_Bool is_float)

{
  float *pfVar1;
  int iVar2;
  _Bool is_float_local;
  uint8_t clomun_local;
  uint8_t row_local;
  void *value_local;
  char time_stamp [48];
  int temp_j_1;
  uint16_t *matrix_1;
  int temp_j;
  float *matrix;
  int j;
  int i;
  
  if (is_float) {
    for (i = 0; i < (int)(uint)row; i = i + 1) {
      for (j = 0; j < (int)(uint)clomun; j = j + 1) {
        iVar2 = j;
        if ((i & 1U) != 0) {
          iVar2 = ((uint)clomun - j) + -1;
        }
        printf("%7.4f ");
        pfVar1 = (float *)((iVar2 + i * (uint)clomun) * 4 + (int)value);
        snprintf(display_PCBA_result::lexical_block_6::lexical_block_6_1::lexical_block_6_1_1::tmp1,
                 0x100,"%7.4f ",pfVar1,(double)*pfVar1);
        log_to_filex(display_PCBA_result::lexical_block_6::lexical_block_6_1::lexical_block_6_1_1::
                     tmp1,time_stamp);
      }
      putchar(10);
      display_PCBA_result::lexical_block_6::lexical_block_6_2::tmp1_1[0] = '\n';
      display_PCBA_result::lexical_block_6::lexical_block_6_2::tmp1_1[1] = '\0';
      log_to_filex(display_PCBA_result::lexical_block_6::lexical_block_6_2::tmp1_1,time_stamp);
    }
  }
  else {
    for (i = 0; i < (int)(uint)row; i = i + 1) {
      for (j = 0; j < (int)(uint)clomun; j = j + 1) {
        iVar2 = j;
        if ((i & 1U) != 0) {
          iVar2 = ((uint)clomun - j) + -1;
        }
        printf("%5d ",(uint)*(ushort *)((iVar2 + i * (uint)clomun) * 2 + (int)value));
        snprintf(display_PCBA_result::lexical_block_7::lexical_block_7_1::lexical_block_7_1_1::
                 tmp1_2,0x100,"%5d ",(uint)*(ushort *)((iVar2 + i * (uint)clomun) * 2 + (int)value))
        ;
        log_to_filex(display_PCBA_result::lexical_block_7::lexical_block_7_1::lexical_block_7_1_1::
                     tmp1_2,time_stamp);
      }
      putchar(10);
      display_PCBA_result::lexical_block_7::lexical_block_7_2::tmp1_3[0] = '\n';
      display_PCBA_result::lexical_block_7::lexical_block_7_2::tmp1_3[1] = '\0';
      log_to_filex(display_PCBA_result::lexical_block_7::lexical_block_7_2::tmp1_3,time_stamp);
    }
  }
  return;
}

