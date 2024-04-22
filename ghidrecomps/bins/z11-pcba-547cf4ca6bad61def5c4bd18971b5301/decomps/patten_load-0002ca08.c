
void patten_load(void)

{
  char acStack_1064 [64];
  char acStack_1024 [4096];
  char *local_24;
  int local_20;
  FILE *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_18 = g_patten._16_4_ + g_patten._8_4_ + g_patten._12_4_;
  for (local_c = 0; local_c < (int)g_patten._0_4_; local_c = local_c + 1) {
    for (local_10 = 0; local_10 < (int)g_patten._4_4_; local_10 = local_10 + 1) {
      memset(acStack_1064,0,0x40);
      sprintf(acStack_1064,"%s/%s/%s-0x%02x/%s-0x%02x.txt",DAT_0002cd78,DAT_0002cd74,DAT_0002cd70,
              local_c,DAT_0002cd6c,local_10);
      printf("fname %s\n",acStack_1064);
      local_1c = fopen(acStack_1064,"r");
      for (local_14 = 0; local_14 < (int)g_patten._20_4_; local_14 = local_14 + 1) {
        local_20 = local_18 * local_10 * g_patten._20_4_ +
                   local_18 * g_patten._20_4_ * local_c * g_patten._4_4_ + local_18 * local_14 +
                   g_patten._88_4_;
        memset(acStack_1024,0,0x1000);
        fgets(acStack_1024,0x1000,local_1c);
        local_24 = strtok(acStack_1024,"work");
        hex2bin(local_20,local_24 + 1,g_patten._8_4_);
        local_24 = strtok(acStack_1024,"nonce");
        hex2bin(local_20 + g_patten._8_4_,local_24 + 1,g_patten._12_4_);
        local_24 = strtok(acStack_1024,"sol");
        hex2bin(local_20 + g_patten._12_4_ + g_patten._8_4_,local_24 + 1,g_patten._16_4_);
        printf("load asic%d core%d patten%d %s\n",local_c,local_10,local_14,acStack_1024);
      }
      fclose(local_1c);
    }
  }
  return;
}

