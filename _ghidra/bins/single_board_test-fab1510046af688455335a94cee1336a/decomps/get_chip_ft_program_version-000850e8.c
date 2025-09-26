
_Bool get_chip_ft_program_version(hashboard_qr_code *qr_code,uint8_t *ft_version)

{
  int iVar1;
  _Bool _Var2;
  uint8_t *ft_version_local;
  hashboard_qr_code *qr_code_local;
  char time_stamp [48];
  char tmp1 [2048];
  char temp [3];
  
  temp[0] = '\0';
  temp[1] = '\0';
  temp[2] = '\0';
  if (qr_code->chip_ftversion[0] == 'F') {
    temp[0] = qr_code->chip_ftversion[1];
    iVar1 = atoi(temp);
    *ft_version = (uint8_t)iVar1;
    if (qr_code->chip_ftversion[2] == 'V') {
      temp[0] = qr_code->chip_ftversion[3];
      temp[1] = qr_code->chip_ftversion[4];
      iVar1 = atoi(temp);
      ft_version[1] = (uint8_t)iVar1;
      if (qr_code->chip_ftversion[5] == 'B') {
        temp[0] = qr_code->chip_ftversion[6];
        temp[1] = '\0';
        iVar1 = atoi(temp);
        ft_version[2] = (uint8_t)iVar1;
        if (qr_code->chip_ftversion[7] == 'C') {
          temp[0] = qr_code->chip_ftversion[8];
          iVar1 = atoi(temp);
          ft_version[3] = (uint8_t)iVar1;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: FT version: F%dV02%dB%dC%d\n","get_chip_ft_program_version",(uint)*ft_version,
                 (uint)ft_version[1],(uint)ft_version[2],(uint)ft_version[3]);
          snprintf(tmp1,0x800,"FT version: F%dV02%dB%dC%d",(uint)*ft_version,(uint)ft_version[1],
                   (uint)ft_version[2],(uint)ft_version[3]);
          log_to_file(tmp1,time_stamp);
          _Var2 = true;
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: 4th FT version is not C, but is %c\n","get_chip_ft_program_version",
                 (uint)(byte)qr_code->chip_ftversion[7]);
          snprintf(tmp1,0x800,"4th FT version is not C, but is %c",
                   (uint)(byte)qr_code->chip_ftversion[7]);
          log_to_file(tmp1,time_stamp);
          _Var2 = false;
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: 3rd FT version is not B, but is %c\n","get_chip_ft_program_version",
               (uint)(byte)qr_code->chip_ftversion[5]);
        snprintf(tmp1,0x800,"3rd FT version is not B, but is %c",
                 (uint)(byte)qr_code->chip_ftversion[5]);
        log_to_file(tmp1,time_stamp);
        _Var2 = false;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: 2nd FT version is not V, but is %c\n","get_chip_ft_program_version",
             (uint)(byte)qr_code->chip_ftversion[2]);
      snprintf(tmp1,0x800,"2nd FT version is not V, but is %c",
               (uint)(byte)qr_code->chip_ftversion[2]);
      log_to_file(tmp1,time_stamp);
      _Var2 = false;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: 1st FT version is not F, but is %c\n","get_chip_ft_program_version",
           (uint)(byte)qr_code->chip_ftversion[0]);
    snprintf(tmp1,0x800,"1st FT version is not F, but is %c",(uint)(byte)qr_code->chip_ftversion[0])
    ;
    log_to_file(tmp1,time_stamp);
    _Var2 = false;
  }
  return _Var2;
}

