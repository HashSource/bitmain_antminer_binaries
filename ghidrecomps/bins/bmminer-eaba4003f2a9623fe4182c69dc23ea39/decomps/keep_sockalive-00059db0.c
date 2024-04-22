
void keep_sockalive(long fd)

{
  long fd_local;
  int tcp_keepintvl;
  int tcp_keepidle;
  int tcp_one;
  int flags;
  
  tcp_one = 1;
  tcp_keepidle = 0x2d;
  tcp_keepintvl = 0x1e;
  flags = fcntl(fd,3,0);
  fcntl(fd,4,flags | 0x800);
  setsockopt(fd,1,9,&tcp_one,4);
  if (opt_delaynet != true) {
    fcntl(fd,2,1);
  }
  setsockopt(fd,6,1,&tcp_one,4);
  setsockopt(fd,6,6,&tcp_one,4);
  setsockopt(fd,6,4,&tcp_keepidle,4);
  setsockopt(fd,6,5,&tcp_keepintvl,4);
  return;
}

