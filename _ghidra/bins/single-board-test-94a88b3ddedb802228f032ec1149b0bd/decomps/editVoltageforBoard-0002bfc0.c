
void editVoltageforBoard(void)

{
  FILE *__stream;
  int local_c;
  
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    if (*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) {
      if (3 < log_level) {
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d: try to add more 0.1V voltage on chain[%d]\n","main.c",0x1c36,
                  local_c);
        }
        fclose(__stream);
      }
      up10_vol_toPIC(local_c);
    }
  }
  return;
}

