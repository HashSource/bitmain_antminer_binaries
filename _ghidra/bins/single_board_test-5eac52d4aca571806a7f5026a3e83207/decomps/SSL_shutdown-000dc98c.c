
int SSL_shutdown(SSL *s)

{
  int iVar1;
  undefined4 uVar2;
  int local_28;
  SSL *local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if (s->rwstate == 0) {
    ERR_put_error(0x14,0xe0,0x114,"ssl/ssl_lib.c",0x82d);
    return -1;
  }
  iVar1 = SSL_in_init();
  if (iVar1 == 0) {
    if ((-1 < s[3].new_session << 0x17) || (local_20 = ASYNC_get_current_job(), local_20 != 0)) {
      iVar1 = (**(code **)(s->type + 0x2c))(s);
      return iVar1;
    }
    iVar1 = s[9].verify_result;
    local_14 = *(undefined4 *)(s->type + 0x2c);
    local_18 = 2;
    local_24 = s;
    local_1c = local_20;
    if (iVar1 == 0) {
      iVar1 = ASYNC_WAIT_CTX_new();
      s[9].verify_result = iVar1;
      if (iVar1 == 0) goto LAB_000dca4e;
    }
    s->bbio = (BIO *)0x1;
    uVar2 = ASYNC_start_job(&s[9].debug,iVar1,&local_28,0xdb44d,&local_24,0x14);
    switch(uVar2) {
    case 0:
      s->bbio = (BIO *)0x1;
      ERR_put_error(0x14,0x185,0x195,"ssl/ssl_lib.c",0x6ab);
      local_28 = -1;
      break;
    case 1:
      local_28 = -1;
      s->bbio = (BIO *)&DAT_00000006;
      break;
    case 2:
      local_28 = -1;
      s->bbio = (BIO *)&DAT_00000005;
      break;
    case 3:
      s[9].debug = 0;
      break;
    default:
      s->bbio = (BIO *)0x1;
      ERR_put_error(0x14,0x185,0x44,"ssl/ssl_lib.c",0x6b8);
      local_28 = -1;
    }
  }
  else {
    ERR_put_error(0x14,0xe0,0x197,"ssl/ssl_lib.c",0x83f);
LAB_000dca4e:
    local_28 = -1;
  }
  return local_28;
}

