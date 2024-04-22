
/* WARNING: Unknown calling convention */

void patten_info_init(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int one_patten_bin_len;
  
  memset(&g_patten,0,0x9c);
  uVar2 = s_pattern_00036c40._4_4_;
  puVar1 = DAT_00022f3c;
  g_patten.asic_num = app_conf->asic_num;
  g_patten.core_num = app_conf->core_num;
  g_patten.patten_num = app_conf->pattern_num;
  *DAT_00022f3c = s_pattern_00036c40._0_4_;
  puVar1[1] = uVar2;
  uVar2 = DAT_00036c4c;
  puVar1 = DAT_00022f40;
  *DAT_00022f40 = DAT_00036c48;
  puVar1[1] = uVar2;
  uVar2 = DAT_00036c54;
  puVar1 = DAT_00022f44;
  *DAT_00022f44 = DAT_00036c50;
  *(char *)(puVar1 + 1) = (char)uVar2;
  uVar2 = DAT_00036c5c;
  puVar1 = DAT_00022f48;
  *DAT_00022f48 = DAT_00036c58;
  *(char *)(puVar1 + 1) = (char)uVar2;
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
  pthread_mutex_init(DAT_00022f4c,(pthread_mutexattr_t *)0x0);
  return;
}

