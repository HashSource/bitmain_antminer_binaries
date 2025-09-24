
int sweep_setup(int type,int chain,void *conf,int test_levels,int pt2_level)

{
  _Bool _Var1;
  int iVar2;
  undefined1 re_write_sweep_cfg;
  eeprom_data_format_t *peVar3;
  size_t __size;
  int test_levels_local;
  void *conf_local;
  int chain_local;
  int type_local;
  char time_stamp [48];
  char tmp1 [256];
  sweep_result_t sr;
  eeprom_data_format_t *eep_ctx;
  sweep_ctx sweep;
  config_ctx ctx;
  int len;
  _Bool force_reset_sweep_info;
  int i_1;
  int i;
  
  set_sweep_cxt(&sweep,(uint)*(byte *)((int)conf + 0xfc));
  memset(&ctx,0,0x174);
  read_eeprom(chain,&eep_ctx);
  if (eep_ctx == (eeprom_data_format_t *)0x0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : eeprom data read ERR!\n","sweep_setup");
    builtin_strncpy(tmp1,"eeprom data read ERR!",0x16);
    log_to_file(tmp1,time_stamp);
    set_sweep_err_state(2,false);
    iVar2 = 2;
  }
  else {
    _Var1 = check_pt2_success(eep_ctx);
    if (_Var1) {
      reset_freq_range_from_eeprom(eep_ctx,&sweep,*(int *)((int)conf + 0x40));
      sweep.range_freq[0] = sweep.range_freq[0] + (float)(longlong)*(int *)((int)conf + 0x490);
      sweep.range_freq[1] = sweep.range_freq[1] + (float)(longlong)*(int *)((int)conf + 0x490);
    }
    peVar3 = eep_ctx;
    if (eep_ctx == (eeprom_data_format_t *)0x0) {
      peVar3 = (eeprom_data_format_t *)0x1;
    }
    re_write_sweep_cfg = SUB41(peVar3,0);
    if (eep_ctx != (eeprom_data_format_t *)0x0) {
      re_write_sweep_cfg = false;
    }
    get_conf(conf,&sweep,test_levels,pt2_level,chain,&ctx,(_Bool)re_write_sweep_cfg);
    if (((sweep.reuse != 1) || (iVar2 = strncmp((char *)conf,"SWEEP",5), iVar2 != 0)) ||
       ((eep_ctx != (eeprom_data_format_t *)0x0 && (_Var1 = check_pt2_success(eep_ctx), _Var1)))) {
      __size = ctx.asics_in_domain * ctx.domains;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : matrix len:%d\n","sweep_setup",__size);
      snprintf(tmp1,0x100,"matrix len:%d",__size);
      log_to_file(tmp1,time_stamp);
      freq_matrix = (float *)malloc(__size * 4);
      for (i = 0; i < (int)__size; i = i + 1) {
        freq_matrix[i] = sweep.range_freq[0];
      }
      memset(&sr,0,0x40c);
      eeprom_get_sweep_result(&sr,eep_ctx);
      for (i_1 = 0; i_1 < (int)__size; i_1 = i_1 + 1) {
        freq_matrix[i_1] = (float)sr.freqs[i_1];
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : custumer repair mode read freq matrix\n","sweep_setup");
      builtin_strncpy(tmp1,"custumer repair mode read freq matri",0x24);
      tmp1[0x24] = 'x';
      tmp1[0x25] = '\0';
      log_to_file(tmp1,time_stamp);
      if (eep_ctx != (eeprom_data_format_t *)0x0) {
        (*eep_ctx->destroy)(eep_ctx);
        eep_ctx = (eeprom_data_format_t *)0x0;
      }
      state_matrix = (uint8_t *)malloc(__size);
      memset(state_matrix,1,__size);
      if (ctx.chain < 3) {
        sw_mode = type;
        if (type == 1) {
          ops.init = (code *)0x5f541;
          ops.sweep = (code *)0x5da7d;
          ops.drop = (code *)0x5f949;
          ops.stop = (code *)0x5e301;
          ops.flush = (code *)0x5e345;
          ops.check_status = (code *)0x5e32d;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : ops init\n","sweep_setup");
          builtin_strncpy(tmp1,"ops init",8);
          tmp1._8_4_ = tmp1._8_4_ & 0xffffff00;
          log_to_file(tmp1,time_stamp);
          iVar2 = (*ops.init)(&ctx,&sweep);
        }
        else {
          puts("not support");
          iVar2 = -1;
        }
      }
      else {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : conf chain id error:%d\n","sweep_setup",ctx.chain);
        snprintf(tmp1,0x100,"conf chain id error:%d",ctx.chain);
        log_to_file(tmp1,time_stamp);
        set_sweep_err_state(3,false);
        iVar2 = 3;
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
      if (eep_ctx != (eeprom_data_format_t *)0x0) {
        (*eep_ctx->destroy)(eep_ctx);
        eep_ctx = (eeprom_data_format_t *)0x0;
      }
      set_sweep_err_state(1,false);
      iVar2 = 1;
    }
  }
  return iVar2;
}

