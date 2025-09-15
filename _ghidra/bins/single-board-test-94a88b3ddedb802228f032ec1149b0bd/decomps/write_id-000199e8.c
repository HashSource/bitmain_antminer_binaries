
void write_id(undefined4 param_1)

{
  size_t __size;
  byte local_20 [16];
  FILE *local_10;
  byte local_9;
  
  local_20[0] = 0x49;
  local_20[1] = 100;
  local_20[2] = 0x3d;
  local_20[3] = 0x20;
  local_20[4] = 0x20;
  local_20[5] = 0x20;
  local_20[6] = 0x20;
  local_20[7] = 0x20;
  local_20[8] = 0x20;
  local_20[9] = 0x20;
  local_20[10] = 0x20;
  local_20[0xb] = 0x20;
  local_20[0xc] = 0x20;
  local_20[0xd] = 0;
  local_20[0xe] = 0;
  local_20[0xf] = 0;
  local_9 = 0;
  printf("\n--- %s\n","write_id");
  local_10 = fopen("/etc/config/Id.ini","w");
  if (local_10 == (FILE *)0x0) {
    printf("\n%s: open Id.ini failed\n","write_id");
  }
  else {
    sprintf((char *)(local_20 + 3),"%d",param_1);
    for (local_9 = 0; local_9 < 0xd; local_9 = local_9 + 1) {
      printf("--- %s: hash_board_id[%d] = %c\n","write_id",(uint)local_9,(uint)local_20[local_9]);
    }
    __size = strlen((char *)local_20);
    fwrite(local_20,__size,1,local_10);
    fclose(local_10);
  }
  return;
}

