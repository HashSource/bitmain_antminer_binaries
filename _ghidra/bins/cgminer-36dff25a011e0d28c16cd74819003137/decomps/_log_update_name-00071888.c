
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
  
  uVar1 = snprintf(cmd,0x1000,
                   "exec 2>&1; update_name () { log_tgt_dir=/$1; path=$2; ts=$3; prefix=\"$4\"_; new_path=$5; new_ts=$6; old_file=$log_tgt_dir/$path/$prefix$ts.tar; new_file=$log_tgt_dir/$new_path/$prefix$new_ts.tar; echo \"old:$old_file new:$new_file\">/tmp/log_updatename.log;if [ ! -d $log_tgt_dir/$new_path ]; then mkdir -p $log_tgt_dir/$new_path; fi; if [ -f $old_file ]; then mv $old_file $new_file;fi; if [ \"`ls -A $log_tgt_dir/$path/ | wc -w`\" == \"0\" ];then rm -rf $log_tgt_dir/$path;fi; }; update_name %s %s %s %s %s %s"
                   ,ctx->tgt_dir,ctx->path,ctx->ts,prefix,path,ts);
  if ((uVar1 == 0xffffffff) || (0xfff < uVar1)) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: too large command LOGUPDATENAME\n","log.c",0x6a,"_log_update_name"
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
        fprintf(pFVar2,"%s:%d:%s: _log_update_name\n","log.c",0x6d,"_log_update_name");
      }
      fclose(pFVar2);
    }
    iVar3 = my_system(cmd);
    if ((iVar3 != 0) && (3 < log_level)) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: my_system returned failed %d on LOGUPDATENAME\n","log.c",0x71,
                "_log_update_name",iVar3);
      }
      fclose(pFVar2);
    }
  }
  return iVar3;
}

