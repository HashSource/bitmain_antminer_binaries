
void set_led(int param_1)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  char acStack_74 [104];
  
  blink_14032 = blink_14032 ^ 1;
  iVar1 = are_pools_active();
  if (iVar1 == 0) {
    if (isC5_CtrlBoard == '\0') {
      if (is7007_ctrl_board == -1) {
        isC5_Board();
      }
      if (is7007_ctrl_board == 1) {
        sprintf(acStack_74,"echo %d > %s",0,"/sys/class/gpio/gpio942/value");
        system(acStack_74);
        uVar2 = 1;
LAB_00034bd2:
        sprintf(acStack_74,"echo %d > %s",uVar2,"/sys/class/gpio/gpio941/value");
        system(acStack_74);
        return;
      }
      sprintf(acStack_74,"echo %d > %s",0,"/sys/class/gpio/gpio38/value");
      system(acStack_74);
      pcVar3 = "/sys/class/gpio/gpio37/value";
    }
    else {
      sprintf(acStack_74,"echo %d > %s",0,"/sys/class/leds/hps_led0/brightness");
      system(acStack_74);
      pcVar3 = "/sys/class/leds/hps_led2/brightness";
    }
    sprintf(acStack_74,"echo %d > %s",1,pcVar3);
    system(acStack_74);
  }
  else {
    if (isC5_CtrlBoard != '\0') {
      if (param_1 != 0) {
        sprintf(acStack_74,"echo %d > %s",0,"/sys/class/leds/hps_led0/brightness");
        system(acStack_74);
        sprintf(acStack_74,"echo %d > %s",(uint)blink_14032,"/sys/class/leds/hps_led2/brightness");
        system(acStack_74);
        return;
      }
      sprintf(acStack_74,"echo %d > %s",0,"/sys/class/leds/hps_led2/brightness");
      system(acStack_74);
      sprintf(acStack_74,"echo %d > %s",(uint)blink_14032,"/sys/class/leds/hps_led0/brightness");
      system(acStack_74);
      return;
    }
    if (is7007_ctrl_board == -1) {
      isC5_Board();
    }
    if (is7007_ctrl_board == 1) {
      if (param_1 != 0) {
        sprintf(acStack_74,"echo %d > %s",0,"/sys/class/gpio/gpio942/value");
        system(acStack_74);
        uVar2 = (uint)blink_14032;
        goto LAB_00034bd2;
      }
      sprintf(acStack_74,"echo %d > %s",0,"/sys/class/gpio/gpio941/value");
      system(acStack_74);
      sprintf(acStack_74,"echo %d > %s",(uint)blink_14032,"/sys/class/gpio/gpio942/value");
      system(acStack_74);
    }
    else if (param_1 == 0) {
      sprintf(acStack_74,"echo %d > %s",0,"/sys/class/gpio/gpio37/value");
      system(acStack_74);
      sprintf(acStack_74,"echo %d > %s",(uint)blink_14032,"/sys/class/gpio/gpio38/value");
      system(acStack_74);
    }
    else {
      sprintf(acStack_74,"echo %d > %s",0,"/sys/class/gpio/gpio38/value");
      system(acStack_74);
      sprintf(acStack_74,"echo %d > %s",(uint)blink_14032,"/sys/class/gpio/gpio37/value");
      system(acStack_74);
    }
  }
  return;
}

