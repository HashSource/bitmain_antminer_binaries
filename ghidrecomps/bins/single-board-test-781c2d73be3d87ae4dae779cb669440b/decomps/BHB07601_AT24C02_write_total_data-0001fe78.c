
/* WARNING: Variable defined which should be unmapped: eeprom */
/* WARNING: Unknown calling convention */

_Bool BHB07601_AT24C02_write_total_data(uchar which_iic,uchar which_chain)

{
  bool address;
  eeprom_layout_t eeprom_00;
  undefined4 uVar1;
  int i;
  int iVar2;
  uint8_t *puVar3;
  byte *pbVar4;
  undefined4 uVar5;
  undefined auStack_31c [236];
  undefined4 local_22c;
  eeprom_layout_t eeprom;
  eeprom_layout_t eeprom_rb;
  
  memset(&eeprom,0,0x100);
  eeprom.fixture_header = 0xff;
  memset(&eeprom_rb,0,0x100);
  eeprom_rb.fixture_header = 0xff;
  printf("\n--- %s\n",DAT_00020004);
  eeprom.fixture_header = 0x1397;
  eeprom.pcb_version =
       (ushort)Conf.HashBoard_Hardware_Version_2 | (ushort)(Conf.HashBoard_Hardware_Version_1 << 8);
  eeprom.bom_version =
       (ushort)Conf.HashBoard_Bom_Version_2 | (ushort)(Conf.HashBoard_Bom_Version_1 << 8);
  eeprom.temp_sensor_type = (uint8_t)Conf.sensor_model;
  eeprom.product_id = (uint8_t)Conf.HashBoard_Product_ID;
  eeprom.fixture_version = 1;
  eeprom.hash_board_sn[0] = '\0';
  eeprom.hash_board_sn[1] = '\0';
  eeprom.hash_board_sn[2] = '\0';
  eeprom.hash_board_sn[3] = '\0';
  eeprom.hash_board_sn[4] = '\0';
  eeprom.hash_board_sn[5] = '\0';
  eeprom.hash_board_sn[6] = '\0';
  eeprom.hash_board_sn[7] = '\0';
  eeprom.hash_board_sn[8] = '\0';
  eeprom.hash_board_sn[9] = '\0';
  eeprom.hash_board_sn[10] = '\0';
  eeprom.hash_board_sn[11] = '\0';
  eeprom.hash_board_sn[12] = '\0';
  eeprom.hash_board_sn[13] = '\0';
  eeprom.hash_board_sn[14] = '\0';
  eeprom.hash_board_sn[15] = '\0';
  eeprom.hash_board_sn[16] = '\0';
  eeprom.hash_board_sn[17] = '\0';
  eeprom.hash_board_sn[18] = '\0';
  eeprom.hash_board_sn[19] = '\0';
  eeprom.crc_test_fixture = CRC16((uint8_t *)&eeprom,0x1e);
  uVar5 = 0x28;
  address = true;
  eeprom.reserved_0[0] = 'Z';
  eeprom.reserved_0[1] = 'Z';
  eeprom.reserved_0[2] = 'Z';
  eeprom.reserved_0[3] = 'Z';
  eeprom.reserved_0[4] = 'Z';
  eeprom.reserved_0[5] = 'Z';
  eeprom.reserved_0[6] = 'Z';
  eeprom.reserved_0[7] = 'Z';
  pbVar4 = (byte *)((int)&local_22c + 3);
  local_22c = (uint)which_chain;
  AT24C02_write_bytes('\0',(uchar *)&eeprom,which_iic,which_chain,0x28);
  uVar1 = DAT_00020004;
  memcpy(&stack0xfffffce0,eeprom.hash_board_sn + 0xc,0xf0);
  puVar3 = eeprom.reserved_1 + 0xd7;
  eeprom_00._4_236_ = auStack_31c;
  eeprom_00.fixture_header = (short)uVar5;
  eeprom_00.fixture_version = (short)((uint)uVar5 >> 0x10);
  eeprom_00.reserved_1[200] = which_iic;
  eeprom_00.reserved_1[201] = '\0';
  eeprom_00.reserved_1[202] = '\0';
  eeprom_00.reserved_1[203] = '\0';
  eeprom_00.reserved_1[204] = (undefined)local_22c;
  eeprom_00.reserved_1[205] = local_22c._1_1_;
  eeprom_00.reserved_1[206] = local_22c._2_1_;
  eeprom_00.reserved_1[207] = local_22c._3_1_;
  eeprom_00.reserved_1[208] = (undefined)eeprom.fixture_header;
  eeprom_00.reserved_1[209] = eeprom.fixture_header._1_1_;
  eeprom_00.reserved_1[210] = (undefined)eeprom.fixture_version;
  eeprom_00.reserved_1[211] = eeprom.fixture_version._1_1_;
  eeprom_00.reserved_1[212] = eeprom.hash_board_sn[0];
  eeprom_00.reserved_1[213] = eeprom.hash_board_sn[1];
  eeprom_00.reserved_1[214] = eeprom.hash_board_sn[2];
  eeprom_00.reserved_1[215] = eeprom.hash_board_sn[3];
  dump_eeprom_info(eeprom_00);
  sleep(1);
  AT24C02_read_bytes('\0',(uchar *)&eeprom_rb,which_iic,(uchar)local_22c,0x28);
  i = 0;
  do {
    pbVar4 = pbVar4 + 1;
    puVar3 = puVar3 + 1;
    iVar2 = i + 1;
    if ((uint)*pbVar4 != (uint)*puVar3) {
      address = false;
      printf("!!! %s: eeprom[0x%x] 0x%x != 0x%x!\n",uVar1,i,(uint)*pbVar4);
      gEEPROM_error = true;
    }
    i = iVar2;
  } while (iVar2 != 0x28);
  if (address) {
    printf("--- %s: save data into EEPROM success! \n",DAT_00020004);
    return address;
  }
  printf("!!! %s: save data into EEPROM fail! \n",DAT_00020004);
  printf("!!! %s: clear EEPROM data! \n",DAT_00020004);
  memset(&eeprom_rb,0xff,0x28);
  AT24C02_write_bytes(address,(uchar *)&eeprom_rb,which_iic,(uchar)local_22c,0x28);
  return address;
}

