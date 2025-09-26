
void multiple_ft_bin_info_decompress
               (char *compressed,char *chip1,char *chip2,char *chip_bin,char *bin_list,int *num)

{
  char combined;
  char combined_00;
  char *chip_bin_local;
  char *chip2_local;
  char *chip1_local;
  char *compressed_local;
  char time_stamp [48];
  char tmp1 [2048];
  char x2;
  char x1;
  
  if ((((compressed == (char *)0x0) || (chip1 == (char *)0x0)) || (chip2 == (char *)0x0)) ||
     ((num == (int *)0x0 || (compressed[5] != 'M')))) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: decompress mbb err,check the e2promdata\n","multiple_ft_bin_info_decompress");
    builtin_strncpy(tmp1,"decompress mbb err,check the e2promdata",0x28);
    log_to_file(tmp1,time_stamp);
  }
  else {
    strncpy(chip1,compressed,5);
    strncpy(chip2,compressed,5);
    combined = compressed[6];
    combined_00 = compressed[7];
    *num = (byte)compressed[8] - 0x30;
    split_x_y(combined,chip1 + 6,chip1 + 8);
    chip1[5] = 'B';
    chip1[7] = 'C';
    split_x_y(combined_00,chip2 + 6,chip2 + 8);
    chip2[5] = 'B';
    chip2[7] = 'C';
    *bin_list = chip_bin[3];
    bin_list[1] = chip_bin[4];
  }
  return;
}

