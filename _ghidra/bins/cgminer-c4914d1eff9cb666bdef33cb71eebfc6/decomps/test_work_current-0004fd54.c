
_Bool test_work_current(work *work)

{
  byte bVar1;
  undefined4 uVar2;
  _Bool _Var3;
  __uint32_t _Var4;
  int iVar5;
  pool *ppVar6;
  pool *ppVar7;
  uchar *puVar8;
  undefined1 *puVar9;
  pool *ppVar10;
  work *work_local;
  char tmp42 [2048];
  uint32_t height;
  char hexstr [68];
  uchar bedata [32];
  uint8_t cb_height_sz;
  uchar *bin_height;
  pool *pool;
  _Bool ret;
  
  ppVar7 = work->pool;
  ret = true;
  puVar8 = ppVar7->coinbase;
  bVar1 = puVar8[0x2a];
  height = 0;
  if (work->mandatory == false) {
    swap256(bedata,work->data + 4);
    __bin2hex(hexstr,bedata,0x20);
    if (bVar1 < 5) {
      _cg_memcpy(&height,puVar8 + 0x2b,(uint)bVar1,"cgminer.c","test_work_current",0x15fb);
      _Var4 = __uint32_identity(height);
      height = _Var4 - 1;
    }
    _cg_wlock(&ppVar7->data_lock,"cgminer.c","test_work_current",0x1600);
    if ((ppVar7->swork).clean != false) {
      (ppVar7->swork).clean = false;
      work->longpoll = true;
    }
    _cg_wunlock(&ppVar7->data_lock,"cgminer.c","test_work_current",0x1608);
    _Var3 = block_exists(hexstr,bedata,work);
    if (_Var3) {
      iVar5 = memcmp(ppVar7->prev_block,bedata,0x20);
      if (iVar5 != 0) {
        iVar5 = memcmp(bedata,current_block,0x20);
        if (iVar5 == 0) {
          if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
            snprintf(tmp42,0x800,"Pool %d now up to date at height %d",ppVar7->pool_no,height);
            _applog(6,tmp42,false);
          }
          _cg_memcpy(ppVar7->prev_block,bedata,0x20,"cgminer.c","test_work_current",0x1642);
        }
        else {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"Stale data from pool %d at height %d",ppVar7->pool_no,height);
            _applog(7,tmp42,false);
          }
          ret = false;
        }
      }
      if (work->longpoll != false) {
        work_block = work_block + 1;
        work->work_block = work_block;
        _Var3 = shared_strategy();
        if ((_Var3) || (ppVar10 = work->pool, ppVar6 = current_pool(), ppVar10 == ppVar6)) {
          if (work->stratum == false) {
            if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
              if (work->gbt == false) {
                puVar9 = &DAT_0008a828;
              }
              else {
                puVar9 = &DAT_0008ca18;
              }
              snprintf(tmp42,0x800,"%sLONGPOLL from pool %d requested work restart",puVar9,
                       work->pool->pool_no);
              _applog(5,tmp42,false);
            }
          }
          else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"Stratum from pool %d requested work restart",ppVar7->pool_no);
            _applog(5,tmp42,false);
          }
          restart_threads();
        }
      }
    }
    else {
      _cg_memcpy(ppVar7->prev_block,bedata,0x20,"cgminer.c","test_work_current",0x1610);
      uVar2 = tmp42._28_4_;
      if (new_blocks == 1) {
        ret = false;
      }
      else {
        work_block = work_block + 1;
        work->work_block = work_block;
        if (work->longpoll == false) {
          if ((have_longpoll == false) || (ppVar7->gbt_solo == true)) {
            if ((ppVar7->gbt_solo != true) &&
               (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
              builtin_strncpy(tmp42,"New block detected on network",0x1e);
              tmp42._30_2_ = SUB42(uVar2,2);
              _applog(5,tmp42,false);
            }
          }
          else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            builtin_strncpy(tmp42,"New block detected on network before pool notificati",0x34);
            tmp42[0x34] = 'o';
            tmp42[0x35] = 'n';
            tmp42[0x36] = '\0';
            _applog(5,tmp42,false);
          }
        }
        else if (work->stratum == false) {
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            if (work->gbt == false) {
              puVar9 = &DAT_0008a828;
            }
            else {
              puVar9 = &DAT_0008ca18;
            }
            snprintf(tmp42,0x800,"%sLONGPOLL from pool %d detected new block",puVar9,
                     work->pool->pool_no);
            _applog(5,tmp42,false);
          }
        }
        else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"Stratum from pool %d detected new block at height %d",
                   ppVar7->pool_no,height);
          _applog(5,tmp42,false);
        }
        restart_threads();
      }
    }
    work->longpoll = false;
  }
  else {
    ret = true;
  }
  return ret;
}

