
void display_PCBA_result(void *value,uint8_t row,uint8_t clomun,_Bool is_float)

{
  _Bool is_float_local;
  uint8_t clomun_local;
  uint8_t row_local;
  void *value_local;
  float matrix_pcba [216];
  uint16_t *matrix_1;
  float *matrix;
  int j;
  int i;
  
  if (is_float) {
    memset(matrix_pcba,0,0x360);
    for (i = 0; i < (int)(uint)row; i = i + 1) {
      printf("%7d ",i);
      for (j = 0; j < (int)(uint)clomun; j = j + 1) {
        if ((i & 1U) == 0) {
          matrix_pcba[i + j * (uint)row] =
               *(float *)((((i + 1) * (uint)clomun + -1) - j) * 4 + (int)value);
        }
        else {
          matrix_pcba[i + j * (uint)row] = *(float *)((j + i * (uint)clomun) * 4 + (int)value);
        }
      }
    }
    putchar(10);
    for (i = 0; i < (int)(uint)clomun; i = i + 1) {
      for (j = 0; j < (int)(uint)row; j = j + 1) {
        printf("%7.4f ");
      }
      putchar(10);
    }
  }
  else {
    memset(matrix_pcba,0,0x1b0);
    for (i = 0; i < (int)(uint)row; i = i + 1) {
      printf("%5d ",i);
      for (j = 0; j < (int)(uint)clomun; j = j + 1) {
        if ((i & 1U) == 0) {
          *(undefined2 *)((int)matrix_pcba + (j * (uint)row + i) * 2) =
               *(undefined2 *)((((i + 1) * (uint)clomun + -1) - j) * 2 + (int)value);
        }
        else {
          *(undefined2 *)((int)matrix_pcba + (j * (uint)row + i) * 2) =
               *(undefined2 *)((j + i * (uint)clomun) * 2 + (int)value);
        }
      }
    }
    putchar(10);
    for (i = 0; i < (int)(uint)clomun; i = i + 1) {
      for (j = 0; j < (int)(uint)row; j = j + 1) {
        printf("%5d ",(uint)*(ushort *)((int)matrix_pcba + (i * (uint)row + j) * 2));
      }
      putchar(10);
    }
  }
  return;
}

