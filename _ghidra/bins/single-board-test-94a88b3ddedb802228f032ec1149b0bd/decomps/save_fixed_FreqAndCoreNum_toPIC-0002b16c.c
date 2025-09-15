
void save_fixed_FreqAndCoreNum_toPIC(void)

{
  int iVar1;
  byte abStack_bc [128];
  FILE *local_3c;
  FILE *local_38;
  FILE *local_34;
  FILE *local_30;
  FILE *local_2c;
  FILE *local_28;
  FILE *local_24;
  FILE *local_20;
  FILE *local_1c;
  FILE *local_18;
  FILE *local_14;
  int local_10;
  uint local_c;
  
  memset(abStack_bc,0,0x80);
  for (local_c = 0; (int)local_c < 0x10; local_c = local_c + 1) {
    if (*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) {
      while( true ) {
        save_freq_badcores(local_c & 0xff,chain_pic_buf + local_c * 0x80);
        read_freq_badcores(local_c & 0xff,abStack_bc);
        iVar1 = memcmp(abStack_bc,chain_pic_buf + local_c * 0x80,0x80);
        if (iVar1 == 0) break;
        if (3 < log_level) {
          local_14 = fopen(log_file,"a+");
          if (local_14 != (FILE *)0x0) {
            fprintf(local_14,"%s:%d: Error: flash write error! on Chain[%d]\n","main.c",0x18db,
                    local_c);
          }
          fclose(local_14);
        }
        if (3 < log_level) {
          local_18 = fopen(log_file,"a+");
          if (local_18 != (FILE *)0x0) {
            fprintf(local_18,"%s:%d: Chain[%d] read chain_pic_buf[%d] : ","main.c",0x18dd,local_c,
                    local_c);
          }
          fclose(local_18);
        }
        for (local_10 = 0; local_10 < 0x80; local_10 = local_10 + 1) {
          if (3 < log_level) {
            local_1c = fopen(log_file,"a+");
            if (local_1c != (FILE *)0x0) {
              fprintf(local_1c,"0x%x ",(uint)(byte)chain_pic_buf[local_10 + local_c * 0x80]);
            }
            fclose(local_1c);
          }
        }
        if (3 < log_level) {
          local_20 = fopen(log_file,"a+");
          if (local_20 != (FILE *)0x0) {
            fputc(10,local_20);
          }
          fclose(local_20);
        }
        if (3 < log_level) {
          local_24 = fopen(log_file,"a+");
          if (local_24 != (FILE *)0x0) {
            fprintf(local_24,"%s:%d: Chain[%d] read buf : ","main.c",0x18e4,local_c);
          }
          fclose(local_24);
        }
        for (local_10 = 0; local_10 < 0x80; local_10 = local_10 + 1) {
          if (3 < log_level) {
            local_28 = fopen(log_file,"a+");
            if (local_28 != (FILE *)0x0) {
              fprintf(local_28,"0x%x ",(uint)abStack_bc[local_10]);
            }
            fclose(local_28);
          }
        }
        if (3 < log_level) {
          local_2c = fopen(log_file,"a+");
          if (local_2c != (FILE *)0x0) {
            fputc(10,local_2c);
          }
          fclose(local_2c);
        }
        if (3 < log_level) {
          local_30 = fopen(log_file,"a+");
          if (local_30 != (FILE *)0x0) {
            fprintf(local_30,"%s:%d: try to write again! on Chain[%d]\n","main.c",0x18eb,local_c);
          }
          fclose(local_30);
        }
        sleep(1);
      }
      if (3 < log_level) {
        local_34 = fopen(log_file,"a+");
        if (local_34 != (FILE *)0x0) {
          fprintf(local_34,"%s:%d: Chain[%d] read buf : ","main.c",0x18f0,local_c);
        }
        fclose(local_34);
      }
      for (local_10 = 0; local_10 < 0x80; local_10 = local_10 + 1) {
        if (3 < log_level) {
          local_38 = fopen(log_file,"a+");
          if (local_38 != (FILE *)0x0) {
            fprintf(local_38,"0x%x ",(uint)abStack_bc[local_10]);
          }
          fclose(local_38);
        }
      }
      if (3 < log_level) {
        local_3c = fopen(log_file,"a+");
        if (local_3c != (FILE *)0x0) {
          fputc(10,local_3c);
        }
        fclose(local_3c);
      }
    }
  }
  return;
}

