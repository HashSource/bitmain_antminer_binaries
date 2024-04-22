
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
    pthread_mutex_lock(DAT_0001590c);
    mining_parse_job(line,g_work_info.target,0x20,DAT_00015918,0x100,DAT_00015914,0x8c,DAT_00015910)
    ;
    user_send_work((runtime_base_t *)args,DAT_00015914,0,0);
    pthread_mutex_unlock(DAT_0001590c);
  } while( true );
}

