
uint voltage_tunning(char param_1,int *param_2)

{
  byte bVar1;
  FILE *pFVar2;
  int iVar3;
  double in_d0;
  double in_d1;
  double dVar4;
  int local_10;
  uint local_c;
  
  dVar4 = ABS(in_d1 - in_d0);
  local_c = param_2[6];
  if ((in_d0 == 0.0) || (local_c == 0)) {
    bVar1 = get_power_iic_value_from_voltage(SUB84(in_d1,0),param_2);
    write_iic_of_S9_plus_power(bVar1,param_2);
    local_c = (uint)bVar1;
    is7007_Board();
  }
  else {
    if (3 < log_level) {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d: last_iic_data = %d\n","power.c",0x173,local_c);
      }
      fclose(pFVar2);
    }
    if ((int)((uint)(dVar4 < 0.02) << 0x1f) < 0) {
      iVar3 = is7007_Board();
      if (iVar3 == 0) {
        if (3 < log_level) {
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d: It\'s very close to target voltage, stop tunning\n","power.c",
                    0x17f);
          }
          fclose(pFVar2);
        }
        *(undefined1 *)(param_2 + 1) = 1;
      }
      else {
        param_2[9] = param_2[9] + 1;
        if (1 < (uint)param_2[9]) {
          if (3 < log_level) {
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d: It\'s very close to target voltage, stop tunning\n","power.c",
                      0x179);
            }
            fclose(pFVar2);
          }
          *(undefined1 *)(param_2 + 1) = 1;
          param_2[9] = 0;
        }
      }
    }
    else {
      if (param_1 == '\0') {
        if ((dVar4 <= 0.25) || (*param_2 != 2)) {
          if ((dVar4 <= 0.13) || (*param_2 != 2)) {
            if (dVar4 <= 0.07) {
              if (dVar4 <= 0.05) {
                local_10 = 1;
              }
              else {
                local_10 = 2;
              }
            }
            else {
              local_10 = 4;
            }
          }
          else {
            local_10 = 8;
          }
        }
        else {
          local_10 = 0x10;
        }
      }
      else {
        local_10 = 1;
      }
      if (*param_2 == 2) {
        if ((int)((uint)(dVar4 < 0.03) << 0x1f) < 0) {
          local_10 = 1;
        }
        else {
          local_10 = local_10 << 1;
        }
      }
      if (in_d1 <= in_d0) {
        if (*param_2 == 1) {
          local_c = local_c - local_10;
          if ((int)local_c < 0) {
            local_c = 0;
          }
        }
        else {
          local_c = local_10 + local_c;
          if (0xff < (int)local_c) {
            local_c = 0xff;
          }
        }
        write_iic_of_S9_plus_power(local_c & 0xff,param_2);
      }
      else {
        if (*param_2 == 1) {
          local_c = local_10 + local_c;
          if (0x7f < (int)local_c) {
            local_c = 0x7f;
          }
        }
        else {
          local_c = local_c - local_10;
          if ((int)local_c < 0) {
            local_c = 0;
          }
        }
        write_iic_of_S9_plus_power(local_c & 0xff,param_2);
      }
    }
  }
  return local_c;
}

