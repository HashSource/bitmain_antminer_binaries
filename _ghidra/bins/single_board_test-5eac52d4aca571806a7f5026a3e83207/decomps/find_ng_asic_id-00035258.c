
uint32_t find_ng_asic_id(uint32_t *id_buf,uint32_t num)

{
  uint32_t num_local;
  uint32_t *id_buf_local;
  uint32_t cnt;
  int i;
  
  cnt = 0;
  i = 1;
  do {
    if ((Local_Config_Information->Hash_Board).Asic_Num < (uint)i) {
      return cnt;
    }
    if (gHistory_Result[gPattern_test_counter].ok_asic_list[i + -1] != true) {
      id_buf[cnt] = i;
      cnt = cnt + 1;
      if (num <= cnt) {
        return cnt;
      }
    }
    i = i + 1;
  } while( true );
}

