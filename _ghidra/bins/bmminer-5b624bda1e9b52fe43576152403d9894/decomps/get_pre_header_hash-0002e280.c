
/* WARNING: Unknown calling convention */

int get_pre_header_hash(uint *buf)

{
  _Bool _Var1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  char tmp42 [2048];
  
  puVar2 = axi_fpga_addr;
  _Var1 = opt_debug;
  uVar10 = axi_fpga_addr[0x50];
  *buf = uVar10;
  uVar3 = puVar2[0x51];
  buf[1] = uVar3;
  uVar4 = puVar2[0x52];
  buf[2] = uVar4;
  uVar9 = puVar2[0x53];
  buf[3] = uVar9;
  uVar8 = puVar2[0x54];
  buf[4] = uVar8;
  uVar7 = puVar2[0x55];
  buf[5] = uVar7;
  uVar5 = puVar2[0x56];
  buf[6] = uVar5;
  uVar6 = puVar2[0x57];
  buf[7] = uVar6;
  if ((_Var1) && (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,
             "%s: PRE_HEADER_HASH buf[0]: 0x%x, buf[1]: 0x%x, buf[2]: 0x%x, buf[3]: 0x%x, buf[4]: 0x%x, buf[5]: 0x%x, buf[6]: 0x%x, buf[7]: 0x%x\n"
             ,"get_pre_header_hash",uVar10,uVar3,uVar4,uVar9,uVar8,uVar7,uVar5,uVar6);
    _applog(7,tmp42,false);
    uVar6 = buf[7];
  }
  return uVar6;
}

