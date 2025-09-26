
int dtls1_write_app_data_bytes(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = SSL_in_init();
  if ((iVar1 != 0) && (iVar1 = ossl_statem_get_in_handshake(param_1), iVar1 == 0)) {
    iVar1 = (**(code **)(param_1 + 0x18))(param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (iVar1 == 0) {
      ERR_put_error(0x14,0x10c,0xe5,"ssl/d1_msg.c",0x17);
      return -1;
    }
  }
  if (0x4000 < param_4) {
    ERR_put_error(0x14,0x10c,0x14e,"ssl/d1_msg.c",0x1d);
    return -1;
  }
  iVar1 = dtls1_write_bytes(param_1,param_2,param_3,param_4);
  return iVar1;
}

