
void look_str_cb(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  size_t __n;
  int iVar3;
  int iVar4;
  char *__s;
  int local_2c [2];
  
  if (param_4[1] == 0) {
    iVar3 = 0;
    do {
      do {
        iVar1 = OPENSSL_sk_num(param_2);
        iVar4 = iVar3 + 1;
        if (iVar1 <= iVar3) {
          return;
        }
        iVar2 = OPENSSL_sk_value(param_2,iVar3);
        (**(code **)(iVar2 + 0x28))(iVar2,local_2c,0,param_1);
        iVar1 = local_2c[0];
        iVar3 = iVar4;
      } while (local_2c[0] == 0);
      __s = *(char **)(local_2c[0] + 0xc);
      __n = strlen(__s);
    } while ((__n != param_4[3]) || (iVar4 = strncasecmp(__s,(char *)param_4[2],__n), iVar4 != 0));
    *param_4 = iVar2;
    param_4[1] = iVar1;
  }
  return;
}

