
undefined4 bitmain_c5_prepare(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 *__s;
  byte bVar4;
  uint uVar5;
  pthread_mutex_t *__mutex;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined local_1c [2];
  undefined2 local_1a;
  
  __mutex = *(pthread_mutex_t **)(*(int *)(param_1 + 0x24) + 0x14);
  *(int *)((int)__mutex + 0x29c) = param_1;
  iVar2 = pthread_mutex_init((pthread_mutex_t *)((int)__mutex + 0x2a4),(pthread_mutexattr_t *)0x0);
  if (iVar2 == 0) {
    iVar2 = pthread_mutex_init(__mutex,(pthread_mutexattr_t *)0x0);
  }
  else {
    _mutex_init_part_3_constprop_28(0x40e3);
    iVar2 = pthread_mutex_init(__mutex,(pthread_mutexattr_t *)0x0);
  }
  if (iVar2 != 0) {
    _mutex_init_part_3_constprop_28(0x40e4);
  }
  _rwlock_init_constprop_22(__mutex + 1,0x40e4);
  iVar2 = pthread_mutex_init((pthread_mutex_t *)((int)__mutex + 0x3b4),(pthread_mutexattr_t *)0x0);
  if (iVar2 != 0) {
    _mutex_init_part_3_constprop_28(0x40e5);
  }
  _rwlock_init_constprop_22((int)__mutex + 0x3cc,0x40e5);
  iVar2 = pthread_mutex_init((pthread_mutex_t *)((int)__mutex + 0xaec),(pthread_mutexattr_t *)0x0);
  if (iVar2 != 0) {
    _mutex_init_part_3_constprop_28(0x40e6);
  }
  _rwlock_init_constprop_22((int)__mutex + 0xb04,0x40e6);
  iVar2 = pthread_mutex_init((pthread_mutex_t *)((int)__mutex + 0x1224),(pthread_mutexattr_t *)0x0);
  if (iVar2 != 0) {
    _mutex_init_part_3_constprop_28(0x40e7);
  }
  __s = &local_38;
  _rwlock_init_constprop_22((int)__mutex + 0x123c,0x40e7);
  memset(__s,0,0x20);
  local_38 = CONCAT31(local_38._1_3_,0x51);
  local_38 = CONCAT22(0x1a,(undefined2)local_38);
  local_34 = CONCAT22(local_34._2_2_,0x700);
  local_30 = CONCAT22((ushort)opt_bitmain_fan_pwm & 0xff,0x3609);
  local_30 = CONCAT13(0x50,(undefined3)local_30);
  local_2c = CONCAT13(0x25,CONCAT12(7,(short)opt_bitmain_c5_freq));
  local_28 = CONCAT22(local_28._2_2_,0xa0a);
  local_34 = CONCAT31(local_34._1_3_,(char)((opt_bitmain_fan_ctrl & 1) << 1)) | 0xfd;
  bVar4 = 0x81;
  local_20 = CONCAT31(local_20._1_3_,4);
  local_20 = CONCAT22(400,(undefined2)local_20);
  _local_1c = CONCAT22(local_1a,600);
  uVar3 = 0xff;
  uVar5 = 0xbc;
  while (bVar4 = bVar4 ^ (byte)uVar3, __s != (undefined4 *)(local_1c + 1)) {
    __s = (undefined4 *)((int)__s + 1);
    bVar1 = *(byte *)__s ^ bVar4;
    bVar4 = chCRCHTalbe[bVar1];
    uVar3 = uVar5;
    uVar5 = (uint)(byte)chCRCLTalbe[bVar1];
  }
  _local_1c = CONCAT22((ushort)bVar4 | (ushort)(uVar5 << 8),600);
  bitmain_c5_init(local_38,local_34,local_30,local_2c,local_28,uStack_24,local_20,_local_1c);
  return 1;
}

