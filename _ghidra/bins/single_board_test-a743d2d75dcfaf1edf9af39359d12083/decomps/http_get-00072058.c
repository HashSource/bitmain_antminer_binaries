
char * http_get(char *url,_Bool ver1_0,_Bool raw)

{
  int iVar1;
  size_t size;
  int iVar2;
  char *pcVar3;
  _Bool raw_local;
  _Bool ver1_0_local;
  char *url_local;
  char time_stamp [48];
  char tmp1 [2048];
  int port;
  char file [2048];
  char host_addr [2048];
  char http_buf [8192];
  char post [2048];
  int len;
  int socket_fd;
  
  memset(post,0,0x800);
  memset(http_buf,0,0x2000);
  memset(host_addr,0,0x800);
  memset(file,0,0x800);
  port = 0;
  if (url == (char *)0x0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: url is null!\n","http_get");
    builtin_strncpy(tmp1,"url is null!",0xc);
    tmp1._12_4_ = tmp1._12_4_ & 0xffffff00;
    log_to_file(tmp1,time_stamp);
    pcVar3 = (char *)0x0;
  }
  else {
    iVar1 = http_parse_url(url,host_addr,file,&port);
    if (iVar1 == 0) {
      iVar1 = http_tcpclient_create(host_addr,port,ver1_0);
      if (iVar1 < 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: tcp client create failed\n","http_get");
        builtin_strncpy(tmp1,"tcp client create failed",0x18);
        tmp1[0x18] = '\0';
        log_to_file(tmp1,time_stamp);
        pcVar3 = (char *)0x0;
      }
      else {
        if (ver1_0) {
          sprintf(http_buf,"GET /%s HTTP/1.0\r\nHost: %s:%d\r\nAccept: */*\r\n\r\n",file,host_addr,
                  port);
        }
        else {
          sprintf(http_buf,"GET /%s HTTP/1.1\r\nHOST: %s:%d\r\nAccept: */*\r\n\r\n",file,host_addr,
                  port);
        }
        size = strlen(http_buf);
        iVar2 = http_tcpclient_send(iVar1,http_buf,size);
        if (iVar2 < 0) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: tcp client send failed\n","http_get");
          builtin_strncpy(tmp1,"tcp client send failed",0x17);
          log_to_file(tmp1,time_stamp);
          http_tcpclient_close(iVar1);
          pcVar3 = (char *)0x0;
        }
        else {
          memset(http_buf,0,0x2000);
          iVar2 = http_tcpclient_recv(iVar1,http_buf);
          if (iVar2 < 1) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s: tcp client recv failed\n","http_get");
            builtin_strncpy(tmp1,"tcp client recv failed",0x17);
            log_to_file(tmp1,time_stamp);
            http_tcpclient_close(iVar1);
            pcVar3 = (char *)0x0;
          }
          else {
            http_tcpclient_close(iVar1);
            pcVar3 = http_parse_result(http_buf,ver1_0,raw);
          }
        }
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: parse url failed!\n","http_get");
      builtin_strncpy(tmp1,"parse url failed",0x10);
      tmp1[0x10] = '!';
      tmp1[0x11] = '\0';
      log_to_file(tmp1,time_stamp);
      pcVar3 = (char *)0x0;
    }
  }
  return pcVar3;
}

