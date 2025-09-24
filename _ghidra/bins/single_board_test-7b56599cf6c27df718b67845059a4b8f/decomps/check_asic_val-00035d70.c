
_Bool check_asic_val(asic_val_t *p_val,double max_val,_Bool logout)

{
  bool bVar1;
  int extraout_r1;
  _Bool _Var2;
  undefined4 uVar3;
  double max_val_local;
  _Bool logout_local;
  asic_val_t *p_val_local;
  char time_stamp_3 [48];
  char time_stamp [48];
  int i_1;
  _Bool read_err;
  int i;
  
  if (logout) {
    for (i = 0; (uint)i < (Local_Config_Information->Hash_Board).Asic_Num; i = i + 1) {
      __aeabi_uidivmod(i,(Local_Config_Information->Hash_Board).Asic_Num_Per_Voltage_Domain);
      if (extraout_r1 == 0) {
        putchar(10);
        check_asic_val::lexical_block_5::lexical_block_5_1::tmp1[0] = '\n';
        check_asic_val::lexical_block_5::lexical_block_5_1::tmp1[1] = '\0';
        log_to_filex(check_asic_val::lexical_block_5::lexical_block_5_1::tmp1,time_stamp);
      }
      printf("[%d]:%.2f ",i,*(undefined4 *)(p_val->asic_val + i),
             *(undefined4 *)((int)(p_val->asic_val + i) + 4));
      snprintf(check_asic_val::lexical_block_5::lexical_block_5_2::tmp1_1,0x100,"[%d]:%.2f ",i,
               *(undefined4 *)(p_val->asic_val + i),*(undefined4 *)((int)(p_val->asic_val + i) + 4))
      ;
      log_to_filex(check_asic_val::lexical_block_5::lexical_block_5_2::tmp1_1,time_stamp);
    }
    putchar(10);
    check_asic_val::lexical_block_6::tmp1_2[0] = '\n';
    check_asic_val::lexical_block_6::tmp1_2[1] = '\0';
    log_to_filex(check_asic_val::lexical_block_6::tmp1_2,time_stamp);
  }
  bVar1 = false;
  for (i_1 = 0; (uint)i_1 < (Local_Config_Information->Hash_Board).Asic_Num; i_1 = i_1 + 1) {
    if (p_val->asic_val_readover[i_1] == '\0') {
      print_time_stamp(time_stamp_3,0x30);
      printf("%s ",time_stamp_3);
      printf("%s : asic [%d]:NULL\n","check_asic_val",i_1);
      snprintf(time_stamp,0x100,"asic [%d]:NULL",i_1);
      log_to_file(time_stamp,time_stamp_3);
      bVar1 = true;
    }
    else if (p_val->asic_val[i_1] <= 250.0) {
      p_val->read_succ_size = p_val->read_succ_size + 1;
      if ((int)((uint)(p_val->max_asic_val < p_val->asic_val[i_1]) << 0x1f) < 0) {
        uVar3 = *(undefined4 *)((int)(p_val->asic_val + i_1) + 4);
        *(undefined4 *)&p_val->max_asic_val = *(undefined4 *)(p_val->asic_val + i_1);
        *(undefined4 *)((int)&p_val->max_asic_val + 4) = uVar3;
        p_val->idx = i_1;
      }
      if (p_val->asic_val[i_1] < p_val->min_asic_val) {
        uVar3 = *(undefined4 *)((int)(p_val->asic_val + i_1) + 4);
        *(undefined4 *)&p_val->min_asic_val = *(undefined4 *)(p_val->asic_val + i_1);
        *(undefined4 *)((int)&p_val->min_asic_val + 4) = uVar3;
      }
      p_val->avg_asic_val = p_val->avg_asic_val + p_val->asic_val[i_1];
    }
    else {
      print_time_stamp(time_stamp_3,0x30);
      printf("%s ",time_stamp_3);
      uVar3 = *(undefined4 *)(p_val->asic_val + i_1);
      printf("%s : asic [%d]:%.2f\n","check_asic_val",i_1,uVar3,uVar3,
             *(undefined4 *)((int)(p_val->asic_val + i_1) + 4));
      snprintf(time_stamp,0x100,"asic [%d]:%.2f",i_1,*(undefined4 *)(p_val->asic_val + i_1),
               *(undefined4 *)((int)(p_val->asic_val + i_1) + 4));
      log_to_file(time_stamp,time_stamp_3);
      bVar1 = true;
    }
  }
  p_val->avg_asic_val = p_val->avg_asic_val / (double)(longlong)p_val->read_succ_size;
  print_time_stamp(time_stamp_3,0x30);
  printf("%s ",time_stamp_3);
  max_val_local._0_4_ = SUB84(max_val,0);
  max_val_local._4_4_ = (undefined4)((ulonglong)max_val >> 0x20);
  printf("%s : Asic val max:%.2f,min:%.2f,avg:%.2f,set max:%.2f\n","check_asic_val",
         *(undefined4 *)&p_val->max_asic_val,*(undefined4 *)((int)&p_val->max_asic_val + 4),
         *(undefined4 *)&p_val->min_asic_val,*(undefined4 *)((int)&p_val->min_asic_val + 4),
         *(undefined4 *)&p_val->avg_asic_val,*(undefined4 *)((int)&p_val->avg_asic_val + 4),
         max_val_local._0_4_,max_val_local._4_4_);
  snprintf(time_stamp,0x100,"Asic val max:%.2f,min:%.2f,avg:%.2f,set max:%.2f",
           *(undefined4 *)&p_val->max_asic_val,*(undefined4 *)&p_val->max_asic_val,
           *(undefined4 *)((int)&p_val->max_asic_val + 4),*(undefined4 *)&p_val->min_asic_val,
           *(undefined4 *)((int)&p_val->min_asic_val + 4),*(undefined4 *)&p_val->avg_asic_val,
           *(undefined4 *)((int)&p_val->avg_asic_val + 4),max_val_local._0_4_,max_val_local._4_4_);
  log_to_file(time_stamp,time_stamp_3);
  if ((p_val->read_succ_size != (Local_Config_Information->Hash_Board).Asic_Num) || (bVar1)) {
    print_time_stamp(time_stamp_3,0x30);
    printf("%s ",time_stamp_3);
    printf("%s : read succ:%d,some aisc read err.\n","check_asic_val",p_val->read_succ_size);
    snprintf(time_stamp,0x100,"read succ:%d,some aisc read err.",p_val->read_succ_size);
    log_to_file(time_stamp,time_stamp_3);
    _Var2 = false;
  }
  else if (p_val->max_asic_val <= max_val) {
    _Var2 = true;
  }
  else {
    print_time_stamp(time_stamp_3,0x30);
    printf("%s ",time_stamp_3);
    printf("%s : max:%.2f,outof range:%.2f, asic_idx:%d\n","check_asic_val",
           *(undefined4 *)&p_val->max_asic_val,*(undefined4 *)((int)&p_val->max_asic_val + 4),
           max_val_local._0_4_,max_val_local._4_4_,p_val->idx);
    snprintf(time_stamp,0x100,"max:%.2f,outof range:%.2f, asic_idx:%d",
             *(undefined4 *)&p_val->max_asic_val,*(undefined4 *)&p_val->max_asic_val,
             *(undefined4 *)((int)&p_val->max_asic_val + 4),max_val_local._0_4_,max_val_local._4_4_,
             p_val->idx);
    log_to_file(time_stamp,time_stamp_3);
    _Var2 = false;
  }
  return _Var2;
}

