
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool test_work_current(work *work)

{
  byte bVar1;
  _Bool _Var2;
  __uint32_t _Var3;
  int iVar4;
  pool *ppVar5;
  pool *ppVar6;
  uchar *puVar7;
  undefined1 *puVar8;
  pool *ppVar9;
  work *work_local;
  char tmp42 [2048];
  uint32_t height;
  char hexstr [68];
  uchar bedata [32];
  uint8_t cb_height_sz;
  uchar *bin_height;
  pool *pool;
  _Bool ret;
  
  ppVar6 = work->pool;
  ret = true;
  puVar7 = ppVar6->coinbase;
  bVar1 = puVar7[0x2a];
  height = 0;
  if (work->mandatory == false) {
    swap256(bedata,work->data + 4);
    __bin2hex(hexstr,bedata,0x20);
    if (bVar1 < 5) {
      _cg_memcpy(&height,puVar7 + 0x2b,(uint)bVar1,"cgminer.c","test_work_current",0x15fb);
      _Var3 = __uint32_identity(height);
      height = _Var3 - 1;
    }
    _cg_wlock(&ppVar6->data_lock,"cgminer.c","test_work_current",0x1600);
    if ((ppVar6->swork).clean != false) {
      (ppVar6->swork).clean = false;
      work->longpoll = true;
    }
    _cg_wunlock(&ppVar6->data_lock,"cgminer.c","test_work_current",0x1608);
    _Var2 = block_exists(hexstr,bedata,work);
    if (_Var2) {
      iVar4 = memcmp(ppVar6->prev_block,bedata,0x20);
      if (iVar4 != 0) {
        iVar4 = memcmp(bedata,current_block,0x20);
        if (iVar4 == 0) {
          if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
            snprintf(tmp42,0x800,"Pool %d now up to date at height %d",ppVar6->pool_no,height);
            _applog(6,tmp42,false);
          }
          _cg_memcpy(ppVar6->prev_block,bedata,0x20,"cgminer.c","test_work_current",0x1642);
        }
        else {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"Stale data from pool %d at height %d",ppVar6->pool_no,height);
            _applog(7,tmp42,false);
          }
          ret = false;
        }
      }
      if (work->longpoll != false) {
        work_block = work_block + 1;
        work->work_block = work_block;
        _Var2 = shared_strategy();
        if ((_Var2) || (ppVar9 = work->pool, ppVar5 = current_pool(), ppVar9 == ppVar5)) {
          if (work->stratum == false) {
            if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
              if (work->gbt == false) {
                puVar8 = &DAT_0008a828;
              }
              else {
                puVar8 = &DAT_0008ca18;
              }
              snprintf(tmp42,0x800,"%sLONGPOLL from pool %d requested work restart",puVar8,
                       work->pool->pool_no);
              _applog(5,tmp42,false);
            }
          }
          else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"Stratum from pool %d requested work restart",ppVar6->pool_no);
            _applog(5,tmp42,false);
          }
          restart_threads();
        }
      }
    }
    else {
      _cg_memcpy(ppVar6->prev_block,bedata,0x20,"cgminer.c","test_work_current",0x1610);
      if (new_blocks == 1) {
        ret = false;
      }
      else {
        work_block = work_block + 1;
        work->work_block = work_block;
        if (work->longpoll == false) {
          if ((have_longpoll == false) || (ppVar6->gbt_solo == true)) {
            if ((ppVar6->gbt_solo != true) &&
               (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
              tmp42[0] = s_New_block_detected_on_network_0008ca84[0];
              tmp42[1] = s_New_block_detected_on_network_0008ca84[1];
              tmp42[2] = s_New_block_detected_on_network_0008ca84[2];
              tmp42[3] = s_New_block_detected_on_network_0008ca84[3];
              tmp42[4] = s_New_block_detected_on_network_0008ca84[4];
              tmp42[5] = s_New_block_detected_on_network_0008ca84[5];
              tmp42[6] = s_New_block_detected_on_network_0008ca84[6];
              tmp42[7] = s_New_block_detected_on_network_0008ca84[7];
              tmp42[8] = s_New_block_detected_on_network_0008ca84[8];
              tmp42[9] = s_New_block_detected_on_network_0008ca84[9];
              tmp42[10] = s_New_block_detected_on_network_0008ca84[10];
              tmp42[11] = s_New_block_detected_on_network_0008ca84[11];
              tmp42[12] = s_New_block_detected_on_network_0008ca84[12];
              tmp42[13] = s_New_block_detected_on_network_0008ca84[13];
              tmp42[14] = s_New_block_detected_on_network_0008ca84[14];
              tmp42[15] = s_New_block_detected_on_network_0008ca84[15];
              tmp42[16] = s_New_block_detected_on_network_0008ca84[16];
              tmp42[17] = s_New_block_detected_on_network_0008ca84[17];
              tmp42[18] = s_New_block_detected_on_network_0008ca84[18];
              tmp42[19] = s_New_block_detected_on_network_0008ca84[19];
              tmp42[20] = s_New_block_detected_on_network_0008ca84[20];
              tmp42[21] = s_New_block_detected_on_network_0008ca84[21];
              tmp42[22] = s_New_block_detected_on_network_0008ca84[22];
              tmp42[23] = s_New_block_detected_on_network_0008ca84[23];
              tmp42[24] = s_New_block_detected_on_network_0008ca84[24];
              tmp42[25] = s_New_block_detected_on_network_0008ca84[25];
              tmp42[26] = s_New_block_detected_on_network_0008ca84[26];
              tmp42[27] = s_New_block_detected_on_network_0008ca84[27];
              tmp42[28] = (char)(short)ram0x0008caa0;
              tmp42[29] = (char)((ushort)(short)ram0x0008caa0 >> 8);
              _applog(5,tmp42,false);
            }
          }
          else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            tmp42[0] = s_New_block_detected_on_network_be_0008ca4c[0];
            tmp42[1] = s_New_block_detected_on_network_be_0008ca4c[1];
            tmp42[2] = s_New_block_detected_on_network_be_0008ca4c[2];
            tmp42[3] = s_New_block_detected_on_network_be_0008ca4c[3];
            tmp42[4] = s_New_block_detected_on_network_be_0008ca4c[4];
            tmp42[5] = s_New_block_detected_on_network_be_0008ca4c[5];
            tmp42[6] = s_New_block_detected_on_network_be_0008ca4c[6];
            tmp42[7] = s_New_block_detected_on_network_be_0008ca4c[7];
            tmp42[8] = s_New_block_detected_on_network_be_0008ca4c[8];
            tmp42[9] = s_New_block_detected_on_network_be_0008ca4c[9];
            tmp42[10] = s_New_block_detected_on_network_be_0008ca4c[10];
            tmp42[11] = s_New_block_detected_on_network_be_0008ca4c[11];
            tmp42[12] = s_New_block_detected_on_network_be_0008ca4c[12];
            tmp42[13] = s_New_block_detected_on_network_be_0008ca4c[13];
            tmp42[14] = s_New_block_detected_on_network_be_0008ca4c[14];
            tmp42[15] = s_New_block_detected_on_network_be_0008ca4c[15];
            tmp42[16] = s_New_block_detected_on_network_be_0008ca4c[16];
            tmp42[17] = s_New_block_detected_on_network_be_0008ca4c[17];
            tmp42[18] = s_New_block_detected_on_network_be_0008ca4c[18];
            tmp42[19] = s_New_block_detected_on_network_be_0008ca4c[19];
            tmp42[20] = s_New_block_detected_on_network_be_0008ca4c[20];
            tmp42[21] = s_New_block_detected_on_network_be_0008ca4c[21];
            tmp42[22] = s_New_block_detected_on_network_be_0008ca4c[22];
            tmp42[23] = s_New_block_detected_on_network_be_0008ca4c[23];
            tmp42[24] = s_New_block_detected_on_network_be_0008ca4c[24];
            tmp42[25] = s_New_block_detected_on_network_be_0008ca4c[25];
            tmp42[26] = s_New_block_detected_on_network_be_0008ca4c[26];
            tmp42[27] = s_New_block_detected_on_network_be_0008ca4c[27];
            tmp42[28] = s_New_block_detected_on_network_be_0008ca4c[28];
            tmp42[29] = s_New_block_detected_on_network_be_0008ca4c[29];
            tmp42[30] = s_New_block_detected_on_network_be_0008ca4c[30];
            tmp42[31] = s_New_block_detected_on_network_be_0008ca4c[31];
            tmp42[32] = s_New_block_detected_on_network_be_0008ca4c[32];
            tmp42[33] = s_New_block_detected_on_network_be_0008ca4c[33];
            tmp42[34] = s_New_block_detected_on_network_be_0008ca4c[34];
            tmp42[35] = s_New_block_detected_on_network_be_0008ca4c[35];
            tmp42[36] = s_New_block_detected_on_network_be_0008ca4c[36];
            tmp42[37] = s_New_block_detected_on_network_be_0008ca4c[37];
            tmp42[38] = s_New_block_detected_on_network_be_0008ca4c[38];
            tmp42[39] = s_New_block_detected_on_network_be_0008ca4c[39];
            tmp42[40] = s_New_block_detected_on_network_be_0008ca4c[40];
            tmp42[41] = s_New_block_detected_on_network_be_0008ca4c[41];
            tmp42[42] = s_New_block_detected_on_network_be_0008ca4c[42];
            tmp42[43] = s_New_block_detected_on_network_be_0008ca4c[43];
            tmp42[44] = s_New_block_detected_on_network_be_0008ca4c[44];
            tmp42[45] = s_New_block_detected_on_network_be_0008ca4c[45];
            tmp42[46] = s_New_block_detected_on_network_be_0008ca4c[46];
            tmp42[47] = s_New_block_detected_on_network_be_0008ca4c[47];
            tmp42[48] = s_New_block_detected_on_network_be_0008ca4c[48];
            tmp42[49] = s_New_block_detected_on_network_be_0008ca4c[49];
            tmp42[50] = s_New_block_detected_on_network_be_0008ca4c[50];
            tmp42[51] = s_New_block_detected_on_network_be_0008ca4c[51];
            tmp42._52_2_ = (undefined2)ram0x0008ca80;
            tmp42[54] = (char)((uint)ram0x0008ca80 >> 0x10);
            _applog(5,tmp42,false);
          }
        }
        else if (work->stratum == false) {
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            if (work->gbt == false) {
              puVar8 = &DAT_0008a828;
            }
            else {
              puVar8 = &DAT_0008ca18;
            }
            snprintf(tmp42,0x800,"%sLONGPOLL from pool %d detected new block",puVar8,
                     work->pool->pool_no);
            _applog(5,tmp42,false);
          }
        }
        else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"Stratum from pool %d detected new block at height %d",
                   ppVar6->pool_no,height);
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

