
/* WARNING: Unknown calling convention */

void AT24C02_write_one_byte(uchar address,uchar data,uchar which_iic,uchar which_chain)

{
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  i2c_write(data | 0x1a00000 | (uint)which_chain << 0x10 | (uint)which_iic << 0x1a |
            (uint)address << 8);
  (*(code *)PTR_pthread_mutex_unlock_00030108)(&i2c_mutex);
  return;
}

