
_Bool set_socket_feature(int32_t socket_fd)

{
  _Bool _Var1;
  int32_t socket_fd_local;
  char time_stamp [48];
  char tmp1 [256];
  timeval timeout;
  int32_t tcp_keepintvl;
  int32_t tcp_keepidle;
  int32_t tcp_one;
  int32_t ret;
  
  tcp_one = 1;
  tcp_keepidle = 0x2d;
  tcp_keepintvl = 0x1e;
  ret = 0;
  timeout.tv_sec = 3;
  timeout.tv_usec = 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : socket_fd = %d\n","set_socket_feature",socket_fd);
  snprintf(tmp1,0x100,"socket_fd = %d",socket_fd);
  log_to_file(tmp1,time_stamp);
  ret = setsockopt(socket_fd,1,0x15,&timeout,8);
  if (ret < 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Set socket send timeout fail, ret = %d\n","set_socket_feature",ret);
    snprintf(tmp1,0x100,"Set socket send timeout fail, ret = %d",ret);
    log_to_file(tmp1,time_stamp);
    _Var1 = false;
  }
  else {
    ret = setsockopt(socket_fd,1,0x14,&timeout,8);
    if (ret < 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Set socket send timeout fail, ret = %d\n","set_socket_feature",ret);
      snprintf(tmp1,0x100,"Set socket send timeout fail, ret = %d",ret);
      log_to_file(tmp1,time_stamp);
      _Var1 = false;
    }
    else {
      ret = setsockopt(socket_fd,1,9,&tcp_one,4);
      if (ret < 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Set socket keep alive fail, ret = %d\n","set_socket_feature",ret);
        snprintf(tmp1,0x100,"Set socket keep alive fail, ret = %d",ret);
        log_to_file(tmp1,time_stamp);
        _Var1 = false;
      }
      else {
        ret = setsockopt(socket_fd,6,1,&tcp_one,4);
        if (ret < 0) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Set socket no delay fail, ret = %d\n","set_socket_feature",ret);
          snprintf(tmp1,0x100,"Set socket no delay fail, ret = %d",ret);
          log_to_file(tmp1,time_stamp);
          _Var1 = false;
        }
        else {
          ret = setsockopt(socket_fd,6,6,&tcp_one,4);
          if (ret < 0) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : Set socket keep cnt fail, ret = %d\n","set_socket_feature",ret);
            snprintf(tmp1,0x100,"Set socket keep cnt fail, ret = %d",ret);
            log_to_file(tmp1,time_stamp);
            _Var1 = false;
          }
          else {
            ret = setsockopt(socket_fd,6,4,&tcp_keepidle,4);
            if (ret < 0) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Set socket keep idle fail, ret = %d\n","set_socket_feature",ret);
              snprintf(tmp1,0x100,"Set socket keep idle fail, ret = %d",ret);
              log_to_file(tmp1,time_stamp);
              _Var1 = false;
            }
            else {
              ret = setsockopt(socket_fd,6,5,&tcp_keepintvl,4);
              if (ret < 0) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : Set socket keep intvl fail, ret = %d\n","set_socket_feature",ret);
                snprintf(tmp1,0x100,"Set socket keep intvl fail, ret = %d",ret);
                log_to_file(tmp1,time_stamp);
                _Var1 = false;
              }
              else {
                _Var1 = true;
              }
            }
          }
        }
      }
    }
  }
  return _Var1;
}

