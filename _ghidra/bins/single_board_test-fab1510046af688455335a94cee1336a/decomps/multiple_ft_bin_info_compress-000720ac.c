
void multiple_ft_bin_info_compress(char *chip1,char *chip2,int *num,char *result,char *chip_bin)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  size_t sVar4;
  char *result_local;
  int *num_local;
  char *chip2_local;
  char *chip1_local;
  char time_stamp [48];
  char tmp1 [2048];
  char temp [6];
  char x3;
  char x2;
  char x1;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: col %d\n","multiple_ft_bin_info_compress",*num);
  snprintf(tmp1,0x800,"col %d",*num);
  log_to_file(tmp1,time_stamp);
  if ((((chip1 == (char *)0x0) || (chip2 == (char *)0x0)) || (*num < 1)) || (7 < *num)) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: mbb info  err\n","multiple_ft_bin_info_compress");
    builtin_strncpy(tmp1,"mbb info  er",0xc);
    tmp1[0xc] = 'r';
    tmp1[0xd] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: mbb col num is %d\n","multiple_ft_bin_info_compress",*num);
    snprintf(tmp1,0x800,"mbb col num is %d",*num);
    log_to_file(tmp1,time_stamp);
    temp[0] = '\0';
    temp[1] = '\0';
    temp[2] = '\0';
    temp[3] = '\0';
    temp[4] = '\0';
    temp[5] = '\0';
    strncpy(temp,chip1,5);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: mbb info temp %s\n","multiple_ft_bin_info_compress",temp);
    snprintf(tmp1,0x800,"mbb info temp %s",temp);
    log_to_file(tmp1,time_stamp);
    sVar4 = strlen(chip1);
    if (((((sVar4 == 0xb) && (sVar4 = strlen(chip2), sVar4 == 0xb)) &&
         ((chip1[5] == 'B' && ((chip2[5] == 'B' && (chip1[7] == 'C')))))) && (chip2[7] == 'C')) &&
       (((((0x30 < (byte)chip1[6] && ((byte)chip1[6] < 0x36)) && (0x30 < (byte)chip2[6])) &&
         (((byte)chip2[6] < 0x36 && (0x30 < (byte)chip1[8])))) &&
        (((byte)chip1[8] < 0x33 && ((0x30 < (byte)chip2[8] && ((byte)chip2[8] < 0x33)))))))) {
      bVar2 = combine_x_y(chip1[6],chip1[8]);
      bVar3 = combine_x_y(chip2[6],chip2[8]);
      bVar1 = (char)*num + 0x30;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: mbb info x1 %c,x2 %c, x3 %c\n","multiple_ft_bin_info_compress",(uint)bVar2,
             (uint)bVar3,(uint)bVar1);
      snprintf(tmp1,0x800,"mbb info x1 %c,x2 %c, x3 %c",(uint)bVar2,(uint)bVar3,(uint)bVar1);
      log_to_file(tmp1,time_stamp);
      snprintf(result,10,"%sM%c%c%c",temp,(uint)bVar2,(uint)bVar3,(uint)bVar1);
      *chip_bin = 'B';
      chip_bin[1] = 'I';
      chip_bin[2] = 'N';
      chip_bin[3] = chip1[10];
      chip_bin[4] = chip2[10];
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: mbb info input err\n","multiple_ft_bin_info_compress");
      builtin_strncpy(tmp1,"mbb info input e",0x10);
      tmp1[0x10] = 'r';
      tmp1[0x11] = 'r';
      tmp1[0x12] = '\0';
      log_to_file(tmp1,time_stamp);
    }
  }
  return;
}

