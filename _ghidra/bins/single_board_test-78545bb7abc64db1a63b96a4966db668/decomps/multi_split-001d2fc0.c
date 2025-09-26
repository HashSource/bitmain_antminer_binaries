
int multi_split(BIO *param_1,char *param_2,int *param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  size_t sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  BIO_METHOD *type;
  size_t __n;
  char *pcVar9;
  char cVar10;
  BIO *local_43c;
  char acStack_428 [1028];
  
  sVar5 = strlen(param_2);
  iVar6 = OPENSSL_sk_new_null();
  *param_3 = iVar6;
  if (iVar6 == 0) {
    return 0;
  }
  bVar3 = true;
  cVar10 = '\0';
  local_43c = (BIO *)0x0;
  bVar1 = false;
  do {
    do {
      while( true ) {
        iVar7 = BIO_gets(param_1,acStack_428,0x400);
        if (iVar7 < 1) {
          BIO_free(local_43c);
          return 0;
        }
        __n = sVar5;
        if (sVar5 == 0xffffffff) {
          __n = strlen(param_2);
        }
        if (((iVar7 <= (int)(__n + 1)) || (iVar8 = strncmp(acStack_428,"--",2), iVar8 != 0)) ||
           (iVar8 = strncmp(acStack_428 + 2,param_2,__n), iVar8 != 0)) break;
        iVar7 = strncmp(acStack_428 + __n + 2,"--",2);
        if (iVar7 == 0) {
          iVar6 = OPENSSL_sk_push(iVar6,local_43c);
          if (iVar6 != 0) {
            return 1;
          }
          goto LAB_001d3116;
        }
        cVar10 = cVar10 + '\x01';
        bVar3 = true;
      }
    } while (cVar10 == '\0');
    pcVar9 = acStack_428 + iVar7;
    bVar4 = false;
    do {
      while( true ) {
        bVar2 = bVar4;
        pcVar9 = pcVar9 + -1;
        if (*pcVar9 == '\n') break;
        if ((*pcVar9 != '\r') || (iVar7 = iVar7 + -1, bVar4 = bVar2, iVar7 == 0)) goto LAB_001d3084;
      }
      iVar7 = iVar7 + -1;
      bVar2 = true;
      bVar4 = true;
    } while (iVar7 != 0);
LAB_001d3084:
    if (bVar3) {
      if ((local_43c != (BIO *)0x0) && (iVar8 = OPENSSL_sk_push(iVar6,local_43c), iVar8 == 0)) {
        iVar6 = 0;
LAB_001d3116:
        BIO_free(local_43c);
        return iVar6;
      }
      type = BIO_s_mem();
      local_43c = BIO_new(type);
      if (local_43c == (BIO *)0x0) {
        return 0;
      }
      BIO_ctrl(local_43c,0x82,0,(void *)0x0);
    }
    else if (bVar1) {
      BIO_write(local_43c,"\r\n",2);
    }
    bVar1 = bVar2;
    if (iVar7 == 0) {
      bVar3 = false;
    }
    else {
      bVar3 = false;
      BIO_write(local_43c,acStack_428,iVar7);
    }
  } while( true );
}

