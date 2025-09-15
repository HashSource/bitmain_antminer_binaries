
void sweep_freq_sort_array(int row,int *src,int *rate,uint len)

{
  uint len_local;
  int *rate_local;
  int *src_local;
  int row_local;
  int min_int32;
  int index_of_max;
  int max;
  int j;
  int i;
  
  for (i = 0; (uint)i < len; i = i + 1) {
    rate[i] = 0;
  }
  for (i = 0; (uint)i < len; i = i + 1) {
    max = -0x80000000;
    index_of_max = 0;
    for (j = 0; (uint)j < len; j = j + 1) {
      if ((row & 1U) == 0) {
        if ((rate[j] == 0) && (max < src[j])) {
          max = src[j];
          index_of_max = j;
        }
      }
      else if ((rate[j] == 0) && (max <= src[j])) {
        max = src[j];
        index_of_max = j;
      }
    }
    rate[index_of_max] = i + 1;
  }
  return;
}

