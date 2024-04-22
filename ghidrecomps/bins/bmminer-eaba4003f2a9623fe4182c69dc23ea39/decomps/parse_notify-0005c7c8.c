
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
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined *puVar14;
  bool bVar15;
  double dVar16;
  char *local_964 [4];
  char *local_954;
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
    _Var2 = _valid_ascii(job_id,"util.c","parse_notify",0x79b);
    if ((((_Var2) && (_Var2 = _valid_hex(prev_hash,"util.c","parse_notify",0x79b), _Var2)) &&
        ((_Var2 = _valid_hex(coinbase1,"util.c","parse_notify",0x79b), _Var2 &&
         (((_Var2 = _valid_hex(coinbase2,"util.c","parse_notify",0x79c), _Var2 &&
           (_Var2 = _valid_hex(bbversion,"util.c","parse_notify",0x79c), _Var2)) &&
          (_Var2 = _valid_hex(nbit,"util.c","parse_notify",0x79c), _Var2)))))) &&
       (_Var2 = _valid_hex(ntime,"util.c","parse_notify",0x79d), _Var2)) {
      _cg_wlock(&pool_local->data_lock,"util.c","parse_notify",0x7a6);
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
      dVar16 = pool_local->next_diff;
      if (dVar16 != 0.0 && dVar16 < 0.0 == NAN(dVar16)) {
        uVar10 = *(undefined4 *)((int)&pool_local->next_diff + 4);
        *(undefined4 *)&pool_local->sdiff = *(undefined4 *)&pool_local->next_diff;
        *(undefined4 *)((int)&pool_local->sdiff + 4) = uVar10;
      }
      pool_local->coinbase_len = pool_local->n1_len + cb1_len + pool_local->n2size + cb2_len;
      uVar11 = pool_local->coinbase_len;
      pool_local->nonce2_offset = pool_local->n1_len + cb1_len;
      for (i = 0; i < pool_local->merkles; i = i + 1) {
        free((pool_local->swork).merkle_bin[i]);
      }
      if (sVar3 != 0) {
        ppuVar6 = (uchar **)
                  _cgrealloc((pool_local->swork).merkle_bin,sVar3 * 4 + 1,"util.c","parse_notify",
                             0x7bb);
        (pool_local->swork).merkle_bin = ppuVar6;
        for (i = 0; i < (int)sVar3; i = i + 1) {
          hexstr = json_array_string(json,i);
          ppuVar6 = (pool_local->swork).merkle_bin;
          puVar7 = (uchar *)_cgmalloc(0x20,"util.c","parse_notify",0x7c0);
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
              tmp42[0] = s_Failed_to_convert_merkle_to_merk_0007b2b0[0];
              tmp42[1] = s_Failed_to_convert_merkle_to_merk_0007b2b0[1];
              tmp42[2] = s_Failed_to_convert_merkle_to_merk_0007b2b0[2];
              tmp42[3] = s_Failed_to_convert_merkle_to_merk_0007b2b0[3];
              tmp42[4] = s_Failed_to_convert_merkle_to_merk_0007b2b0[4];
              tmp42[5] = s_Failed_to_convert_merkle_to_merk_0007b2b0[5];
              tmp42[6] = s_Failed_to_convert_merkle_to_merk_0007b2b0[6];
              tmp42[7] = s_Failed_to_convert_merkle_to_merk_0007b2b0[7];
              tmp42[8] = s_Failed_to_convert_merkle_to_merk_0007b2b0[8];
              tmp42[9] = s_Failed_to_convert_merkle_to_merk_0007b2b0[9];
              tmp42[10] = s_Failed_to_convert_merkle_to_merk_0007b2b0[10];
              tmp42[11] = s_Failed_to_convert_merkle_to_merk_0007b2b0[11];
              tmp42[12] = s_Failed_to_convert_merkle_to_merk_0007b2b0[12];
              tmp42[13] = s_Failed_to_convert_merkle_to_merk_0007b2b0[13];
              tmp42[14] = s_Failed_to_convert_merkle_to_merk_0007b2b0[14];
              tmp42[15] = s_Failed_to_convert_merkle_to_merk_0007b2b0[15];
              tmp42[16] = s_Failed_to_convert_merkle_to_merk_0007b2b0[16];
              tmp42[17] = s_Failed_to_convert_merkle_to_merk_0007b2b0[17];
              tmp42[18] = s_Failed_to_convert_merkle_to_merk_0007b2b0[18];
              tmp42[19] = s_Failed_to_convert_merkle_to_merk_0007b2b0[19];
              tmp42[20] = s_Failed_to_convert_merkle_to_merk_0007b2b0[20];
              tmp42[21] = s_Failed_to_convert_merkle_to_merk_0007b2b0[21];
              tmp42[22] = s_Failed_to_convert_merkle_to_merk_0007b2b0[22];
              tmp42[23] = s_Failed_to_convert_merkle_to_merk_0007b2b0[23];
              tmp42[24] = s_Failed_to_convert_merkle_to_merk_0007b2b0[24];
              tmp42[25] = s_Failed_to_convert_merkle_to_merk_0007b2b0[25];
              tmp42[26] = s_Failed_to_convert_merkle_to_merk_0007b2b0[26];
              tmp42[27] = s_Failed_to_convert_merkle_to_merk_0007b2b0[27];
              tmp42[28] = s_Failed_to_convert_merkle_to_merk_0007b2b0[28];
              tmp42[29] = s_Failed_to_convert_merkle_to_merk_0007b2b0[29];
              tmp42[30] = s_Failed_to_convert_merkle_to_merk_0007b2b0[30];
              tmp42[31] = s_Failed_to_convert_merkle_to_merk_0007b2b0[31];
              tmp42[32] = s_Failed_to_convert_merkle_to_merk_0007b2b0[32];
              tmp42[33] = s_Failed_to_convert_merkle_to_merk_0007b2b0[33];
              tmp42[34] = s_Failed_to_convert_merkle_to_merk_0007b2b0[34];
              tmp42[35] = s_Failed_to_convert_merkle_to_merk_0007b2b0[35];
              tmp42[36] = s_Failed_to_convert_merkle_to_merk_0007b2b0[36];
              tmp42[37] = s_Failed_to_convert_merkle_to_merk_0007b2b0[37];
              tmp42[38] = s_Failed_to_convert_merkle_to_merk_0007b2b0[38];
              tmp42[39] = s_Failed_to_convert_merkle_to_merk_0007b2b0[39];
              tmp42[40] = s_Failed_to_convert_merkle_to_merk_0007b2b0[40];
              tmp42[41] = s_Failed_to_convert_merkle_to_merk_0007b2b0[41];
              tmp42[42] = s_Failed_to_convert_merkle_to_merk_0007b2b0[42];
              tmp42[43] = s_Failed_to_convert_merkle_to_merk_0007b2b0[43];
              tmp42[44] = s_Failed_to_convert_merkle_to_merk_0007b2b0[44];
              tmp42[45] = s_Failed_to_convert_merkle_to_merk_0007b2b0[45];
              tmp42[46] = s_Failed_to_convert_merkle_to_merk_0007b2b0[46];
              tmp42[47] = s_Failed_to_convert_merkle_to_merk_0007b2b0[47];
              tmp42[48] = s_Failed_to_convert_merkle_to_merk_0007b2b0[48];
              tmp42[49] = s_Failed_to_convert_merkle_to_merk_0007b2b0[49];
              tmp42[50] = s_Failed_to_convert_merkle_to_merk_0007b2b0[50];
              tmp42[51] = s_Failed_to_convert_merkle_to_merk_0007b2b0[51];
              tmp42._52_2_ = (undefined2)ram0x0007b2e4;
              tmp42[54] = (char)((uint)ram0x0007b2e4 >> 0x10);
              _applog(3,tmp42,false);
            }
            goto out_unlock;
          }
        }
      }
      pool_local->merkles = sVar3;
      if (pool_local->merkles < 2) {
        uVar9 = *(uint *)&pool_local->bad_work;
        iVar12 = *(int *)((int)&pool_local->bad_work + 4);
        *(uint *)&pool_local->bad_work = uVar9 + 1;
        *(uint *)((int)&pool_local->bad_work + 4) = iVar12 + (uint)(0xfffffffe < uVar9);
      }
      if (clean != false) {
        *(undefined4 *)&pool_local->nonce2 = 0;
        *(undefined4 *)((int)&pool_local->nonce2 + 4) = 0;
      }
      local_964[1] = pool_local->ntime;
      local_964[2] = pool_local->nbit;
      local_964[0] = blank_merkle;
      local_964[3] = "00000000";
      local_954 = workpadding;
      snprintf(header,0xe1,"%s%s%s%s%s%s%s",pool_local->bbversion);
      ret = hex2bin(pool_local->header_bin,header,0x70);
      if (ret) {
        iVar12 = -(cb1_len + 0xe & 0xfffffff8);
        cb1 = (uchar *)((int)&val_local + iVar12);
        ret = hex2bin(cb1,coinbase1,cb1_len);
        if (ret) {
          iVar1 = -(cb2_len + 0xe & 0xfffffff8);
          cb2 = (uchar *)((int)&val_local + iVar1 + iVar12);
          ret = hex2bin(cb2,coinbase2,cb2_len);
          if (ret) {
            free(pool_local->coinbase);
            *(undefined4 *)(tmp42 + iVar1 + iVar12 + -0x20) = 0x7f9;
            puVar7 = (uchar *)_cgcalloc(uVar11,1,"util.c","parse_notify",
                                        *(int *)(tmp42 + iVar1 + iVar12 + -0x20));
            pool_local->coinbase = puVar7;
            puVar7 = pool_local->coinbase;
            *(char **)(tmp42 + iVar1 + iVar12 + -0x20) = "parse_notify";
            *(undefined4 *)((int)local_964 + iVar1 + iVar12) = 0x7fa;
            _cg_memcpy(puVar7,cb1,cb1_len,"util.c",*(char **)(tmp42 + iVar1 + iVar12 + -0x20),
                       *(int *)((int)local_964 + iVar1 + iVar12));
            if (pool_local->n1_len != 0) {
              puVar7 = pool_local->coinbase + cb1_len;
              src = pool_local->nonce1bin;
              uVar11 = pool_local->n1_len;
              *(char **)(tmp42 + iVar1 + iVar12 + -0x20) = "parse_notify";
              *(undefined4 *)((int)local_964 + iVar1 + iVar12) = 0x7fc;
              _cg_memcpy(puVar7,src,uVar11,"util.c",*(char **)(tmp42 + iVar1 + iVar12 + -0x20),
                         *(int *)((int)local_964 + iVar1 + iVar12));
            }
            puVar7 = pool_local->coinbase;
            sVar3 = pool_local->n1_len;
            uVar11 = pool_local->n2size;
            *(char **)(tmp42 + iVar1 + iVar12 + -0x20) = "parse_notify";
            *(undefined4 *)((int)local_964 + iVar1 + iVar12) = 0x7fd;
            _cg_memcpy(puVar7 + sVar3 + cb1_len + uVar11,cb2,cb2_len,"util.c",
                       *(char **)(tmp42 + iVar1 + iVar12 + -0x20),
                       *(int *)((int)local_964 + iVar1 + iVar12));
            if (opt_debug != false) {
              cb = bin2hex(pool_local->coinbase,pool_local->coinbase_len);
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                iVar13 = pool_local->pool_no;
                *(char **)(tmp42 + iVar1 + iVar12 + -0x20) = cb;
                snprintf(tmp42,0x800,"Pool %d coinbase %s",iVar13);
                _applog(7,tmp42,false);
              }
              free(cb);
            }
          }
          else if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
            tmp42[0] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[0];
            tmp42[1] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[1];
            tmp42[2] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[2];
            tmp42[3] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[3];
            tmp42[4] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[4];
            tmp42[5] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[5];
            tmp42[6] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[6];
            tmp42[7] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[7];
            tmp42[8] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[8];
            tmp42[9] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[9];
            tmp42[10] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[10];
            tmp42[11] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[11];
            tmp42[12] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[12];
            tmp42[13] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[13];
            tmp42[14] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[14];
            tmp42[15] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[15];
            tmp42[16] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[16];
            tmp42[17] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[17];
            tmp42[18] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[18];
            tmp42[19] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[19];
            tmp42[20] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[20];
            tmp42[21] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[21];
            tmp42[22] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[22];
            tmp42[23] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[23];
            tmp42[24] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[24];
            tmp42[25] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[25];
            tmp42[26] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[26];
            tmp42[27] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[27];
            tmp42[28] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[28];
            tmp42[29] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[29];
            tmp42[30] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[30];
            tmp42[31] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[31];
            tmp42[32] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[32];
            tmp42[33] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[33];
            tmp42[34] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[34];
            tmp42[35] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[35];
            tmp42[36] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[36];
            tmp42[37] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[37];
            tmp42[38] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[38];
            tmp42[39] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[39];
            tmp42[40] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[40];
            tmp42[41] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[41];
            tmp42[42] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[42];
            tmp42[43] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[43];
            tmp42[44] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[44];
            tmp42[45] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[45];
            tmp42[46] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[46];
            tmp42[47] = s_Failed_to_convert_cb2_to_cb2_bin_0007b370[47];
            tmp42[48] = (char)ram0x0007b3a0;
            _applog(3,tmp42,false);
          }
        }
        else if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          tmp42[0] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[0];
          tmp42[1] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[1];
          tmp42[2] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[2];
          tmp42[3] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[3];
          tmp42[4] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[4];
          tmp42[5] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[5];
          tmp42[6] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[6];
          tmp42[7] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[7];
          tmp42[8] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[8];
          tmp42[9] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[9];
          tmp42[10] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[10];
          tmp42[11] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[11];
          tmp42[12] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[12];
          tmp42[13] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[13];
          tmp42[14] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[14];
          tmp42[15] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[15];
          tmp42[16] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[16];
          tmp42[17] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[17];
          tmp42[18] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[18];
          tmp42[19] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[19];
          tmp42[20] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[20];
          tmp42[21] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[21];
          tmp42[22] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[22];
          tmp42[23] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[23];
          tmp42[24] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[24];
          tmp42[25] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[25];
          tmp42[26] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[26];
          tmp42[27] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[27];
          tmp42[28] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[28];
          tmp42[29] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[29];
          tmp42[30] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[30];
          tmp42[31] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[31];
          tmp42[32] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[32];
          tmp42[33] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[33];
          tmp42[34] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[34];
          tmp42[35] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[35];
          tmp42[36] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[36];
          tmp42[37] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[37];
          tmp42[38] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[38];
          tmp42[39] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[39];
          tmp42[40] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[40];
          tmp42[41] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[41];
          tmp42[42] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[42];
          tmp42[43] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[43];
          tmp42[44] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[44];
          tmp42[45] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[45];
          tmp42[46] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[46];
          tmp42[47] = s_Failed_to_convert_cb1_to_cb1_bin_0007b33c[47];
          tmp42[48] = (char)ram0x0007b36c;
          _applog(3,tmp42,false);
        }
      }
      else if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        tmp42[0] = s_Failed_to_convert_header_to_head_0007b304[0];
        tmp42[1] = s_Failed_to_convert_header_to_head_0007b304[1];
        tmp42[2] = s_Failed_to_convert_header_to_head_0007b304[2];
        tmp42[3] = s_Failed_to_convert_header_to_head_0007b304[3];
        tmp42[4] = s_Failed_to_convert_header_to_head_0007b304[4];
        tmp42[5] = s_Failed_to_convert_header_to_head_0007b304[5];
        tmp42[6] = s_Failed_to_convert_header_to_head_0007b304[6];
        tmp42[7] = s_Failed_to_convert_header_to_head_0007b304[7];
        tmp42[8] = s_Failed_to_convert_header_to_head_0007b304[8];
        tmp42[9] = s_Failed_to_convert_header_to_head_0007b304[9];
        tmp42[10] = s_Failed_to_convert_header_to_head_0007b304[10];
        tmp42[11] = s_Failed_to_convert_header_to_head_0007b304[11];
        tmp42[12] = s_Failed_to_convert_header_to_head_0007b304[12];
        tmp42[13] = s_Failed_to_convert_header_to_head_0007b304[13];
        tmp42[14] = s_Failed_to_convert_header_to_head_0007b304[14];
        tmp42[15] = s_Failed_to_convert_header_to_head_0007b304[15];
        tmp42[16] = s_Failed_to_convert_header_to_head_0007b304[16];
        tmp42[17] = s_Failed_to_convert_header_to_head_0007b304[17];
        tmp42[18] = s_Failed_to_convert_header_to_head_0007b304[18];
        tmp42[19] = s_Failed_to_convert_header_to_head_0007b304[19];
        tmp42[20] = s_Failed_to_convert_header_to_head_0007b304[20];
        tmp42[21] = s_Failed_to_convert_header_to_head_0007b304[21];
        tmp42[22] = s_Failed_to_convert_header_to_head_0007b304[22];
        tmp42[23] = s_Failed_to_convert_header_to_head_0007b304[23];
        tmp42[24] = s_Failed_to_convert_header_to_head_0007b304[24];
        tmp42[25] = s_Failed_to_convert_header_to_head_0007b304[25];
        tmp42[26] = s_Failed_to_convert_header_to_head_0007b304[26];
        tmp42[27] = s_Failed_to_convert_header_to_head_0007b304[27];
        tmp42[28] = s_Failed_to_convert_header_to_head_0007b304[28];
        tmp42[29] = s_Failed_to_convert_header_to_head_0007b304[29];
        tmp42[30] = s_Failed_to_convert_header_to_head_0007b304[30];
        tmp42[31] = s_Failed_to_convert_header_to_head_0007b304[31];
        tmp42[32] = s_Failed_to_convert_header_to_head_0007b304[32];
        tmp42[33] = s_Failed_to_convert_header_to_head_0007b304[33];
        tmp42[34] = s_Failed_to_convert_header_to_head_0007b304[34];
        tmp42[35] = s_Failed_to_convert_header_to_head_0007b304[35];
        tmp42[36] = s_Failed_to_convert_header_to_head_0007b304[36];
        tmp42[37] = s_Failed_to_convert_header_to_head_0007b304[37];
        tmp42[38] = s_Failed_to_convert_header_to_head_0007b304[38];
        tmp42[39] = s_Failed_to_convert_header_to_head_0007b304[39];
        tmp42[40] = s_Failed_to_convert_header_to_head_0007b304[40];
        tmp42[41] = s_Failed_to_convert_header_to_head_0007b304[41];
        tmp42[42] = s_Failed_to_convert_header_to_head_0007b304[42];
        tmp42[43] = s_Failed_to_convert_header_to_head_0007b304[43];
        tmp42[44] = s_Failed_to_convert_header_to_head_0007b304[44];
        tmp42[45] = s_Failed_to_convert_header_to_head_0007b304[45];
        tmp42[46] = s_Failed_to_convert_header_to_head_0007b304[46];
        tmp42[47] = s_Failed_to_convert_header_to_head_0007b304[47];
        tmp42[48] = s_Failed_to_convert_header_to_head_0007b304[48];
        tmp42[49] = s_Failed_to_convert_header_to_head_0007b304[49];
        tmp42[50] = s_Failed_to_convert_header_to_head_0007b304[50];
        tmp42[51] = s_Failed_to_convert_header_to_head_0007b304[51];
        tmp42._52_2_ = (undefined2)ram0x0007b338;
        tmp42[54] = (char)((uint)ram0x0007b338 >> 0x10);
        _applog(3,tmp42,false);
      }
out_unlock:
      _cg_wunlock(&pool_local->data_lock,"util.c","parse_notify",0x806);
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
            puVar14 = &DAT_0007b420;
          }
          else {
            puVar14 = &DAT_0007b41c;
          }
          snprintf(tmp42,0x800,"clean: %s",puVar14);
          _applog(7,tmp42,false);
        }
      }
      free(coinbase1);
      free(coinbase2);
      pool_local->getwork_requested = pool_local->getwork_requested + 1;
      bVar15 = 0xfffffffe < (uint)total_getworks;
      total_getworks._0_4_ = (uint)total_getworks + 1;
      total_getworks._4_4_ = total_getworks._4_4_ + (uint)bVar15;
      ppVar8 = current_pool();
      if (ppVar8 == pool_local) {
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

