
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void singleboard_set_address_test(void)

{
  int iVar1;
  undefined4 local_420;
  undefined4 uStack_41c;
  undefined4 uStack_418;
  undefined4 uStack_414;
  undefined4 local_410;
  undefined2 local_40c;
  undefined local_40a;
  undefined local_20;
  byte local_1f;
  undefined local_1e;
  uint local_1c;
  undefined4 local_18;
  int local_14;
  
  read_register(0,0,0,0);
  read_register(0,1,0,0);
  usleep(200000);
  asic_addr_interval();
  set_address();
  usleep(200000);
  read_register(0,1,0,0);
  local_14 = 0;
  do {
    if (2 < local_14) {
LAB_000223a2:
      if (local_14 == 3) {
        set_address_test_result = 1;
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
          snprintf((char *)&local_420,0x400,"%s Success\n","singleboard_set_address_test");
          _applog(2,&local_420,0);
        }
      }
      else {
        set_address_test_result = 0xffffffff;
      }
      return;
    }
    local_20 = 0;
    local_1f = (char)local_14 * (char)addr_interval;
    local_1e = 0;
    local_1c = 0;
    local_18 = 0;
    iVar1 = read_reg_item(&local_20,500);
    if (iVar1 < 0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        local_420._0_1_ = s_read_chip_num_timeout_00034808[0];
        local_420._1_1_ = s_read_chip_num_timeout_00034808[1];
        local_420._2_1_ = s_read_chip_num_timeout_00034808[2];
        local_420._3_1_ = s_read_chip_num_timeout_00034808[3];
        uStack_41c._0_1_ = s_read_chip_num_timeout_00034808[4];
        uStack_41c._1_1_ = s_read_chip_num_timeout_00034808[5];
        uStack_41c._2_1_ = s_read_chip_num_timeout_00034808[6];
        uStack_41c._3_1_ = s_read_chip_num_timeout_00034808[7];
        uStack_418._0_1_ = s_read_chip_num_timeout_00034808[8];
        uStack_418._1_1_ = s_read_chip_num_timeout_00034808[9];
        uStack_418._2_1_ = s_read_chip_num_timeout_00034808[10];
        uStack_418._3_1_ = s_read_chip_num_timeout_00034808[11];
        uStack_414._0_1_ = s_read_chip_num_timeout_00034808[12];
        uStack_414._1_1_ = s_read_chip_num_timeout_00034808[13];
        uStack_414._2_1_ = s_read_chip_num_timeout_00034808[14];
        uStack_414._3_1_ = s_read_chip_num_timeout_00034808[15];
        local_410._0_1_ = s_read_chip_num_timeout_00034808[16];
        local_410._1_1_ = s_read_chip_num_timeout_00034808[17];
        local_410._2_1_ = s_read_chip_num_timeout_00034808[18];
        local_410._3_1_ = s_read_chip_num_timeout_00034808[19];
        local_40c = (undefined2)ram0x0003481c;
        local_40a = (undefined)((uint)ram0x0003481c >> 0x10);
        _applog(2,&local_420,0);
      }
      goto LAB_000223a2;
    }
    if ((local_1c & 0xff) != (uint)local_1f) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf((char *)&local_420,0x400,"Set address Fail set:%02x get:%02x\n",(uint)local_1f,
                 local_1c & 0xff);
        _applog(2,&local_420,0);
      }
      goto LAB_000223a2;
    }
    local_14 = local_14 + 1;
  } while( true );
}

