
/* WARNING: Removing unreachable block (ram,0x0005bb08) */

int sweep_setup(int type,int chain,void *conf,int test_levels,int pt2_level)

{
  byte bVar1;
  _Bool _Var2;
  size_t sVar3;
  int iVar4;
  undefined1 re_write_sweep_cfg;
  eeprom_v1 *peVar5;
  int test_levels_local;
  void *conf_local;
  int chain_local;
  int type_local;
  char time_stamp [48];
  char tmp1 [256];
  char chip_ftversion [16];
  sweep_result_t sr;
  eeprom_v1 *eep_ctx;
  sweep_ctx sweep;
  config_ctx ctx;
  int len;
  _Bool force_reset_sweep_info;
  int bin;
  size_t len_1;
  int i_1;
  int i;
  
  set_sweep_cxt(&sweep,(uint)*(byte *)((int)conf + 0x104));
  memset(&ctx,0,0x184);
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
      sweep.range_freq[0] = sweep.range_freq[0] + (float)(longlong)*(int *)((int)conf + 0x538);
      sweep.range_freq[1] = sweep.range_freq[1] + (float)(longlong)*(int *)((int)conf + 0x538);
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
    peVar5 = eep_ctx;
    if (eep_ctx == (eeprom_v1 *)0x0) {
      peVar5 = (eeprom_v1 *)0x1;
    }
    re_write_sweep_cfg = SUB41(peVar5,0);
    if (eep_ctx != (eeprom_v1 *)0x0) {
      re_write_sweep_cfg = false;
    }
    get_conf(conf,&sweep,test_levels,pt2_level,chain,&ctx,(_Bool)re_write_sweep_cfg);
    set_special_nonce_rate(eep_ctx,&ctx);
    if (((sweep.reuse != 1) || (iVar4 = strncmp((char *)conf,"SWEEP",5), iVar4 != 0)) ||
       ((eep_ctx != (eeprom_v1 *)0x0 && (_Var2 = check_pt2_success(eep_ctx), _Var2)))) {
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
      memset(&sr,0,0x40c);
      eeprom_get_sweep_result(&sr,eep_ctx);
      for (i_1 = 0; i_1 < (int)sVar3; i_1 = i_1 + 1) {
        freq_matrix[i_1] = (float)sr.freqs[i_1];
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : custumer repair mode read freq matrix\n","sweep_setup");
      builtin_strncpy(tmp1,"custumer repair mode read freq matri",0x24);
      tmp1[0x24] = 'x';
      tmp1[0x25] = '\0';
      log_to_file(tmp1,time_stamp);
      state_matrix = (uint8_t *)malloc(sVar3);
      memset(state_matrix,1,sVar3);
      if (ctx.chain < 3) {
        sw_mode = type;
        if (type == 1) {
          ops.init = (code *)0x59789;
          ops.sweep = (code *)0x57dc5;
          ops.drop = (code *)0x59b81;
          ops.stop = (code *)0x58659;
          ops.flush = (code *)0x58699;
          ops.check_status = (code *)0x58681;
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

