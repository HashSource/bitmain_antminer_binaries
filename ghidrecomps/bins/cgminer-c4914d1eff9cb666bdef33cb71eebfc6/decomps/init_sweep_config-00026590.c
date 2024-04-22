
/* WARNING: Unknown calling convention */

void init_sweep_config(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  _Bool _Var3;
  FILE *pFVar4;
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
  
  uVar2 = DAT_00027314;
  uVar1 = DAT_00027310;
  _g_minor_type = PKG_BSL;
  _g_bin_level = BIN1;
  chain = 0;
  do {
    if (0xf < chain) {
LAB_000265f6:
      _Var3 = is_T11();
      if (_Var3) {
        if ((_g_minor_type == PKG_BSL) || (_g_minor_type == PKG_B_BGM)) {
          if (_g_bin_level == BIN1) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = 0;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = 0x40228000;
            g_sweep_config_eco.max_aging_voltage = (double)CONCAT44(uVar2,uVar1) + 9.25;
            g_sweep_config_eco.sweep_min_freq = 300;
            g_sweep_config_eco.sweep_max_freq = 0x15e;
            _Var3 = is_column_sweep();
            if (_Var3) {
              g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027318;
              g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_0002731c;
              g_sweep_config_hpf.max_aging_voltage =
                   (double)CONCAT44(DAT_0002731c,DAT_00027318) + (double)CONCAT44(uVar2,uVar1);
              g_sweep_config_hpf.sweep_min_freq = 0x14f;
              g_sweep_config_hpf.sweep_max_freq = 0x181;
            }
            else {
              g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027328;
              g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_0002732c;
              if (_g_minor_type == PKG_B_BGM) {
                g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027320;
                g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_00027324;
              }
              g_sweep_config_hpf.max_aging_voltage =
                   (double)CONCAT44(g_sweep_config_hpf.sweep_start_voltage._4_4_,
                                    g_sweep_config_hpf.sweep_start_voltage._0_4_) +
                   (double)CONCAT44(uVar2,uVar1);
              g_sweep_config_hpf.sweep_min_freq = 0x163;
              g_sweep_config_hpf.sweep_max_freq = 0x181;
            }
          }
          else if (_g_bin_level == BIN2) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = 0;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = 0x40228000;
            g_sweep_config_eco.max_aging_voltage = (double)CONCAT44(uVar2,uVar1) + 9.25;
            g_sweep_config_eco.sweep_min_freq = 300;
            g_sweep_config_eco.sweep_max_freq = 0x15e;
            _Var3 = is_column_sweep();
            if (_Var3) {
              g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027318;
              g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_0002731c;
              g_sweep_config_hpf.max_aging_voltage =
                   (double)CONCAT44(DAT_0002731c,DAT_00027318) + (double)CONCAT44(uVar2,uVar1);
              g_sweep_config_hpf.sweep_min_freq = 0x14f;
              g_sweep_config_hpf.sweep_max_freq = 0x181;
            }
            else {
              g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027328;
              g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_0002732c;
              g_sweep_config_hpf.max_aging_voltage =
                   (double)CONCAT44(DAT_0002732c,DAT_00027328) + (double)CONCAT44(uVar2,uVar1);
              g_sweep_config_hpf.sweep_min_freq = 0x163;
              g_sweep_config_hpf.sweep_max_freq = 0x181;
            }
          }
          else if (_g_bin_level == BIN3) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = DAT_00027330;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = DAT_00027334;
            g_sweep_config_eco.max_aging_voltage =
                 (double)CONCAT44(DAT_00027334,DAT_00027330) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_eco.sweep_min_freq = 0x10e;
            g_sweep_config_eco.sweep_max_freq = 0x136;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027338;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_0002733c;
            g_sweep_config_hpf.max_aging_voltage =
                 (double)CONCAT44(DAT_0002733c,DAT_00027338) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_hpf.sweep_min_freq = 300;
            g_sweep_config_hpf.sweep_max_freq = 0x15e;
          }
          else {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = DAT_00027340;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = DAT_00027344;
            g_sweep_config_eco.max_aging_voltage =
                 (double)CONCAT44(DAT_00027344,DAT_00027340) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_eco.sweep_min_freq = 0x10e;
            g_sweep_config_eco.sweep_max_freq = 0x136;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027348;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_0002734c;
            g_sweep_config_hpf.max_aging_voltage =
                 (double)CONCAT44(DAT_0002734c,DAT_00027348) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_hpf.sweep_min_freq = 300;
            g_sweep_config_hpf.sweep_max_freq = 0x15e;
          }
        }
        else if (_g_minor_type == PKG_BE) {
          if (_g_bin_level == BIN1) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = DAT_00027350;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = DAT_00027354;
            g_sweep_config_eco.max_aging_voltage =
                 (double)CONCAT44(DAT_00027354,DAT_00027350) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_eco.sweep_min_freq = 0x118;
            g_sweep_config_eco.sweep_max_freq = 0x14a;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027318;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_0002731c;
            g_sweep_config_hpf.max_aging_voltage =
                 (double)CONCAT44(DAT_0002731c,DAT_00027318) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_hpf.sweep_min_freq = 300;
            g_sweep_config_hpf.sweep_max_freq = 0x168;
          }
          else if (_g_bin_level == BIN2) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = DAT_00027350;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = DAT_00027354;
            g_sweep_config_eco.max_aging_voltage =
                 (double)CONCAT44(DAT_00027354,DAT_00027350) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_eco.sweep_min_freq = 0x118;
            g_sweep_config_eco.sweep_max_freq = 0x14a;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027318;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_0002731c;
            g_sweep_config_hpf.max_aging_voltage =
                 (double)CONCAT44(DAT_0002731c,DAT_00027318) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_hpf.sweep_min_freq = 300;
            g_sweep_config_hpf.sweep_max_freq = 0x168;
          }
          else if (_g_bin_level == BIN3) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = DAT_00027330;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = DAT_00027334;
            g_sweep_config_eco.max_aging_voltage =
                 (double)CONCAT44(DAT_00027334,DAT_00027330) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_eco.sweep_min_freq = 0x10e;
            g_sweep_config_eco.sweep_max_freq = 0x136;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027338;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_0002733c;
            g_sweep_config_hpf.max_aging_voltage =
                 (double)CONCAT44(DAT_0002733c,DAT_00027338) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_hpf.sweep_min_freq = 300;
            g_sweep_config_hpf.sweep_max_freq = 0x15e;
          }
          else {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = DAT_00027340;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = DAT_00027344;
            g_sweep_config_eco.max_aging_voltage =
                 (double)CONCAT44(DAT_00027344,DAT_00027340) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_eco.sweep_min_freq = 0x10e;
            g_sweep_config_eco.sweep_max_freq = 0x136;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027348;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_0002734c;
            g_sweep_config_hpf.max_aging_voltage =
                 (double)CONCAT44(DAT_0002734c,DAT_00027348) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_hpf.sweep_min_freq = 300;
            g_sweep_config_hpf.sweep_max_freq = 0x15e;
          }
        }
        else if (_g_minor_type == PKG_CE) {
          if (_g_bin_level == BIN1) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = DAT_00027358;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = DAT_0002735c;
            g_sweep_config_eco.max_aging_voltage =
                 (double)CONCAT44(DAT_0002735c,DAT_00027358) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_eco.sweep_min_freq = 300;
            g_sweep_config_eco.sweep_max_freq = 0x17c;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027350;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_00027354;
            g_sweep_config_hpf.max_aging_voltage =
                 (double)CONCAT44(DAT_00027354,DAT_00027350) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_hpf.sweep_min_freq = 0x19f;
            g_sweep_config_hpf.sweep_max_freq = 0x1d1;
          }
          else if (_g_bin_level == BIN2) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = DAT_00027358;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = DAT_0002735c;
            g_sweep_config_eco.max_aging_voltage =
                 (double)CONCAT44(DAT_0002735c,DAT_00027358) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_eco.sweep_min_freq = 300;
            g_sweep_config_eco.sweep_max_freq = 0x17c;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027350;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_00027354;
            g_sweep_config_hpf.max_aging_voltage =
                 (double)CONCAT44(DAT_00027354,DAT_00027350) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_hpf.sweep_min_freq = 0x19f;
            g_sweep_config_hpf.sweep_max_freq = 0x1d1;
          }
          else if (_g_bin_level == BIN3) {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = DAT_00027360;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = DAT_00027364;
            g_sweep_config_eco.max_aging_voltage =
                 (double)CONCAT44(DAT_00027364,DAT_00027360) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_eco.sweep_min_freq = 0x136;
            g_sweep_config_eco.sweep_max_freq = 0x168;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027368;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_0002736c;
            g_sweep_config_hpf.max_aging_voltage =
                 (double)CONCAT44(DAT_0002736c,DAT_00027368) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_hpf.sweep_min_freq = 400;
            g_sweep_config_hpf.sweep_max_freq = 0x1c2;
          }
          else {
            g_sweep_config_eco.sweep_start_voltage._0_4_ = DAT_00027360;
            g_sweep_config_eco.sweep_start_voltage._4_4_ = DAT_00027364;
            g_sweep_config_eco.max_aging_voltage =
                 (double)CONCAT44(DAT_00027364,DAT_00027360) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_eco.sweep_min_freq = 0x136;
            g_sweep_config_eco.sweep_max_freq = 0x168;
            g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027368;
            g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_0002736c;
            g_sweep_config_hpf.max_aging_voltage =
                 (double)CONCAT44(DAT_0002736c,DAT_00027368) + (double)CONCAT44(uVar2,uVar1);
            g_sweep_config_hpf.sweep_min_freq = 400;
            g_sweep_config_hpf.sweep_max_freq = 0x1c2;
          }
        }
        else {
          g_sweep_config_eco.sweep_start_voltage._0_4_ = DAT_00027370;
          g_sweep_config_eco.sweep_start_voltage._4_4_ = DAT_00027374;
          g_sweep_config_eco.max_aging_voltage =
               (double)CONCAT44(DAT_00027374,DAT_00027370) + (double)CONCAT44(uVar2,uVar1);
          g_sweep_config_eco.sweep_min_freq = 0xfa;
          g_sweep_config_eco.sweep_max_freq = 300;
          g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027378;
          g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_0002737c;
          g_sweep_config_hpf.max_aging_voltage =
               (double)CONCAT44(DAT_0002737c,DAT_00027378) + (double)CONCAT44(uVar2,uVar1);
          g_sweep_config_hpf.sweep_min_freq = 300;
          g_sweep_config_hpf.sweep_max_freq = 0x168;
        }
      }
      else {
        _Var3 = is_T11a();
        if (_Var3) {
          g_sweep_config_eco.sweep_start_voltage._0_4_ = DAT_00027380;
          g_sweep_config_eco.sweep_start_voltage._4_4_ = DAT_00027384;
          g_sweep_config_eco.max_aging_voltage = (double)CONCAT44(DAT_0002738c,DAT_00027388);
          g_sweep_config_eco.sweep_min_freq = 0xfa;
          g_sweep_config_eco.sweep_max_freq = 0x113;
          g_sweep_config_hpf.sweep_start_voltage._0_4_ = DAT_00027390;
          g_sweep_config_hpf.sweep_start_voltage._4_4_ = DAT_00027394;
          g_sweep_config_hpf.max_aging_voltage = 19.5;
          g_sweep_config_hpf.sweep_min_freq = 0x127;
          g_sweep_config_hpf.sweep_max_freq = 0x140;
        }
      }
      if (3 < log_level) {
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fwrite("\nsweep config for eco mode: \n",1,0x1d,pFVar4);
        }
        fclose(pFVar4);
      }
      if (3 < log_level) {
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"sweep_start_voltage: %.2f\n",g_sweep_config_eco.sweep_start_voltage._0_4_,
                  g_sweep_config_eco.sweep_start_voltage._4_4_);
        }
        fclose(pFVar4);
      }
      if (3 < log_level) {
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"max_aging_voltage:   %.2f\n",g_sweep_config_eco.max_aging_voltage._0_4_,
                  g_sweep_config_eco.max_aging_voltage._4_4_);
        }
        fclose(pFVar4);
      }
      if (3 < log_level) {
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"sweep_min_freq:      %dM\n",g_sweep_config_eco.sweep_min_freq);
        }
        fclose(pFVar4);
      }
      if (3 < log_level) {
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"sweep_max_freq:      %dM\n",g_sweep_config_eco.sweep_max_freq);
        }
        fclose(pFVar4);
      }
      if (3 < log_level) {
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fwrite("\nsweep config for hpf mode: \n",1,0x1d,pFVar4);
        }
        fclose(pFVar4);
      }
      if (3 < log_level) {
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"sweep_start_voltage: %.2f\n",g_sweep_config_hpf.sweep_start_voltage._0_4_,
                  g_sweep_config_hpf.sweep_start_voltage._4_4_);
        }
        fclose(pFVar4);
      }
      if (3 < log_level) {
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"max_aging_voltage:   %.2f\n",g_sweep_config_hpf.max_aging_voltage._0_4_,
                  g_sweep_config_hpf.max_aging_voltage._4_4_);
        }
        fclose(pFVar4);
      }
      if (3 < log_level) {
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"sweep_min_freq:      %dM\n",g_sweep_config_hpf.sweep_min_freq);
        }
        fclose(pFVar4);
      }
      if (3 < log_level) {
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"sweep_max_freq:      %dM\n",g_sweep_config_hpf.sweep_max_freq);
        }
        fclose(pFVar4);
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

