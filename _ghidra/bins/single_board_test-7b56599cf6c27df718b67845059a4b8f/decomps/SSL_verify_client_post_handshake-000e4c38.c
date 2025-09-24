
undefined4 SSL_verify_client_post_handshake(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) ||
     (iVar1 = **(int **)(param_1 + 4), iVar1 < 0x304 || iVar1 == 0x10000)) {
    uVar2 = 0;
    ERR_put_error(0x14,0x268,0x10a,"ssl/ssl_lib.c",0x1608);
  }
  else {
    if (*(int *)(param_1 + 0x1c) == 0) {
      ERR_put_error(0x14,0x268,0x11c,"ssl/ssl_lib.c",0x160c);
      return 0;
    }
    iVar1 = SSL_is_init_finished();
    if (iVar1 == 0) {
      ERR_put_error(0x14,0x268,0x79,"ssl/ssl_lib.c",0x1611);
      uVar2 = 0;
    }
    else {
      switch(*(undefined4 *)(param_1 + 0x5f4)) {
      case 0:
        uVar2 = 0;
        ERR_put_error(0x14,0x268,0x117,"ssl/ssl_lib.c",0x1617);
        break;
      default:
        uVar2 = 0;
        ERR_put_error(0x14,0x268,0x44,"ssl/ssl_lib.c",0x161b);
        break;
      case 2:
        *(undefined4 *)(param_1 + 0x5f4) = 3;
        iVar1 = send_certificate_request(param_1);
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0x5f4) = 2;
          ERR_put_error(0x14,0x268,0x11b,"ssl/ssl_lib.c",0x162c);
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
          ossl_statem_set_in_init(param_1,1);
        }
        break;
      case 3:
        uVar2 = 0;
        ERR_put_error(0x14,0x268,0x11d,"ssl/ssl_lib.c",0x1620);
        break;
      case 4:
        uVar2 = 0;
        ERR_put_error(0x14,0x268,0x11e,"ssl/ssl_lib.c",0x1623);
      }
    }
  }
  return uVar2;
}

