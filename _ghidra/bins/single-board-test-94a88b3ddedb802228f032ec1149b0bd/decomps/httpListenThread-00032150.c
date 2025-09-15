
undefined4 httpListenThread(void)

{
  int iVar1;
  socklen_t local_40;
  sockaddr sStack_3c;
  sockaddr local_2c;
  FILE *local_1c;
  FILE *local_18;
  FILE *local_14;
  undefined4 local_10;
  int local_c;
  
  local_10 = 0;
  local_c = -1;
  sleep(0x1e);
  do {
    listen_sockfd = socket(2,1,6);
    if (listen_sockfd < 0) {
      if (3 < log_level) {
        local_14 = fopen(log_file,"a+");
        if (local_14 != (FILE *)0x0) {
          fprintf(local_14,"%s:%d: socket creating failed, try again after 10s...\n","main.c",0x350e
                 );
        }
        fclose(local_14);
      }
      sleep(10);
    }
    else {
      memset(&local_2c,0,0x10);
      local_2c.sa_family = 2;
      local_2c.sa_data._2_4_ = htonl(0);
      local_2c.sa_data._0_2_ = htons(0x17ac);
      iVar1 = bind(listen_sockfd,&local_2c,0x10);
      if (iVar1 < 0) {
        if (3 < log_level) {
          local_18 = fopen(log_file,"a+");
          if (local_18 != (FILE *)0x0) {
            fprintf(local_18,"%s:%d: http port bind failed! try again after 10s...\n","main.c",
                    0x351b);
          }
          fclose(local_18);
        }
        close(listen_sockfd);
        listen_sockfd = -1;
        sleep(10);
      }
      else {
        iVar1 = listen(listen_sockfd,100);
        if (-1 < iVar1) break;
        if (3 < log_level) {
          local_1c = fopen(log_file,"a+");
          if (local_1c != (FILE *)0x0) {
            fprintf(local_1c,"%s:%d: http listen failed! try again after 10s...\n","main.c",0x3526);
          }
          fclose(local_1c);
        }
        close(listen_sockfd);
        listen_sockfd = -1;
        sleep(10);
      }
    }
  } while (ExitServer != '\x01');
  puts("start listen on 6060 ...");
  do {
    if (ExitServer == '\x01') {
LAB_000323ea:
      close(listen_sockfd);
      listen_sockfd = 0xffffffff;
      return local_10;
    }
    local_c = -1;
    while ((local_c == -1 && (ExitServer != '\x01'))) {
      usleep(10000);
      local_40 = 0x10;
      local_c = accept(listen_sockfd,&sStack_3c,&local_40);
    }
    if (ExitServer != '\0') {
      if (local_c != -1) {
        close(local_c);
        local_c = -1;
      }
      goto LAB_000323ea;
    }
    printf("one client connected sock=%d\n",local_c);
    statusServiceThread(local_c);
  } while( true );
}

