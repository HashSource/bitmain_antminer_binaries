
_Bool get_chip_ft_program_version_ex(hashboard_qr_code *qr_code,uint8_t *ft_version)

{
  bool bVar1;
  bool bVar2;
  size_t sVar3;
  int iVar4;
  uint8_t *ft_version_local;
  hashboard_qr_code *qr_code_local;
  char time_stamp [48];
  char tmp1 [2048];
  char temp [4] [10];
  int32_t number;
  _Bool end;
  uint32_t length;
  _Bool begin;
  _Bool find_numbers;
  uint32_t i;
  uint32_t index2;
  uint32_t index1;
  
  memset(temp,0,0x28);
  index1 = 0;
  index2 = 0;
  bVar2 = false;
  bVar1 = false;
  memset(temp,0,0x28);
  sVar3 = strlen(qr_code->chip_ftversion);
  i = 0;
  do {
    if (sVar3 + 1 <= i) {
      return true;
    }
    if (((byte)qr_code->chip_ftversion[i] < 0x30) || (0x39 < (byte)qr_code->chip_ftversion[i])) {
      if (bVar1) {
        bVar2 = true;
        bVar1 = false;
      }
    }
    else {
      bVar1 = true;
      temp[index1][index2] = qr_code->chip_ftversion[i];
      index2 = index2 + 1;
    }
    if (bVar2) {
      if (3 < index1) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: There are too many number sector in ft version: %s, error.\n",
               "get_chip_ft_program_version_ex",qr_code->chip_ftversion);
        snprintf(tmp1,0x800,"There are too many number sector in ft version: %s, error.",
                 qr_code->chip_ftversion);
        log_to_file(tmp1,time_stamp);
        return false;
      }
      iVar4 = atoi(temp[index1]);
      if ((iVar4 < 0) || (0xff < iVar4)) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: FT version: %dst number: %d, error\n","get_chip_ft_program_version_ex",index1,
               iVar4);
        snprintf(tmp1,0x800,"FT version: %dst number: %d, error",index1,iVar4);
        log_to_file(tmp1,time_stamp);
        return false;
      }
      ft_version[index1] = (uint8_t)iVar4;
      index1 = index1 + 1;
      index2 = 0;
      bVar2 = false;
    }
    i = i + 1;
  } while( true );
}

