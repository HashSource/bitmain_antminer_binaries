
void hash_rate_guard(_Bool enable,float env_temp,double real_rate,_Bool high_chip_temp_flag)

{
  _Bool _Var1;
  int iVar2;
  FILE *pFVar3;
  double real_rate_local;
  float env_temp_local;
  _Bool high_chip_temp_flag_local;
  _Bool enable_local;
  FILE *pFile_1;
  FILE *pFile;
  double ideal_rate;
  
  if (enable) {
    _Var1 = is_fixed_mode();
    if (_Var1) {
      iVar2 = get_ideal_hash_rate_max();
    }
    else {
      iVar2 = get_eeprom_total_hash_rate();
    }
    ideal_rate = (double)(longlong)iVar2;
    if ((int)((uint)(real_rate < ideal_rate * 0.9800000190734863) << 0x1f) < 0) {
      if (high_chip_temp_flag) {
        return;
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,
                  "%s:%d:%s: hash rate guard triggered! env_temp: %0.1f, avg_rate: %0.1f < %0.1f in 30min\n"
                  ,"driver-btm-soc.c",0xd9d,"hash_rate_guard");
        }
        fclose(pFVar3);
      }
      if (24.0 < env_temp) {
        if ((30.0 < env_temp) || (env_temp <= 24.0)) {
          if ((36.0 < env_temp) || (env_temp <= 30.0)) {
            if ((40.0 < env_temp) || (env_temp <= 36.0)) {
              if ((40.0 < env_temp) && (3 < log_level)) {
                print_crt_time_to_file(log_file,3);
                pFVar3 = fopen(log_file,"a+");
                if (pFVar3 != (FILE *)0x0) {
                  fprintf(pFVar3,"%s:%d:%s: env temp is above 30, will not increase voltage",
                          "driver-btm-soc.c",0xdb2,"hash_rate_guard");
                }
                fclose(pFVar3);
              }
            }
            else {
              volt_increase_for_mode0
                        (10.0,0.1,hash_rate_guard::volt_increased_flag,
                         &hash_rate_guard::outer_reopen_flag);
            }
          }
          else {
            volt_increase_for_mode0
                      (10.1,0.1,hash_rate_guard::volt_increased_flag,
                       &hash_rate_guard::outer_reopen_flag);
          }
        }
        else {
          volt_increase_for_mode0
                    (10.2,0.1,hash_rate_guard::volt_increased_flag,
                     &hash_rate_guard::outer_reopen_flag);
          hash_rate_guard::outer_reopen_flag = false;
        }
      }
      else {
        volt_increase_for_mode0
                  (10.3,0.1,hash_rate_guard::volt_increased_flag,&hash_rate_guard::outer_reopen_flag
                  );
        hash_rate_guard::outer_reopen_flag = false;
      }
    }
    else {
      hash_rate_guard::outer_reopen_flag = true;
      if ((35.0 < env_temp) || (env_temp <= 29.0)) {
        if ((41.0 < env_temp) || (env_temp <= 35.0)) {
          if (41.0 < env_temp) {
            volt_decrease_for_mode0
                      (g_sweep_config_hpf.sweep_start_voltage,0.1,
                       hash_rate_guard::volt_increased_flag);
          }
        }
        else {
          volt_decrease_for_mode0
                    (g_sweep_config_hpf.sweep_start_voltage,0.1,hash_rate_guard::volt_increased_flag
                    );
        }
      }
      else {
        volt_decrease_for_mode0
                  (g_sweep_config_hpf.sweep_start_voltage + 0.1,0.1,
                   hash_rate_guard::volt_increased_flag);
      }
    }
    if (((int)((uint)(real_rate < ideal_rate * 0.9800000190734863) << 0x1f) < 0) &&
       (hash_rate_guard::outer_reopen_flag != false)) {
      hash_rate_guard::outer_reopen_flag = false;
      reopen_once();
    }
  }
  return;
}

