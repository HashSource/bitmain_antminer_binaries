
_Bool setup_stratum_socket(pool *pool)

{
  undefined4 uVar1;
  _Bool _Var2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  pool *pool_local;
  fd_set rw;
  char tmp42 [2048];
  int err;
  socklen_t len;
  timeval tv_timeout;
  addrinfo hints;
  addrinfo *servinfo;
  int n;
  int selret;
  fd_set *__arr;
  uint __i;
  int sockd;
  char *sockaddr_port;
  char *sockaddr_url;
  addrinfo *p;
  
  _mutex_lock(&pool->stratum_lock,"util.c","setup_stratum_socket",0xb9b);
  pool->stratum_active = false;
  if (pool->sock != 0) {
    close(pool->sock);
  }
  pool->sock = 0;
  _mutex_unlock(&pool->stratum_lock,"util.c","setup_stratum_socket",0xba0);
  memset(&hints,0,0x20);
  hints.ai_family = 0;
  hints.ai_socktype = 1;
  if ((pool->rpc_proxy == (char *)0x0) && (opt_socks_proxy != (char *)0x0)) {
    pool->rpc_proxy = opt_socks_proxy;
    extract_sockaddr(pool->rpc_proxy,&pool->sockaddr_proxy_url,&pool->sockaddr_proxy_port);
    pool->rpc_proxytype = 3;
  }
  if (pool->rpc_proxy == (char *)0x0) {
    sockaddr_url = pool->sockaddr_url;
    sockaddr_port = pool->stratum_port;
  }
  else {
    sockaddr_url = pool->sockaddr_proxy_url;
    sockaddr_port = pool->sockaddr_proxy_port;
  }
  iVar3 = getaddrinfo(sockaddr_url,sockaddr_port,(addrinfo *)&hints,(addrinfo **)&servinfo);
  if (iVar3 == 0) {
    for (p = servinfo; p != (addrinfo *)0x0; p = p->ai_next) {
      sockd = socket(p->ai_family,p->ai_socktype,p->ai_protocol);
      if (sockd == -1) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          builtin_strncpy(tmp42,"Failed socke",0xc);
          tmp42[0xc] = 't';
          tmp42[0xd] = '\0';
          _applog(7,tmp42,false);
        }
      }
      else {
        noblock_socket(sockd);
        iVar3 = connect(sockd,(sockaddr *)p->ai_addr,p->ai_addrlen);
        if (iVar3 != -1) {
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            builtin_strncpy(tmp42,"Succeeded immediate connect",0x1c);
            _applog(4,tmp42,false);
          }
          block_socket(sockd);
          break;
        }
        tv_timeout.tv_sec = 1;
        tv_timeout.tv_usec = 0;
        _Var2 = sock_connecting();
        if (_Var2) {
          do {
            __arr = &rw;
            for (__i = 0; __i < 0x20; __i = __i + 1) {
              rw.fds_bits[__i] = 0;
            }
            iVar3 = sockd + 0x1f;
            if (-1 < sockd) {
              iVar3 = sockd;
            }
            uVar5 = sockd & 0x1f;
            if (sockd < 1) {
              uVar5 = -(-sockd & 0x1fU);
            }
            rw.fds_bits[iVar3 >> 5] = rw.fds_bits[iVar3 >> 5] | 1 << (uVar5 & 0xff);
            selret = select(sockd + 1,(fd_set *)0x0,(fd_set *)&rw,(fd_set *)0x0,
                            (timeval *)&tv_timeout);
            if (0 < selret) {
              iVar3 = sockd + 0x1f;
              if (-1 < sockd) {
                iVar3 = sockd;
              }
              uVar5 = sockd & 0x1f;
              if (sockd < 1) {
                uVar5 = -(-sockd & 0x1fU);
              }
              if ((1 << (uVar5 & 0xff) & rw.fds_bits[iVar3 >> 5]) != 0) {
                len = 4;
                n = getsockopt(sockd,1,4,&err,&len);
                uVar1 = tmp42._24_4_;
                if ((n == 0) && (err == 0)) {
                  if ((opt_debug != false) &&
                     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level))))
                  {
                    builtin_strncpy(tmp42,"Succeeded delayed connect",0x1a);
                    tmp42._26_2_ = SUB42(uVar1,2);
                    _applog(7,tmp42,false);
                  }
                  block_socket(sockd);
                  goto LAB_00043baa;
                }
              }
            }
          } while ((selret < 0) && (_Var2 = interrupted(), _Var2));
          close(sockd);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            builtin_strncpy(tmp42,"Select timeout/failed connec",0x1c);
            tmp42[0x1c] = 't';
            tmp42[0x1d] = '\0';
            _applog(7,tmp42,false);
          }
        }
        else {
          close(sockd);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            builtin_strncpy(tmp42,"Failed sock connect",0x14);
            _applog(7,tmp42,false);
          }
        }
      }
    }
LAB_00043baa:
    if (p == (addrinfo *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
        snprintf(tmp42,0x800,"Failed to connect to stratum on %s:%s",sockaddr_url,sockaddr_port);
        _applog(6,tmp42,false);
      }
      freeaddrinfo((addrinfo *)servinfo);
      _Var2 = false;
    }
    else {
      freeaddrinfo((addrinfo *)servinfo);
      if (pool->rpc_proxy != (char *)0x0) {
        switch(pool->rpc_proxytype) {
        case 0:
          _Var2 = http_negotiate(pool,sockd,false);
          if (!_Var2) {
            return false;
          }
          break;
        case 1:
          _Var2 = http_negotiate(pool,sockd,true);
          if (!_Var2) {
            return false;
          }
          break;
        case 2:
          _Var2 = socks4_negotiate(pool,sockd,false);
          if (!_Var2) {
            return false;
          }
          break;
        case 3:
        case 5:
          _Var2 = socks5_negotiate(pool,sockd);
          if (!_Var2) {
            return false;
          }
          break;
        case 4:
          _Var2 = socks4_negotiate(pool,sockd,true);
          if (!_Var2) {
            return false;
          }
          break;
        default:
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            snprintf(tmp42,0x800,"Unsupported proxy type for %s:%s",pool->sockaddr_proxy_url,
                     pool->sockaddr_proxy_port);
            _applog(4,tmp42,false);
          }
          return false;
        }
      }
      if (pool->sockbuf == (char *)0x0) {
        pcVar4 = (char *)_cgcalloc(0x2000,1,"util.c","setup_stratum_socket",0xc29);
        pool->sockbuf = pcVar4;
        pool->sockbuf_size = 0x2000;
      }
      pool->sock = sockd;
      keep_sockalive(sockd);
      _Var2 = true;
    }
  }
  else {
    if (pool->probed == true) {
      if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
        snprintf(tmp42,0x800,"Failed to getaddrinfo for %s:%s",sockaddr_url,sockaddr_port);
        _applog(6,tmp42,false);
      }
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800,"Failed to resolve (?wrong URL) %s:%s",sockaddr_url,sockaddr_port);
        _applog(4,tmp42,false);
      }
      pool->probed = true;
    }
    _Var2 = false;
  }
  return _Var2;
}

