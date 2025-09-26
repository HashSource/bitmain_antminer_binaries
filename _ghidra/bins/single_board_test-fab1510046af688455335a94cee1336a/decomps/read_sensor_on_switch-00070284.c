
int32_t read_sensor_on_switch(int32_t chain,int32_t index)

{
  int32_t iVar1;
  int32_t index_local;
  int32_t chain_local;
  int32_t channal;
  uint8_t is_remote;
  int32_t temp;
  
  temp = 0;
  if (index == 0) {
    iVar1 = switch_slection(chain,'\x05');
    if (iVar1 == -10) {
      temp = -10;
    }
    else {
      iVar1 = LM75A_open(chain,'\x01');
      if (iVar1 < 0) {
        temp = -1;
      }
      else {
        temp = read_sensor_on_lm75a(chain,1);
      }
    }
  }
  else if (index == 1) {
    iVar1 = switch_slection(chain,'\x06');
    if (iVar1 == -10) {
      temp = -10;
    }
    else {
      iVar1 = LM75A_open(chain,'\0');
      if (iVar1 < 0) {
        temp = -1;
      }
      else {
        temp = read_sensor_on_lm75a(chain,0);
      }
    }
  }
  else if ((1 < index) && (index < 0xc)) {
    if (6 < index) {
      channal._0_1_ = (char)index + -7;
    }
    else {
      channal._0_1_ = (char)index + -2;
    }
    iVar1 = switch_slection(chain,(char)channal);
    if (iVar1 == -10) {
      temp = -10;
    }
    else {
      usleep(0x32);
      temp = read_sensor_on_tmp451(chain,6 < index);
    }
  }
  return temp;
}

