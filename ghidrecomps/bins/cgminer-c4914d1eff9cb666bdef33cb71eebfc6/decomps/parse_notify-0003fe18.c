
_Bool parse_notify(pool *pool,json_t *val)

{
  int iVar1;
  _Bool _Var2;
  json_t *json;
  size_t sVar3;
  char *s;
  char *s_00;
  char *s_01;
  char *s_02;
  char *s_03;
  char *s_04;
  char *s_05;
  json_t *pjVar4;
  size_t sVar5;
  uchar **ppuVar6;
  uchar *puVar7;
  uchar *puVar8;
  char *pcVar9;
  pool *ppVar10;
  uchar *puVar11;
  int iVar12;
  _Bool _Var13;
  uint len;
  uint len_00;
  uint uVar14;
  uint uVar15;
  undefined *puVar16;
  undefined4 uVar17;
  int iVar18;
  char *pcVar19;
  bool bVar20;
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
    s = json_array_string(val_local,0);
    s_00 = __json_array_string(val_local,1);
    s_01 = json_array_string(val_local,2);
    s_02 = json_array_string(val_local,3);
    s_03 = __json_array_string(val_local,5);
    s_04 = __json_array_string(val_local,6);
    s_05 = __json_array_string(val_local,7);
    pjVar4 = json_array_get(val_local,8);
    if ((pjVar4 == (json_t *)0x0) ||
       (pjVar4 = json_array_get(val_local,8), pjVar4->type != JSON_TRUE)) {
      _Var13 = false;
    }
    else {
      _Var13 = true;
    }
    _Var2 = _valid_ascii(s,"util.c","parse_notify",0x7d7);
    if ((((_Var2) && (_Var2 = _valid_hex(s_00,"util.c","parse_notify",0x7d7), _Var2)) &&
        ((_Var2 = _valid_hex(s_01,"util.c","parse_notify",0x7d7), _Var2 &&
         (((_Var2 = _valid_hex(s_02,"util.c","parse_notify",0x7d8), _Var2 &&
           (_Var2 = _valid_hex(s_03,"util.c","parse_notify",0x7d8), _Var2)) &&
          (_Var2 = _valid_hex(s_04,"util.c","parse_notify",0x7d8), _Var2)))))) &&
       (_Var2 = _valid_hex(s_05,"util.c","parse_notify",0x7d9), _Var2)) {
      _cg_wlock(&pool_local->data_lock,"util.c","parse_notify",0x7e2);
      free((pool_local->swork).job_id);
      (pool_local->swork).job_id = s;
      snprintf(pool_local->prev_hash,0x41,"%s",s_00);
      sVar5 = strlen(s_01);
      len = sVar5 >> 1;
      sVar5 = strlen(s_02);
      len_00 = sVar5 >> 1;
      snprintf(pool_local->bbversion,9,"%s",s_03);
      snprintf(pool_local->nbit,9,"%s",s_04);
      snprintf(pool_local->ntime,9,"%s",s_05);
      (pool_local->swork).clean = _Var13;
      if (0.0 < pool_local->next_diff) {
        uVar17 = *(undefined4 *)((int)&pool_local->next_diff + 4);
        *(undefined4 *)&pool_local->sdiff = *(undefined4 *)&pool_local->next_diff;
        *(undefined4 *)((int)&pool_local->sdiff + 4) = uVar17;
      }
      pool_local->coinbase_len = pool_local->n1_len + len + pool_local->n2size + len_00;
      uVar14 = pool_local->coinbase_len;
      pool_local->nonce2_offset = len + pool_local->n1_len;
      for (i = 0; i < pool_local->merkles; i = i + 1) {
        free((pool_local->swork).merkle_bin[i]);
      }
      if (sVar3 != 0) {
        ppuVar6 = (uchar **)
                  _cgrealloc((pool_local->swork).merkle_bin,sVar3 * 4 + 1,"util.c","parse_notify",
                             0x7f8);
        (pool_local->swork).merkle_bin = ppuVar6;
        for (i = 0; i < (int)sVar3; i = i + 1) {
          pcVar9 = json_array_string(json,i);
          ppuVar6 = (pool_local->swork).merkle_bin;
          puVar7 = (uchar *)_cgmalloc(0x20,"util.c","parse_notify",0x7fd);
          ppuVar6[i] = puVar7;
          if (((opt_protocol != false) && (opt_debug != false)) &&
             ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
            snprintf(tmp42,0x800,"merkle %d: %s",i);
            _applog(7,tmp42,false);
          }
          ret = hex2bin((pool_local->swork).merkle_bin[i],pcVar9,0x20);
          free(pcVar9);
          if (!ret) {
            if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
              builtin_strncpy(tmp42,"Failed to convert merkle to merkle_bin in parse_noti",0x34);
              tmp42[0x34] = 'f';
              tmp42[0x35] = 'y';
              tmp42[0x36] = '\0';
              _applog(3,tmp42,false);
            }
            goto LAB_00040782;
          }
        }
      }
      pool_local->merkles = sVar3;
      if (pool_local->merkles < 2) {
        uVar15 = (uint)pool_local->bad_work;
        iVar18 = *(int *)((int)&pool_local->bad_work + 4);
        *(uint *)&pool_local->bad_work = uVar15 + 1;
        *(uint *)((int)&pool_local->bad_work + 4) = iVar18 + (uint)(0xfffffffe < uVar15);
      }
      if (_Var13 != false) {
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
        iVar18 = -(len + 0xe & 0xfffffff8);
        ret = hex2bin((uchar *)((int)&val_local + iVar18),s_01,len);
        if (ret) {
          iVar1 = -(len_00 + 0xe & 0xfffffff8);
          pcVar19 = tmp42 + iVar1 + iVar18 + -0x20;
          puVar7 = (uchar *)((int)&val_local + iVar1 + iVar18);
          ret = hex2bin(puVar7,s_02,len_00);
          if (ret) {
            free(pool_local->coinbase);
            pcVar19[0] = '6';
            pcVar19[1] = '\b';
            pcVar19[2] = '\0';
            pcVar19[3] = '\0';
            puVar8 = (uchar *)_cgcalloc(uVar14,1,"util.c","parse_notify",
                                        *(int *)(tmp42 + iVar1 + iVar18 + -0x20));
            pool_local->coinbase = puVar8;
            puVar8 = pool_local->coinbase;
            *(undefined4 *)((int)local_96c + iVar1 + iVar18) = 0x837;
            *(char **)(tmp42 + iVar1 + iVar18 + -0x20) = "parse_notify";
            _cg_memcpy(puVar8,(uchar *)((int)&val_local + iVar18),len,"util.c",
                       *(char **)(tmp42 + iVar1 + iVar18 + -0x20),
                       *(int *)((int)local_96c + iVar1 + iVar18));
            if (pool_local->n1_len != 0) {
              puVar11 = pool_local->coinbase;
              puVar8 = pool_local->nonce1bin;
              uVar14 = pool_local->n1_len;
              *(undefined4 *)((int)local_96c + iVar1 + iVar18) = 0x839;
              *(char **)(tmp42 + iVar1 + iVar18 + -0x20) = "parse_notify";
              _cg_memcpy(puVar11 + len,puVar8,uVar14,"util.c",
                         *(char **)(tmp42 + iVar1 + iVar18 + -0x20),
                         *(int *)((int)local_96c + iVar1 + iVar18));
            }
            puVar8 = pool_local->coinbase;
            sVar3 = pool_local->n1_len;
            uVar14 = pool_local->n2size;
            *(undefined4 *)((int)local_96c + iVar1 + iVar18) = 0x83a;
            *(char **)(tmp42 + iVar1 + iVar18 + -0x20) = "parse_notify";
            _cg_memcpy(puVar8 + uVar14 + sVar3 + len,puVar7,len_00,"util.c",
                       *(char **)(tmp42 + iVar1 + iVar18 + -0x20),
                       *(int *)((int)local_96c + iVar1 + iVar18));
            if (opt_debug != false) {
              pcVar9 = bin2hex(pool_local->coinbase,pool_local->coinbase_len);
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                iVar12 = pool_local->pool_no;
                *(char **)(tmp42 + iVar1 + iVar18 + -0x20) = pcVar9;
                snprintf(tmp42,0x800,"Pool %d coinbase %s",iVar12);
                _applog(7,tmp42,false);
              }
              free(pcVar9);
            }
          }
          else if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
            builtin_strncpy(tmp42,"Failed to convert cb2 to cb2_bin in parse_notify",0x30);
            tmp42._48_4_ = tmp42._48_4_ & 0xffffff00;
            _applog(3,tmp42,false);
          }
        }
        else if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          builtin_strncpy(tmp42,"Failed to convert cb1 to cb1_bin in parse_notify",0x30);
          tmp42._48_4_ = tmp42._48_4_ & 0xffffff00;
          _applog(3,tmp42,false);
        }
      }
      else if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
        builtin_strncpy(tmp42,"Failed to convert header to header_bin in parse_noti",0x34);
        tmp42[0x34] = 'f';
        tmp42[0x35] = 'y';
        tmp42[0x36] = '\0';
        _applog(3,tmp42,false);
      }
LAB_00040782:
      _cg_wunlock(&pool_local->data_lock,"util.c","parse_notify",0x843);
      if (opt_protocol != false) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"job_id: %s",s);
          _applog(7,tmp42,false);
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"prev_hash: %s",s_00);
          _applog(7,tmp42,false);
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"coinbase1: %s",s_01);
          _applog(7,tmp42,false);
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"coinbase2: %s",s_02);
          _applog(7,tmp42,false);
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"bbversion: %s",s_03);
          _applog(7,tmp42,false);
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"nbit: %s",s_04);
          _applog(7,tmp42,false);
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"ntime: %s",s_05);
          _applog(7,tmp42,false);
        }
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          if (_Var13 == false) {
            puVar16 = &DAT_00087f38;
          }
          else {
            puVar16 = &DAT_00087f34;
          }
          snprintf(tmp42,0x800,"clean: %s",puVar16);
          _applog(7,tmp42,false);
        }
      }
      free(s_01);
      free(s_02);
      pool_local->getwork_requested = pool_local->getwork_requested + 1;
      bVar20 = 0xfffffffe < (uint)total_getworks;
      total_getworks._0_4_ = (uint)total_getworks + 1;
      total_getworks._4_4_ = total_getworks._4_4_ + (uint)bVar20;
      ppVar10 = current_pool();
      if (pool_local == ppVar10) {
        opt_work_update = true;
      }
    }
    else {
      free(s);
      free(s_01);
      free(s_02);
    }
  }
  return ret;
}

