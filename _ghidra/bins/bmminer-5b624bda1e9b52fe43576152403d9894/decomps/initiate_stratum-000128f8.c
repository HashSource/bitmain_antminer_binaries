
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

_Bool initiate_stratum(pool *pool)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  _Bool _Var4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  size_t sVar11;
  send_ret sVar12;
  json_t *pjVar13;
  json_t *pjVar14;
  long lVar15;
  json_t *val;
  char *pcVar16;
  uchar *p;
  undefined4 uVar17;
  char *func;
  char *func_00;
  undefined4 uVar18;
  char *func_01;
  int line;
  size_t sVar19;
  int line_00;
  char *pcVar20;
  int line_01;
  int line_02;
  int extraout_r3;
  int extraout_r3_00;
  addrinfo *paVar21;
  size_t index;
  pthread_rwlock_t *ppVar22;
  char *sessionid;
  json_int_t jVar23;
  json_t *local_2b7c;
  char *local_2b78;
  char *local_2b74;
  addrinfo *servinfo;
  int tcp_one;
  socklen_t len;
  int err_1;
  timeval tv_timeout;
  addrinfo hints;
  json_error_t err;
  fd_set rw;
  char tmp42 [2048];
  char s [8192];
  
  local_2b7c = (json_t *)0x0;
  bVar1 = 0;
  bVar2 = false;
LAB_00012a20:
  iVar5 = pthread_mutex_lock((pthread_mutex_t *)&pool->stratum_lock);
  if (iVar5 != 0) {
    _mutex_lock((pthread_mutex_t *)"setup_stratum_socket",(char *)0xae1,func_00,line_00);
  }
  pool->stratum_active = false;
  if (pool->sock != 0) {
    close(pool->sock);
  }
  pool->sock = 0;
  iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&pool->stratum_lock);
  if (iVar5 != 0) {
    piVar9 = __errno_location();
    snprintf(tmp42,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar9,"util.c",
             "setup_stratum_socket",0xae6);
    _applog(3,tmp42,true);
    _quit(1);
  }
  (*selective_yield)();
  pcVar20 = opt_socks_proxy;
  hints.ai_flags = 0;
  hints.ai_family = 0;
  hints.ai_protocol = 0;
  hints.ai_addrlen = 0;
  hints.ai_addr = (sockaddr *)0x0;
  hints.ai_canonname = (char *)0x0;
  hints.ai_next = (addrinfo *)0x0;
  hints.ai_socktype = 1;
  if (pool->rpc_proxy == (char *)0x0) {
    if (opt_socks_proxy != (char *)0x0) {
      pool->rpc_proxy = opt_socks_proxy;
      extract_sockaddr(pcVar20,&pool->sockaddr_proxy_url,&pool->sockaddr_proxy_port);
      pool->rpc_proxytype = 3;
      if (pool->rpc_proxy != (char *)0x0) goto LAB_00012a78;
    }
    local_2b78 = pool->sockaddr_url;
    local_2b74 = pool->stratum_port;
  }
  else {
LAB_00012a78:
    local_2b78 = pool->sockaddr_proxy_url;
    local_2b74 = pool->sockaddr_proxy_port;
  }
  iVar5 = getaddrinfo(local_2b78,local_2b74,(addrinfo *)&hints,(addrinfo **)&servinfo);
  paVar21 = servinfo;
  if (iVar5 != 0) {
    if (pool->probed == false) {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800,"Failed to resolve (?wrong URL) %s:%s",local_2b78,local_2b74);
        _applog(4,tmp42,false);
      }
      pool->probed = true;
    }
    else if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      snprintf(tmp42,0x800,"Failed to getaddrinfo for %s:%s",local_2b78,local_2b74);
      _applog(6,tmp42,false);
    }
    goto LAB_0001295c;
  }
joined_r0x00012a9c:
  if (paVar21 == (addrinfo *)0x0) goto LAB_00012c7e;
  iVar5 = socket(paVar21->ai_family,paVar21->ai_socktype,paVar21->ai_protocol);
  if (iVar5 == -1) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      uVar6._0_1_ = 'F';
      uVar6._1_1_ = 'a';
      uVar6._2_1_ = 'i';
      uVar6._3_1_ = 'l';
      uVar17._0_1_ = 'e';
      uVar17._1_1_ = 'd';
      uVar17._2_1_ = ' ';
      uVar17._3_1_ = 's';
      uVar18._0_1_ = 'o';
      uVar18._1_1_ = 'c';
      uVar18._2_1_ = 'k';
      uVar18._3_1_ = 'e';
      pcVar20 = tmp42;
LAB_00012afe:
      *(undefined4 *)pcVar20 = uVar6;
      *(undefined4 *)(pcVar20 + 4) = uVar17;
      *(undefined4 *)(pcVar20 + 8) = uVar18;
      pcVar20[0xc] = 't';
      pcVar20[0xd] = '\0';
      _applog(7,tmp42,false);
    }
LAB_00012b0c:
    paVar21 = paVar21->ai_next;
    goto joined_r0x00012a9c;
  }
  uVar7 = fcntl(iVar5,3,0);
  fcntl(iVar5,4,uVar7 | 0x800);
  iVar8 = connect(iVar5,(sockaddr *)paVar21->ai_addr,paVar21->ai_addrlen);
  if (iVar8 == -1) {
    uVar7 = 0;
    tv_timeout.tv_usec = 0;
    tv_timeout.tv_sec = 1;
    piVar9 = __errno_location();
    if (*piVar9 == 0x73) {
      iVar8 = iVar5 + 0x1f;
      if (-1 < iVar5) {
        iVar8 = iVar5;
      }
      iVar8 = iVar8 >> 5;
LAB_00012b8e:
      if (uVar7 < 0x20) {
LAB_00012c14:
        ((fd_set *)&rw)->fds_bits[uVar7] = 0;
        uVar7 = uVar7 + 1;
        goto LAB_00012b8e;
      }
      ((fd_set *)&rw)->fds_bits[iVar8] =
           1 << (iVar5 % 0x20 & 0xffU) | ((fd_set *)&rw)->fds_bits[iVar8];
      iVar10 = select(iVar5 + 1,(fd_set *)0x0,(fd_set *)&rw,(fd_set *)0x0,(timeval *)&tv_timeout);
      if (iVar10 < 1) {
        uVar7 = 0;
        if ((iVar10 == 0) || (*piVar9 != 4)) goto LAB_00012bcc;
        goto LAB_00012c14;
      }
      if ((((fd_set *)&rw)->fds_bits[iVar8] >> (iVar5 % 0x20 & 0xffU) & 1U) != 0) {
        len = 4;
        iVar8 = getsockopt(iVar5,1,4,&err_1,&len);
        uVar6 = tmp42._24_4_;
        if ((iVar8 == 0) && (err_1 == 0)) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            builtin_strncpy(tmp42,"Succeeded delayed connect",0x1a);
            tmp42._26_2_ = SUB42(uVar6,2);
            _applog(7,tmp42,false);
          }
          goto LAB_00012d30;
        }
      }
LAB_00012bcc:
      close(iVar5);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = 'S';
        tmp42[1] = 'e';
        tmp42[2] = 'l';
        tmp42[3] = 'e';
        tmp42[4] = 'c';
        tmp42[5] = 't';
        tmp42[6] = ' ';
        tmp42[7] = 't';
        tmp42[8] = 'i';
        tmp42[9] = 'm';
        tmp42[10] = 'e';
        tmp42[0xb] = 'o';
        tmp42[0xc] = 'u';
        tmp42[0xd] = 't';
        tmp42[0xe] = '/';
        tmp42[0xf] = 'f';
        pcVar20 = tmp42 + 0x10;
        uVar6._0_1_ = 'a';
        uVar6._1_1_ = 'i';
        uVar6._2_1_ = 'l';
        uVar6._3_1_ = 'e';
        uVar17._0_1_ = 'd';
        uVar17._1_1_ = ' ';
        uVar17._2_1_ = 'c';
        uVar17._3_1_ = 'o';
        uVar18._0_1_ = 'n';
        uVar18._1_1_ = 'n';
        uVar18._2_1_ = 'e';
        uVar18._3_1_ = 'c';
        goto LAB_00012afe;
      }
    }
    else {
      close(iVar5);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        builtin_strncpy(tmp42,"Failed sock connect",0x14);
        _applog(7,tmp42,false);
        paVar21 = paVar21->ai_next;
        goto joined_r0x00012a9c;
      }
    }
    goto LAB_00012b0c;
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
    builtin_strncpy(tmp42,"Succeeded immediate connect",0x1c);
    _applog(4,tmp42,false);
  }
LAB_00012d30:
  block_socket(iVar5);
  freeaddrinfo((addrinfo *)servinfo);
  if (pool->rpc_proxy == (char *)0x0) goto LAB_00012e06;
  switch(pool->rpc_proxytype) {
  case 0:
    bVar3 = http_negotiate(pool,iVar5,false);
    break;
  case 1:
    bVar3 = http_negotiate(pool,iVar5,true);
    break;
  case 2:
    _Var4 = socks4_negotiate(pool,iVar5,false);
    if (!_Var4) goto LAB_0001295c;
    pcVar20 = pool->sockbuf;
    goto joined_r0x00012fe8;
  case 3:
  case 5:
    rw.fds_bits[0]._0_1_ = 5;
    rw.fds_bits[0]._1_1_ = 1;
    rw.fds_bits[0]._2_1_ = 0;
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Attempting to negotiate with %s:%s SOCKS5 proxy",
               pool->sockaddr_proxy_url,pool->sockaddr_proxy_port);
      _applog(7,tmp42,false);
    }
    send(iVar5,&rw,3,0);
    iVar8 = recv_byte(iVar5);
    if ((iVar8 != 5) || (uVar7 = recv_byte(iVar5), uVar7 != rw.fds_bits[0]._2_1_)) {
joined_r0x000133d4:
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800,"Bad response from %s:%s SOCKS5 server",pool->sockaddr_proxy_url,
                 pool->sockaddr_proxy_port);
        _applog(4,tmp42,false);
      }
      goto LAB_0001295c;
    }
    pcVar20 = pool->sockaddr_url;
    rw.fds_bits[0]._0_1_ = 5;
    rw.fds_bits[0]._1_1_ = 1;
    rw.fds_bits[0]._2_1_ = 0;
    rw.fds_bits[0]._3_1_ = 3;
    sVar11 = strlen(pcVar20);
    if (0xfe < (int)sVar11) {
      sVar11 = 0xff;
    }
    rw.fds_bits[1]._0_1_ = (undefined1)sVar11;
    _cg_memcpy((void *)((int)rw.fds_bits + 5),pcVar20,sVar11,"util.c","socks5_negotiate",0xa4c);
    lVar15 = strtol(pool->stratum_port,(char **)0x0,10);
    *(char *)((int)rw.fds_bits + sVar11 + 6) = (char)lVar15;
    *(char *)((int)rw.fds_bits + sVar11 + 5) = (char)((uint)lVar15 >> 8);
    send(iVar5,&rw,sVar11 + 7,0);
    iVar8 = recv_byte(iVar5);
    if ((iVar8 != 5) || (iVar8 = recv_byte(iVar5), iVar8 != 0)) goto joined_r0x000133d4;
    recv_byte(iVar5);
    uVar7 = recv_byte(iVar5);
    if ((uVar7 & 0xff) == 1) {
      recv_byte(iVar5);
      recv_byte(iVar5);
      recv_byte(iVar5);
      recv_byte(iVar5);
      goto LAB_000137d6;
    }
    if ((uVar7 & 0xff) != 3) goto joined_r0x000133d4;
    iVar10 = recv_byte(iVar5);
    iVar8 = 0;
    if (0 < iVar10) {
      do {
        iVar8 = iVar8 + 1;
        recv_byte(iVar5);
      } while (iVar8 != iVar10);
    }
LAB_000137d6:
    recv_byte(iVar5);
    recv_byte(iVar5);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Success negotiating with %s:%s SOCKS5 proxy",pool->sockaddr_proxy_url,
               pool->sockaddr_proxy_port);
      _applog(7,tmp42,false);
    }
LAB_00012e06:
    pcVar20 = pool->sockbuf;
joined_r0x00012fe8:
    if (pcVar20 == (char *)0x0) {
      pcVar20 = (char *)_cgcalloc(0x2000,1,"util.c","setup_stratum_socket",0xb6f);
      pool->sockbuf = pcVar20;
      pool->sockbuf_size = 0x2000;
    }
    pool->sock = iVar5;
    err_1 = 0x1e;
    tcp_one = 1;
    len = 0x2d;
    uVar7 = fcntl(iVar5,3,0);
    fcntl(iVar5,4,uVar7 | 0x800);
    setsockopt(iVar5,1,9,&tcp_one,4);
    if (opt_delaynet == false) {
      fcntl(iVar5,2,1);
    }
    setsockopt(iVar5,6,1,&tcp_one,4);
    setsockopt(iVar5,6,6,&tcp_one,4);
    setsockopt(iVar5,6,4,&len,4);
    setsockopt(iVar5,6,5,&err_1,4);
    if (bVar2) {
      clear_sock(pool);
      swork_id = swork_id + 1;
      sprintf(s,"{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": []}");
    }
    else if (pool->sessionid == (char *)0x0) {
      swork_id = swork_id + 1;
      sprintf(s,"{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": [\"bmminer/2.0.0\"]}");
    }
    else {
      swork_id = swork_id + 1;
      sprintf(s,
              "{\"id\": %d, \"method\": \"mining.subscribe\", \"params\": [\"bmminer/2.0.0\", \"%s\"]}"
             );
    }
    sVar11 = strlen(s);
    sVar12 = __stratum_send(pool,s,sVar11);
    if (sVar12 == SEND_OK) {
      _Var4 = socket_full(pool,0x3c);
      if (_Var4) {
        pcVar20 = recv_line(pool);
        if (pcVar20 == (char *)0x0) {
          bVar3 = true;
        }
        else {
          local_2b7c = json_loads(pcVar20,0,&err);
          free(pcVar20);
          if (local_2b7c != (json_t *)0x0) {
            pjVar13 = json_object_get(local_2b7c,"result");
            pjVar14 = json_object_get(local_2b7c,"error");
            if ((pjVar13 == (json_t *)0x0) || (pjVar13->type == JSON_NULL)) {
              if (pjVar14 != (json_t *)0x0) goto LAB_00013236;
              pcVar16 = (char *)malloc(0x11);
              pcVar20 = (char *)0x0;
              if (pcVar16 != (char *)0x0) {
                builtin_strncpy(pcVar16,"(unknown reason)",0x11);
                pcVar20 = pcVar16;
              }
            }
            else {
              if ((pjVar14 == (json_t *)0x0) || (pjVar14->type == JSON_NULL)) {
                pjVar14 = json_array_get(pjVar13,0);
                if ((pjVar14 != (json_t *)0x0) &&
                   ((pjVar14->type == JSON_ARRAY &&
                    (sVar19 = json_array_size(pjVar14), 0 < (int)sVar19)))) {
                  index = 0;
                  do {
                    val = json_array_get(pjVar14,index);
                    if ((val == (json_t *)0x0) || (val->type != JSON_ARRAY)) break;
                    index = index + 1;
                    pcVar20 = __json_array_string(val,0);
                    if ((pcVar20 != (char *)0x0) &&
                       (iVar5 = strncasecmp(pcVar20,"mining.notify",0xd), iVar5 == 0)) {
                      pcVar20 = json_array_string(val,1);
                      if (pcVar20 != (char *)0x0) goto LAB_00013454;
                      break;
                    }
                  } while (sVar19 != index);
                }
                pcVar20 = (char *)(uint)opt_debug;
                if ((pcVar20 != (char *)0x0) &&
                   (((use_syslog != false || (opt_log_output != false)) ||
                    (pcVar20 = (char *)0x0, 6 < opt_log_level)))) {
                  pcVar20 = (char *)0x0;
                  builtin_strncpy(tmp42,"Failed to get sessionid in initiate_stratum",0x2c);
                  _applog(7,tmp42,false);
                }
LAB_00013454:
                pcVar16 = json_array_string(pjVar13,1);
                _Var4 = _valid_hex(pcVar16,"initiate_stratum",(char *)0xbf0,line_01);
                uVar6 = tmp42._44_4_;
                if (_Var4) {
                  pjVar13 = json_array_get(pjVar13,2);
                  jVar23 = json_integer_value(pjVar13);
                  uVar6 = tmp42._44_4_;
                  if (0xe < (uint)jVar23 - 2) {
                    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level))
                    {
                      builtin_strncpy(tmp42,"Failed to get valid n2size in initiate_stratum",0x2f);
                      tmp42[0x2f] = SUB41(uVar6,3);
                      _applog(6,tmp42,false);
                    }
                    bVar3 = true;
                    free(pcVar20);
                    free(pcVar16);
                    bVar2 = true;
                    goto LAB_0001295e;
                  }
                  if (((pcVar20 != (char *)0x0) && (pool->sessionid != (char *)0x0)) &&
                     ((iVar5 = strcmp(pcVar20,pool->sessionid), iVar5 == 0 &&
                      (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level))))
                     )) {
                    snprintf(tmp42,0x800,
                             "Pool %d successfully negotiated resume with the same session ID",
                             pool->pool_no);
                    _applog(5,tmp42,false);
                  }
                  iVar5 = pthread_mutex_lock((pthread_mutex_t *)&pool->data_lock);
                  if (iVar5 != 0) {
                    _mutex_lock((pthread_mutex_t *)"initiate_stratum",(char *)0xc04,func_01,line_02)
                    ;
                  }
                  ppVar22 = &(pool->data_lock).rwlock;
                  iVar5 = pthread_rwlock_wrlock((pthread_rwlock_t *)ppVar22);
                  if (iVar5 != 0) {
                    piVar9 = __errno_location();
                    snprintf(tmp42,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar9,
                             "util.c","initiate_stratum",0xc04);
                    _applog(3,tmp42,true);
                    _quit(1);
                  }
                  free(pool->nonce1);
                  free(pool->sessionid);
                  pool->nonce1 = pcVar16;
                  pool->sessionid = pcVar20;
                  sVar11 = strlen(pcVar16);
                  pool->n1_len = sVar11 >> 1;
                  free(pool->nonce1bin);
                  p = (uchar *)_cgcalloc(pool->n1_len,1,"util.c","initiate_stratum",0xc0b);
                  pool->nonce1bin = p;
                  hex2bin(p,pool->nonce1,pool->n1_len);
                  pool->n2size = (uint)jVar23;
                  iVar8 = pthread_rwlock_unlock((pthread_rwlock_t *)ppVar22);
                  iVar5 = extraout_r3;
                  if (iVar8 != 0) {
                    piVar9 = __errno_location();
                    snprintf(tmp42,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",
                             *piVar9,"util.c","initiate_stratum",0xc0e);
                    _applog(3,tmp42,true);
                    _quit(1);
                    iVar5 = extraout_r3_00;
                  }
                  _mutex_unlock_noyield
                            (&(pool->data_lock).mutex,"initiate_stratum",(char *)0xc0e,iVar5);
                  (*selective_yield)();
                  if (((pcVar20 != (char *)0x0) && (opt_debug != false)) &&
                     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level))))))
                  {
                    snprintf(tmp42,0x800,"Pool %d stratum session id: %s",pool->pool_no,
                             pool->sessionid);
                    _applog(7,tmp42,false);
                  }
                  if (pool->stratum_url == (char *)0x0) {
                    pool->stratum_url = pool->sockaddr_url;
                  }
                  _Var4 = opt_protocol;
                  pool->next_diff = 0.0;
                  pool->stratum_active = true;
                  pool->sdiff = 1.0;
                  if (((_Var4 != false) && (opt_debug != false)) &&
                     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level))))))
                  {
                    snprintf(tmp42,0x800,
                             "Pool %d confirmed mining.subscribe with extranonce1 %s extran2size %d"
                             ,pool->pool_no,pool->nonce1,pool->n2size);
                    _applog(7,tmp42,false);
                  }
                  _Var4 = true;
                  goto LAB_00013178;
                }
                if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
                  builtin_strncpy(tmp42,"Failed to get valid nonce1 in initiate_stratum",0x2f);
                  tmp42[0x2f] = SUB41(uVar6,3);
                  _applog(6,tmp42,false);
                }
                bVar3 = true;
                free(pcVar20);
                bVar2 = true;
                goto LAB_0001295e;
              }
LAB_00013236:
              pcVar20 = json_dumps(pjVar14,3);
            }
            if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
              snprintf(tmp42,0x800,"JSON-RPC decode failed: %s",pcVar20);
              _applog(6,tmp42,false);
            }
            bVar3 = true;
            free(pcVar20);
            bVar2 = true;
            goto LAB_0001295e;
          }
          if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 6)) {
            bVar3 = true;
            bVar2 = true;
          }
          else {
            bVar3 = true;
            snprintf(tmp42,0x800,"JSON decode failed(%d): %s",err.line,err.text);
            _applog(6,tmp42,false);
            bVar2 = true;
          }
        }
      }
      else {
        if ((opt_debug == false) ||
           (((use_syslog == false && (opt_log_output == false)) && (opt_log_level < 7))))
        goto LAB_000130e0;
        bVar3 = true;
        builtin_strncpy(tmp42,"Timed out waiting for response in initiate_strat",0x30);
        tmp42[0x30] = 'u';
        tmp42[0x31] = 'm';
        tmp42[0x32] = '\0';
        _applog(7,tmp42,false);
      }
    }
    else if ((opt_debug == false) ||
            (((use_syslog == false && (opt_log_output == false)) && (opt_log_level < 7)))) {
LAB_000130e0:
      bVar3 = true;
    }
    else {
      bVar3 = true;
      builtin_strncpy(tmp42,"Failed to send s in initiate_stratum",0x24);
      tmp42._36_4_ = tmp42._36_4_ & 0xffffff00;
      _applog(7,tmp42,false);
    }
    goto LAB_0001295e;
  case 4:
    _Var4 = socks4_negotiate(pool,iVar5,true);
    if (_Var4) goto LAB_00012e06;
    goto LAB_0001295c;
  default:
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"Unsupported proxy type for %s:%s",pool->sockaddr_proxy_url,
               pool->sockaddr_proxy_port);
      _applog(4,tmp42,false);
    }
    goto LAB_0001295c;
  }
  if (!bVar3) goto LAB_0001295c;
  goto LAB_00012e06;
LAB_00012c7e:
  if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
    snprintf(tmp42,0x800,"Failed to connect to stratum on %s:%s",local_2b78,local_2b74);
    _applog(6,tmp42,false);
  }
  freeaddrinfo((addrinfo *)servinfo);
LAB_0001295c:
  bVar3 = false;
LAB_0001295e:
  if (!(bool)(bVar2 & (bVar1 ^ 1))) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"Initiate stratum failed",0x18);
      _applog(7,tmp42,false);
    }
    if (bVar3) {
      suspend_stratum(pool);
    }
    if (local_2b7c == (json_t *)0x0) {
      _Var4 = false;
    }
    else {
      _Var4 = false;
LAB_00013178:
      if ((local_2b7c->refcount != 0xffffffff) &&
         (sVar19 = local_2b7c->refcount - 1, local_2b7c->refcount = sVar19, sVar19 == 0)) {
        json_delete(local_2b7c);
      }
    }
    return _Var4;
  }
  iVar5 = pthread_mutex_lock((pthread_mutex_t *)&pool->data_lock);
  if (iVar5 != 0) {
    _mutex_lock((pthread_mutex_t *)"initiate_stratum",(char *)0xc2a,func,line);
  }
  ppVar22 = &(pool->data_lock).rwlock;
  iVar5 = pthread_rwlock_wrlock((pthread_rwlock_t *)ppVar22);
  if (iVar5 != 0) {
    piVar9 = __errno_location();
    snprintf(tmp42,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar9,"util.c",
             "initiate_stratum",0xc2a);
    _applog(3,tmp42,true);
    _quit(1);
  }
  free(pool->sessionid);
  free(pool->nonce1);
  pool->nonce1 = (char *)0x0;
  pool->sessionid = (char *)0x0;
  iVar5 = pthread_rwlock_unlock((pthread_rwlock_t *)ppVar22);
  if (iVar5 != 0) {
    piVar9 = __errno_location();
    snprintf(tmp42,0x800,"WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar9,"util.c",
             "initiate_stratum",0xc2e);
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&pool->data_lock);
  if (iVar5 != 0) {
    piVar9 = __errno_location();
    snprintf(tmp42,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar9,"util.c",
             "initiate_stratum",0xc2e);
    _applog(3,tmp42,true);
    _quit(1);
  }
  (*selective_yield)();
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    builtin_strncpy(tmp42,"Failed to resume stratum, trying afresh",0x28);
    _applog(7,tmp42,false);
  }
  if (((local_2b7c != (json_t *)0x0) && (local_2b7c->refcount != 0xffffffff)) &&
     (sVar19 = local_2b7c->refcount - 1, local_2b7c->refcount = sVar19, sVar19 == 0)) {
    json_delete(local_2b7c);
  }
  bVar1 = 1;
  goto LAB_00012a20;
}

