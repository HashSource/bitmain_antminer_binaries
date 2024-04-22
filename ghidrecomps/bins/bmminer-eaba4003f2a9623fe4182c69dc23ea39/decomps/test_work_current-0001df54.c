
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool test_work_current(work *work)

{
  byte bVar1;
  _Bool _Var2;
  int iVar3;
  pool *ppVar4;
  pool *ppVar5;
  uchar *puVar6;
  undefined1 *puVar7;
  pool *ppVar8;
  work *work_local;
  char tmp42 [2048];
  uint height;
  char hexstr [68];
  uchar bedata [32];
  uchar cb_height_sz;
  uchar *bin_height;
  pool *pool;
  _Bool ret;
  
  ppVar5 = work->pool;
  ret = true;
  puVar6 = ppVar5->coinbase;
  bVar1 = puVar6[0x2a];
  height = 0;
  if (work->mandatory == false) {
    swap256(bedata,work->data + 4);
    __bin2hex(hexstr,bedata,0x20);
    if (bVar1 < 5) {
      _cg_memcpy(&height,puVar6 + 0x2b,(uint)bVar1,"cgminer.c","test_work_current",0x15b0);
      height = height - 1;
    }
    _cg_wlock(&ppVar5->data_lock,"cgminer.c","test_work_current",0x15b5);
    if ((ppVar5->swork).clean != false) {
      (ppVar5->swork).clean = false;
      work->longpoll = true;
    }
    _cg_wunlock(&ppVar5->data_lock,"cgminer.c","test_work_current",0x15bd);
    _Var2 = block_exists(hexstr,bedata,work);
    if (_Var2) {
      iVar3 = memcmp(ppVar5->prev_block,bedata,0x20);
      if (iVar3 != 0) {
        iVar3 = memcmp(bedata,current_block,0x20);
        if (iVar3 == 0) {
          if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
            snprintf(tmp42,0x800,"Pool %d now up to date at height %d",ppVar5->pool_no,height);
            _applog(6,tmp42,false);
          }
          _cg_memcpy(ppVar5->prev_block,bedata,0x20,"cgminer.c","test_work_current",0x15f7);
        }
        else {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"Stale data from pool %d at height %d",ppVar5->pool_no,height);
            _applog(7,tmp42,false);
          }
          ret = false;
        }
      }
      if (work->longpoll != false) {
        work_block = work_block + 1;
        work->work_block = work_block;
        _Var2 = shared_strategy();
        if ((_Var2) || (ppVar8 = work->pool, ppVar4 = current_pool(), ppVar8 == ppVar4)) {
          if (work->stratum == false) {
            if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
              if (work->gbt == false) {
                puVar7 = &DAT_00071100;
              }
              else {
                puVar7 = &DAT_000731e0;
              }
              snprintf(tmp42,0x800,"%sLONGPOLL from pool %d requested work restart",puVar7,
                       work->pool->pool_no);
              _applog(5,tmp42,false);
            }
          }
          else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"Stratum from pool %d requested work restart",ppVar5->pool_no);
            _applog(5,tmp42,false);
          }
          restart_threads();
        }
      }
    }
    else {
      _cg_memcpy(ppVar5->prev_block,bedata,0x20,"cgminer.c","test_work_current",0x15c5);
      if (new_blocks == 1) {
        ret = false;
      }
      else {
        work_block = work_block + 1;
        work->work_block = work_block;
        if (work->longpoll == false) {
          if ((have_longpoll == false) || (ppVar5->gbt_solo == true)) {
            if ((ppVar5->gbt_solo != true) &&
               (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
              tmp42[0] = s_New_block_detected_on_network_0007324c[0];
              tmp42[1] = s_New_block_detected_on_network_0007324c[1];
              tmp42[2] = s_New_block_detected_on_network_0007324c[2];
              tmp42[3] = s_New_block_detected_on_network_0007324c[3];
              tmp42[4] = s_New_block_detected_on_network_0007324c[4];
              tmp42[5] = s_New_block_detected_on_network_0007324c[5];
              tmp42[6] = s_New_block_detected_on_network_0007324c[6];
              tmp42[7] = s_New_block_detected_on_network_0007324c[7];
              tmp42[8] = s_New_block_detected_on_network_0007324c[8];
              tmp42[9] = s_New_block_detected_on_network_0007324c[9];
              tmp42[10] = s_New_block_detected_on_network_0007324c[10];
              tmp42[11] = s_New_block_detected_on_network_0007324c[11];
              tmp42[12] = s_New_block_detected_on_network_0007324c[12];
              tmp42[13] = s_New_block_detected_on_network_0007324c[13];
              tmp42[14] = s_New_block_detected_on_network_0007324c[14];
              tmp42[15] = s_New_block_detected_on_network_0007324c[15];
              tmp42[16] = s_New_block_detected_on_network_0007324c[16];
              tmp42[17] = s_New_block_detected_on_network_0007324c[17];
              tmp42[18] = s_New_block_detected_on_network_0007324c[18];
              tmp42[19] = s_New_block_detected_on_network_0007324c[19];
              tmp42[20] = s_New_block_detected_on_network_0007324c[20];
              tmp42[21] = s_New_block_detected_on_network_0007324c[21];
              tmp42[22] = s_New_block_detected_on_network_0007324c[22];
              tmp42[23] = s_New_block_detected_on_network_0007324c[23];
              tmp42[24] = s_New_block_detected_on_network_0007324c[24];
              tmp42[25] = s_New_block_detected_on_network_0007324c[25];
              tmp42[26] = s_New_block_detected_on_network_0007324c[26];
              tmp42[27] = s_New_block_detected_on_network_0007324c[27];
              tmp42[28] = (char)(short)ram0x00073268;
              tmp42[29] = (char)((ushort)(short)ram0x00073268 >> 8);
              _applog(5,tmp42,false);
            }
          }
          else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            tmp42[0] = s_New_block_detected_on_network_be_00073214[0];
            tmp42[1] = s_New_block_detected_on_network_be_00073214[1];
            tmp42[2] = s_New_block_detected_on_network_be_00073214[2];
            tmp42[3] = s_New_block_detected_on_network_be_00073214[3];
            tmp42[4] = s_New_block_detected_on_network_be_00073214[4];
            tmp42[5] = s_New_block_detected_on_network_be_00073214[5];
            tmp42[6] = s_New_block_detected_on_network_be_00073214[6];
            tmp42[7] = s_New_block_detected_on_network_be_00073214[7];
            tmp42[8] = s_New_block_detected_on_network_be_00073214[8];
            tmp42[9] = s_New_block_detected_on_network_be_00073214[9];
            tmp42[10] = s_New_block_detected_on_network_be_00073214[10];
            tmp42[11] = s_New_block_detected_on_network_be_00073214[11];
            tmp42[12] = s_New_block_detected_on_network_be_00073214[12];
            tmp42[13] = s_New_block_detected_on_network_be_00073214[13];
            tmp42[14] = s_New_block_detected_on_network_be_00073214[14];
            tmp42[15] = s_New_block_detected_on_network_be_00073214[15];
            tmp42[16] = s_New_block_detected_on_network_be_00073214[16];
            tmp42[17] = s_New_block_detected_on_network_be_00073214[17];
            tmp42[18] = s_New_block_detected_on_network_be_00073214[18];
            tmp42[19] = s_New_block_detected_on_network_be_00073214[19];
            tmp42[20] = s_New_block_detected_on_network_be_00073214[20];
            tmp42[21] = s_New_block_detected_on_network_be_00073214[21];
            tmp42[22] = s_New_block_detected_on_network_be_00073214[22];
            tmp42[23] = s_New_block_detected_on_network_be_00073214[23];
            tmp42[24] = s_New_block_detected_on_network_be_00073214[24];
            tmp42[25] = s_New_block_detected_on_network_be_00073214[25];
            tmp42[26] = s_New_block_detected_on_network_be_00073214[26];
            tmp42[27] = s_New_block_detected_on_network_be_00073214[27];
            tmp42[28] = s_New_block_detected_on_network_be_00073214[28];
            tmp42[29] = s_New_block_detected_on_network_be_00073214[29];
            tmp42[30] = s_New_block_detected_on_network_be_00073214[30];
            tmp42[31] = s_New_block_detected_on_network_be_00073214[31];
            tmp42[32] = s_New_block_detected_on_network_be_00073214[32];
            tmp42[33] = s_New_block_detected_on_network_be_00073214[33];
            tmp42[34] = s_New_block_detected_on_network_be_00073214[34];
            tmp42[35] = s_New_block_detected_on_network_be_00073214[35];
            tmp42[36] = s_New_block_detected_on_network_be_00073214[36];
            tmp42[37] = s_New_block_detected_on_network_be_00073214[37];
            tmp42[38] = s_New_block_detected_on_network_be_00073214[38];
            tmp42[39] = s_New_block_detected_on_network_be_00073214[39];
            tmp42[40] = s_New_block_detected_on_network_be_00073214[40];
            tmp42[41] = s_New_block_detected_on_network_be_00073214[41];
            tmp42[42] = s_New_block_detected_on_network_be_00073214[42];
            tmp42[43] = s_New_block_detected_on_network_be_00073214[43];
            tmp42[44] = s_New_block_detected_on_network_be_00073214[44];
            tmp42[45] = s_New_block_detected_on_network_be_00073214[45];
            tmp42[46] = s_New_block_detected_on_network_be_00073214[46];
            tmp42[47] = s_New_block_detected_on_network_be_00073214[47];
            tmp42[48] = s_New_block_detected_on_network_be_00073214[48];
            tmp42[49] = s_New_block_detected_on_network_be_00073214[49];
            tmp42[50] = s_New_block_detected_on_network_be_00073214[50];
            tmp42[51] = s_New_block_detected_on_network_be_00073214[51];
            tmp42._52_2_ = (undefined2)ram0x00073248;
            tmp42[54] = (char)((uint)ram0x00073248 >> 0x10);
            _applog(5,tmp42,false);
          }
        }
        else if (work->stratum == false) {
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            if (work->gbt == false) {
              puVar7 = &DAT_00071100;
            }
            else {
              puVar7 = &DAT_000731e0;
            }
            snprintf(tmp42,0x800,"%sLONGPOLL from pool %d detected new block",puVar7,
                     work->pool->pool_no);
            _applog(5,tmp42,false);
          }
        }
        else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"Stratum from pool %d detected new block at height %d",
                   ppVar5->pool_no,height);
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

