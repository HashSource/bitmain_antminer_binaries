
void getAsicNumTest(char param_1)

{
  uint uVar1;
  FILE *pFVar2;
  int local_c;
  
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    testDone[local_c] = 0;
  }
  puts("clement2 init_fpga");
  if (param_1 != '\0') {
    start_pic_heart = 0;
    pthread_mutex_lock((pthread_mutex_t *)iic_mutex);
    reset_fpga();
    pthread_mutex_unlock((pthread_mutex_t *)iic_mutex);
    send_pic_heart_once();
    start_pic_heart = 1;
  }
  reset_global_arg();
  start_receive = 1;
  gStartTest = 0;
  puts("clement reset_hashboard");
  if (param_1 != '\0') {
    set_reset_allhashboard(1);
    sleep(3);
    set_reset_allhashboard(0);
    sleep(1);
  }
  puts("\n--- set command mode");
  if (conf._40_4_ == 0) {
    puts("clement2 set_dhash_acc_control vil");
    uVar1 = get_dhash_acc_control();
    set_dhash_acc_control(uVar1 & 0xffff7edf | 0x8100);
    cgpu._2562268_4_ = 0;
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d: set command mode to VIL\n","main.c",0x3245);
      }
      fclose(pFVar2);
    }
  }
  else {
    cgpu._2562268_4_ = 1;
    puts("set command mode to FIL");
  }
  if (Conf._124_4_ != 0) {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d: \n--- check asic number\n","main.c",0x324b);
      }
      fclose(pFVar2);
    }
    for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
      if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) == 1) &&
         (check_asic_reg_oneChain(local_c,CHIP_ADDRESS & 0xff), 3 < log_level)) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d: check chain[%d]: asicNum = %d\n","main.c",0x3252,local_c,
                  (uint)(byte)cgpu[local_c + 0x271924]);
        }
        fclose(pFVar2);
      }
    }
  }
  return;
}

