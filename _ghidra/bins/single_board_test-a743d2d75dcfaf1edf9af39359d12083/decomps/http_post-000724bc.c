
char * http_post(char *url,char *post_str)

{
  int iVar1;
  int socket;
  size_t sVar2;
  char *pcVar3;
  char *post_str_local;
  char *url_local;
  char time_stamp [48];
  char tmp1 [2048];
  char time_str [24];
  int port;
  char file [2048];
  char host_addr [2048];
  char lpbuf [8192];
  int revs;
  int len;
  int socket_fd;
  
  puts("http request");
  memset(lpbuf,0,0x2000);
  memset(host_addr,0,0x800);
  memset(file,0,0x800);
  port = 0;
  if ((url == (char *)0x0) || (post_str == (char *)0x0)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: http_post parameter check failed!\n","http_post");
    builtin_strncpy(tmp1,"http_post parameter check failed",0x20);
    tmp1[0x20] = '!';
    tmp1[0x21] = '\0';
    log_to_file(tmp1,time_stamp);
    pcVar3 = (char *)0x0;
  }
  else {
    iVar1 = http_parse_url(url,host_addr,file,&port);
    if (iVar1 == 0) {
      printf("log parse url:%s addr:%s file:%s port:%d \n",url,host_addr,file,port);
      socket = create_connection_to_server_by_name(host_addr,port);
      iVar1 = port;
      if (socket < 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: create socket failed\n","http_post");
        builtin_strncpy(tmp1,"create socket failed",0x14);
        tmp1._20_4_ = tmp1._20_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
        pcVar3 = (char *)0x0;
      }
      else {
        sVar2 = strlen(post_str);
        snprintf(lpbuf,0x2000,
                 "POST /%s HTTP/1.1\r\nHOST: %s:%d\r\nAccept: */*\r\nContent-Type:application/json\r\nConnection:keep-alive\r\nContent-Length: %d\r\n\r\n"
                 ,file,host_addr,iVar1,sVar2);
        sVar2 = strlen(lpbuf);
        iVar1 = http_tcpclient_send(socket,lpbuf,sVar2);
        if (iVar1 < 0) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: http_tcpclient_send failed..\n","http_post");
          builtin_strncpy(tmp1,"http_tcpclient_send failed..",0x1c);
          tmp1._28_4_ = tmp1._28_4_ & 0xffffff00;
          log_to_file(tmp1,time_stamp);
          http_tcpclient_close(socket);
          pcVar3 = (char *)0x0;
        }
        else {
          sVar2 = strlen(post_str);
          iVar1 = http_tcpclient_send(socket,post_str,sVar2);
          if (iVar1 < 0) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: http_tcpclient_send failed..\n","http_post");
            builtin_strncpy(tmp1,"http_tcpclient_send failed..",0x1c);
            tmp1._28_4_ = tmp1._28_4_ & 0xffffff00;
            log_to_file(tmp1,time_stamp);
            http_tcpclient_close(socket);
            pcVar3 = (char *)0x0;
          }
          else {
            get_format_time(time_str);
            printf("send over time:%s\n",time_str);
            iVar1 = http_tcpclient_recv(socket,lpbuf);
            if (iVar1 < 1) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s: http_tcpclient_recv failed\n","http_post");
              builtin_strncpy(tmp1,"http_tcpclient_recv failed",0x1b);
              log_to_file(tmp1,time_stamp);
              http_tcpclient_close(socket);
              pcVar3 = (char *)0x0;
            }
            else {
              http_tcpclient_close(socket);
              get_format_time(time_str);
              printf("recv over time:%s\n",time_str);
              pcVar3 = http_parse_result(lpbuf,false,false);
            }
          }
        }
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: http_parse_url failed!\n","http_post");
      builtin_strncpy(tmp1,"http_parse_url failed!",0x17);
      log_to_file(tmp1,time_stamp);
      pcVar3 = (char *)0x0;
    }
  }
  return pcVar3;
}

