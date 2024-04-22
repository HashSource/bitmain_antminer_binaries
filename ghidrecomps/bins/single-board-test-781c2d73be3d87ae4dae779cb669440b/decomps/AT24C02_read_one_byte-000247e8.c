
/* WARNING: Unknown calling convention */

uchar AT24C02_read_one_byte(uchar address,uchar which_iic,uchar which_chain)

{
  uchar uVar1;
  
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar1 = i2c_read((uint)which_chain << 0x10 | 0x1a00000 | (uint)which_iic << 0x1a |
                   (uint)address << 8);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  return uVar1;
}

