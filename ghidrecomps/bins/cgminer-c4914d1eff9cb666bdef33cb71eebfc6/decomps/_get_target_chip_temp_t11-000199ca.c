
int _get_target_chip_temp_t11(_Bool is_low_temp_env,int min_entrance_pcb_temp)

{
  _Bool _Var1;
  FILE *pFVar2;
  int iVar3;
  int iVar4;
  int min_entrance_pcb_temp_local;
  _Bool is_low_temp_env_local;
  FILE *pFile_1;
  FILE *pFile;
  int chain;
  
  if (!_get_target_chip_temp_t11::minor_type_init) {
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if ((dev->chain_exist[chain] != 0) &&
         (_get_target_chip_temp_t11::minor_types = g_minor_type[chain], 3 < log_level)) {
        print_crt_time_to_file(log_file,3);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: chip miner_type = [%d]\n","temperature.c",0x641,
                  "_get_target_chip_temp_t11",_get_target_chip_temp_t11::minor_types);
        }
        fclose(pFVar2);
      }
    }
    _get_target_chip_temp_t11::minor_type_init = true;
  }
  if ((_get_target_chip_temp_t11::minor_types == PKG_BSL) ||
     (_get_target_chip_temp_t11::minor_types == PKG_BE)) {
    _Var1 = is_economic_mode();
    if (_Var1) {
      if (min_entrance_pcb_temp < 0x1b) {
        iVar4 = 0x55;
      }
      else if (min_entrance_pcb_temp < 0x24) {
        iVar4 = 0x55 - ((min_entrance_pcb_temp + -0x1a) * 0xb) / 9;
      }
      else if (min_entrance_pcb_temp < 0x2d) {
        iVar4 = ((min_entrance_pcb_temp + -0x23) * 9) / 9 + 0x4a;
      }
      else {
        iVar4 = 0x53;
      }
    }
    else if ((_get_target_chip_temp_t11::minor_types == PKG_BSL) &&
            (_Var1 = is_special_mode(), _Var1)) {
      iVar4 = 0x5a;
    }
    else {
      iVar4 = 0x55;
    }
  }
  else if (_get_target_chip_temp_t11::minor_types == PKG_CE) {
    _Var1 = is_economic_mode();
    if (_Var1) {
      if (min_entrance_pcb_temp < 0x11) {
        iVar4 = 0x4b;
      }
      else if (min_entrance_pcb_temp < 0x19) {
        iVar4 = (min_entrance_pcb_temp + -0x10) * 5;
        iVar3 = iVar4 + 7;
        if (-1 < iVar4) {
          iVar3 = iVar4;
        }
        iVar4 = 0x4b - (iVar3 >> 3);
      }
      else if (min_entrance_pcb_temp < 0x1e) {
        iVar4 = 0x46 - ((min_entrance_pcb_temp + -0x18) * 10) / 5;
      }
      else if (min_entrance_pcb_temp < 0x28) {
        iVar4 = ((min_entrance_pcb_temp + -0x1d) * 0xc) / 10 + 0x3c;
      }
      else if (min_entrance_pcb_temp < 0x31) {
        iVar4 = ((min_entrance_pcb_temp + -0x27) * 10) / 9 + 0x48;
      }
      else {
        iVar4 = 0x52;
      }
    }
    else {
      iVar4 = 0x55;
    }
  }
  else if (_get_target_chip_temp_t11::minor_types == PKG_B_BGM) {
    _Var1 = is_economic_mode();
    if (_Var1) {
      if (min_entrance_pcb_temp < 0xd) {
        iVar4 = 0x55;
      }
      else if (min_entrance_pcb_temp < 0x12) {
        iVar4 = 0x55 - ((min_entrance_pcb_temp + -0xc) * 10) / 5;
      }
      else if (min_entrance_pcb_temp < 0x1a) {
        iVar4 = (min_entrance_pcb_temp + -0x11) * 5;
        iVar3 = iVar4 + 7;
        if (-1 < iVar4) {
          iVar3 = iVar4;
        }
        iVar4 = 0x4b - (iVar3 >> 3);
      }
      else if (min_entrance_pcb_temp < 0x24) {
        iVar4 = ((min_entrance_pcb_temp + -0x19) * 0xc) / 10 + 0x46;
      }
      else {
        iVar4 = 0x52;
      }
    }
    else if ((_get_target_chip_temp_t11::minor_types == PKG_B_BGM) &&
            (_Var1 = is_special_mode(), _Var1)) {
      iVar4 = 0x5a;
    }
    else {
      iVar4 = 0x55;
    }
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(temp_log,3);
      pFVar2 = fopen(temp_log,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: error, unknow chip package type....\n","temperature.c",0x6a9,
                "_get_target_chip_temp_t11");
      }
      fclose(pFVar2);
    }
    _Var1 = is_economic_mode();
    if (_Var1) {
      if (min_entrance_pcb_temp < 0x11) {
        iVar4 = 0x4b;
      }
      else if (min_entrance_pcb_temp < 0x19) {
        iVar4 = (min_entrance_pcb_temp + -0x10) * 5;
        iVar3 = iVar4 + 7;
        if (-1 < iVar4) {
          iVar3 = iVar4;
        }
        iVar4 = 0x4b - (iVar3 >> 3);
      }
      else if (min_entrance_pcb_temp < 0x1e) {
        iVar4 = 0x46 - ((min_entrance_pcb_temp + -0x18) * 10) / 5;
      }
      else if (min_entrance_pcb_temp < 0x28) {
        iVar4 = ((min_entrance_pcb_temp + -0x1d) * 0xc) / 10 + 0x3c;
      }
      else if (min_entrance_pcb_temp < 0x31) {
        iVar4 = ((min_entrance_pcb_temp + -0x27) * 10) / 9 + 0x48;
      }
      else {
        iVar4 = 0x52;
      }
    }
    else {
      iVar4 = 0x55;
    }
  }
  return iVar4;
}

