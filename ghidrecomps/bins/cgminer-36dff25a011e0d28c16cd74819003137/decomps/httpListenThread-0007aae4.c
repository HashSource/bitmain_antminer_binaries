
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
        tmp42[0] = s_socket_creating_failed__try_agai_000acf34[0];
        tmp42[1] = s_socket_creating_failed__try_agai_000acf34[1];
        tmp42[2] = s_socket_creating_failed__try_agai_000acf34[2];
        tmp42[3] = s_socket_creating_failed__try_agai_000acf34[3];
        tmp42[4] = s_socket_creating_failed__try_agai_000acf34[4];
        tmp42[5] = s_socket_creating_failed__try_agai_000acf34[5];
        tmp42[6] = s_socket_creating_failed__try_agai_000acf34[6];
        tmp42[7] = s_socket_creating_failed__try_agai_000acf34[7];
        tmp42[8] = s_socket_creating_failed__try_agai_000acf34[8];
        tmp42[9] = s_socket_creating_failed__try_agai_000acf34[9];
        tmp42[10] = s_socket_creating_failed__try_agai_000acf34[10];
        tmp42[11] = s_socket_creating_failed__try_agai_000acf34[11];
        tmp42[12] = s_socket_creating_failed__try_agai_000acf34[12];
        tmp42[13] = s_socket_creating_failed__try_agai_000acf34[13];
        tmp42[14] = s_socket_creating_failed__try_agai_000acf34[14];
        tmp42[15] = s_socket_creating_failed__try_agai_000acf34[15];
        tmp42[16] = s_socket_creating_failed__try_agai_000acf34[16];
        tmp42[17] = s_socket_creating_failed__try_agai_000acf34[17];
        tmp42[18] = s_socket_creating_failed__try_agai_000acf34[18];
        tmp42[19] = s_socket_creating_failed__try_agai_000acf34[19];
        tmp42[20] = s_socket_creating_failed__try_agai_000acf34[20];
        tmp42[21] = s_socket_creating_failed__try_agai_000acf34[21];
        tmp42[22] = s_socket_creating_failed__try_agai_000acf34[22];
        tmp42[23] = s_socket_creating_failed__try_agai_000acf34[23];
        tmp42[24] = s_socket_creating_failed__try_agai_000acf34[24];
        tmp42[25] = s_socket_creating_failed__try_agai_000acf34[25];
        tmp42[26] = s_socket_creating_failed__try_agai_000acf34[26];
        tmp42[27] = s_socket_creating_failed__try_agai_000acf34[27];
        tmp42[28] = s_socket_creating_failed__try_agai_000acf34[28];
        tmp42[29] = s_socket_creating_failed__try_agai_000acf34[29];
        tmp42[30] = s_socket_creating_failed__try_agai_000acf34[30];
        tmp42[31] = s_socket_creating_failed__try_agai_000acf34[31];
        tmp42[32] = s_socket_creating_failed__try_agai_000acf34[32];
        tmp42[33] = s_socket_creating_failed__try_agai_000acf34[33];
        tmp42[34] = s_socket_creating_failed__try_agai_000acf34[34];
        tmp42[35] = s_socket_creating_failed__try_agai_000acf34[35];
        tmp42[36] = s_socket_creating_failed__try_agai_000acf34[36];
        tmp42[37] = s_socket_creating_failed__try_agai_000acf34[37];
        tmp42[38] = s_socket_creating_failed__try_agai_000acf34[38];
        tmp42[39] = s_socket_creating_failed__try_agai_000acf34[39];
        tmp42[40] = s_socket_creating_failed__try_agai_000acf34[40];
        tmp42[41] = s_socket_creating_failed__try_agai_000acf34[41];
        tmp42[42] = s_socket_creating_failed__try_agai_000acf34[42];
        tmp42[43] = s_socket_creating_failed__try_agai_000acf34[43];
        tmp42._44_2_ = (undefined2)ram0x000acf60;
        tmp42[46] = (char)((uint)ram0x000acf60 >> 0x10);
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
          tmp42[0] = s_http_port_bind_failed__try_again_000acf64[0];
          tmp42[1] = s_http_port_bind_failed__try_again_000acf64[1];
          tmp42[2] = s_http_port_bind_failed__try_again_000acf64[2];
          tmp42[3] = s_http_port_bind_failed__try_again_000acf64[3];
          tmp42[4] = s_http_port_bind_failed__try_again_000acf64[4];
          tmp42[5] = s_http_port_bind_failed__try_again_000acf64[5];
          tmp42[6] = s_http_port_bind_failed__try_again_000acf64[6];
          tmp42[7] = s_http_port_bind_failed__try_again_000acf64[7];
          tmp42[8] = s_http_port_bind_failed__try_again_000acf64[8];
          tmp42[9] = s_http_port_bind_failed__try_again_000acf64[9];
          tmp42[10] = s_http_port_bind_failed__try_again_000acf64[10];
          tmp42[11] = s_http_port_bind_failed__try_again_000acf64[11];
          tmp42[12] = s_http_port_bind_failed__try_again_000acf64[12];
          tmp42[13] = s_http_port_bind_failed__try_again_000acf64[13];
          tmp42[14] = s_http_port_bind_failed__try_again_000acf64[14];
          tmp42[15] = s_http_port_bind_failed__try_again_000acf64[15];
          tmp42[16] = s_http_port_bind_failed__try_again_000acf64[16];
          tmp42[17] = s_http_port_bind_failed__try_again_000acf64[17];
          tmp42[18] = s_http_port_bind_failed__try_again_000acf64[18];
          tmp42[19] = s_http_port_bind_failed__try_again_000acf64[19];
          tmp42[20] = s_http_port_bind_failed__try_again_000acf64[20];
          tmp42[21] = s_http_port_bind_failed__try_again_000acf64[21];
          tmp42[22] = s_http_port_bind_failed__try_again_000acf64[22];
          tmp42[23] = s_http_port_bind_failed__try_again_000acf64[23];
          tmp42[24] = s_http_port_bind_failed__try_again_000acf64[24];
          tmp42[25] = s_http_port_bind_failed__try_again_000acf64[25];
          tmp42[26] = s_http_port_bind_failed__try_again_000acf64[26];
          tmp42[27] = s_http_port_bind_failed__try_again_000acf64[27];
          tmp42[28] = s_http_port_bind_failed__try_again_000acf64[28];
          tmp42[29] = s_http_port_bind_failed__try_again_000acf64[29];
          tmp42[30] = s_http_port_bind_failed__try_again_000acf64[30];
          tmp42[31] = s_http_port_bind_failed__try_again_000acf64[31];
          tmp42[32] = s_http_port_bind_failed__try_again_000acf64[32];
          tmp42[33] = s_http_port_bind_failed__try_again_000acf64[33];
          tmp42[34] = s_http_port_bind_failed__try_again_000acf64[34];
          tmp42[35] = s_http_port_bind_failed__try_again_000acf64[35];
          tmp42[36] = s_http_port_bind_failed__try_again_000acf64[36];
          tmp42[37] = s_http_port_bind_failed__try_again_000acf64[37];
          tmp42[38] = s_http_port_bind_failed__try_again_000acf64[38];
          tmp42[39] = s_http_port_bind_failed__try_again_000acf64[39];
          tmp42[40] = s_http_port_bind_failed__try_again_000acf64[40];
          tmp42[41] = s_http_port_bind_failed__try_again_000acf64[41];
          tmp42[42] = s_http_port_bind_failed__try_again_000acf64[42];
          tmp42[43] = s_http_port_bind_failed__try_again_000acf64[43];
          tmp42._44_2_ = (undefined2)ram0x000acf90;
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
          tmp42[0] = s_http_listen_failed__try_again_af_000acf94[0];
          tmp42[1] = s_http_listen_failed__try_again_af_000acf94[1];
          tmp42[2] = s_http_listen_failed__try_again_af_000acf94[2];
          tmp42[3] = s_http_listen_failed__try_again_af_000acf94[3];
          tmp42[4] = s_http_listen_failed__try_again_af_000acf94[4];
          tmp42[5] = s_http_listen_failed__try_again_af_000acf94[5];
          tmp42[6] = s_http_listen_failed__try_again_af_000acf94[6];
          tmp42[7] = s_http_listen_failed__try_again_af_000acf94[7];
          tmp42[8] = s_http_listen_failed__try_again_af_000acf94[8];
          tmp42[9] = s_http_listen_failed__try_again_af_000acf94[9];
          tmp42[10] = s_http_listen_failed__try_again_af_000acf94[10];
          tmp42[11] = s_http_listen_failed__try_again_af_000acf94[11];
          tmp42[12] = s_http_listen_failed__try_again_af_000acf94[12];
          tmp42[13] = s_http_listen_failed__try_again_af_000acf94[13];
          tmp42[14] = s_http_listen_failed__try_again_af_000acf94[14];
          tmp42[15] = s_http_listen_failed__try_again_af_000acf94[15];
          tmp42[16] = s_http_listen_failed__try_again_af_000acf94[16];
          tmp42[17] = s_http_listen_failed__try_again_af_000acf94[17];
          tmp42[18] = s_http_listen_failed__try_again_af_000acf94[18];
          tmp42[19] = s_http_listen_failed__try_again_af_000acf94[19];
          tmp42[20] = s_http_listen_failed__try_again_af_000acf94[20];
          tmp42[21] = s_http_listen_failed__try_again_af_000acf94[21];
          tmp42[22] = s_http_listen_failed__try_again_af_000acf94[22];
          tmp42[23] = s_http_listen_failed__try_again_af_000acf94[23];
          tmp42[24] = s_http_listen_failed__try_again_af_000acf94[24];
          tmp42[25] = s_http_listen_failed__try_again_af_000acf94[25];
          tmp42[26] = s_http_listen_failed__try_again_af_000acf94[26];
          tmp42[27] = s_http_listen_failed__try_again_af_000acf94[27];
          tmp42[28] = s_http_listen_failed__try_again_af_000acf94[28];
          tmp42[29] = s_http_listen_failed__try_again_af_000acf94[29];
          tmp42[30] = s_http_listen_failed__try_again_af_000acf94[30];
          tmp42[31] = s_http_listen_failed__try_again_af_000acf94[31];
          tmp42[32] = s_http_listen_failed__try_again_af_000acf94[32];
          tmp42[33] = s_http_listen_failed__try_again_af_000acf94[33];
          tmp42[34] = s_http_listen_failed__try_again_af_000acf94[34];
          tmp42[35] = s_http_listen_failed__try_again_af_000acf94[35];
          tmp42[36] = s_http_listen_failed__try_again_af_000acf94[36];
          tmp42[37] = s_http_listen_failed__try_again_af_000acf94[37];
          tmp42[38] = s_http_listen_failed__try_again_af_000acf94[38];
          tmp42[39] = s_http_listen_failed__try_again_af_000acf94[39];
          tmp42._40_3_ = (undefined3)ram0x000acfbc;
          _applog(5,tmp42,false);
        }
        close(listen_sockfd);
        listen_sockfd = -1;
        sleep(10);
      }
    }
  } while (ExitServer != true);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    tmp42[0] = s_start_listen_on_6060_____000acfc0[0];
    tmp42[1] = s_start_listen_on_6060_____000acfc0[1];
    tmp42[2] = s_start_listen_on_6060_____000acfc0[2];
    tmp42[3] = s_start_listen_on_6060_____000acfc0[3];
    tmp42[4] = s_start_listen_on_6060_____000acfc0[4];
    tmp42[5] = s_start_listen_on_6060_____000acfc0[5];
    tmp42[6] = s_start_listen_on_6060_____000acfc0[6];
    tmp42[7] = s_start_listen_on_6060_____000acfc0[7];
    tmp42[8] = s_start_listen_on_6060_____000acfc0[8];
    tmp42[9] = s_start_listen_on_6060_____000acfc0[9];
    tmp42[10] = s_start_listen_on_6060_____000acfc0[10];
    tmp42[11] = s_start_listen_on_6060_____000acfc0[11];
    tmp42[12] = s_start_listen_on_6060_____000acfc0[12];
    tmp42[13] = s_start_listen_on_6060_____000acfc0[13];
    tmp42[14] = s_start_listen_on_6060_____000acfc0[14];
    tmp42[15] = s_start_listen_on_6060_____000acfc0[15];
    tmp42[16] = s_start_listen_on_6060_____000acfc0[16];
    tmp42[17] = s_start_listen_on_6060_____000acfc0[17];
    tmp42[18] = s_start_listen_on_6060_____000acfc0[18];
    tmp42[19] = s_start_listen_on_6060_____000acfc0[19];
    tmp42[20] = s_start_listen_on_6060_____000acfc0[20];
    tmp42[21] = s_start_listen_on_6060_____000acfc0[21];
    tmp42[22] = s_start_listen_on_6060_____000acfc0[22];
    tmp42[23] = s_start_listen_on_6060_____000acfc0[23];
    tmp42[24] = (char)ram0x000acfd8;
    _applog(5,tmp42,false);
  }
  do {
    if (ExitServer == true) {
LAB_0007b004:
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
      goto LAB_0007b004;
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"one client connected sock=%d",AcceptSocket);
      _applog(7,tmp42,false);
    }
    statusServiceThread((void *)AcceptSocket);
  } while( true );
}

