
undefined4
bm1740_pack_ioctl_pkg(undefined4 param_1,undefined4 param_2,undefined4 param_3,byte *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  char acStack_1fc [256];
  uint local_fc;
  undefined4 local_f8;
  uint local_f4;
  uint local_f0;
  uint local_ec;
  undefined4 local_e8;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  byte *local_a4;
  byte *local_a0;
  byte *local_9c;
  byte *local_98;
  byte *local_94;
  byte *local_90;
  byte *local_8c;
  byte *local_88;
  byte *local_84;
  byte *local_80;
  byte *local_7c;
  byte *local_78;
  byte *local_74;
  byte *local_70;
  byte *local_6c;
  byte *local_68;
  byte *local_64;
  byte *local_60;
  byte *local_5c;
  byte *local_58;
  byte *local_54;
  byte *local_50;
  byte *local_4c;
  byte *local_48;
  byte *local_44;
  byte *local_40;
  byte *local_3c;
  byte *local_38;
  byte *local_34;
  byte *local_30;
  byte *local_2c;
  byte *local_28;
  byte *local_24;
  byte *local_20;
  byte *local_1c;
  byte *local_18;
  byte *local_14;
  
  switch(param_3) {
  case 0:
    local_28 = param_4;
    uVar2 = bm1740_makeup_get_status_cmd(param_1,param_2,param_4[1],*param_4,param_4[2]);
    break;
  case 1:
    local_2c = param_4;
    bm1740_set_reg_table(param_4[2],*(undefined4 *)(param_4 + 4));
    uVar2 = bm1740_makeup_set_config_cmd
                      (param_1,param_2,local_2c[1],*local_2c,local_2c[2],
                       *(undefined4 *)(local_2c + 4));
    break;
  case 2:
    local_14 = param_4;
    bm1740_get_reg_table(0x1c,&local_a8);
    uVar1 = get_bt8d_from_baud(*(undefined4 *)(local_14 + 4));
    local_a8 = local_a8 & 0xffffe0ff | (uVar1 & 0x1f) << 8;
    bm1740_set_reg_table(0x1c,local_a8);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_14[1],*local_14,0x1c,local_a8);
    break;
  case 3:
    local_18 = param_4;
    uVar2 = bm1740_makeup_get_status_cmd(param_1,param_2,param_4[1],*param_4,0x1c);
    break;
  case 4:
    local_84 = param_4;
    bm1740_get_reg_table(0x40,&local_f4);
    local_f4 = local_f4 & 0xfffffff8 | (uint)(local_84[2] & 7);
    bm1740_set_reg_table(0x40,local_f4);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_84[1],*local_84,0x40,local_f4);
    break;
  case 5:
    local_4c = param_4;
    bm1740_get_reg_table(0x1c,&local_c4);
    local_c4 = local_c4 | 0x4060;
    bm1740_set_reg_table(0x1c,local_c4);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_4c[1],*local_4c,0x1c,local_c4);
    break;
  default:
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
      snprintf(acStack_1fc,0x100,"unknow ioctl type %d\n",param_3);
      _applog(0,acStack_1fc,0);
    }
    uVar2 = 0;
    break;
  case 7:
    local_50 = param_4;
    bm1740_get_reg_table(0x20,&local_c8);
    local_c8 = local_c8 & 0xff0000ff | 0x1000000 | (uint)(local_50[2] & 0x7f) << 0x11 |
               (uint)local_50[3] << 8;
    bm1740_set_reg_table(0x20,local_c8);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_50[1],*local_50,0x20,local_c8);
    break;
  case 8:
    local_54 = param_4;
    bm1740_get_reg_table(0x20,&local_cc);
    local_cc = local_cc & 0xff010000 | 0x10000 | (uint)(local_54[2] & 0x7f) << 0x11 |
               (uint)local_54[3] << 8 | (uint)local_54[4];
    bm1740_set_reg_table(0x20,local_cc);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_54[1],*local_54,0x20,local_cc);
    break;
  case 9:
    local_44 = param_4;
    bm1740_get_reg_table(0x14,&local_c0);
    local_c0 = local_c0 & 0xffffff00 | *(uint *)(local_44 + 4) & 0xff;
    bm1740_set_reg_table(0x14,local_c0);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_44[1],*local_44,0x14,local_c0);
    break;
  case 10:
    local_48 = param_4;
    uVar2 = bm1740_makeup_get_status_cmd(param_1,param_2,param_4[1],*param_4,0x14);
    break;
  case 0xb:
    local_58 = param_4;
    bm1740_get_reg_table(0x24,&local_d0);
    local_d0 = local_d0 & 0x7fffffff | *(int *)(local_58 + 4) << 0x1f;
    bm1740_set_reg_table(0x24,local_d0);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_58[1],*local_58,0x24,local_d0);
    break;
  case 0xc:
    local_5c = param_4;
    bm1740_get_reg_table(0x24,&local_d4);
    local_d4 = CONCAT22(local_d4._2_2_,(short)*(undefined4 *)(local_5c + 4));
    bm1740_set_reg_table(0x24,local_d4);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_5c[1],*local_5c,0x24,local_d4);
    break;
  case 0xe:
    local_64 = param_4;
    bm1740_get_reg_table(0x28,&local_d8);
    local_d8 = *(undefined4 *)(local_64 + 4);
    bm1740_set_reg_table(0x28,local_d8);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_64[1],*local_64,0x28,local_d8);
    break;
  case 0xf:
  case 0x10:
    local_1c = param_4;
    uVar2 = bm1740_makeup_get_status_cmd(param_1,param_2,param_4[1],*param_4,0x1c);
    break;
  case 0x11:
    local_20 = param_4;
    bm1740_get_reg_table(0x1c,&local_ac);
    local_ac = local_ac & 0xffffdfff | (*(uint *)(local_20 + 4) & 1) << 0xd;
    bm1740_set_reg_table(0x1c,local_ac);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_20[1],*local_20,0x1c,local_ac);
    break;
  case 0x12:
    local_24 = param_4;
    bm1740_get_reg_table(0x1c,&local_b0);
    local_b0 = local_b0 & 0xfffffffc | *(uint *)(local_24 + 4) & 3;
    bm1740_set_reg_table(0x1c,local_b0);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_24[1],*local_24,0x1c,local_b0);
    break;
  case 0x13:
    local_30 = param_4;
    bm1740_get_reg_table(0,&local_b4);
    local_b4 = local_b4 & 0xffffff00 | (uint)*local_30;
    bm1740_set_reg_table(0,local_b4);
    uVar2 = bm1740_makeup_set_address_cmd(param_1,param_2,*local_30);
    break;
  case 0x14:
    uVar2 = bm1740_makeup_chain_inactive_cmd(param_1,param_2);
    break;
  case 0x15:
  case 0x16:
    local_34 = param_4;
    uVar2 = bm1740_makeup_get_status_cmd(param_1,param_2,param_4[1],*param_4,0);
    break;
  case 0x17:
    local_b8 = 0;
    local_38 = param_4;
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,param_4[1],*param_4,8,0);
    break;
  case 0x18:
    local_3c = param_4;
    uVar2 = bm1740_makeup_get_status_cmd(param_1,param_2,param_4[1],*param_4,8);
    break;
  case 0x19:
    local_40 = param_4;
    bm1740_get_reg_table(0xc,&local_bc);
    bm1740_get_plldata(*(undefined4 *)(local_40 + 4),&local_bc);
    bm1740_set_reg_table(0xc,local_bc);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_40[1],*local_40,0xc,local_bc);
    break;
  case 0x1a:
    local_60 = param_4;
    uVar2 = bm1740_makeup_get_status_cmd(param_1,param_2,param_4[1],*param_4,0x24);
    break;
  case 0x1b:
    local_68 = param_4;
    bm1740_get_reg_table(0x30,&local_dc);
    local_dc = local_dc & 0xf0000000 | (uint)(local_68[2] & 0xf) << 0x18 |
               (uint)(local_68[3] & 0xf) << 0x14 | (uint)(local_68[4] & 0xf) << 0x10 |
               (uint)(local_68[5] & 0xf) << 0xc | (uint)(local_68[6] & 0xf) << 8 |
               (uint)(local_68[7] & 0xf) << 4 | (uint)(local_68[8] & 0xf);
    bm1740_set_reg_table(0x30,local_dc);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_68[1],*local_68,0x30,local_dc);
    break;
  case 0x1c:
    local_6c = param_4;
    bm1740_get_reg_table(0x34,&local_e0);
    if (*(int *)(local_6c + 4) == 0) {
      local_e0 = local_e0 & 0x7fffffff;
    }
    else {
      local_e0 = local_e0 | 0x80000000;
    }
    bm1740_set_reg_table(0x34,local_e0);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_6c[1],*local_6c,0x34,local_e0);
    break;
  case 0x1d:
    local_70 = param_4;
    uVar2 = bm1740_makeup_get_status_cmd(param_1,param_2,param_4[1],*param_4,0x34);
    break;
  case 0x1e:
    local_74 = param_4;
    bm1740_get_reg_table(0x38,&local_e4);
    local_e4 = local_e4 & 0xffff | *(int *)(local_74 + 4) << 0x10;
    bm1740_set_reg_table(0x38,local_e4);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_74[1],*local_74,0x38,local_e4);
    break;
  case 0x1f:
    local_78 = param_4;
    bm1740_get_reg_table(0x38,&local_e8);
    local_e8 = CONCAT22(local_e8._2_2_,(short)*(undefined4 *)(local_78 + 4));
    bm1740_set_reg_table(0x38,local_e8);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_78[1],*local_78,0x38,local_e8);
    break;
  case 0x20:
    local_7c = param_4;
    bm1740_get_reg_table(0x3c,&local_ec);
    local_ec = local_ec & 0xffffff3f | (uint)(local_7c[2] & 3) << 6;
    bm1740_set_reg_table(0x3c,local_ec);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_7c[1],*local_7c,0x3c,local_ec);
    break;
  case 0x21:
    local_80 = param_4;
    bm1740_get_reg_table(0x3c,&local_f0);
    local_f0 = local_f0 & 0xffffffc0 | (uint)(local_80[2] & 0x3f);
    bm1740_set_reg_table(0x3c,local_f0);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_80[1],*local_80,0x3c,local_f0);
    break;
  case 0x22:
    local_88 = param_4;
    bm1740_get_reg_table(0x54,&local_f8);
    local_f8 = *(undefined4 *)(local_88 + 4);
    bm1740_set_reg_table(0x54,local_f8);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_88[1],*local_88,0x54,local_f8);
    break;
  case 0x23:
    local_8c = param_4;
    bm1740_get_reg_table(0x58,&local_fc);
    local_fc = local_fc & 0xfffffffc | (*(uint *)(local_8c + 4) & 1) << 1 |
               *(uint *)(local_8c + 8) & 1;
    bm1740_set_reg_table(0x58,local_fc);
    uVar2 = bm1740_makeup_set_config_cmd(param_1,param_2,local_8c[1],*local_8c,0x58,local_fc);
    break;
  case 0x24:
    local_90 = param_4;
    uVar2 = bm1740_makeup_bist_setup_cmd(param_4[1],*param_4,param_1,param_2);
    break;
  case 0x25:
    local_94 = param_4;
    uVar2 = bm1740_makeup_bist_write_wait_cmd
                      (param_4[1],*param_4,param_4 + 2,param_4[8],param_1,param_2);
    break;
  case 0x26:
    local_98 = param_4;
    uVar2 = bm1740_makeup_bist_write_wait_read_cmd(param_4[1],*param_4,param_4 + 2,param_1,param_2);
    break;
  case 0x27:
    local_9c = param_4;
    uVar2 = bm1740_makeup_bist_wait_cmd(param_4[1],*param_4,param_4 + 2,param_1,param_2);
    break;
  case 0x28:
    local_a0 = param_4;
    uVar2 = bm1740_makeup_bist_read_cmd(param_4[1],*param_4,param_1,param_2);
    break;
  case 0x29:
    local_a4 = param_4;
    uVar2 = bm1740_makeup_bist_disable_cmd(param_4[1],*param_4,param_1,param_2);
  }
  return uVar2;
}

