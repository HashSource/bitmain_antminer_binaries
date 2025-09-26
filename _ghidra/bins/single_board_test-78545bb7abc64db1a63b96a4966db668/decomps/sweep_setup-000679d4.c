
/* WARNING: Removing unreachable block (ram,0x00067b08) */

int sweep_setup(int type,int chain,void *conf,int test_levels,int pt2_level)

{
  byte bVar1;
  _Bool _Var2;
  size_t sVar3;
  int iVar4;
  char *pcVar5;
  undefined1 re_write_sweep_cfg;
  eeprom_v1 *peVar6;
  int test_levels_local;
  void *conf_local;
  int chain_local;
  int type_local;
  char time_stamp [48];
  char tmp1 [256];
  char chip_ftversion [16];
  eeprom_v1 *eep_ctx;
  sweep_ctx sweep;
  config_ctx ctx;
  int len;
  _Bool force_reset_sweep_info;
  int bin;
  size_t len_1;
  int i;
  
  set_sweep_cxt(&sweep,(uint)*(byte *)((int)conf + 0x1c4));
  memset(&ctx,0,0x1cc);
  eep_ctx = (eeprom_v1 *)0x0;
  read_eeprom(chain,&eep_ctx);
  if (eep_ctx == (eeprom_v1 *)0x0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : eeprom data read ERR!\n","sweep_setup");
    builtin_strncpy(tmp1,"eeprom data read ERR!",0x16);
    log_to_file(tmp1,time_stamp);
    set_sweep_err_state(2,false);
    iVar4 = 2;
  }
  else {
    _Var2 = check_pt2_success(eep_ctx);
    if (_Var2) {
      reset_freq_range_from_eeprom(eep_ctx,&sweep,*(int *)((int)conf + 0x40));
      sweep.range_freq[0] = sweep.range_freq[0] + (float)(longlong)*(int *)((int)conf + 0x5fc);
      sweep.range_freq[1] = sweep.range_freq[1] + (float)(longlong)*(int *)((int)conf + 0x5fc);
      memset(chip_ftversion,0,0x10);
      bVar1 = (eep_ctx->data).field_2.raw[0x48];
      strncpy(chip_ftversion,(char *)((eep_ctx->data).field_2.raw + 0x3b),10);
      memcpy(ctx.ft,chip_ftversion,0x10);
      sVar3 = strlen(ctx.ft);
      sprintf(ctx.ft + sVar3,"-%d",(uint)bVar1);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : ftinfo:%s\n","sweep_setup",ctx.ft);
      snprintf(tmp1,0x100,"ftinfo:%s",ctx.ft);
      log_to_file(tmp1,time_stamp);
    }
    peVar6 = eep_ctx;
    if (eep_ctx == (eeprom_v1 *)0x0) {
      peVar6 = (eeprom_v1 *)0x1;
    }
    re_write_sweep_cfg = SUB41(peVar6,0);
    if (eep_ctx != (eeprom_v1 *)0x0) {
      re_write_sweep_cfg = false;
    }
    get_conf(conf,&sweep,test_levels,pt2_level,chain,&ctx,(_Bool)re_write_sweep_cfg);
    sVar3 = strlen((char *)((int)conf + 0x20));
    memcpy(ctx.board.board_name,(void *)((int)conf + 0x20),sVar3);
    if (((sweep.reuse != 1) || (iVar4 = strncmp((char *)conf,"SWEEP",5), iVar4 != 0)) ||
       ((eep_ctx != (eeprom_v1 *)0x0 && (_Var2 = check_pt2_success(eep_ctx), _Var2)))) {
      pcVar5 = strstr(ctx.board.board_name,"A3HB70503");
      if ((pcVar5 != (char *)0x0) &&
         ((((_Var2 = is_ft("E1V07B5C1-3"), _Var2 || (_Var2 = is_ft("E1V07B4C2-1"), _Var2)) ||
           (_Var2 = is_ft("E1V07B3C2-1"), _Var2)) || (_Var2 = is_ft("E1V07B3C1-4"), _Var2)))) {
        ctx.standard.nonce_rate = 0x25f8;
      }
      sVar3 = ctx.asics_in_domain * ctx.domains;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : matrix len:%d\n","sweep_setup",sVar3);
      snprintf(tmp1,0x100,"matrix len:%d",sVar3);
      log_to_file(tmp1,time_stamp);
      freq_matrix = (float *)malloc(sVar3 * 4);
      for (i = 0; i < (int)sVar3; i = i + 1) {
        freq_matrix[i] = sweep.range_freq[0];
      }
      state_matrix = (uint8_t *)malloc(sVar3);
      memset(state_matrix,1,sVar3);
      if (ctx.chain < 3) {
        sw_mode = type;
        if (type == 1) {
          ops.init = (code *)0x65a89;
          ops.sweep = (code *)0x62bc1;
          ops.drop = (code *)0x65ed5;
          ops.stop = (code *)0x64559;
          ops.flush = (code *)0x6459d;
          ops.check_status = (code *)0x64585;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : ops init\n","sweep_setup");
          builtin_strncpy(tmp1,"ops init",8);
          tmp1._8_4_ = tmp1._8_4_ & 0xffffff00;
          log_to_file(tmp1,time_stamp);
          iVar4 = (*ops.init)(&ctx,&sweep);
        }
        else {
          puts("not support");
          iVar4 = -1;
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : conf chain id error:%d\n","sweep_setup",ctx.chain);
        snprintf(tmp1,0x100,"conf chain id error:%d",ctx.chain);
        log_to_file(tmp1,time_stamp);
        set_sweep_err_state(3,false);
        iVar4 = 3;
      }
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : pt2 result is fail,can not start sweep\n","sweep_setup");
      builtin_strncpy(tmp1,"pt2 result is fail,can not start swe",0x24);
      tmp1[0x24] = 'e';
      tmp1[0x25] = 'p';
      tmp1[0x26] = '\0';
      log_to_file(tmp1,time_stamp);
      set_sweep_err_state(1,false);
      iVar4 = 1;
    }
  }
  return iVar4;
}

