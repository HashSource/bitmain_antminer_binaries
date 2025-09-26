
int check_asic_by_temp(float *asic_temp)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float *asic_temp_local;
  int addr [9];
  char time_stamp [48];
  char tmp1 [2048];
  float avg;
  int target_addr;
  int col;
  int row;
  float temp_percentage;
  int count;
  float sum;
  int n;
  int m;
  int j;
  int i;
  
  temp_percentage = 0.0;
  iVar2 = config_get_tpl_row();
  iVar3 = config_get_tpl_column();
  for (i = 0; iVar3 * iVar2 - i != 0 && i <= iVar3 * iVar2; i = i + 1) {
    if (asic_temp[i] == 0.0) {
      return -1;
    }
  }
  i = 0;
  do {
    if (iVar2 <= i) {
      return -1;
    }
    for (j = 0; j < iVar3; j = j + 1) {
      iVar4 = config_get_tpl_data(i,j);
      iVar4 = iVar4 + -1;
      sum = 0.0;
      memset(addr,0,0x24);
      count = 0;
      for (m = 0; m < 3; m = m + 1) {
        for (n = 0; iVar1 = count, n < 3; n = n + 1) {
          if ((i == 0) && (j == 0)) {
            count = count + 1;
            iVar5 = config_get_tpl_data(m,n);
            addr[iVar1] = iVar5 + -1;
          }
          else if ((i == 0) && (iVar3 + -1 == j)) {
            count = count + 1;
            iVar5 = config_get_tpl_data(m,j - n);
            addr[iVar1] = iVar5 + -1;
          }
          else {
            if (i == 0) {
              count = count + 1;
              iVar5 = config_get_tpl_data(m,j + -1);
              addr[iVar1] = iVar5 + -1;
              iVar1 = count;
              count = count + 1;
              iVar5 = config_get_tpl_data(m + i,j);
              addr[iVar1] = iVar5 + -1;
              iVar1 = count;
              count = count + 1;
              iVar5 = config_get_tpl_data(i + m,j + 1);
              addr[iVar1] = iVar5 + -1;
              break;
            }
            if ((iVar2 + -1 == i) && (j == 0)) {
              count = count + 1;
              iVar5 = config_get_tpl_data(i - m,n);
              addr[iVar1] = iVar5 + -1;
            }
            else if ((iVar2 + -1 == i) && (iVar3 + -1 == j)) {
              count = count + 1;
              iVar5 = config_get_tpl_data(i - m,j - n);
              addr[iVar1] = iVar5 + -1;
            }
            else {
              if (iVar2 + -1 == i) {
                count = count + 1;
                iVar5 = config_get_tpl_data(i - m,j + -1);
                addr[iVar1] = iVar5 + -1;
                iVar1 = count;
                count = count + 1;
                iVar5 = config_get_tpl_data(i - m,j);
                addr[iVar1] = iVar5 + -1;
                iVar1 = count;
                count = count + 1;
                iVar5 = config_get_tpl_data(i - m,j + 1);
                addr[iVar1] = iVar5 + -1;
                break;
              }
              if (j == 0) {
                if (m == 0) {
                  count = count + 1;
                  iVar5 = config_get_tpl_data(i,n);
                  addr[iVar1] = iVar5 + -1;
                }
                else if (m == 1) {
                  count = count + 1;
                  iVar5 = config_get_tpl_data(i + -1,n);
                  addr[iVar1] = iVar5 + -1;
                }
                else {
                  count = count + 1;
                  iVar5 = config_get_tpl_data(i + 1,n);
                  addr[iVar1] = iVar5 + -1;
                }
              }
              else {
                if (iVar3 + -1 != j) {
                  if (m == 0) {
                    count = count + 1;
                    iVar5 = config_get_tpl_data(i,j + -1);
                    addr[iVar1] = iVar5 + -1;
                    iVar1 = count;
                    count = count + 1;
                    iVar5 = config_get_tpl_data(i,j);
                    addr[iVar1] = iVar5 + -1;
                    iVar1 = count;
                    count = count + 1;
                    iVar5 = config_get_tpl_data(i,j + 1);
                    addr[iVar1] = iVar5 + -1;
                  }
                  else if (m == 1) {
                    count = count + 1;
                    iVar5 = config_get_tpl_data(i + -1,j + -1);
                    addr[iVar1] = iVar5 + -1;
                    iVar1 = count;
                    count = count + 1;
                    iVar5 = config_get_tpl_data(i + -1,j);
                    addr[iVar1] = iVar5 + -1;
                    iVar1 = count;
                    count = count + 1;
                    iVar5 = config_get_tpl_data(i + -1,j + 1);
                    addr[iVar1] = iVar5 + -1;
                  }
                  else {
                    count = count + 1;
                    iVar5 = config_get_tpl_data(i + 1,j + -1);
                    addr[iVar1] = iVar5 + -1;
                    iVar1 = count;
                    count = count + 1;
                    iVar5 = config_get_tpl_data(i + 1,j);
                    addr[iVar1] = iVar5 + -1;
                    iVar1 = count;
                    count = count + 1;
                    iVar5 = config_get_tpl_data(i + 1,j + 1);
                    addr[iVar1] = iVar5 + -1;
                  }
                  break;
                }
                if (m == 0) {
                  count = count + 1;
                  iVar5 = config_get_tpl_data(i,j - n);
                  addr[iVar1] = iVar5 + -1;
                }
                else if (m == 1) {
                  count = count + 1;
                  iVar5 = config_get_tpl_data(i + -1,j - n);
                  addr[iVar1] = iVar5 + -1;
                }
                else {
                  count = count + 1;
                  iVar5 = config_get_tpl_data(i + 1,j - n);
                  addr[iVar1] = iVar5 + -1;
                }
              }
            }
          }
        }
      }
      for (m = 0; m < 9; m = m + 1) {
        sum = sum + asic_temp[addr[m]];
      }
      temp_percentage = ABS(sum / 9.0 - asic_temp[iVar4]) / (sum / 9.0);
      if (0.15 < temp_percentage) {
        check_asic_by_temp::fail_num = check_asic_by_temp::fail_num + 1;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: poor chip process or bad asic happen:asic %d, temp %.2f, temp_percentage %.2f\n"
               ,"check_asic_by_temp",iVar4,&temp_percentage,(double)asic_temp[iVar4],
               (double)temp_percentage);
        snprintf(tmp1,0x800,
                 "poor chip process or bad asic happen:asic %d, temp %.2f, temp_percentage %.2f",
                 iVar4,(double)asic_temp[iVar4],(double)temp_percentage);
        log_to_file(tmp1,time_stamp);
        if (3 < check_asic_by_temp::fail_num) {
          return iVar4;
        }
      }
    }
    i = i + 1;
  } while( true );
}

