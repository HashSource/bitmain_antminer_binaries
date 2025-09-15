
int log_rotate(_log_ctx *ctx)

{
  uint uVar1;
  FILE *pFVar2;
  int iVar3;
  _log_ctx *ctx_local;
  char cmd [4096];
  FILE *pFile;
  FILE *pFile_2;
  FILE *pFile_3;
  FILE *pFile_1;
  int ret;
  int debug;
  
  uVar1 = snprintf(cmd,0x1000,"/usr/bin/checksize.sh %d %s",0,ctx->tgt_dir);
  if ((uVar1 == 0xffffffff) || (0xfff < uVar1)) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: too large command LOGCHECKSIZE\n","log.c",0x78,"log_rotate");
      }
      fclose(pFVar2);
    }
    iVar3 = -1;
  }
  else {
    iVar3 = my_system(cmd);
    if ((iVar3 != 0) && (3 < log_level)) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: my_system returned failed %d on LOGCHECKSIZE\n","log.c",0x7e,
                "log_rotate",iVar3);
      }
      fclose(pFVar2);
    }
    uVar1 = snprintf(cmd,0x1000,"/usr/bin/rotate.sh %d %d %s %s %s %s %s",0,ctx->need_clear,
                     ctx->tgt_dir,ctx->src_dir,ctx->path,ctx->ts,ctx->prefix);
    if ((uVar1 == 0xffffffff) || (0xfff < uVar1)) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: too large command LOGROTATE\n","log.c",0x84,"log_rotate");
        }
        fclose(pFVar2);
      }
      iVar3 = -1;
    }
    else {
      iVar3 = my_system(cmd);
      if ((iVar3 != 0) && (3 < log_level)) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: my_system returned failed %d on LOGROTATE\n","log.c",0x8a,
                  "log_rotate",iVar3);
        }
        fclose(pFVar2);
      }
    }
  }
  return iVar3;
}

