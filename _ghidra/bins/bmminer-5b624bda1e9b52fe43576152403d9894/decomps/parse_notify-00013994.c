
/* WARNING: Unknown calling convention */

_Bool parse_notify(pool *pool,json_t *val)

{
  _Bool _Var1;
  json_t *json;
  byte *pbVar2;
  char *pcVar3;
  char *s;
  json_t *pjVar4;
  size_t sVar5;
  int iVar6;
  uchar *puVar7;
  uchar *puVar8;
  pool *ppVar9;
  char *pcVar10;
  uchar **ppuVar11;
  byte *pbVar12;
  char *func;
  size_t extraout_r3;
  size_t line;
  int line_00;
  int line_01;
  int line_02;
  int line_03;
  int line_04;
  int line_05;
  int iVar13;
  size_t n;
  int line_06;
  undefined4 *puVar14;
  uint extraout_r3_00;
  uint extraout_r3_01;
  int extraout_r3_02;
  uint extraout_r3_03;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  double dVar18;
  char *local_974 [4];
  char *local_964;
  char *local_960;
  int local_95c;
  char *local_958;
  byte *local_954;
  pthread_rwlock_t *local_950;
  pthread_mutex_t *local_94c;
  uint local_948;
  char *local_944;
  char *local_940;
  char *local_93c;
  char *local_938;
  _Bool *local_934;
  uint local_930;
  uint local_92c;
  uint local_928;
  char *local_924;
  char *local_920;
  char *local_91c;
  uchar *local_918;
  char *local_914;
  char header [228];
  char tmp42 [2048];
  
  json = json_array_get(val,4);
  if (json == (json_t *)0x0) {
    return false;
  }
  if (json->type != JSON_ARRAY) {
    return false;
  }
  local_918 = (uchar *)json_array_size(json);
  pbVar2 = (byte *)json_array_string(val,0);
  local_914 = __json_array_string(val,1);
  pcVar3 = json_array_string(val,2);
  s = json_array_string(val,3);
  local_91c = __json_array_string(val,5);
  local_920 = __json_array_string(val,6);
  local_924 = __json_array_string(val,7);
  pjVar4 = json_array_get(val,8);
  if (pjVar4 == (json_t *)0x0) {
    local_928 = 0;
  }
  else {
    pjVar4 = json_array_get(val,8);
    local_928 = (uint)(pjVar4->type == JSON_TRUE);
  }
  if (pbVar2 == (byte *)0x0) {
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3))
    goto LAB_00013a88;
    pcVar10 = "Null string passed to valid_ascii from";
  }
  else {
    sVar5 = strlen((char *)pbVar2);
    if (sVar5 != 0) {
      line = extraout_r3;
      if (0 < (int)sVar5) {
        if (*pbVar2 - 0x20 < 0x5f) {
          line = 0;
          pbVar12 = pbVar2;
          do {
            line = line + 1;
            if (sVar5 == line) goto LAB_00013a76;
            pbVar12 = pbVar12 + 1;
          } while (*pbVar12 - 0x20 < 0x5f);
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          local_974[0] = "util.c";
          local_974[2] = (char *)0x79b;
          local_974[1] = "parse_notify";
          snprintf(tmp42,0x800,"Invalid char 0x%x passed to valid_ascii from"," in %s %s():%d");
          _applog(3,tmp42,false);
        }
        goto LAB_00013a88;
      }
LAB_00013a76:
      _Var1 = _valid_hex(local_914,"parse_notify",(char *)0x79b,line);
      if (((!_Var1) || (_Var1 = _valid_hex(pcVar3,"parse_notify",(char *)0x79b,line_00), !_Var1)) ||
         ((_Var1 = _valid_hex(s,"parse_notify",(char *)0x79c,line_01), !_Var1 ||
          (((_Var1 = _valid_hex(local_91c,"parse_notify",(char *)0x79c,line_02), !_Var1 ||
            (_Var1 = _valid_hex(local_920,"parse_notify",(char *)0x79c,line_03), !_Var1)) ||
           (_Var1 = _valid_hex(local_924,"parse_notify",(char *)0x79d,line_04), !_Var1))))))
      goto LAB_00013a88;
      local_94c = &(pool->data_lock).mutex;
      iVar6 = pthread_mutex_lock((pthread_mutex_t *)local_94c);
      iVar13 = line_05;
      if (iVar6 != 0) {
        _mutex_lock((pthread_mutex_t *)"parse_notify",(char *)0x7a6,func,line_05);
        iVar13 = extraout_r3_02;
      }
      local_950 = &(pool->data_lock).rwlock;
      _wr_lock(local_950,"parse_notify",(char *)0x7a6,iVar13);
      local_938 = pool->prev_hash;
      free((pool->swork).job_id);
      (pool->swork).job_id = (char *)pbVar2;
      local_93c = pool->bbversion;
      snprintf(local_938,0x41,"%s",local_914);
      sVar5 = strlen(pcVar3);
      local_92c = sVar5 >> 1;
      local_940 = pool->nbit;
      sVar5 = strlen(s);
      local_930 = sVar5 >> 1;
      local_944 = pool->ntime;
      snprintf(local_93c,9,"%s",local_91c);
      snprintf(local_940,9,"%s",local_920);
      snprintf(local_944,9,"%s",local_924);
      dVar18 = pool->next_diff;
      (pool->swork).clean = SUB41(local_928,0);
      if (0.0 < dVar18) {
        pool->sdiff = dVar18;
      }
      iVar13 = local_92c + pool->n1_len;
      pool->nonce2_offset = iVar13;
      uVar16 = local_930;
      if (0 < pool->merkles) {
        uVar16 = 0;
      }
      local_948 = pool->n2size + local_930 + iVar13;
      pool->coinbase_len = local_948;
      if (0 < pool->merkles) {
        do {
          ppuVar11 = (pool->swork).merkle_bin + uVar16;
          uVar16 = uVar16 + 1;
          free(*ppuVar11);
        } while ((int)uVar16 < pool->merkles);
      }
      puVar7 = local_918;
      if (local_918 == (uchar *)0x0) {
LAB_00013bee:
        pool->merkles = (int)local_918;
        local_934 = &opt_protocol;
LAB_00013bf8:
        uVar16 = (uint)pool->bad_work;
        iVar13 = *(int *)((int)&pool->bad_work + 4);
        *(uint *)&pool->bad_work = uVar16 + 1;
        *(uint *)((int)&pool->bad_work + 4) = iVar13 + (uint)(0xfffffffe < uVar16);
      }
      else {
        ppuVar11 = (uchar **)
                   _cgrealloc((pool->swork).merkle_bin,(int)local_918 * 4 + 1,"util.c",
                              "parse_notify",0x7bb);
        (pool->swork).merkle_bin = ppuVar11;
        if ((int)puVar7 < 1) goto LAB_00013bee;
        local_934 = &opt_protocol;
        puVar7 = (uchar *)0x0;
        local_958 = pcVar3;
        local_954 = pbVar2;
        do {
          pcVar3 = json_array_string(json,(uint)puVar7);
          ppuVar11 = (pool->swork).merkle_bin;
          local_95c = (int)puVar7 << 2;
          puVar8 = (uchar *)_cgmalloc(0x20,"util.c","parse_notify",0x7c0);
          _Var1 = *local_934;
          ppuVar11[(int)puVar7] = puVar8;
          if (((_Var1 != false) && (opt_debug != false)) &&
             ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
            local_960 = tmp42;
            snprintf(tmp42,0x800,"merkle %d: %s",puVar7);
            _applog(7,local_960,false);
          }
          puVar7 = puVar7 + 1;
          _Var1 = hex2bin(*(uchar **)((int)(pool->swork).merkle_bin + local_95c),pcVar3,0x20);
          free(pcVar3);
          pbVar2 = local_954;
          pcVar3 = local_958;
          if (!_Var1) {
            if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3))
            goto LAB_00014048;
            pcVar10 = "Failed to convert merkle to merkle_bin in parse_notify";
            goto LAB_000142ac;
          }
        } while (local_918 != puVar7);
        pool->merkles = (int)local_918;
        if ((int)local_918 < 2) goto LAB_00013bf8;
      }
      if (local_928 != 0) {
        *(undefined4 *)&pool->nonce2 = 0;
        *(undefined4 *)((int)&pool->nonce2 + 4) = 0;
      }
      local_974[1] = local_944;
      local_974[2] = local_940;
      local_964 = workpadding;
      local_974[0] = "0000000000000000000000000000000000000000000000000000000000000000";
      local_974[3] = "00000000";
      snprintf(header,0xe1,"%s%s%s%s%s%s%s",local_93c);
      _Var1 = hex2bin(pool->header_bin,header,0x70);
      if (_Var1) {
        iVar13 = -(local_92c + 0xe & 0xfffffff8);
        _Var1 = hex2bin((uchar *)((int)&local_960 + iVar13),pcVar3,local_92c);
        if (_Var1) {
          iVar6 = -(local_930 + 0xe & 0xfffffff8);
          local_918 = (uchar *)((int)&local_960 + iVar6 + iVar13);
          _Var1 = hex2bin(local_918,s,local_930);
          if (_Var1) {
            free(pool->coinbase);
            *(undefined4 *)(&stack0xfffff688 + iVar6 + iVar13) = 0x7f9;
            puVar7 = (uchar *)_cgcalloc(local_948,1,"util.c","parse_notify",
                                        *(int *)(&stack0xfffff688 + iVar6 + iVar13));
            pool->coinbase = puVar7;
            *(undefined4 *)((int)local_974 + iVar6 + iVar13) = 0x7fa;
            *(char **)(&stack0xfffff688 + iVar6 + iVar13) = "parse_notify";
            _cg_memcpy(puVar7,(uchar *)((int)&local_960 + iVar13),local_92c,"util.c",
                       *(char **)(&stack0xfffff688 + iVar6 + iVar13),
                       *(int *)((int)local_974 + iVar6 + iVar13));
            uVar16 = local_92c;
            n = pool->n1_len;
            if (n != 0) {
              puVar7 = pool->coinbase;
              *(undefined4 *)((int)local_974 + iVar6 + iVar13) = 0x7fc;
              *(char **)(&stack0xfffff688 + iVar6 + iVar13) = "parse_notify";
              _cg_memcpy(puVar7 + uVar16,pool->nonce1bin,n,"util.c",
                         *(char **)(&stack0xfffff688 + iVar6 + iVar13),
                         *(int *)((int)local_974 + iVar6 + iVar13));
              n = pool->n1_len;
            }
            uVar16 = local_92c;
            uVar15 = pool->n2size;
            puVar8 = pool->coinbase;
            *(char **)(&stack0xfffff688 + iVar6 + iVar13) = "parse_notify";
            puVar7 = local_918;
            *(undefined4 *)((int)local_974 + iVar6 + iVar13) = 0x7fd;
            _cg_memcpy(puVar8 + uVar15 + n + uVar16,puVar7,local_930,"util.c",
                       *(char **)(&stack0xfffff688 + iVar6 + iVar13),
                       *(int *)((int)local_974 + iVar6 + iVar13));
            uVar16 = (uint)opt_debug;
            if (opt_debug != 0) {
              pcVar10 = bin2hex(pool->coinbase,pool->coinbase_len);
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                *(char **)(&stack0xfffff688 + iVar6 + iVar13) = pcVar10;
                snprintf(tmp42,0x800,"Pool %d coinbase %s",pool->pool_no);
                _applog(7,tmp42,false);
              }
              free(pcVar10);
              uVar16 = extraout_r3_01;
            }
            goto LAB_00013d0e;
          }
          if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3))
          goto LAB_00014048;
          pcVar10 = "Failed to convert cb2 to cb2_bin in parse_notify";
        }
        else {
          if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3))
          goto LAB_00014048;
          pcVar10 = "Failed to convert cb1 to cb1_bin in parse_notify";
          _Var1 = false;
        }
        tmp42._0_4_ = *(undefined4 *)pcVar10;
        tmp42._4_4_ = *(undefined4 *)(pcVar10 + 4);
        tmp42._8_4_ = *(undefined4 *)(pcVar10 + 8);
        tmp42._12_4_ = *(undefined4 *)(pcVar10 + 0xc);
        tmp42._16_4_ = *(undefined4 *)(pcVar10 + 0x10);
        tmp42._20_4_ = *(undefined4 *)(pcVar10 + 0x14);
        tmp42._24_4_ = *(undefined4 *)(pcVar10 + 0x18);
        tmp42._28_4_ = *(undefined4 *)(pcVar10 + 0x1c);
        tmp42._32_4_ = *(undefined4 *)(pcVar10 + 0x20);
        tmp42._36_4_ = *(undefined4 *)(pcVar10 + 0x24);
        tmp42._40_4_ = *(undefined4 *)(pcVar10 + 0x28);
        tmp42._44_4_ = *(undefined4 *)(pcVar10 + 0x2c);
        tmp42[0x30] = (char)*(undefined4 *)(pcVar10 + 0x30);
        _applog(3,tmp42,false);
        uVar16 = extraout_r3_00;
      }
      else if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3)) {
LAB_00014048:
        _Var1 = false;
        uVar16 = opt_log_level;
      }
      else {
        pcVar10 = "Failed to convert header to header_bin in parse_notify";
LAB_000142ac:
        _Var1 = false;
        tmp42._0_4_ = *(undefined4 *)pcVar10;
        tmp42._4_4_ = *(undefined4 *)(pcVar10 + 4);
        tmp42._8_4_ = *(undefined4 *)(pcVar10 + 8);
        tmp42._12_4_ = *(undefined4 *)(pcVar10 + 0xc);
        tmp42._16_4_ = *(undefined4 *)(pcVar10 + 0x10);
        tmp42._20_4_ = *(undefined4 *)(pcVar10 + 0x14);
        tmp42._24_4_ = *(undefined4 *)(pcVar10 + 0x18);
        tmp42._28_4_ = *(undefined4 *)(pcVar10 + 0x1c);
        tmp42._32_4_ = *(undefined4 *)(pcVar10 + 0x20);
        tmp42._36_4_ = *(undefined4 *)(pcVar10 + 0x24);
        tmp42._40_4_ = *(undefined4 *)(pcVar10 + 0x28);
        tmp42._44_4_ = *(undefined4 *)(pcVar10 + 0x2c);
        tmp42._48_4_ = *(undefined4 *)(pcVar10 + 0x30);
        tmp42._52_2_ = (undefined2)*(undefined4 *)(pcVar10 + 0x34);
        tmp42[0x36] = (char)((uint)*(undefined4 *)(pcVar10 + 0x34) >> 0x10);
        _applog(3,tmp42,false);
        uVar16 = extraout_r3_03;
      }
LAB_00013d0e:
      _rw_unlock(local_950,"parse_notify",(char *)0x806,uVar16);
      _mutex_unlock_noyield(local_94c,"parse_notify",(char *)0x806,line_06);
      (*selective_yield)();
      if ((*local_934 == false) || (opt_debug == false)) goto LAB_00013f68;
      if ((use_syslog == false) && ((opt_log_output == false && (opt_log_level < 7)))) {
LAB_00013d8e:
        if ((opt_log_output != false) || (6 < opt_log_level)) goto LAB_00013d9e;
LAB_00013dcc:
        if ((opt_log_output != false) || (6 < opt_log_level)) goto LAB_00013e16;
LAB_00013e44:
        if ((opt_log_output != false) || (6 < opt_log_level)) goto LAB_00013e54;
LAB_00013e82:
        if ((opt_log_output != false) || (6 < opt_log_level)) goto LAB_00013e92;
LAB_00013ebe:
        if ((opt_log_output != false) || (6 < opt_log_level)) goto LAB_00013ece;
LAB_00013efa:
        if ((opt_log_output != false) || (6 < opt_log_level)) goto LAB_00013f0a;
LAB_00013f34:
        if ((opt_log_output == false) && (opt_log_level < 7)) goto LAB_00013f68;
      }
      else {
        snprintf(tmp42,0x800,"job_id: %s",pbVar2);
        _applog(7,tmp42,false);
        if (opt_debug == false) goto LAB_00013f68;
        if (use_syslog == false) goto LAB_00013d8e;
LAB_00013d9e:
        snprintf(tmp42,0x800,"prev_hash: %s",local_914);
        _applog(7,tmp42,false);
        if (opt_debug == false) goto LAB_00013f68;
        if (use_syslog == false) goto LAB_00013dcc;
LAB_00013e16:
        snprintf(tmp42,0x800,"coinbase1: %s",pcVar3);
        _applog(7,tmp42,false);
        if (opt_debug == false) goto LAB_00013f68;
        if (use_syslog == false) goto LAB_00013e44;
LAB_00013e54:
        snprintf(tmp42,0x800,"coinbase2: %s",s);
        _applog(7,tmp42,false);
        if (opt_debug == false) goto LAB_00013f68;
        if (use_syslog == false) goto LAB_00013e82;
LAB_00013e92:
        snprintf(tmp42,0x800,"bbversion: %s",local_91c);
        _applog(7,tmp42,false);
        if (opt_debug == false) goto LAB_00013f68;
        if (use_syslog == false) goto LAB_00013ebe;
LAB_00013ece:
        snprintf(tmp42,0x800,"nbit: %s",local_920);
        _applog(7,tmp42,false);
        if (opt_debug == false) goto LAB_00013f68;
        if (use_syslog == false) goto LAB_00013efa;
LAB_00013f0a:
        snprintf(tmp42,0x800,"ntime: %s",local_924);
        _applog(7,tmp42,false);
        if (opt_debug == false) goto LAB_00013f68;
        if (use_syslog == false) goto LAB_00013f34;
      }
      puVar14 = (undefined4 *)&DAT_00045cc4;
      if (local_928 == 0) {
        puVar14 = &DAT_00045cc8;
      }
      snprintf(tmp42,0x800,"clean: %s",puVar14);
      _applog(7,tmp42,false);
LAB_00013f68:
      free(pcVar3);
      free(s);
      pool->getwork_requested = pool->getwork_requested + 1;
      bVar17 = 0xfffffffe < (uint)total_getworks;
      total_getworks._0_4_ = (uint)total_getworks + 1;
      total_getworks._4_4_ = total_getworks._4_4_ + (uint)bVar17;
      ppVar9 = current_pool();
      if (pool != ppVar9) {
        return _Var1;
      }
      opt_work_update = true;
      return _Var1;
    }
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3))
    goto LAB_00013a88;
    pcVar10 = "Zero length string passed to valid_ascii from";
  }
  local_974[1] = (char *)0x79b;
  local_974[0] = "parse_notify";
  snprintf(tmp42,0x800,pcVar10," in %s %s():%d");
  _applog(3,tmp42,false);
LAB_00013a88:
  free(pbVar2);
  free(pcVar3);
  free(s);
  return false;
}

