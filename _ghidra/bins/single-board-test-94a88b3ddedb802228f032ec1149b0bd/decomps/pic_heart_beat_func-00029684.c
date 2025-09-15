
undefined4 pic_heart_beat_func(void)

{
  int iVar1;
  int aiStack_54 [16];
  FILE *local_14;
  FILE *local_10;
  uint local_c;
  
  local_c = 0;
  memset(aiStack_54,0,0x40);
  while (ExitFlag != '\x01') {
    if (start_pic_heart == '\x01') {
      for (local_c = 0; (int)local_c < 0x10; local_c = local_c + 1) {
        if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) && (start_pic_heart == '\x01')) {
          usleep(10000);
          iVar1 = pic_heart_beat(local_c & 0xff);
          if (iVar1 == 0) {
            aiStack_54[local_c] = aiStack_54[local_c] + 1;
            if (1 < log_level) {
              local_10 = fopen(log_file,"a+");
              if (local_10 != (FILE *)0x0) {
                fprintf(local_10,"%s:%d: chain[%d] heart beat fail %d times.\n","main.c",0xd9f,
                        local_c,aiStack_54[local_c]);
              }
              fclose(local_10);
            }
          }
          else {
            aiStack_54[local_c] = 0;
          }
          if (6 < aiStack_54[local_c]) {
            if (1 < log_level) {
              local_14 = fopen(log_file,"a+");
              if (local_14 != (FILE *)0x0) {
                fprintf(local_14,"%s:%d: chain[%d] is dead...\n","main.c",0xda4,local_c);
              }
              fclose(local_14);
            }
            sprintf(search_failed_info,"J%d:pic dead",local_c);
            saveSearchFailedFlagInfo();
            searchStatus = 2;
          }
        }
      }
      sleep(10);
    }
    else {
      sleep(1);
    }
  }
  picheartExit = 1;
  return 0;
}

