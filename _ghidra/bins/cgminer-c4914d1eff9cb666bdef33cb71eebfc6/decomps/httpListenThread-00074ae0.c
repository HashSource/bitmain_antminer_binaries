
void * httpListenThread(void *param)

{
  undefined4 uVar1;
  int iVar2;
  void *param_local;
  char tmp42 [2048];
  int addr_len;
  sockaddr_in client_addr;
  sockaddr_in service;
  int ret;
  int AcceptSocket;
  
  sleep(0x1e);
  do {
    listen_sockfd = socket(2,1,6);
    if (listen_sockfd < 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        builtin_strncpy(tmp42,"socket creating failed, try again after 10s.",0x2c);
        tmp42[0x2c] = '.';
        tmp42[0x2d] = '.';
        tmp42[0x2e] = '\0';
        _applog(5,tmp42,false);
      }
      sleep(10);
    }
    else {
      memset(&service,0,0x10);
      service.sin_family = 2;
      service.sin_addr.s_addr = htonl(0);
      service.sin_port = htons(0x17ac);
      iVar2 = bind(listen_sockfd,(sockaddr *)&service,0x10);
      if (iVar2 < 0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          builtin_strncpy(tmp42,"http port bind failed! try again after 10s..",0x2c);
          tmp42[0x2c] = '.';
          tmp42[0x2d] = '\0';
          _applog(5,tmp42,false);
        }
        close(listen_sockfd);
        listen_sockfd = -1;
        sleep(10);
      }
      else {
        iVar2 = listen(listen_sockfd,100);
        uVar1 = tmp42._40_4_;
        if (-1 < iVar2) break;
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          builtin_strncpy(tmp42,"http listen failed! try again after 10s...",0x2b);
          tmp42[0x2b] = SUB41(uVar1,3);
          _applog(5,tmp42,false);
        }
        close(listen_sockfd);
        listen_sockfd = -1;
        sleep(10);
      }
    }
  } while (ExitServer != true);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    builtin_strncpy(tmp42,"start listen on 6060 ...",0x18);
    tmp42._24_4_ = tmp42._24_4_ & 0xffffff00;
    _applog(5,tmp42,false);
  }
  do {
    if (ExitServer == true) {
LAB_00074e5c:
      close(listen_sockfd);
      listen_sockfd = -1;
      return (void *)0x0;
    }
    AcceptSocket = -1;
    while ((AcceptSocket == -1 && (ExitServer != true))) {
      usleep(10000);
      addr_len = 0x10;
      AcceptSocket = accept(listen_sockfd,(sockaddr *)&client_addr,(socklen_t *)&addr_len);
    }
    if (ExitServer != false) {
      if (AcceptSocket != -1) {
        close(AcceptSocket);
      }
      goto LAB_00074e5c;
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"one client connected sock=%d",AcceptSocket);
      _applog(7,tmp42,false);
    }
    statusServiceThread((void *)AcceptSocket);
  } while( true );
}

