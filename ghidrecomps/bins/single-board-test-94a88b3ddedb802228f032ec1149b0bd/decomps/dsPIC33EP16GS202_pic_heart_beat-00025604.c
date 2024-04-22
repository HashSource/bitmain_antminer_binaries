
/* WARNING: Removing unreachable block (ram,0x00025790) */

undefined4 dsPIC33EP16GS202_pic_heart_beat(undefined param_1)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  
  pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
  usleep(500000);
  T9_plus_write_pic_iic(0,0,0,param_1,0x55);
  T9_plus_write_pic_iic(0,0,0,param_1,0xaa);
  T9_plus_write_pic_iic(0,0,0,param_1,4);
  T9_plus_write_pic_iic(0,0,0,param_1,0x16);
  T9_plus_write_pic_iic(0,0,0,param_1,0);
  T9_plus_write_pic_iic(0,0,0,param_1,0x1a);
  usleep(500000);
  T9_plus_write_pic_iic(1,0,0,param_1,0);
  cVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
  cVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
  T9_plus_write_pic_iic(1,0,0,param_1,0);
  T9_plus_write_pic_iic(1,0,0,param_1,0);
  T9_plus_write_pic_iic(1,0,0,param_1,0);
  pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
  if ((cVar1 == '\x16') && (cVar2 == '\x01')) {
    uVar3 = 1;
  }
  else {
    sleep(1);
    uVar3 = 0;
  }
  return uVar3;
}

