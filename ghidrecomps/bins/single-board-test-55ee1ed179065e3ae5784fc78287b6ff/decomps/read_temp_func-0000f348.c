
void read_temp_func(byte *param_1)

{
  byte bVar1;
  
  bVar1 = *param_1;
  do {
    if ((*(char *)((int)&gIsReadTemp + (uint)bVar1) != '\0') &&
       (*(char *)((int)&gIsOpenCoreEnd + (uint)bVar1) != '\0')) {
      *(undefined *)((int)&gReadingTemp + (uint)bVar1) = 1;
      usleep(Conf._200_4_ * 0xf);
      if (Conf[252] == '\x01') {
        read_asic_temperature(bVar1);
      }
      else {
        printf("\n%s: please config sensor_model in Config.ini\n","read_temp_func");
      }
      if (*(char *)((int)&gNotReadOutTemp + (uint)bVar1) != '\x01') {
        set_PWM_according_to_temperature(bVar1);
      }
      *(undefined *)((int)&gReadingTemp + (uint)bVar1) = 0;
    }
    usleep(1000000);
  } while( true );
}

