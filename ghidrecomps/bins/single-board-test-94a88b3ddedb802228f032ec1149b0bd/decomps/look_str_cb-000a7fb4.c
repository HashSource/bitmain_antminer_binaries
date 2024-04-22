
void look_str_cb(undefined4 param_1,_STACK *param_2,undefined4 param_3,void **param_4)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  void *__n;
  void *pvVar4;
  void *pvVar5;
  char *__s;
  void *local_24;
  
  pvVar4 = param_4[1];
  if (param_4[1] == (void *)0x0) {
    do {
      iVar2 = sk_num(param_2);
      pvVar5 = (void *)((int)pvVar4 + 1);
      if (iVar2 <= (int)pvVar4) {
        return;
      }
      pvVar3 = sk_value(param_2,(int)pvVar4);
      (**(code **)((int)pvVar3 + 0x30))(pvVar3,&local_24,0,param_1);
      pvVar1 = local_24;
      __s = *(char **)((int)local_24 + 0xc);
      __n = (void *)strlen(__s);
      pvVar4 = pvVar5;
    } while ((__n != param_4[3]) ||
            (iVar2 = strncasecmp(__s,(char *)param_4[2],(size_t)__n), iVar2 != 0));
    *param_4 = pvVar3;
    param_4[1] = pvVar1;
  }
  return;
}

