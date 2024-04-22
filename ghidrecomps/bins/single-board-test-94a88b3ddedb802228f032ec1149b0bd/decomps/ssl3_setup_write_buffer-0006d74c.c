
undefined4 ssl3_setup_write_buffer(SSL *param_1)

{
  int iVar1;
  size_t *psVar2;
  size_t sVar3;
  int iVar4;
  size_t sVar5;
  size_t *psVar6;
  ssl3_state_st *psVar7;
  size_t num;
  _func_3296 *p_Var8;
  
  iVar1 = SSL_version(param_1);
  if (iVar1 == 0xfeff) {
    iVar1 = 0x61;
    iVar4 = 0xe;
  }
  else {
    iVar1 = SSL_version(param_1);
    if (iVar1 == 0x100) {
      iVar1 = 0x61;
      iVar4 = 0xe;
    }
    else {
      iVar1 = 0x58;
      iVar4 = 5;
    }
  }
  if ((param_1->s3->wbuf).buf == (uchar *)0x0) {
    iVar4 = iVar4 + param_1->client_version;
    if (param_1->references << 0xe < 0) {
      num = iVar4 + 0x53;
    }
    else {
      num = iVar4 + 0x453;
    }
    p_Var8 = param_1->psk_server_callback;
    if (-1 < param_1->references << 0x14) {
      num = num + iVar1;
    }
    CRYPTO_lock(9,0xc,DAT_0006d828,0x25b);
    psVar6 = *(size_t **)(p_Var8 + 0x15c);
    if (((psVar6 == (size_t *)0x0) || (num != *psVar6)) ||
       (psVar2 = (size_t *)psVar6[2], psVar2 == (size_t *)0x0)) {
      CRYPTO_lock(10,0xc,DAT_0006d828,0x265);
      psVar2 = (size_t *)CRYPTO_malloc(num,DAT_0006d828,0x267);
      if (psVar2 == (size_t *)0x0) {
        ERR_put_error(0x14,0x123,0x41,DAT_0006d828,0x2ce);
        return 0;
      }
    }
    else {
      sVar5 = psVar6[1];
      sVar3 = *psVar2;
      psVar6[1] = sVar5 - 1;
      psVar6[2] = sVar3;
      if (sVar5 - 1 == 0) {
        *psVar6 = 0;
      }
      CRYPTO_lock(10,0xc,DAT_0006d828,0x265);
    }
    psVar7 = param_1->s3;
    (psVar7->wbuf).buf = (uchar *)psVar2;
    (psVar7->wbuf).len = num;
  }
  return 1;
}

