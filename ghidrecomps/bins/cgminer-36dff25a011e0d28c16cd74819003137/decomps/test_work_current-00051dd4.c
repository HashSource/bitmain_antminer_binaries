
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool test_work_current(work *work)

{
  byte bVar1;
  uint uVar2;
  _Bool _Var3;
  __uint32_t _Var4;
  int iVar5;
  pool *ppVar6;
  pool *ppVar7;
  uchar *puVar8;
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
  
  ppVar7 = work->pool;
  ret = true;
  puVar8 = ppVar7->coinbase;
  bVar1 = puVar8[0x2a];
  height = 0;
  if (work->mandatory == false) {
    swap256(bedata,work->data + 4);
    __bin2hex(hexstr,bedata,0x20);
    if (bVar1 < 5) {
      _cg_memcpy(&height,puVar8 + 0x2b,(uint)bVar1,"cgminer.c","test_work_current",0x15f8);
      _Var4 = __uint32_identity(height);
      height = _Var4 - 1;
    }
    _cg_wlock(&ppVar7->data_lock,"cgminer.c","test_work_current",0x15fd);
    if ((ppVar7->swork).clean != false) {
      (ppVar7->swork).clean = false;
      work->longpoll = true;
    }
    _cg_wunlock(&ppVar7->data_lock,"cgminer.c","test_work_current",0x1605);
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
          _cg_memcpy(ppVar7->prev_block,bedata,0x20,"cgminer.c","test_work_current",0x163f);
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
        if ((_Var3) || (ppVar9 = work->pool, ppVar6 = current_pool(), ppVar9 == ppVar6)) {
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
            snprintf(tmp42,0x800,"Stratum from pool %d requested work restart",ppVar7->pool_no);
            _applog(5,tmp42,false);
          }
          restart_threads();
        }
      }
    }
    else {
      _cg_memcpy(ppVar7->prev_block,bedata,0x20,"cgminer.c","test_work_current",0x160d);
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
              tmp42[0] = s_New_block_detected_on_network_000a3e40[0];
              tmp42[1] = s_New_block_detected_on_network_000a3e40[1];
              tmp42[2] = s_New_block_detected_on_network_000a3e40[2];
              tmp42[3] = s_New_block_detected_on_network_000a3e40[3];
              tmp42[4] = s_New_block_detected_on_network_000a3e40[4];
              tmp42[5] = s_New_block_detected_on_network_000a3e40[5];
              tmp42[6] = s_New_block_detected_on_network_000a3e40[6];
              tmp42[7] = s_New_block_detected_on_network_000a3e40[7];
              tmp42[8] = s_New_block_detected_on_network_000a3e40[8];
              tmp42[9] = s_New_block_detected_on_network_000a3e40[9];
              tmp42[10] = s_New_block_detected_on_network_000a3e40[10];
              tmp42[11] = s_New_block_detected_on_network_000a3e40[11];
              tmp42[12] = s_New_block_detected_on_network_000a3e40[12];
              tmp42[13] = s_New_block_detected_on_network_000a3e40[13];
              tmp42[14] = s_New_block_detected_on_network_000a3e40[14];
              tmp42[15] = s_New_block_detected_on_network_000a3e40[15];
              tmp42[16] = s_New_block_detected_on_network_000a3e40[16];
              tmp42[17] = s_New_block_detected_on_network_000a3e40[17];
              tmp42[18] = s_New_block_detected_on_network_000a3e40[18];
              tmp42[19] = s_New_block_detected_on_network_000a3e40[19];
              tmp42[20] = s_New_block_detected_on_network_000a3e40[20];
              tmp42[21] = s_New_block_detected_on_network_000a3e40[21];
              tmp42[22] = s_New_block_detected_on_network_000a3e40[22];
              tmp42[23] = s_New_block_detected_on_network_000a3e40[23];
              tmp42[24] = s_New_block_detected_on_network_000a3e40[24];
              tmp42[25] = s_New_block_detected_on_network_000a3e40[25];
              tmp42[26] = s_New_block_detected_on_network_000a3e40[26];
              tmp42[27] = s_New_block_detected_on_network_000a3e40[27];
              tmp42[28] = (char)(short)ram0x000a3e5c;
              tmp42[29] = (char)((ushort)(short)ram0x000a3e5c >> 8);
              _applog(5,tmp42,false);
            }
          }
          else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            tmp42[0] = s_New_block_detected_on_network_be_000a3e08[0];
            tmp42[1] = s_New_block_detected_on_network_be_000a3e08[1];
            tmp42[2] = s_New_block_detected_on_network_be_000a3e08[2];
            tmp42[3] = s_New_block_detected_on_network_be_000a3e08[3];
            tmp42[4] = s_New_block_detected_on_network_be_000a3e08[4];
            tmp42[5] = s_New_block_detected_on_network_be_000a3e08[5];
            tmp42[6] = s_New_block_detected_on_network_be_000a3e08[6];
            tmp42[7] = s_New_block_detected_on_network_be_000a3e08[7];
            tmp42[8] = s_New_block_detected_on_network_be_000a3e08[8];
            tmp42[9] = s_New_block_detected_on_network_be_000a3e08[9];
            tmp42[10] = s_New_block_detected_on_network_be_000a3e08[10];
            tmp42[11] = s_New_block_detected_on_network_be_000a3e08[11];
            tmp42[12] = s_New_block_detected_on_network_be_000a3e08[12];
            tmp42[13] = s_New_block_detected_on_network_be_000a3e08[13];
            tmp42[14] = s_New_block_detected_on_network_be_000a3e08[14];
            tmp42[15] = s_New_block_detected_on_network_be_000a3e08[15];
            tmp42[16] = s_New_block_detected_on_network_be_000a3e08[16];
            tmp42[17] = s_New_block_detected_on_network_be_000a3e08[17];
            tmp42[18] = s_New_block_detected_on_network_be_000a3e08[18];
            tmp42[19] = s_New_block_detected_on_network_be_000a3e08[19];
            tmp42[20] = s_New_block_detected_on_network_be_000a3e08[20];
            tmp42[21] = s_New_block_detected_on_network_be_000a3e08[21];
            tmp42[22] = s_New_block_detected_on_network_be_000a3e08[22];
            tmp42[23] = s_New_block_detected_on_network_be_000a3e08[23];
            tmp42[24] = s_New_block_detected_on_network_be_000a3e08[24];
            tmp42[25] = s_New_block_detected_on_network_be_000a3e08[25];
            tmp42[26] = s_New_block_detected_on_network_be_000a3e08[26];
            tmp42[27] = s_New_block_detected_on_network_be_000a3e08[27];
            tmp42[28] = s_New_block_detected_on_network_be_000a3e08[28];
            tmp42[29] = s_New_block_detected_on_network_be_000a3e08[29];
            tmp42[30] = s_New_block_detected_on_network_be_000a3e08[30];
            tmp42[31] = s_New_block_detected_on_network_be_000a3e08[31];
            tmp42[32] = s_New_block_detected_on_network_be_000a3e08[32];
            tmp42[33] = s_New_block_detected_on_network_be_000a3e08[33];
            tmp42[34] = s_New_block_detected_on_network_be_000a3e08[34];
            tmp42[35] = s_New_block_detected_on_network_be_000a3e08[35];
            tmp42[36] = s_New_block_detected_on_network_be_000a3e08[36];
            tmp42[37] = s_New_block_detected_on_network_be_000a3e08[37];
            tmp42[38] = s_New_block_detected_on_network_be_000a3e08[38];
            tmp42[39] = s_New_block_detected_on_network_be_000a3e08[39];
            tmp42[40] = s_New_block_detected_on_network_be_000a3e08[40];
            tmp42[41] = s_New_block_detected_on_network_be_000a3e08[41];
            tmp42[42] = s_New_block_detected_on_network_be_000a3e08[42];
            tmp42[43] = s_New_block_detected_on_network_be_000a3e08[43];
            tmp42[44] = s_New_block_detected_on_network_be_000a3e08[44];
            tmp42[45] = s_New_block_detected_on_network_be_000a3e08[45];
            tmp42[46] = s_New_block_detected_on_network_be_000a3e08[46];
            tmp42[47] = s_New_block_detected_on_network_be_000a3e08[47];
            tmp42[48] = s_New_block_detected_on_network_be_000a3e08[48];
            tmp42[49] = s_New_block_detected_on_network_be_000a3e08[49];
            tmp42[50] = s_New_block_detected_on_network_be_000a3e08[50];
            tmp42[51] = s_New_block_detected_on_network_be_000a3e08[51];
            tmp42._52_2_ = (undefined2)ram0x000a3e3c;
            tmp42[54] = (char)((uint)ram0x000a3e3c >> 0x10);
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

