
void look_str_cb(undefined4 param_1,_STACK *param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  void *pvVar2;
  size_t __n;
  int iVar3;
  int iVar4;
  char *__s;
  int local_24;
  
  iVar3 = param_4[1];
  if (param_4[1] == 0) {
    do {
      iVar1 = sk_num(param_2);
      iVar4 = iVar3 + 1;
      if (iVar1 <= iVar3) {
        return;
      }
      pvVar2 = sk_value(param_2,iVar3);
      (**(code **)((int)pvVar2 + 0x30))(pvVar2,&local_24,0,param_1);
      iVar1 = local_24;
      __s = *(char **)(local_24 + 0xc);
      __n = strlen(__s);
      iVar3 = iVar4;
    } while ((__n != param_4[3]) || (iVar4 = strncasecmp(__s,(char *)param_4[2],__n), iVar4 != 0));
    *param_4 = pvVar2;
    param_4[1] = iVar1;
  }
  return;
}

