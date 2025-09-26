
int BIO_get_port(char *str,ushort *port_ptr)

{
  int iVar1;
  uint uVar2;
  undefined4 local_1c;
  
  local_1c = 0;
  if (str == (char *)0x0) {
    ERR_put_error(0x20,0x6b,0x71,"crypto/bio/b_sock.c",0x40);
    return 0;
  }
  iVar1 = BIO_sock_init();
  if (iVar1 == 1) {
    iVar1 = BIO_lookup(0,str,0,2,1,&local_1c);
    if (iVar1 == 0) {
      ERR_add_error_data(2,"host=",str);
      uVar2 = 0;
    }
    else {
      iVar1 = BIO_ADDRINFO_family(local_1c);
      if (iVar1 == 2) {
        BIO_ADDRINFO_address(local_1c);
        uVar2 = BIO_ADDR_rawport();
        *port_ptr = (ushort)((uVar2 & 0xff) << 8) | (ushort)(uVar2 >> 8) & 0xff;
      }
      else {
        ERR_put_error(0x20,0x6b,0x8d,"crypto/bio/b_sock.c",0x4a);
      }
      uVar2 = (uint)(iVar1 == 2);
      BIO_ADDRINFO_free(local_1c);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

