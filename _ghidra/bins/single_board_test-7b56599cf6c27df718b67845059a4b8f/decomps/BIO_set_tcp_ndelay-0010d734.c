
int BIO_set_tcp_ndelay(int sock,int turn_on)

{
  int iVar1;
  int local_c;
  
  local_c = turn_on;
  iVar1 = setsockopt(sock,6,1,&local_c,4);
  return (uint)(iVar1 == 0);
}

