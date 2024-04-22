
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
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
              tmp42[0] = s_please_assign_ctrl_type__keyboar_000349e8[0];
              tmp42[1] = s_please_assign_ctrl_type__keyboar_000349e8[1];
              tmp42[2] = s_please_assign_ctrl_type__keyboar_000349e8[2];
              tmp42[3] = s_please_assign_ctrl_type__keyboar_000349e8[3];
              tmp42[4] = s_please_assign_ctrl_type__keyboar_000349e8[4];
              tmp42[5] = s_please_assign_ctrl_type__keyboar_000349e8[5];
              tmp42[6] = s_please_assign_ctrl_type__keyboar_000349e8[6];
              tmp42[7] = s_please_assign_ctrl_type__keyboar_000349e8[7];
              tmp42[8] = s_please_assign_ctrl_type__keyboar_000349e8[8];
              tmp42[9] = s_please_assign_ctrl_type__keyboar_000349e8[9];
              tmp42[10] = s_please_assign_ctrl_type__keyboar_000349e8[10];
              tmp42[11] = s_please_assign_ctrl_type__keyboar_000349e8[11];
              tmp42[12] = s_please_assign_ctrl_type__keyboar_000349e8[12];
              tmp42[13] = s_please_assign_ctrl_type__keyboar_000349e8[13];
              tmp42[14] = s_please_assign_ctrl_type__keyboar_000349e8[14];
              tmp42[15] = s_please_assign_ctrl_type__keyboar_000349e8[15];
              tmp42[16] = s_please_assign_ctrl_type__keyboar_000349e8[16];
              tmp42[17] = s_please_assign_ctrl_type__keyboar_000349e8[17];
              tmp42[18] = s_please_assign_ctrl_type__keyboar_000349e8[18];
              tmp42[19] = s_please_assign_ctrl_type__keyboar_000349e8[19];
              tmp42[20] = s_please_assign_ctrl_type__keyboar_000349e8[20];
              tmp42[21] = s_please_assign_ctrl_type__keyboar_000349e8[21];
              tmp42[22] = s_please_assign_ctrl_type__keyboar_000349e8[22];
              tmp42[23] = s_please_assign_ctrl_type__keyboar_000349e8[23];
              tmp42[24] = s_please_assign_ctrl_type__keyboar_000349e8[24];
              tmp42[25] = s_please_assign_ctrl_type__keyboar_000349e8[25];
              tmp42[26] = s_please_assign_ctrl_type__keyboar_000349e8[26];
              tmp42[27] = s_please_assign_ctrl_type__keyboar_000349e8[27];
              tmp42[28] = s_please_assign_ctrl_type__keyboar_000349e8[28];
              tmp42[29] = s_please_assign_ctrl_type__keyboar_000349e8[29];
              tmp42[30] = s_please_assign_ctrl_type__keyboar_000349e8[30];
              tmp42[31] = s_please_assign_ctrl_type__keyboar_000349e8[31];
              tmp42[32] = s_please_assign_ctrl_type__keyboar_000349e8[32];
              tmp42[33] = s_please_assign_ctrl_type__keyboar_000349e8[33];
              tmp42[34] = s_please_assign_ctrl_type__keyboar_000349e8[34];
              tmp42[35] = s_please_assign_ctrl_type__keyboar_000349e8[35];
              tmp42[36] = s_please_assign_ctrl_type__keyboar_000349e8[36];
              tmp42[37] = s_please_assign_ctrl_type__keyboar_000349e8[37];
              tmp42[38] = s_please_assign_ctrl_type__keyboar_000349e8[38];
              tmp42[39] = s_please_assign_ctrl_type__keyboar_000349e8[39];
              tmp42[40] = s_please_assign_ctrl_type__keyboar_000349e8[40];
              tmp42[41] = s_please_assign_ctrl_type__keyboar_000349e8[41];
              tmp42[42] = s_please_assign_ctrl_type__keyboar_000349e8[42];
              tmp42[43] = s_please_assign_ctrl_type__keyboar_000349e8[43];
              tmp42[44] = (char)ram0x00034a14;
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
      tmp42[0] = s_cgpu_init_failed_000349bc[0];
      tmp42[1] = s_cgpu_init_failed_000349bc[1];
      tmp42[2] = s_cgpu_init_failed_000349bc[2];
      tmp42[3] = s_cgpu_init_failed_000349bc[3];
      tmp42[4] = s_cgpu_init_failed_000349bc[4];
      tmp42[5] = s_cgpu_init_failed_000349bc[5];
      tmp42[6] = s_cgpu_init_failed_000349bc[6];
      tmp42[7] = s_cgpu_init_failed_000349bc[7];
      tmp42[8] = s_cgpu_init_failed_000349bc[8];
      tmp42[9] = s_cgpu_init_failed_000349bc[9];
      tmp42[10] = s_cgpu_init_failed_000349bc[10];
      tmp42[11] = s_cgpu_init_failed_000349bc[11];
      tmp42[12] = s_cgpu_init_failed_000349bc[12];
      tmp42[13] = s_cgpu_init_failed_000349bc[13];
      tmp42[14] = s_cgpu_init_failed_000349bc[14];
      tmp42[15] = s_cgpu_init_failed_000349bc[15];
      tmp42[16] = (char)(short)ram0x000349cc;
      tmp42[17] = (char)((ushort)(short)ram0x000349cc >> 8);
      _applog(2,tmp42,false);
    }
  }
  return -1;
}

