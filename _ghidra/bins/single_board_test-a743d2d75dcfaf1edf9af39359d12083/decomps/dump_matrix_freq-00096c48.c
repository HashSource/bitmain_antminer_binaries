
void dump_matrix_freq(float *matrix,int row,int cloumn)

{
  int cloumn_local;
  int row_local;
  float *matrix_local;
  int matrix_asis_addr [216];
  float matrix_pcba [216];
  int j;
  int i;
  
  puts("============matrix freq==============");
  memset(matrix_pcba,0,0x360);
  memset(matrix_asis_addr,0,0x360);
  i = 0;
  while( true ) {
    if (row <= i) break;
    printf("%6d ",i);
    for (j = 0; j < cloumn; j = j + 1) {
      if ((i & 1U) == 0) {
        matrix_pcba[i + row * j] = matrix[(cloumn * (i + 1) + -1) - j];
        matrix_asis_addr[row * j + i] = (cloumn * (i + 1) + -1) - j;
      }
      else {
        matrix_pcba[i + row * j] = matrix[j + i * cloumn];
        matrix_asis_addr[row * j + i] = i * cloumn + j;
      }
    }
    i = i + 1;
  }
  putchar(10);
  for (i = 0; i < cloumn; i = i + 1) {
    for (j = 0; j < row; j = j + 1) {
      printf("%3.2f ");
    }
    putchar(10);
  }
  puts("addr map:");
  for (i = 0; i < cloumn; i = i + 1) {
    for (j = 0; j < row; j = j + 1) {
      printf("%d ",matrix_asis_addr[row * i + j]);
    }
    putchar(10);
  }
  puts("============matrix freq==============");
  return;
}

