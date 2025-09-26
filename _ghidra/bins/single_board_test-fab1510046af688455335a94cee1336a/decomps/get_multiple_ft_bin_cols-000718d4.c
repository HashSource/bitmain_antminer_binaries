
int get_multiple_ft_bin_cols(ft_bin_list_t *list)

{
  ft_bin_list_t *list_local;
  int i;
  int cols;
  
  cols = 0;
  for (i = 0; i < list->ft_bin_cnt; i = i + 1) {
    cols = cols + (((uint)*(byte *)((int)list->ft_bin + i * 4 + 2) << 0x18) >> 0x1c);
  }
  return cols;
}

