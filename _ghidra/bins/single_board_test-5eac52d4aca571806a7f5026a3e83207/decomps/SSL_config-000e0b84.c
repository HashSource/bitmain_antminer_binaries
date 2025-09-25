
bool SSL_config(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_2c = param_2;
  if (param_1 == 0) {
    ERR_put_error(0x14,0x187,0x43,"ssl/ssl_mcnf.c",0x21);
    SSL_CONF_CTX_free(0);
    return false;
  }
  iVar1 = conf_ssl_name_find(param_2,&local_28);
  if (iVar1 == 0) {
    ERR_put_error(0x14,0x187,0x71,"ssl/ssl_mcnf.c",0x29);
    ERR_add_error_data(2,"name=",local_2c);
  }
  else {
    uVar2 = conf_ssl_get(local_28,&local_2c,&local_24);
    iVar1 = SSL_CONF_CTX_new();
    if (iVar1 != 0) {
      iVar5 = *(int *)(param_1 + 4);
      SSL_CONF_CTX_set_ssl(iVar1,param_1);
      if (*(int *)(iVar5 + 0x18) == 0xdb48d) {
        uVar3 = 0x66;
        uVar4 = 0x62;
      }
      else {
        uVar3 = 0x6e;
        uVar4 = 0x6a;
      }
      if (*(int *)(iVar5 + 0x1c) == 0xdb48d) {
        uVar3 = uVar4;
      }
      SSL_CONF_CTX_set_flags(iVar1,uVar3);
      if (local_24 != 0) {
        uVar6 = 0;
        do {
          conf_ssl_get_cmd(uVar2,uVar6,&local_20,&local_1c);
          uVar6 = uVar6 + 1;
          iVar5 = SSL_CONF_cmd(iVar1,local_20,local_1c);
          if (iVar5 < 1) {
            if (iVar5 == -2) {
              ERR_put_error(0x14,0x187,0x8b,"ssl/ssl_mcnf.c",0x48);
            }
            else {
              ERR_put_error(0x14,0x187,0x180,"ssl/ssl_mcnf.c",0x4a);
            }
            ERR_add_error_data(6,"section=",local_2c,", cmd=",local_20,", arg=",local_1c);
            SSL_CONF_CTX_free(iVar1);
            return false;
          }
        } while (uVar6 < local_24);
      }
      iVar5 = SSL_CONF_CTX_finish(iVar1);
      SSL_CONF_CTX_free(iVar1);
      return 0 < iVar5;
    }
  }
  SSL_CONF_CTX_free(0);
  return false;
}

