
int _log_remount(_log_ctx *ctx)

{
  FILE *pFVar1;
  uint uVar2;
  int iVar3;
  _log_ctx *ctx_local;
  char cmd [1024];
  FILE *pFile_1;
  FILE *pFile_2;
  int ret;
  FILE *pFile;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: remount /nvdata\n","log.c",0xb2,"_log_remount");
    }
    fclose(pFVar1);
  }
  uVar2 = snprintf(cmd,0x400,
                   "exec 2>&1; remount () { mnt_point=/$1; umount -lf $mnt_point && mount -t jffs2 /dev/mtdblock5 $mnt_point; }; remount %s"
                   ,ctx->tgt_dir);
  if ((uVar2 == 0xffffffff) || (0x3ff < uVar2)) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: too large command LOG_REMOUNT\n","log.c",0xb6,"_log_remount");
      }
      fclose(pFVar1);
    }
    iVar3 = -1;
  }
  else {
    iVar3 = my_system(cmd);
    if ((iVar3 != 0) && (3 < log_level)) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: my_system returned failed %d on LOG_REMOUNT\n","log.c",0xbd,
                "_log_remount",iVar3);
      }
      fclose(pFVar1);
    }
  }
  return iVar3;
}

