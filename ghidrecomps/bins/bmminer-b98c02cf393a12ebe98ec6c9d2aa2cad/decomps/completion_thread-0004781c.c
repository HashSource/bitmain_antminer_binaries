
undefined4 completion_thread(int param_1)

{
  pthread_setcanceltype(1,(int *)0x0);
  (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 0x14));
  _cgsem_post(param_1,"util.c",DAT_00047848,0xe55);
  return 0;
}

