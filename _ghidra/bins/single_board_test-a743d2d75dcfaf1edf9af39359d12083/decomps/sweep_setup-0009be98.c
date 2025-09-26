
int sweep_setup(int type,int chain,void *conf,int test_levels,int confirm_level)

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
  char tmp42 [256];
  eeprom_data_format_t *eep_ctx;
  sweep_ctx sweep;
  config_ctx ctx;
  int len;
  _Bool force_reset_sweep_info;
  int i;
  
  set_sweep_cxt(&sweep,(uint)*(byte *)((int)conf + 0xf8));
  memset(&ctx,0,0x174);
  read_eeprom(chain,&eep_ctx);
  if (eep_ctx == (eeprom_data_format_t *)0x0) {
    builtin_strncpy(tmp42,"eeprom data read ERR!",0x16);
    puts(tmp42);
    iVar2 = 2;
  }
  else {
    _Var1 = check_pt2_success(eep_ctx);
    if (_Var1) {
      reset_freq_range_from_eeprom(eep_ctx,&sweep,*(int *)((int)conf + 0x40));
    }
    peVar3 = eep_ctx;
    if (eep_ctx == (eeprom_data_format_t *)0x0) {
      peVar3 = (eeprom_data_format_t *)0x1;
    }
    re_write_sweep_cfg = SUB41(peVar3,0);
    if (eep_ctx != (eeprom_data_format_t *)0x0) {
      re_write_sweep_cfg = false;
    }
    get_conf(conf,&sweep,test_levels,confirm_level,chain,&ctx,(_Bool)re_write_sweep_cfg);
    if (((sweep.reuse != 1) || (iVar2 = strncmp((char *)conf,"SWEEP",5), iVar2 != 0)) ||
       ((eep_ctx != (eeprom_data_format_t *)0x0 && (_Var1 = check_pt2_success(eep_ctx), _Var1)))) {
      __size = ctx.asics_in_domain * ctx.domains;
      snprintf(tmp42,0x100,"matrix len:%d",__size);
      puts(tmp42);
      freq_matrix = (float *)malloc(__size * 4);
      for (i = 0; i < (int)__size; i = i + 1) {
        freq_matrix[i] = sweep.range_freq[0];
      }
      if (eep_ctx != (eeprom_data_format_t *)0x0) {
        (*eep_ctx->destroy)(eep_ctx);
        eep_ctx = (eeprom_data_format_t *)0x0;
      }
      state_matrix = (uint8_t *)malloc(__size);
      memset(state_matrix,1,__size);
      if (ctx.chain < 3) {
        sw_mode = type;
        if (type == 1) {
          builtin_strncpy(tmp42,"ops init",8);
          tmp42._8_4_ = tmp42._8_4_ & 0xffffff00;
          ops.warmup = (code *)0x9acf9;
          ops.init = (code *)0x9b06d;
          ops.sweep = (code *)0x981bd;
          ops.stop = (code *)0x98f41;
          ops.flush = (code *)0x98f85;
          ops.check_status = (code *)0x98f6d;
          puts(tmp42);
          iVar2 = (*ops.init)(&ctx,&sweep);
        }
        else {
          puts("not support");
          iVar2 = 4;
        }
      }
      else {
        snprintf(tmp42,0x100,"conf chain id error:%d",ctx.chain);
        puts(tmp42);
        iVar2 = 3;
      }
    }
    else {
      builtin_strncpy(tmp42,"pt2 result is fail,can not start swe",0x24);
      tmp42[0x24] = 'e';
      tmp42[0x25] = 'p';
      tmp42[0x26] = '\0';
      puts(tmp42);
      if (eep_ctx != (eeprom_data_format_t *)0x0) {
        (*eep_ctx->destroy)(eep_ctx);
      }
      iVar2 = 1;
    }
  }
  return iVar2;
}

