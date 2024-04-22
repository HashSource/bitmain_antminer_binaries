
/* WARNING: Unknown calling convention */

void log_init(void)

{
  int iVar1;
  pthread_t log_thread;
  time_t timer;
  FILE *pFile;
  tm *tm_info;
  _log_ctx *ctx;
  
  ctx = &log_ctx;
  if (log_ctx.path[0] == '\0') {
    time(&timer);
    tm_info = (tm *)localtime(&timer);
    strftime(ctx->path,0xf,"%Y-%m/%d",(tm *)tm_info);
    strftime(ctx->ts,10,"%H-%M-%S",(tm *)tm_info);
    ctx->need_clear = 1;
    ctx->src_dir = "/var/log";
    ctx->tgt_dir = "nvdata";
    ctx->prefix = "cglog_init";
    log_rotate(ctx);
    iVar1 = pthread_create(&log_thread,(pthread_attr_t *)0x0,log_thread_routine + 1,ctx);
    if (iVar1 != 0) {
      print_crt_time_to_file(log_file,1);
      pFile = (FILE *)fopen(log_file,"a+");
      if (pFile != (FILE *)0x0) {
        fprintf((FILE *)pFile,"Assert fail!! %s:%d: Failed to create log thread","log.c",0x101);
      }
      fclose((FILE *)pFile);
                    /* WARNING: Subroutine does not return */
      __assert_fail("0","log.c",0x101,"log_init");
    }
    pthread_detach(log_thread);
  }
  return;
}

