
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * httpListenThread(void *param)

{
  int iVar1;
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
        tmp42[0] = s_socket_creating_failed__try_agai_00096854[0];
        tmp42[1] = s_socket_creating_failed__try_agai_00096854[1];
        tmp42[2] = s_socket_creating_failed__try_agai_00096854[2];
        tmp42[3] = s_socket_creating_failed__try_agai_00096854[3];
        tmp42[4] = s_socket_creating_failed__try_agai_00096854[4];
        tmp42[5] = s_socket_creating_failed__try_agai_00096854[5];
        tmp42[6] = s_socket_creating_failed__try_agai_00096854[6];
        tmp42[7] = s_socket_creating_failed__try_agai_00096854[7];
        tmp42[8] = s_socket_creating_failed__try_agai_00096854[8];
        tmp42[9] = s_socket_creating_failed__try_agai_00096854[9];
        tmp42[10] = s_socket_creating_failed__try_agai_00096854[10];
        tmp42[11] = s_socket_creating_failed__try_agai_00096854[11];
        tmp42[12] = s_socket_creating_failed__try_agai_00096854[12];
        tmp42[13] = s_socket_creating_failed__try_agai_00096854[13];
        tmp42[14] = s_socket_creating_failed__try_agai_00096854[14];
        tmp42[15] = s_socket_creating_failed__try_agai_00096854[15];
        tmp42[16] = s_socket_creating_failed__try_agai_00096854[16];
        tmp42[17] = s_socket_creating_failed__try_agai_00096854[17];
        tmp42[18] = s_socket_creating_failed__try_agai_00096854[18];
        tmp42[19] = s_socket_creating_failed__try_agai_00096854[19];
        tmp42[20] = s_socket_creating_failed__try_agai_00096854[20];
        tmp42[21] = s_socket_creating_failed__try_agai_00096854[21];
        tmp42[22] = s_socket_creating_failed__try_agai_00096854[22];
        tmp42[23] = s_socket_creating_failed__try_agai_00096854[23];
        tmp42[24] = s_socket_creating_failed__try_agai_00096854[24];
        tmp42[25] = s_socket_creating_failed__try_agai_00096854[25];
        tmp42[26] = s_socket_creating_failed__try_agai_00096854[26];
        tmp42[27] = s_socket_creating_failed__try_agai_00096854[27];
        tmp42[28] = s_socket_creating_failed__try_agai_00096854[28];
        tmp42[29] = s_socket_creating_failed__try_agai_00096854[29];
        tmp42[30] = s_socket_creating_failed__try_agai_00096854[30];
        tmp42[31] = s_socket_creating_failed__try_agai_00096854[31];
        tmp42[32] = s_socket_creating_failed__try_agai_00096854[32];
        tmp42[33] = s_socket_creating_failed__try_agai_00096854[33];
        tmp42[34] = s_socket_creating_failed__try_agai_00096854[34];
        tmp42[35] = s_socket_creating_failed__try_agai_00096854[35];
        tmp42[36] = s_socket_creating_failed__try_agai_00096854[36];
        tmp42[37] = s_socket_creating_failed__try_agai_00096854[37];
        tmp42[38] = s_socket_creating_failed__try_agai_00096854[38];
        tmp42[39] = s_socket_creating_failed__try_agai_00096854[39];
        tmp42[40] = s_socket_creating_failed__try_agai_00096854[40];
        tmp42[41] = s_socket_creating_failed__try_agai_00096854[41];
        tmp42[42] = s_socket_creating_failed__try_agai_00096854[42];
        tmp42[43] = s_socket_creating_failed__try_agai_00096854[43];
        tmp42._44_2_ = (undefined2)ram0x00096880;
        tmp42[46] = (char)((uint)ram0x00096880 >> 0x10);
        _applog(5,tmp42,false);
      }
      sleep(10);
    }
    else {
      memset(&service,0,0x10);
      service.sin_family = 2;
      service.sin_addr.s_addr = htonl(0);
      service.sin_port = htons(0x17ac);
      iVar1 = bind(listen_sockfd,(sockaddr *)&service,0x10);
      if (iVar1 < 0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          tmp42[0] = s_http_port_bind_failed__try_again_00096884[0];
          tmp42[1] = s_http_port_bind_failed__try_again_00096884[1];
          tmp42[2] = s_http_port_bind_failed__try_again_00096884[2];
          tmp42[3] = s_http_port_bind_failed__try_again_00096884[3];
          tmp42[4] = s_http_port_bind_failed__try_again_00096884[4];
          tmp42[5] = s_http_port_bind_failed__try_again_00096884[5];
          tmp42[6] = s_http_port_bind_failed__try_again_00096884[6];
          tmp42[7] = s_http_port_bind_failed__try_again_00096884[7];
          tmp42[8] = s_http_port_bind_failed__try_again_00096884[8];
          tmp42[9] = s_http_port_bind_failed__try_again_00096884[9];
          tmp42[10] = s_http_port_bind_failed__try_again_00096884[10];
          tmp42[11] = s_http_port_bind_failed__try_again_00096884[11];
          tmp42[12] = s_http_port_bind_failed__try_again_00096884[12];
          tmp42[13] = s_http_port_bind_failed__try_again_00096884[13];
          tmp42[14] = s_http_port_bind_failed__try_again_00096884[14];
          tmp42[15] = s_http_port_bind_failed__try_again_00096884[15];
          tmp42[16] = s_http_port_bind_failed__try_again_00096884[16];
          tmp42[17] = s_http_port_bind_failed__try_again_00096884[17];
          tmp42[18] = s_http_port_bind_failed__try_again_00096884[18];
          tmp42[19] = s_http_port_bind_failed__try_again_00096884[19];
          tmp42[20] = s_http_port_bind_failed__try_again_00096884[20];
          tmp42[21] = s_http_port_bind_failed__try_again_00096884[21];
          tmp42[22] = s_http_port_bind_failed__try_again_00096884[22];
          tmp42[23] = s_http_port_bind_failed__try_again_00096884[23];
          tmp42[24] = s_http_port_bind_failed__try_again_00096884[24];
          tmp42[25] = s_http_port_bind_failed__try_again_00096884[25];
          tmp42[26] = s_http_port_bind_failed__try_again_00096884[26];
          tmp42[27] = s_http_port_bind_failed__try_again_00096884[27];
          tmp42[28] = s_http_port_bind_failed__try_again_00096884[28];
          tmp42[29] = s_http_port_bind_failed__try_again_00096884[29];
          tmp42[30] = s_http_port_bind_failed__try_again_00096884[30];
          tmp42[31] = s_http_port_bind_failed__try_again_00096884[31];
          tmp42[32] = s_http_port_bind_failed__try_again_00096884[32];
          tmp42[33] = s_http_port_bind_failed__try_again_00096884[33];
          tmp42[34] = s_http_port_bind_failed__try_again_00096884[34];
          tmp42[35] = s_http_port_bind_failed__try_again_00096884[35];
          tmp42[36] = s_http_port_bind_failed__try_again_00096884[36];
          tmp42[37] = s_http_port_bind_failed__try_again_00096884[37];
          tmp42[38] = s_http_port_bind_failed__try_again_00096884[38];
          tmp42[39] = s_http_port_bind_failed__try_again_00096884[39];
          tmp42[40] = s_http_port_bind_failed__try_again_00096884[40];
          tmp42[41] = s_http_port_bind_failed__try_again_00096884[41];
          tmp42[42] = s_http_port_bind_failed__try_again_00096884[42];
          tmp42[43] = s_http_port_bind_failed__try_again_00096884[43];
          tmp42._44_2_ = (undefined2)ram0x000968b0;
          _applog(5,tmp42,false);
        }
        close(listen_sockfd);
        listen_sockfd = -1;
        sleep(10);
      }
      else {
        iVar1 = listen(listen_sockfd,100);
        if (-1 < iVar1) break;
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          tmp42[0] = s_http_listen_failed__try_again_af_000968b4[0];
          tmp42[1] = s_http_listen_failed__try_again_af_000968b4[1];
          tmp42[2] = s_http_listen_failed__try_again_af_000968b4[2];
          tmp42[3] = s_http_listen_failed__try_again_af_000968b4[3];
          tmp42[4] = s_http_listen_failed__try_again_af_000968b4[4];
          tmp42[5] = s_http_listen_failed__try_again_af_000968b4[5];
          tmp42[6] = s_http_listen_failed__try_again_af_000968b4[6];
          tmp42[7] = s_http_listen_failed__try_again_af_000968b4[7];
          tmp42[8] = s_http_listen_failed__try_again_af_000968b4[8];
          tmp42[9] = s_http_listen_failed__try_again_af_000968b4[9];
          tmp42[10] = s_http_listen_failed__try_again_af_000968b4[10];
          tmp42[11] = s_http_listen_failed__try_again_af_000968b4[11];
          tmp42[12] = s_http_listen_failed__try_again_af_000968b4[12];
          tmp42[13] = s_http_listen_failed__try_again_af_000968b4[13];
          tmp42[14] = s_http_listen_failed__try_again_af_000968b4[14];
          tmp42[15] = s_http_listen_failed__try_again_af_000968b4[15];
          tmp42[16] = s_http_listen_failed__try_again_af_000968b4[16];
          tmp42[17] = s_http_listen_failed__try_again_af_000968b4[17];
          tmp42[18] = s_http_listen_failed__try_again_af_000968b4[18];
          tmp42[19] = s_http_listen_failed__try_again_af_000968b4[19];
          tmp42[20] = s_http_listen_failed__try_again_af_000968b4[20];
          tmp42[21] = s_http_listen_failed__try_again_af_000968b4[21];
          tmp42[22] = s_http_listen_failed__try_again_af_000968b4[22];
          tmp42[23] = s_http_listen_failed__try_again_af_000968b4[23];
          tmp42[24] = s_http_listen_failed__try_again_af_000968b4[24];
          tmp42[25] = s_http_listen_failed__try_again_af_000968b4[25];
          tmp42[26] = s_http_listen_failed__try_again_af_000968b4[26];
          tmp42[27] = s_http_listen_failed__try_again_af_000968b4[27];
          tmp42[28] = s_http_listen_failed__try_again_af_000968b4[28];
          tmp42[29] = s_http_listen_failed__try_again_af_000968b4[29];
          tmp42[30] = s_http_listen_failed__try_again_af_000968b4[30];
          tmp42[31] = s_http_listen_failed__try_again_af_000968b4[31];
          tmp42[32] = s_http_listen_failed__try_again_af_000968b4[32];
          tmp42[33] = s_http_listen_failed__try_again_af_000968b4[33];
          tmp42[34] = s_http_listen_failed__try_again_af_000968b4[34];
          tmp42[35] = s_http_listen_failed__try_again_af_000968b4[35];
          tmp42[36] = s_http_listen_failed__try_again_af_000968b4[36];
          tmp42[37] = s_http_listen_failed__try_again_af_000968b4[37];
          tmp42[38] = s_http_listen_failed__try_again_af_000968b4[38];
          tmp42[39] = s_http_listen_failed__try_again_af_000968b4[39];
          tmp42._40_3_ = (undefined3)ram0x000968dc;
          _applog(5,tmp42,false);
        }
        close(listen_sockfd);
        listen_sockfd = -1;
        sleep(10);
      }
    }
  } while (ExitServer != true);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    tmp42[0] = s_start_listen_on_6060_____000968e0[0];
    tmp42[1] = s_start_listen_on_6060_____000968e0[1];
    tmp42[2] = s_start_listen_on_6060_____000968e0[2];
    tmp42[3] = s_start_listen_on_6060_____000968e0[3];
    tmp42[4] = s_start_listen_on_6060_____000968e0[4];
    tmp42[5] = s_start_listen_on_6060_____000968e0[5];
    tmp42[6] = s_start_listen_on_6060_____000968e0[6];
    tmp42[7] = s_start_listen_on_6060_____000968e0[7];
    tmp42[8] = s_start_listen_on_6060_____000968e0[8];
    tmp42[9] = s_start_listen_on_6060_____000968e0[9];
    tmp42[10] = s_start_listen_on_6060_____000968e0[10];
    tmp42[11] = s_start_listen_on_6060_____000968e0[11];
    tmp42[12] = s_start_listen_on_6060_____000968e0[12];
    tmp42[13] = s_start_listen_on_6060_____000968e0[13];
    tmp42[14] = s_start_listen_on_6060_____000968e0[14];
    tmp42[15] = s_start_listen_on_6060_____000968e0[15];
    tmp42[16] = s_start_listen_on_6060_____000968e0[16];
    tmp42[17] = s_start_listen_on_6060_____000968e0[17];
    tmp42[18] = s_start_listen_on_6060_____000968e0[18];
    tmp42[19] = s_start_listen_on_6060_____000968e0[19];
    tmp42[20] = s_start_listen_on_6060_____000968e0[20];
    tmp42[21] = s_start_listen_on_6060_____000968e0[21];
    tmp42[22] = s_start_listen_on_6060_____000968e0[22];
    tmp42[23] = s_start_listen_on_6060_____000968e0[23];
    tmp42[24] = (char)ram0x000968f8;
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

