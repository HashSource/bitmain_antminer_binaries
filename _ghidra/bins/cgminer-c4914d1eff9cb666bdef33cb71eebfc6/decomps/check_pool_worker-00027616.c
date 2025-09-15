
/* WARNING: Unknown calling convention */

int check_pool_worker(void)

{
  FILE *pFVar1;
  FILE *pFile;
  FILE *pFile_1;
  int ret;
  int valid_pool;
  int pool;
  
  valid_pool = 0;
  ret = 0;
  for (pool = 0; pool < total_pools; pool = pool + 1) {
    if (*pools[pool]->rpc_url != '\0') {
      if (*pools[pool]->rpc_user == '\0') {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: Blank worker exists.\n","driver-btm-soc.c",0x1885,
                    "check_pool_worker");
          }
          fclose(pFVar1);
        }
      }
      else {
        valid_pool = valid_pool + 1;
      }
    }
  }
  if (valid_pool == 0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: No valid pools, please configure them first!\n","driver-btm-soc.c"
                ,0x188c,"check_pool_worker");
      }
      fclose(pFVar1);
    }
    ret = -1;
  }
  return ret;
}

