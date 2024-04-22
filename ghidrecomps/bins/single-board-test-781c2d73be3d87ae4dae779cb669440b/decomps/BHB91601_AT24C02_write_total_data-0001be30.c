
/* WARNING: Unknown calling convention */

_Bool BHB91601_AT24C02_write_total_data(uchar which_iic,uchar which_chain)

{
  uchar uVar1;
  uint16_t uVar2;
  
  printf("\n--- %s\n",DAT_0001bf50);
  gAT24C02_data_map[122] = '\x04';
  gAT24C02_data_map[0] = '~';
  gAT24C02_data_map[123] = (uchar)Conf.TempSensor1;
  gAT24C02_data_map[121] = (uchar)Conf.sensor_model;
  gAT24C02_data_map[125] = (uchar)Conf.TempSensor2;
  gAT24C02_data_map[251] = (uchar)Conf.HashBoard_Hardware_Version_2;
  gAT24C02_data_map[1] = (uchar)((*(int *)(DAT_0001bf54 + 0x2f4) * 5 + 1000U) / 100);
  gAT24C02_data_map[252] = (uchar)Conf.HashBoard_Bom_Version_1;
  gAT24C02_data_map[124] = '\0';
  gAT24C02_data_map[127] = (uchar)Conf.TempSensor3;
  gAT24C02_data_map[126] = '\0';
  gAT24C02_data_map[129] = (uchar)Conf.TempSensor4;
  gAT24C02_data_map[253] = (uchar)Conf.HashBoard_Bom_Version_2;
  gAT24C02_data_map[250] = (uchar)Conf.HashBoard_Hardware_Version_1;
  gAT24C02_data_map[128] = '\0';
  gAT24C02_data_map[130] = '\0';
  uVar2 = CRC16(gAT24C02_data_map,0xfe);
  gAT24C02_data_map[255] = (uchar)(uVar2 >> 8);
  gAT24C02_data_map[254] = (uchar)uVar2;
  AT24C02_write_bytes('\0',gAT24C02_data_map,which_iic,which_chain,0x100);
  uVar1 = AT24C02_read_one_byte(0xff,which_iic,which_chain);
  if (gAT24C02_data_map[255] != uVar1) {
    gEEPROM_error = true;
    printf("!!! %s: save data into EEPROM fail! \n",DAT_0001bf50);
    return false;
  }
  printf("--- %s: save data into EEPROM success! \n",DAT_0001bf50);
  return true;
}

