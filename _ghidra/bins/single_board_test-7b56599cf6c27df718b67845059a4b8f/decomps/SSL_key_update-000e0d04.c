
undefined4 SSL_key_update(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) ||
     (iVar1 = **(int **)(param_1 + 4), iVar1 < 0x304 || iVar1 == 0x10000)) {
    uVar2 = 0;
    ERR_put_error(0x14,0x203,0x10a,"ssl/ssl_lib.c",0x84c);
  }
  else {
    if (1 < param_2) {
      ERR_put_error(0x14,0x203,0x78,"ssl/ssl_lib.c",0x852);
      return 0;
    }
    iVar1 = SSL_is_init_finished();
    if (iVar1 == 0) {
      ERR_put_error(0x14,0x203,0x79,"ssl/ssl_lib.c",0x857);
      uVar2 = 0;
    }
    else {
      iVar1 = RECORD_LAYER_write_pending(param_1 + 0x650);
      if (iVar1 == 0) {
        uVar2 = 1;
        ossl_statem_set_in_init(param_1,1);
        *(uint *)(param_1 + 0x5f0) = param_2;
      }
      else {
        ERR_put_error(0x14,0x203,0x7f,"ssl/ssl_lib.c",0x85c);
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

