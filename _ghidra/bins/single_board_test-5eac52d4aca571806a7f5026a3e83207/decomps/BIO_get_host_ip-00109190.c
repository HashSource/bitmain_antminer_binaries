
int BIO_get_host_ip(char *str,uchar *ip)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_20;
  int local_1c [2];
  
  iVar3 = 0;
  local_20 = 0;
  iVar1 = BIO_sock_init();
  if (iVar1 == 1) {
    iVar1 = BIO_lookup(str,0,0,2,1,&local_20);
    if (iVar1 == 0) {
      ERR_add_error_data(2,"host=",str);
      iVar3 = 0;
    }
    else {
      iVar1 = BIO_ADDRINFO_family(local_20);
      if (iVar1 == 2) {
        uVar2 = BIO_ADDRINFO_address(local_20);
        iVar1 = BIO_ADDR_rawaddress(uVar2,0,local_1c);
        if (iVar1 == 0) {
          iVar3 = 0;
        }
        else if (local_1c[0] == 4) {
          uVar2 = BIO_ADDRINFO_address(local_20);
          iVar3 = BIO_ADDR_rawaddress(uVar2,ip,local_1c);
        }
      }
      else {
        ERR_put_error(0x20,0x6a,0x6b,"crypto/bio/b_sock.c",0x29);
      }
      BIO_ADDRINFO_free(local_20);
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}

