
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

_Bool initiate_stratum(pool *pool)

{
  char cVar1;
  pthread_mutex_t *ppVar2;
  uchar atyp;
  ushort port;
  int iVar5;
  int sockd;
  uint uVar6;
  int flags;
  int iVar7;
  int *piVar8;
  int iVar9;
  int selret;
  int n;
  int flags_1;
  bool bVar3;
  _Bool _Var4;
  send_ret sVar10;
  json_t *pjVar11;
  json_t *res_val;
  json_t *pjVar12;
  json_t *err_val;
  undefined4 *puVar13;
  char *__retval;
  int len_1;
  long lVar14;
  json_t *arr_val;
  int arrsize;
  json_t *val;
  json_t *arr;
  char *s_00;
  char *nonce1;
  char *pcVar15;
  char *notify;
  size_t sVar16;
  uchar *p_00;
  pthread_mutex_t **pppVar17;
  undefined4 uVar18;
  _Bool *in_r2;
  int *piVar19;
  undefined2 uVar20;
  uint in_r3;
  char *pcVar21;
  size_t sVar22;
  undefined4 uVar23;
  pthread_mutex_t *line;
  addrinfo *p;
  addrinfo *paVar24;
  size_t index;
  pthread_rwlock_t *ppVar25;
  undefined4 uVar26;
  uint __i;
  _Bool *p_Var27;
  char *ss;
  uchar uclen;
  char *sessionid;
  json_int_t jVar28;
  json_t *local_2b7c;
  char *sockaddr_url;
  char *sockaddr_port;
  uint local_2b70;
  uint local_2b68;
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
  local_2b70 = 0;
  local_2b68 = 0;
LAB_00012a20:
  iVar5 = pthread_mutex_lock((pthread_mutex_t *)&pool->stratum_lock);
  if (iVar5 != 0) {
    _mutex_lock(DAT_0001398c,(char *)0xae1,in_r2,in_r3);
  }
  pool->stratum_active = false;
  if (pool->sock != 0) {
    close(pool->sock);
  }
  pool->sock = 0;
  iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&pool->stratum_lock);
  ppVar2 = DAT_0001398c;
  if (iVar5 != 0) {
    piVar19 = __errno_location();
    snprintf(tmp42,0x800,DAT_00013990,*piVar19,"util.c",ppVar2,0xae6);
    _applog(3,tmp42,true);
    _quit(1);
  }
  (*selective_yield)();
  pcVar21 = opt_socks_proxy;
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
      extract_sockaddr(pcVar21,&pool->sockaddr_proxy_url,&pool->sockaddr_proxy_port);
      pool->rpc_proxytype = 3;
      if (pool->rpc_proxy != (char *)0x0) goto LAB_00012a78;
    }
    sockaddr_url = pool->sockaddr_url;
    sockaddr_port = pool->stratum_port;
  }
  else {
LAB_00012a78:
    sockaddr_url = pool->sockaddr_proxy_url;
    sockaddr_port = pool->sockaddr_proxy_port;
  }
  in_r2 = (_Bool *)&hints;
  iVar5 = getaddrinfo(sockaddr_url,sockaddr_port,(addrinfo *)in_r2,(addrinfo **)&servinfo);
  p_Var27 = DAT_00012ab4;
  paVar24 = servinfo;
  if (iVar5 != 0) {
    if (pool->probed == false) {
      if (((use_syslog != false) || (*DAT_00012aa8 != '\0')) || (3 < (int)*DAT_00012aac)) {
        snprintf(tmp42,0x800,DAT_00012ab0,sockaddr_url,sockaddr_port);
        in_r2 = (_Bool *)0x0;
        _applog(4,tmp42,false);
      }
      p_Var27 = DAT_00012ab4;
      pool->probed = true;
    }
    else if (((use_syslog != false) || (*DAT_00013020 != '\0')) ||
            (p_Var27 = DAT_00013028, 5 < *DAT_00013024)) {
      snprintf(tmp42,0x800,DAT_0001302c,sockaddr_url,sockaddr_port);
      p_Var27 = DAT_00013028;
      in_r2 = (_Bool *)0x0;
      _applog(6,tmp42,false);
    }
    goto LAB_0001295c;
  }
joined_r0x00012a9c:
  if (paVar24 == (addrinfo *)0x0) goto LAB_00012c7e;
  piVar19 = (int *)paVar24->ai_protocol;
  iVar5 = socket(paVar24->ai_family,paVar24->ai_socktype,(int)piVar19);
  if (iVar5 == -1) {
    p_Var27 = DAT_00012d64;
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) ||
        (piVar19 = (int *)&opt_log_output, 6 < opt_log_level)))) {
      uVar20 = (undefined2)ram0x00045884;
      puVar13 = (undefined4 *)tmp42;
      uVar18 = s_Failed_socket_00045878._0_4_;
      uVar23 = s_Failed_socket_00045878._4_4_;
      uVar26 = s_Failed_socket_00045878._8_4_;
LAB_00012afe:
      *puVar13 = uVar18;
      puVar13[1] = uVar23;
      puVar13[2] = uVar26;
      piVar19 = (int *)0x0;
      *(undefined2 *)(puVar13 + 3) = uVar20;
      _applog(7,tmp42,false);
    }
    goto LAB_00012b0c;
  }
  uVar6 = fcntl(iVar5,3,0);
  fcntl(iVar5,4,uVar6 | 0x800);
  in_r2 = (_Bool *)paVar24->ai_addrlen;
  iVar7 = connect(iVar5,(sockaddr *)paVar24->ai_addr,(socklen_t)in_r2);
  if (iVar7 == -1) {
    __i = 0;
    tv_timeout.tv_usec = 0;
    tv_timeout.tv_sec = 1;
    piVar8 = __errno_location();
    if (*piVar8 == 0x73) {
      iVar7 = iVar5 + 0x1f;
      if (-1 < iVar5) {
        iVar7 = iVar5;
      }
      iVar7 = iVar7 >> 5;
LAB_00012b8e:
      if (__i < 0x20) {
LAB_00012c14:
        *(int *)((int)((json_error_t *)&rw)->source + (__i - 3) * 4) = 0;
        __i = __i + 1;
        goto LAB_00012b8e;
      }
      *(int *)((int)((json_error_t *)&rw)->source + (iVar7 + -3) * 4) =
           1 << (iVar5 % 0x20 & 0xffU) |
           *(int *)((int)((json_error_t *)&rw)->source + (iVar7 + -3) * 4);
      piVar19 = (int *)(json_error_t *)&rw;
      iVar9 = select(iVar5 + 1,(fd_set *)0x0,(fd_set *)(json_error_t *)&rw,(fd_set *)0x0,
                     (timeval *)&tv_timeout);
      if (iVar9 < 1) {
        __i = 0;
        if ((iVar9 == 0) || (*piVar8 != 4)) goto LAB_00012bcc;
        goto LAB_00012c14;
      }
      if ((*(int *)((int)((json_error_t *)&rw)->source + (iVar7 + -3) * 4) >> (iVar5 % 0x20 & 0xffU)
          & 1U) != 0) {
        in_r2 = (_Bool *)0x4;
        len = 4;
        iVar7 = getsockopt(iVar5,1,4,&err_1,&len);
        piVar19 = (int *)in_r2;
        if ((iVar7 == 0) && (err_1 == 0)) {
          if ((opt_debug != false) &&
             (((in_r2 = &use_syslog, use_syslog != false || (*DAT_00012d70 != '\0')) ||
              (6 < *DAT_00013560)))) {
            tmp42._0_4_ = *DAT_00012d7c;
            tmp42._4_4_ = DAT_00012d7c[1];
            tmp42._8_4_ = DAT_00012d7c[2];
            tmp42._12_4_ = DAT_00012d7c[3];
            tmp42._16_4_ = DAT_00012d7c[4];
            tmp42._20_4_ = DAT_00012d7c[5];
            tmp42[24] = (char)(short)DAT_00012d7c[6];
            tmp42[25] = (char)((ushort)(short)DAT_00012d7c[6] >> 8);
            in_r2 = (_Bool *)0x0;
            _applog(7,tmp42,false);
          }
          goto LAB_00012d30;
        }
      }
LAB_00012bcc:
      close(iVar5);
      p_Var27 = &opt_debug;
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) ||
          (piVar19 = &opt_log_level, 6 < opt_log_level)))) {
        tmp42._0_4_ = *DAT_00012d68;
        tmp42._4_4_ = DAT_00012d68[1];
        tmp42._8_4_ = DAT_00012d68[2];
        tmp42._12_4_ = DAT_00012d68[3];
        puVar13 = (undefined4 *)(tmp42 + 0x10);
        uVar20 = (undefined2)DAT_00012d68[7];
        uVar18 = DAT_00012d68[4];
        uVar23 = DAT_00012d68[5];
        uVar26 = DAT_00012d68[6];
        goto LAB_00012afe;
      }
LAB_00012b0c:
      paVar24 = paVar24->ai_next;
      in_r2 = (_Bool *)piVar19;
    }
    else {
      p_Var27 = &opt_debug;
      close(iVar5);
      piVar19 = (int *)in_r2;
      if ((opt_debug == false) ||
         (((use_syslog == false && (opt_log_output == false)) &&
          (piVar19 = (int *)&opt_log_output, opt_log_level < 7)))) goto LAB_00012b0c;
      tmp42._0_4_ = *DAT_00012d6c;
      tmp42._4_4_ = DAT_00012d6c[1];
      tmp42._8_4_ = DAT_00012d6c[2];
      tmp42._12_4_ = DAT_00012d6c[3];
      tmp42._16_4_ = DAT_00012d6c[4];
      in_r2 = (_Bool *)0x0;
      _applog(7,tmp42,false);
      paVar24 = paVar24->ai_next;
    }
    goto joined_r0x00012a9c;
  }
  if (((use_syslog != false) || (*DAT_00013020 != '\0')) || (3 < *DAT_00013024)) {
    tmp42._0_4_ = *DAT_00013030;
    tmp42._4_4_ = DAT_00013030[1];
    tmp42._8_4_ = DAT_00013030[2];
    tmp42._12_4_ = DAT_00013030[3];
    tmp42._16_4_ = DAT_00013030[4];
    tmp42._20_4_ = DAT_00013030[5];
    tmp42._24_4_ = DAT_00013030[6];
    in_r2 = (_Bool *)0x0;
    _applog(4,tmp42,false);
  }
LAB_00012d30:
  block_socket(iVar5);
  freeaddrinfo((addrinfo *)servinfo);
  p_Var27 = DAT_00013028;
  if (pool->rpc_proxy == (char *)0x0) goto LAB_00012e06;
  switch(pool->rpc_proxytype) {
  case 0:
    in_r2 = (_Bool *)0x0;
    bVar3 = http_negotiate(pool,iVar5,false);
    p_Var27 = DAT_00013028;
    break;
  case 1:
    in_r2 = (_Bool *)0x1;
    bVar3 = http_negotiate(pool,iVar5,true);
    p_Var27 = DAT_00013028;
    break;
  case 2:
    in_r2 = (_Bool *)0x0;
    _Var4 = socks4_negotiate(pool,iVar5,false);
    p_Var27 = DAT_00013028;
    if (!_Var4) goto LAB_0001295c;
    pcVar21 = pool->sockbuf;
    goto joined_r0x00012fe8;
  case 3:
  case 5:
    rw.fds_bits[0]._0_1_ = 5;
    rw.fds_bits[0]._1_1_ = 1;
    rw.fds_bits[0]._2_1_ = 0;
    if ((opt_debug != false) &&
       (((use_syslog != false || (*DAT_00013020 != '\0')) || (6 < *DAT_000132c0)))) {
      snprintf(tmp42,0x800,DAT_00013044,pool->sockaddr_proxy_url,pool->sockaddr_proxy_port);
      _applog(7,tmp42,false);
    }
    in_r2 = (_Bool *)0x3;
    send(iVar5,&rw,3,0);
    iVar7 = recv_byte(iVar5);
    if ((iVar7 != 5) ||
       (uVar6 = recv_byte(iVar5), pcVar21 = DAT_0001356c, uVar6 != rw.fds_bits[0]._2_1_)) {
joined_r0x000133d4:
      if (((use_syslog != false) || (*DAT_00013020 != '\0')) || (3 < *DAT_00013024)) {
        snprintf(tmp42,0x800,DAT_00013048,pool->sockaddr_proxy_url,pool->sockaddr_proxy_port);
        in_r2 = (_Bool *)0x0;
        _applog(4,tmp42,false);
      }
      goto LAB_0001295c;
    }
    pcVar15 = pool->sockaddr_url;
    rw.fds_bits[0]._0_1_ = 5;
    rw.fds_bits[0]._1_1_ = 1;
    rw.fds_bits[0]._2_1_ = 0;
    rw.fds_bits[0]._3_1_ = 3;
    sVar16 = strlen(pcVar15);
    if (0xfe < (int)sVar16) {
      sVar16 = 0xff;
    }
    rw.fds_bits[1]._0_1_ = (undefined)sVar16;
    _cg_memcpy((void *)((int)rw.fds_bits + 5),pcVar15,sVar16,DAT_00013570,pcVar21,0xa4c);
    lVar14 = strtol(pool->stratum_port,(char **)0x0,10);
    in_r2 = (_Bool *)(sVar16 + 7);
    *(char *)((int)rw.fds_bits + sVar16 + 6) = (char)lVar14;
    *(char *)((int)rw.fds_bits + sVar16 + 5) = (char)((uint)lVar14 >> 8);
    send(iVar5,&rw,(size_t)in_r2,0);
    iVar7 = recv_byte(iVar5);
    if ((iVar7 != 5) || (iVar7 = recv_byte(iVar5), iVar7 != 0)) goto joined_r0x000133d4;
    recv_byte(iVar5);
    uVar6 = recv_byte(iVar5);
    if ((uVar6 & 0xff) == 1) {
      recv_byte(iVar5);
      recv_byte(iVar5);
      recv_byte(iVar5);
      recv_byte(iVar5);
      goto LAB_000137d6;
    }
    if ((uVar6 & 0xff) != 3) goto joined_r0x000133d4;
    iVar9 = recv_byte(iVar5);
    iVar7 = 0;
    if (0 < iVar9) {
      do {
        iVar7 = iVar7 + 1;
        recv_byte(iVar5);
      } while (iVar7 != iVar9);
    }
LAB_000137d6:
    recv_byte(iVar5);
    recv_byte(iVar5);
    if ((opt_debug != false) &&
       (((use_syslog != false || (*DAT_00013870 != '\0')) || (6 < (int)*DAT_00013874)))) {
      snprintf(tmp42,0x800,DAT_0001389c,pool->sockaddr_proxy_url,pool->sockaddr_proxy_port);
      _applog(7,tmp42,false);
    }
LAB_00012e06:
    pcVar21 = pool->sockbuf;
joined_r0x00012fe8:
    if (pcVar21 == (char *)0x0) {
      pcVar21 = (char *)_cgcalloc(0x2000,1,DAT_00013050,DAT_0001304c,0xb6f);
      pool->sockbuf = pcVar21;
      pool->sockbuf_size = 0x2000;
    }
    pool->sock = iVar5;
    err_1 = 0x1e;
    tcp_one = 1;
    len = 0x2d;
    uVar6 = fcntl(iVar5,3,0);
    fcntl(iVar5,4,uVar6 | 0x800);
    setsockopt(iVar5,1,9,&tcp_one,4);
    if (*DAT_00013034 == '\0') {
      fcntl(iVar5,2,1);
    }
    setsockopt(iVar5,6,1,&tcp_one,4);
    setsockopt(iVar5,6,6,&tcp_one,4);
    setsockopt(iVar5,6,4,&len,4);
    setsockopt(iVar5,6,5,&err_1,4);
    pcVar15 = DAT_000132dc;
    pcVar21 = DAT_0001303c;
    if (local_2b68 == 0) {
      if (pool->sessionid == (char *)0x0) {
        *DAT_000132cc = *DAT_000132cc + 1;
        sprintf(s,pcVar15);
      }
      else {
        *DAT_00013038 = *DAT_00013038 + 1;
        sprintf(s,pcVar21);
      }
    }
    else {
      clear_sock(pool);
      pcVar21 = DAT_000132d0;
      *DAT_000132cc = *DAT_000132cc + 1;
      sprintf(s,pcVar21);
    }
    in_r2 = (_Bool *)strlen(s);
    sVar10 = __stratum_send(pool,s,(ssize_t)in_r2);
    p_Var27 = DAT_00013028;
    if (sVar10 == SEND_OK) {
      _Var4 = socket_full(pool,0x3c);
      p_Var27 = DAT_000132c8;
      if (!_Var4) {
        in_r2 = &opt_debug;
        if ((opt_debug == false) ||
           (((use_syslog == false && (*DAT_000132bc == '\0')) && (*DAT_000132c0 < 7))))
        goto LAB_000130e0;
        bVar3 = true;
        tmp42._0_4_ = *DAT_000132e0;
        tmp42._4_4_ = DAT_000132e0[1];
        tmp42._8_4_ = DAT_000132e0[2];
        tmp42._12_4_ = DAT_000132e0[3];
        tmp42._16_4_ = DAT_000132e0[4];
        tmp42._20_4_ = DAT_000132e0[5];
        tmp42._24_4_ = DAT_000132e0[6];
        tmp42._28_4_ = DAT_000132e0[7];
        tmp42._32_4_ = DAT_000132e0[8];
        tmp42._36_4_ = DAT_000132e0[9];
        tmp42._40_4_ = DAT_000132e0[10];
        tmp42._44_4_ = DAT_000132e0[0xb];
        in_r2 = (_Bool *)0x0;
        tmp42._48_2_ = (undefined2)DAT_000132e0[0xc];
        tmp42[50] = (char)((uint)DAT_000132e0[0xc] >> 0x10);
        _applog(7,tmp42,false);
        goto LAB_0001295e;
      }
      pcVar21 = recv_line(pool);
      if (pcVar21 == (char *)0x0) {
        bVar3 = true;
        p_Var27 = DAT_000132c8;
      }
      else {
        in_r2 = (_Bool *)&err;
        local_2b7c = json_loads(pcVar21,0,(json_error_t *)in_r2);
        free(pcVar21);
        p_Var27 = DAT_00013564;
        if (local_2b7c == (json_t *)0x0) {
          if (((use_syslog == false) && (*DAT_0001355c == '\0')) && (*DAT_00013560 < 6)) {
            bVar3 = true;
            local_2b68 = 1;
          }
          else {
            bVar3 = true;
            snprintf(tmp42,0x800,DAT_00013568,err.line,err.text);
            in_r2 = (_Bool *)0x0;
            _applog(6,tmp42,false);
            local_2b68 = 1;
          }
        }
        else {
          pjVar11 = json_object_get(local_2b7c,DAT_000132e4);
          pjVar12 = json_object_get(local_2b7c,DAT_000132e8);
          if ((pjVar11 == (json_t *)0x0) || (pjVar11->type == JSON_NULL)) {
            if (pjVar12 != (json_t *)0x0) goto LAB_00013236;
            puVar13 = (undefined4 *)malloc(0x11);
            ss = (char *)0x0;
            if (puVar13 != (undefined4 *)0x0) {
              uVar18 = DAT_000132f0[1];
              in_r2 = (_Bool *)DAT_000132f0[2];
              uVar23 = DAT_000132f0[3];
              uVar26 = DAT_000132f0[4];
              *puVar13 = *DAT_000132f0;
              puVar13[1] = uVar18;
              puVar13[2] = in_r2;
              puVar13[3] = uVar23;
              *(char *)(puVar13 + 4) = (char)uVar26;
              ss = (char *)puVar13;
            }
          }
          else {
            if ((pjVar12 == (json_t *)0x0) || (pjVar12->type == JSON_NULL)) {
              pjVar12 = json_array_get(pjVar11,0);
              if ((pjVar12 != (json_t *)0x0) &&
                 ((pcVar21 = (char *)pjVar12->type, pcVar21 == (char *)0x1 &&
                  (sVar22 = json_array_size(pjVar12), 0 < (int)sVar22)))) {
                index = 0;
                do {
                  val = json_array_get(pjVar12,index);
                  if ((val == (json_t *)0x0) || (val->type != JSON_ARRAY)) break;
                  index = index + 1;
                  pcVar15 = __json_array_string(val,0);
                  if ((pcVar15 != (char *)0x0) &&
                     (iVar5 = strncasecmp(pcVar15,DAT_00013580,0xd), iVar5 == 0)) {
                    pcVar15 = json_array_string(val,1);
                    if (pcVar15 != (char *)0x0) goto LAB_00013454;
                    break;
                  }
                } while (sVar22 != index);
              }
              pcVar21 = (char *)(uint)opt_debug;
              pcVar15 = pcVar21;
              if ((pcVar21 != (char *)0x0) &&
                 (((use_syslog != false || (*DAT_0001355c != '\0')) ||
                  (pcVar21 = (char *)0x0, pcVar15 = pcVar21, 6 < *DAT_00013560)))) {
                tmp42._0_4_ = *DAT_00013574;
                tmp42._4_4_ = DAT_00013574[1];
                tmp42._8_4_ = DAT_00013574[2];
                tmp42._12_4_ = DAT_00013574[3];
                tmp42._16_4_ = DAT_00013574[4];
                tmp42._20_4_ = DAT_00013574[5];
                tmp42._24_4_ = DAT_00013574[6];
                pcVar21 = (char *)DAT_00013574[7];
                tmp42._32_4_ = DAT_00013574[8];
                tmp42._36_4_ = DAT_00013574[9];
                tmp42._40_4_ = DAT_00013574[10];
                tmp42._28_4_ = pcVar21;
                _applog(7,tmp42,false);
                pcVar15 = (char *)0x0;
              }
LAB_00013454:
              s_00 = json_array_string(pjVar11,1);
              in_r2 = (_Bool *)0xbf0;
              nonce1._0_1_ = _valid_hex(s_00,DAT_00013578,(char *)0xbf0,(int)pcVar21);
              if (!nonce1._0_1_) {
                if (((use_syslog != false) || (*DAT_0001355c != '\0')) || (5 < *DAT_00013560)) {
                  tmp42._0_4_ = *DAT_0001357c;
                  tmp42._4_4_ = DAT_0001357c[1];
                  tmp42._8_4_ = DAT_0001357c[2];
                  tmp42._12_4_ = DAT_0001357c[3];
                  tmp42._16_4_ = DAT_0001357c[4];
                  tmp42._20_4_ = DAT_0001357c[5];
                  tmp42._24_4_ = DAT_0001357c[6];
                  tmp42._28_4_ = DAT_0001357c[7];
                  tmp42._32_4_ = DAT_0001357c[8];
                  tmp42._36_4_ = DAT_0001357c[9];
                  tmp42._40_4_ = DAT_0001357c[10];
                  in_r2 = (_Bool *)0x0;
                  tmp42._44_3_ = (undefined3)DAT_0001357c[0xb];
                  _applog(6,tmp42,false);
                }
                bVar3 = true;
                free(pcVar15);
                local_2b68 = 1;
                p_Var27 = DAT_00013564;
                goto LAB_0001295e;
              }
              pjVar11 = json_array_get(pjVar11,2);
              jVar28 = json_integer_value(pjVar11);
              uVar6 = (uint)jVar28 - 2;
              if (uVar6 < 0xf) {
                if ((((pcVar15 != (char *)0x0) && (pool->sessionid != (char *)0x0)) &&
                    (iVar5 = strcmp(pcVar15,pool->sessionid), iVar5 == 0)) &&
                   (((*DAT_0001386c != '\0' || (*DAT_00013870 != '\0')) ||
                    (uVar6 = *DAT_00013874, 4 < (int)uVar6)))) {
                  uVar6 = pool->pool_no;
                  snprintf(tmp42,0x800,DAT_00013878);
                  in_r2 = (_Bool *)0x0;
                  _applog(5,tmp42,false);
                }
                iVar5 = pthread_mutex_lock((pthread_mutex_t *)&pool->data_lock);
                if (iVar5 != 0) {
                  _mutex_lock(DAT_00013880,(char *)0xc04,in_r2,uVar6);
                }
                ppVar25 = &(pool->data_lock).rwlock;
                iVar5 = pthread_rwlock_wrlock((pthread_rwlock_t *)ppVar25);
                if (iVar5 != 0) {
                  piVar19 = __errno_location();
                  snprintf(tmp42,0x800,DAT_00013894,*piVar19,DAT_0001387c,DAT_00013880,0xc04);
                  _applog(3,tmp42,true);
                  _quit(1);
                }
                free(pool->nonce1);
                free(pool->sessionid);
                pool->nonce1 = s_00;
                pool->sessionid = pcVar15;
                sVar16 = strlen(s_00);
                ppVar2 = DAT_00013880;
                pcVar21 = DAT_0001387c;
                pool->n1_len = sVar16 >> 1;
                free(pool->nonce1bin);
                line = ppVar2;
                p_00 = (uchar *)_cgcalloc(pool->n1_len,1,pcVar21,ppVar2->__size,0xc0b);
                pool->nonce1bin = p_00;
                hex2bin(p_00,pool->nonce1,pool->n1_len);
                pool->n2size = (uint)jVar28;
                iVar5 = pthread_rwlock_unlock((pthread_rwlock_t *)ppVar25);
                if (iVar5 != 0) {
                  pppVar17 = (pthread_mutex_t **)__errno_location();
                  line = *pppVar17;
                  snprintf(tmp42,0x800,DAT_00013898,line,pcVar21,ppVar2,0xc0e);
                  _applog(3,tmp42,true);
                  _quit(1);
                }
                _mutex_unlock_noyield
                          (&(pool->data_lock).mutex,DAT_00013880->__size,(char *)0xc0e,(int)line);
                (*selective_yield)();
                if (((pcVar15 != (char *)0x0) && (*DAT_00013884 != '\0')) &&
                   ((*DAT_0001386c != '\0' || ((*DAT_00013870 != '\0' || (6 < (int)*DAT_00013874))))
                   )) {
                  snprintf(tmp42,0x800,DAT_00013888,pool->pool_no,pool->sessionid);
                  _applog(7,tmp42,false);
                }
                if (pool->stratum_url == (char *)0x0) {
                  pool->stratum_url = pool->sockaddr_url;
                }
                cVar1 = *DAT_0001388c;
                pool->next_diff = 0.0;
                pool->stratum_active = true;
                pool->sdiff = 1.0;
                if (((cVar1 != '\0') && (*DAT_00013884 != '\0')) &&
                   ((*DAT_0001386c != '\0' || ((*DAT_00013870 != '\0' || (6 < (int)*DAT_00013874))))
                   )) {
                  snprintf(tmp42,0x800,DAT_00013890,pool->pool_no,pool->nonce1,pool->n2size);
                  _applog(7,tmp42,false);
                }
                _Var4 = true;
                goto LAB_00013178;
              }
              if (((use_syslog != false) || (*DAT_0001355c != '\0')) || (5 < *DAT_00013560)) {
                tmp42._0_4_ = *DAT_00013584;
                tmp42._4_4_ = DAT_00013584[1];
                tmp42._8_4_ = DAT_00013584[2];
                tmp42._12_4_ = DAT_00013584[3];
                tmp42._16_4_ = DAT_00013584[4];
                tmp42._20_4_ = DAT_00013584[5];
                tmp42._24_4_ = DAT_00013584[6];
                tmp42._28_4_ = DAT_00013584[7];
                tmp42._32_4_ = DAT_00013584[8];
                tmp42._36_4_ = DAT_00013584[9];
                tmp42._40_4_ = DAT_00013584[10];
                in_r2 = (_Bool *)0x0;
                tmp42._44_3_ = (undefined3)DAT_00013584[0xb];
                _applog(6,tmp42,false);
              }
              bVar3 = true;
              free(pcVar15);
              p_Var27 = DAT_00013564;
              free(s_00);
              local_2b68 = 1;
              goto LAB_0001295e;
            }
LAB_00013236:
            ss = json_dumps(pjVar12,3);
          }
          if (((use_syslog != false) || (*DAT_000132bc != '\0')) || (5 < *DAT_000132c0)) {
            snprintf(tmp42,0x800,DAT_000132ec,ss);
            in_r2 = (_Bool *)0x0;
            _applog(6,tmp42,false);
          }
          bVar3 = true;
          free(ss);
          local_2b68 = 1;
          p_Var27 = DAT_000132c8;
        }
      }
    }
    else if ((opt_debug == false) ||
            (((use_syslog == false && (*DAT_00013020 == '\0')) && (*DAT_00013024 < 7)))) {
LAB_000130e0:
      bVar3 = true;
    }
    else {
      bVar3 = true;
      tmp42._0_4_ = *DAT_00013040;
      tmp42._4_4_ = DAT_00013040[1];
      tmp42._8_4_ = DAT_00013040[2];
      tmp42._12_4_ = DAT_00013040[3];
      tmp42._16_4_ = DAT_00013040[4];
      tmp42._20_4_ = DAT_00013040[5];
      tmp42._24_4_ = DAT_00013040[6];
      tmp42._28_4_ = DAT_00013040[7];
      in_r2 = (_Bool *)0x0;
      tmp42._32_4_ = DAT_00013040[8];
      tmp42[36] = (char)DAT_00013040[9];
      _applog(7,tmp42,false);
    }
    goto LAB_0001295e;
  case 4:
    in_r2 = (_Bool *)0x1;
    _Var4 = socks4_negotiate(pool,iVar5,true);
    p_Var27 = DAT_00013028;
    if (!_Var4) goto LAB_0001295c;
    goto LAB_00012e06;
  default:
    if (((use_syslog != false) || (*DAT_000132bc != '\0')) || (3 < *DAT_000132c0)) {
      snprintf(tmp42,0x800,DAT_000132c4,pool->sockaddr_proxy_url,pool->sockaddr_proxy_port);
      p_Var27 = DAT_000132c8;
      in_r2 = (_Bool *)0x0;
      _applog(4,tmp42,false);
    }
    goto LAB_0001295c;
  }
  DAT_00013028 = p_Var27;
  if (bVar3) goto LAB_00012e06;
  goto LAB_0001295c;
LAB_00012c7e:
  if (((use_syslog != false) || (*DAT_00012d70 != '\0')) || (5 < *DAT_00012d74)) {
    snprintf(tmp42,0x800,DAT_00012d78,sockaddr_url,sockaddr_port);
    in_r2 = (_Bool *)0x0;
    _applog(6,tmp42,false);
  }
  freeaddrinfo((addrinfo *)servinfo);
LAB_0001295c:
  bVar3 = false;
LAB_0001295e:
  local_2b70 = local_2b70 ^ 1;
  if ((local_2b68 & local_2b70) == 0) {
    if ((*p_Var27 != false) &&
       (((*DAT_000132d4 != '\0' || (*DAT_000132bc != '\0')) || (6 < *DAT_000132c0)))) {
      tmp42._0_4_ = *DAT_000132d8;
      tmp42._4_4_ = DAT_000132d8[1];
      tmp42._8_4_ = DAT_000132d8[2];
      tmp42._12_4_ = DAT_000132d8[3];
      tmp42._16_4_ = DAT_000132d8[4];
      tmp42._20_4_ = DAT_000132d8[5];
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
         (sVar22 = local_2b7c->refcount - 1, local_2b7c->refcount = sVar22, sVar22 == 0)) {
        json_delete(local_2b7c);
      }
    }
    return _Var4;
  }
  iVar5 = pthread_mutex_lock((pthread_mutex_t *)&pool->data_lock);
  if (iVar5 != 0) {
    _mutex_lock(DAT_00013984,(char *)0xc2a,in_r2,local_2b70);
  }
  ppVar25 = &(pool->data_lock).rwlock;
  iVar5 = pthread_rwlock_wrlock((pthread_rwlock_t *)ppVar25);
  if (iVar5 != 0) {
    piVar19 = __errno_location();
    snprintf(tmp42,0x800,DAT_00013894,*piVar19,"util.c",DAT_00013880,0xc2a);
    in_r2 = (_Bool *)0x1;
    _applog(3,tmp42,true);
    _quit(1);
  }
  free(pool->sessionid);
  free(pool->nonce1);
  pool->nonce1 = (char *)0x0;
  pool->sessionid = (char *)0x0;
  iVar5 = pthread_rwlock_unlock((pthread_rwlock_t *)ppVar25);
  if (iVar5 != 0) {
    piVar19 = __errno_location();
    snprintf(tmp42,0x800,DAT_00013988,*piVar19,"util.c",DAT_00013984,0xc2e);
    in_r2 = (_Bool *)0x1;
    _applog(3,tmp42,true);
    _quit(1);
  }
  iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&pool->data_lock);
  if (iVar5 != 0) {
    piVar19 = __errno_location();
    snprintf(tmp42,0x800,DAT_00013990,*piVar19,"util.c",DAT_00013984,0xc2e);
    in_r2 = (_Bool *)0x1;
    _applog(3,tmp42,true);
    _quit(1);
  }
  (*selective_yield)();
  in_r3 = (uint)*p_Var27;
  if ((in_r3 != 0) &&
     (((in_r2 = &use_syslog, use_syslog != false || (*DAT_00012aa8 != '\0')) ||
      (in_r3 = *DAT_00012aac, 6 < (int)in_r3)))) {
    tmp42._0_4_ = *DAT_00012ab8;
    tmp42._4_4_ = DAT_00012ab8[1];
    tmp42._8_4_ = DAT_00012ab8[2];
    tmp42._12_4_ = DAT_00012ab8[3];
    tmp42._16_4_ = DAT_00012ab8[4];
    tmp42._20_4_ = DAT_00012ab8[5];
    tmp42._24_4_ = DAT_00012ab8[6];
    in_r3 = DAT_00012ab8[7];
    in_r2 = (_Bool *)0x0;
    tmp42._32_4_ = DAT_00012ab8[8];
    tmp42._36_4_ = DAT_00012ab8[9];
    tmp42._28_4_ = in_r3;
    _applog(7,tmp42,false);
  }
  if ((local_2b7c != (json_t *)0x0) && (in_r3 = local_2b7c->refcount, in_r3 != 0xffffffff)) {
    in_r3 = in_r3 - 1;
    local_2b7c->refcount = in_r3;
    if (in_r3 == 0) {
      json_delete(local_2b7c);
    }
  }
  local_2b70 = 1;
  goto LAB_00012a20;
}

