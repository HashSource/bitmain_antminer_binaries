
uint8_t get_chip_bin(hashboard_qr_code *qr_code)

{
  uint8_t uVar1;
  hashboard_qr_code *qr_code_local;
  char time_stamp [48];
  char tmp1 [256];
  
  if (qr_code->chip_bin[3] == '1') {
    uVar1 = '\x01';
  }
  else if (qr_code->chip_bin[3] == '2') {
    uVar1 = '\x02';
  }
  else if (qr_code->chip_bin[3] == '3') {
    uVar1 = '\x03';
  }
  else if (qr_code->chip_bin[3] == '4') {
    uVar1 = '\x04';
  }
  else if (qr_code->chip_bin[3] == '5') {
    uVar1 = '\x05';
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Can\'t get chip bin number. chip_bin: %s\n","get_chip_bin",qr_code->chip_bin);
    snprintf(tmp1,0x100,"Can\'t get chip bin number. chip_bin: %s",qr_code->chip_bin);
    log_to_file(tmp1,time_stamp);
    uVar1 = 0xff;
  }
  return uVar1;
}

