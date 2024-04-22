
void hash_rate_guard(_Bool enable,float env_temp,double real_rate,_Bool high_chip_temp_flag)

{
  _Bool _Var1;
  int iVar2;
  FILE *pFVar3;
  double in_d1;
  char *in_stack_ffffffb0;
  undefined4 in_stack_ffffffb4;
  double in_stack_ffffffb8;
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
    if ((int)((uint)(in_d1 < ideal_rate * DAT_000207b8) << 0x1f) < 0) {
      if (high_chip_temp_flag) {
        return;
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          in_stack_ffffffb8 = (double)env_temp;
          in_stack_ffffffb0 = "hash_rate_guard";
          fprintf(pFVar3,
                  "%s:%d:%s: hash rate guard triggered! env_temp: %0.1f, avg_rate: %0.1f < %0.1f in 30min\n"
                  ,"driver-btm-soc.c",0xd9d);
        }
        fclose(pFVar3);
      }
      if (24.0 < env_temp) {
        if ((30.0 < env_temp) || (env_temp == 24.0 || env_temp < 24.0 != NAN(env_temp))) {
          if ((DAT_000207e0 < env_temp) || (env_temp == 30.0 || env_temp < 30.0 != NAN(env_temp))) {
            if ((DAT_000207e4 < env_temp) ||
               (env_temp == DAT_000207e0 ||
                env_temp < DAT_000207e0 != (NAN(env_temp) || NAN(DAT_000207e0)))) {
              if ((env_temp != DAT_000207e4 &&
                   env_temp < DAT_000207e4 == (NAN(env_temp) || NAN(DAT_000207e4))) &&
                 (3 < log_level)) {
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
                        ((double)CONCAT44(in_stack_ffffffb4,in_stack_ffffffb0),in_stack_ffffffb8,
                         hash_rate_guard::volt_increased_flag,&hash_rate_guard::outer_reopen_flag);
            }
          }
          else {
            volt_increase_for_mode0
                      ((double)CONCAT44(in_stack_ffffffb4,in_stack_ffffffb0),in_stack_ffffffb8,
                       hash_rate_guard::volt_increased_flag,&hash_rate_guard::outer_reopen_flag);
          }
        }
        else {
          volt_increase_for_mode0
                    ((double)CONCAT44(in_stack_ffffffb4,in_stack_ffffffb0),in_stack_ffffffb8,
                     hash_rate_guard::volt_increased_flag,&hash_rate_guard::outer_reopen_flag);
          hash_rate_guard::outer_reopen_flag = false;
        }
      }
      else {
        volt_increase_for_mode0
                  ((double)CONCAT44(in_stack_ffffffb4,in_stack_ffffffb0),in_stack_ffffffb8,
                   hash_rate_guard::volt_increased_flag,&hash_rate_guard::outer_reopen_flag);
        hash_rate_guard::outer_reopen_flag = false;
      }
    }
    else {
      hash_rate_guard::outer_reopen_flag = true;
      if ((DAT_000207e8 < env_temp) || (env_temp == 29.0 || env_temp < 29.0 != NAN(env_temp))) {
        if ((DAT_000207ec < env_temp) ||
           (env_temp == DAT_000207e8 ||
            env_temp < DAT_000207e8 != (NAN(env_temp) || NAN(DAT_000207e8)))) {
          if (env_temp != DAT_000207ec &&
              env_temp < DAT_000207ec == (NAN(env_temp) || NAN(DAT_000207ec))) {
            volt_decrease_for_mode0
                      ((double)CONCAT44(in_stack_ffffffb4,in_stack_ffffffb0),in_stack_ffffffb8,
                       hash_rate_guard::volt_increased_flag);
          }
        }
        else {
          volt_decrease_for_mode0
                    ((double)CONCAT44(in_stack_ffffffb4,in_stack_ffffffb0),in_stack_ffffffb8,
                     hash_rate_guard::volt_increased_flag);
        }
      }
      else {
        volt_decrease_for_mode0
                  ((double)CONCAT44(in_stack_ffffffb4,in_stack_ffffffb0),in_stack_ffffffb8,
                   hash_rate_guard::volt_increased_flag);
      }
    }
    if (((int)((uint)(in_d1 < ideal_rate * DAT_000207b8) << 0x1f) < 0) &&
       (hash_rate_guard::outer_reopen_flag != false)) {
      hash_rate_guard::outer_reopen_flag = false;
      reopen_once();
    }
  }
  return;
}

