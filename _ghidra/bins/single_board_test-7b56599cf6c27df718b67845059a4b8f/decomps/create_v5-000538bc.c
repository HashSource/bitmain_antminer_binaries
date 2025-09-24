
int create_v5(eeprom_data_format_t *v5)

{
  int iVar1;
  eeprom_data_format_t *v5_local;
  char time_stamp [48];
  char tmp1 [256];
  char board_name [9];
  char chip_tech [3];
  char hashboard_index [16];
  char hashboard_ctrl_code [16];
  char temp_sensor_type [16];
  char chip_ftversion [16];
  char chip_bin [16];
  char chip_marking [16];
  char chip_die [16];
  char factory_job [32];
  char board_sn [32];
  size_t len;
  
  len = 0;
  (*v5->enc_algorithm_set)(v5,'\x01');
  (*v5->enc_key_version_set)(v5,'\x01');
  if (g_pt1.board_sn[0] == '\0') {
    iVar1 = -1;
  }
  else {
    memset(board_sn,0,0x20);
    len = 0x20;
    snprintf(board_sn,0x20,"%s",0xa296a8);
    (*v5->board_sn_set)(v5,board_sn,&len);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : board_sn:%s\n","create_v5",0xa296a8);
    snprintf(tmp1,0x100,"board_sn:%s",0xa296a8);
    log_to_file(tmp1,time_stamp);
    len = 0x10;
    memset(chip_die,0,0x10);
    snprintf(chip_die,0x10,"%s",0xa2963c);
    (*v5->chip_die_set)(v5,chip_die,&len);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : chip_die:%s\n","create_v5",0xa2963c);
    snprintf(tmp1,0x100,"chip_die:%s",0xa2963c);
    log_to_file(tmp1,time_stamp);
    len = 0x10;
    memset(chip_marking,0,0x10);
    snprintf(chip_marking,0x10,"%s",0xa2964c);
    (*v5->chip_marking_set)(v5,chip_marking,&len);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : chip_marking:%s\n","create_v5",0xa2964c);
    snprintf(tmp1,0x100,"chip_marking:%s",0xa2964c);
    log_to_file(tmp1,time_stamp);
    len = 0x10;
    memset(chip_ftversion,0,0x10);
    snprintf(chip_ftversion,0x10,"%s",0xa2965c);
    (*v5->ft_version_set)(v5,chip_ftversion,&len);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : chip_ftversion:%s\n","create_v5",0xa2965c);
    snprintf(tmp1,0x100,"chip_ftversion:%s",0xa2965c);
    log_to_file(tmp1,time_stamp);
    len = 3;
    memset(chip_tech,0,3);
    snprintf(chip_tech,3,"%s",0xa2969c);
    (*v5->chip_tech_set)(v5,chip_tech,&len);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : chip_tech:%s\n","create_v5",0xa2969c);
    snprintf(tmp1,0x100,"chip_tech:%s",0xa2969c);
    log_to_file(tmp1,time_stamp);
    (*v5->chip_bin_set)(v5,(uint8_t)g_pt1.chip_bin);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : create_v5 set chip_bin %d\n","create_v5",g_pt1.chip_bin);
    snprintf(tmp1,0x100,"create_v5 set chip_bin %d",g_pt1.chip_bin);
    log_to_file(tmp1,time_stamp);
    (*v5->asic_sensor_type_set)(v5,'\0');
    (*v5->pic_sensor_type_set)(v5,'\0');
    (*v5->pcb_version_set)(v5,0x140);
    (*v5->bom_version_set)(v5,0x20);
    (*v5->pt1_result_set)(v5,'\x01');
    (*v5->pt1_count_set)(v5,'\x01');
    (*v5->pt2_result_set)(v5,'\x01');
    (*v5->pt2_count_set)(v5,'\x01');
    len = 9;
    memset(board_name,0,9);
    snprintf(board_name,9,"%s",0xa2969f);
    (*v5->board_name_set)(v5,board_name,&len);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : board_name:%s\n","create_v5",0xa2969f);
    snprintf(tmp1,0x100,"board_name:%s",0xa2969f);
    log_to_file(tmp1,time_stamp);
    len = 0x20;
    memset(factory_job,0,0x20);
    snprintf(factory_job,0x20,"%s",&g_pt1);
    (*v5->factory_job_set)(v5,factory_job,&len);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : factory_job:%s\n","create_v5",&g_pt1);
    snprintf(tmp1,0x100,"factory_job:%s",&g_pt1);
    log_to_file(tmp1,time_stamp);
    (*v5->voltage_set)(v5,0x50a);
    (*v5->frequency_set)(v5,0x1b3);
    (*v5->nonce_rate_set)(v5,0x26ff);
    (*v5->pcb_temp_in_set)(v5,'*');
    (*v5->pcb_temp_out_set)(v5,'7');
    (*v5->test_version_set)(v5,'\x01');
    (*v5->test_standard_set)(v5,'\x01');
    iVar1 = 0;
  }
  return iVar1;
}

