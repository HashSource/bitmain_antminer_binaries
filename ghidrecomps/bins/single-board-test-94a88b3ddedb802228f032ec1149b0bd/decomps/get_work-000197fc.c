
int get_work(int param_1,int param_2)

{
  void *pvVar1;
  uint32_t uVar2;
  uint local_24;
  int *local_20;
  FILE *local_1c;
  void *local_18;
  size_t local_14;
  void *local_10;
  int local_c;
  
  local_c = 0;
  local_24 = 240000;
  local_10 = malloc(240000);
  fseek(*(FILE **)(cgpu + param_1 * 4),0,2);
  local_14 = ftell(*(FILE **)(cgpu + param_1 * 4));
  fseek(*(FILE **)(cgpu + param_1 * 4),0,0);
  local_18 = malloc(local_14);
  local_14 = fread(local_18,1,local_14,*(FILE **)(cgpu + param_1 * 4));
  uncompress(local_10,&local_24,local_18,local_14);
  free(local_18);
  pvVar1 = malloc(param_2 * 0x34);
  *(void **)(cgpu + (param_1 + 0xa8) * 4) = pvVar1;
  if (*(int *)(cgpu + (param_1 + 0xa8) * 4) == 0) {
    if (1 < log_level) {
      local_1c = fopen(log_file,"a+");
      if (local_1c != (FILE *)0x0) {
        fprintf(local_1c,"%s:%d: malloc struct work err\n","driver-bitmain.c",0x2ee);
      }
      fclose(local_1c);
    }
    local_c = 0;
  }
  else {
    for (; ((uint)(local_c * 0x30) < local_24 && (local_c < param_2)); local_c = local_c + 1) {
      local_20 = (int *)(local_c * 0x34 + *(int *)(cgpu + (param_1 + 0xa8) * 4));
      memcpy(local_20 + 1,(void *)(local_c * 0x30 + 0x2c + (int)local_10),4);
      uVar2 = htonl(local_20[1]);
      local_20[1] = uVar2;
      memcpy(local_20 + 5,(void *)((int)local_10 + local_c * 0x30),0x20);
      memcpy(local_20 + 2,(void *)(local_c * 0x30 + 0x20 + (int)local_10),0xc);
      *local_20 = local_c;
    }
    free(local_10);
  }
  return local_c;
}

