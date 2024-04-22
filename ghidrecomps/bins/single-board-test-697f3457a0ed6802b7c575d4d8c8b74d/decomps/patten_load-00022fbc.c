
void patten_load(char *root_path)

{
  FILE *__stream;
  char *pcVar1;
  int iVar2;
  uchar *p;
  char *root_path_local;
  char fname [128];
  char buff [4096];
  char *tmp;
  uint8_t *cur_patten;
  FILE *fp_patten;
  int one_patten_bin_len;
  int which_patten;
  int which_core;
  int which_asic;
  
  iVar2 = g_patten.sol_bin_len + g_patten.work_bin_len + g_patten.nonce_bin_len;
  which_asic = 0;
  do {
    if (g_patten.asic_num <= which_asic) {
      puts("Load Patten Done");
      return;
    }
    for (which_core = 0; which_core < g_patten.core_num; which_core = which_core + 1) {
      memset(fname,0,0x80);
      sprintf(fname,"%s/%s/%s/%s-0x%02x/%s-0x%02x.txt",root_path,DAT_00023328,DAT_00023324,
              DAT_00023320,which_asic,DAT_0002331c,which_core);
      printf("fname %s\n",fname);
      __stream = fopen(fname,"r");
      if (__stream == (FILE *)0x0) {
        printf("open %s failed\n",fname);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      for (which_patten = 0; which_patten < g_patten.patten_num; which_patten = which_patten + 1) {
        p = g_patten.patten_start +
            iVar2 * which_core * g_patten.patten_num +
            iVar2 * g_patten.patten_num * which_asic * g_patten.core_num + iVar2 * which_patten;
        memset(buff,0,0x1000);
        fgets(buff,0x1000,__stream);
        pcVar1 = strstr(buff,"work");
        hex2bin(p,pcVar1 + 5,g_patten.work_bin_len);
        pcVar1 = strstr(buff,"nonce");
        hex2bin(p + g_patten.work_bin_len,pcVar1 + 6,g_patten.nonce_bin_len);
        pcVar1 = strstr(buff,"sol");
        hex2bin(p + g_patten.nonce_bin_len + g_patten.work_bin_len,pcVar1 + 4,g_patten.sol_bin_len);
      }
      fclose(__stream);
    }
    which_asic = which_asic + 1;
  } while( true );
}

