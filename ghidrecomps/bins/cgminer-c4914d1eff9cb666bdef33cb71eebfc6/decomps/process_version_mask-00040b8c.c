
void process_version_mask(pool *pool,char *mask)

{
  uint32_t uVar1;
  FILE *__stream;
  char *mask_local;
  pool *pool_local;
  char tmp42 [2048];
  FILE *pFile;
  
  if (mask == (char *)0x0) {
    pool->support_ab = false;
    pool->version_num = 1;
  }
  else {
    uVar1 = strtol(mask,(char **)0x0,0x10);
    uVar1 = swab32(uVar1);
    pool->ab_mask = uVar1;
    uVar1 = real_mask(pool->ab_mask & 0xc000,2);
    pool->ab_mask = uVar1;
    if ((pool->ab_mask & 0xc000U) == 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"Pool %d rolling mask do not match!",pool->pool_no);
        _applog(5,tmp42,false);
      }
      pool->support_ab = false;
      pool->version_num = 1;
    }
    else {
      pool->support_ab = true;
      pool->version_num = 2;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d:%s: Pool %d Version num is %d\n","util.c",0x882,
                  "process_version_mask",pool->pool_no,pool->version_num);
        }
        fclose(__stream);
      }
    }
  }
  return;
}

