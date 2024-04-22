
undefined4 ssl3_setup_read_buffer(SSL *param_1)

{
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  ssl3_state_st *psVar4;
  size_t *psVar5;
  int iVar6;
  size_t *psVar7;
  size_t num;
  _func_3296 *p_Var8;
  bool bVar9;
  
  iVar1 = SSL_version(param_1);
  if (iVar1 == 0xfeff) {
    num = 0x8150;
    iVar1 = 0xd;
  }
  else {
    num = 0x8148;
    iVar1 = SSL_version(param_1);
    if (iVar1 == 0x100) {
      iVar1 = 0xd;
      num = 0x8150;
    }
    else {
      iVar1 = 5;
    }
  }
  psVar5 = (size_t *)(param_1->s3->rbuf).buf;
  if (psVar5 == (size_t *)0x0) {
    iVar6 = param_1->references;
    p_Var8 = param_1->psk_server_callback;
    bVar9 = -1 < iVar6 << 0x1a;
    if (bVar9) {
      num = iVar1 + 0x4100;
    }
    else {
      iVar1 = 1;
    }
    if (bVar9) {
      num = num + 0x43;
    }
    else {
      param_1->s3->init_extra = iVar1;
    }
    if (-1 < iVar6 << 0xe) {
      num = num + 0x400;
    }
    CRYPTO_lock(9,0xc,DAT_0006d748,0x25b);
    psVar7 = *(size_t **)(p_Var8 + 0x160);
    if (((psVar7 == (size_t *)0x0) || (num != *psVar7)) ||
       (psVar5 = (size_t *)psVar7[2], psVar5 == (size_t *)0x0)) {
      CRYPTO_lock(10,0xc,DAT_0006d748,0x265);
      psVar5 = (size_t *)CRYPTO_malloc(num,DAT_0006d748,0x267);
      if (psVar5 == (size_t *)0x0) {
        ERR_put_error(0x14,0x9c,0x41,DAT_0006d748,0x2a9);
        return 0;
      }
    }
    else {
      sVar3 = psVar7[1];
      sVar2 = *psVar5;
      psVar7[1] = sVar3 - 1;
      psVar7[2] = sVar2;
      if (sVar3 - 1 == 0) {
        *psVar7 = 0;
      }
      CRYPTO_lock(10,0xc,DAT_0006d748,0x265);
    }
    psVar4 = param_1->s3;
    (psVar4->rbuf).buf = (uchar *)psVar5;
    (psVar4->rbuf).len = num;
  }
  param_1->packet = (uchar *)psVar5;
  return 1;
}

