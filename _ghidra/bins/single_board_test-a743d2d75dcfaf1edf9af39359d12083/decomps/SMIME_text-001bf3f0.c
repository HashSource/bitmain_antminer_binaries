
int SMIME_text(BIO *in,BIO *out)

{
  _STACK *st;
  int iVar1;
  void *pvVar2;
  char *local_1018 [1025];
  
  st = (_STACK *)mime_parse_hdr();
  if (st == (_STACK *)0x0) {
    ERR_put_error(0xd,0xd5,0xcf,"asn_mime.c",0x238);
    iVar1 = 0;
  }
  else {
    local_1018[0] = "content-type";
    iVar1 = sk_find(st,local_1018);
    if (((iVar1 < 0) || (pvVar2 = sk_value(st,iVar1), pvVar2 == (void *)0x0)) ||
       (*(char **)((int)pvVar2 + 4) == (char *)0x0)) {
      ERR_put_error(0xd,0xd5,0xce,"asn_mime.c",0x23c);
      sk_pop_free(st,(func *)0x1be1e1);
      iVar1 = 0;
    }
    else {
      iVar1 = strcmp(*(char **)((int)pvVar2 + 4),"text/plain");
      if (iVar1 == 0) {
        sk_pop_free(st,(func *)0x1be1e1);
        while( true ) {
          iVar1 = BIO_read(in,local_1018,0x1000);
          if (iVar1 < 1) break;
          BIO_write(out,local_1018,iVar1);
        }
        if (iVar1 == 0) {
          iVar1 = 1;
        }
        else {
          iVar1 = 0;
        }
      }
      else {
        ERR_put_error(0xd,0xd5,0xcd,"asn_mime.c",0x241);
        ERR_add_error_data(2,"type: ",*(undefined4 *)((int)pvVar2 + 4));
        sk_pop_free(st,(func *)0x1be1e1);
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}

