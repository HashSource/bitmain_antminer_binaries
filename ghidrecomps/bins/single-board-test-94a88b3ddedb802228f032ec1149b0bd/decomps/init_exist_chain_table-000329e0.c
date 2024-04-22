
void init_exist_chain_table(void)

{
  FILE *__stream;
  int local_10;
  int local_c;
  
  local_c = 0;
  do {
    if (0xf < local_c) {
      if (3 < log_level) {
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d: total_exist_chain_num = %d\n","main.c",0x368b,
                  total_exist_chain_num);
        }
        fclose(__stream);
      }
      return;
    }
    if (*(int *)(cgpu + (local_c + 0x9c638) * 4) == 1) {
      for (local_10 = 0; local_10 < 0x10; local_10 = local_10 + 1) {
        if (*(int *)(exist_chain + local_10 * 4) == 0) {
          *(int *)(exist_chain + local_10 * 4) = local_c;
          break;
        }
      }
      total_exist_chain_num = total_exist_chain_num + 1;
    }
    local_c = local_c + 1;
  } while( true );
}

