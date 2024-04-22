
int freq_tuning_get_max_index(int *array,uint len)

{
  uint len_local;
  int *array_local;
  int i;
  int max_index;
  int max;
  
  max = *array;
  max_index = 0;
  for (i = 0; (uint)i < len; i = i + 1) {
    if (max < array[i]) {
      max = array[i];
      max_index = i;
    }
  }
  return max_index;
}

