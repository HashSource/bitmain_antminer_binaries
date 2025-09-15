
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void patten_info_init(void)

{
  int one_patten_bin_len;
  
  memset(&g_patten,0,0x9c);
  g_patten.asic_num = app_conf->asic_num;
  g_patten.core_num = app_conf->core_num;
  g_patten.patten_num = app_conf->pattern_num;
  builtin_strncpy(g_patten.dir_root,"pattern",8);
  builtin_strncpy(g_patten.dir_algo,"zec-z15",8);
  builtin_strncpy(g_patten.dir_asic,"asic",4);
  g_patten.dir_asic[4] = '\0';
  builtin_strncpy(g_patten.file_core,"core",4);
  g_patten.file_core[4] = '\0';
  g_patten.work_bin_len = 0x8c;
  g_patten.nonce_bin_len = 4;
  g_patten.sol_bin_len = 0x540;
  g_patten.total_pattens = g_patten.patten_num * g_patten.core_num * g_patten.asic_num;
  g_patten.patten_start =
       (uchar *)malloc(g_patten.patten_num * g_patten.core_num * g_patten.asic_num * 0x5d0);
  if (g_patten.patten_start == (uchar *)0x0) {
    printf("%s[%d] malloc failed\n","patten_info_init",0x1d);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  memset(g_patten.patten_start,0,g_patten.patten_num * g_patten.core_num * g_patten.asic_num * 0x5d0
        );
  g_patten.is_nonce_match =
       (uchar *)malloc(g_patten.patten_num * g_patten.core_num * g_patten.asic_num);
  if (g_patten.is_nonce_match == (uchar *)0x0) {
    printf("%s[%d] malloc failed\n","patten_info_init",0x23);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  memset(g_patten.is_nonce_match,0,g_patten.patten_num * g_patten.core_num * g_patten.asic_num);
  g_patten.asic_recv_nonces = (int *)malloc(g_patten.asic_num << 2);
  if (g_patten.asic_recv_nonces == (int *)0x0) {
    printf("%s[%d] malloc failed\n","patten_info_init",0x29);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  memset(g_patten.asic_recv_nonces,0,g_patten.asic_num << 2);
  pthread_mutex_init((pthread_mutex_t *)&g_patten.patten_mutex,(pthread_mutexattr_t *)0x0);
  return;
}

