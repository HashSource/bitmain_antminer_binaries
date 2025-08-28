
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void init_sweep_config(void)

{
  _Bool _Var1;
  FILE *pFVar2;
  FILE *pFile_9;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_6;
  FILE *pFile_5;
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  double aging_volt_add;
  CHIP_LEVEL _g_bin_level;
  CHIP_MINOR_TYPE _g_minor_type;
  int chain;
  
  _g_minor_type = PKG_BSL;
  _g_bin_level = BIN1;
  chain = 0;
  do {
    if (0xf < chain) {
LAB_000265f6:
      _Var1 = is_T11();
      if (_Var1) {
        if ((_g_minor_type == PKG_BSL) || (_g_minor_type == PKG_B_BGM)) {
          if (_g_bin_level == BIN1) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = 0;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = 0x40228000;
            g_sweep_config_eco.max_aging_voltage = 9.65;
            g_sweep_config_eco.sweep_min_freq = 300;
            g_sweep_config_eco.sweep_max_freq = 0x15e;
            _Var1 = is_column_sweep();
            if (_Var1) {
              g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0x33333333;
              g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x40233333;
              g_sweep_config_hpf.max_aging_voltage = 10.0;
              g_sweep_config_hpf.sweep_min_freq = 0x14f;
              g_sweep_config_hpf.sweep_max_freq = 0x181;
            }
            else {
              if (_g_minor_type == PKG_B_BGM) {
                g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0x66666666;
                g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x40236666;
              }
              else {
                g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0xcccccccd;
                g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x4023cccc;
              }
              g_sweep_config_hpf.max_aging_voltage =
                   (double)CONCAT44(g_sweep_config_hpf.sweep_start_voltage._4_4_,
                                    g_sweep_config_hpf.sweep_start_voltage._0_4_) + 0.4;
              g_sweep_config_hpf.sweep_min_freq = 0x163;
              g_sweep_config_hpf.sweep_max_freq = 0x181;
            }
          }
          else if (_g_bin_level == BIN2) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = 0;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = 0x40228000;
            g_sweep_config_eco.max_aging_voltage = 9.65;
            g_sweep_config_eco.sweep_min_freq = 300;
            g_sweep_config_eco.sweep_max_freq = 0x15e;
            _Var1 = is_column_sweep();
            if (_Var1) {
              g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0x33333333;
              g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x40233333;
              g_sweep_config_hpf.max_aging_voltage = 10.0;
              g_sweep_config_hpf.sweep_min_freq = 0x14f;
              g_sweep_config_hpf.sweep_max_freq = 0x181;
            }
            else {
              g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0xcccccccd;
              g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x4023cccc;
              g_sweep_config_hpf.max_aging_voltage = 10.3;
              g_sweep_config_hpf.sweep_min_freq = 0x163;
              g_sweep_config_hpf.sweep_max_freq = 0x181;
            }
          }
          else if (_g_bin_level == BIN3) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = 0xae147ae1;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = 0x4022e147;
            g_sweep_config_eco.max_aging_voltage = 9.84;
            g_sweep_config_eco.sweep_min_freq = 0x10e;
            g_sweep_config_eco.sweep_max_freq = 0x136;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0xae147ae1;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x4023e147;
            g_sweep_config_hpf.max_aging_voltage = 10.34;
            g_sweep_config_hpf.sweep_min_freq = 300;
            g_sweep_config_hpf.sweep_max_freq = 0x15e;
          }
          else {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = 0xf5c28f5c;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = 0x40235c28;
            g_sweep_config_eco.max_aging_voltage = 10.08;
            g_sweep_config_eco.sweep_min_freq = 0x10e;
            g_sweep_config_eco.sweep_max_freq = 0x136;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0xc28f5c29;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x402428f5;
            g_sweep_config_hpf.max_aging_voltage = 10.48;
            g_sweep_config_hpf.sweep_min_freq = 300;
            g_sweep_config_hpf.sweep_max_freq = 0x15e;
          }
        }
        else if (_g_minor_type == PKG_BE) {
          if (_g_bin_level == BIN1) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = 0x66666666;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = 0x40226666;
            g_sweep_config_eco.max_aging_voltage = 9.6;
            g_sweep_config_eco.sweep_min_freq = 0x118;
            g_sweep_config_eco.sweep_max_freq = 0x14a;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0x33333333;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x40233333;
            g_sweep_config_hpf.max_aging_voltage = 10.0;
            g_sweep_config_hpf.sweep_min_freq = 300;
            g_sweep_config_hpf.sweep_max_freq = 0x168;
          }
          else if (_g_bin_level == BIN2) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = 0x66666666;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = 0x40226666;
            g_sweep_config_eco.max_aging_voltage = 9.6;
            g_sweep_config_eco.sweep_min_freq = 0x118;
            g_sweep_config_eco.sweep_max_freq = 0x14a;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0x33333333;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x40233333;
            g_sweep_config_hpf.max_aging_voltage = 10.0;
            g_sweep_config_hpf.sweep_min_freq = 300;
            g_sweep_config_hpf.sweep_max_freq = 0x168;
          }
          else if (_g_bin_level == BIN3) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = 0xae147ae1;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = 0x4022e147;
            g_sweep_config_eco.max_aging_voltage = 9.84;
            g_sweep_config_eco.sweep_min_freq = 0x10e;
            g_sweep_config_eco.sweep_max_freq = 0x136;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0xae147ae1;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x4023e147;
            g_sweep_config_hpf.max_aging_voltage = 10.34;
            g_sweep_config_hpf.sweep_min_freq = 300;
            g_sweep_config_hpf.sweep_max_freq = 0x15e;
          }
          else {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = 0xf5c28f5c;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = 0x40235c28;
            g_sweep_config_eco.max_aging_voltage = 10.08;
            g_sweep_config_eco.sweep_min_freq = 0x10e;
            g_sweep_config_eco.sweep_max_freq = 0x136;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0xc28f5c29;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x402428f5;
            g_sweep_config_hpf.max_aging_voltage = 10.48;
            g_sweep_config_hpf.sweep_min_freq = 300;
            g_sweep_config_hpf.sweep_max_freq = 0x15e;
          }
        }
        else if (_g_minor_type == PKG_CE) {
          if (_g_bin_level == BIN1) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = 0x33333333;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = 0x40213333;
            g_sweep_config_eco.max_aging_voltage = 9.0;
            g_sweep_config_eco.sweep_min_freq = 300;
            g_sweep_config_eco.sweep_max_freq = 0x17c;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0x66666666;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x40226666;
            g_sweep_config_hpf.max_aging_voltage = 9.6;
            g_sweep_config_hpf.sweep_min_freq = 0x19f;
            g_sweep_config_hpf.sweep_max_freq = 0x1d1;
          }
          else if (_g_bin_level == BIN2) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = 0x33333333;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = 0x40213333;
            g_sweep_config_eco.max_aging_voltage = 9.0;
            g_sweep_config_eco.sweep_min_freq = 300;
            g_sweep_config_eco.sweep_max_freq = 0x17c;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0x66666666;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x40226666;
            g_sweep_config_hpf.max_aging_voltage = 9.6;
            g_sweep_config_hpf.sweep_min_freq = 0x19f;
            g_sweep_config_hpf.sweep_max_freq = 0x1d1;
          }
          else if (_g_bin_level == BIN3) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = 0x33333333;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = 0x40223333;
            g_sweep_config_eco.max_aging_voltage = 9.5;
            g_sweep_config_eco.sweep_min_freq = 0x136;
            g_sweep_config_eco.sweep_max_freq = 0x168;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0xcccccccd;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x4022cccc;
            g_sweep_config_hpf.max_aging_voltage = 9.8;
            g_sweep_config_hpf.sweep_min_freq = 400;
            g_sweep_config_hpf.sweep_max_freq = 0x1c2;
          }
          else {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = 0x33333333;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = 0x40223333;
            g_sweep_config_eco.max_aging_voltage = 9.5;
            g_sweep_config_eco.sweep_min_freq = 0x136;
            g_sweep_config_eco.sweep_max_freq = 0x168;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0xcccccccd;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x4022cccc;
            g_sweep_config_hpf.max_aging_voltage = 9.8;
            g_sweep_config_hpf.sweep_min_freq = 400;
            g_sweep_config_hpf.sweep_max_freq = 0x1c2;
          }
        }
        else {
          g_sweep_config_eco.sweep_start_voltage._0_4_ = 0x3d70a3d7;
          g_sweep_config_eco.sweep_start_voltage._4_4_ = 0x4022d70a;
          g_sweep_config_eco.max_aging_voltage = 9.82;
          g_sweep_config_eco.sweep_min_freq = 0xfa;
          g_sweep_config_eco.sweep_max_freq = 300;
          g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0x9999999a;
          g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x40239999;
          g_sweep_config_hpf.max_aging_voltage = 10.200000000000001;
          g_sweep_config_hpf.sweep_min_freq = 300;
          g_sweep_config_hpf.sweep_max_freq = 0x168;
        }
      }
      else {
        _Var1 = is_T11a();
        if (_Var1) {
          g_sweep_config_eco.sweep_start_voltage._0_4_ = 0xcccccccd;
          g_sweep_config_eco.sweep_start_voltage._4_4_ = 0x40324ccc;
          g_sweep_config_eco.max_aging_voltage = 18.7;
          g_sweep_config_eco.sweep_min_freq = 0xfa;
          g_sweep_config_eco.sweep_max_freq = 0x113;
          g_sweep_config_hpf.sweep_start_voltage._0_4_ = 0xcccccccd;
          g_sweep_config_hpf.sweep_start_voltage._4_4_ = 0x40334ccc;
          g_sweep_config_hpf.max_aging_voltage = 19.5;
          g_sweep_config_hpf.sweep_min_freq = 0x127;
          g_sweep_config_hpf.sweep_max_freq = 0x140;
        }
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fwrite("\nsweep config for eco mode: \n",1,0x1d,pFVar2);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"sweep_start_voltage: %.2f\n",g_sweep_config_eco.sweep_start_voltage._0_4_,
                  g_sweep_config_eco.sweep_start_voltage._4_4_);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"max_aging_voltage:   %.2f\n",g_sweep_config_eco.max_aging_voltage._0_4_,
                  g_sweep_config_eco.max_aging_voltage._4_4_);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"sweep_min_freq:      %dM\n",g_sweep_config_eco.sweep_min_freq);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"sweep_max_freq:      %dM\n",g_sweep_config_eco.sweep_max_freq);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fwrite("\nsweep config for hpf mode: \n",1,0x1d,pFVar2);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"sweep_start_voltage: %.2f\n",g_sweep_config_hpf.sweep_start_voltage._0_4_,
                  g_sweep_config_hpf.sweep_start_voltage._4_4_);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"max_aging_voltage:   %.2f\n",g_sweep_config_hpf.max_aging_voltage._0_4_,
                  g_sweep_config_hpf.max_aging_voltage._4_4_);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"sweep_min_freq:      %dM\n",g_sweep_config_hpf.sweep_min_freq);
        }
        fclose(pFVar2);
      }
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"sweep_max_freq:      %dM\n",g_sweep_config_hpf.sweep_max_freq);
        }
        fclose(pFVar2);
      }
      return;
    }
    if (dev->chain_exist[chain] != 0) {
      _g_minor_type = g_minor_type[chain];
      _g_bin_level = g_bin_level[chain];
      goto LAB_000265f6;
    }
    chain = chain + 1;
  } while( true );
}

