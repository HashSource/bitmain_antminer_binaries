
undefined8 dsPIC33EP16GS202_pic_get_an_voltage2(byte param_1)

{
  undefined2 uVar1;
  undefined uVar2;
  undefined8 uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined local_20;
  undefined local_1c;
  undefined uStack_1b;
  FILE *local_18;
  FILE *local_14;
  undefined2 local_10;
  undefined local_d;
  int local_c;
  
  local_d = 4;
  local_24 = 0;
  local_20 = 0;
  local_28 = 0xff;
  local_c = 0;
  local_10 = 0x2d;
  uVar1 = local_10;
  while( true ) {
    local_1c = (undefined)((ushort)uVar1 >> 8);
    uStack_1b = (undefined)uVar1;
    if (1 < local_c) {
      return DAT_00034ce8;
    }
    local_c = local_c + 1;
    T9_plus_write_pic_iic(0,0,0,param_1,0x55);
    T9_plus_write_pic_iic(0,0,0,param_1,0xaa);
    T9_plus_write_pic_iic(0,0,0,param_1,local_d);
    T9_plus_write_pic_iic(0,0,0,param_1,0x29);
    T9_plus_write_pic_iic(0,0,0,param_1,local_1c);
    T9_plus_write_pic_iic(0,0,0,param_1,uStack_1b);
    usleep(500000);
    uVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    local_28 = CONCAT31(local_28._1_3_,uVar2);
    uVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    local_28._0_2_ = CONCAT11(uVar2,(undefined)local_28);
    uVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    local_28._0_3_ = CONCAT12(uVar2,(undefined2)local_28);
    uVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    local_28 = CONCAT13(uVar2,(undefined3)local_28);
    uVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    local_24 = CONCAT31(local_24._1_3_,uVar2);
    uVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    local_24._0_2_ = CONCAT11(uVar2,(undefined)local_24);
    uVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    local_24._0_3_ = CONCAT12(uVar2,(undefined2)local_24);
    uVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    local_24 = CONCAT13(uVar2,(undefined3)local_24);
    local_20 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    if ((local_28._1_1_ == ')') && (local_28._2_1_ == '\x01')) break;
    if (3 < log_level) {
      local_14 = fopen(log_file,"a+");
      if (local_14 != (FILE *)0x0) {
        fprintf(local_14,"%s:%d: Couldn\'t hear AN voltage response from IIC[%d]\n","power.c",0x21b,
                (uint)param_1);
      }
      fclose(local_14);
    }
    dump_mem("read_back_data:",&local_28,9);
    sleep(1);
    uVar1 = CONCAT11(local_1c,uStack_1b);
  }
  if (5 < log_level) {
    local_18 = fopen(log_file,"a+");
    if (local_18 != (FILE *)0x0) {
      fprintf(local_18,"%s:%d: Receive AN voltage response from IIC[%d]\n","power.c",0x221,
              (uint)param_1);
    }
    fclose(local_18);
  }
  uVar3 = decode_an_voltage_buf(&local_28);
  return uVar3;
}

