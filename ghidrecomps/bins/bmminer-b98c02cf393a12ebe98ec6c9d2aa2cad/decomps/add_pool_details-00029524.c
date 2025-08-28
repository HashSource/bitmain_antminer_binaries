
undefined1
add_pool_details(void *param_1,int param_2,undefined4 param_3,char *param_4,char *param_5)

{
  undefined1 uVar1;
  undefined4 uVar2;
  size_t sVar3;
  size_t sVar4;
  char *__s;
  
  uVar2 = get_proxy(param_3,param_1);
  *(char **)((int)param_1 + 0xac) = param_4;
  *(undefined4 *)((int)param_1 + 0xa4) = uVar2;
  *(char **)((int)param_1 + 0xb0) = param_5;
  sVar3 = strlen(param_4);
  sVar4 = strlen(param_5);
  sVar3 = sVar4 + sVar3 + 2;
  __s = (char *)_cgmalloc(sVar3,"cgminer.c","add_pool_details",0x29db);
  *(char **)((int)param_1 + 0xa8) = __s;
  snprintf(__s,sVar3,"%s:%s",*(undefined4 *)((int)param_1 + 0xac),
           *(undefined4 *)((int)param_1 + 0xb0));
  *(undefined1 *)((int)param_1 + 0x11c) = 1;
  *(byte *)((int)param_1 + 0x6b) = (byte)param_2 ^ 1;
  *(undefined1 *)((int)param_1 + 0x61) = 1;
  if (*(int *)((int)param_1 + 100) != 1) {
    *(undefined4 *)((int)param_1 + 100) = 1;
    enabled_pools = enabled_pools + 1;
  }
  pthread_create((pthread_t *)((int)param_1 + 0x118),(pthread_attr_t *)0x0,
                 (__start_routine *)0x23015,param_1);
  uVar1 = 1;
  if (param_2 == 0) {
    pthread_join(*(pthread_t *)((int)param_1 + 0x118),(void **)0x0);
    uVar1 = pools_active;
  }
  return uVar1;
}

