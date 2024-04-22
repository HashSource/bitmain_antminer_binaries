
void * bitmain_scanhash(void *arg)

{
  longlong lVar1;
  void *pvVar2;
  int iVar3;
  uint64_t uVar4;
  void *arg_local;
  uchar midstate [32];
  char tmp42 [2048];
  work *work;
  pool *c_pool;
  pool *pool_stratum2;
  pool *pool_stratum1;
  pool *pool_stratum0;
  uint version;
  uint work_id;
  uint chain_id;
  uint64_t nonce2;
  uint job_id;
  uint nonce3;
  uint b;
  uint a;
  bitmain_soc_info *info;
  cgpu_info *bitmain_soc;
  thr_info *thr;
  pool *pool;
  int i;
  
  bitmain_soc = *(cgpu_info **)((int)arg + 0x24);
  info = (bitmain_soc_info *)bitmain_soc->device_data;
  a = 0;
  b = 0;
  h = 0;
  thr = (thr_info *)arg;
  pthread_mutex_lock((pthread_mutex_t *)&nonce_mutex);
  _cg_rlock(&info->update_lock,"driver-btm-soc.c","bitmain_scanhash",0x2f8a);
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          if (nonce_read_out.nonce_num == 0) {
            _cg_runlock(&info->update_lock,"driver-btm-soc.c","bitmain_scanhash",0x2fe3);
            pthread_mutex_unlock((pthread_mutex_t *)&nonce_mutex);
            cgsleep_ms(1);
            if (((((uint)h | h._4_4_) != 0) && (opt_debug != false)) &&
               ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
              lVar1 = (h & 0xffffffff) * 0xffffffff;
              snprintf(tmp42,0x800,"%s: hashes %u ...\n","bitmain_scanhash",(int)lVar1,
                       (int)((ulonglong)lVar1 >> 0x20) - h._4_4_);
              _applog(7,tmp42,false);
            }
            lVar1 = (h & 0xffffffff) * 0xffffffff;
            pvVar2 = (void *)((int)((ulonglong)lVar1 >> 0x20) - h._4_4_);
            h = CONCAT44(pvVar2,(int)lVar1);
            return pvVar2;
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
                    (nonce_read_out.nonce_buffer[nonce_read_out.p_rd].header_version & 0xff0000) >>
                    8 | (nonce_read_out.nonce_buffer[nonce_read_out.p_rd].header_version & 0xff00)
                        << 8;
          midstate[0] = '\0';
          midstate[1] = '\0';
          midstate[2] = '\0';
          midstate[3] = '\0';
          midstate[4] = '\0';
          midstate[5] = '\0';
          midstate[6] = '\0';
          midstate[7] = '\0';
          midstate[8] = '\0';
          midstate[9] = '\0';
          midstate[10] = '\0';
          midstate[11] = '\0';
          midstate[12] = '\0';
          midstate[13] = '\0';
          midstate[14] = '\0';
          midstate[15] = '\0';
          midstate[16] = '\0';
          midstate[17] = '\0';
          midstate[18] = '\0';
          midstate[19] = '\0';
          midstate[20] = '\0';
          midstate[21] = '\0';
          midstate[22] = '\0';
          midstate[23] = '\0';
          midstate[24] = '\0';
          midstate[25] = '\0';
          midstate[26] = '\0';
          midstate[27] = '\0';
          midstate[28] = '\0';
          midstate[29] = '\0';
          midstate[30] = '\0';
          midstate[31] = '\0';
          for (i = 0; i < 0x20; i = i + 1) {
            iVar3 = i;
            if (i < 0) {
              iVar3 = i + 3;
            }
            midstate[(7 - (iVar3 >> 2)) * 4 + i % 4] =
                 nonce_read_out.nonce_buffer[nonce_read_out.p_rd].midstate[i];
          }
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,
                     "%s:chain_id:%d   job_id:0x%x   work_id:0x%x   nonce2:0x%llx   nonce3:0x%x   version:0x%x\n"
                     ,"bitmain_scanhash",chain_id,job_id,work_id);
            _applog(7,tmp42,false);
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
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              snprintf(tmp42,0x800,"%s: recv same nonce ...\n","bitmain_scanhash");
              _applog(7,tmp42,false);
            }
            inc_hw_errors(thr);
            dev->chain_hw[chain_id] = dev->chain_hw[chain_id] + 1;
          }
        }
        bitmain_scanhash::last_nonce3 = nonce3;
        bitmain_scanhash::last_workid = work_id;
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"%s: Chain ID J%d ...\n","bitmain_scanhash",chain_id + 1);
          _applog(7,tmp42,false);
        }
        if ((given_id - 2 <= job_id) || (job_id <= given_id)) break;
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"%s: job_id error ...\n","bitmain_scanhash");
          _applog(7,tmp42,false);
        }
        if (dev->chain_exist[chain_id] == 1) {
          inc_hw_errors(thr);
          dev->chain_hw[chain_id] = dev->chain_hw[chain_id] + 1;
        }
      }
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s: given_id:%d job_id:%d switch:%d  ...\n","bitmain_scanhash",
                 given_id,job_id,given_id - job_id);
        _applog(7,tmp42,false);
      }
      if (given_id - job_id != 1) break;
      pool = pool_stratum1;
LAB_00051048:
      c_pool = pools[pool->pool_no];
      get_work_by_nonce2(thr,&work,pool,c_pool,CONCAT44(nonce2._4_4_,(undefined4)nonce2),
                         (uint)pool->ntime,version);
      uVar4 = hashtest_submit(thr,work,nonce3,midstate,pool,
                              CONCAT44(nonce2._4_4_,(undefined4)nonce2),chain_id);
      h = uVar4 + h;
      _free_work(&work,"driver-btm-soc.c","bitmain_scanhash",0x2fe1);
    }
    if (given_id == job_id) {
      pool = pool_stratum0;
      goto LAB_00051048;
    }
    if (given_id - job_id == 2) {
      pool = pool_stratum2;
      goto LAB_00051048;
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: job_id non\'t found given=%d, job=%d...\n","bitmain_scanhash",
               given_id,job_id);
      _applog(7,tmp42,false);
    }
    if (dev->chain_exist[chain_id] == 1) {
      inc_hw_errors(thr);
      dev->chain_hw[chain_id] = dev->chain_hw[chain_id] + 1;
    }
  } while( true );
}

