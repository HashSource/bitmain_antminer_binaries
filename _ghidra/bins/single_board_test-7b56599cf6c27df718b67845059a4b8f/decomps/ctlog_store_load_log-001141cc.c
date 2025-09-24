
int ctlog_store_load_log(int param_1,undefined4 param_2,undefined4 *param_3)

{
  char *group;
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  CONF *conf;
  undefined4 local_1c;
  
  local_1c = 0;
  if (param_1 == 0) {
    return 1;
  }
  group = (char *)CRYPTO_strndup(param_1,param_2,"crypto/ct/ct_log.c",0xa7);
  if (group == (char *)0x0) {
LAB_0011427c:
    CTLOG_free(local_1c);
    ERR_put_error(0x32,0x82,0x41,"crypto/ct/ct_log.c",0xbf);
    return -1;
  }
  conf = (CONF *)param_3[1];
  pcVar1 = NCONF_get_string(conf,group,"description");
  if (pcVar1 == (char *)0x0) {
    ERR_put_error(0x32,0x77,0x6f,"crypto/ct/ct_log.c",0x7d);
  }
  else {
    pcVar2 = NCONF_get_string(conf,group,"key");
    if (pcVar2 != (char *)0x0) {
      iVar3 = CTLOG_new_from_base64(&local_1c,pcVar2,pcVar1);
      CRYPTO_free(group);
      if (iVar3 < 0) {
        return iVar3;
      }
      if (iVar3 != 0) {
        iVar3 = OPENSSL_sk_push(*(undefined4 *)*param_3,local_1c);
        if (iVar3 != 0) {
          return 1;
        }
        goto LAB_0011427c;
      }
      goto LAB_0011425a;
    }
    ERR_put_error(0x32,0x77,0x70,"crypto/ct/ct_log.c",0x83);
  }
  CRYPTO_free(group);
LAB_0011425a:
  param_3[2] = param_3[2] + 1;
  return 1;
}

