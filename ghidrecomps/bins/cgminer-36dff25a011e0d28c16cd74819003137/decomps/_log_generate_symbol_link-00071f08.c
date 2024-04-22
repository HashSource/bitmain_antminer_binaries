
int _log_generate_symbol_link(_log_ctx *ctx,char *prefix,char *path)

{
  uint uVar1;
  FILE *pFVar2;
  int iVar3;
  char *path_local;
  char *prefix_local;
  _log_ctx *ctx_local;
  char cmd [4096];
  FILE *pFile;
  FILE *pFile_1;
  int ret;
  
  uVar1 = snprintf(cmd,0x1000,
                   "exec 2>&1; gen_symbol_link () { selflog=/tmp/log_symbol_link.log; log_tgt_dir=/$1; path=$2; ts=$3; prefix=\"$4\"_; new_path=$5; old_file=$log_tgt_dir/$path/$prefix$ts.tar; new_file=$log_tgt_dir/$new_path/LINK_$prefix$ts.tar; echo \"old:$old_file symbol link:$new_file\">$selflog;if [ ! -d $log_tgt_dir/$new_path ]; then mkdir -p $log_tgt_dir/$new_path; fi; if [ -f $old_file ]; then ln -sf $old_file $new_file;else echo \"old tarball not found\">>$selflog;fi; }; gen_symbol_link %s %s %s %s %s"
                   ,ctx->tgt_dir,ctx->path,ctx->ts,prefix,path);
  if ((uVar1 == 0xffffffff) || (0xfff < uVar1)) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: too large command LOG_SYMBOL_LINK\n","log.c",0xa0,
                "_log_generate_symbol_link");
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
        fprintf(pFVar2,"%s:%d:%s: my_system returned failed %d on LOG_SYMBOL_LINK\n","log.c",0xa7,
                "_log_generate_symbol_link",iVar3);
      }
      fclose(pFVar2);
    }
  }
  return iVar3;
}

