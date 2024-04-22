
int write_eeprom(uint8_t chain,int addr,uint8_t *buf,int len)

{
  _Bool _Var1;
  _Bool _Var2;
  int iVar3;
  int len_local;
  uint8_t *buf_local;
  int addr_local;
  uint8_t chain_local;
  _Bool ret;
  int i;
  
  if (chain_list[chain] == 0) {
    printf("chain[%d] does not exist!\n",(uint)chain);
    iVar3 = -1;
  }
  else {
    _Var1 = eeprom_write(chain,addr,buf,len);
    usleep(10000);
    _Var2 = eeprom_write(chain,addr,buf,len);
    if (_Var2 && _Var1) {
      for (i = 0; i < len; i = i + 1) {
        printf("[chain%d] [0x%02x] : 0x%02x\n",(uint)chain,addr + i,(uint)buf[i]);
      }
      iVar3 = 0;
    }
    else {
      puts("write error!");
      iVar3 = -1;
    }
  }
  return iVar3;
}

