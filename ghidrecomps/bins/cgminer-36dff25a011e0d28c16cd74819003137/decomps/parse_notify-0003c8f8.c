
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool parse_notify(pool *pool,json_t *val)

{
  int iVar1;
  _Bool _Var2;
  json_t *json;
  size_t sVar3;
  json_t *pjVar4;
  size_t sVar5;
  uchar **ppuVar6;
  char *hexstr;
  uchar *puVar7;
  pool *ppVar8;
  uchar *src;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  bool bVar14;
  double dVar15;
  char *local_96c [4];
  char *local_95c;
  json_t *val_local;
  pool *pool_local;
  char tmp42 [2048];
  char header [228];
  char *cb;
  char *merkle;
  size_t alloc_len;
  size_t cb2_len;
  size_t cb1_len;
  _Bool clean;
  char *ntime;
  char *nbit;
  char *bbversion;
  char *coinbase2;
  char *coinbase1;
  char *prev_hash;
  char *job_id;
  int merkles;
  json_t *arr;
  uchar *cb2;
  uchar *cb1;
  int i;
  _Bool ret;
  
  ret = false;
  val_local = val;
  pool_local = pool;
  json = json_array_get(val,4);
  if (((json != (json_t *)0x0) && (json != (json_t *)0x0)) && (json->type == JSON_ARRAY)) {
    sVar3 = json_array_size(json);
    job_id = json_array_string(val_local,0);
    prev_hash = __json_array_string(val_local,1);
    coinbase1 = json_array_string(val_local,2);
    coinbase2 = json_array_string(val_local,3);
    bbversion = __json_array_string(val_local,5);
    nbit = __json_array_string(val_local,6);
    ntime = __json_array_string(val_local,7);
    pjVar4 = json_array_get(val_local,8);
    if ((pjVar4 == (json_t *)0x0) ||
       (pjVar4 = json_array_get(val_local,8), pjVar4->type != JSON_TRUE)) {
      clean = false;
    }
    else {
      clean = true;
    }
    _Var2 = _valid_ascii(job_id,"util.c","parse_notify",0x7d7);
    if ((((_Var2) && (_Var2 = _valid_hex(prev_hash,"util.c","parse_notify",0x7d7), _Var2)) &&
        ((_Var2 = _valid_hex(coinbase1,"util.c","parse_notify",0x7d7), _Var2 &&
         (((_Var2 = _valid_hex(coinbase2,"util.c","parse_notify",0x7d8), _Var2 &&
           (_Var2 = _valid_hex(bbversion,"util.c","parse_notify",0x7d8), _Var2)) &&
          (_Var2 = _valid_hex(nbit,"util.c","parse_notify",0x7d8), _Var2)))))) &&
       (_Var2 = _valid_hex(ntime,"util.c","parse_notify",0x7d9), _Var2)) {
      _cg_wlock(&pool_local->data_lock,"util.c","parse_notify",0x7e2);
      free((pool_local->swork).job_id);
      (pool_local->swork).job_id = job_id;
      snprintf(pool_local->prev_hash,0x41,"%s",prev_hash);
      sVar5 = strlen(coinbase1);
      cb1_len = sVar5 >> 1;
      sVar5 = strlen(coinbase2);
      cb2_len = sVar5 >> 1;
      snprintf(pool_local->bbversion,9,"%s",bbversion);
      snprintf(pool_local->nbit,9,"%s",nbit);
      snprintf(pool_local->ntime,9,"%s",ntime);
      (pool_local->swork).clean = clean;
      dVar15 = pool_local->next_diff;
      if (dVar15 != 0.0 && dVar15 < 0.0 == NAN(dVar15)) {
        uVar11 = *(undefined4 *)((int)&pool_local->next_diff + 4);
        *(undefined4 *)&pool_local->sdiff = *(undefined4 *)&pool_local->next_diff;
        *(undefined4 *)((int)&pool_local->sdiff + 4) = uVar11;
      }
      pool_local->coinbase_len = pool_local->n1_len + cb1_len + pool_local->n2size + cb2_len;
      uVar12 = pool_local->coinbase_len;
      pool_local->nonce2_offset = pool_local->n1_len + cb1_len;
      for (i = 0; i < pool_local->merkles; i = i + 1) {
        free((pool_local->swork).merkle_bin[i]);
      }
      if (sVar3 != 0) {
        ppuVar6 = (uchar **)
                  _cgrealloc((pool_local->swork).merkle_bin,sVar3 * 4 + 1,"util.c","parse_notify",
                             0x7f8);
        (pool_local->swork).merkle_bin = ppuVar6;
        for (i = 0; i < (int)sVar3; i = i + 1) {
          hexstr = json_array_string(json,i);
          ppuVar6 = (pool_local->swork).merkle_bin;
          puVar7 = (uchar *)_cgmalloc(0x20,"util.c","parse_notify",0x7fd);
          ppuVar6[i] = puVar7;
          if (((opt_protocol != false) && (opt_debug != false)) &&
             ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
            snprintf(tmp42,0x800,"merkle %d: %s",i);
            _applog(7,tmp42,false);
          }
          ret = hex2bin((pool_local->swork).merkle_bin[i],hexstr,0x20);
          free(hexstr);
          if (!ret) {
            if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
              tmp42[0] = s_Failed_to_convert_merkle_to_merk_0009f3a0[0];
              tmp42[1] = s_Failed_to_convert_merkle_to_merk_0009f3a0[1];
              tmp42[2] = s_Failed_to_convert_merkle_to_merk_0009f3a0[2];
              tmp42[3] = s_Failed_to_convert_merkle_to_merk_0009f3a0[3];
              tmp42[4] = s_Failed_to_convert_merkle_to_merk_0009f3a0[4];
              tmp42[5] = s_Failed_to_convert_merkle_to_merk_0009f3a0[5];
              tmp42[6] = s_Failed_to_convert_merkle_to_merk_0009f3a0[6];
              tmp42[7] = s_Failed_to_convert_merkle_to_merk_0009f3a0[7];
              tmp42[8] = s_Failed_to_convert_merkle_to_merk_0009f3a0[8];
              tmp42[9] = s_Failed_to_convert_merkle_to_merk_0009f3a0[9];
              tmp42[10] = s_Failed_to_convert_merkle_to_merk_0009f3a0[10];
              tmp42[11] = s_Failed_to_convert_merkle_to_merk_0009f3a0[11];
              tmp42[12] = s_Failed_to_convert_merkle_to_merk_0009f3a0[12];
              tmp42[13] = s_Failed_to_convert_merkle_to_merk_0009f3a0[13];
              tmp42[14] = s_Failed_to_convert_merkle_to_merk_0009f3a0[14];
              tmp42[15] = s_Failed_to_convert_merkle_to_merk_0009f3a0[15];
              tmp42[16] = s_Failed_to_convert_merkle_to_merk_0009f3a0[16];
              tmp42[17] = s_Failed_to_convert_merkle_to_merk_0009f3a0[17];
              tmp42[18] = s_Failed_to_convert_merkle_to_merk_0009f3a0[18];
              tmp42[19] = s_Failed_to_convert_merkle_to_merk_0009f3a0[19];
              tmp42[20] = s_Failed_to_convert_merkle_to_merk_0009f3a0[20];
              tmp42[21] = s_Failed_to_convert_merkle_to_merk_0009f3a0[21];
              tmp42[22] = s_Failed_to_convert_merkle_to_merk_0009f3a0[22];
              tmp42[23] = s_Failed_to_convert_merkle_to_merk_0009f3a0[23];
              tmp42[24] = s_Failed_to_convert_merkle_to_merk_0009f3a0[24];
              tmp42[25] = s_Failed_to_convert_merkle_to_merk_0009f3a0[25];
              tmp42[26] = s_Failed_to_convert_merkle_to_merk_0009f3a0[26];
              tmp42[27] = s_Failed_to_convert_merkle_to_merk_0009f3a0[27];
              tmp42[28] = s_Failed_to_convert_merkle_to_merk_0009f3a0[28];
              tmp42[29] = s_Failed_to_convert_merkle_to_merk_0009f3a0[29];
              tmp42[30] = s_Failed_to_convert_merkle_to_merk_0009f3a0[30];
              tmp42[31] = s_Failed_to_convert_merkle_to_merk_0009f3a0[31];
              tmp42[32] = s_Failed_to_convert_merkle_to_merk_0009f3a0[32];
              tmp42[33] = s_Failed_to_convert_merkle_to_merk_0009f3a0[33];
              tmp42[34] = s_Failed_to_convert_merkle_to_merk_0009f3a0[34];
              tmp42[35] = s_Failed_to_convert_merkle_to_merk_0009f3a0[35];
              tmp42[36] = s_Failed_to_convert_merkle_to_merk_0009f3a0[36];
              tmp42[37] = s_Failed_to_convert_merkle_to_merk_0009f3a0[37];
              tmp42[38] = s_Failed_to_convert_merkle_to_merk_0009f3a0[38];
              tmp42[39] = s_Failed_to_convert_merkle_to_merk_0009f3a0[39];
              tmp42[40] = s_Failed_to_convert_merkle_to_merk_0009f3a0[40];
              tmp42[41] = s_Failed_to_convert_merkle_to_merk_0009f3a0[41];
              tmp42[42] = s_Failed_to_convert_merkle_to_merk_0009f3a0[42];
              tmp42[43] = s_Failed_to_convert_merkle_to_merk_0009f3a0[43];
              tmp42[44] = s_Failed_to_convert_merkle_to_merk_0009f3a0[44];
              tmp42[45] = s_Failed_to_convert_merkle_to_merk_0009f3a0[45];
              tmp42[46] = s_Failed_to_convert_merkle_to_merk_0009f3a0[46];
              tmp42[47] = s_Failed_to_convert_merkle_to_merk_0009f3a0[47];
              tmp42[48] = s_Failed_to_convert_merkle_to_merk_0009f3a0[48];
              tmp42[49] = s_Failed_to_convert_merkle_to_merk_0009f3a0[49];
              tmp42[50] = s_Failed_to_convert_merkle_to_merk_0009f3a0[50];
              tmp42[51] = s_Failed_to_convert_merkle_to_merk_0009f3a0[51];
              tmp42._52_2_ = (undefined2)ram0x0009f3d4;
              tmp42[54] = (char)((uint)ram0x0009f3d4 >> 0x10);
              _applog(3,tmp42,false);
            }
            goto out_unlock;
          }
        }
      }
      pool_local->merkles = sVar3;
      if (pool_local->merkles < 2) {
        uVar9 = *(uint *)&pool_local->bad_work;
        iVar13 = *(int *)((int)&pool_local->bad_work + 4);
        *(uint *)&pool_local->bad_work = uVar9 + 1;
        *(uint *)((int)&pool_local->bad_work + 4) = iVar13 + (uint)(0xfffffffe < uVar9);
      }
      if (clean != false) {
        *(undefined4 *)&pool_local->nonce2 = 0;
        *(undefined4 *)((int)&pool_local->nonce2 + 4) = 0;
      }
      local_96c[1] = pool_local->ntime;
      local_96c[2] = pool_local->nbit;
      local_95c = workpadding;
      local_96c[3] = "00000000";
      local_96c[0] = blank_merkle;
      snprintf(header,0xe1,"%s%s%s%s%s%s%s",pool_local->bbversion);
      ret = hex2bin(pool_local->header_bin,header,0x70);
      if (ret) {
        iVar13 = -(cb1_len + 0xe & 0xfffffff8);
        cb1 = (uchar *)((int)&val_local + iVar13);
        ret = hex2bin(cb1,coinbase1,cb1_len);
        if (ret) {
          iVar1 = -(cb2_len + 0xe & 0xfffffff8);
          cb2 = (uchar *)((int)&val_local + iVar1 + iVar13);
          ret = hex2bin(cb2,coinbase2,cb2_len);
          if (ret) {
            free(pool_local->coinbase);
            *(undefined4 *)(tmp42 + iVar1 + iVar13 + -0x20) = 0x836;
            puVar7 = (uchar *)_cgcalloc(uVar12,1,"util.c","parse_notify",
                                        *(int *)(tmp42 + iVar1 + iVar13 + -0x20));
            pool_local->coinbase = puVar7;
            puVar7 = pool_local->coinbase;
            *(undefined4 *)((int)local_96c + iVar1 + iVar13) = 0x837;
            *(char **)(tmp42 + iVar1 + iVar13 + -0x20) = "parse_notify";
            _cg_memcpy(puVar7,cb1,cb1_len,"util.c",*(char **)(tmp42 + iVar1 + iVar13 + -0x20),
                       *(int *)((int)local_96c + iVar1 + iVar13));
            if (pool_local->n1_len != 0) {
              puVar7 = pool_local->coinbase + cb1_len;
              src = pool_local->nonce1bin;
              uVar12 = pool_local->n1_len;
              *(undefined4 *)((int)local_96c + iVar1 + iVar13) = 0x839;
              *(char **)(tmp42 + iVar1 + iVar13 + -0x20) = "parse_notify";
              _cg_memcpy(puVar7,src,uVar12,"util.c",*(char **)(tmp42 + iVar1 + iVar13 + -0x20),
                         *(int *)((int)local_96c + iVar1 + iVar13));
            }
            puVar7 = pool_local->coinbase;
            sVar3 = pool_local->n1_len;
            uVar12 = pool_local->n2size;
            *(undefined4 *)((int)local_96c + iVar1 + iVar13) = 0x83a;
            *(char **)(tmp42 + iVar1 + iVar13 + -0x20) = "parse_notify";
            _cg_memcpy(puVar7 + sVar3 + cb1_len + uVar12,cb2,cb2_len,"util.c",
                       *(char **)(tmp42 + iVar1 + iVar13 + -0x20),
                       *(int *)((int)local_96c + iVar1 + iVar13));
            if (opt_debug != false) {
              cb = bin2hex(pool_local->coinbase,pool_local->coinbase_len);
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                iVar10 = pool_local->pool_no;
                *(char **)(tmp42 + iVar1 + iVar13 + -0x20) = cb;
                snprintf(tmp42,0x800,"Pool %d coinbase %s",iVar10);
                _applog(7,tmp42,false);
              }
              free(cb);
            }
          }
          else if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
            tmp42[0] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[0];
            tmp42[1] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[1];
            tmp42[2] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[2];
            tmp42[3] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[3];
            tmp42[4] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[4];
            tmp42[5] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[5];
            tmp42[6] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[6];
            tmp42[7] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[7];
            tmp42[8] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[8];
            tmp42[9] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[9];
            tmp42[10] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[10];
            tmp42[11] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[11];
            tmp42[12] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[12];
            tmp42[13] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[13];
            tmp42[14] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[14];
            tmp42[15] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[15];
            tmp42[16] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[16];
            tmp42[17] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[17];
            tmp42[18] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[18];
            tmp42[19] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[19];
            tmp42[20] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[20];
            tmp42[21] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[21];
            tmp42[22] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[22];
            tmp42[23] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[23];
            tmp42[24] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[24];
            tmp42[25] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[25];
            tmp42[26] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[26];
            tmp42[27] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[27];
            tmp42[28] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[28];
            tmp42[29] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[29];
            tmp42[30] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[30];
            tmp42[31] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[31];
            tmp42[32] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[32];
            tmp42[33] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[33];
            tmp42[34] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[34];
            tmp42[35] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[35];
            tmp42[36] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[36];
            tmp42[37] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[37];
            tmp42[38] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[38];
            tmp42[39] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[39];
            tmp42[40] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[40];
            tmp42[41] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[41];
            tmp42[42] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[42];
            tmp42[43] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[43];
            tmp42[44] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[44];
            tmp42[45] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[45];
            tmp42[46] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[46];
            tmp42[47] = s_Failed_to_convert_cb2_to_cb2_bin_0009f460[47];
            tmp42[48] = (char)ram0x0009f490;
            _applog(3,tmp42,false);
          }
        }
        else if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          tmp42[0] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[0];
          tmp42[1] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[1];
          tmp42[2] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[2];
          tmp42[3] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[3];
          tmp42[4] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[4];
          tmp42[5] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[5];
          tmp42[6] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[6];
          tmp42[7] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[7];
          tmp42[8] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[8];
          tmp42[9] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[9];
          tmp42[10] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[10];
          tmp42[11] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[11];
          tmp42[12] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[12];
          tmp42[13] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[13];
          tmp42[14] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[14];
          tmp42[15] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[15];
          tmp42[16] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[16];
          tmp42[17] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[17];
          tmp42[18] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[18];
          tmp42[19] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[19];
          tmp42[20] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[20];
          tmp42[21] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[21];
          tmp42[22] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[22];
          tmp42[23] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[23];
          tmp42[24] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[24];
          tmp42[25] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[25];
          tmp42[26] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[26];
          tmp42[27] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[27];
          tmp42[28] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[28];
          tmp42[29] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[29];
          tmp42[30] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[30];
          tmp42[31] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[31];
          tmp42[32] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[32];
          tmp42[33] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[33];
          tmp42[34] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[34];
          tmp42[35] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[35];
          tmp42[36] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[36];
          tmp42[37] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[37];
          tmp42[38] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[38];
          tmp42[39] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[39];
          tmp42[40] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[40];
          tmp42[41] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[41];
          tmp42[42] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[42];
          tmp42[43] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[43];
          tmp42[44] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[44];
          tmp42[45] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[45];
          tmp42[46] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[46];
          tmp42[47] = s_Failed_to_convert_cb1_to_cb1_bin_0009f42c[47];
          tmp42[48] = (char)ram0x0009f45c;
          _applog(3,tmp42,false);
        }
      }
      else if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        tmp42[0] = s_Failed_to_convert_header_to_head_0009f3f4[0];
        tmp42[1] = s_Failed_to_convert_header_to_head_0009f3f4[1];
        tmp42[2] = s_Failed_to_convert_header_to_head_0009f3f4[2];
        tmp42[3] = s_Failed_to_convert_header_to_head_0009f3f4[3];
        tmp42[4] = s_Failed_to_convert_header_to_head_0009f3f4[4];
        tmp42[5] = s_Failed_to_convert_header_to_head_0009f3f4[5];
        tmp42[6] = s_Failed_to_convert_header_to_head_0009f3f4[6];
        tmp42[7] = s_Failed_to_convert_header_to_head_0009f3f4[7];
        tmp42[8] = s_Failed_to_convert_header_to_head_0009f3f4[8];
        tmp42[9] = s_Failed_to_convert_header_to_head_0009f3f4[9];
        tmp42[10] = s_Failed_to_convert_header_to_head_0009f3f4[10];
        tmp42[11] = s_Failed_to_convert_header_to_head_0009f3f4[11];
        tmp42[12] = s_Failed_to_convert_header_to_head_0009f3f4[12];
        tmp42[13] = s_Failed_to_convert_header_to_head_0009f3f4[13];
        tmp42[14] = s_Failed_to_convert_header_to_head_0009f3f4[14];
        tmp42[15] = s_Failed_to_convert_header_to_head_0009f3f4[15];
        tmp42[16] = s_Failed_to_convert_header_to_head_0009f3f4[16];
        tmp42[17] = s_Failed_to_convert_header_to_head_0009f3f4[17];
        tmp42[18] = s_Failed_to_convert_header_to_head_0009f3f4[18];
        tmp42[19] = s_Failed_to_convert_header_to_head_0009f3f4[19];
        tmp42[20] = s_Failed_to_convert_header_to_head_0009f3f4[20];
        tmp42[21] = s_Failed_to_convert_header_to_head_0009f3f4[21];
        tmp42[22] = s_Failed_to_convert_header_to_head_0009f3f4[22];
        tmp42[23] = s_Failed_to_convert_header_to_head_0009f3f4[23];
        tmp42[24] = s_Failed_to_convert_header_to_head_0009f3f4[24];
        tmp42[25] = s_Failed_to_convert_header_to_head_0009f3f4[25];
        tmp42[26] = s_Failed_to_convert_header_to_head_0009f3f4[26];
        tmp42[27] = s_Failed_to_convert_header_to_head_0009f3f4[27];
        tmp42[28] = s_Failed_to_convert_header_to_head_0009f3f4[28];
        tmp42[29] = s_Failed_to_convert_header_to_head_0009f3f4[29];
        tmp42[30] = s_Failed_to_convert_header_to_head_0009f3f4[30];
        tmp42[31] = s_Failed_to_convert_header_to_head_0009f3f4[31];
        tmp42[32] = s_Failed_to_convert_header_to_head_0009f3f4[32];
        tmp42[33] = s_Failed_to_convert_header_to_head_0009f3f4[33];
        tmp42[34] = s_Failed_to_convert_header_to_head_0009f3f4[34];
        tmp42[35] = s_Failed_to_convert_header_to_head_0009f3f4[35];
        tmp42[36] = s_Failed_to_convert_header_to_head_0009f3f4[36];
        tmp42[37] = s_Failed_to_convert_header_to_head_0009f3f4[37];
        tmp42[38] = s_Failed_to_convert_header_to_head_0009f3f4[38];
        tmp42[39] = s_Failed_to_convert_header_to_head_0009f3f4[39];
        tmp42[40] = s_Failed_to_convert_header_to_head_0009f3f4[40];
        tmp42[41] = s_Failed_to_convert_header_to_head_0009f3f4[41];
        tmp42[42] = s_Failed_to_convert_header_to_head_0009f3f4[42];
        tmp42[43] = s_Failed_to_convert_header_to_head_0009f3f4[43];
        tmp42[44] = s_Failed_to_convert_header_to_head_0009f3f4[44];
        tmp42[45] = s_Failed_to_convert_header_to_head_0009f3f4[45];
        tmp42[46] = s_Failed_to_convert_header_to_head_0009f3f4[46];
        tmp42[47] = s_Failed_to_convert_header_to_head_0009f3f4[47];
        tmp42[48] = s_Failed_to_convert_header_to_head_0009f3f4[48];
        tmp42[49] = s_Failed_to_convert_header_to_head_0009f3f4[49];
        tmp42[50] = s_Failed_to_convert_header_to_head_0009f3f4[50];
        tmp42[51] = s_Failed_to_convert_header_to_head_0009f3f4[51];
        tmp42._52_2_ = (undefined2)ram0x0009f428;
        tmp42[54] = (char)((uint)ram0x0009f428 >> 0x10);
        _applog(3,tmp42,false);
      }
out_unlock:
      _cg_wunlock(&pool_local->data_lock,"util.c","parse_notify",0x843);
      if (opt_protocol != false) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"job_id: %s",job_id);
          _applog(7,tmp42,false);
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"prev_hash: %s",prev_hash);
          _applog(7,tmp42,false);
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"coinbase1: %s",coinbase1);
          _applog(7,tmp42,false);
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"coinbase2: %s",coinbase2);
          _applog(7,tmp42,false);
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"bbversion: %s",bbversion);
          _applog(7,tmp42,false);
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"nbit: %s",nbit);
          _applog(7,tmp42,false);
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"ntime: %s",ntime);
          _applog(7,tmp42,false);
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          if (clean == false) {
            uVar12 = 0xf510;
          }
          else {
            uVar12 = 0xf50c;
          }
          snprintf(tmp42,0x800,"clean: %s",uVar12 | 0x90000);
          _applog(7,tmp42,false);
        }
      }
      free(coinbase1);
      free(coinbase2);
      pool_local->getwork_requested = pool_local->getwork_requested + 1;
      bVar14 = 0xfffffffe < (uint)total_getworks;
      total_getworks._0_4_ = (uint)total_getworks + 1;
      total_getworks._4_4_ = total_getworks._4_4_ + (uint)bVar14;
      ppVar8 = current_pool();
      if (pool_local == ppVar8) {
        opt_work_update = true;
      }
    }
    else {
      free(job_id);
      free(coinbase1);
      free(coinbase2);
    }
  }
  return ret;
}

