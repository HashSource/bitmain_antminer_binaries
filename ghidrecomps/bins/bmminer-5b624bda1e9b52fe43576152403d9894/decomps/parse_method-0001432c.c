
/* WARNING: Unknown calling convention */

_Bool parse_method(pool *pool,char *s)

{
  _Bool _Var1;
  json_t *json;
  json_t *pjVar2;
  json_t *method;
  json_t *json_00;
  json_t *err_val;
  json_t *val;
  json_t *params;
  char *pcVar3;
  char *ss;
  char *buf;
  int iVar4;
  json_t *id_val_1;
  undefined4 uVar5;
  int id_1;
  size_t sVar6;
  char *nonce1;
  json_t *id_val;
  int id;
  char *msg;
  int n2size;
  uchar *puVar7;
  int *piVar8;
  int i;
  char *pcVar9;
  json_type in_r3;
  size_t sVar10;
  double *pdVar11;
  pthread_mutex_t *line;
  undefined uVar12;
  json_t *unaff_r5;
  uint index;
  pthread_rwlock_t *ppVar13;
  double dVar14;
  int idiff;
  double dVar15;
  json_int_t jVar16;
  undefined8 in_stack_ffffdec0;
  pthread_mutex_t *ppVar18;
  undefined8 uVar17;
  json_error_t err;
  char tmp42 [2048];
  
  ppVar18 = (pthread_mutex_t *)((ulonglong)in_stack_ffffdec0 >> 0x20);
  if (s == (char *)0x0) {
    return false;
  }
  json = json_loads(s,0,&err);
  if (json == (json_t *)0x0) {
    if (((*DAT_00014588 == '\0') && (*DAT_0001458c == '\0')) && (*DAT_00014590 < 6)) {
      return false;
    }
    snprintf(tmp42,0x800,DAT_00014598,err.line,err.text);
    _applog(6,tmp42,false);
    return false;
  }
  pjVar2 = json_object_get(json,DAT_0001457c);
  if (pjVar2 != (json_t *)0x0) {
    json_00 = json_object_get(json,DAT_00014580);
    val = json_object_get(json,DAT_00014584);
    if ((json_00 != (json_t *)0x0) && (in_r3 = json_00->type, in_r3 != JSON_NULL)) {
      pcVar3 = json_dumps(json_00,3);
      if ((*DAT_00014588 != '\0') || ((*DAT_0001458c != '\0' || (5 < *DAT_00014590)))) {
        snprintf(tmp42,0x800,DAT_00014594,pcVar3);
        _applog(6,tmp42,false);
      }
      unaff_r5 = (json_t *)0x0;
      free(pcVar3);
      goto out_decref;
    }
    pcVar3 = json_string_value(pjVar2);
    if (pcVar3 != (char *)0x0) {
      iVar4 = strncasecmp(pcVar3,DAT_0001459c,0x14);
      pcVar9 = DAT_00014588;
      if (iVar4 == 0) {
        pool->support_vil = true;
        if (((*pcVar9 != '\0') || (*DAT_0001458c != '\0')) || (5 < *DAT_00014590)) {
          tmp42._0_4_ = *DAT_000145a0;
          tmp42._4_4_ = DAT_000145a0[1];
          tmp42._8_4_ = DAT_000145a0[2];
          tmp42._12_4_ = DAT_000145a0[3];
          tmp42._16_4_ = DAT_000145a0[4];
          tmp42._20_4_ = DAT_000145a0[5];
          tmp42._24_3_ = (undefined3)DAT_000145a0[6];
          _applog(6,tmp42,false);
        }
        index = 0;
        while( true ) {
          sVar10 = json_array_size(val);
          if (sVar10 <= index) break;
          pjVar2 = json_array_get(val,index);
          jVar16 = json_integer_value(pjVar2);
          pool->version[0] = (int)jVar16;
          index = index + 1;
          pool = (pool *)&pool->prio;
        }
        goto out_decref;
      }
      iVar4 = strncasecmp(pcVar3,DAT_000145a4,0xd);
      if (iVar4 == 0) {
        _Var1 = parse_notify(pool,val);
        if (_Var1) {
          unaff_r5 = (json_t *)0x1;
          pool->stratum_notify = true;
        }
        else {
          pool->stratum_notify = _Var1;
          unaff_r5 = (json_t *)0x0;
        }
        goto out_decref;
      }
      pcVar9 = (char *)0x15;
      iVar4 = strncasecmp(pcVar3,DAT_000145a8,0x15);
      if (iVar4 == 0) {
        pjVar2 = json_array_get(val,0);
        dVar14 = json_number_value(pjVar2);
        unaff_r5 = (json_t *)0x0;
        if (dVar14 == 0.0) goto out_decref;
        iVar4 = pthread_mutex_lock((pthread_mutex_t *)&pool->data_lock);
        if (iVar4 != 0) {
          _mutex_lock(DAT_00014a30,(char *)0x830,pcVar9,in_r3);
        }
        ppVar13 = &(pool->data_lock).rwlock;
        iVar4 = pthread_rwlock_wrlock((pthread_rwlock_t *)ppVar13);
        if (iVar4 != 0) {
          piVar8 = __errno_location();
          ppVar18 = DAT_00014a30;
          snprintf(tmp42,0x800,DAT_00014a3c,*piVar8,DAT_00014a14,DAT_00014a30,0x830);
          _applog(3,tmp42,true);
          _quit(1);
        }
        pdVar11 = &pool->next_diff;
        dVar15 = *pdVar11;
        if (dVar15 == 0.0 || dVar15 < 0.0 != NAN(dVar15)) {
          *pdVar11 = dVar14;
          dVar15 = pool->sdiff;
          pool->sdiff = dVar14;
        }
        else {
          *pdVar11 = dVar14;
        }
        iVar4 = pthread_rwlock_unlock((pthread_rwlock_t *)ppVar13);
        if (iVar4 != 0) {
          piVar8 = __errno_location();
          ppVar18 = DAT_00014a30;
          snprintf(tmp42,0x800,DAT_00014a34,*piVar8,DAT_00014a14,DAT_00014a30,0x83d);
          _applog(3,tmp42,true);
          _quit(1);
        }
        iVar4 = pthread_mutex_unlock((pthread_mutex_t *)&pool->data_lock);
        if (iVar4 != 0) {
          piVar8 = __errno_location();
          ppVar18 = DAT_00014a30;
          snprintf(tmp42,0x800,DAT_00014a38,*piVar8,DAT_00014a14,DAT_00014a30,0x83d);
          _applog(3,tmp42,true);
          _quit(1);
        }
        (**DAT_00014838)();
        if (dVar14 == dVar15) {
          if ((*DAT_00014864 != '\0') &&
             (((*DAT_0001483c != '\0' || (*DAT_00014840 != '\0')) || (6 < *DAT_00014844)))) {
            unaff_r5 = (json_t *)0x1;
            snprintf(tmp42,0x800,DAT_00014868,pool->pool_no,dVar14);
            _applog(7,tmp42,false);
            goto out_decref;
          }
        }
        else if (dVar14 == (double)(longlong)(int)(longlong)dVar14) {
          if (((*DAT_0001483c != '\0') || (*DAT_00014840 != '\0')) || (4 < *DAT_00014844)) {
            uVar17 = CONCAT44(ppVar18,(int)(longlong)dVar14);
            iVar4 = pool->pool_no;
            pcVar3 = DAT_00014848;
LAB_00014684:
            snprintf(tmp42,0x800,pcVar3,iVar4,uVar17);
LAB_00014688:
            unaff_r5 = (json_t *)0x1;
            _applog(5,tmp42,false);
            goto out_decref;
          }
        }
        else if (((*DAT_0001483c != '\0') || (*DAT_00014840 != '\0')) || (4 < *DAT_00014844)) {
          snprintf(tmp42,0x800,DAT_0001486c,pool->pool_no,dVar14);
          goto LAB_00014688;
        }
      }
      else {
        iVar4 = strncasecmp(pcVar3,DAT_000145ac,0x15);
        if (iVar4 != 0) {
          iVar4 = strncasecmp(pcVar3,DAT_000145b0,0x10);
          if (iVar4 == 0) {
            _Var1 = parse_reconnect(pool,val);
            unaff_r5 = (json_t *)(uint)_Var1;
            goto out_decref;
          }
          iVar4 = strncasecmp(pcVar3,DAT_000145b4,0x12);
          if (iVar4 == 0) {
            pjVar2 = json_object_get(json,DAT_00014854);
            if (pjVar2 != (json_t *)0x0) {
              pjVar2 = json_object_get(json,DAT_00014854);
              jVar16 = json_integer_value(pjVar2);
              uVar5 = (undefined4)jVar16;
              pcVar3 = DAT_00014858;
LAB_0001454c:
              id_1 = (int)tmp42;
              sprintf((char *)id_1,pcVar3,uVar5);
              sVar6 = strlen(tmp42);
              _Var1 = stratum_send(pool,tmp42,sVar6);
              unaff_r5 = (json_t *)(uint)_Var1;
              goto out_decref;
            }
          }
          else {
            iVar4 = strncasecmp(pcVar3,DAT_000145b8,0x13);
            if (iVar4 == 0) {
              if ((val != (json_t *)0x0) && (val->type == JSON_ARRAY)) {
                pjVar2 = json_array_get(val,0);
                pcVar3 = json_string_value(pjVar2);
                if (pcVar3 != (char *)0x0) {
                  if (((*DAT_0001483c != '\0') || (*DAT_00014840 != '\0')) || (4 < *DAT_00014844)) {
                    uVar17 = CONCAT44(ppVar18,pcVar3);
                    iVar4 = pool->pool_no;
                    pcVar3 = DAT_0001485c;
                    goto LAB_00014684;
                  }
                  goto LAB_000147fa;
                }
              }
            }
            else {
              iVar4 = strncasecmp(pcVar3,DAT_000145bc,0xb);
              if (iVar4 == 0) {
                if (((*DAT_00014588 != '\0') || (*DAT_0001458c != '\0')) || (5 < *DAT_00014590)) {
                  snprintf(tmp42,0x800,DAT_000145c0,pool->pool_no);
                  _applog(6,tmp42,false);
                }
                unaff_r5 = json_object_get(json,DAT_000145c4);
                if (unaff_r5 == (json_t *)0x0) goto out_decref;
                pjVar2 = json_object_get(json,DAT_000145c4);
                jVar16 = json_integer_value(pjVar2);
                uVar5 = (undefined4)jVar16;
                pcVar3 = DAT_000145c8;
                goto LAB_0001454c;
              }
            }
          }
          goto LAB_00014412;
        }
        pcVar3 = json_array_string(val,0);
        pcVar9 = (char *)0x85c;
        nonce1._0_1_ = _valid_hex(pcVar3,DAT_0001484c,(char *)0x85c,in_r3);
        if (!nonce1._0_1_) {
          if (((*DAT_0001483c != '\0') || (*DAT_00014840 != '\0')) ||
             (unaff_r5 = (json_t *)0x0, 5 < *DAT_00014844)) {
            unaff_r5 = (json_t *)0x0;
            tmp42._0_4_ = *DAT_00014850;
            tmp42._4_4_ = DAT_00014850[1];
            tmp42._8_4_ = DAT_00014850[2];
            tmp42._12_4_ = DAT_00014850[3];
            tmp42._16_4_ = DAT_00014850[4];
            tmp42._20_4_ = DAT_00014850[5];
            tmp42._24_4_ = DAT_00014850[6];
            tmp42._28_4_ = DAT_00014850[7];
            tmp42._32_4_ = DAT_00014850[8];
            tmp42._36_4_ = DAT_00014850[9];
            tmp42._40_4_ = DAT_00014850[10];
            tmp42._44_2_ = (undefined2)DAT_00014850[0xb];
            tmp42[46] = (char)((uint)DAT_00014850[0xb] >> 0x10);
            _applog(6,tmp42,false);
          }
          goto out_decref;
        }
        pjVar2 = json_array_get(val,1);
        jVar16 = json_integer_value(pjVar2);
        if ((uint)jVar16 == 0) {
          if (((*DAT_0001483c != '\0') || (*DAT_00014840 != '\0')) || (5 < *DAT_00014844)) {
            tmp42._0_4_ = *DAT_00014860;
            tmp42._4_4_ = DAT_00014860[1];
            tmp42._8_4_ = DAT_00014860[2];
            tmp42._12_4_ = DAT_00014860[3];
            tmp42._16_4_ = DAT_00014860[4];
            tmp42._20_4_ = DAT_00014860[5];
            tmp42._24_4_ = DAT_00014860[6];
            tmp42._28_4_ = DAT_00014860[7];
            tmp42._32_4_ = DAT_00014860[8];
            tmp42._36_4_ = DAT_00014860[9];
            tmp42._40_4_ = DAT_00014860[10];
            tmp42._44_2_ = (undefined2)DAT_00014860[0xb];
            tmp42[46] = (char)((uint)DAT_00014860[0xb] >> 0x10);
            _applog(6,tmp42,false);
          }
          unaff_r5 = (json_t *)0x0;
          free(pcVar3);
          goto out_decref;
        }
        iVar4 = pthread_mutex_lock((pthread_mutex_t *)&pool->data_lock);
        if (iVar4 != 0) {
          _mutex_lock(DAT_00014a10,(char *)0x868,pcVar9,in_r3);
        }
        ppVar18 = DAT_00014a10;
        ppVar13 = &(pool->data_lock).rwlock;
        _wr_lock(ppVar13,DAT_00014a10->__size,(char *)0x868,in_r3);
        free(pool->nonce1);
        pool->nonce1 = pcVar3;
        sVar6 = strlen(pcVar3);
        pool->n1_len = sVar6 >> 1;
        free(pool->nonce1bin);
        line = ppVar18;
        puVar7 = (uchar *)_cgcalloc(pool->n1_len,1,DAT_00014a14->__size,ppVar18->__size,0x86d);
        pool->nonce1bin = puVar7;
        if (puVar7 == (uchar *)0x0) {
          line = DAT_00014a14;
          snprintf(tmp42,0x800,DAT_00014a2c,DAT_00014a14,ppVar18,0x86f);
          _applog(3,tmp42,true);
          _quit(1);
        }
        hex2bin(pool->nonce1bin,pool->nonce1,pool->n1_len);
        ppVar18 = DAT_00014a10;
        pool->n2size = (uint)jVar16;
        _rw_unlock(ppVar13,ppVar18->__size,(char *)0x872,(int)line);
        _mutex_unlock_noyield(&(pool->data_lock).mutex,DAT_00014a10->__size,(char *)0x872,(int)line)
        ;
        (**DAT_00014a18)();
        if (((*DAT_00014a1c != '\0') || (*DAT_00014a20 != '\0')) || (4 < *DAT_00014a24)) {
          snprintf(tmp42,0x800,DAT_00014a28,pool->pool_no);
          unaff_r5 = (json_t *)0x1;
          _applog(5,tmp42,false);
          goto out_decref;
        }
      }
LAB_000147fa:
      unaff_r5 = (json_t *)0x1;
      goto out_decref;
    }
  }
LAB_00014412:
  unaff_r5 = (json_t *)0x0;
out_decref:
  uVar12 = SUB41(unaff_r5,0);
  if (json->refcount == 0xffffffff) {
    return (_Bool)uVar12;
  }
  sVar10 = json->refcount - 1;
  json->refcount = sVar10;
  if (sVar10 == 0) {
    json_delete(json);
    return (_Bool)uVar12;
  }
  return (_Bool)uVar12;
}

