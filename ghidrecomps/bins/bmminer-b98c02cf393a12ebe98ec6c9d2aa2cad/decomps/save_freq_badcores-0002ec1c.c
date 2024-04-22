
undefined4 save_freq_badcores(undefined4 param_1,int param_2)

{
  char cVar1;
  char cVar2;
  undefined *puVar3;
  
  puVar3 = (undefined *)(param_2 + -1);
  cVar1 = '\0';
  do {
    puVar3 = puVar3 + 1;
    cVar2 = cVar1 + '\x01';
    write_EEPROM_iic(0,1,cVar1,param_1,*puVar3);
    cVar1 = cVar2;
  } while (cVar2 != -0x80);
  return 0x80;
}

