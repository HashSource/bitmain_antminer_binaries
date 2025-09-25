
char * ssl_request(char *url,char *post_str)

{
  int iVar1;
  SSL_METHOD *meth;
  SSL_CTX *ctx_00;
  SSL *s;
  int iVar2;
  SSL_CIPHER *c;
  size_t sVar3;
  int *piVar4;
  char *pcVar5;
  char *post_str_local;
  char *url_local;
  char time_stamp [48];
  char tmp1 [256];
  int port;
  char file [2048];
  char host_addr [2048];
  char lpbuf [8192];
  SSL *ssl;
  SSL_CTX *ctx;
  int len;
  int socket_id;
  char *resp;
  
  puts("https request");
  memset(lpbuf,0,0x2000);
  memset(host_addr,0,0x800);
  memset(file,0,0x800);
  port = 0;
  resp = (char *)0x0;
  if ((url == (char *)0x0) || (post_str == (char *)0x0)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : http_post parameter check failed!\n","ssl_request");
    builtin_strncpy(tmp1,"http_post parameter check failed",0x20);
    tmp1[0x20] = '!';
    tmp1[0x21] = '\0';
    log_to_file(tmp1,time_stamp);
    resp = (char *)0x0;
  }
  else {
    iVar1 = http_parse_url(url,host_addr,file,&port);
    if (iVar1 == 0) {
      printf("host:%s,file:%s,port:%d\n",host_addr,file,port);
      printf("log parse url:%s addr:%s file:%s port:%d \n",url,host_addr,file,port);
      iVar1 = create_connection_to_server_by_name(host_addr,port);
      OPENSSL_init_ssl(0,0,0);
      OPENSSL_init_crypto(0xc,0,0);
      OPENSSL_init_ssl("table signature algorithm",0,0);
      meth = (SSL_METHOD *)TLS_client_method();
      ctx_00 = SSL_CTX_new(meth);
      if (ctx_00 == (SSL_CTX *)0x0) {
        ERR_print_errors_fp(stdout);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      s = SSL_new(ctx_00);
      SSL_set_fd(s,iVar1);
      iVar2 = SSL_connect(s);
      if (iVar2 == -1) {
        ERR_print_errors_fp(stderr);
      }
      else {
        c = SSL_get_current_cipher(s);
        pcVar5 = SSL_CIPHER_get_name(c);
        printf("Connected with %s encryption\n",pcVar5);
      }
      iVar2 = port;
      sVar3 = strlen(post_str);
      snprintf(lpbuf,0x2000,
               "POST /%s HTTP/1.1\r\nHOST: %s:%d\r\nAccept: */*\r\nContent-Type:application/json\r\nConnection:keep-alive\r\nContent-Length: %d\r\n\r\n"
               ,file,host_addr,iVar2,sVar3);
      sVar3 = strlen(lpbuf);
      iVar2 = SSL_write(s,lpbuf,sVar3);
      if (-1 < iVar2) {
        sVar3 = strlen(post_str);
        iVar2 = SSL_write(s,post_str,sVar3);
        if (-1 < iVar2) {
          memset(lpbuf,0,0x2000);
          iVar2 = SSL_read(s,lpbuf,0x2000);
          if (iVar2 < 0) {
            piVar4 = __errno_location();
            iVar2 = *piVar4;
            piVar4 = __errno_location();
            pcVar5 = strerror(*piVar4);
            printf("msg recv fail,errcode:%d,err msg:%s\n",iVar2,pcVar5);
          }
          else {
            resp = http_parse_result(lpbuf,false,false);
          }
        }
      }
      SSL_shutdown(s);
      SSL_free(s);
      close(iVar1);
      SSL_CTX_free(ctx_00);
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : http_parse_url failed!\n","ssl_request");
      builtin_strncpy(tmp1,"http_parse_url failed!",0x17);
      log_to_file(tmp1,time_stamp);
      resp = (char *)0x0;
    }
  }
  return resp;
}

