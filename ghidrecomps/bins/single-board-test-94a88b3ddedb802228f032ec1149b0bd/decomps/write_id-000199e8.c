
void write_id(undefined4 param_1)

{
  size_t __size;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  FILE *local_10;
  byte local_9;
  
  local_20 = 0x203d6449;
  local_1c = 0x20202020;
  local_18 = 0x20202020;
  local_14 = 0x20;
  local_9 = 0;
  printf("\n--- %s\n","write_id");
  local_10 = fopen("/etc/config/Id.ini","w");
  if (local_10 == (FILE *)0x0) {
    printf("\n%s: open Id.ini failed\n","write_id");
  }
  else {
    sprintf((char *)((int)&local_20 + 3),"%d",param_1);
    for (local_9 = 0; local_9 < 0xd; local_9 = local_9 + 1) {
      printf("--- %s: hash_board_id[%d] = %c\n","write_id",(uint)local_9,
             (uint)*(byte *)((int)&local_20 + (uint)local_9));
    }
    __size = strlen((char *)&local_20);
    fwrite(&local_20,__size,1,local_10);
    fclose(local_10);
  }
  return;
}

