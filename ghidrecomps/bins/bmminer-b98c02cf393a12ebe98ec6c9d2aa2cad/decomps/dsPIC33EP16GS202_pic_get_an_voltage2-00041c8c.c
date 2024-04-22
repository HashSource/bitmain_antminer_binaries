
undefined8 dsPIC33EP16GS202_pic_get_an_voltage2(undefined4 param_1)

{
  undefined uVar1;
  FILE *pFVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 local_2c;
  undefined4 local_28;
  undefined local_24;
  
  iVar3 = 2;
  local_28 = 0;
  local_24 = 0;
  local_2c = 0xff;
  do {
    T9_plus_write_pic_iic(0,0,0,param_1,0x55);
    T9_plus_write_pic_iic(0,0,0,param_1,0xaa);
    T9_plus_write_pic_iic(0,0,0,param_1,4);
    T9_plus_write_pic_iic(0,0,0,param_1,0x29);
    T9_plus_write_pic_iic(0,0,0,param_1,0);
    T9_plus_write_pic_iic(0,0,0,param_1,0x2d);
    usleep(500000);
    uVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    local_2c = CONCAT31(local_2c._1_3_,uVar1);
    uVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    local_2c._0_2_ = CONCAT11(uVar1,(undefined)local_2c);
    uVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    local_2c._0_3_ = CONCAT12(uVar1,(undefined2)local_2c);
    uVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    local_2c = CONCAT13(uVar1,(undefined3)local_2c);
    uVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    local_28 = CONCAT31(local_28._1_3_,uVar1);
    uVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    local_28._0_2_ = CONCAT11(uVar1,(undefined)local_28);
    uVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    local_28._0_3_ = CONCAT12(uVar1,(undefined2)local_28);
    uVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    local_28 = CONCAT13(uVar1,(undefined3)local_28);
    local_24 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    if ((local_2c._1_1_ == ')') && (local_2c._2_1_ == '\x01')) {
      if (5 < log_level) {
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: Receive AN voltage response from IIC[%d]\n","power.c",0x220,
                  DAT_00041e90,param_1);
        }
        fclose(pFVar2);
      }
      uVar4 = decode_an_voltage_buf(&local_2c);
      return uVar4;
    }
    if (3 < log_level) {
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: Couldn\'t hear AN voltage response from IIC[%d]\n","power.c",0x21a
                ,DAT_00041e90,param_1);
      }
      fclose(pFVar2);
    }
    dump_mem("read_back_data:",&local_2c,9);
    sleep(1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return DAT_00041e88;
}

