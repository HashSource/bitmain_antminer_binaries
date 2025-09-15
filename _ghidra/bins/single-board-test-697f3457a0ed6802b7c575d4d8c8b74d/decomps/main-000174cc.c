
/* WARNING: Unknown calling convention */

int main(void)

{
  runtime_base_t *runtime_00;
  int iVar1;
  char tmp42 [1024];
  char command [64];
  runtime_base_t *runtime;
  int ret;
  
  memset(command,0,0x40);
  app_conf = app_config_init("/mnt/card/Config.ini");
  runtime_00 = (runtime_base_t *)calloc(0xb94,1);
  env_init(runtime_00);
  if (app_conf != (app_config_t *)0x0) {
    iVar1 = cgpu_init(runtime_00);
    if (-1 < iVar1) {
      display_arguments();
      fan_control('\x02');
      do {
        memset(command,0,0x40);
        iVar1 = strcmp(app_conf->pcba_repeat_ctrl,"keyboard");
        if (iVar1 == 0) {
          ret = __isoc99_fscanf(stdin,&DAT_000349dc,command);
        }
        else {
          iVar1 = strcmp(app_conf->pcba_repeat_ctrl,"button");
          if (iVar1 != 0) {
            if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
              builtin_strncpy(tmp42,"please assign ctrl type: keyboard or button\n",0x2c);
              tmp42[0x2c] = '\0';
              _applog(2,tmp42,false);
            }
            free(runtime_00);
            app_config_exit(app_conf);
            cgpu_exit();
            return 0;
          }
          ret = v9_key_read(command,0x40);
        }
        if ((0 < ret) && (command[0] == '0')) {
          singleBoardTest_Z15_BM1746();
        }
        usleep(100000);
      } while( true );
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      builtin_strncpy(tmp42,"cgpu init failed",0x10);
      tmp42[0x10] = '\n';
      tmp42[0x11] = '\0';
      _applog(2,tmp42,false);
    }
  }
  return -1;
}

