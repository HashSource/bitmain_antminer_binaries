
int SSL_peek(SSL *ssl,void *buf,int num)

{
  stack_st_void *psVar1;
  undefined4 uVar2;
  int iVar3;
  stack_st_void *local_28;
  SSL *local_24;
  void *local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  
  if (num < 0) {
    ERR_put_error(0x14,0x10e,0x10f,"ssl/ssl_lib.c",0x77a);
    return -1;
  }
  if (ssl->rwstate == 0) {
    ERR_put_error(0x14,0x20a,0x114,"ssl/ssl_lib.c",0x75b);
    return -1;
  }
  if (ssl->new_session << 0x1e < 0) {
    return 0;
  }
  if ((-1 < ssl[3].new_session << 0x17) || (local_18 = ASYNC_get_current_job(), local_18 != 0)) {
    psVar1 = (stack_st_void *)(**(code **)(ssl->type + 0x24))(ssl,buf,num,&local_28);
    goto LAB_000dc576;
  }
  iVar3 = ssl[9].verify_result;
  local_14 = *(undefined4 *)(ssl->type + 0x24);
  local_24 = ssl;
  local_20 = buf;
  local_1c = num;
  if (iVar3 == 0) {
    iVar3 = ASYNC_WAIT_CTX_new();
    ssl[9].verify_result = iVar3;
    if (iVar3 != 0) goto LAB_000dc5a2;
    local_28 = (stack_st_void *)0xffffffff;
  }
  else {
LAB_000dc5a2:
    ssl->bbio = (BIO *)0x1;
    uVar2 = ASYNC_start_job(&ssl[9].debug,iVar3,&local_28,0xdb44d,&local_24,0x14);
    switch(uVar2) {
    case 0:
      ssl->bbio = (BIO *)0x1;
      ERR_put_error(0x14,0x185,0x195,"ssl/ssl_lib.c",0x6ab);
      local_28 = (stack_st_void *)0xffffffff;
      break;
    case 1:
      local_28 = (stack_st_void *)0xffffffff;
      ssl->bbio = (BIO *)&DAT_00000006;
      break;
    case 2:
      local_28 = (stack_st_void *)0xffffffff;
      ssl->bbio = (BIO *)&DAT_00000005;
      break;
    case 3:
      ssl[9].debug = 0;
      break;
    default:
      ssl->bbio = (BIO *)0x1;
      ERR_put_error(0x14,0x185,0x44,"ssl/ssl_lib.c",0x6b8);
      local_28 = (stack_st_void *)0xffffffff;
    }
  }
  psVar1 = local_28;
  local_28 = ssl[9].ex_data.sk;
LAB_000dc576:
  if (0 < (int)psVar1) {
    psVar1 = local_28;
  }
  return (int)psVar1;
}

