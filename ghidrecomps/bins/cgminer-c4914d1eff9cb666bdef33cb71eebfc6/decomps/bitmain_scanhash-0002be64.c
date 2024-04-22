
void * bitmain_scanhash(void *arg)

{
  _Bool _Var1;
  int iVar2;
  uint uVar3;
  uint64_t uVar4;
  void *arg_local;
  uint8_t midstate [32];
  work *work;
  FILE *pFile_5;
  pool *c_pool;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  pool *pool_stratum2;
  pool *pool_stratum1;
  pool *pool_stratum0;
  FILE *pFile;
  uint32_t version;
  uint32_t work_id;
  uint32_t chain_id;
  uint64_t nonce2;
  uint32_t job_id;
  uint32_t nonce3;
  FILE *pFile_6;
  bitmain_soc_info *info;
  cgpu_info *bitmain_soc;
  thr_info *thr;
  pool *pool;
  int i;
  
  bitmain_soc = *(cgpu_info **)((int)arg + 0x24);
  info = (bitmain_soc_info *)bitmain_soc->device_data;
  h = 0;
  thr = (thr_info *)arg;
  pthread_mutex_lock((pthread_mutex_t *)&nonce_mutex);
  _cg_rlock(&info->update_lock,"driver-btm-soc.c","bitmain_scanhash",0x1dbe);
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          if (nonce_read_out.nonce_num == 0) {
            _cg_runlock(&info->update_lock,"driver-btm-soc.c","bitmain_scanhash",0x1e17);
            pthread_mutex_unlock((pthread_mutex_t *)&nonce_mutex);
            cgsleep_ms(1);
            if ((((uint)h | h._4_4_) != 0) && (4 < log_level)) {
              print_crt_time_to_file(log_file,4);
              pFile_6 = (FILE *)fopen(log_file,"a+");
              if (pFile_6 != (FILE *)0x0) {
                fprintf((FILE *)pFile_6,"%s:%d:%s: hashes %llu ...\n","driver-btm-soc.c",0x1e1c,
                        "bitmain_scanhash");
              }
              fclose((FILE *)pFile_6);
            }
            h = CONCAT44((((uint)h & 0xfffffffe) - h._4_4_) +
                         (uint)((uint)h * -0x80000000 < (uint)h) * -2 +
                         (uint)CARRY4((uint)h * 0x7fffffff,(uint)h * 0x7fffffff) +
                         (uint)CARRY4((uint)h * -2,(uint)h),-(uint)h);
            return (void *)0x0;
          }
          nonce3 = nonce_read_out.nonce_buffer[nonce_read_out.p_rd].nonce3;
          job_id = nonce_read_out.nonce_buffer[nonce_read_out.p_rd].job_id;
          nonce2._0_4_ = *(undefined4 *)&nonce_read_out.nonce_buffer[nonce_read_out.p_rd].nonce2;
          nonce2._4_4_ = *(undefined4 *)
                          ((int)&nonce_read_out.nonce_buffer[nonce_read_out.p_rd].nonce2 + 4);
          chain_id = nonce_read_out.nonce_buffer[nonce_read_out.p_rd].chain_num;
          work_id = nonce_read_out.nonce_buffer[nonce_read_out.p_rd].work_id;
          version = nonce_read_out.nonce_buffer[nonce_read_out.p_rd].header_version << 0x18 |
                    nonce_read_out.nonce_buffer[nonce_read_out.p_rd].header_version >> 0x18 |
                    nonce_read_out.nonce_buffer[nonce_read_out.p_rd].header_version >> 8 & 0xff00 |
                    (nonce_read_out.nonce_buffer[nonce_read_out.p_rd].header_version & 0xff00) << 8;
          memset(midstate,0,0x20);
          for (i = 0; i < 0x20; i = i + 1) {
            iVar2 = i + 3;
            if (-1 < i) {
              iVar2 = i;
            }
            uVar3 = i & 3;
            if (i < 1) {
              uVar3 = -(-i & 3U);
            }
            midstate[(7 - (iVar2 >> 2)) * 4 + uVar3] =
                 nonce_read_out.nonce_buffer[nonce_read_out.p_rd].midstate[i];
          }
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFile = (FILE *)fopen(log_file,"a+");
            if (pFile != (FILE *)0x0) {
              fprintf((FILE *)pFile,
                      "%s:%d:%s: chain_id:%d   job_id:0x%x   work_id:0x%x   nonce2:0x%llx   nonce3:0x%x   version:0x%x\n"
                      ,"driver-btm-soc.c",0x1dcc,"bitmain_scanhash",chain_id,job_id,work_id,
                      (undefined4)nonce2,nonce2._4_4_,nonce3,version);
            }
            fclose((FILE *)pFile);
          }
          pool_stratum0 = &info->pool0;
          pool_stratum1 = &info->pool1;
          pool_stratum2 = &info->pool2;
          if (nonce_read_out.p_rd < 0x1fe) {
            nonce_read_out.p_rd = nonce_read_out.p_rd + 1;
          }
          else {
            nonce_read_out.p_rd = 0;
          }
          nonce_read_out.nonce_num = nonce_read_out.nonce_num - 1;
          if ((nonce3 != bitmain_scanhash::last_nonce3) ||
             (work_id != bitmain_scanhash::last_workid)) break;
          if (dev->chain_exist[chain_id] == 1) {
            if (4 < log_level) {
              print_crt_time_to_file(log_file,4);
              pFile_1 = (FILE *)fopen(log_file,"a+");
              if (pFile_1 != (FILE *)0x0) {
                fprintf((FILE *)pFile_1,"%s:%d:%s: recv same nonce ...\n","driver-btm-soc.c",0x1de8,
                        "bitmain_scanhash");
              }
              fclose((FILE *)pFile_1);
            }
            inc_hw_errors(thr);
            _Var1 = is_re_open_core_now();
            if (!_Var1) {
              dev->chain_hw[chain_id] = dev->chain_hw[chain_id] + 1;
            }
          }
        }
        bitmain_scanhash::last_nonce3 = nonce3;
        bitmain_scanhash::last_workid = work_id;
        if (4 < log_level) {
          print_crt_time_to_file(log_file,4);
          pFile_2 = (FILE *)fopen(log_file,"a+");
          if (pFile_2 != (FILE *)0x0) {
            fprintf((FILE *)pFile_2,"%s:%d:%s: Chain ID J%d ...\n","driver-btm-soc.c",0x1df0,
                    "bitmain_scanhash",chain_id + 1);
          }
          fclose((FILE *)pFile_2);
        }
        if ((given_id - 2 <= job_id) || (job_id <= given_id)) break;
        if (4 < log_level) {
          print_crt_time_to_file(log_file,4);
          pFile_3 = (FILE *)fopen(log_file,"a+");
          if (pFile_3 != (FILE *)0x0) {
            fprintf((FILE *)pFile_3,"%s:%d:%s: job_id error ...\n","driver-btm-soc.c",0x1df3,
                    "bitmain_scanhash");
          }
          fclose((FILE *)pFile_3);
        }
        if (dev->chain_exist[chain_id] == 1) {
          inc_hw_errors(thr);
          dev->chain_hw[chain_id] = dev->chain_hw[chain_id] + 1;
        }
      }
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFile_4 = (FILE *)fopen(log_file,"a+");
        if (pFile_4 != (FILE *)0x0) {
          fprintf((FILE *)pFile_4,"%s:%d:%s: given_id:%d job_id:%d switch:%d  ...\n",
                  "driver-btm-soc.c",0x1dfc,"bitmain_scanhash",given_id,job_id,given_id - job_id);
        }
        fclose((FILE *)pFile_4);
      }
      if (given_id - job_id != 1) break;
      pool = pool_stratum1;
LAB_0002c53c:
      c_pool = pools[pool->pool_no];
      get_work_by_nonce2(thr,&work,pool,c_pool,CONCAT44(nonce2._4_4_,(undefined4)nonce2),version);
      uVar4 = hashtest_submit(thr,work,nonce3,midstate,pool,
                              CONCAT44(nonce2._4_4_,(undefined4)nonce2),chain_id);
      h = uVar4 + h;
      _free_work(&work,"driver-btm-soc.c","bitmain_scanhash",0x1e15);
    }
    if (given_id == job_id) {
      pool = pool_stratum0;
      goto LAB_0002c53c;
    }
    if (given_id - job_id == 2) {
      pool = pool_stratum2;
      goto LAB_0002c53c;
    }
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFile_5 = (FILE *)fopen(log_file,"a+");
      if (pFile_5 != (FILE *)0x0) {
        fprintf((FILE *)pFile_5,"%s:%d:%s: job_id non\'t found given=%d, job=%d...\n",
                "driver-btm-soc.c",0x1e0a,"bitmain_scanhash",given_id,job_id);
      }
      fclose((FILE *)pFile_5);
    }
    if (dev->chain_exist[chain_id] == 1) {
      inc_hw_errors(thr);
      dev->chain_hw[chain_id] = dev->chain_hw[chain_id] + 1;
    }
  } while( true );
}

