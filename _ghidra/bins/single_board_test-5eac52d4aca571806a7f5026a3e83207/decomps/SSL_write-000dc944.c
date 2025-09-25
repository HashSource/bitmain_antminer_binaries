
int SSL_write(SSL *ssl,void *buf,int num)

{
  int iVar1;
  int local_c [2];
  
  if (num < 0) {
    ERR_put_error(0x14,0xd0,0x10f,"ssl/ssl_lib.c",0x7c2);
    iVar1 = -1;
  }
  else {
    iVar1 = ssl_write_internal(ssl,buf,num,local_c);
    if (0 < iVar1) {
      iVar1 = local_c[0];
    }
  }
  return iVar1;
}

