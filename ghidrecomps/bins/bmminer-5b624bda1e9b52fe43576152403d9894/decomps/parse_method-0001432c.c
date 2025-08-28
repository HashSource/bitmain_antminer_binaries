
/* WARNING: Unknown calling convention */

_Bool parse_method(pool *pool,char *s)

{
  _Bool _Var1;
  json_t *json;
  json_t *pjVar2;
  json_t *json_00;
  json_t *val;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  size_t sVar7;
  int iVar8;
  uchar *puVar9;
  int *piVar10;
  char *func;
  char *func_00;
  size_t sVar11;
  int line;
  double *pdVar12;
  int line_00;
  int line_01;
  int line_02;
  int line_03;
  int extraout_r3;
  undefined1 uVar13;
  json_t *unaff_r5;
  uint index;
  pthread_rwlock_t *ppVar14;
  double dVar15;
  double dVar16;
  json_int_t jVar17;
  undefined8 in_stack_ffffdec0;
  undefined8 uVar18;
  json_error_t err;
  char tmp42 [2048];
  
  pcVar3 = (char *)((ulonglong)in_stack_ffffdec0 >> 0x20);
  if (s == (char *)0x0) {
    return false;
  }
  json = json_loads(s,0,&err);
  if (json == (json_t *)0x0) {
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 6)) {
      return false;
    }
    snprintf(tmp42,0x800,"JSON decode failed(%d): %s",err.line,err.text);
    _applog(6,tmp42,false);
    return false;
  }
  pjVar2 = json_object_get(json,"method");
  if (pjVar2 != (json_t *)0x0) {
    json_00 = json_object_get(json,"error");
    val = json_object_get(json,"params");
    if ((json_00 != (json_t *)0x0) && (json_00->type != JSON_NULL)) {
      pcVar3 = json_dumps(json_00,3);
      if ((use_syslog != false) || ((opt_log_output != false || (5 < opt_log_level)))) {
        snprintf(tmp42,0x800,"JSON-RPC method decode failed: %s",pcVar3);
        _applog(6,tmp42,false);
      }
      unaff_r5 = (json_t *)0x0;
      free(pcVar3);
      goto LAB_000143b8;
    }
    pcVar4 = json_string_value(pjVar2);
    if (pcVar4 != (char *)0x0) {
      iVar5 = strncasecmp(pcVar4,"mining.multi_version",0x14);
      uVar6 = tmp42._24_4_;
      if (iVar5 == 0) {
        pool->support_vil = true;
        if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
          builtin_strncpy(tmp42,"Pool support multi version",0x1b);
          tmp42[0x1b] = SUB41(uVar6,3);
          _applog(6,tmp42,false);
        }
        index = 0;
        while( true ) {
          sVar11 = json_array_size(val);
          if (sVar11 <= index) break;
          pjVar2 = json_array_get(val,index);
          jVar17 = json_integer_value(pjVar2);
          pool->version[0] = (int)jVar17;
          index = index + 1;
          pool = (pool *)&pool->prio;
        }
        goto LAB_000143b8;
      }
      iVar5 = strncasecmp(pcVar4,"mining.notify",0xd);
      if (iVar5 == 0) {
        _Var1 = parse_notify(pool,val);
        if (_Var1) {
          unaff_r5 = (json_t *)0x1;
          pool->stratum_notify = true;
        }
        else {
          pool->stratum_notify = _Var1;
          unaff_r5 = (json_t *)0x0;
        }
        goto LAB_000143b8;
      }
      iVar5 = strncasecmp(pcVar4,"mining.set_difficulty",0x15);
      if (iVar5 == 0) {
        pjVar2 = json_array_get(val,0);
        dVar15 = json_number_value(pjVar2);
        unaff_r5 = (json_t *)0x0;
        if (dVar15 == 0.0) goto LAB_000143b8;
        iVar5 = pthread_mutex_lock((pthread_mutex_t *)&pool->data_lock);
        if (iVar5 != 0) {
          _mutex_lock((pthread_mutex_t *)"parse_diff",(char *)0x830,func,line);
        }
        ppVar14 = &(pool->data_lock).rwlock;
        iVar5 = pthread_rwlock_wrlock((pthread_rwlock_t *)ppVar14);
        if (iVar5 != 0) {
          piVar10 = __errno_location();
          pcVar3 = "parse_diff";
          snprintf(tmp42,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar10,"util.c",
                   "parse_diff",0x830);
          _applog(3,tmp42,true);
          _quit(1);
        }
        pdVar12 = &pool->next_diff;
        dVar16 = *pdVar12;
        if (dVar16 <= 0.0) {
          *pdVar12 = dVar15;
          dVar16 = pool->sdiff;
          pool->sdiff = dVar15;
        }
        else {
          *pdVar12 = dVar15;
        }
        iVar5 = pthread_rwlock_unlock((pthread_rwlock_t *)ppVar14);
        if (iVar5 != 0) {
          piVar10 = __errno_location();
          pcVar3 = "parse_diff";
          snprintf(tmp42,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar10,
                   "util.c","parse_diff",0x83d);
          _applog(3,tmp42,true);
          _quit(1);
        }
        iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&pool->data_lock);
        if (iVar5 != 0) {
          piVar10 = __errno_location();
          pcVar3 = "parse_diff";
          snprintf(tmp42,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar10,"util.c"
                   ,"parse_diff",0x83d);
          _applog(3,tmp42,true);
          _quit(1);
        }
        (*selective_yield)();
        if (dVar15 == dVar16) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            unaff_r5 = (json_t *)0x1;
            snprintf(tmp42,0x800,"Pool %d difficulty set to %f",pool->pool_no,dVar15);
            _applog(7,tmp42,false);
            goto LAB_000143b8;
          }
        }
        else if (dVar15 == (double)(longlong)(int)(longlong)dVar15) {
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            uVar18 = CONCAT44(pcVar3,(int)(longlong)dVar15);
            iVar5 = pool->pool_no;
            pcVar3 = "Pool %d difficulty changed to %d";
LAB_00014684:
            snprintf(tmp42,0x800,pcVar3,iVar5,uVar18);
LAB_00014688:
            unaff_r5 = (json_t *)0x1;
            _applog(5,tmp42,false);
            goto LAB_000143b8;
          }
        }
        else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"Pool %d difficulty changed to %.1f",pool->pool_no,dVar15);
          goto LAB_00014688;
        }
      }
      else {
        iVar5 = strncasecmp(pcVar4,"mining.set_extranonce",0x15);
        if (iVar5 != 0) {
          iVar5 = strncasecmp(pcVar4,"client.reconnect",0x10);
          if (iVar5 == 0) {
            _Var1 = parse_reconnect(pool,val);
            unaff_r5 = (json_t *)(uint)_Var1;
            goto LAB_000143b8;
          }
          iVar5 = strncasecmp(pcVar4,"client.get_version",0x12);
          if (iVar5 == 0) {
            pjVar2 = json_object_get(json,"id");
            if (pjVar2 != (json_t *)0x0) {
              pjVar2 = json_object_get(json,"id");
              jVar17 = json_integer_value(pjVar2);
              uVar6 = (undefined4)jVar17;
              pcVar3 = "{\"id\": %d, \"result\": \"bmminer/2.0.0\", \"error\": null}";
LAB_0001454c:
              sprintf(tmp42,pcVar3,uVar6);
              sVar7 = strlen(tmp42);
              _Var1 = stratum_send(pool,tmp42,sVar7);
              unaff_r5 = (json_t *)(uint)_Var1;
              goto LAB_000143b8;
            }
          }
          else {
            iVar5 = strncasecmp(pcVar4,"client.show_message",0x13);
            if (iVar5 == 0) {
              if ((val != (json_t *)0x0) && (val->type == JSON_ARRAY)) {
                pjVar2 = json_array_get(val,0);
                pcVar4 = json_string_value(pjVar2);
                if (pcVar4 != (char *)0x0) {
                  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                    uVar18 = CONCAT44(pcVar3,pcVar4);
                    iVar5 = pool->pool_no;
                    pcVar3 = "Pool %d message: %s";
                    goto LAB_00014684;
                  }
                  goto LAB_000147fa;
                }
              }
            }
            else {
              iVar5 = strncasecmp(pcVar4,"mining.ping",0xb);
              if (iVar5 == 0) {
                if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
                  snprintf(tmp42,0x800,"Pool %d ping",pool->pool_no);
                  _applog(6,tmp42,false);
                }
                unaff_r5 = json_object_get(json,"id");
                if (unaff_r5 == (json_t *)0x0) goto LAB_000143b8;
                pjVar2 = json_object_get(json,"id");
                jVar17 = json_integer_value(pjVar2);
                uVar6 = (undefined4)jVar17;
                pcVar3 = "{\"id\": %d, \"result\": \"pong\", \"error\": null}";
                goto LAB_0001454c;
              }
            }
          }
          goto LAB_00014412;
        }
        pcVar3 = json_array_string(val,0);
        _Var1 = _valid_hex(pcVar3,"parse_extranonce",(char *)0x85c,line_00);
        if (!_Var1) {
          if (((use_syslog != false) || (opt_log_output != false)) ||
             (unaff_r5 = (json_t *)0x0, 5 < opt_log_level)) {
            unaff_r5 = (json_t *)0x0;
            builtin_strncpy(tmp42,"Failed to get valid nonce1 in parse_extranon",0x2c);
            tmp42[0x2c] = 'c';
            tmp42[0x2d] = 'e';
            tmp42[0x2e] = '\0';
            _applog(6,tmp42,false);
          }
          goto LAB_000143b8;
        }
        pjVar2 = json_array_get(val,1);
        jVar17 = json_integer_value(pjVar2);
        if ((uint)jVar17 == 0) {
          if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
            builtin_strncpy(tmp42,"Failed to get valid n2size in parse_extranon",0x2c);
            tmp42[0x2c] = 'c';
            tmp42[0x2d] = 'e';
            tmp42[0x2e] = '\0';
            _applog(6,tmp42,false);
          }
          unaff_r5 = (json_t *)0x0;
          free(pcVar3);
          goto LAB_000143b8;
        }
        iVar8 = pthread_mutex_lock((pthread_mutex_t *)&pool->data_lock);
        iVar5 = line_01;
        if (iVar8 != 0) {
          _mutex_lock((pthread_mutex_t *)"parse_extranonce",(char *)0x868,func_00,line_01);
          iVar5 = extraout_r3;
        }
        ppVar14 = &(pool->data_lock).rwlock;
        _wr_lock(ppVar14,"parse_extranonce",(char *)0x868,iVar5);
        free(pool->nonce1);
        pool->nonce1 = pcVar3;
        sVar7 = strlen(pcVar3);
        pool->n1_len = sVar7 >> 1;
        free(pool->nonce1bin);
        puVar9 = (uchar *)_cgcalloc(pool->n1_len,1,"util.c","parse_extranonce",0x86d);
        pool->nonce1bin = puVar9;
        if (puVar9 == (uchar *)0x0) {
          snprintf(tmp42,0x800,"Failed to calloc pool->nonce1bin in %s %s():%d","util.c",
                   "parse_extranonce",0x86f);
          _applog(3,tmp42,true);
          _quit(1);
        }
        hex2bin(pool->nonce1bin,pool->nonce1,pool->n1_len);
        pool->n2size = (uint)jVar17;
        _rw_unlock(ppVar14,"parse_extranonce",(char *)0x872,line_02);
        _mutex_unlock_noyield(&(pool->data_lock).mutex,"parse_extranonce",(char *)0x872,line_03);
        (*selective_yield)();
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"Pool %d extranonce change requested",pool->pool_no);
          unaff_r5 = (json_t *)0x1;
          _applog(5,tmp42,false);
          goto LAB_000143b8;
        }
      }
LAB_000147fa:
      unaff_r5 = (json_t *)0x1;
      goto LAB_000143b8;
    }
  }
LAB_00014412:
  unaff_r5 = (json_t *)0x0;
LAB_000143b8:
  uVar13 = SUB41(unaff_r5,0);
  if (json->refcount == 0xffffffff) {
    return (_Bool)uVar13;
  }
  sVar11 = json->refcount - 1;
  json->refcount = sVar11;
  if (sVar11 == 0) {
    json_delete(json);
    return (_Bool)uVar13;
  }
  return (_Bool)uVar13;
}

