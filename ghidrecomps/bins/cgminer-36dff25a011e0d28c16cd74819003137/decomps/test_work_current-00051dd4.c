
_Bool test_work_current(work *work)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  _Bool _Var4;
  __uint32_t _Var5;
  int iVar6;
  pool *ppVar7;
  pool *ppVar8;
  uchar *puVar9;
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
  
  ppVar8 = work->pool;
  ret = true;
  puVar9 = ppVar8->coinbase;
  bVar1 = puVar9[0x2a];
  height = 0;
  if (work->mandatory == false) {
    swap256(bedata,work->data + 4);
    __bin2hex(hexstr,bedata,0x20);
    if (bVar1 < 5) {
      _cg_memcpy(&height,puVar9 + 0x2b,(uint)bVar1,"cgminer.c","test_work_current",0x15f8);
      _Var5 = __uint32_identity(height);
      height = _Var5 - 1;
    }
    _cg_wlock(&ppVar8->data_lock,"cgminer.c","test_work_current",0x15fd);
    if ((ppVar8->swork).clean != false) {
      (ppVar8->swork).clean = false;
      work->longpoll = true;
    }
    _cg_wunlock(&ppVar8->data_lock,"cgminer.c","test_work_current",0x1605);
    _Var4 = block_exists(hexstr,bedata,work);
    if (_Var4) {
      iVar6 = memcmp(ppVar8->prev_block,bedata,0x20);
      if (iVar6 != 0) {
        iVar6 = memcmp(bedata,current_block,0x20);
        if (iVar6 == 0) {
          if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
            snprintf(tmp42,0x800,"Pool %d now up to date at height %d",ppVar8->pool_no,height);
            _applog(6,tmp42,false);
          }
          _cg_memcpy(ppVar8->prev_block,bedata,0x20,"cgminer.c","test_work_current",0x163f);
        }
        else {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"Stale data from pool %d at height %d",ppVar8->pool_no,height);
            _applog(7,tmp42,false);
          }
          ret = false;
        }
      }
      if (work->longpoll != false) {
        work_block = work_block + 1;
        work->work_block = work_block;
        _Var4 = shared_strategy();
        if ((_Var4) || (ppVar10 = work->pool, ppVar7 = current_pool(), ppVar10 == ppVar7)) {
          if (work->stratum == false) {
            if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
              if (work->gbt == false) {
                uVar2 = 0x1bd4;
              }
              else {
                uVar2 = 0x3dd4;
              }
              snprintf(tmp42,0x800,"%sLONGPOLL from pool %d requested work restart",uVar2 | 0xa0000,
                       work->pool->pool_no);
              _applog(5,tmp42,false);
            }
          }
          else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"Stratum from pool %d requested work restart",ppVar8->pool_no);
            _applog(5,tmp42,false);
          }
          restart_threads();
        }
      }
    }
    else {
      _cg_memcpy(ppVar8->prev_block,bedata,0x20,"cgminer.c","test_work_current",0x160d);
      uVar3 = tmp42._28_4_;
      if (new_blocks == 1) {
        ret = false;
      }
      else {
        work_block = work_block + 1;
        work->work_block = work_block;
        if (work->longpoll == false) {
          if ((have_longpoll == false) || (ppVar8->gbt_solo == true)) {
            if ((ppVar8->gbt_solo != true) &&
               (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
              builtin_strncpy(tmp42,"New block detected on network",0x1e);
              tmp42._30_2_ = SUB42(uVar3,2);
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
              uVar2 = 0x1bd4;
            }
            else {
              uVar2 = 0x3dd4;
            }
            snprintf(tmp42,0x800,"%sLONGPOLL from pool %d detected new block",uVar2 | 0xa0000,
                     work->pool->pool_no);
            _applog(5,tmp42,false);
          }
        }
        else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"Stratum from pool %d detected new block at height %d",
                   ppVar8->pool_no,height);
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

