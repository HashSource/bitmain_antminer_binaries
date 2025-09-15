
void * log_thread_routine(void *arg)

{
  int iVar1;
  uint uVar2;
  size_t __n;
  char *__s1;
  void *arg_local;
  char ts [20];
  char path [30];
  time_t tloc;
  FILE *pFile;
  int ret;
  tm *tm_info;
  _log_ctx *ctx;
  uint32_t counter;
  
  counter = 0;
  ctx = (_log_ctx *)arg;
  if (arg == (void *)0x0) {
    print_crt_time_to_file(log_file,1);
    pFile = (FILE *)fopen(log_file,"a+");
    if (pFile != (FILE *)0x0) {
      fprintf((FILE *)pFile,"Assert fail!! %s:%d: input arg wrong\n","log.c",0xb2);
    }
    fclose((FILE *)pFile);
                    /* WARNING: Subroutine does not return */
    __assert_fail("0","log.c",0xb2,"log_thread_routine");
  }
  *(undefined4 *)arg = 0;
  *(char **)((int)arg + 0x5c) = "cglog_sync";
  do {
    counter = counter + 1;
    if (counter % 0x1e == 0) {
      time(&tloc);
      tm_info = (tm *)localtime(&tloc);
      strftime(path,0xf,"%Y-%m/%d",(tm *)tm_info);
      strftime(ts,10,"%H-%M-%S",(tm *)tm_info);
      iVar1 = strncmp(ctx->path,"1970",4);
      if ((iVar1 == 0) && (0x1e13380 < tloc)) {
        ret = _log_update_name(ctx,"cglog_init",path,ts);
        uVar2 = _log_update_name(ctx,"cglog_sync",path,ts);
        ret = ret | uVar2;
        if (ret == 0) {
          strncpy(ctx->path,path,0x1e);
          strncpy(ctx->ts,ts,0x14);
          strcpy(ctx->last_path,ctx->path);
        }
      }
      if (ctx->last_path[0] == '\0') {
        strcpy(ctx->last_path,ctx->path);
      }
      else {
        __s1 = ctx->last_path;
        __n = strlen(path);
        iVar1 = strncmp(__s1,path,__n);
        if (iVar1 != 0) {
          ret = _log_generate_symbol_link(ctx,"cglog_sync",path);
          if (ret == 0) {
            strncpy(ctx->last_path,path,0x1e);
          }
        }
      }
      log_rotate(ctx);
    }
    sleep(1);
  } while( true );
}

