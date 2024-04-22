
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

void read_config(void)

{
  uint uVar1;
  FILE *__stream;
  FILE *file;
  char *pcVar2;
  char *temp;
  char *pcVar3;
  uint uVar4;
  char cVar5;
  int starttemp;
  char str [1024];
  
  memset(str,0,0x400);
  starttemp = 0;
  __stream = fopen("/mnt/card/Config.ini","r");
LAB_00018474:
  pcVar2 = fgets(str,0x3ff,__stream);
  if (pcVar2 != (char *)0x0) {
    while( true ) {
      if ((str[0] == '#') || (str[1] == '#')) goto LAB_00018474;
      pcVar2 = strstr(str,"Name=");
      if (pcVar2 == (char *)0x0) break;
      gName_len = 0;
      pcVar2 = pcVar2 + 5;
      cVar5 = *pcVar2;
      pcVar3 = DAT_0001873c;
      do {
        pcVar3 = pcVar3 + 1;
        *pcVar3 = cVar5;
        gName_len = gName_len + 1;
        pcVar2 = pcVar2 + 1;
        cVar5 = *pcVar2;
        if (cVar5 == '\r' || cVar5 == '\n') goto LAB_000184cc;
      } while (gName_len != 0x40);
      gName_len = 0x41;
LAB_000184cc:
      Conf.name[gName_len] = '\0';
      gHashBoard_BHB91601P = false;
      gHashBoard_BHB91603S = false;
      gHashBoard_V9 = false;
      gHashBoard_BHB91601S = false;
      if (Conf.name._0_4_ == 0x39424842) {
        if (Conf.name._4_4_ == 0x31303631) {
          if (Conf.name[8] == 'P') {
            gHashBoard_BHB91601P = true;
            printf("\n---%s: gHashBoard_BHB91601P\n\n","read_config");
            if (Conf.name._0_4_ != 0x39424842) goto LAB_000184f6;
            if (Conf.name._4_4_ != 0x31303631) goto LAB_00018636;
          }
          if (Conf.name[8] == 'S') {
            gHashBoard_BHB91601S = true;
            printf("\n---%s: gHashBoard_BHB91601S\n\n","read_config");
            if (Conf.name._0_4_ != 0x39424842) goto LAB_000184f6;
            goto LAB_00018636;
          }
        }
        else {
LAB_00018636:
          if ((Conf.name._4_4_ == 0x33303631) && (Conf.name[8] == 'S')) {
            gHashBoard_BHB91603S = true;
            printf("\n---%s: gHashBoard_BHB91603S\n\n","read_config");
            goto LAB_000184f6;
          }
        }
      }
      else {
LAB_000184f6:
        if ((Conf.name._0_4_ == 0x30424842) && (Conf.name._4_4_ == 0x31303637)) {
          gHashBoard_BHB07601 = true;
          printf("\n---%s: gHashBoard_BHB07601\n\n","read_config");
        }
      }
      if ((Conf.name._0_4_ & 0xffff) != 0x3956) goto LAB_00018474;
      gHashBoard_V9 = true;
      printf("\n---%s: gHashBoard_V9\n\n","read_config");
      pcVar2 = fgets(str,0x3ff,__stream);
      if (pcVar2 == (char *)0x0) goto LAB_00018536;
    }
    pcVar2 = strstr(str,"pattern_number=");
    if (pcVar2 == (char *)0x0) {
      pcVar2 = strstr(str,"AsicNum=");
      if (pcVar2 == (char *)0x0) {
        pcVar2 = strstr(str,"AsicType=");
        if (pcVar2 == (char *)0x0) {
          pcVar2 = strstr(str,"Freq1=");
          if (pcVar2 == (char *)0x0) {
            pcVar2 = strstr(str,"Freq2=");
            if (pcVar2 == (char *)0x0) {
              pcVar2 = strstr(str,"Freq3=");
              if (pcVar2 == (char *)0x0) {
                pcVar2 = strstr(str,"Freq4=");
                if (pcVar2 == (char *)0x0) {
                  pcVar2 = strstr(str,"Freq5=");
                  if (pcVar2 == (char *)0x0) {
                    pcVar2 = strstr(str,"Freq6=");
                    if (pcVar2 == (char *)0x0) {
                      pcVar2 = strstr(str,"Freq7=");
                      if (pcVar2 == (char *)0x0) {
                        pcVar2 = strstr(str,"Freq8=");
                        if (pcVar2 == (char *)0x0) {
                          pcVar2 = strstr(str,"Freq9=");
                          if (pcVar2 == (char *)0x0) {
                            pcVar2 = strstr(str,"Voltage1=");
                            if (pcVar2 != (char *)0x0) {
                              __isoc99_sscanf(pcVar2 + 9,&DAT_0002b908,DAT_00018db8);
                              if (Conf.Voltage1 != 0) {
                                gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01';
                              }
                              printf("Voltage1 = %d\n");
                              goto LAB_00018474;
                            }
                            pcVar2 = strstr(str,"Voltage2=");
                            if (pcVar2 == (char *)0x0) {
                              pcVar2 = strstr(str,"Voltage3=");
                              if (pcVar2 == (char *)0x0) {
                                pcVar2 = strstr(str,"Voltage4=");
                                if (pcVar2 == (char *)0x0) {
                                  pcVar2 = strstr(str,"Voltage5=");
                                  if (pcVar2 == (char *)0x0) {
                                    pcVar2 = strstr(str,"Voltage6=");
                                    if (pcVar2 == (char *)0x0) {
                                      pcVar2 = strstr(str,"Voltage7=");
                                      if (pcVar2 == (char *)0x0) {
                                        pcVar2 = strstr(str,"Voltage8=");
                                        if (pcVar2 == (char *)0x0) {
                                          pcVar2 = strstr(str,"Voltage9=");
                                          if (pcVar2 == (char *)0x0) {
                                            pcVar2 = strstr(str,"Voltage_accuracy=");
                                            if (pcVar2 == (char *)0x0) {
                                              pcVar2 = strstr(str,"OpenCoreGap=");
                                              if (pcVar2 == (char *)0x0) {
                                                pcVar2 = strstr(str,"CheckTemp=");
                                                if (pcVar2 == (char *)0x0) {
                                                  pcVar2 = strstr(str,"Open_Core_Num1=");
                                                  if (pcVar2 == (char *)0x0) {
                                                    pcVar2 = strstr(str,"Open_Core_Num2=");
                                                    if (pcVar2 == (char *)0x0) {
                                                      pcVar2 = strstr(str,"Open_Core_Num3=");
                                                      if (pcVar2 == (char *)0x0) {
                                                        pcVar2 = strstr(str,"Open_Core_Num4=");
                                                        if (pcVar2 == (char *)0x0) {
                                                          pcVar2 = strstr(str,"Open_Core_Num5=");
                                                          if (pcVar2 == (char *)0x0) {
                                                            pcVar2 = strstr(str,"Open_Core_Num6=");
                                                            if (pcVar2 == (char *)0x0) {
                                                              pcVar2 = strstr(str,"Open_Core_Num7=")
                                                              ;
                                                              if (pcVar2 == (char *)0x0) {
                                                                pcVar2 = strstr(str,
                                                  "Open_Core_Num8=");
                                                  if (pcVar2 == (char *)0x0) {
                                                    pcVar2 = strstr(str,"sensor_model=");
                                                    if (pcVar2 == (char *)0x0) {
                                                      pcVar2 = strstr(str,"remote_local_gap=");
                                                      if (pcVar2 != (char *)0x0) {
                                                        __isoc99_sscanf(pcVar2 + 0x11,&DAT_0002c32c,
                                                                        DAT_00019128);
                                                        goto LAB_00018474;
                                                      }
                                                      pcVar2 = strstr(str,"TempSensor1=");
                                                      if (pcVar2 == (char *)0x0) {
                                                        pcVar2 = strstr(str,"TempSensor2=");
                                                        if (pcVar2 == (char *)0x0) {
                                                          pcVar2 = strstr(str,"TempSensor3=");
                                                          if (pcVar2 == (char *)0x0) {
                                                            pcVar2 = strstr(str,"TempSensor4=");
                                                            if (pcVar2 == (char *)0x0) {
                                                              pcVar2 = strstr(str,"StartSensor=");
                                                              if (pcVar2 == (char *)0x0) {
                                                                pcVar2 = strstr(str,"StartTemp=");
                                                                if (pcVar2 == (char *)0x0) {
                                                                  pcVar2 = strstr(str,"TargetTemp=")
                                                                  ;
                                                                  if (pcVar2 == (char *)0x0) {
                                                                    pcVar2 = strstr(str,
                                                  "add_voltage_after_test_ok=");
                                                  if (pcVar2 == (char *)0x0) {
                                                    pcVar2 = strstr(str,"add_voltage_value=");
                                                    if (pcVar2 == (char *)0x0) {
                                                      pcVar2 = strstr(str,"AlarmTemp=");
                                                      if (pcVar2 == (char *)0x0) {
                                                        pcVar2 = strstr(str,"HeatingUpTime=");
                                                        if (pcVar2 == (char *)0x0) {
                                                          pcVar2 = strstr(str,"MaxTempGap=");
                                                          if (pcVar2 == (char *)0x0) {
                                                            pcVar2 = strstr(str,"Invalid_Asic_Num=")
                                                            ;
                                                            if (pcVar2 == (char *)0x0) {
                                                              pcVar2 = strstr(str,
                                                  "Invalid_Core_Num=");
                                                  if (pcVar2 == (char *)0x0) {
                                                    pcVar2 = strstr(str,"Least_nonce_per_core=");
                                                    if (pcVar2 == (char *)0x0) {
                                                      pcVar2 = strstr(str,"Most_HW_Num=");
                                                      if (pcVar2 == (char *)0x0) {
                                                        pcVar2 = strstr(str,"close_power_delay=");
                                                        if (pcVar2 == (char *)0x0) {
                                                          pcVar2 = strstr(str,"fan_speed=");
                                                          if (pcVar2 == (char *)0x0) {
                                                            pcVar2 = strstr(str,
                                                  "HashBoard_Hardware_Version_1=");
                                                  if (pcVar2 == (char *)0x0) {
                                                    pcVar2 = strstr(str,
                                                  "HashBoard_Hardware_Version_2=");
                                                  if (pcVar2 == (char *)0x0) {
                                                    pcVar2 = strstr(str,"HashBoard_Bom_Version_1=");
                                                    if (pcVar2 == (char *)0x0) {
                                                      pcVar2 = strstr(str,"HashBoard_Bom_Version_2="
                                                                     );
                                                      if (pcVar2 == (char *)0x0) {
                                                        pcVar2 = strstr(str,"HashBoard_Product_ID=")
                                                        ;
                                                        if (pcVar2 == (char *)0x0) {
                                                          pcVar2 = strstr(str,"timeout_percent=");
                                                          if (pcVar2 == (char *)0x0) {
                                                            pcVar2 = strstr(str,"baudrate=");
                                                            if (pcVar2 == (char *)0x0) {
                                                              pcVar2 = strstr(str,"Only_find_ASIC=")
                                                              ;
                                                              if (pcVar2 == (char *)0x0) {
                                                                pcVar2 = strstr(str,
                                                  "pre_open_core_voltage=");
                                                  if (pcVar2 == (char *)0x0) {
                                                    pcVar2 = strstr(str,"io_strength=");
                                                    if (pcVar2 == (char *)0x0) {
                                                      pcVar2 = strstr(str,"repair_mode=");
                                                      if (pcVar2 == (char *)0x0) {
                                                        pcVar2 = strstr(str,"Dump_Lost_Nonce=");
                                                        if (pcVar2 == (char *)0x0) {
                                                          pcVar2 = strstr(str,"CoreClockDelay=");
                                                          if (pcVar2 == (char *)0x0) {
                                                            pcVar2 = strstr(str,
                                                  "bad_chip_nonce_rate=");
                                                  if (pcVar2 == (char *)0x0) {
                                                    pcVar2 = strstr(str,"bad_chip_num=");
                                                    if (pcVar2 != (char *)0x0) {
                                                      __isoc99_sscanf(pcVar2 + 0xd,&DAT_0002b908,
                                                                      DAT_00019630);
                                                      printf("bad_chip_num = %d\n",Conf.bad_chip_num
                                                            );
                                                    }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x14,&DAT_0002b908,
                                                                    DAT_0001962c);
                                                    printf("bad_chip_nonce_rate = %d\n",
                                                           Conf.bad_chip_nonce_rate);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xf,&DAT_0002c190,
                                                                    DAT_00019628);
                                                    printf("CoreClockDelay = 0x%02x\n",
                                                           Conf.CoreClockDelay);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x10,&DAT_0002b908,
                                                                    DAT_00019624);
                                                    printf("Dump_Lost_Nonce = %d\n",
                                                           Conf.Dump_Lost_Nonce);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xc,&DAT_0002b908,
                                                                    DAT_0001961c);
                                                    uVar4 = Conf.repair_mode;
                                                    *DAT_00019620 = Conf.repair_mode;
                                                    printf("repair_mode = %d\n",uVar4);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xc,&DAT_0002c190,
                                                                    DAT_00019504);
                                                    if (Conf.io_strength == 0) {
                                                      Conf.io_strength = 0x2112111;
                                                    }
                                                    uVar4 = Conf.io_strength;
                                                    *DAT_00019508 = Conf.io_strength;
                                                    printf("io_strength = 0x%08x\n",uVar4);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x16,&DAT_0002b908,
                                                                    DAT_00019500);
                                                    printf("pre_open_core_voltage = %d\n",
                                                           Conf.pre_open_core_voltage);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xf,&DAT_0002b908,
                                                                    DAT_000194f8);
                                                    uVar4 = Conf.Only_find_ASIC & 0xff;
                                                    *DAT_000194fc = (char)Conf.Only_find_ASIC;
                                                    printf("Only_find_ASIC = %d\n",uVar4);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 9,&DAT_0002b908,
                                                                    DAT_000194f0);
                                                    uVar4 = Conf.baud & 0xff;
                                                    *DAT_000194f4 = (char)Conf.baud;
                                                    printf("baudrate = %d\n",uVar4);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x10,&DAT_0002b908,
                                                                    DAT_000194e8);
                                                    uVar4 = Conf.timeout_percent & 0xff;
                                                    *DAT_000194ec = (char)Conf.timeout_percent;
                                                    printf("timeout_percent = %d\n",uVar4);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x15,&DAT_0002b908,
                                                                    DAT_000194e4);
                                                    printf("HashBoard_Product_ID = %d\n",
                                                           Conf.HashBoard_Product_ID);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x18,&DAT_0002b908,
                                                                    DAT_000194e0);
                                                    printf("HashBoard_Bom_Version_2 = %d\n",
                                                           Conf.HashBoard_Bom_Version_2);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x18,&DAT_0002b908,
                                                                    DAT_000194dc);
                                                    printf("HashBoard_Bom_Version_1 = %d\n",
                                                           Conf.HashBoard_Bom_Version_1);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x1d,&DAT_0002b908,
                                                                    DAT_000194d8);
                                                    printf("HashBoard_Hardware_Version_2 = %d\n",
                                                           Conf.HashBoard_Hardware_Version_2);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x1d,&DAT_0002b908,
                                                                    DAT_000194d4);
                                                    printf("HashBoard_Hardware_Version_1 = %d\n",
                                                           Conf.HashBoard_Hardware_Version_1);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 10,&DAT_0002b908,
                                                                    DAT_000194cc);
                                                    uVar4 = Conf.fan_speed;
                                                    *DAT_000194d0 = (char)Conf.fan_speed;
                                                    printf("fan_speed = %d\n",uVar4);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x12,&DAT_0002b908,
                                                                    DAT_000194c8);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xc,&DAT_0002b908,
                                                                    DAT_000194c4);
                                                    printf("Most_HW_Num = %d\n",Conf.Most_HW_Num);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x15,&DAT_0002b908,
                                                                    DAT_000194c0);
                                                    printf("Least_nonce_per_core = %d\n",
                                                           Conf.Least_nonce_per_core);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x11,&DAT_0002b908,
                                                                    DAT_000194bc);
                                                    printf("Invalid_Core_Num = %d\n",
                                                           Conf.Invalid_Core_Num);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x11,&DAT_0002b908,
                                                                    DAT_000194b8);
                                                    printf("Invalid_Asic_Num = %d\n",
                                                           Conf.Invalid_Asic_Num);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xb,&DAT_0002b908,
                                                                    DAT_00019158);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xe,&DAT_0002b908,
                                                                    DAT_00019154);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 10,&DAT_0002b908,
                                                                    DAT_00019150);
                                                    printf("AlarmTemp = %d\n",Conf.AlarmTemp);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x12,&DAT_0002b908,
                                                                    DAT_0001914c);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0x1a,&DAT_0002b908,
                                                                    DAT_00019148);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xb,&DAT_0002b908,
                                                                    DAT_00019144);
                                                    printf("TargetTemp = %d\n",Conf.TargetTemp);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 10,&DAT_0002b908,
                                                                    DAT_00019140);
                                                    __isoc99_sscanf(pcVar2 + 10,&DAT_0002b908,
                                                                    &starttemp);
                                                    Conf.StartTemp = starttemp;
                                                    if (starttemp < 0) {
                                                      starttemp = -starttemp;
                                                      Conf.StartTemp = -(int)(char)starttemp;
                                                    }
                                                    printf("StartTemp = %d\n");
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xc,&DAT_0002b908,
                                                                    DAT_0001913c);
                                                  }
                                                  goto LAB_00018474;
                                                  }
                                                  __isoc99_sscanf(pcVar2 + 0xc,&DAT_0002b908,
                                                                  DAT_00019138);
                                                  uVar4 = Conf.TempSensor4;
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xc,&DAT_0002b908,
                                                                    DAT_00019134);
                                                    uVar4 = Conf.TempSensor3;
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xc,&DAT_0002b908,
                                                                    DAT_00019130);
                                                    uVar4 = Conf.TempSensor2;
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xc,&DAT_0002b908,
                                                                    DAT_0001912c);
                                                    uVar4 = Conf.TempSensor1;
                                                  }
                                                  if (uVar4 != 0) {
                                                    gSensor_number = gSensor_number + 1;
                                                  }
                                                  goto LAB_00018474;
                                                  }
                                                  __isoc99_sscanf(pcVar2 + 0xd,&DAT_0002b908);
                                                  if (Conf.sensor_model == 6) {
                                                    gSensor_i2c_addr_high_4_bit = 0x9a0000;
                                                  }
                                                  else if (Conf.sensor_model == 7) {
                                                    gSensor_i2c_addr_high_4_bit = 0x9c0000;
                                                  }
                                                  else {
                                                    gSensor_i2c_addr_high_4_bit = 0x980000;
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xf,&DAT_0002c190,
                                                                    DAT_00019120);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xf,&DAT_0002c190,
                                                                    DAT_0001911c);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xf,&DAT_0002c190,
                                                                    DAT_00019118);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xf,&DAT_0002c190,
                                                                    DAT_00018df8);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xf,&DAT_0002c190,
                                                                    DAT_00018df4);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xf,&DAT_0002c190,
                                                                    DAT_00018df0);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xf,&DAT_0002c190,
                                                                    DAT_00018dec);
                                                  }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xf,&DAT_0002c190,
                                                                    DAT_00018de8);
                                                  }
                                                }
                                                else {
                                                  __isoc99_sscanf(pcVar2 + 10,&DAT_0002b908,
                                                                  DAT_00018de4);
                                                }
                                              }
                                              else {
                                                __isoc99_sscanf(pcVar2 + 0xc,&DAT_0002b908,
                                                                DAT_00018de0);
                                              }
                                            }
                                            else {
                                              __isoc99_sscanf(pcVar2 + 0x11,&DAT_0002b908,
                                                              DAT_00018ddc);
                                            }
                                            goto LAB_00018474;
                                          }
                                          __isoc99_sscanf(pcVar2 + 9,&DAT_0002b908,DAT_00018dd8);
                                          uVar4 = Conf.Voltage9;
                                        }
                                        else {
                                          __isoc99_sscanf(pcVar2 + 9,&DAT_0002b908,DAT_00018dd4);
                                          uVar4 = Conf.Voltage8;
                                        }
                                      }
                                      else {
                                        __isoc99_sscanf(pcVar2 + 9,&DAT_0002b908,DAT_00018dd0);
                                        uVar4 = Conf.Voltage7;
                                      }
                                    }
                                    else {
                                      __isoc99_sscanf(pcVar2 + 9,&DAT_0002b908,DAT_00018dcc);
                                      uVar4 = Conf.Voltage6;
                                    }
                                  }
                                  else {
                                    __isoc99_sscanf(pcVar2 + 9,&DAT_0002b908,DAT_00018dc8);
                                    uVar4 = Conf.Voltage5;
                                  }
                                }
                                else {
                                  __isoc99_sscanf(pcVar2 + 9,&DAT_0002b908,DAT_00018dc4);
                                  uVar4 = Conf.Voltage4;
                                }
                              }
                              else {
                                __isoc99_sscanf(pcVar2 + 9,&DAT_0002b908,DAT_00018dc0);
                                uVar4 = Conf.Voltage3;
                              }
                            }
                            else {
                              __isoc99_sscanf(pcVar2 + 9,&DAT_0002b908,DAT_00018dbc);
                              uVar4 = Conf.Voltage2;
                            }
                            if (uVar4 != 0) {
                              gHowManyVoltageLevel = gHowManyVoltageLevel + '\x01';
                            }
                            goto LAB_00018474;
                          }
                          __isoc99_sscanf(pcVar2 + 6,&DAT_0002b908,DAT_00018db4);
                        }
                        else {
                          __isoc99_sscanf(pcVar2 + 6,&DAT_0002b908,DAT_00018db0);
                        }
                      }
                      else {
                        __isoc99_sscanf(pcVar2 + 6,&DAT_0002b908,DAT_00018a98);
                      }
                    }
                    else {
                      __isoc99_sscanf(pcVar2 + 6,&DAT_0002b908,DAT_00018a94);
                    }
                  }
                  else {
                    __isoc99_sscanf(pcVar2 + 6,&DAT_0002b908,DAT_00018a90);
                  }
                }
                else {
                  __isoc99_sscanf(pcVar2 + 6,&DAT_0002b908,DAT_00018a8c);
                }
              }
              else {
                __isoc99_sscanf(pcVar2 + 6,&DAT_0002b908,DAT_00018a88);
              }
            }
            else {
              __isoc99_sscanf(pcVar2 + 6,&DAT_0002b908,DAT_00018a84);
            }
          }
          else {
            __isoc99_sscanf(pcVar2 + 6,&DAT_0002b908,DAT_00018a80);
          }
        }
        else {
          __isoc99_sscanf(pcVar2 + 9,&DAT_0002c190,DAT_00018a7c);
        }
      }
      else {
        __isoc99_sscanf(pcVar2 + 8,&DAT_0002b908,DAT_00018a78);
        if (Conf.AsicNum == 1) {
          gChain_Asic_Interval = 0x100;
        }
      }
    }
    else {
      __isoc99_sscanf(pcVar2 + 0xf,&DAT_0002b908,DAT_00018748);
      gPattern_number = Conf.pattern_number;
      printf("gPattern_number = %d\n",Conf.pattern_number);
    }
    goto LAB_00018474;
  }
LAB_00018536:
  uVar1 = Conf.AsicType;
  uVar4 = Conf.AsicNum;
  if (Conf.AsicNum == 1) {
    if (Conf.AsicType == 0x569) {
      strcpy(DAT_00018a70,Single_BM1385_WorkDataPathPrefix);
      strcpy(DAT_00018a74,BTC_WorkDataFilePrefix);
      Conf.CoreNum = 0x32;
      if (gHashBoard_V9 == false) goto LAB_00018820;
    }
    else if (gHashBoard_V9 == false) {
      if (Conf.AsicType - 0x3657 < 2) {
        strcpy(DAT_00018a70,Single_BM1391_WorkDataPathPrefix);
        strcpy(DAT_00018a74,BTC_WorkDataFilePrefix);
        Conf.CoreNum = 0x100;
      }
      if (uVar1 == 0x1397) {
        strcpy(DAT_00018a70,Single_BM1397_WorkDataPathPrefix);
        strcpy(DAT_00018a74,Single_BM1397_WorkDataFilePrefix);
        Conf.CoreNum = 0x2a0;
      }
LAB_00018820:
      if ((gHashBoard_BHB91601P == false) && (gHashBoard_BHB91601S == false)) goto LAB_000185aa;
      strcpy(DAT_00018a70,BHB91601_WorkDataPathPrefix);
      strcpy(DAT_00018a74,BTC_WorkDataFilePrefix);
      goto LAB_000187e8;
    }
LAB_00018766:
    strcpy(DAT_00018a70,V9_WorkDataPathPrefix);
    strcpy(DAT_00018a74,BTC_WorkDataFilePrefix);
    gPic_addr_high_4_bit = 0xa00000;
    gChain_Asic_Interval = 4;
    Conf.AsicNum = 0x2d;
    Conf.CoreNum = 0x32;
    Conf.AsicType = 0x569;
    if ((gHashBoard_BHB91601P == false) && (gHashBoard_BHB91601S == false)) goto LAB_000185aa;
    strcpy(DAT_00018a70,BHB91601_WorkDataPathPrefix);
    strcpy(DAT_00018a74,BTC_WorkDataFilePrefix);
  }
  else {
    if (gHashBoard_V9 != false) goto LAB_00018766;
    if ((gHashBoard_BHB91601P == false) && (gHashBoard_BHB91601S == false)) goto LAB_000185aa;
    strcpy(DAT_00018740,BHB91601_WorkDataPathPrefix);
    strcpy(DAT_00018744,BTC_WorkDataFilePrefix);
    gPic_addr_high_4_bit = 0x400000;
    gChain_Asic_Interval = 3;
    Conf.CoreNum = 0x100;
    if ((uVar4 == 0x3c) || ((uVar4 == 0x48 || (uVar4 == 0x54)))) {
      BHB91601_ASIC_NUMBER = uVar4;
      goto LAB_000185aa;
    }
  }
LAB_000187e8:
  Conf.CoreNum = 0x100;
  gPic_addr_high_4_bit = 0x400000;
  gChain_Asic_Interval = 3;
  BHB91601_ASIC_NUMBER = 0x54;
  printf("\n!!! %s: Don\'t find AsicNum in Config.ini, please config it\n\n","read_config");
LAB_000185aa:
  if (gHashBoard_BHB91603S != false) {
    strcpy(DAT_00018740,BHB91603_WorkDataPathPrefix);
    strcpy(DAT_00018744,BTC_WorkDataFilePrefix);
    gPic_addr_high_4_bit = 0x400000;
    gChain_Asic_Interval = 2;
    BHB91601_ASIC_NUMBER = 0x60;
    Conf.CoreNum = 0x100;
  }
  if (gHashBoard_BHB07601 != false) {
    strcpy(DAT_00018740,BHB07601_WorkDataPathPrefix);
    strcpy(DAT_00018744,BHB07601_WorkDataFilePrefix);
    gPic_addr_high_4_bit = 0x400000;
    gChain_Asic_Interval = 5;
    BHB07601_ASIC_NUMBER = 0x30;
    Conf.CoreNum = 0x2a0;
  }
  return;
}

