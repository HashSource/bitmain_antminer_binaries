
void set_PIC16F1704_voltage_z9(uint32_t i2c,uint8_t chain,uint16_t vol)

{
  uint16_t vol_local;
  uint8_t chain_local;
  uint32_t i2c_local;
  size_t i;
  
  vol_local = vol;
  chain_local = chain;
  i2c_local = i2c;
  for (i = 0; i < 4; i = i + 1) {
    PIC16F1704_i2c_forward_send(i2c_local,chain_local,"PQTU"[i],0,'\0',1,(uint8_t *)0x0);
    PIC16F1704_i2c_forward_send(i2c_local,chain_local,"PQTU"[i],0,'!',2,(uint8_t *)&vol_local);
  }
  return;
}

