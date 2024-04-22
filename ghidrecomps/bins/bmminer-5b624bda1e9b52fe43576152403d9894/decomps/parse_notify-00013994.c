
/* WARNING: Unknown calling convention */

_Bool parse_notify(pool *pool,json_t *val)

{
  char cVar1;
  int iVar2;
  pthread_mutex_t *lock;
  uint *puVar3;
  _Bool _Var4;
  json_t *json;
  json_t *arr;
  int merkles;
  byte *pbVar5;
  char *job_id;
  char *prev_hash;
  char *pcVar6;
  char *coinbase1;
  char *s;
  char *coinbase2;
  char *bbversion;
  char *nbit;
  char *ntime;
  json_t *pjVar7;
  size_t sVar8;
  int len;
  int iVar9;
  size_t cb1_len;
  size_t cb2_len;
  uchar *puVar10;
  uchar *puVar11;
  pool *ppVar12;
  char *cb;
  uchar **ppuVar13;
  byte *pbVar14;
  size_t alloc_len;
  char *pcVar15;
  uint in_r3;
  size_t n;
  undefined4 uVar16;
  uint uVar17;
  uint uVar18;
  uchar *idx;
  char *merkle;
  undefined4 *puVar19;
  double dVar20;
  char *local_974 [4];
  undefined4 local_964;
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
  char *local_934;
  uint local_930;
  uint local_92c;
  _Bool clean;
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
  pbVar5 = (byte *)json_array_string(val,0);
  local_914 = __json_array_string(val,1);
  pcVar6 = json_array_string(val,2);
  s = json_array_string(val,3);
  local_91c = __json_array_string(val,5);
  local_920 = __json_array_string(val,6);
  local_924 = __json_array_string(val,7);
  pjVar7 = json_array_get(val,8);
  if (pjVar7 == (json_t *)0x0) {
    _clean = 0;
  }
  else {
    pjVar7 = json_array_get(val,8);
    in_r3 = (uint)(pjVar7->type == JSON_TRUE);
    _clean = in_r3;
  }
  if (pbVar5 == (byte *)0x0) {
    pcVar15 = DAT_00014314;
    if ((*DAT_000142f8 == '\0') && (*DAT_000142fc == '\0')) {
      uVar18 = *DAT_00014300;
joined_r0x00014148:
      if ((int)uVar18 < 3) goto LAB_00013a88;
    }
  }
  else {
    sVar8 = strlen((char *)pbVar5);
    lock = DAT_00013aa8;
    if (sVar8 != 0) {
      if (0 < (int)sVar8) {
        if (*pbVar5 - 0x20 < 0x5f) {
          in_r3 = 0;
          pbVar14 = pbVar5;
          do {
            in_r3 = in_r3 + 1;
            if (sVar8 == in_r3) goto LAB_00013a76;
            pbVar14 = pbVar14 + 1;
          } while (*pbVar14 - 0x20 < 0x5f);
        }
        if (((*DAT_000140c8 != '\0') || (*DAT_000140a0 != '\0')) || (2 < (int)*DAT_000140a4)) {
          local_974[0] = DAT_000140cc;
          local_974[2] = (char *)0x79b;
          local_974[1] = DAT_000140d0;
          snprintf(tmp42,0x800,DAT_000140d4,DAT_000140d8);
          _applog(3,tmp42,false);
        }
        goto LAB_00013a88;
      }
LAB_00013a76:
      _Var4 = _valid_hex(local_914,DAT_00013aa8->__size,(char *)0x79b,in_r3);
      if ((((!_Var4) || (_Var4 = _valid_hex(pcVar6,lock->__size,(char *)0x79b,in_r3), !_Var4)) ||
          (_Var4 = _valid_hex(s,lock->__size,(char *)0x79c,in_r3), !_Var4)) ||
         ((_Var4 = _valid_hex(local_91c,lock->__size,(char *)0x79c,in_r3), !_Var4 ||
          (_Var4 = _valid_hex(local_920,lock->__size,(char *)0x79c,in_r3), !_Var4))))
      goto LAB_00013a88;
      pcVar15 = (char *)0x79d;
      _Var4 = _valid_hex(local_924,lock->__size,(char *)0x79d,in_r3);
      if (!_Var4) goto LAB_00013a88;
      local_94c = &(pool->data_lock).mutex;
      iVar9 = pthread_mutex_lock((pthread_mutex_t *)local_94c);
      if (iVar9 != 0) {
        _mutex_lock(lock,(char *)0x7a6,pcVar15,in_r3);
      }
      local_950 = &(pool->data_lock).rwlock;
      _wr_lock(local_950,DAT_00013dd8,(char *)0x7a6,in_r3);
      local_938 = pool->prev_hash;
      free((pool->swork).job_id);
      pcVar15 = DAT_00013ddc;
      (pool->swork).job_id = (char *)pbVar5;
      local_93c = pool->bbversion;
      snprintf(local_938,0x41,pcVar15,local_914);
      sVar8 = strlen(pcVar6);
      local_92c = sVar8 >> 1;
      local_940 = pool->nbit;
      sVar8 = strlen(s);
      local_930 = sVar8 >> 1;
      local_944 = pool->ntime;
      snprintf(local_93c,9,DAT_00013ddc,local_91c);
      snprintf(local_940,9,DAT_00013ddc,local_920);
      snprintf(local_944,9,DAT_00013ddc,local_924);
      dVar20 = pool->next_diff;
      (pool->swork).clean = SUB41(_clean,0);
      if (dVar20 != 0.0 && dVar20 < 0.0 == NAN(dVar20)) {
        pool->sdiff = dVar20;
      }
      iVar9 = local_92c + pool->n1_len;
      pool->nonce2_offset = iVar9;
      uVar18 = local_930;
      if (0 < pool->merkles) {
        uVar18 = 0;
      }
      local_948 = pool->n2size + local_930 + iVar9;
      pool->coinbase_len = local_948;
      if (0 < pool->merkles) {
        do {
          ppuVar13 = (pool->swork).merkle_bin + uVar18;
          uVar18 = uVar18 + 1;
          free(*ppuVar13);
        } while ((int)uVar18 < pool->merkles);
      }
      puVar10 = local_918;
      if (local_918 == (uchar *)0x0) {
LAB_00013bee:
        local_934 = DAT_00013de0;
        pool->merkles = (int)local_918;
LAB_00013bf8:
        uVar18 = *(uint *)&pool->bad_work;
        iVar9 = *(int *)((int)&pool->bad_work + 4);
        *(uint *)&pool->bad_work = uVar18 + 1;
        *(uint *)((int)&pool->bad_work + 4) = iVar9 + (uint)(0xfffffffe < uVar18);
      }
      else {
        ppuVar13 = (uchar **)
                   _cgrealloc((pool->swork).merkle_bin,(int)local_918 * 4 + 1,DAT_00014304,
                              DAT_00014308,0x7bb);
        (pool->swork).merkle_bin = ppuVar13;
        if ((int)puVar10 < 1) goto LAB_00013bee;
        local_934 = DAT_00014318;
        puVar10 = (uchar *)0x0;
        local_958 = pcVar6;
        local_954 = pbVar5;
        do {
          pcVar6 = json_array_string(json,(uint)puVar10);
          ppuVar13 = (pool->swork).merkle_bin;
          local_95c = (int)puVar10 << 2;
          puVar11 = (uchar *)_cgmalloc(0x20,DAT_00014304,DAT_00014308,0x7c0);
          cVar1 = *local_934;
          ppuVar13[(int)puVar10] = puVar11;
          if (((cVar1 != '\0') && (opt_debug != false)) &&
             ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
            local_960 = tmp42;
            snprintf(tmp42,0x800,DAT_0001431c,puVar10);
            _applog(7,local_960,false);
          }
          puVar10 = puVar10 + 1;
          _Var4 = hex2bin(*(uchar **)((int)(pool->swork).merkle_bin + local_95c),pcVar6,0x20);
          free(pcVar6);
          pbVar5 = local_954;
          pcVar6 = local_958;
          if (!_Var4) {
            puVar19 = DAT_00014324;
            if ((*DAT_000142f8 != '\0') || (*DAT_000142fc != '\0')) goto LAB_000142ac;
            uVar18 = *DAT_00014300;
            goto joined_r0x00014288;
          }
        } while (local_918 != puVar10);
        pool->merkles = (int)local_918;
        if ((int)local_918 < 2) goto LAB_00013bf8;
      }
      if (_clean != 0) {
        *(undefined4 *)&pool->nonce2 = 0;
        *(undefined4 *)((int)&pool->nonce2 + 4) = 0;
      }
      local_964 = *DAT_00013de4;
      local_974[1] = local_944;
      local_974[2] = local_940;
      local_974[0] = DAT_00013de8;
      local_974[3] = (char *)DAT_00013dec;
      snprintf(header,0xe1,DAT_00013df0,local_93c);
      _Var4 = hex2bin(pool->header_bin,header,0x70);
      if (_Var4) {
        iVar9 = -(local_92c + 0xe & 0xfffffff8);
        _Var4 = hex2bin((uchar *)((int)&local_960 + iVar9),pcVar6,local_92c);
        if (_Var4) {
          iVar2 = -(local_930 + 0xe & 0xfffffff8);
          local_918 = (uchar *)((int)&local_960 + iVar2 + iVar9);
          _Var4 = hex2bin(local_918,s,local_930);
          if (_Var4) {
            free(pool->coinbase);
            *(undefined4 *)(&stack0xfffff688 + iVar2 + iVar9) = 0x7f9;
            puVar10 = (uchar *)_cgcalloc(local_948,1,DAT_00013df4,DAT_00013dd8,
                                         *(int *)(&stack0xfffff688 + iVar2 + iVar9));
            pool->coinbase = puVar10;
            *(undefined4 *)((int)local_974 + iVar2 + iVar9) = 0x7fa;
            *(pthread_mutex_t **)(&stack0xfffff688 + iVar2 + iVar9) = lock;
            _cg_memcpy(puVar10,(uchar *)((int)&local_960 + iVar9),local_92c,DAT_00013df4,
                       *(char **)(&stack0xfffff688 + iVar2 + iVar9),
                       *(int *)((int)local_974 + iVar2 + iVar9));
            uVar18 = local_92c;
            n = pool->n1_len;
            if (n != 0) {
              puVar10 = pool->coinbase;
              *(undefined4 *)((int)local_974 + iVar2 + iVar9) = 0x7fc;
              *(char **)(&stack0xfffff688 + iVar2 + iVar9) = DAT_000140d0;
              _cg_memcpy(puVar10 + uVar18,pool->nonce1bin,n,DAT_000140cc,
                         *(char **)(&stack0xfffff688 + iVar2 + iVar9),
                         *(int *)((int)local_974 + iVar2 + iVar9));
              n = pool->n1_len;
            }
            uVar18 = local_92c;
            pbVar14 = DAT_00013dfc;
            uVar17 = pool->n2size;
            puVar11 = pool->coinbase;
            *(pthread_mutex_t **)(&stack0xfffff688 + iVar2 + iVar9) = lock;
            puVar10 = local_918;
            *(undefined4 *)((int)local_974 + iVar2 + iVar9) = 0x7fd;
            _cg_memcpy(puVar11 + uVar17 + n + uVar18,puVar10,local_930,DAT_00013df4,
                       *(char **)(&stack0xfffff688 + iVar2 + iVar9),
                       *(int *)((int)local_974 + iVar2 + iVar9));
            uVar18 = (uint)*pbVar14;
            if (uVar18 != 0) {
              pcVar15 = bin2hex(pool->coinbase,pool->coinbase_len);
              uVar18 = (uint)*pbVar14;
              if ((uVar18 != 0) &&
                 (((*DAT_000140c8 != '\0' || (*DAT_000140a0 != '\0')) ||
                  (uVar18 = *DAT_000140a4, 6 < (int)uVar18)))) {
                *(char **)(&stack0xfffff688 + iVar2 + iVar9) = pcVar15;
                uVar18 = pool->pool_no;
                snprintf(tmp42,0x800,DAT_000140dc);
                _applog(7,tmp42,false);
              }
              free(pcVar15);
            }
          }
          else {
            puVar19 = DAT_000140e4;
            if (((*DAT_000140c8 == '\0') && (*DAT_000140a0 == '\0')) &&
               (uVar18 = *DAT_000140a4, (int)uVar18 < 3)) goto LAB_00014048;
LAB_0001401c:
            tmp42._0_4_ = *puVar19;
            tmp42._4_4_ = puVar19[1];
            tmp42._8_4_ = puVar19[2];
            tmp42._12_4_ = puVar19[3];
            tmp42._16_4_ = puVar19[4];
            tmp42._20_4_ = puVar19[5];
            tmp42._24_4_ = puVar19[6];
            tmp42._28_4_ = puVar19[7];
            tmp42._32_4_ = puVar19[8];
            tmp42._36_4_ = puVar19[9];
            tmp42._40_4_ = puVar19[10];
            uVar18 = puVar19[0xb];
            tmp42[48] = (char)puVar19[0xc];
            tmp42._44_4_ = uVar18;
            _applog(3,tmp42,false);
          }
        }
        else {
          if (((*DAT_000142f8 != '\0') || (*DAT_000142fc != '\0')) ||
             (uVar18 = *DAT_00014300, 2 < (int)uVar18)) {
            _Var4 = false;
            puVar19 = DAT_00014320;
            goto LAB_0001401c;
          }
LAB_00014048:
          _Var4 = false;
        }
      }
      else {
        puVar19 = DAT_00014328;
        if ((*DAT_000142f8 == '\0') && (*DAT_000142fc == '\0')) {
          uVar18 = *DAT_00014300;
joined_r0x00014288:
          if ((int)uVar18 < 3) goto LAB_00014048;
        }
LAB_000142ac:
        _Var4 = false;
        tmp42._0_4_ = *puVar19;
        tmp42._4_4_ = puVar19[1];
        tmp42._8_4_ = puVar19[2];
        tmp42._12_4_ = puVar19[3];
        tmp42._16_4_ = puVar19[4];
        tmp42._20_4_ = puVar19[5];
        tmp42._24_4_ = puVar19[6];
        tmp42._28_4_ = puVar19[7];
        tmp42._32_4_ = puVar19[8];
        tmp42._36_4_ = puVar19[9];
        tmp42._40_4_ = puVar19[10];
        tmp42._44_4_ = puVar19[0xb];
        tmp42._48_4_ = puVar19[0xc];
        uVar17 = puVar19[0xd];
        uVar18 = uVar17 >> 0x10;
        tmp42._52_2_ = (undefined2)uVar17;
        tmp42[54] = (char)(uVar17 >> 0x10);
        _applog(3,tmp42,false);
      }
      _rw_unlock(local_950,DAT_00013dd8,(char *)0x806,uVar18);
      _mutex_unlock_noyield(local_94c,DAT_00013dd8,(char *)0x806,uVar18);
      (**DAT_00013df8)();
      pbVar14 = DAT_00013dfc;
      if ((*local_934 == '\0') || (*DAT_00013dfc == 0)) goto LAB_00013f68;
      if ((use_syslog == false) && ((*DAT_00013e00 == '\0' && (*DAT_00013e04 < 7)))) {
LAB_00013d8e:
        if ((*DAT_00013e00 != '\0') || (6 < *DAT_00013e04)) goto LAB_00013d9e;
LAB_00013dcc:
        if ((*DAT_00013e00 != '\0') || (pcVar15 = DAT_00013e00, 6 < *DAT_00013e04))
        goto LAB_00013e16;
LAB_00013e44:
        if ((*pcVar15 != '\0') || (6 < (int)*DAT_000140a4)) goto LAB_00013e54;
LAB_00013e82:
        if ((*pcVar15 != '\0') || (6 < (int)*DAT_000140a4)) goto LAB_00013e92;
LAB_00013ebe:
        if ((*pcVar15 != '\0') || (6 < (int)*DAT_000140a4)) goto LAB_00013ece;
LAB_00013efa:
        if ((*pcVar15 != '\0') || (6 < (int)*DAT_000140a4)) goto LAB_00013f0a;
LAB_00013f34:
        if ((*pcVar15 == '\0') && ((int)*DAT_000140a4 < 7)) goto LAB_00013f68;
      }
      else {
        snprintf(tmp42,0x800,DAT_00013e08,pbVar5);
        _applog(7,tmp42,false);
        if (*pbVar14 == 0) goto LAB_00013f68;
        if (use_syslog == false) goto LAB_00013d8e;
LAB_00013d9e:
        snprintf(tmp42,0x800,DAT_00013e0c,local_914);
        _applog(7,tmp42,false);
        if (*pbVar14 == 0) goto LAB_00013f68;
        if (use_syslog == false) goto LAB_00013dcc;
LAB_00013e16:
        snprintf(tmp42,0x800,DAT_0001409c,pcVar6);
        _applog(7,tmp42,false);
        if (*pbVar14 == 0) goto LAB_00013f68;
        pcVar15 = DAT_000140a0;
        if (use_syslog == false) goto LAB_00013e44;
LAB_00013e54:
        snprintf(tmp42,0x800,DAT_000140a8,s);
        _applog(7,tmp42,false);
        if (*pbVar14 == 0) goto LAB_00013f68;
        pcVar15 = DAT_000140a0;
        if (use_syslog == false) goto LAB_00013e82;
LAB_00013e92:
        snprintf(tmp42,0x800,DAT_000140ac,local_91c);
        _applog(7,tmp42,false);
        if (*pbVar14 == 0) goto LAB_00013f68;
        pcVar15 = DAT_000140a0;
        if (use_syslog == false) goto LAB_00013ebe;
LAB_00013ece:
        snprintf(tmp42,0x800,DAT_000140b0,local_920);
        _applog(7,tmp42,false);
        if (*pbVar14 == 0) goto LAB_00013f68;
        pcVar15 = DAT_000140a0;
        if (use_syslog == false) goto LAB_00013efa;
LAB_00013f0a:
        snprintf(tmp42,0x800,DAT_000140b4,local_924);
        _applog(7,tmp42,false);
        if (*pbVar14 == 0) goto LAB_00013f68;
        pcVar15 = DAT_000140a0;
        if (use_syslog == false) goto LAB_00013f34;
      }
      uVar16 = DAT_000140b8;
      if (_clean == 0) {
        uVar16 = DAT_000140e0;
      }
      snprintf(tmp42,0x800,DAT_000140bc,uVar16);
      _applog(7,tmp42,false);
LAB_00013f68:
      free(pcVar6);
      free(s);
      puVar3 = DAT_000140c0;
      uVar18 = *DAT_000140c0;
      uVar17 = DAT_000140c0[1];
      pool->getwork_requested = pool->getwork_requested + 1;
      *puVar3 = uVar18 + 1;
      puVar3[1] = uVar17 + (0xfffffffe < uVar18);
      ppVar12 = current_pool();
      if (pool != ppVar12) {
        return _Var4;
      }
      *DAT_000140c4 = 1;
      return _Var4;
    }
    pcVar15 = DAT_0001430c;
    if ((*DAT_000142f8 == '\0') && (*DAT_000142fc == '\0')) {
      uVar18 = *DAT_00014300;
      goto joined_r0x00014148;
    }
  }
  local_974[1] = (char *)0x79b;
  local_974[0] = DAT_00014308;
  snprintf(tmp42,0x800,pcVar15,DAT_00014310);
  _applog(3,tmp42,false);
LAB_00013a88:
  free(pbVar5);
  free(pcVar6);
  free(s);
  return false;
}

