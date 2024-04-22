
/* WARNING: Unknown calling convention */

void btm_show_core_nonce(void)

{
  bool bVar1;
  char *__s;
  FILE *__s_00;
  int iVar2;
  size_t __size;
  char *tmp;
  FILE *file_tmp;
  int len;
  int k;
  int j;
  int i;
  
  len = 0;
  __s = (char *)malloc(0x40000);
  if (__s != (char *)0x0) {
    memset(__s,0,0x40000);
    bVar1 = 6 < btm_show_core_nonce::loop;
    btm_show_core_nonce::loop = btm_show_core_nonce::loop + 1;
    if (bVar1) {
      time_num = time_num + 1;
      btm_init_core_nonce_file(time_num);
      btm_clear_core_nonce();
      btm_show_core_nonce::loop = 0;
    }
    __s_00 = btm_open_core_nonce_file(time_num);
    if (__s_00 != (FILE *)0x0) {
      for (k = 0; k < 0x10; k = k + 1) {
        if (dev->chain_exist[k] == 1) {
          iVar2 = sprintf(__s + len,"\n----------chain[%02d]-loop[%d]----------\n",k,
                          btm_show_core_nonce::loop);
          len = len + iVar2;
          for (i = 0; i < 0x6c; i = i + 1) {
            iVar2 = sprintf(__s + len,"\n----------asic[%02d]----------\n",i);
            len = len + iVar2;
            for (j = 0; j < 0xd0; j = j + 1) {
              iVar2 = sprintf(__s + len,"\tcore[%03d]=%d",j,asic_core_nonce_num_chain[k][i][j]);
              len = len + iVar2;
              if ((j & 7U) == 0) {
                *(undefined2 *)(__s + len) = DAT_000792f4;
                len = len + 1;
              }
            }
          }
        }
      }
      __size = strlen(__s);
      fwrite(__s,__size,1,(FILE *)__s_00);
      fclose((FILE *)__s_00);
    }
    free(__s);
  }
  return;
}

