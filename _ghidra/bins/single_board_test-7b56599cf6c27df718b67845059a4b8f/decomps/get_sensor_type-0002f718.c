
uint8_t get_sensor_type(hashboard_qr_code *qr_code)

{
  int iVar1;
  uint8_t uVar2;
  hashboard_qr_code *qr_code_local;
  char time_stamp [48];
  char tmp1 [256];
  
  iVar1 = strcmp(qr_code->temp_sensor_type,"TMP451");
  if (iVar1 == 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : sensor type is TMP451\n","get_sensor_type");
    builtin_strncpy(tmp1,"sensor type is TMP45",0x14);
    tmp1[0x14] = '1';
    tmp1[0x15] = '\0';
    log_to_file(tmp1,time_stamp);
    uVar2 = '\x01';
  }
  else {
    iVar1 = strcmp(qr_code->temp_sensor_type,"NCT218");
    if (iVar1 == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : sensor type is NCT218\n","get_sensor_type");
      builtin_strncpy(tmp1,"sensor type is NCT21",0x14);
      tmp1[0x14] = '8';
      tmp1[0x15] = '\0';
      log_to_file(tmp1,time_stamp);
      uVar2 = '\x05';
    }
    else {
      iVar1 = strcmp(qr_code->temp_sensor_type,"LM75A");
      if (iVar1 == 0) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : sensor type is LM75A\n","get_sensor_type");
        builtin_strncpy(tmp1,"sensor type is LM75A",0x14);
        tmp1._20_2_ = (ushort)(byte)tmp1[0x15] << 8;
        log_to_file(tmp1,time_stamp);
        uVar2 = '\n';
      }
      else {
        iVar1 = strcmp(qr_code->temp_sensor_type,"TMP75A");
        if (iVar1 == 0) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : sensor type is TMP75A\n","get_sensor_type");
          builtin_strncpy(tmp1,"sensor type is TMP75",0x14);
          tmp1[0x14] = 'A';
          tmp1[0x15] = '\0';
          log_to_file(tmp1,time_stamp);
          uVar2 = '\v';
        }
        else {
          iVar1 = strcmp(qr_code->temp_sensor_type,"DS75S");
          if (iVar1 == 0) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : sensor type is DS75S\n","get_sensor_type");
            builtin_strncpy(tmp1,"sensor type is DS75S",0x14);
            tmp1._20_2_ = (ushort)(byte)tmp1[0x15] << 8;
            log_to_file(tmp1,time_stamp);
            uVar2 = '\f';
          }
          else {
            iVar1 = strcmp(qr_code->temp_sensor_type,"DS75S+");
            if (iVar1 == 0) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : sensor type is DS75S+\n","get_sensor_type");
              builtin_strncpy(tmp1,"sensor type is DS75S",0x14);
              tmp1[0x14] = '+';
              tmp1[0x15] = '\0';
              log_to_file(tmp1,time_stamp);
              uVar2 = '\x0f';
            }
            else {
              iVar1 = strcmp(qr_code->temp_sensor_type,"GM452");
              if (iVar1 == 0) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : sensor type is GM452\n","get_sensor_type");
                builtin_strncpy(tmp1,"sensor type is GM452",0x14);
                tmp1._20_2_ = (ushort)(byte)tmp1[0x15] << 8;
                log_to_file(tmp1,time_stamp);
                uVar2 = '\r';
              }
              else {
                iVar1 = strcmp(qr_code->temp_sensor_type,"CT75");
                if (iVar1 == 0) {
                  print_time_stamp(time_stamp,0x30);
                  printf("%s ",time_stamp);
                  printf("%s : sensor type is CT75\n","get_sensor_type");
                  builtin_strncpy(tmp1,"sensor type is CT75",0x14);
                  log_to_file(tmp1,time_stamp);
                  uVar2 = '\x0e';
                }
                else {
                  iVar1 = strcmp(qr_code->temp_sensor_type,"TMP75");
                  if (iVar1 == 0) {
                    print_time_stamp(time_stamp,0x30);
                    printf("%s ",time_stamp);
                    printf("%s : sensor type is TMP75\n","get_sensor_type");
                    builtin_strncpy(tmp1,"sensor type is TMP75",0x14);
                    tmp1._20_2_ = (ushort)(byte)tmp1[0x15] << 8;
                    log_to_file(tmp1,time_stamp);
                    uVar2 = '\x10';
                  }
                  else {
                    iVar1 = strcmp(qr_code->temp_sensor_type,"SD177");
                    if (iVar1 == 0) {
                      print_time_stamp(time_stamp,0x30);
                      printf("%s ",time_stamp);
                      printf("%s : sensor type is SD177\n","get_sensor_type");
                      builtin_strncpy(tmp1,"sensor type is SD177",0x14);
                      tmp1._20_2_ = (ushort)(byte)tmp1[0x15] << 8;
                      log_to_file(tmp1,time_stamp);
                      uVar2 = '\x11';
                    }
                    else {
                      iVar1 = strcmp(qr_code->temp_sensor_type,"GX21M");
                      if (iVar1 == 0) {
                        print_time_stamp(time_stamp,0x30);
                        printf("%s ",time_stamp);
                        printf("%s : sensor type is GX21M\n","get_sensor_type");
                        builtin_strncpy(tmp1,"sensor type is GX21M",0x14);
                        tmp1._20_2_ = (ushort)(byte)tmp1[0x15] << 8;
                        log_to_file(tmp1,time_stamp);
                        uVar2 = '\x12';
                      }
                      else {
                        iVar1 = strcmp(qr_code->temp_sensor_type,"NT175");
                        if (iVar1 == 0) {
                          print_time_stamp(time_stamp,0x30);
                          printf("%s ",time_stamp);
                          printf("%s : sensor type is NST175\n","get_sensor_type");
                          builtin_strncpy(tmp1,"sensor type is NST17",0x14);
                          tmp1[0x14] = '5';
                          tmp1[0x15] = '\0';
                          log_to_file(tmp1,time_stamp);
                          uVar2 = '\x13';
                        }
                        else {
                          print_time_stamp(time_stamp,0x30);
                          printf("%s ",time_stamp);
                          printf("%s : Can\'t get sensor type. temp_sensor_type: %s\n",
                                 "get_sensor_type",qr_code->temp_sensor_type);
                          snprintf(tmp1,0x100,"Can\'t get sensor type. temp_sensor_type: %s",
                                   qr_code->temp_sensor_type);
                          log_to_file(tmp1,time_stamp);
                          uVar2 = '\0';
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar2;
}

