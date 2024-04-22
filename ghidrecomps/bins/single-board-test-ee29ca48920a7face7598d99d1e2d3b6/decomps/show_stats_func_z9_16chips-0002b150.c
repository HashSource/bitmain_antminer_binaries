
undefined4 show_stats_func_z9_16chips(void)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  bool bVar10;
  int local_24;
  
  local_24 = 0;
  while (show_id_alive != 0) {
    usleep(1000000);
    memset(lcd_buffer + 0x20,0x20,0x40);
    sprintf(lcd_buffer + 0x20,"time %ds",local_24);
    iVar1 = is_asic_pass(0);
    bVar10 = iVar1 != 0;
    if (bVar10) {
      iVar1 = 1;
    }
    bVar2 = (byte)iVar1;
    if (!bVar10) {
      bVar2 = 0;
    }
    iVar1 = is_asic_pass(1);
    bVar10 = iVar1 != 0;
    if (bVar10) {
      iVar1 = 1;
    }
    bVar3 = (byte)iVar1;
    if (!bVar10) {
      bVar3 = 0;
    }
    iVar1 = is_asic_pass(2);
    bVar10 = iVar1 != 0;
    if (bVar10) {
      iVar1 = 1;
    }
    bVar4 = (byte)iVar1;
    if (!bVar10) {
      bVar4 = 0;
    }
    iVar1 = is_asic_pass(3);
    bVar10 = iVar1 != 0;
    if (bVar10) {
      iVar1 = 1;
    }
    bVar5 = (byte)iVar1;
    if (!bVar10) {
      bVar5 = 0;
    }
    iVar1 = is_asic_pass(4);
    bVar10 = iVar1 != 0;
    if (bVar10) {
      iVar1 = 1;
    }
    bVar6 = (byte)iVar1;
    if (!bVar10) {
      bVar6 = 0;
    }
    iVar1 = is_asic_pass(5);
    bVar10 = iVar1 != 0;
    if (bVar10) {
      iVar1 = 1;
    }
    bVar7 = (byte)iVar1;
    if (!bVar10) {
      bVar7 = 0;
    }
    iVar1 = is_asic_pass(6);
    bVar10 = iVar1 != 0;
    if (bVar10) {
      iVar1 = 1;
    }
    bVar8 = (byte)iVar1;
    if (!bVar10) {
      bVar8 = 0;
    }
    iVar1 = is_asic_pass(7);
    bVar10 = iVar1 != 0;
    if (bVar10) {
      iVar1 = 1;
    }
    bVar9 = (byte)iVar1;
    if (!bVar10) {
      bVar9 = 0;
    }
    sprintf(DAT_0002b390,"nonce=%d%d%d%d %d%d%d%d",(uint)bVar2,(uint)bVar3,(uint)bVar4,(uint)bVar5,
            (uint)bVar6,(uint)bVar7,(uint)bVar8,(uint)bVar9);
    iVar1 = is_asic_pass(8);
    bVar10 = iVar1 != 0;
    if (bVar10) {
      iVar1 = 1;
    }
    bVar2 = (byte)iVar1;
    if (!bVar10) {
      bVar2 = 0;
    }
    iVar1 = is_asic_pass(9);
    bVar10 = iVar1 != 0;
    if (bVar10) {
      iVar1 = 1;
    }
    bVar3 = (byte)iVar1;
    if (!bVar10) {
      bVar3 = 0;
    }
    iVar1 = is_asic_pass(10);
    bVar10 = iVar1 != 0;
    if (bVar10) {
      iVar1 = 1;
    }
    bVar4 = (byte)iVar1;
    if (!bVar10) {
      bVar4 = 0;
    }
    iVar1 = is_asic_pass(0xb);
    bVar10 = iVar1 != 0;
    if (bVar10) {
      iVar1 = 1;
    }
    bVar5 = (byte)iVar1;
    if (!bVar10) {
      bVar5 = 0;
    }
    iVar1 = is_asic_pass(0xc);
    bVar10 = iVar1 != 0;
    if (bVar10) {
      iVar1 = 1;
    }
    bVar6 = (byte)iVar1;
    if (!bVar10) {
      bVar6 = 0;
    }
    iVar1 = is_asic_pass(0xd);
    bVar10 = iVar1 != 0;
    if (bVar10) {
      iVar1 = 1;
    }
    bVar7 = (byte)iVar1;
    if (!bVar10) {
      bVar7 = 0;
    }
    iVar1 = is_asic_pass(0xe);
    bVar10 = iVar1 != 0;
    if (bVar10) {
      iVar1 = 1;
    }
    bVar8 = (byte)iVar1;
    if (!bVar10) {
      bVar8 = 0;
    }
    iVar1 = is_asic_pass(0xf);
    bVar10 = iVar1 != 0;
    if (bVar10) {
      iVar1 = 1;
    }
    bVar9 = (byte)iVar1;
    if (!bVar10) {
      bVar9 = 0;
    }
    sprintf(DAT_0002b394,"      %d%d%d%d %d%d%d%d",(uint)bVar2,(uint)bVar3,(uint)bVar4,(uint)bVar5,
            (uint)bVar6,(uint)bVar7,(uint)bVar8,(uint)bVar9);
    sprintf(DAT_0002b398,"%d-%d\'C %d-%d\'C",(uint)sensor_info._1_1_,(uint)(byte)sensor_info,
            (uint)sensor_info._5_1_,(uint)sensor_info._4_1_);
    local_24 = local_24 + 1;
    write(cgpu._36_4_,lcd_buffer + 0x20,0x40);
  }
  return 0;
}

