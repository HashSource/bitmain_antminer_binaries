
void * pt1_board_protect_func(void *args)

{
  pthread_t __th;
  int iVar1;
  void *args_local;
  char time_stamp [48];
  char tmp1 [256];
  int i;
  int time_acc;
  
  time_acc = (Local_Config_Information->Test_Info).Max_PT1_Board_Poweron_Time;
  if (time_acc == 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Have not cfg max board poweron time.\n","pt1_board_protect_func");
    builtin_strncpy(tmp1,"Have not cfg max board poweron time.",0x24);
    tmp1[0x24] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  else {
    while (iVar1 = time_acc + -1, 0 < time_acc) {
      for (i = 0; i < 10; i = i + 1) {
        usleep(100000);
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : PT1 board power on left %d\n","pt1_board_protect_func",iVar1);
      snprintf(tmp1,0x100,"PT1 board power on left %d",iVar1);
      log_to_file(tmp1,time_stamp);
      time_acc = iVar1;
    }
    err_exit("power protect");
  }
  __th = pthread_self();
  pthread_detach(__th);
  return (void *)0x0;
}

