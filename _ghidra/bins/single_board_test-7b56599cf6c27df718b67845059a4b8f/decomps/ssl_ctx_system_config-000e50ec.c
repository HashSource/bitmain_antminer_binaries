
void ssl_ctx_system_config(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  char *local_2c;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar5 = 0;
  local_2c = (char *)0x0;
  if (param_1 == (int *)0x0) {
    ERR_put_error(0x14,0x187,0x43,"ssl/ssl_mcnf.c",0x21);
    SSL_CONF_CTX_free(0);
    return;
  }
  local_2c = "system_default";
  iVar1 = conf_ssl_name_find("system_default",&local_28);
  if (iVar1 != 0) {
    uVar2 = conf_ssl_get(local_28,&local_2c,&local_24);
    iVar1 = SSL_CONF_CTX_new();
    if (iVar1 != 0) {
      iVar6 = *param_1;
      SSL_CONF_CTX_set_ssl_ctx(iVar1,param_1);
      if (*(int *)(iVar6 + 0x18) == 0xdf6dd) {
        uVar3 = 6;
        uVar4 = 2;
      }
      else {
        uVar3 = 0xe;
        uVar4 = 10;
      }
      if (*(int *)(iVar6 + 0x1c) == 0xdf6dd) {
        uVar3 = uVar4;
      }
      SSL_CONF_CTX_set_flags(iVar1,uVar3);
      if (local_24 != 0) {
        do {
          conf_ssl_get_cmd(uVar2,uVar5,&local_20,&local_1c);
          uVar5 = uVar5 + 1;
          iVar6 = SSL_CONF_cmd(iVar1,local_20,local_1c);
          if (iVar6 < 1) {
            if (iVar6 == -2) {
              ERR_put_error(0x14,0x187,0x8b,"ssl/ssl_mcnf.c",0x48);
            }
            else {
              ERR_put_error(0x14,0x187,0x180,"ssl/ssl_mcnf.c",0x4a);
            }
            ERR_add_error_data(6,"section=",local_2c,", cmd=",local_20,", arg=",local_1c);
            SSL_CONF_CTX_free(iVar1);
            return;
          }
        } while (uVar5 < local_24);
      }
      SSL_CONF_CTX_finish(iVar1);
      SSL_CONF_CTX_free(iVar1);
      return;
    }
  }
  SSL_CONF_CTX_free(0);
  return;
}

