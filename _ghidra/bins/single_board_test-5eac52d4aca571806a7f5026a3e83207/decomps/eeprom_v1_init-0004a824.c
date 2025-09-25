
int eeprom_v1_init(eeprom_v1 *eeprom,uint8_t board_id,uint32_t nonce)

{
  uint32_t nonce_local;
  uint8_t board_id_local;
  eeprom_v1 *eeprom_local;
  uint8_t i_1;
  uint8_t i;
  
  memset(eeprom,0,0x180);
  memcpy((eeprom->private).key_raw,key_raw_fixed,0x20);
  memcpy((eeprom->private).iv_raw,iv_raw_fixed,0x10);
  (eeprom->private).board_id = board_id;
  (eeprom->private).nonce = nonce;
  for (i = '\0'; i < 8; i = i + '\x01') {
    *(uint32_t *)((eeprom->private).key_raw + (uint)i * 4) =
         (eeprom->private).nonce ^ *(uint *)((eeprom->private).key_raw + (uint)i * 4);
  }
  for (i_1 = '\0'; i_1 < 4; i_1 = i_1 + '\x01') {
    *(uint32_t *)((eeprom->private).iv_raw + (uint)i_1 * 4) =
         (eeprom->private).nonce ^ *(uint *)((eeprom->private).iv_raw + (uint)i_1 * 4);
  }
  eeprom->is_version_available = (_func__Bool_eeprom_v1_t_ptr *)0x49e21;
  eeprom->is_board_name_available = (_func__Bool_eeprom_v1_t_ptr *)0x49e55;
  eeprom->is_pt1_available = (_func__Bool_eeprom_v1_t_ptr *)0x49e79;
  eeprom->is_pt2_available = (_func__Bool_eeprom_v1_t_ptr *)0x49ea1;
  eeprom->is_sweep_available = (_func__Bool_eeprom_v1_t_ptr *)0x49ec9;
  eeprom->version_store = (_func_int_eeprom_v1_t_ptr *)0x4a4fd;
  eeprom->board_name_store = (_func_int_eeprom_v1_t_ptr *)0x4a571;
  eeprom->pt1_store = (_func_int_eeprom_v1_t_ptr *)0x49ef1;
  eeprom->pt2_store = (_func_int_eeprom_v1_t_ptr *)0x49fd1;
  eeprom->sweep_store = (_func_int_eeprom_v1_t_ptr *)0x4a0b1;
  eeprom->version_retrieve = (_func_int_eeprom_v1_t_ptr *)0x4a531;
  eeprom->board_name_retrieve = (_func_int_eeprom_v1_t_ptr *)0x4a5a5;
  eeprom->pt1_retrieve = (_func_int_eeprom_v1_t_ptr *)0x4a191;
  eeprom->pt2_retrieve = (_func_int_eeprom_v1_t_ptr *)0x4a2b5;
  eeprom->sweep_retrieve = (_func_int_eeprom_v1_t_ptr *)0x4a3d9;
  eeprom->set_sweep_freq = (_func_void_eeprom_v1_t_ptr_uint16_t_ptr_uint8_t *)0x4a601;
  eeprom->get_sweep_freq =
       (_func_void_eeprom_v1_t_ptr_uint16_t_ptr_uint16_t_ptr_uint16_t_ptr_uint8_t *)0x4a769;
  return 0;
}

