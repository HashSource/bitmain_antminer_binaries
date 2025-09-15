
_Bool check_freq_valid(uint32_t *freq_buf,uint32_t len,uint32_t valid_max_freq)

{
  uint32_t valid_max_freq_local;
  uint32_t len_local;
  uint32_t *freq_buf_local;
  uint32_t compare_diff;
  int i;
  
  i = 0;
  while( true ) {
    if (len <= (uint)i) {
      return true;
    }
    if (valid_max_freq + 1 < freq_buf[i]) break;
    i = i + 1;
  }
  return false;
}

