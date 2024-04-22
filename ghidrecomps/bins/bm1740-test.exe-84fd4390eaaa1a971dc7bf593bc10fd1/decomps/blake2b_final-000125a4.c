
undefined4 blake2b_final(int param_1,void *param_2,byte param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined auStack_4c [64];
  int local_c;
  
  memset(auStack_4c,0,0x40);
  if (((param_2 == (void *)0x0) || (param_3 == 0)) || (0x40 < param_3)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar3 = blake2b_is_lastblock(param_1);
    if ((int)uVar3 == 0) {
      if (0x80 < *(uint *)(param_1 + 0x160)) {
        blake2b_increment_counter(param_1,(int)((ulonglong)uVar3 >> 0x20),0x80,0);
        blake2b_compress(param_1,param_1 + 0x60);
        *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + -0x80;
        memcpy((void *)(param_1 + 0x60),(void *)(param_1 + 0xe0),*(size_t *)(param_1 + 0x160));
      }
      blake2b_increment_counter
                (param_1,*(undefined4 *)(param_1 + 0x160),*(undefined4 *)(param_1 + 0x160),0);
      blake2b_set_lastblock(param_1);
      memset((void *)(param_1 + *(int *)(param_1 + 0x160) + 0x60),0,
             0x100 - *(int *)(param_1 + 0x160));
      blake2b_compress(param_1,param_1 + 0x60);
      for (local_c = 0; local_c < 8; local_c = local_c + 1) {
        puVar2 = (undefined4 *)(param_1 + local_c * 8);
        store64(auStack_4c + local_c * 8,auStack_4c + local_c * 8,*puVar2,puVar2[1]);
      }
      memcpy(param_2,auStack_4c,(uint)param_3);
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

