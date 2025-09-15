
/* WARNING: Removing unreachable block (ram,0x000158a4) */

void * mining_mode(void *args)

{
  int iVar1;
  void *args_local;
  char line [4096];
  uint64_t i;
  runtime_base_t *runtime;
  
  puts("SILENTARMY mining mode ready");
  fflush(stdout);
  do {
    do {
      usleep(100000);
      iVar1 = read_last_line(line,0x1000,1);
    } while (iVar1 == 0);
    pthread_mutex_lock((pthread_mutex_t *)&g_work_info.work_info_mutex);
    mining_parse_job(line,g_work_info.target,0x20,g_work_info.job_id,0x100,g_work_info.header,0x8c,
                     &g_work_info.fixed_nonce_bytes);
    user_send_work((runtime_base_t *)args,g_work_info.header,0,0);
    pthread_mutex_unlock((pthread_mutex_t *)&g_work_info.work_info_mutex);
  } while( true );
}

