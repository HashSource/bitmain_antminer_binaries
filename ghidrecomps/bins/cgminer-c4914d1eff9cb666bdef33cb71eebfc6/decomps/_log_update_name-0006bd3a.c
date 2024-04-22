
int _log_update_name(_log_ctx *ctx,char *prefix,char *path,char *ts)

{
  uint uVar1;
  FILE *pFVar2;
  int iVar3;
  char *ts_local;
  char *path_local;
  char *prefix_local;
  _log_ctx *ctx_local;
  char cmd [4096];
  FILE *pFile;
  FILE *pFile_2;
  FILE *pFile_1;
  int ret;
  
  uVar1 = snprintf(cmd,0x1000,"/usr/bin/updatename.sh %s %s %s %s %s %s",ctx->tgt_dir,ctx->path,
                   ctx->ts,prefix,path,ts);
  if ((uVar1 == 0xffffffff) || (0xfff < uVar1)) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: too large command LOGUPDATENAME\n","log.c",0x62,"_log_update_name"
               );
      }
      fclose(pFVar2);
    }
    iVar3 = -1;
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: _log_update_name\n","log.c",0x65,"_log_update_name");
      }
      fclose(pFVar2);
    }
    iVar3 = my_system(cmd);
    if ((iVar3 != 0) && (3 < log_level)) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: my_system returned failed %d on LOGUPDATENAME\n","log.c",0x69,
                "_log_update_name",iVar3);
      }
      fclose(pFVar2);
    }
  }
  return iVar3;
}

