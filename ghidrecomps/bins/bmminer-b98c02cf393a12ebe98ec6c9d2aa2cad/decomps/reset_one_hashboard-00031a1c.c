
void reset_one_hashboard(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
  set_QN_write_data_command(param_1 << 0x10 | 0x8000000f);
  while( true ) {
    uVar1 = get_QN_write_data_command();
    if (-1 < (int)uVar1) break;
    usleep(10000);
  }
  (*(code *)PTR_sleep_0007ceac)(1,(int)((ulonglong)uVar1 >> 0x20),param_3,param_4);
  return;
}

