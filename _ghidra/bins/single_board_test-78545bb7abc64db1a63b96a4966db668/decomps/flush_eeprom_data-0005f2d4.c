
int flush_eeprom_data(float *matrix,int chain)

{
  undefined4 uVar1;
  _Bool _Var2;
  int iVar3;
  int chain_local;
  float *matrix_local;
  char time_stamp [48];
  char tmp1 [256];
  eeprom_v1 *ctx;
  eeprom_v1 eeprom_tmp;
  _Bool temp;
  
  _Var2 = build_eeprom_data_pt2(true,&g_rt,matrix);
  if (_Var2) {
    ctx = (eeprom_v1 *)0x0;
    read_eeprom((g_rt.config)->chain,&ctx);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : write pt2 and sweep result\n","flush_eeprom_data");
    builtin_strncpy(tmp1,"write pt2 and sweep resu",0x18);
    tmp1[0x18] = 'l';
    tmp1[0x19] = 't';
    tmp1[0x1a] = '\0';
    log_to_file(tmp1,time_stamp);
    memcpy(&eeprom_tmp.data,&ctx->data,0x100);
    iVar3 = (*ctx->pt2_store)(ctx);
    if ((iVar3 == 0) && (iVar3 = (*ctx->sweep_store)(ctx), iVar3 == 0)) {
      iVar3 = (*ctx->pt2_retrieve)(ctx);
      if ((iVar3 == 0) && (iVar3 = (*ctx->sweep_retrieve)(ctx), iVar3 == 0)) {
        iVar3 = memcmp((void *)((int)&(ctx->data).field_2 + 0x60),
                       (void *)((int)&eeprom_tmp.data.field_2 + 0x60),0x8f);
        if ((iVar3 == 0) &&
           (iVar3 = memcmp((void *)((int)&(ctx->data).field_2 + 0x50),
                           (void *)((int)&eeprom_tmp.data.field_2 + 0x50),0xf), iVar3 == 0)) {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Write EEPROM ok\n","flush_eeprom_data");
          builtin_strncpy(tmp1,"Write EEPROM ok",0x10);
          log_to_file(tmp1,time_stamp);
          iVar3 = 0;
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Check EEPROM data fail\n","flush_eeprom_data");
          uVar1 = tmp1._20_4_;
          builtin_strncpy(tmp1,"Check EEPROM data fail",0x17);
          tmp1[0x17] = SUB41(uVar1,3);
          log_to_file(tmp1,time_stamp);
          iVar3 = -1;
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : Read EEPROM fail\n","flush_eeprom_data");
        builtin_strncpy(tmp1,"Read EEPROM fail",0x10);
        tmp1._16_4_ = tmp1._16_4_ & 0xffffff00;
        log_to_file(tmp1,time_stamp);
        iVar3 = -1;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Write EEPROM fail\n","flush_eeprom_data");
      builtin_strncpy(tmp1,"Write EEPROM fai",0x10);
      tmp1[0x10] = 'l';
      tmp1[0x11] = '\0';
      log_to_file(tmp1,time_stamp);
      iVar3 = -1;
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : build eeprom data failed\n","flush_eeprom_data");
    builtin_strncpy(tmp1,"build eeprom data failed",0x18);
    tmp1._24_2_ = (ushort)(byte)tmp1[0x19] << 8;
    log_to_file(tmp1,time_stamp);
    iVar3 = -1;
  }
  return iVar3;
}

