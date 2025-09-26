
int eeprom_v1_board_name_retrieve(eeprom_v1 *eeprom)

{
  int32_t iVar1;
  int iVar2;
  eeprom_v1 *eeprom_local;
  char board_name [15];
  
  board_name[0] = '\0';
  board_name[1] = '\0';
  board_name[2] = '\0';
  board_name[3] = '\0';
  board_name[4] = '\0';
  board_name[5] = '\0';
  board_name[6] = '\0';
  board_name[7] = '\0';
  board_name[8] = '\0';
  board_name[9] = '\0';
  board_name[10] = '\0';
  board_name[0xb] = '\0';
  board_name[0xc] = '\0';
  board_name[0xd] = '\0';
  board_name[0xe] = '\0';
  iVar1 = eeprom_read((uint)(eeprom->private).board_id,'\x01',(uint8_t *)board_name,0xf);
  if (iVar1 == 0) {
    *(undefined4 *)(eeprom->data).board_name = board_name._0_4_;
    *(undefined4 *)((eeprom->data).board_name + 4) = board_name._4_4_;
    *(undefined4 *)((eeprom->data).board_name + 8) = board_name._8_4_;
    *(undefined2 *)((eeprom->data).board_name + 0xc) = board_name._12_2_;
    (eeprom->data).board_name[0xe] = board_name[0xe];
    iVar2 = 0;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

