
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
  eeprom->is_version_available = (_func__Bool_eeprom_v1_t_ptr *)0x50ba9;
  eeprom->is_board_name_available = (_func__Bool_eeprom_v1_t_ptr *)0x50bdd;
  eeprom->is_pt1_available = (_func__Bool_eeprom_v1_t_ptr *)0x50c01;
  eeprom->is_pt2_available = (_func__Bool_eeprom_v1_t_ptr *)0x50c29;
  eeprom->is_sweep_available = (_func__Bool_eeprom_v1_t_ptr *)0x50c51;
  eeprom->version_store = (_func_int_eeprom_v1_t_ptr *)0x5129d;
  eeprom->board_name_store = (_func_int_eeprom_v1_t_ptr *)0x51311;
  eeprom->pt1_store = (_func_int_eeprom_v1_t_ptr *)0x50c79;
  eeprom->pt2_store = (_func_int_eeprom_v1_t_ptr *)0x50d5d;
  eeprom->sweep_store = (_func_int_eeprom_v1_t_ptr *)0x50e41;
  eeprom->version_retrieve = (_func_int_eeprom_v1_t_ptr *)0x512d1;
  eeprom->board_name_retrieve = (_func_int_eeprom_v1_t_ptr *)0x51345;
  eeprom->pt1_retrieve = (_func_int_eeprom_v1_t_ptr *)0x50f25;
  eeprom->pt2_retrieve = (_func_int_eeprom_v1_t_ptr *)0x5104d;
  eeprom->sweep_retrieve = (_func_int_eeprom_v1_t_ptr *)0x51175;
  eeprom->set_sweep_freq = (_func_void_eeprom_v1_t_ptr_uint16_t_ptr_uint8_t *)0x513b5;
  eeprom->get_sweep_freq =
       (_func_void_eeprom_v1_t_ptr_uint16_t_ptr_uint16_t_ptr_uint16_t_ptr_uint8_t *)0x5152d;
  return 0;
}

