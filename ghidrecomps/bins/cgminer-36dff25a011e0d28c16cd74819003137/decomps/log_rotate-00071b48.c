
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
  
  uVar1 = snprintf(cmd,0x1000,
                   "exec 2>&1; log_checksize () {     debug_mode=$1;     log_tgt_dir_name=$2;     log_tgt_dir=/$log_tgt_dir_name;     tmp_dir=/tmp/.tmp.$$;     selflog=/tmp/log_checknvdata.log;     echo \"start check /nvdata size: \" `date` > $selflog;     if [ $debug_mode -eq 0 ];     then         threshold1_percentage=75; threshold2_percentage=60;     else         threshold1_percentage=3; threshold2_percentage=3;     fi; nvdata_state=`df -k| grep $log_tgt_dir_name`; if [ \"$nvdata_state\" = \"\" ]; then     echo \"ERROR: can\'t find $log_tgt_dir\" >> $selflog; exit -1; fi; used=`echo $nvdata_state| awk \'{print $5}\'|sed \"s/%%//g\"`; used_blocks=`echo $nvdata_state | awk \'{print $3}\'`; total_blocks=`echo $nvdata_state | awk \'{print $2}\'`; threshold1=$((total_blocks*threshold1_percentage/100)); threshold2=$((total_blocks*threshold2_percentage/100)); echo \"used_blocks   =$used_blocks\" >> $selflog; echo \"threshold1    =$threshold1\" >> $selflog; echo \"threshold2    =$threshold2\" >> $selflog; echo \"total_blocks  =$total_blocks\" >> $selflog; mkdir $tmp_dir; cd $tmp_dir; if [ $used_blocks -gt $threshold1 ]; then     if [ $debug_mode -eq 0 ];     then         filelist=`find $log_tgt_dir -type f -name \"cglog_*\"| xargs ls -tr`;     else         filelist=`find $log_tgt_dir -type f -name \"test_log*\" | xargs ls -tr`;     fi;     echo $filelist >> $selflog;     if [ ! -z \"$filelist\" ];     then         for file in $filelist;         do             used_blocks=`df -k | grep $log_tgt_dir_name | awk \'{print $3}\'`;             if [ $used_blocks -lt $threshold2 ];             then                 echo \"$used_blocks < $threshold2\" >> $selflog; break;             else                 echo \"$used_blocks > $threshold2\" >> $selflog; cat /dev/null >$file;rm -f $file;           fi;         done;     else         echo \"ERROR: no log file found\" >> $selflog;     fi; else     echo \"enough free space ($((100-used))%% left). do nothing\" >> $selflog; fi; cd $log_tgt_dir; rm -rf $tmp_dir ; }; log_checksize %d %s"
                   ,0,ctx->tgt_dir);
  if ((uVar1 == 0xffffffff) || (0xfff < uVar1)) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: too large command LOGCHECKSIZE\n","log.c",0x80,"log_rotate");
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
        fprintf(pFVar2,"%s:%d:%s: my_system returned failed %d on LOGCHECKSIZE\n","log.c",0x86,
                "log_rotate",iVar3);
      }
      fclose(pFVar2);
    }
    uVar1 = snprintf(cmd,0x1000,
                     "exec 2>&1; log_rotate () {     debug_mode=$1;     need_clear=$2;     log_tgt_dir_name=$3;     log_src_dir=$4;     path=$5;     ts=$6;     prefix=\"$7\"_;     log_bak_dir=/tmp/var.log.bak;     log_tgt_dir=/$log_tgt_dir_name;     selflog=/tmp/log_rotate.log;     if [ $debug_mode -eq 0 ];     then         threshold1_percentage=75; threshold2_percentage=60;     else         threshold1_percentage=15; threshold2_percentage=10;     fi; echo \"start bakcup logs: \" `date` > $selflog; cglog_archieve_file=$log_tgt_dir/$path/$prefix$ts.tar; rm -rf $log_bak_dir; mkdir -p $log_bak_dir; dmesg > $log_src_dir/dmesg.log; root_state=`df -k| grep root`; if [ \"$root_state\" = \"\" ]; then     echo \"ERROR: can\'t find root\" >> $selflog; exit -1; fi; used_blocks=`echo $root_state | awk \'{print $3}\'`; total_blocks=`echo $root_state | awk \'{print $2}\'`; threshold1=$((total_blocks*threshold1_percentage/100)); if [ $used_blocks -gt $threshold1 ] || [ $need_clear -eq 1 ]; then     echo \"used_blocks=$used_blocks > threshold1=$threshold1, total_blocks=$total_blocks\" >> $selflog; echo \"clear $log_src_dir\" >> $selflog; cd $log_bak_dir; mv $log_src_dir/* ./;if [ $need_clear -ne 1 ]; then cglog_archieve_file=$log_tgt_dir/$path/$prefix$ts\"_clearAT_\"`date \'+%%Y-%%m-%%d_%%H-%%M-%%S\'`.tar;fi;echo \"backup to $cglog_archieve_file\">>$selflog; else     echo \"used_blocks=$used_blocks <= threshold1=$threshold1, total_blocks=$total_blocks\" >> $selflog; echo \"only archieve logs to $cglog_archieve_file\" >> $selflog; cd $log_src_dir; fi; if [ ! -d $log_tgt_dir/$path ]; then     mkdir -p $log_tgt_dir/$path; fi; cat /dev/null > $cglog_archieve_file;tar cf $cglog_archieve_file * && rm $log_bak_dir/ -rf; }; log_rotate %d %d %s %s %s %s %s"
                     ,0,ctx->need_clear,ctx->tgt_dir,ctx->src_dir,ctx->path,ctx->ts,ctx->prefix);
    if ((uVar1 == 0xffffffff) || (0xfff < uVar1)) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: too large command LOGROTATE\n","log.c",0x8c,"log_rotate");
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
          fprintf(pFVar2,"%s:%d:%s: my_system returned failed %d on LOGROTATE\n","log.c",0x92,
                  "log_rotate",iVar3);
        }
        fclose(pFVar2);
      }
    }
  }
  return iVar3;
}

