
undefined4 multi_split(BIO *param_1,char *param_2,_STACK **param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  size_t sVar5;
  int iVar6;
  int iVar7;
  BIO_METHOD *type;
  size_t __n;
  char cVar8;
  BIO *b;
  undefined4 local_42c;
  char acStack_428 [2];
  char acStack_426 [1026];
  
  cVar8 = '\0';
  bVar3 = true;
  b = (BIO *)0x0;
  sVar5 = strlen(param_2);
  local_42c = sk_new_null();
  *param_3 = local_42c;
  bVar1 = false;
  do {
    do {
      while( true ) {
        iVar6 = BIO_gets(param_1,acStack_428,0x400);
        if (iVar6 < 1) {
          return 0;
        }
        __n = sVar5;
        if (sVar5 == 0xffffffff) {
          __n = strlen(param_2);
        }
        if (((iVar6 <= (int)(__n + 1)) || (iVar7 = strncmp(acStack_428,DAT_0012730c,2), iVar7 != 0))
           || (iVar7 = strncmp(acStack_426,param_2,__n), iVar7 != 0)) break;
        iVar6 = strncmp(acStack_426 + __n,DAT_0012730c,2);
        if (iVar6 == 0) {
          sk_push(local_42c,b);
          return 1;
        }
        cVar8 = cVar8 + '\x01';
        bVar3 = true;
      }
    } while (cVar8 == '\0');
    bVar4 = false;
    do {
      while (bVar2 = bVar4, acStack_428[iVar6 + -1] != '\n') {
        if ((acStack_428[iVar6 + -1] != '\r') || (iVar6 = iVar6 + -1, bVar4 = bVar2, iVar6 == 0))
        goto LAB_0012729a;
      }
      iVar6 = iVar6 + -1;
      bVar2 = true;
      bVar4 = true;
    } while (iVar6 != 0);
LAB_0012729a:
    if (bVar3) {
      if (b != (BIO *)0x0) {
        sk_push(local_42c,b);
      }
      type = BIO_s_mem();
      b = BIO_new(type);
      BIO_ctrl(b,0x82,0,(void *)0x0);
    }
    else if (bVar1) {
      BIO_write(b,DAT_00127310,2);
    }
    bVar1 = bVar2;
    if (iVar6 == 0) {
      bVar3 = false;
    }
    else {
      bVar3 = false;
      BIO_write(b,acStack_428,iVar6);
    }
  } while( true );
}

