
/* WARNING: Unknown calling convention */

void single_BM1391P_open_core(uchar which_chain)

{
  uchar core_id;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  __useconds_t _Var4;
  uint uVar5;
  uint OpenCoreNum3;
  uint OpenCoreNum4;
  uint OpenCoreNum5;
  uint OpenCoreNum6;
  uint OpenCoreNum7;
  uint uVar6;
  uint OpenCoreNum8;
  uint uVar7;
  uint OpenCoreNum1;
  uint uVar8;
  uint OpenCoreNum2;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint buf_vil_tw [13];
  
  uVar1 = (uint)which_chain;
  memset(buf_vil_tw,0,0x34);
  uVar7 = Conf.OpenCoreNum8;
  uVar3 = Conf.OpenCoreNum1;
  local_78 = Conf.OpenCoreNum2;
  uVar6 = 0;
  local_74 = Conf.OpenCoreNum3;
  uVar8 = uVar1 << 0x10 | 0x1000080;
  local_70 = Conf.OpenCoreNum4;
  local_6c = Conf.OpenCoreNum5;
  local_68 = Conf.OpenCoreNum6;
  local_64 = Conf.OpenCoreNum7;
  printf("\n--- %s: Chain : %d\n",DAT_00013700,uVar1);
  gIsOpenCoreEnd = false;
  uVar2 = read_axi_fpga(0x40);
  write_axi_fpga(0x40,uVar2 & 0xffffffdf);
  write_axi_fpga(0x24,0);
  uVar2 = 1 << uVar1;
  memset(buf_vil_tw,0,0x34);
  do {
    while (core_id = (uchar)uVar6, uVar6 < 0x20) {
      if ((int)(uVar3 << 0x1f) < 0) {
        BM1391_enable_core_clock(which_chain,'\0',core_id,'\x01');
        _Var4 = 5000;
        do {
          usleep(_Var4);
          uVar5 = read_axi_fpga(3);
          _Var4 = 3000;
        } while ((uVar5 & uVar2) == 0);
        buf_vil_tw[0] = uVar8;
        set_TW_write_command(buf_vil_tw);
        usleep(Conf.OpenCoreGap);
      }
      uVar6 = uVar6 + 1;
      uVar3 = uVar3 >> 1;
      if (uVar6 == 0x100) goto LAB_000134c0;
    }
    if (uVar6 - 0x20 < 0x20) {
      if ((int)(local_78 << 0x1f) < 0) {
        BM1391_enable_core_clock(which_chain,'\0',core_id,'\x01');
        _Var4 = 5000;
        do {
          usleep(_Var4);
          uVar5 = read_axi_fpga(3);
          _Var4 = 3000;
        } while ((uVar5 & uVar2) == 0);
        buf_vil_tw[0] = uVar8;
        set_TW_write_command(buf_vil_tw);
        usleep(Conf.OpenCoreGap);
      }
      local_78 = local_78 >> 1;
    }
    else if (uVar6 - 0x40 < 0x20) {
      if ((int)(local_74 << 0x1f) < 0) {
        BM1391_enable_core_clock(which_chain,'\0',core_id,'\x01');
        _Var4 = 5000;
        do {
          usleep(_Var4);
          uVar5 = read_axi_fpga(3);
          _Var4 = 3000;
        } while ((uVar5 & uVar2) == 0);
        buf_vil_tw[0] = uVar8;
        set_TW_write_command(buf_vil_tw);
        usleep(Conf.OpenCoreGap);
      }
      local_74 = local_74 >> 1;
    }
    else if (uVar6 - 0x60 < 0x20) {
      if ((int)(local_70 << 0x1f) < 0) {
        BM1391_enable_core_clock(which_chain,'\0',core_id,'\x01');
        _Var4 = 5000;
        do {
          usleep(_Var4);
          uVar5 = read_axi_fpga(3);
          _Var4 = 3000;
        } while ((uVar5 & uVar2) == 0);
        buf_vil_tw[0] = uVar8;
        set_TW_write_command(buf_vil_tw);
        usleep(Conf.OpenCoreGap);
      }
      local_70 = local_70 >> 1;
    }
    else if (uVar6 - 0x80 < 0x20) {
      if ((int)(local_6c << 0x1f) < 0) {
        BM1391_enable_core_clock(which_chain,'\0',core_id,'\x01');
        _Var4 = 5000;
        do {
          usleep(_Var4);
          uVar5 = read_axi_fpga(3);
          _Var4 = 3000;
        } while ((uVar5 & uVar2) == 0);
        buf_vil_tw[0] = uVar8;
        set_TW_write_command(buf_vil_tw);
        usleep(Conf.OpenCoreGap);
      }
      local_6c = local_6c >> 1;
    }
    else if (uVar6 - 0xa0 < 0x20) {
      if ((int)(local_68 << 0x1f) < 0) {
        BM1391_enable_core_clock(which_chain,'\0',core_id,'\x01');
        _Var4 = 5000;
        do {
          usleep(_Var4);
          uVar5 = read_axi_fpga(3);
          _Var4 = 3000;
        } while ((uVar5 & uVar2) == 0);
        buf_vil_tw[0] = uVar8;
        set_TW_write_command(buf_vil_tw);
        usleep(Conf.OpenCoreGap);
      }
      local_68 = local_68 >> 1;
    }
    else if (uVar6 - 0xc0 < 0x20) {
      if ((int)(local_64 << 0x1f) < 0) {
        BM1391_enable_core_clock(which_chain,'\0',core_id,'\x01');
        _Var4 = 5000;
        do {
          usleep(_Var4);
          uVar5 = read_axi_fpga(3);
          _Var4 = 3000;
        } while ((uVar5 & uVar2) == 0);
        buf_vil_tw[0] = uVar8;
        set_TW_write_command(buf_vil_tw);
        usleep(Conf.OpenCoreGap);
      }
      local_64 = local_64 >> 1;
    }
    else {
      if ((int)(uVar7 << 0x1f) < 0) {
        BM1391_enable_core_clock(which_chain,'\0',core_id,'\x01');
        _Var4 = 5000;
        do {
          usleep(_Var4);
          uVar5 = read_axi_fpga(3);
          _Var4 = 3000;
        } while ((uVar5 & uVar2) == 0);
        buf_vil_tw[0] = uVar8;
        set_TW_write_command(buf_vil_tw);
        usleep(Conf.OpenCoreGap);
      }
      uVar7 = uVar7 >> 1;
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 != 0x100);
LAB_000134c0:
  uVar3 = read_axi_fpga(0x30);
  write_axi_fpga(0x30,uVar3 | 0x400000);
  gIsOpenCoreEnd = true;
  printf("\n--- %s end: Chain : %d\n",DAT_00013700,uVar1);
  return;
}

